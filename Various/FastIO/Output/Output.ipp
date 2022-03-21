template <int bufferSize> Output<bufferSize>::Output() : file(stdout), pointer(0) {}
template <int bufferSize> Output<bufferSize>::Output(FILE*  _file) : file(_file), pointer(0) {}
template <int bufferSize> Output<bufferSize>::Output(string path) : file(fopen(path.c_str(), "w")), pointer(0) {}
template <int bufferSize> Output<bufferSize>::~Output() { flush(); }

template <int bufferSize> template <typename T> void Output<bufferSize>::W (const T& n) {
	if (n < 0) {
		WC('-');
		WP(-n);
	}
	else WP(n);
	return ;
}

template <int bufferSize> template <typename T> void Output<bufferSize>::WP(const T& n) {
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

template <int bufferSize> template <typename T> void Output<bufferSize>::WD(const T& n) { return WC(char(n + '0')); }

template <int bufferSize> void Output<bufferSize>::WC(char c) {
	if (pointer == bufferSize) flush();
	buffer[pointer++] = c;
	return ;
}

template <int bufferSize> void Output<bufferSize>::WS(const string& s) { for (char c : s) WC(c); return ; }
template <int bufferSize> void Output<bufferSize>::WSpace() { return WC(' '); }
template <int bufferSize> void Output<bufferSize>::WLine() { return WC('\n'); }

// --- private ---

template <int bufferSize> void Output<bufferSize>::flush() { fwrite(buffer, 1, pointer, file); pointer = 0; return ; }
