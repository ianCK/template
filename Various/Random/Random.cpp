// returns an unsigned int
class Rng_int {
	using ui = unsigned int;
	private:
		static constexpr ui ini_x = 123456789, ini_y = 362436069, ini_z = 521288629, ini_w = 88675123;
		ui x, y, z, w;

		ui randint() {
			ui t = x ^ (x << 11);
			x = y;
			y = z;
			z = w;
			return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
		}

	public:
		Rng_int(ui seed = 0) : x(ini_x), y(ini_y), z(ini_z), w(ini_w ^ (seed * 371928365)) {}
		void set_seed(ui seed) {x = ini_x, y = ini_y, z = ini_z, w = ini_w ^ (seed * 371928365);}
		ui operator () () {return randint();}
		// [0, r - 1]
		ui operator () (ui r) {return randint() % r;}
		// [l, r]
		int operator () (int l, int r) {return l + (randint() % (r - l + 1));}
} rng_int;

pair<int, int> rng_pair(int l, int r) {
	int a = rng_int(l, r), b = rng_int(l, r - 1);
	if (b >= a) return MP(a, b + 1);
	else return MP(a, b);
}

// [0, 1]
double rng_double() {return double(rng_int()) * 2.3283064370807974e-10;}
// [0, r]
double rng_double(double r) {return rng_double() * r;}
// [l, r]
double rng_double(double l, double r) {return l + rng_double(r - l);}

inline unsigned int Time_Seed() {return std::chrono::system_clock::now().time_since_epoch().count();}

double rng_normal() {
	static default_random_engine generator;
	static normal_distribution<double> distribution(0, 1);

	return distribution(generator);
}

class Rng_ll {
	using ull = unsigned long long int;
	private:
		static constexpr ull ini_x = 123456789, ini_y = 362436069, ini_z = 521288629, ini_w = 88675123;
		ull x, y, z, w;

		ull randint() {
			ull t = x ^ (x << 11);
			x = y;
			y = z;
			z = w;
			return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
		}

	public:
		Rng_ll(ull seed = 0) : x(ini_x), y(ini_y), z(ini_z), w(ini_w ^ seed) {}
		void set_seed(ull seed) {x = ini_x, y = ini_y, z = ini_z, w = ini_w ^ seed;}
		ull operator () () {return randint();}
} rng_ll;
