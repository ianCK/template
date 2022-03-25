Debugger::Debugger() : output(stderr) {}
Debugger::Debugger(FILE* file) : output(file) {}
Debugger::Debugger(string path) : output(path) {}

template <typename T> void Debugger::W (const T& n) { return output.W(n); }
template <typename T, typename... Targs> void Debugger::W(const T& n, const Targs&... Fargs) { return output.W(n, Fargs...); }
template <typename T> void Debugger::WP(const T& n) { return output.WP(n); }
template <typename T> void Debugger::WD(const T& n) { return output.WD(n); }
void Debugger::WC(char c) { return output.WC(c); }
void Debugger::WS(const string& s) { return output.WS(s); }
void Debugger::WSpace() { return output.WSpace(); }
void Debugger::WLine() { return output.WLine(); }

void Debugger::flush() { return output.flush(); }

template <> void Debugger::print<short>(const short& n) { return W(n); }
template <> void Debugger::print<unsigned short>(const unsigned short& n) { return WP(n); }

template <> void Debugger::print<int>(const int& n) { return W(n); }
template <> void Debugger::print<unsigned int>(const unsigned int& n) { return WP(n); }

template <> void Debugger::print<long>(const long& n) { return W(n); }
template <> void Debugger::print<unsigned long>(const unsigned long& n) { return WP(n); }

template <> void Debugger::print<long long int>(const long long int& n) { return W(n); }
template <> void Debugger::print<unsigned long long int>(const unsigned long long int& n) { return WP(n); }

#ifdef __SIZEOF_INT128__
template <> void Debugger::print<__int128>(const __int128& n) { return W(n); }
template <> void Debugger::print<unsigned __int128>(const unsigned __int128& n) { return WP(n); }
#endif

template <> void Debugger::print<bool>(const bool& n) { return (n ? WS("true") : WS("false")); }

template <> void Debugger::print<char>(const char& n) { return WC(n); }
template <> void Debugger::print<unsigned char>(const unsigned char& n) { return WP(n); }

template <> void Debugger::print<float>(const float& n) { return W(n); }
template <> void Debugger::print<double>(const double& n) { return W(n); }
template <> void Debugger::print<long double>(const long double& n) { return W(n); }

void Debugger::print(const char* n) { return WS(n); }
template <> void Debugger::print<string>(const string& n) { return WS(n); }

template <typename T1, typename T2> void Debugger::print(const pair<T1, T2>& n) {
	WC('('); print(n.first); WS(", "); print(n.second); WC(')');
	return ;
}

template <typename... Targs> void Debugger::print(const tuple<Targs...>& n) {
	WC('('); print(n, make_integer_sequence<int, sizeof...(Targs)>()); WC(')');
	return ;
}

template <size_t N> void Debugger::print(const bitset<N>& bs) {
	for (size_t i = 0; i < N; i++) {
		if (bs.test(i)) WC('1');
		else WC('0');
	}
	return ;
}

template <typename T> void Debugger::print(const vector<T>& vec) {
	WC('[');
	if (vec.empty()) WS("empty");
	else {
		int sz = int(vec.size());
		print(vec[0]); for (int i = 1; i < sz; i++) { WS(", "); print(vec[i]); }
	}
	WC(']');
	return ;
}

template <typename T> void Debugger::print(const stack<T>& st) {
	stack<T> tmp(st);
	WC('{');
	if (tmp.empty()) WS("empty");
	else {
		print(tmp.top()); tmp.pop();
		while (!tmp.empty()) { WS(", "); print(tmp.top()); tmp.pop(); }
	}
	WC('}');
	return ;
}

template <typename T> void Debugger::print(const queue<T>& qu) {
	queue<T> tmp(qu);
	WC('{');
	if (tmp.empty()) WS("empty");
	else {
		print(tmp.front()); tmp.pop();
		while (!tmp.empty()) { WS(", "); print(tmp.front()); tmp.pop(); }
	}
	WC('}');
	return ;
}

template <typename T> void Debugger::print(const deque<T>& dq) {
	WC('{');
	if (dq.empty()) WS("empty");
	else {
		int sz = int(dq.size());
		print(dq[0]); for (int i = 1; i < sz; i++) { WS(", "); print(dq[i]); }
	}
	WC('}');
	return ;
}

template <typename T1, typename T2, typename T3> void Debugger::print(const priority_queue<T1, T2, T3>& pq) {
	priority_queue<T1, T2, T3> tmp(pq);
	WC('{');
	if (tmp.empty()) WS("empty");
	else {
		print(tmp.top()); tmp.pop();
		while (!tmp.empty()) { WS(", "); print(tmp.top()); tmp.pop(); }
	}
	WC('}');
	return ;
}

template <typename T> void Debugger::print(const set<T>& se) {
	WC('{');
	if (se.empty()) WS("empty");
	else {
		bool first = true;
		for (const T& i : se) {
			if (first) first = false;
			else WS(", ");
			print(i);
		}
	}
	WC('}');
	return ;
}

template <typename T1, typename T2> void Debugger::print(const map<T1, T2>& ma) {
	WC('{');
	if (ma.empty()) WS("empty");
	else {
		bool first = true;
		for (const pair<const T1, T2>& i : ma) {
			if (first) first = false;
			else WS(", ");
			print(i);
		}
	}
	WC('}');
	return ;
}

template <typename T> void Debugger::print(const T& n) {
	n.out(output);
	return ;
}

template <typename T, typename... Targs> void Debugger::print(const T& n, const Targs&... Fargs) { print(n); WC(','); WSpace(); return print(Fargs...); }
template <typename T> void Debugger::printArray(int n, T* x) {
	for (int i = 1; i <= n; i++) {
		WSpace();
		print(x[i]);
	}

	WLine();
	return ;
}

template <typename T> void Debugger::printArray0(int n, T* x) {
	for (int i = 0; i < n; i++) {
		WSpace();
		print(x[i]);
	}

	WLine();
	return ;
}

template <typename T> void Debugger::printArrayLn(int n, T* x) {
	for (int i = 1; i <= n; i++) {
		print(x[i]);
		WLine();
	}

	return ;
}

template <typename T> void Debugger::printArray0Ln(int n, T* x) {
	for (int i = 0; i < n; i++) {
		print(x[i]);
		WLine();
	}

	return ;
}

// --- private ---

template <typename T> void Debugger::printp(const T& n, falseType ft) {
	WS(", "); print(n);
	return ;
}
template <typename T> void Debugger::printp(const T& n, trueType tt) {
	print(n);
	return ;
}

template <int i, typename... Targs> void Debugger::printi(const tuple<Targs...>& n) {
	return printp(get<i>(n), boolType<isZero<i>::value>());
}

template <int... Is, typename... Targs> void Debugger::print(const tuple<Targs...>& n, integer_sequence<int, Is...> seq) {
	[[maybe_unused]] auto l = { (printi<Is>(n), 0)... };
	return ;
}
