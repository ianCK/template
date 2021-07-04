// AddEdge(u, v, cap, cost)
template <typename T> struct MCMF {
	struct Edge {
		int to, rev;
		T cap, wei;
		Edge (int a, T b, T c, int d) {to = a; cap = b; wei = c; rev = d;}
	};

	vector<vector<Edge>> graph;
	vector<T> d;
	vector<int> p, ed;
	vector<bool> inq;
	int size;
	static constexpr T kInf = numeric_limits<T>::max() / 2 - 10;

	void init(int n) {
		size = n;
		graph.clear(); graph.resize(n);
		d.clear(); d.resize(n);
		p.clear(); p.resize(n);
		ed.clear(); ed.resize(n);
		inq.clear(); inq.resize(n);
		return ;
	}

	void AddEdge(int a, int b, T c, T d) {
		graph[a].push_back(Edge(b, c, d, int(graph[b].size())));
		graph[b].push_back(Edge(a, 0, -d, int(graph[a].size()) - 1));
		return ;
	}

	bool spfa(int s, int t, T &f, T &c) {
		for (int i = 0; i < size; i++) {
			d[i] = kInf;
			p[i] = ed[i] = -1;
			inq[i] = false;
		}

		d[s] = 0;
		queue<int> q;
		q.push(s);
		while (!q.empty()) {
			int x = q.front(); q.pop();
			inq[x] = false;
			for (int i = 0; i < int(graph[x].size()); i++) {
				Edge &e = graph[x][i];
				if (e.cap > 0 && d[e.to] > d[x] + e.wei) {
					d[e.to] = d[x] + e.wei;
					p[e.to] = x;
					ed[e.to] = i;
					if (!inq[e.to]) {
						q.push(e.to);
						inq[e.to] = true;
					}
				}
			}
		}

		if (d[t] == kInf) return false;

		T dlt = kInf;
		for (int x = t; x != s; x = p[x]) dlt = min(dlt, graph[p[x]][ed[x]].cap);
		for (int x = t; x != s; x = p[x]) {
			Edge &e = graph[p[x]][ed[x]];
			e.cap -= dlt;
			graph[e.to][e.rev].cap += dlt;
		}

		f += dlt; c += d[t] * dlt;
		return true;
	}

	pair<T, T> operator () (int s, int t) {
		T f = 0, c = 0;
		while (spfa(s, t, f, c));
		return make_pair(f, c);
	}
};
