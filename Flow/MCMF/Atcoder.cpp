namespace atcoder {
	namespace internal {
		template <class E> struct csr {
			std::vector<int> start;
			std::vector<E> elist;
			explicit csr(int n, const std::vector<std::pair<int, E>>& edges) : start(n + 1), elist(edges.size()) {
			for (auto e : edges) start[e.first + 1]++;
			for (int i = 1; i <= n; i++) start[i] += start[i - 1];
			auto counter = start;
			for (auto e : edges) elist[counter[e.first]++] = e.second;
			}
		};
	}

	template <class Cap, class Cost> struct MCMF {
		public:
			MCMF() {}
			explicit MCMF(int n) : _n(n) {}

			void init(int n) {_n = n; return _edges.clear();}
			void AddEdge(int from, int to, Cap cap, Cost cost) {return _edges.push_back(Edge(from, to, cap, cost));}

			struct Edge {
				int from, to;
				Cap cap, flow;
				Cost cost;
				Edge(int a, int b, Cap f, Cost c) : from(a), to(b), cap(f), flow(0), cost(c) {}
			};

			Edge GetEdge(int i) const {return _edges[i];}
			std::vector<Edge> Edges() const {return _edges;}

			std::pair<Cap, Cost> flow(int s, int t) {return flow(s, t, std::numeric_limits<Cap>::max());}
			std::pair<Cap, Cost> flow(int s, int t, Cap flow_limit) {return slope(s, t, flow_limit).back();}
			std::vector<std::pair<Cap, Cost>> slope(int s, int t) {return slope(s, t, std::numeric_limits<Cap>::max());}
			std::vector<std::pair<Cap, Cost>> slope(int s, int t, Cap flow_limit) {
				int m = int(_edges.size());
				std::vector<int> edge_idx(m);

				auto g = [&]() {
					std::vector<int> degree(_n), redge_idx(m);
					std::vector<std::pair<int, _Edge>> elist;
					elist.reserve(m << 1);
					for (int i = 0; i < m; i++) {
						auto e = _edges[i];
						edge_idx[i] = degree[e.from]++;
						redge_idx[i] = degree[e.to]++;
						elist.push_back(make_pair(e.from, _Edge(e.to, -1, e.cap - e.flow, e.cost)));
						elist.push_back(make_pair(e.to, _Edge(e.from, -1, e.flow, -e.cost)));
					}
					auto _g = internal::csr<_Edge>(_n, elist);
					for (int i = 0; i < m; i++) {
						auto e = _edges[i];
						edge_idx[i] += _g.start[e.from];
						redge_idx[i] += _g.start[e.to];
						_g.elist[edge_idx[i]].rev = redge_idx[i];
						_g.elist[redge_idx[i]].rev = edge_idx[i];
					}
					return _g;
				}();

				auto result = slope(g, s, t, flow_limit);
				
				for (int i = 0; i < m; i++) _edges[i].flow = _edges[i].cap - g.elist[edge_idx[i]].cap;
				return result;
			}

		private:
			int _n;
			std::vector<Edge> _edges;

			struct _Edge {
				int to, rev;
				Cap cap;
				Cost cost;
				_Edge() {}
				_Edge(int a, int b, Cap f, Cost c): to(a), rev(b), cap(f), cost(c) {}
			};

			std::vector<std::pair<Cap, Cost>> slope(internal::csr<_Edge>& g, int s, int t, Cap flow_limit) {
				std::vector<std::pair<Cost, Cost>> dual_dist(_n);
				std::vector<int> prev_e(_n);
				std::vector<bool> vis(_n);
				struct Q {
					Cost key;
					int to;
					Q(Cost a, int b): key(a), to(b) {}
					bool operator < (Q r) const {return key > r.key;}
				};
				std::vector<int> que_min;
				std::vector<Q> que;
				auto dual_ref = [&]() {
					for (int i = 0; i < _n; i++) dual_dist[i].second = std::numeric_limits<Cost>::max();
					std::fill(vis.begin(), vis.end(), false);
					que_min.clear();
					que.clear();

					size_t heap_r = 0;

					dual_dist[s].second = 0;
					que_min.push_back(s);
					while (!que_min.empty() || !que.empty()) {
						int v;
						if (!que_min.empty()) {
							v = que_min.back();
							que_min.pop_back();
						}
						else {
							while (heap_r < que.size()) {
								heap_r++;
								std::push_heap(que.begin(), que.begin() + heap_r);
							}
							v = que.front().to;
							std::pop_heap(que.begin(), que.end());
							que.pop_back();
							heap_r--;
						}
						if (vis[v]) continue;
						vis[v] = true;
						if (v == t) break;
						Cost dual_v = dual_dist[v].first, dist_v = dual_dist[v].second;
						for (int i = g.start[v]; i < g.start[v + 1]; i++) {
							auto e = g.elist[i];
							if (!e.cap) continue;
							Cost cost = e.cost - dual_dist[e.to].first + dual_v;
							if (dual_dist[e.to].second - dist_v > cost) {
								Cost dist_to = dist_v + cost;
								dual_dist[e.to].second = dist_to;
								prev_e[e.to] = e.rev;
								if (dist_to == dist_v) que_min.push_back(e.to);
								else que.push_back(Q(dist_to, e.to));
							}
						}
					}
					if (!vis[t]) return false;

					for (int v = 0; v < _n; v++) if (vis[v]) dual_dist[v].first -= dual_dist[t].second - dual_dist[v].second;
					return true;
				};
				Cap flow = 0;
				Cost cost = 0, prev_cost_per_flow = -1;
				std::vector<std::pair<Cap, Cost>> result = {make_pair(Cap(0), Cost(0))};
				while (flow < flow_limit) {
					if (!dual_ref()) break;
					Cap c = flow_limit - flow;
					for (int v = t; v != s; v = g.elist[prev_e[v]].to) c = std::min(c, g.elist[g.elist[prev_e[v]].rev].cap);
					for (int v = t; v != s; v = g.elist[prev_e[v]].to) {
						auto &e = g.elist[prev_e[v]];
						e.cap += c;
						g.elist[e.rev].cap -= c;
					}
					Cost d = -dual_dist[s].first;
					flow += c;
					cost += c * d;
					if (prev_cost_per_flow == d) result.pop_back();
					result.push_back(make_pair(flow, cost));
					prev_cost_per_flow = d;
				}
				return result;
			}
	};
}

