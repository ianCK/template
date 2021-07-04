struct Big_Int {
	private:
		static constexpr int kLen = 9;
		static constexpr int kMod = 1'000'000'000;
		bool _positive;
		vector<int> _val;

	public:
		Big_Int () {
			_positive = true;
			_val.push_back(0);
		}
		Big_Int(string s) {
			int diff;
			if (s[0] == '-') {
				_positive = false;
				diff = 1;
			}
			else {
				_positive = true;
				diff = 0;
			}

			int sz = int(s.size());
			int val_sz = (sz - diff + 8) / 9;

			_val.reserve(val_sz);

			int cur_id = sz - 1;

			while (cur_id - kLen + 1 >= diff) {
				cur_id -= kLen;
				_val.push_back(stoi(s.substr(cur_id + 1, kLen)));
			}

			if (cur_id >= diff) _val.push_back(stoi(s.substr(diff, cur_id - diff + 1)));
		}
		Big_Int (const Big_Int &x) {
			_positive = x._positive;
			_val = x._val;
		}
		template <typename T> Big_Int (T x) {
			*this = Big_Int(to_string(x));
		}

		Big_Int operator -() const {
			Big_Int ans(*this);
			ans._positive = !ans._positive;
			return ans;
		}
		Big_Int operator + (const Big_Int &x) const {
			Big_Int ans;
			int lhs_sz = int(_val.size()), rhs_sz = int(x._val.size());
			int lim = max(lhs_sz, rhs_sz) + 1;
			ans._val.resize(lim);

			if (_positive == x._positive) {
				ans._positive = _positive;
				for (int i = 0; i < lhs_sz; i++) ans._val[i] += _val[i];
				for (int i = 0; i < rhs_sz; i++) ans._val[i] += x._val[i];
				for (int i = 0, k = 0; i < lim; i++) {
					ans._val[i] += k;
					if (ans._val[i] >= kMod) {
						ans._val[i] -= kMod;
						k = 1;
					}
					else k = 0;
				}
			}
			else {
				ans._positive = _positive;
				for (int i = 0; i < lhs_sz; i++) ans._val[i] += _val[i];
				for (int i = 0; i < rhs_sz; i++) ans._val[i] -= x._val[i];
				int k = 0;
				for (int i = 0; i < lim; i++) {
					ans._val[i] += k;
					if (ans._val[i] < 0) {
						ans._val[i] += kMod;
						k = -1;
					}
					else if (ans._val[i] >= kMod) {
						ans._val[i] -= kMod;
						k = 1;
					}
					else k = 0;
				}

				// k = 0 or -1 
				if (k < 0) {
					ans._positive = !ans._positive;
					k = 0;
					for (int i = 0; i < lim; i++) {
						ans._val[i] = -ans._val[i] + k;
						if (ans._val[i] < 0) {
							ans._val[i] += kMod;
							k = -1;
						}
						else if (ans._val[i] >= kMod) {
							ans._val[i] -= kMod;
							k = 1;
						}
						else k = 0;
					}
				}
			}

			while (int(ans._val.size()) > 1 && ans._val.back() == 0) ans._val.pop_back();
			if (ans._val.back() == 0) ans._positive = true;
			return ans;
		}
		Big_Int operator - (const Big_Int &x) const {return *this + (-x);}

		Big_Int operator * (const Big_Int &x) const {
			Big_Int ans;
			int lhs_sz = int(_val.size()), rhs_sz = int(x._val.size());

			if (min(lhs_sz, rhs_sz) <= 60) {
				int lim = lhs_sz + rhs_sz + 2;
				ans._val.resize(lim);
				ans._positive = !(_positive ^ x._positive);

				for (int i = 0; i < lhs_sz; i++) for (int j = 0; j < rhs_sz; j++) {
					long long int tmp = 1LL * _val[i] * x._val[j] + ans._val[i + j];
					ans._val[i + j] = tmp % kMod;
					ans._val[i + j + 1] += tmp / kMod;
					if (ans._val[i + j + 1] >= kMod) {
						ans._val[i + j + 1] -= kMod;
						ans._val[i + j + 2]++;
					}
				}

				for (int i = 0, k = 0; i < lim; i++) {
					ans._val[i] += k;
					if (ans._val[i] >= kMod) {
						ans._val[i] -= kMod;
						k = 1;
					}
					else k = 0;
				}
			}
			else {
			}

			while (int(ans._val.size()) > 1 && ans._val.back() == 0) ans._val.pop_back();
			if (ans._val.back() == 0) ans._positive = true;
			return ans;
		}

		// TODO
		Big_Int operator / (const Big_Int &x) const {assert(false); return Big_Int();}
		Big_Int operator % (const Big_Int &x) const {assert(false); return Big_Int();}
		
		Big_Int operator += (const Big_Int &x) {return *this = *this + x;}
		Big_Int operator -= (const Big_Int &x) {return *this = *this - x;}
		Big_Int operator *= (const Big_Int &x) {return *this = *this * x;}
		Big_Int operator /= (const Big_Int &x) {return *this = *this / x;}
		Big_Int operator %= (const Big_Int &x) {return *this = *this % x;}
		Big_Int operator ++(int) {return *this += Big_Int(1);}
		Big_Int operator --(int) {return *this -= Big_Int(1);}

		bool operator < (const Big_Int &x) const {
			if (_positive != x._positive) return x._positive; // equivilant with !_positive
			else {
				int lhs_sz = int(_val.size()), rhs_sz = int(x._val.size());
				if (_positive) {
					if (lhs_sz != rhs_sz) return lhs_sz < rhs_sz;
					for (int i = lhs_sz - 1; i >= 0; i--) if (_val[i] != x._val[i]) return _val[i] < x._val[i];
				}
				else {
					if (lhs_sz != rhs_sz) return lhs_sz > rhs_sz;
					for (int i = lhs_sz - 1; i >= 0; i--) if (_val[i] != x._val[i]) return _val[i] > x._val[i];
				}
				return false;
			}
		}
		bool operator <= (const Big_Int &x) const {
			if (_positive != x._positive) return x._positive; // equivilant with !_positive
			else {
				int lhs_sz = int(_val.size()), rhs_sz = int(x._val.size());
				if (_positive) {
					if (lhs_sz != rhs_sz) return lhs_sz < rhs_sz;
					for (int i = lhs_sz - 1; i >= 0; i--) if (_val[i] != x._val[i]) return _val[i] < x._val[i];
				}
				else {
					if (lhs_sz != rhs_sz) return lhs_sz > rhs_sz;
					for (int i = lhs_sz - 1; i >= 0; i--) if (_val[i] != x._val[i]) return _val[i] > x._val[i];
				}
				return true;
			}
		}
		bool operator > (const Big_Int &x) const {return !(*this <= x);}
		bool operator >= (const Big_Int &x) const {return !(*this < x);}
		bool operator == (const Big_Int &x) const {return _positive == x._positive && _val == x._val;}
		bool operator != (const Big_Int &x) const {return !(*this == x);}

		void in() {
			if (Fast_IO_activated) {
				char c;
				while (!isdigit(c = Get_Raw_Char()) && c != '-') ;
				string s(1, c);
				while (isdigit(c = Get_Raw_Char())) s += c;
				*this = Big_Int(s);
			}
			else {
				string s; cin >> s;
				*this = Big_Int(s);
			}
			return ;
		}
		void out() {
			int sz = int(_val.size());

			if (!_positive) printf("-");
			printf("%s", to_string(_val[sz - 1]).c_str());
			for (int i = sz - 2; i >= 0; i--) {
				string tmp = to_string(_val[i]);
				int tmp_sz = int(tmp.size());
				for (int j = tmp_sz; j < kLen; j++) printf("0");
				printf("%s", tmp.c_str());
			}
			return ;
		}

		string to_str() {
			string ans;
			int sz = int(_val.size());

			if (!_positive) printf("-");
			ans += to_string(_val[sz - 1]);
			for (int i = sz - 2; i >= 0; i--) {
				string tmp = to_string(_val[i]);
				int tmp_sz = int(tmp.size());
				for (int j = tmp_sz; j < kLen; j++) ans += "0"; 
				ans += tmp;
			}
			return ans;
		}
};
