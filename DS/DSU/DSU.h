#pragma once

#include <CommonInclude/CommonInclude.h>

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

		void init(int n);
		void clear();

		int Find(int n);

		int union_size(int n);
		bool same(int l, int r);
		int component_count() const;

		bool Merge(int l, int r);
};

#include <DS/DSU/DSU.ipp>
