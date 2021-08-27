// s/e_temp ~= the upperbound of s/e_diff

struct Annealing {

	double start_temperature;
	double end_temperature;

	double start_time;
	double end_time;

	Annealing(double s_temp, double e_temp, double e_time) : 
		start_time(clock()), end_time(e_time), start_temperature(s_temp), end_temperature(e_temp) {}
	~Annealing() {}

	double temperature() const {
		double x = (clock() - start_time) / (end_time - start_time);
		return pow(start_temperature, 1 - x) * pow(end_temperature, x);
	}

	bool operator () (double diff) const {return diff >= 0 or rng_double() < exp(diff / temperature());}
};
