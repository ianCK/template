#pragma once

class Input {
	public:
		Input();
		Input(FILE*  _file);
		Input(string path);

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

	private:
		static constexpr int bufferSize = 1 << 16;

		FILE* file;
		char buffer[bufferSize];
		int pointer;

		void read();
		char getRawChar();
		static bool isDigit(char c);

		template <typename T> void RLi(int i, T* a);
		template <typename T, typename... Targs> void RLi(int i, T* a, Targs*... Fargs);

		template <typename T> void RLPi(int i, T* a);
		template <typename T, typename... Targs> void RLPi(int i, T* a, Targs*... Fargs);

		template <typename T> void RLDi(int i, T* a);
		template <typename T, typename... Targs> void RLDi(int i, T* a, Targs*... Fargs);

		void RLSi(int i, string* a);
		template <typename... Targs> void RLSi(int i, string* a, Targs*... Fargs);
};

#include <Various/FastIO/Input/Input.ipp> 
