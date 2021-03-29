template <typename T, typename T1 = vector<T>, typename T2 = less<T>> struct myPQ {
	priority_queue<T, T1, T2> pq, xpq;
	
	inline void push(const T &x) {pq.push(x);}
	inline void pop() {pq.pop();}
	inline T top() const {return pq.top();}
	inline bool empty() const {return pq.empty();}
	inline int size() const {return pq.size();}
	void clear() {
		while (!pq.empty()) pq.pop();
		while (!xpq.empty()) xpq.pop();
		return ;
	}
	void erase(const T &x) {
		xpq.push(x);
		while (!xpq.empty() && xpq.top() == pq.top()) xpq.pop(), pq.pop();
		return ;
	}
};
template <typename T> using MPQ = myPQ<T, vector<T>, less<T>>;
template <typename T> using MPQ_R = myPQ<T, vector<T>, greater<T>>;
