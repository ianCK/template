Output::Output() : file(stdout), pointer(0) {}
Output::Output(FILE*  _file) : file(_file), pointer(0) {}
Output::Output(string path) : file(fopen(path.c_str(), "w")), pointer(0) {}
Output::~Output() { flush(); }

template <> void Output::W<char>(const char& n) { return WC(n); }

template <> void Output::W<float>(const float& n) { 
	static char buffer[50];
	sprintf(buffer, "%f", n);
	return WS(buffer); 
}

template <> void Output::W<double>(const double& n) {
	static char buffer[50];
	sprintf(buffer, "%lf", n);
	return WS(buffer); 
}

template <> void Output::W<long double>(const long double& n) {
	static char buffer[50];
	sprintf(buffer, "%Lf", n);
	return WS(buffer); 
}

template <> void Output::W<short>(const short& n) { return WInteger(n); }
template <> void Output::W<unsigned short>(const unsigned short& n) { return WP(n); }

template <> void Output::W<int>(const int& n) { return WInteger(n); }
template <> void Output::W<unsigned int>(const unsigned int& n) { return WP(n); }

template <> void Output::W<long>(const long& n) { return WInteger(n); }
template <> void Output::W<unsigned long>(const unsigned long& n) { return WP(n); }

template <> void Output::W<long long int>(const long long int& n) { return WInteger(n); }
template <> void Output::W<unsigned long long int>(const unsigned long long int& n) { return WP(n); }

#ifdef __SIZEOF_INT128__
template <> void Output::W<__int128>(const __int128& n) { return WInteger(n); }
template <> void Output::W<unsigned __int128>(const unsigned __int128& n) { return WP(n); }
#endif

template <typename T> void Output::W (const T& n) { return n.out(*this); }

template <typename T, typename... Targs> void Output::W(const T& n, const Targs&... Fargs) { W(n); return W(Fargs...); }

template <typename T> void Output::WP(const T& n) {
	if (n == 0) return WC('0');

	T tmp(n);
	static char buffer[40];
	int pointer = 0;

	while (tmp) {
		buffer[pointer++] = char(tmp % 10 + '0');
		tmp /= 10;
	}

	for (int i = pointer - 1; i >= 0; i--) WC(buffer[i]); 
	return ;
}

template <typename T> void Output::WD(const T& n) { return WC(char(n + '0')); }

void Output::WC(char c) {
	if (pointer == bufferSize) flush();
	buffer[pointer++] = c;
	return ;
}

void Output::WS(const string& s) { for (char c : s) WC(c); return ; }
void Output::WS(const char* s) { int i = 0; while (s[i]) WC(s[i++]); return ; }
void Output::WSpace() { return WC(' '); }
void Output::WLine() { return WC('\n'); }

void Output::flush() { fwrite(buffer, 1, pointer, file); pointer = 0; return ; }

// --- private ---

template <typename T> void Output::WInteger (const T& n) {
	if (n < 0) {
		WC('-');
		WP(-n);
	}
	else WP(n);
	return ;
}
