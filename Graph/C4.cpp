// To Count C4 in simple graph in O(Msqrt(M))
// sort the graph by degree in non-ascending order
// 0-indexed

template <typename T> T Count_C4(vector<vector<int>> &graph) {
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
		for (int j : new_graph[i]) for (int k : new_graph[j]) cnt[k] = 0;
		for (int j : new_graph[i]) for (int k : new_graph[j]) ans += cnt[k]++;
	}
	return ans;
}

tuple<int, int, int, int> Find_C4(vector<vector<int>> &graph) {
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
		for (int j : new_graph[i]) for (int k : new_graph[j]) went[k] = -1;
		for (int j : new_graph[i]) for (int k : new_graph[j]) 
			if (~went[k]) return make_tuple(degree[i].second, degree[j].second, degree[k].second, degree[went[k]].second);
			else went[k] = j;
	}

	return make_tuple(-1, -1, -1, -1);
}
