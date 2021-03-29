// 0-indexed
// O(n^2m) (this upper bound is very high)
// init(n)

template <typename T = int> struct Dinic {
	struct Edge {
		int to, nxt;
		T cap;
		Edge(int a, int b, T c) {to = a, nxt = b, cap = c;}
	};

	vector<Edge> graph;
	vector<int> dep, iter, went, head, tail;
	int size;

	void init(int n) {
		size = n;
		graph.clear();
		head.clear(); head.resize(size, -1);
		tail.clear(); tail.resize(size, -2);
		iter.resize(size);
		went.resize(size);
		dep.resize(size);
		return ;
	}

	void AddEdge(int u, int v, T c) {
		graph.push_back(Edge(v, int(1E9), c));
		graph.push_back(Edge(u, int(1E9), 0));
		int u_edge = int(graph.size()) - 2, v_edge = int(graph.size()) - 1;
		if (head[u] == -1) head[u] = u_edge;
		if (head[v] == -1) head[v] = v_edge;
		if (tail[u] != -2) graph[tail[u]].nxt = u_edge;
		if (tail[v] != -2) graph[tail[v]].nxt = v_edge;
		tail[u] = u_edge;
		tail[v] = v_edge;
		return ;
	}

	void AddEdge_B(int u, int v, T c) {
		graph.push_back(Edge(v, int(1E9), c));
		graph.push_back(Edge(u, int(1E9), c));
		int u_edge = int(graph.size()) - 2, v_edge = int(graph.size()) - 1;
		if (head[u] == -1) head[u] = u_edge;
		if (head[v] == -1) head[v] = v_edge;
		if (tail[u] != -2) graph[tail[u]].nxt = u_edge;
		if (tail[v] != -2) graph[tail[v]].nxt = v_edge;
		tail[u] = u_edge;
		tail[v] = v_edge;
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
			for (int i = head[now]; i <= tail[now]; i = graph[i].nxt) if (graph[i].cap > 0 && went[graph[i].to] != t) {
				went[graph[i].to] = t;
				dep[graph[i].to] = dep[now] + 1;
				iter[graph[i].to] = head[graph[i].to];
				q.push(graph[i].to);
			}
		}
		return ;
	}

	T Dfs(int u, int t, T nv) {
		if (u == t) return nv;
		for (int &i = iter[u]; i <= tail[u]; i = graph[i].nxt) {
			Edge &nxt = graph[i];
			if (nxt.cap > 0 && dep[nxt.to] > dep[u]) {
				T tmp = Dfs(nxt.to, t, min(nxt.cap, nv));
				if (tmp > 0) {
					nxt.cap -= tmp;
					graph[i ^ 1].cap += tmp;
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
