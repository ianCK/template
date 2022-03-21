Input::Input() : file(stdin) { read(); }
Input::Input(FILE*  _file) : file(_file) { read(); }
Input::Input(string path) : file(fopen(path.c_str(), "r")) { read(); }

template <typename T> void Input::R (T& n) {
	static_assert(is_integral<T>::value, "R requires an integral type");
	char c;
	bool neg = false;
	while (!isDigit(c = getRawChar())) if (c == '-') neg = true;
	n = int(c - '0');
	while (isDigit(c = getRawChar())) n = n * 10 + int(c - '0');
	if (neg) n = -n;
	return ;
}

template <typename T> void Input::RP(T& n) {
	static_assert(is_integral<T>::value, "RP requires an integral type");
	char c;
	while (!isDigit(c = getRawChar())) ;
	n = int(c - '0');
	while (isDigit(c = getRawChar())) n = n * 10 + int(c - '0');
	return ;
}

template <typename T> void Input::RD(T& n) {
	static_assert(is_integral<T>::value, "RD requires an integral type");
	char c;
	while (!isDigit(c = getRawChar())) ;
	n = int(c - '0');
	return ;
}

void Input::RS(string& s) {
	s.clear();
	char c = getRawChar();
	while (c == ' ' or c == '\n') c = getRawChar();
	while (c != ' ' and c != '\n') {
		s += c;
		c = getRawChar();
	}
	return ;
}

template <typename T, typename... Targs> void Input::R (T& n, Targs&... Fargs) { R(n); return R(Fargs...); }
template <typename T, typename... Targs> void Input::RP(T& n, Targs&... Fargs) { RP(n); return RP(Fargs...); }
template <typename T, typename... Targs> void Input::RD(T& n, Targs&... Fargs) { RD(n); return RD(Fargs...); }
template <typename... Targs> void Input::RS(string& s, Targs&... Fargs) { RS(s); return RS(Fargs...); }
template <typename... Targs> void Input::RL  (int n, Targs*... Fargs) { for (int i = 1; i <= n; i++) RLi(i, Fargs...); }
template <typename... Targs> void Input::RL0 (int n, Targs*... Fargs) { for (int i = 0; i < n; i++)  RLi(i, Fargs...); }
template <typename... Targs> void Input::RLP (int n, Targs*... Fargs) { for (int i = 1; i <= n; i++) RLPi(i, Fargs...); }
template <typename... Targs> void Input::RLP0(int n, Targs*... Fargs) { for (int i = 0; i < n; i++)  RLPi(i, Fargs...); }
template <typename... Targs> void Input::RLD (int n, Targs*... Fargs) { for (int i = 1; i <= n; i++) RLDi(i, Fargs...); }
template <typename... Targs> void Input::RLD0(int n, Targs*... Fargs) { for (int i = 0; i < n; i++)  RLDi(i, Fargs...); }
template <typename... Targs> void Input::RLS (int n, Targs*... Fargs) { for (int i = 1; i <= n; i++) RLSi(i, Fargs...); }
template <typename... Targs> void Input::RLS0(int n, Targs*... Fargs) { for (int i = 0; i < n; i++)  RLSi(i, Fargs...); }

// --- private ---

void Input::read() { fread(buffer, 1, bufferSize, file); pointer = 0; return ; }

char Input::getRawChar() {
	if (pointer == bufferSize) read();
	return buffer[pointer++];
}

bool Input::isDigit(char c) { return '0' <= c and c <= '9'; }

template <typename T> void Input::RLi(int i, T* a) { return R(a[i]); }
template <typename T, typename... Targs> void Input::RLi(int i, T* a, Targs*... Fargs) { R(a[i]); return RLi(i, Fargs...); }

template <typename T> void Input::RLPi(int i, T* a) { return RP(a[i]); }
template <typename T, typename... Targs> void Input::RLPi(int i, T* a, Targs*... Fargs) { RP(a[i]); return RLPi(i, Fargs...); }

template <typename T> void Input::RLDi(int i, T* a) { return RD(a[i]); }
template <typename T, typename... Targs> void Input::RLDi(int i, T* a, Targs*... Fargs) { RD(a[i]); return RLDi(i, Fargs...); }

void Input::RLSi(int i, string* a) { return RS(a[i]); }
template <typename... Targs> void Input::RLSi(int i, string* a, Targs*... Fargs) { RS(a[i]); return RSi(i, Fargs...); }
