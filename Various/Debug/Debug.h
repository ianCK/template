#pragma once

#include <Various/FastIO/Output/Output.h>

#undef Debug
#undef DebugArray
#undef DebugArray0
#undef DebugArrayLn
#undef DebugArray0Ln
#undef NL

class Debugger {
	public:
		Debugger();
		Debugger(FILE* file);
		Debugger(string path);

		template <typename T> void W (const T& n);
		template <typename T, typename... Targs> void W(const T& n, const Targs&... Fargs);
		template <typename T> void WP(const T& n);
		template <typename T> void WD(const T& n);
		void WC(char c);
		void WS(const string& s);
		void WSpace();
		void WLine();

		void flush();

		template <typename T> void print(const T& n);
		void print(const char* n);
		template <typename T1, typename T2> void print(const pair<T1, T2>& n);
		template <typename... Targs> void print(const tuple<Targs...>& n);
		template <size_t N> void print(const bitset<N>& bs);
		template <typename T> void print(const vector<T>& vec);
		template <typename T> void print(const stack<T>& st);
		template <typename T> void print(const queue<T>& qu);
		template <typename T> void print(const deque<T>& dq);
		template <typename T1, typename T2, typename T3> void print(const priority_queue<T1, T2, T3>& pq);
		template <typename T> void print(const set<T>& se);
		template <typename T1, typename T2> void print(const map<T1, T2>& ma);

		template <typename T, typename... Targs> void print(const T& n, const Targs&... Fargs);
		template <typename T> void printArray(int n, T* x);
		template <typename T> void printArray0(int n, T* x);
		template <typename T> void printArrayLn(int n, T* x);
		template <typename T> void printArray0Ln(int n, T* x);

	private:
		Output output;

		template <typename T> void printp(const T& n, falseType ft);
		template <typename T> void printp(const T& n, trueType tt);
		template <int i, typename... Targs> void printi(const tuple<Targs...>& n); 
		template <int... Is, typename... Targs> void print(const tuple<Targs...>& n, integer_sequence<int, Is...>); // inner

} debug;

#define Debug(...) {debug.WS("("+string(#__VA_ARGS__)+") = ");debug.print(__VA_ARGS__);debug.WLine();debug.flush();}
#define DebugArray(n,x) {debug.WS(#x);debug.WS(" :");debug.printArray(n,x);debug.flush();}
#define DebugArray0(n,x) {debug.WS(#x);debug.WS(" :");debug.printArray0(n,x);debug.flush();}
#define DebugArrayLn(n,x) {debug.WS(#x);debug.WS(" :\n");debug.printArrayLn(n,x);debug.flush();}
#define DebugArray0Ln(n,x) {debug.WS(#x);debug.WS(" :\n");debug.printArray0Ln(n,x);debug.flush();}
#define NL {debug.WLine();debug.flush();}

#include <Various/Debug/Debug.ipp>
