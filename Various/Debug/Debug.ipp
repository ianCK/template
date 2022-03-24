DebugOutput::DebugOutput() : output(stderr) {}
DebugOutput::DebugOutput(FILE* file) : output(file) {}
DebugOutput::DebugOutput(string path) : output(path) {}

template <typename T> void DebugOutput::W (const T& n) { return output.W(n); }
template <typename T, typename... Targs> void DebugOutput::W(const T& n, const Targs&... Fargs) { return output.W(n, Fargs...); }
template <typename T> void DebugOutput::WP(const T& n) { return output.WP(n); }
template <typename T> void DebugOutput::WD(const T& n) { return output.WD(n); }
void DebugOutput::WC(char c) { return output.WC(c); }
void DebugOutput::WS(const string& s) { return output.WS(s); }
void DebugOutput::WSpace() { return output.WSpace(); }
void DebugOutput::WLine() { return output.WLine(); }

void DebugOutput::flush() { return output.flush(); }

template <> void DebugOutput::print<short>(const short& n) { return W(n); }
template <> void DebugOutput::print<unsigned short>(const unsigned short& n) { return WP(n); }

template <> void DebugOutput::print<int>(const int& n) { return W(n); }
template <> void DebugOutput::print<unsigned int>(const unsigned int& n) { return WP(n); }

template <> void DebugOutput::print<long>(const long& n) { return W(n); }
template <> void DebugOutput::print<unsigned long>(const unsigned long& n) { return WP(n); }

template <> void DebugOutput::print<long long int>(const long long int& n) { return W(n); }
template <> void DebugOutput::print<unsigned long long int>(const unsigned long long int& n) { return WP(n); }

#ifdef __SIZEOF_INT128__
template <> void DebugOutput::print<__int128>(const __int128& n) { return W(n); }
template <> void DebugOutput::print<unsigned __int128>(const unsigned __int128& n) { return WP(n); }
#endif

template <> void DebugOutput::print<bool>(const bool& n) { return (n ? WS("true") : WS("false")); }

template <> void DebugOutput::print<char>(const char& n) { return WC(n); }
template <> void DebugOutput::print<unsigned char>(const unsigned char& n) { return WP(n); }

template <> void DebugOutput::print<float>(const float& n) { return W(n); }
template <> void DebugOutput::print<double>(const double& n) { return W(n); }
template <> void DebugOutput::print<long double>(const long double& n) { return W(n); }

void DebugOutput::print(const char* n) { return WS(n); }
template <> void DebugOutput::print<string>(const string& n) { return WS(n); }

template <typename T> void DebugOutput::printp(const T& n, falseType ft) {
	WC(','); WSpace(); W(n);
	return ;
}
template <typename T> void DebugOutput::printp(const T& n, trueType tt) {
	W(n);
	return ;
}

template <typename T1, typename T2> void DebugOutput::print(const pair<T1, T2>& n) {
	WC('('); W(n.first); printp<falseType>(n.second); WC(')');
	return ;
}

template <int i, typename... Targs> void DebugOutput::printi(const tuple<Targs...>& n) {
	return printp(get<i>(n), boolType<isZero<i>::value>());
}

template <int... Is, typename... Targs> void DebugOutput::print(const tuple<Targs...>& n, integer_sequence<int, Is...> seq) {
	[[maybe_unused]] auto l = { (printi<Is>(n), 0)... };
	return ;
}

template <typename... Targs> void DebugOutput::print(const tuple<Targs...>& n) {
	WC('('); print(n, make_integer_sequence<int, sizeof...(Targs)>()); WC(')');
	return ;
}

// TODO
// bitset
//
// vector
//
// stack
// queue
// deque
//
// set
// map
// pq

template <typename T> void DebugOutput::print(const T& n) {
	n.out(output);
	return ;
}

template <typename T, typename... Targs> void DebugOutput::print(const T& n, const Targs&... Fargs) { print(n); WC(','); WSpace(); return print(Fargs...); }
template <typename T> void DebugOutput::printArray(int n, T* x) {
	for (int i = 1; i <= n; i++) {
		WSpace();
		print(x[i]);
	}

	WLine();
	return ;
}

template <typename T> void DebugOutput::printArray0(int n, T* x) {
	for (int i = 0; i < n; i++) {
		WSpace();
		print(x[i]);
	}

	WLine();
	return ;
}

template <typename T> void DebugOutput::printArrayLn(int n, T* x) {
	for (int i = 1; i <= n; i++) {
		print(x[i]);
		WLine();
	}

	return ;
}

template <typename T> void DebugOutput::printArray0Ln(int n, T* x) {
	for (int i = 0; i < n; i++) {
		print(x[i]);
		WLine();
	}

	return ;
}
