// a_lst < a_cur
// return max

template <class T> class MCHT {
	private:
		deque<tuple<T, T, T>> dq; // (a, b, pop_time)
		int sz;
		
		static T intersect(T lhs_a, T lhs_b, T rhs_a, T rhs_b);

	public:
		MCHT();
		void push(T a, T b);
		T ask(T x);
		T operator () (T x);

		void out() const;
};

template <class T> T MCHT<T>::intersect(T lhs_a, T lhs_b, T rhs_a, T rhs_b) {
	return (rhs_b - lhs_b) / (lhs_a - rhs_a);
}

template <class T> MCHT<T>::MCHT() : sz(0) {}

template <class T> void MCHT<T>::push(T a, T b) {
	while (sz > 1) {
		T pos = intersect(get<0>(dq.back()), get<1>(dq.back()), a, b);
		if (pos <= get<2>(dq[sz - 2])) dq.pop_back(), sz--;
		else break;
	}

	if (sz) {
		T pos = intersect(get<0>(dq.back()), get<1>(dq.back()), a, b);
		get<2>(dq.back()) = pos;
	}

	dq.push_back(make_tuple<T, T, T>(T(a), T(b), T(0))), sz++;
	return ;
}

template <class T> T MCHT<T>::ask(T x) {
	while (sz > 1 and x > get<2>(dq.front())) dq.pop_front(), sz--;
	return get<0>(dq.front()) * x + get<1>(dq.front());
}
template <class T> T MCHT<T>::operator () (T x) {return ask(x);}

template <class T> void MCHT<T>::out() const {return _print(dq);}
