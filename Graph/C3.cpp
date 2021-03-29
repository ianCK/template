// To Count C3 in simple graph in O(Msqrt(M))
// sort the graph by degree in non-ascending order
// 0-indexed

template <typename T> T Count_C3(const vector<vector<int>> &graph) {
	T ans = 0;
	int n = int(graph.size());
	vector<vector<int>> new_graph(n);
	vector<pair<int, int>> degree(n);
	vector<int> cnt(n), idx(n);

	for (int i = 0; i < n; i++) degree[i] = make_pair(int(graph[i].size()), i);
	sort(degree.begin(), degree.end(), greater<pair<int, int>>());

	for (int i = 0; i < n; i++) idx[degree[i].second] = i;
	for (int i = 0; i < n; i++) for (int j : graph[degree[i].second]) new_graph[i].push_back(idx[j]);
	for (int i = 0; i < n; i++) sort(new_graph[i].begin(), new_graph[i].end(), greater<int>());

	for (int i = 0; i < n; i++) {
		for (int j : new_graph[i]) new_graph[j].pop_back();
		for (int j : new_graph[i]) cnt[j] = 0;
		for (int j : new_graph[i]) for (int k : new_graph[j]) cnt[k]++;
		for (int j : new_graph[i]) ans += cnt[j];
	}

	return ans / 2;
}

tuple<int, int, int> Find_C3(const vector<vector<int>> &graph) {
	int n = int(graph.size());
	vector<vector<int>> new_graph(n);
	vector<pair<int, int>> degree(n);
	vector<int> went(n), idx(n);

	for (int i = 0; i < n; i++) degree[i] = make_pair(int(graph[i].size()), i);
	sort(degree.begin(), degree.end(), greater<pair<int, int>>());

	for (int i = 0; i < n; i++) idx[degree[i].second] = i;
	for (int i = 0; i < n; i++) for (int j : graph[degree[i].second]) new_graph[i].push_back(idx[j]);
	for (int i = 0; i < n; i++) sort(new_graph[i].begin(), new_graph[i].end(), greater<int>());

	for (int i = 0; i < n; i++) {
		for (int j : new_graph[i]) new_graph[j].pop_back();
		for (int j : new_graph[i]) went[j] = -1;
		for (int j : new_graph[i]) for (int k : new_graph[j]) went[k] = j;
		for (int j : new_graph[i]) if (~went[j]) return make_tuple(degree[i].second, degree[j].second, degree[went[j]].second);
	}

	return make_tuple(-1, -1, -1);
}
