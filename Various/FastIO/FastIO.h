#pragma once

#include "Input/Input.h"
#include "Output/Output.h"

// R -> Read
// D -> digit (no check for neg, only one digit)
// P -> positive (no check for neg)
// S -> string
// L -> loop
// W -> write

class FastIO {
	public:
		FastIO();
		FastIO(FILE*  inputFile, FILE*  outputFile);
		FastIO(string inputPath, FILE*  outputFile);
		FastIO(FILE*  inputFile, string outputPath);
		FastIO(string inputPath, string outputPath);

		// --- Input ---

		template <typename T> void R (T& n);
		template <typename T> void RP(T& n);
		template <typename T> void RD(T& n);
		void RS(string& s);

		template <typename T, typename... Targs> void R (T& n, Targs&... Fargs);
		template <typename T, typename... Targs> void RP(T& n, Targs&... Fargs);
		template <typename T, typename... Targs> void RD(T& n, Targs&... Fargs);
		template <typename... Targs> void RS(string& s, Targs&... Fargs);

		template <typename... Targs> void RL  (int n, Targs*... Fargs);
		template <typename... Targs> void RL0 (int n, Targs*... Fargs);
		template <typename... Targs> void RLP (int n, Targs*... Fargs);
		template <typename... Targs> void RLP0(int n, Targs*... Fargs);
		template <typename... Targs> void RLD (int n, Targs*... Fargs);
		template <typename... Targs> void RLD0(int n, Targs*... Fargs);
		template <typename... Targs> void RLS (int n, Targs*... Fargs);
		template <typename... Targs> void RLS0(int n, Targs*... Fargs);

		// --- Output ---

		template <typename T> void W (const T& n);
		template <typename T, typename... Targs> void W(const T& n, const Targs&... Fargs);
		template <typename T> void WP(const T& n);
		template <typename T> void WD(const T& n);
		void WC(char c);
		void WS(const string& s);
		void WS(const char* s);
		void WSpace();
		void WLine();

	private:
		Input input;
		Output output;
};

#include "FastIO.ipp"
