#include "C:\Users\ianli\Desktop\CP\template\Flow\Dinic.cpp"
// output saved in vector<pair<int, int>> gomory_tree[kN];
// AddEdge -> bidirectional Cut(u, v) = min edge in path(u, v)
template <typename T> struct Gomory_Hu {
	Dinic<T> dinic;
	vector<pair<int, int>> gomory_tree[kN];
	int size;
	void init(int n) {
		size = n;
		dinic.init(n);
		return ;
	}

	void Gomory(vector<int> &v, int rep = 1) {
		if (v.size() <= 1) return;
		int cut, s = v[0], t = v[1];
		vector<int> l, r;
		dinic.Reweight();
		cut = Dinic(s, t);
		for (int i : v)
			if (went[i] == went[s]) l.push_back(i);
			else r.push_back(i);
		gomory_tree[s].push_back(make_pair(t, cut));
		gomory_tree[t].push_back(make_pair(s, cut));
		Gomory(l, t);
		Gomory(r, s);
		return;
	}

	void Build() {
		for (int i = 0; i < size; i++) gomory_tree[i].clear();
		vector<int> all;
		all.resize(size);
		for (int i = 0; i < size; i++) all[i] = i;
		Gomory(all, size);
		return;
	}
};
