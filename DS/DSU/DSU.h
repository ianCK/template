#pragma once

#include <CommonInclude/CommonInclude.h>
#include <Various/FastIO/Output/Output.h>

// 0-base
class DSU {
	private:
		int *p;
		int size;
		int components;

	public:
		DSU();
		DSU(int n);
		DSU(const DSU& oth);
		~DSU();

		void Init(int n);
		void Clear();

		int Find(int n);

		int UnionSize(int n);
		bool Same(int l, int r);
		int ComponentCount() const;
        vector<vector<int>> Components();

		bool Merge(int l, int r);


        void out(Output& output) const;
};

#include <DS/DSU/DSU.ipp>
