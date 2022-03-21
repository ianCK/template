FastIO::FastIO() : input(stdin), output(stdout) {}
FastIO::FastIO(FILE*  inputFile, FILE*  outputFile) : input(inputFile), output(outputFile) {}
FastIO::FastIO(string inputPath, FILE*  outputFile) : input(inputPath), output(outputFile) {}
FastIO::FastIO(FILE*  inputFile, string outputPath) : input(inputFile), output(outputPath) {}
FastIO::FastIO(string inputPath, string outputPath) : input(inputPath), output(outputPath) {}

// --- Input ---

template <typename T> void FastIO::R (T& n) { return input.R(n); }
template <typename T> void FastIO::RP(T& n) { return input.RP(n); }
template <typename T> void FastIO::RD(T& n) { return input.RD(n); }
void FastIO::RS(string& s) {return input.RS(s); }

template <typename T, typename... Targs> void FastIO::R (T& n, Targs&... Fargs) { return input.R(n, Fargs...); }
template <typename T, typename... Targs> void FastIO::RP(T& n, Targs&... Fargs) { return input.RP(n, Fargs...); }
template <typename T, typename... Targs> void FastIO::RD(T& n, Targs&... Fargs) { return input.RD(n, Fargs...); }
template <typename... Targs> void FastIO::RS(string& s, Targs&... Fargs) { return input.RS(s, Fargs...); }

template <typename... Targs> void FastIO::RL  (int n, Targs*... Fargs) { return input.RL(n, Fargs...); }
template <typename... Targs> void FastIO::RL0 (int n, Targs*... Fargs) { return input.RL0(n, Fargs...); }
template <typename... Targs> void FastIO::RLP (int n, Targs*... Fargs) { return input.RLP(n, Fargs...); }
template <typename... Targs> void FastIO::RLP0(int n, Targs*... Fargs) { return input.RLP0(n, Fargs...); }
template <typename... Targs> void FastIO::RLD (int n, Targs*... Fargs) { return input.RLD(n, Fargs...); }
template <typename... Targs> void FastIO::RLD0(int n, Targs*... Fargs) { return input.RLD0(n, Fargs...); }
template <typename... Targs> void FastIO::RLS (int n, Targs*... Fargs) { return input.RLS(n, Fargs...); }
template <typename... Targs> void FastIO::RLS0(int n, Targs*... Fargs) { return input.RLS0(n, Fargs...); }

// --- Output ---

template <typename T> void FastIO::W (const T& n) { return output.W(n); }
template <typename T> void FastIO::WP(const T& n) { return output.WP(n); }
template <typename T> void FastIO::WD(const T& n) { return output.WD(n); }
void FastIO::WC(char c) { return output.WC(c); }
void FastIO::WS(const string& s) { return output.WS(s); }
void FastIO::WSpace() { return output.WSpace(); }
void FastIO::WLine() { return output.WLine(); }
