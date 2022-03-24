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

template <typename T> void Output::W (const T& n) {
	if (n < 0) {
		WC('-');
		WP(-n);
	}
	else WP(n);
	return ;
}

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

// --- private ---

void Output::flush() { fwrite(buffer, 1, pointer, file); pointer = 0; return ; }
