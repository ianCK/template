// Test Source : ARC092 A
// kN = #(left vertices), kM = #(right vertices)
// AddEdge(left_vertex, right_vertex)
// MaxMatch() -> matchx, matchy
// 0-based

struct Bipartite_Matching {
	struct Edge {
		int ed, next;
		Edge(int a, int b) {ed = a, next = b;}
	};
	vector<Edge> edge;
	int *head, *disx, *disy, *matchx, *matchy;
	// Because vector<bool> is faster
	vector<bool> vis;
	int bfs_dis, x_size, y_size;

	Bipartite_Matching() : head(nullptr), disx(nullptr), disy(nullptr), matchx(nullptr), matchy(nullptr) {}
	~Bipartite_Matching() {
		delete [] head;
		delete [] disx;
		delete [] disy;
		delete [] matchx;
		delete [] matchy;
	}

	void init(int n, int m) {
		x_size = n, y_size = m;
		edge.clear();
		if (head) delete [] head; head = new int[x_size];
		if (disx) delete [] disx; disx = new int[x_size];
		if (disy) delete [] disy; disy = new int[y_size];
		if (matchx) delete [] matchx; matchx = new int[x_size];
		if (matchy) delete [] matchy; matchy = new int[y_size];
		vis.clear(); vis.resize(y_size);
		memset(head, -1, sizeof(int) * x_size);
		return ;
	}

	void AddEdge(int a, int b) {
		edge.push_back(Edge(b, head[a]));
		head[a] = int(edge.size()) - 1;
		return ;
	}

	bool Bfs() {
		queue<int> que;
		bfs_dis = x_size << 1;
		memset(disx, -1, sizeof(int) * x_size);
		memset(disy, -1, sizeof(int) * y_size);

		for (int i = 0; i < x_size; ++i) if (matchx[i] < 0) {
			disx[i] = 0;
			que.push(i);
		}

		while (!que.empty()) {
			int x = que.front();
			que.pop();
			if (disx[x] > bfs_dis) break;
			for (int i = head[x]; i >= 0; i = edge[i].next) {
				int y = edge[i].ed;
				if (disy[y] < 0) {
					disy[y] = disx[x] + 1;
					if (matchy[y] < 0) bfs_dis = disy[y];
					else {
						disx[matchy[y]] = disy[y] + 1;
						que.push(matchy[y]);
					}
				}
			}
		}

		return bfs_dis < (x_size << 1);
	}

	bool Dfs(int x) {
		for (int i = head[x]; i >= 0; i = edge[i].next) {
			int y = edge[i].ed;
			if (!vis[y] && disy[y] == disx[x] + 1) {
				vis[y] = true;
				if (matchy[y] >= 0 && disy[y] == bfs_dis) continue;
				if (matchy[y] < 0 || Dfs(matchy[y])) {
					matchx[x] = y;
					matchy[y] = x;
					return true;
				}
			}
		}
		return false;
	}

	int MaxMatch() {
		int ret = 0;
		memset(matchx, -1, sizeof(int) * x_size);
		memset(matchy, -1, sizeof(int) * y_size);
		while (Bfs()) {
			fill(vis.begin(), vis.end(), false);
			for (int i = 0; i < x_size; ++i) if (matchx[i] < 0 && Dfs(i)) ++ret;
		}
		return ret;
	}

	int operator ()() {return MaxMatch();}
};
