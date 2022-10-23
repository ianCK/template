template <typename T> void sort(vector<T> &v) { return sort(v.begin(), v.end()); }
template <typename T> void sort_r(vector<T> &v) { return sort(v.begin(), v.end(), greater<T>()); }

void sort(string &s) { return sort(s.begin(), s.end()); }
void sort_r(string &s) { return sort(s.begin(), s.end(), greater<char>()); }

template <typename T> void reverse(vector<T> &v) { return reverse(v.begin(), v.end()); }
void reverse(string &s) { return reverse(s.begin(), s.end()); }

template <typename T> void Merge(const vector<T> &a, const vector<T> &b, vector<T> &c) {
    if (c.size() < a.size() + b.size()) c.resize(a.size() + b.size());
    merge(a.begin(), a.end(), b.begin(), b.end(), c.begin());
    return ;
}

template <typename T> void Concatanate(const vector<T> &a, const vector<T> &b, vector<T> &c) {
    int a_size = int(a.size()), b_size = int(b.size());
    c.resize(a_size + b_size);
    for (int i = 0; i < a_size; i++) c[i] = a[i];
    for (int i = 0; i < b_size; i++) c[i + a_size] = b[i];
    return ;
}

template <typename T> void Append(vector<T> &lhs, const vector<T>& rhs) {
    int lsz = int(lhs.size()), rsz = int(rhs.size());
    lhs.reserve(lsz + rsz);
    for (int i = 0; i < rsz; i++) lhs.push_back(rhs[i]);
    return ;
}

template <typename T> void Erase(vector<T> &vec, const T& x) {
    int sz = int(vec.size());
    for (int i = 0; i < sz; i++) if (vec[i] == x) {
        swap(vec[i], vec.back());
        vec.pop_back();
        break;
    }
    return ;
}

template <typename T> void Discrete(vector<T> &v) { sort(v); v.resize(unique(v.begin(), v.end()) - v.begin()); return ; }
template <typename T> int Discrete_Id(const vector<T> &v, const T& x) { return lower_bound(v.begin(), v.end(), x) - v.begin(); }

template <typename T> T ABS(T n) { return n >= 0 ? n : -n; }
template <typename T> __attribute__((target("bmi"))) T gcd(T a, T b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    if (a == 0 || b == 0) return a + b;
    int n = __builtin_ctzll(a);
    int m = __builtin_ctzll(b);
    a >>= n;
    b >>= m;
    while (a != b) {
        int m = __builtin_ctzll(a - b);
        bool f = a > b;
        T c = f ? a : b;
        b = f ? b : a;
        a = (c - b) >> m;
    }
    return a << min(n, m);
}
template <typename T> T lcm(const T& a, const T& b) { return a * (b / gcd(a, b)); }
template <typename T, typename... Targs> T gcd(const T& a, const T& b, const T& c, const Targs&... args) { return gcd(a, gcd(b, c, args...)); }
template <typename T, typename... Targs> T lcm(const T& a, const T& b, const T& c, const Targs&... args) { return lcm(a, lcm(b, c, args...)); }

template <typename T> T min( const vector<T>& vec )
{
    int n = int( vec.size() );
    T ans = vec[0];
    for( int i = 1; i < n; i++ ) chmin( ans, vec[i] );
    return ans;
}

template <typename T> T max( const vector<T>& vec )
{
    int n = int( vec.size() );
    T ans = vec[0];
    for( int i = 1; i < n; i++ ) chmax( ans, vec[i] );
    return ans;
}

template <typename T, typename... Targs> T min(const T& a, const T& b, const T& c, const Targs&... args) { return min(a, min(b, c, args...)); }
template <typename T, typename... Targs> T max(const T& a, const T& b, const T& c, const Targs&... args) { return max(a, max(b, c, args...)); }
template <typename T, typename... Targs> void chmin(T &a, const T& b, const Targs&... args) { a = min(a, b, args...); return ; }
template <typename T, typename... Targs> void chmax(T &a, const T& b, const Targs&... args) { a = max(a, b, args...); return ; }
template <typename T> T SQ(T x) { return x * x; }

vector<int> Primes(int n) {
    if (n <= 1) return {};
    // 2 ~ n
    vector<int> primes;
    vector<bool> isPrime(n + 1, true);

    primes.reserve(n / __lg(n));

    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) primes.push_back(i);
        for (int j : primes) {
            if (i * j > n) break;
            isPrime[i * j] = false;
            if (i % j == 0) break;
        }
    }
    return primes;
}

