#pragma once

// R -> Read
// D -> digit (no check for neg, only one digit)
// P -> positive (no check for neg)
// S -> string
// L -> loop
// W -> write

class FastIO {
	private:
		static constexpr int bufferSize = 1 << 16;
		static constexpr int bufferMod = bufferSize - 1; // (use & to mod)

		FILE *input, *output;

		char inputBuffer[bufferSize];
		char outputBuffer[bufferSize];

		int inputPointer;
		int outputPointer;

		char getRawChar() {
			if (inputPointer == bufferSize) {
				fread(inputBuffer, 1, bufferSize, input);
				inputPointer = 0;
			}
			return inputBuffer[inputPointer++];
		}

		static bool isDigit(char c) {return '0' <= c and c <= '9';}

		void outputAll() {
			fwrite(outputBuffer, 1, bufferSize, output);
			return ;
		}
		void outputRemain() {
			fwrite(outputBuffer, 1, outputPointer, output);
			return ;
		}

		template <typename T> void RLi(int i, T *a) {return R(a[i]);}
		template <typename T, typename... Targs> void RLi(int i, T *a, Targs*... Fargs) {R(a[i]); return RLi(i, Fargs...);}

		template <typename T> void RLPi(int i, T *a) {return RP(a[i]);}
		template <typename T, typename... Targs> void RLPi(int i, T *a, Targs*... Fargs) {RP(a[i]); return RLPi(i, Fargs...);}

		template <typename T> void RLDi(int i, T *a) {return RD(a[i]);}
		template <typename T, typename... Targs> void RLDi(int i, T *a, Targs*... Fargs) {RD(a[i]); return RLDi(i, Fargs...);}

		void RLSi(int i, string *a) {return RS(a[i]);}
		template <typename... Targs> void RLSi(int i, string *a, Targs*... Fargs) {RS(a[i]); return RLSi(i, Fargs...);}

		void WC(char c) {
			if (outputPointer == bufferSize) {
				outputAll();
				outputPointer = 0;
			}
			outputBuffer[outputPointer++] = c;
			return ;
		}

	public:
		FastIO() : input(stdin), output(stdout), inputPointer(0), outputPointer(0) {
			fread(inputBuffer, 1, bufferSize, input);
		}
		FastIO(string inputPath, string outputPath) : 
			input(fopen(inputPath.c_str(), "r")), 
			output(fopen(outputPath.c_str(), "w")),
			inputPointer(0),
			outputPointer(0) {
				fread(inputBuffer, 1, bufferSize, input);
			}

		~FastIO() {
			outputRemain();
			fclose(input);
			fclose(output);
		}

		template <typename T> void R (T& n) {
			static_assert(is_integral<T>::value, "R requires an integral type");
			char c;
			bool neg = false;
			while (!isDigit(c = getRawChar())) if (c == '-') neg = true;
			n = int(c - '0');
			while (isDigit(c = getRawChar())) n = n * 10 + int(c - '0');
			if (neg) n = -n;
			return ;
		}
		template <typename T> void RP(T& n) {
			static_assert(is_integral<T>::value, "RP requires an integral type");
			char c;
			while (!isDigit(c = getRawChar()));
			n = int(c - '0');
			while (isDigit(c = getRawChar())) n = n * 10 + int(c - '0');
			return ;
		}
		template <typename T> void RD(T& n) {
			static_assert(is_integral<T>::value, "RD requires an integral type");
			char c;
			while (!isDigit(c = getRawChar())) ;
			n = int(c - '0');
			return ;
		}
		void RS(string& s) {
			// Can optimize?
			s.clear();
			char c = getRawChar();
			while (c == ' ' or c == '\n') c = getRawChar();
			while (c != ' ' and c != '\n') {
				s += c;
				c = getRawChar();
			}
			return ;
		}

		template <typename T, typename... Targs> void R (T &n, Targs&... Fargs) {R (n); return R (Fargs...);}
		template <typename T, typename... Targs> void RD(T &n, Targs&... Fargs) {RD(n); return RD(Fargs...);}
		template <typename T, typename... Targs> void RP(T &n, Targs&... Fargs) {RP(n); return RP(Fargs...);}
		template <typename... Targs> void RS(string &s, Targs&... Fargs) {RS(s); return RS(Fargs...);}

		template <typename... Targs> void RL(int n, Targs*... Fargs) {for (int i = 1; i <= n; i++) RLi(i, Fargs...);}
		template <typename... Targs> void RL0(int n, Targs*... Fargs) {for (int i = 0; i < n; i++) RLi(i, Fargs...);}

		template <typename... Targs> void RLP(int n, Targs*... Fargs) {for (int i = 1; i <= n; i++) RLPi(i, Fargs...);}
		template <typename... Targs> void RLP0(int n, Targs*... Fargs) {for (int i = 0; i < n; i++) RLPi(i, Fargs...);}

		template <typename... Targs> void RLD(int n, Targs*... Fargs) {for (int i = 1; i <= n; i++) RLDi(i, Fargs...);}
		template <typename... Targs> void RLD0(int n, Targs*... Fargs) {for (int i = 0; i < n; i++) RLDi(i, Fargs...);}

		template <typename... Targs> void RLS(int n, Targs*... Fargs) {for (int i = 1; i <= n; i++) RLSi(i, Fargs...);}
		template <typename... Targs> void RLS0(int n, Targs*... Fargs) {for (int i = 0; i < n; i++) RLSi(i, Fargs...);}

		template <typename T> void W(const T& n) {
			static_assert(is_integral<T>::value, "W requires an integral type");
			if (n < 0) WC('-');
			return WP(-n);
		}
		template <typename T> void WP(const T& n) {
			static_assert(is_integral<T>::value, "WP requires an integral type");

			if (n == 0) return WC('0');

			T tmp = n;

			static char buffer[40];

			int pointer = 0;
			while (tmp) {
				buffer[pointer++] = char(tmp % 10 + '0');
				tmp /= 10;
			}

			for (int i = pointer - 1; i >= 0; i--) WC(buffer[i]);

			return ;
		}
		template <typename T> void WD(const T& n) {
			static_assert(is_integral<T>::value, "WD requires an integral type");
			return WC(char(n + '0'));
		}
		void WS(const string& s) {for (char c : s) WC(c); return ;}
		void WSpace() {return WC(' ');}
		void WLine() {return WC('\n');}
};
