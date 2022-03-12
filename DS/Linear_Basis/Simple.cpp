template <typename T> class Linear_Basis {
	public:
		T base[sizeof(T) << 3];
		int sz;

		Linear_Basis() : sz(0) {}
		Linear_Basis(const Linear_Basis& other) : sz(other.sz) {
			memcpy(base, other.base, sizeof(T) * other.sz);
		}

		void insert(T x) {
			for (int i = 0; i < sz; i++) chmin(x, x ^ base[i]);
			if (x) base[sz++] = x;
			return ;
		}

		bool ask(T x) const {
			for (int i = 0; i < sz; i++) chmin(x, x ^ base[i]);
			return !x;
		}
};

template <typename T> Linear_Basis<T> Merge(const Linear_Basis<T> &lhs, const Linear_Basis<T> &rhs) {
	Linear_Basis<T> ans(lhs);
	for (int i = 0; i < rhs.sz; i++) ans.insert(rhs.base[i]);
	return ans;
}
