template <typename T> class Normalizer {
	private:
		vector<T> vec;

	public:
		Normalizer() {}
		Normalizer(int n) {vec.reserve(n);}

		inline void reserve(int n) {return vec.reserve(n);}
		inline void insert(T x) {return vec.push_back(x);}
		void build() {
			sort(vec.begin(), vec.end());
			vec.resize(unique(vec.begin(), vec.end()) - vec.begin());
			return ;
		}
		int getId(T x) {return lower_bound(vec.begin(), vec.end(), x) - vec.begin();}
		T getVal(int id) {return vec[id];}
};
