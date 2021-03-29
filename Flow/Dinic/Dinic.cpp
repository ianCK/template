template <typename T> struct Dinic {
	struct Edge {
		int to, rev;
		T cap;
		Edge(int a, int b, T c) {to = a, rev = b, cap = c;}
	};

	vector<Edge> *graph;
	int *dep, *iter, *went;
	int size;

	void init(int n) {
		size = n;
		delete [] graph; graph = new vector<Edge>[size];
		delete []  went; went  = new int[size];
		delete []  iter; iter  = new int[size];
		delete []   dep; dep   = new int[size];
		return ;
	}

	void AddEdge(int u, int v, T c) {
		graph[u].push_back(Edge(v, int(graph[v].size()), c));
		graph[v].push_back(Edge(u, int(graph[u].size()) - 1, 0));
		return ;
	}

	void AddEdge_B(int u, int v, T c) {
		graph[u].push_back(Edge(v, int(graph[v].size()), c));
		graph[v].push_back(Edge(u, int(graph[u].size()) - 1, c));
		return ;
	}
	
	// Only for B
	void Reweight() {
		for (int i = 0; i < size; i++) for (Edge &j : graph[i]) if (j.to > i) 
			j.cap = graph[j.to][j.rev].cap = (j.cap + graph[j.to][j.rev].cap) >> 1;
		return ;
	}

	void Bfs(int s, int t) {
		queue<int> q;
		went[s] = t;
		iter[s] = dep[s] = 0;
		q.push(s);
		while (!q.empty()) {
			int now = q.front();
			q.pop();
			for (Edge i : graph[now]) if (i.cap > 0 && went[i.to] != t) {
				went[i.to] = t;
				dep[i.to] = dep[now] + 1;
				iter[i.to] = 0;
				q.push(i.to);
			}
		}
		return ;
	}

	T Dfs(int u, int t, T nv) {
		if (u == t) return nv;
		for (int &i = iter[u]; i < int(graph[u].size()); i++) {
			Edge &nxt = graph[u][i];
			if (nxt.cap > 0 && dep[nxt.to] > dep[u]) {
				T tmp = Dfs(nxt.to, t, min(nxt.cap, nv));
				if (tmp > 0) {
					nxt.cap -= tmp;
					graph[nxt.to][nxt.rev].cap += tmp;
					return tmp;
				}
			}
		}
		return 0;
	}

	T solve(int s, int t) {
		int cnt = went[s];
		T ans = 0, kInf = numeric_limits<T>::max();
		while (true) {
			Bfs(s, ++cnt);
			if (went[s] != went[t]) break;
			T f = 0;
			while ((f = Dfs(s, t, kInf)) > 0) ans += f;
		}
		return ans;
	}

	T operator ()(int s, int t) {return solve(s, t);}

	// Should be called right after Dinic
	vector<int> S_side(int s) {
		vector<int> ans;
		for (int i = 0; i < size; i++) if (went[s] == went[i]) ans.PB(i);
		return ans;
	}
};
