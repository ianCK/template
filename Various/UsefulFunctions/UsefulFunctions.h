#pragma once

// template <typename T, typename... Targs> vector<T> make_vector(Targs... targs);

template <typename T> void sort(vector<T> &v);
template <typename T> void sort_r(vector<T> &v);

void sort(string &s);
void sort_r(string &s);

template <typename T> void reverse(vector<T> &v);
void reverse(string &s);

template <typename T> void Merge(const vector<T> &a, const vector<T> &b, vector<T> &c);
template <typename T> void Concatanate(const vector<T> &a, const vector<T> &b, vector<T> &c);
template <typename T> void Append(vector<T> &lhs, const vector<T>& rhs);
template <typename T> void Erase(vector<T> &vec, const T& x);
template <typename T> void Discrete(vector<T> &v);
template <typename T> int Discrete_Id(const vector<T> &v, const T& x);

template <typename T> using PQ = priority_queue<T>;
template <typename T> using PQ_R = priority_queue<T, vector<T>, greater<T>>;

template <typename T> T ABS(T n);
template <typename T> __attribute__((target("bmi"))) T gcd(T a, T b);
template <typename T> T lcm(const T& a, const T& b);
template <typename T, typename... Targs> T gcd(const T& a, T b, T c, Targs... args);
template <typename T, typename... Targs> T lcm(const T& a, T b, T c, Targs... args);

template <typename T> T min( const vector<T>& vec );
template <typename T> T max( const vector<T>& vec );

template <typename T, typename... Targs> T min(const T& a, T b, T c, Targs... args);
template <typename T, typename... Targs> T max(const T& a, T b, T c, Targs... args);
template <typename T, typename... Targs> void chmin(T &a, const T& b, const Targs&... args);
template <typename T, typename... Targs> void chmax(T &a, const T& b, const Targs&... args);
template <typename T> T SQ(T x);

// 2 ~ n
vector<int> Primes(int n);

// O(sq(n))
template <typename T> vector<T> factors(T n);

// O(lg(n))
template <typename T> vector<T> factorize(T n);

// vec must be sorted
template <typename T> vector<pair<T, int>> Compress(vector<T> vec);

int mex(const vector<int>& vec);

template <typename T> vector<int> sortBy(T* v, int l, int r);

#include <Various/UsefulFunctions/UsefulFunctions.ipp>