template <typename T> vector<T> factors(T x) {
    // maybe use factorize would be faster?
    vector<T> ans;
    for (T i = 1; i * i <= x; i++) if (x % i == 0) ans.push_back(i);

    int id = int(ans.size()) - 1;
    if (ans[id] * ans[id] == x) id--;
    for (int i = id; i >= 0; i--) ans.push_back(x / ans[i]);

    return ans;
}

namespace MR32 {
using ull = unsigned long long int;
using uint = unsigned int;
ull PowMod(ull a, ull b, ull kMod) {
    ull ans = 1;
    for (; b; b >>= 1, a = a * a % kMod) if (b & 1) ans = ans * a % kMod;
    return ans;
}

bool IsPrime(uint x) {
    static constexpr bool low[8] = {false, false, true, true, false, true, false, true};
    static constexpr uint as = 3, a[3] = {2, 7, 61};
    if (x < 8) return low[x];

    uint t = x - 1;
    int r = 0;
    while ((t & 1) == 0) {
        t >>= 1;
        r++;
    }
    for (uint i = 0; i < as; i++) if (a[i] <= x - 2) {
        bool ok = false;
        ull tt = PowMod(a[i], t, x);
        if (tt == 1) continue;
        for (int j = 0; j < r; j++, tt = tt * tt % x) if (tt == x - 1) {
            ok = true;
            break;
        }
        if (!ok) return false;
    }
    return true;
}
}

#ifdef __SIZEOF_INT128__
namespace MR64 {
using uint128 = unsigned __int128;
using ull = unsigned long long int;
using uint = unsigned int;
uint128 PowMod(uint128 a, uint128 b, uint128 kMod) {
    uint128 ans = 1;
    for (; b; b >>= 1, a = a * a % kMod) if (b & 1) ans = ans * a % kMod;
    return ans;
}

bool IsPrime(ull x) {
    static constexpr bool low[8] = {false, false, true, true, false, true, false, true};
    static constexpr uint as = 7, a[7] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
    if (x < 8) return low[x];
    ull t = x - 1;
    int r = 0;
    while ((t & 1) == 0) {
        t >>= 1;
        r++;
    }
    for (uint i = 0; i < as; i++) if (a[i] <= x - 2) {
        bool ok = false;
        uint128 tt = PowMod(a[i], t, x);
        if (tt == 1) continue;
        for (int j = 0; j < r; j++, tt = tt * tt % x) if (tt == x - 1) {
            ok = true;
            break;
        }
        if (!ok) return false;
    }
    return true;
}
}
#endif

bool IsPrime(unsigned long long int x) {
#ifdef __SIZEOF_INT128__
    if ((x >> 32) == 0) return MR32::IsPrime(x);
    else return MR64::IsPrime(x);
#endif
    return MR32::IsPrime(x);
}

#ifdef __SIZEOF_INT128__
uint64_t PollardRho(uint64_t x) {
    static mt19937 rng;
    if (!(x & 1)) return 2;
    if (IsPrime(x)) return x;
    int64_t a = rng() % (x - 2) + 2, b = a;
    uint64_t c = rng() % (x - 1) + 1, d = 1;
    while (d == 1) {
        a = (__int128(a) * a + c) % x;
        b = (__int128(b) * b + c) % x;
        b = (__int128(b) * b + c) % x;
        d = gcd(uint64_t(abs(a - b)), x);
        if (d == x) return PollardRho(x);
    }
    return d;
}

template <typename T> vector<T> factorize(T x) {
    if (x <= 1) return vector<T>();
    T p = PollardRho(x);
    if (p == x) return vector<T>(1, x);
    vector<T> ans, lhs = factorize(p), rhs = factorize(x / p);
    Merge(lhs, rhs, ans);
    return ans;
}
#endif

int mex(const vector<int>& vec) {
    int n = int(vec.size());
    vector<bool> have(n, false);
    for (int i : vec) if (0 <= i and i < n) have[i] = true;
    for (int i = 0; i < n; i++) if (!have[i]) return i;
    return n;
}

template <typename T> vector<int> sortBy(T* v, int l, int r) {
    vector<pair<T, int>> vec;
    vec.reserve(r - l + 1);
    for (int i = l; i <= r; i++) vec.emplace_back(v[i], i);

    sort(vec);

    vector<int> ans;
    ans.reserve(r - l + 1);
    for (auto [ignore, idx] : vec) ans.push_back(idx);

    return ans;
}
