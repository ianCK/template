#pragma once

template <int N, int M = N> class foo {
};

template <int N> class foo<N, N> {
	public:
		template <int K> foo<N, K> bar(const foo<N, K>& o) const { return foo<N, K>(); } 
};

#include "foo.ipp"
