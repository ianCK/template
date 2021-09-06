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
		Rng_int(ui seed = 0) : x(ini_x), y(ini_y), z(ini_z), w(ini_w ^ seed) {}
		void set_seed(ui seed) {x = ini_x, y = ini_y, z = ini_z, w = ini_w ^ seed;}
		ui operator () () {return randint();}
		// [1, r]
		ui operator () (ui r) {return randint() % r + 1;}
		// [l, r]
		ui operator () (ui l, ui r) {return l + (randint() % (r - l + 1));}
} rng_int;

// [0, 1]
double rng_double() {return double(rng_int()) * 2.3283064370807974e-10;}
// [0, r]
double rng_double(double r) {return rng_double() * r;}
// [l, r]
double rng_double(double l, double r) {return l + rng_double(r - l);}

inline unsigned int Time_Seed() {return std::chrono::system_clock::now().time_since_epoch().count();}
