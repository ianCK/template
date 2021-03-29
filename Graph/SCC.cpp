// Directed edge
// constexpr kN = ?
// went.reset(), in.reset()
// (t = 0, scccnt = 0) (not necessary)
// scc saved in Tarjan::scc[kN], scccnt : 0 ~ x - 1
// graph saved in vector<int> graph[kN]
// reusable

namespace Tarjan {
	int dep[kN], low[kN], t, scc[kN], scccnt;
	bitset<kN> went, in;
	stack<int> st;
}

void tarjan(int cur) {
	Tarjan::dep[cur] = Tarjan::low[cur] = Tarjan::t++;
	Tarjan::went[cur] = Tarjan::in[cur] = true;
	Tarjan::st.push(cur);
	for (int i : graph[cur]) {
		if (!Tarjan::went[i]) tarjan(i);
		if (Tarjan::in[i]) Tarjan::low[cur] = min(Tarjan::low[cur], Tarjan::low[i]);
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
