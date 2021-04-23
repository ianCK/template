enum {
  END = -9,
  UNSAT = 0,
  SAT = 1,
  MARK = 2,
  IMPLIED = 6
};
struct solver {
  int *DB, nVars, nClauses, mem_used, mem_fixed,
    mem_max, maxLemmas, nLemmas, *buffer,
    nConflicts, *model, *reason, *falseStack,
    *falsed, *first, *forced, *processed,
    *assigned, *next, *prev, head, res, fast, slow;
};
void unassign(struct solver* S, int lit) {
  S->falsed[lit] = 0;
}
void restart(struct solver* S) {
  while (S->assigned > S->forced)
    unassign(S, *(--S->assigned));
  S->processed = S->forced;
}
void assign(
  struct solver* S, int* reason, int forced) {
  int lit = reason[0];
  S->falsed[-lit] = forced ? IMPLIED : 1;
  *(S->assigned++) = -lit;
  S->reason[abs(lit)] = 1 + int((reason)-S->DB);
  S->model[abs(lit)] = (lit > 0);
}
void addWatch(struct solver* S, int lit, int mem) {
  S->DB[mem] = S->first[lit];
  S->first[lit] = mem;
}
int* getMemory(struct solver* S, int mem_size) {
  if (S->mem_used + mem_size > S->mem_max) {
    printf("c out of memory\n");
    exit(0);
  }
  int* store = (S->DB + S->mem_used);
  S->mem_used += mem_size;
  return store;
}
int* addClause(
  struct solver* S, int* in, int size, int irr) {
  int i, used = S->mem_used;
  int* clause = getMemory(S, size + 3) + 2;
  if (size > 1) {
    addWatch(S, in[0], used);
    addWatch(S, in[1], used + 1);
  }
  for (i = 0; i < size; i++) clause[i] = in[i];
  clause[i] = 0;
  if (irr) S->mem_fixed = S->mem_used;
  else
    S->nLemmas++;
  if ((size == 1) && !S->falsed[-in[0]]) {
    assign(S, clause, 1);
  }
  return clause;
}
void reduceDB(struct solver* S, int k) {
  while (S->nLemmas > S->maxLemmas)
    S->maxLemmas += 300;
  S->nLemmas = 0;
  int i;
  for (i = -S->nVars; i <= S->nVars; i++) {
    if (i == 0) continue;
    int* watch = &S->first[i];
    while (*watch != END)
      if (*watch >= S->mem_fixed)
        watch = (S->DB + *watch);
      else
        *watch = S->DB[*watch];
  }
  int old_used = S->mem_used;
  S->mem_used = S->mem_fixed;
  for (i = S->mem_fixed + 2; i < old_used;
       i += 3) {
    int count = 0, head = i;
    while (S->DB[i]) {
      int lit = S->DB[i++];
      if ((lit > 0) == S->model[abs(lit)]) count++;
    }
    if (count < k)
      addClause(S, S->DB + head, i - head, 0);
  }
}
void bump(struct solver* S, int lit) {
  if (S->falsed[lit] != IMPLIED) {
    S->falsed[lit] = MARK;
    int var = abs(lit);
    if (var != S->head) {
      S->prev[S->next[var]] = S->prev[var];
      S->next[S->prev[var]] = S->next[var];
      S->next[S->head] = var;
      S->prev[var] = S->head;
      S->head = var;
    }
  }
}
int implied(struct solver* S, int lit) {
  if (S->falsed[lit] > MARK)
    return (S->falsed[lit] & MARK);
  if (!S->reason[abs(lit)]) return 0;
  int* p = (S->DB + S->reason[abs(lit)] - 1);
  while (*(++p))
    if ((S->falsed[*p] ^ MARK) &&
      !implied(S, *p)) {
      S->falsed[lit] = IMPLIED - 1;
      return 0;
    }
  S->falsed[lit] = IMPLIED;
  return 1;
}
int* analyze(struct solver* S, int* clause) {
  S->res++;
  S->nConflicts++;
  while (*clause) bump(S, *(clause++));
  while (S->reason[abs(*(--S->assigned))]) {
    if (S->falsed[*S->assigned] == MARK) {
      int* check = S->assigned;
      while (S->falsed[*(--check)] != MARK)
        if (!S->reason[abs(*check)]) goto build;
      clause =
        S->DB + S->reason[abs(*S->assigned)];
      while (*clause) bump(S, *(clause++));
    }
    unassign(S, *S->assigned);
  }
build:;
  int size = 0, lbd = 0, flag = 0;
  int* p = S->processed = S->assigned;
  while (p >= S->forced) {
    if ((S->falsed[*p] == MARK) &&
      !implied(S, *p)) {
      S->buffer[size++] = *p;
      flag = 1;
    }
    if (!S->reason[abs(*p)]) {
      lbd += flag;
      flag = 0;
      if (size == 1) S->processed = p;
    }
    S->falsed[*(p--)] = 1;
  }
  S->fast -= S->fast >> 5;
  S->fast += lbd << 15;
  S->slow -= S->slow >> 15;
  S->slow += lbd << 5;
  while (S->assigned > S->processed)
    unassign(S, *(S->assigned--));
  unassign(S, *S->assigned);
  S->buffer[size] = 0;
  return addClause(S, S->buffer, size, 0);
}
int propagate(struct solver* S) {
  int forced = S->reason[abs(*S->processed)];
  while (S->processed < S->assigned) {
    int lit = *(S->processed++);
    int* watch = &S->first[lit];
    while (*watch != END) {
      int i, unit = 1;
      int* clause = (S->DB + *watch + 1);
      if (clause[-2] == 0) clause++;
      if (clause[0] == lit) clause[0] = clause[1];
      for (i = 2; unit && clause[i]; i++)
        if (!S->falsed[clause[i]]) {
          clause[1] = clause[i];
          clause[i] = lit;
          int store = *watch;
          unit = 0;
          *watch = S->DB[*watch];
          addWatch(S, clause[1], store);
        }
      if (unit) {
        clause[1] = lit;
        watch = (S->DB + *watch);
        if (S->falsed[-clause[0]]) continue;
        if (!S->falsed[clause[0]]) {
          assign(S, clause, forced);
        } else {
          if (forced) return UNSAT;
          int* lemma = analyze(S, clause);
          if (!lemma[1]) forced = 1;
          assign(S, lemma, forced);
          break;
        }
      }
    }
  }
  if (forced) S->forced = S->processed;
  return SAT;
}
int solve(struct solver* S) {
  int decision = S->head;
  S->res = 0;
  for (;;) {
    int old_nLemmas = S->nLemmas;
    if (propagate(S) == UNSAT) return UNSAT;
    if (S->nLemmas > old_nLemmas) {
      decision = S->head;
      if (S->fast > (S->slow / 100) * 125) {
        S->res = 0;
        S->fast = (S->slow / 100) * 125;
        restart(S);
        if (S->nLemmas > S->maxLemmas)
          reduceDB(S, 6);
      }
    }
    while (S->falsed[decision] ||
      S->falsed[-decision]) {
      decision = S->prev[decision];
    }
    if (decision == 0) return SAT;
    decision =
      S->model[decision] ? decision : -decision;
    S->falsed[-decision] = 1;
    *(S->assigned++) = -decision;
    decision = abs(decision);
    S->reason[decision] = 0;
  }
}
void initCDCL(struct solver* S, int n, int m) {
  if (n < 1) n = 1;
  S->nVars = n;
  S->nClauses = m;
  S->mem_max = 1 << 30;
  S->mem_used = 0;
  S->nLemmas = 0;
  S->nConflicts = 0;
  S->maxLemmas = 2000;
  S->fast = S->slow = 1 << 24;
  S->DB = static_cast<int*>(
    calloc(S->mem_max, sizeof(int)));
  S->model = getMemory(S, n + 1);
  S->next = getMemory(S, n + 1);
  S->prev = getMemory(S, n + 1);
  S->buffer = getMemory(S, n);
  S->reason = getMemory(S, n + 1);
  S->falseStack = getMemory(S, n + 1);
  S->forced = S->falseStack;
  S->processed = S->falseStack;
  S->assigned = S->falseStack;
  S->falsed = getMemory(S, 2 * n + 1);
  S->falsed += n;
  S->first = getMemory(S, 2 * n + 1);
  S->first += n;
  S->DB[S->mem_used++] = 0;
  int i;
  for (i = 1; i <= n; i++) {
    S->prev[i] = i - 1;
    S->next[i - 1] = i;
    S->model[i] = S->falsed[-i] = S->falsed[i] = 0;
    S->first[i] = S->first[-i] = END;
  }
  S->head = n;
}
