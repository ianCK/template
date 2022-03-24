#pragma once

#include "../FastIO/Output/Output.h"

#undef Debug
#undef DebugArray
#undef DebugArray0
#undef DebugArrayLn
#undef DebugArray0Ln
#undef NL

template <int i> class isZero { public: static constexpr bool value = false; };
template <> class isZero<0> { public: static constexpr bool value = true; };

class falseType {};
class trueType {};

template <bool b> class boolType : public falseType {};
template <> class boolType<true> : public trueType {};

class DebugOutput {
	public:
		DebugOutput();
		DebugOutput(FILE* file);
		DebugOutput(string path);

		template <typename T> void W (const T& n);
		template <typename T, typename... Targs> void W(const T& n, const Targs&... Fargs);
		template <typename T> void WP(const T& n);
		template <typename T> void WD(const T& n);
		void WC(char c);
		void WS(const string& s);
		void WSpace();
		void WLine();

		void flush();

		void print(const char* n); // This is an overload
		template <typename T> void print(const T& n);
		template <typename T1, typename T2> void print(const pair<T1, T2>& n); // This is an overload
		template <typename... Targs> void print(const tuple<Targs...>& n); // This is an overload

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

#include "Debug.ipp"
