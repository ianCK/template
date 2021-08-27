template <int size> struct Connected_State {
	int v[size];
	int color_count;
	vector<pair<int, int>> vec; // min_pos, original color

	Connected_State() : color_count(0) {memset(v, -1, sizeof(v));}
	~Connected_State() {}

	inline int component_count() const {return color_count + 1;}

	void pull() {
		// O(size lg(size))
		sort(vec);
		
		int sz = int(vec.size());
		vector<int> to_color(sz);
		for (int i = 0; i < sz; i++) to_color[vec[i].second] = i;
		for (int i = 0; i < size; i++) if (v[i] >= 0) v[i] = to_color[v[i]];
		for (int i = 0; i < sz; i++) vec[i].second = i;

		return ;
	}

	void Merge(int a, int b) {
		// assert(v[a] >= 0 and v[b] >= 0);
		int a_color = v[a], b_color = v[b];
		int lowest = size;
		for (int i = 0; i < size; i++) if (v[i] == b_color) v[i] = a_color;

		int sz = int(vec.size());
		for (int i = 0; i < sz; i++) {
			if (vec[i].second == a_color) chmin(vec[i].first, lowest);
			if (vec[i].second == b_color) {
				swap(vec[i], vec.back());
				vec.pop_back();
				sz--;
				i--;
			}
		}

		pull();
		return ;
	}

	void new_component(int pos) {
		vec.push_back(make_pair(pos, color_count));
		v[pos] = color_count++;
		pull();
		return ;
	}

	bool operator == (const Connected_State &x) const {return memcmp(v, x.v, sizeof(v)) == 0;}
	int& operator [] (int x) {return v[x];}

	void out() {
		printf("v :"); for (int i = 0; i < size; i++) printf(" %d", v[i]); printf("\n");
		return ;
	}
};
