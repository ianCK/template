// O(log(n + m + a + b))
// sum_{i = 0..n-1} (ai + b) // m
long long int Floor_Sum(long long int n, long long int m, long long int a, long long int b) {
	long long int ans = 0;
	if (a >= m) {
		ans += (n - 1) * n * (a / m) / 2;
		a %= m;
	}
	if (b >= m) {
		ans += n * (b / m);
		b %= m;
	}
	long long int y_max = (a * n + b) / m, x_max = (y_max * m - b);
	if (y_max == 0) return ans;
	ans += (n - (x_max + a - 1) / a) * y_max;
	ans += Floor_Sum(y_max, a, m, (a - x_max % a) % a);
	return ans;
}

