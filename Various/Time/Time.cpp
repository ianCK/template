// rate < 1 -> diff:low->high
// rate = 1 -> straight line
// rate > 1 -> diff:high->low

struct Time_slope {
	static constexpr double kEps = 1E-9;

	double start_time, end_time, rate;
	double start_value, end_value;
	bool one;
	bool rev;

	Time_slope(double s, double e, double r, double sv = 0, double ev = 1) : start_time(s * CLOCKS_PER_SEC), end_time(e * CLOCKS_PER_SEC), rate(r), start_value(sv), end_value(ev) {
		if (fabs(r - 1) < kEps) one = true;
		else one = false;

		if (start_value < end_value) rev = false;
		else rev = true;
	}

	static double current_time() {return clock();}

	double cal01() const {
		return one ? (start_time - current_time()) / (start_time - end_time)
							 : (pow(rate, start_time - current_time()) - 1) / (pow(rate, start_time - end_time) - 1);
	}

	double operator ()() const {
		return rev ? start_value - cal01() * (start_value - end_value)
							 : cal01() * (end_value - start_value) + start_value;
	}
};
