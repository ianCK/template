// 0-based
template <int K, typename T, typename Comp = less<T>> struct BestK {
	private:
		Comp comp;
		T _val[K];
		int _size;

	public:
		BestK() : _size(0) {}
		~BestK() {}
		inline int size() const {return _size;}

		bool insert(T x) {
			for (int i = 0; i < _size; i++) if (comp(x, _val[i])) {
				for (int j = i; j < _size; j++) swap(x, _val[j]);
				if (_size < K) _val[_size++] = x;
				return true;
			}

			if (_size < K) {
				_val[_size++] = x;
				return true;
			}

			return false;
		}
		T operator [](int x) const {return _val[x];}
};

template <int size, typename T> using WorstK = BestK<size, T, greater<T>>;
