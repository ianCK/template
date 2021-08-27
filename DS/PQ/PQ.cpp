template <typename T, typename T1 = vector<T>, typename T2 = less<T>> class Erasable_PQ {
	private:
		priority_queue<T, T1, T2> _pq, _xpq;
		void pull();

	public:
		Erasable_PQ();
		~Erasable_PQ();

		bool empty() const; 
		int size() const;
		void clear();

		void push(T x);
		void pop();
		T top();

		void erase(T x);

		void out() const;
};

template <typename T, typename T1, typename T2> void Erasable_PQ<T, T1, T2>::pull() {
	while (!_xpq.empty() && _xpq.top() == _pq.top()) _xpq.pop(), _pq.pop();
	return ;
}

template <typename T, typename T1, typename T2> Erasable_PQ<T, T1, T2>::Erasable_PQ() {}
template <typename T, typename T1, typename T2> Erasable_PQ<T, T1, T2>::~Erasable_PQ() {}

template <typename T, typename T1, typename T2> bool Erasable_PQ<T, T1, T2>::empty() const {return int(_pq.size()) - int(_xpq.size()) == 0;}
template <typename T, typename T1, typename T2> int Erasable_PQ<T, T1, T2>::size() const {return int(_pq.size()) - int(_xpq.size());}
template <typename T, typename T1, typename T2> void Erasable_PQ<T, T1, T2>::clear() {
	priority_queue<T, T1, T2> pq, xpq;
	swap(pq, _pq);
	swap(xpq, _xpq);
	return ;
}

template <typename T, typename T1, typename T2> void Erasable_PQ<T, T1, T2>::push(T x) {return _pq.push(x);}
template <typename T, typename T1, typename T2> void Erasable_PQ<T, T1, T2>::pop() {return _pq.pop();}
template <typename T, typename T1, typename T2> T Erasable_PQ<T, T1, T2>::top() {
	pull();
	return _pq.top();
}

template <typename T, typename T1, typename T2> void Erasable_PQ<T, T1, T2>::erase(T x) {
	_xpq.push(x);
	return ;
}

template <typename T, typename T1, typename T2> void Erasable_PQ<T, T1, T2>::out() const {
	if (this -> size() == 0) printf("empty");
	else {
		priority_queue<T, T1, T2> pq(_pq), xpq(_xpq);
		bool first = true;
		printf("(");
		while (!pq.empty()) {
			while (!xpq.empty() && xpq.top() == pq.top()) xpq.pop(), pq.pop();
			if (!pq.empty()) {
				if (first) first = false;
				else printf(", ");
				_print(pq.top());

				pq.pop();
			}
		}
		printf(")");
	}
	return ;
}

template <typename T> using EPQ = Erasable_PQ<T, vector<T>, less<T>>;
template <typename T> using EPQ_R = Erasable_PQ<T, vector<T>, greater<T>>;
