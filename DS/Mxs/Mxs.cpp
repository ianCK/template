template <typename T1, typename T2, typename Comp = less<T1>> class Mxs {
	private:
		Comp _comp;
		T1 _cur_mx;
		vector<T2> _val;

	public:
		Mxs();
		~Mxs();

		int size() const;
		bool empty() const;
		void reserve(int x);
		void clear();
		T1 mx() const;
		T2 any() const;
		bool insert(T1 key, T2 val);

		vector<T2> operator ()();

		void out() const;
};

template <typename T1, typename T2, typename Comp> Mxs<T1, T2, Comp>::Mxs() {}
template <typename T1, typename T2, typename Comp> Mxs<T1, T2, Comp>::~Mxs() {}

template <typename T1, typename T2, typename Comp> int Mxs<T1, T2, Comp>::size() const {return int(_val.size());}
template <typename T1, typename T2, typename Comp> bool Mxs<T1, T2, Comp>::empty() const {return _val.empty();}
template <typename T1, typename T2, typename Comp> void Mxs<T1, T2, Comp>::reserve(int x) {return _val.reserve(x);}
template <typename T1, typename T2, typename Comp> void Mxs<T1, T2, Comp>::clear() {return _val.clear();}
template <typename T1, typename T2, typename Comp> T1 Mxs<T1, T2, Comp>::mx() const {return _cur_mx;}
template <typename T1, typename T2, typename Comp> T2 Mxs<T1, T2, Comp>::any() const {return _val[0];}

template <typename T1, typename T2, typename Comp> bool Mxs<T1, T2, Comp>::insert(T1 key, T2 val) {
	if (_val.empty()) {
		_cur_mx = key;
		_val.push_back(val);
		return true;
	}
	else if (_comp(_cur_mx, key)) {
		_cur_mx = key;
		_val.clear();
		_val.push_back(val);
		return true;
	}
	else if (!_comp(key, _cur_mx)) {
		_val.push_back(val);
		return true;
	}
	else return false;
}

template <typename T1, typename T2, typename Comp> vector<T2> Mxs<T1, T2, Comp>::operator ()() {return move(_val);}

template <typename T1, typename T2, typename Comp> void Mxs<T1, T2, Comp>::out() const {
	if (this -> empty()) printf("empty");
	else {
		int sz = this -> size();
		printf("(");
		_print(_val[0]);
		for (int i = 1; i < sz; i++) {
			printf(", ");
			_print(_val[i]);
		}
		printf(")");
	}
}

template <typename T1, typename T2> using Mns = Mxs<T1, T2, greater<T1>>;
