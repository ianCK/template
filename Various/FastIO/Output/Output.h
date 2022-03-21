#pragma once

template <int bufferSize> class Output {
	public:
		Output();
		Output(FILE*  _file);
		Output(string path);
		~Output();

		template <typename T> void W (const T& n);
		template <typename T> void WP(const T& n);
		template <typename T> void WD(const T& n);
		void WC(char c);
		void WS(const string& s);
		void WSpace();
		void WLine();

	private:

		FILE* file;
		char buffer[bufferSize];
		int pointer;

		void flush();
};

#include "Output.ipp"
