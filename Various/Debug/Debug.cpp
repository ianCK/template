void _print(bool x) {printf("%d", x ? 1 : 0);}
void _print(char x) {printf("%c", x);}
void _print(short x) {printf("%hd", x);}
void _print(unsigned short x) {printf("%hu", x);}
void _print(int x) {printf("%d", x);}
void _print(unsigned int x) {printf("%u", x);}
void _print(long long int x) {printf("%lld", x);}
void _print(unsigned long long int x) {printf("%llu", x);}
void _print(float x) {printf("%f", x);}
void _print(double x) {printf("%lf", x);}
void _print(long double x) {printf("%Lf", x);}
template <typename T1, typename T2> void _print(pair<T1, T2> x) {printf("("); _print(x.first); printf(", "); _print(x.second); printf(")");}
template <typename T1, typename T2, typename T3> void _print(tuple<T1, T2, T3> x) {printf("("); _print(get<0>(x)); printf(", "); _print(get<1>(x)); printf(", "); _print(get<2>(x)); printf(")");}
template <typename T> void _print(vector<T> v) {
	if (v.empty()) printf(" empty");
	else for (T i : v) printf(" "), _print(i);
}
template <typename T> void _print(set<T> s) {
	if (s.empty()) printf(" empty");
	else for (T i : s) printf(" "), _print(i);
}
template <typename T> void _print(stack<T> s) {
	if (s.empty()) printf(" empty");
	else while (!s.empty()) {printf(" "); _print(s.top()); s.pop();}
}
template <typename T> void _print(queue<T> q) {
	if (q.empty()) printf(" empty");
	else while (!q.empty()) {printf(" "); _print(q.front()); q.pop();}
}
template <typename T> void _print(deque<T> dq) {
	if (dq.empty()) printf(" empty");
	else {
		int sz = int(dq.size());
		for (int i = 0; i < sz; i++) printf(" "), _print(dq[i]);
	}
}
template <typename T1, typename T2, typename T3> void _print(priority_queue<T1, T2, T3> pq) {
	if (pq.empty()) printf(" empty");
	else while (!pq.empty()) {printf(" "); _print(pq.top()); pq.pop();}
}
template <int size> void _print(bitset<size> bs) {
	for (int i = 0; i < size; i++) printf("%d", bs[i] ? 1 : 0);
}
template <typename T1, typename T2> void _print(map<T1, T2> m) {
	if (m.empty()) printf(" empty");
	else for (pair<T1, T2> i : m) {printf(" "); _print(i);}
}

template <typename T> void _print(T x) {return x.out();}
template <typename T, typename... Targs> void _print(T x, Targs... Fargs) {_print(x); printf(", "); _print(Fargs...);}
