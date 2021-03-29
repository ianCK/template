// Bidirected edge
// constexpr kN = ?, kM = ?
// went.reset(), in.reset(), used.reset()
// (t = 0, scccnt = 0) (not necessary)
// scc saved in Tarjan::scc[kN], scccnt : 0 ~ x - 1
// graph saved in vector<pair<int, int>> graph[kN] : (to, id)
// reusable

namespace Tarjan {
	int dep[kN], low[kN], t, scc[kN], scccnt;
	bitset<kN> went, in;
	bitset<kM> used;
	stack<int> st;
}

void tarjan(int cur) {
	Tarjan::dep[cur] = Tarjan::low[cur] = Tarjan::t++;
	Tarjan::went[cur] = Tarjan::in[cur] = true;
	Tarjan::st.push(cur);
	for (pair<int, int> i : graph[cur]) if (!used[i.second]) {
		used[i.second] = true;
		if (!went[i.first]) tarjan(i.first);
		if (in[i.first]) Tarjan::low[cur] = min(Tarjan::low[cur], Tarjan::low[i.first]);
	}
	
	if (Tarjan::dep[cur] == Tarjan::low[cur]) {
		while (Tarjan::st.top() != cur) {
			Tarjan::in[Tarjan::st.top()] = false;
			Tarjan::scc[Tarjan::st.top()] = Tarjan::scccnt;
			Tarjan::st.pop();
		}
		Tarjan::in[cur] = false;
		Tarjan::scc[cur] = Tarjan::scccnt++;
		Tarjan::st.pop();
	}
	return ;
}
