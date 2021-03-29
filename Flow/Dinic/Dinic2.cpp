template <typename T> struct Dinic {
	struct Edge {
		int to, next;
		T cap;
		Edge(int a, int b, T c) {to = a, next = b, cap = c;}
	};

	vector<Edge> edge;
	int *head, *dep, *iter, *went;
	int size;

	void init(int n) {
		size = n;
		edge.clear();
		delete []  dep; dep  = new int[size];
		delete [] went; went = new int[size];
		delete [] iter; iter = new int[size];
		delete [] head; head = new int[size];
		memset(head, -1, sizeof(int) * size);
		return ;
	}

	void AddEdge(int u, int v, T c) {
		edge.PB(Edge(v, head[u], c));
		edge.PB(Edge(u, head[v], 0));
		head[u] = int(edge.size()) - 2;
		head[v] = int(edge.size()) - 1;
		return ;
	}

	void AddEdge_B(int u, int v, T c) {
		edge.PB(Edge(v, head[u], c));
		edge.PB(Edge(u, head[v], c));
		head[u] = int(edge.size()) - 2;
		head[v] = int(edge.size()) - 1;
		return ;
	}

	void Bfs(int s, int t) {
		queue<int> q;
		went[s] = t;
		iter[s] = head[s];
		dep[s] = 0;
		q.push(s);
		while (!q.empty()) {
			int now = q.front();
			q.pop();
			for (int i = head[now]; ~i; i = edge[i].next) if (edge[i].cap > 0 && went[edge[i].to] != t) {
				went[edge[i].to] = t;
				dep[edge[i].to] = dep[now] + 1;
				iter[edge[i].to] = head[edge[i].to];
				q.push(edge[i].to);
			}
		}
		return ;
	}

	T Dfs(int u, int t, T nv) {
		if (u == t) return nv;
		for (int &i = iter[u]; ~i; i = edge[i].next) {
			if (edge[i].cap > 0 && dep[edge[i].to] > dep[u]) {
				T tmp = Dfs(edge[i].to, t, min(edge[i].cap, nv));
				if (tmp > 0) {
					edge[i].cap -= tmp;
					edge[i ^ 1].cap += tmp;
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
