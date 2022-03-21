template <int bufferSize> Input<bufferSize>::Input() : file(stdin) { read(); }
template <int bufferSize> Input<bufferSize>::Input(FILE*  _file) : file(_file) { read(); }
template <int bufferSize> Input<bufferSize>::Input(string path) : file(fopen(path.c_str(), "r")) { read(); }

template <int bufferSize> template <typename T> void Input<bufferSize>::R (T& n) {
	static_assert(is_integral<T>::value, "R requires an integral type");
	char c;
	bool neg = false;
	while (!isDigit(c = getRawChar())) if (c == '-') neg = true;
	n = int(c - '0');
	while (isDigit(c = getRawChar())) n = n * 10 + int(c - '0');
	if (neg) n = -n;
	return ;
}

template <int bufferSize> template <typename T> void Input<bufferSize>::RP(T& n) {
	static_assert(is_integral<T>::value, "RP requires an integral type");
	char c;
	while (!isDigit(c = getRawChar())) ;
	n = int(c - '0');
	while (isDigit(c = getRawChar())) n = n * 10 + int(c - '0');
	return ;
}

template <int bufferSize> template <typename T> void Input<bufferSize>::RD(T& n) {
	static_assert(is_integral<T>::value, "RD requires an integral type");
	char c;
	while (!isDigit(c = getRawChar())) ;
	n = int(c - '0');
	return ;
}

template <int bufferSize> void Input<bufferSize>::RS(string& s) {
	s.clear();
	char c = getRawChar();
	while (c == ' ' or c == '\n') c = getRawChar();
	while (c != ' ' and c != '\n') {
		s += c;
		c = getRawChar();
	}
	return ;
}

template <int bufferSize> template <typename T, typename... Targs> void Input<bufferSize>::R (T& n, Targs&... Fargs) { R(n); return R(Fargs...); }
template <int bufferSize> template <typename T, typename... Targs> void Input<bufferSize>::RP(T& n, Targs&... Fargs) { RP(n); return RP(Fargs...); }
template <int bufferSize> template <typename T, typename... Targs> void Input<bufferSize>::RD(T& n, Targs&... Fargs) { RD(n); return RD(Fargs...); }
template <int bufferSize> template <typename... Targs> void Input<bufferSize>::RS(string& s, Targs&... Fargs) { RS(s); return RS(Fargs...); }
template <int bufferSize> template <typename... Targs> void Input<bufferSize>::RL  (int n, Targs*... Fargs) { for (int i = 1; i <= n; i++) RLi(i, Fargs...); }
template <int bufferSize> template <typename... Targs> void Input<bufferSize>::RL0 (int n, Targs*... Fargs) { for (int i = 0; i < n; i++)  RLi(i, Fargs...); }
template <int bufferSize> template <typename... Targs> void Input<bufferSize>::RLP (int n, Targs*... Fargs) { for (int i = 1; i <= n; i++) RLPi(i, Fargs...); }
template <int bufferSize> template <typename... Targs> void Input<bufferSize>::RLP0(int n, Targs*... Fargs) { for (int i = 0; i < n; i++)  RLPi(i, Fargs...); }
template <int bufferSize> template <typename... Targs> void Input<bufferSize>::RLD (int n, Targs*... Fargs) { for (int i = 1; i <= n; i++) RLDi(i, Fargs...); }
template <int bufferSize> template <typename... Targs> void Input<bufferSize>::RLD0(int n, Targs*... Fargs) { for (int i = 0; i < n; i++)  RLDi(i, Fargs...); }
template <int bufferSize> template <typename... Targs> void Input<bufferSize>::RLS (int n, Targs*... Fargs) { for (int i = 1; i <= n; i++) RLSi(i, Fargs...); }
template <int bufferSize> template <typename... Targs> void Input<bufferSize>::RLS0(int n, Targs*... Fargs) { for (int i = 0; i < n; i++)  RLSi(i, Fargs...); }

// --- private ---

template <int bufferSize> void Input<bufferSize>::read() { fread(buffer, 1, bufferSize, file); pointer = 0; return ; }

template <int bufferSize> char Input<bufferSize>::getRawChar() {
	if (pointer == bufferSize) read();
	return buffer[pointer++];
}

template <int bufferSize> bool Input<bufferSize>::isDigit(char c) { return '0' <= c and c <= '9'; }

template <int bufferSize> template <typename T> void Input<bufferSize>::RLi(int i, T* a) { return R(a[i]); }
template <int bufferSize> template <typename T, typename... Targs> void Input<bufferSize>::RLi(int i, T* a, Targs*... Fargs) { R(a[i]); return RLi(i, Fargs...); }

template <int bufferSize> template <typename T> void Input<bufferSize>::RLPi(int i, T* a) { return RP(a[i]); }
template <int bufferSize> template <typename T, typename... Targs> void Input<bufferSize>::RLPi(int i, T* a, Targs*... Fargs) { RP(a[i]); return RLPi(i, Fargs...); }

template <int bufferSize> template <typename T> void Input<bufferSize>::RLDi(int i, T* a) { return RD(a[i]); }
template <int bufferSize> template <typename T, typename... Targs> void Input<bufferSize>::RLDi(int i, T* a, Targs*... Fargs) { RD(a[i]); return RLDi(i, Fargs...); }

template <int bufferSize> void Input<bufferSize>::RLSi(int i, string* a) { return RS(a[i]); }
template <int bufferSize> template <typename... Targs> void Input<bufferSize>::RLSi(int i, string* a, Targs*... Fargs) { RS(a[i]); return RSi(i, Fargs...); }
