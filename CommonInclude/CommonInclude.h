#pragma once

#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define F first
#define S second
#define MP make_pair
#define MTP make_tuple
#define Debug(...) ;
#define DebugArray(n,x) ;
#define DebugArray0(n,x) ;
#define DebugArrayLn(n,x) ;
#define DebugArray0Ln(n,x) ;
#define NL ;
using ui = unsigned int;
using ll = long long int;
using ull = unsigned long long int;

#ifdef __SIZEOF_INT128__
using lll = __int128;
using ulll = unsigned __int128;
#endif

template <int i> class isZero { public: static constexpr bool value = false; };
template <> class isZero<0> { public: static constexpr bool value = true; };

class falseType { public: static constexpr bool value = false; };
class trueType { public: static constexpr bool value = true; };

template <bool b = false> class boolType : public falseType {};
template <> class boolType<true> : public trueType {};
