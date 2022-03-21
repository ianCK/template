#pragma once

class Output {
	public:
		Output();
		Output(FILE*  _file);
		Output(string path);
		~Output();

		template <typename T> void W (const T& n);
		template <typename T, typename... Targs> void W(const T& n, const Targs&... Fargs);
		template <typename T> void WP(const T& n);
		template <typename T> void WD(const T& n);
		void WC(char c);
		void WS(const string& s);
		void WSpace();
		void WLine();

	private:
		static constexpr int bufferSize = 1 << 16;

		FILE* file;
		char buffer[bufferSize];
		int pointer;

		void flush();
};

#include "Output.ipp"
