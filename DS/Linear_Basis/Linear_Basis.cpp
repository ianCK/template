template <int max_bit> struct Linear_Basis {
	bool have_zero;
	int current_size;
	bitset<max_bit> bs[max_bit];
	// 0 ~ current_size - 1
	
	Linear_Basis() {
		have_zero = false;
		current_size = 0;
	}
	void init() {
		have_zero = false;
		current_size = 0;
	}

	bool zero() const {return have_zero;}
	int size() const {return current_size;}
	long long int order() const {return have_zero ? 1LL << current_size : (1LL << current_size) - 1;}

	bool insert(bitset<max_bit> x) {
		int xpos = -1, xbit = -1;
		for (int i = 0, nbit = 0; i < current_size; i++) {
			while (!x[nbit] && !bs[i][nbit]) nbit++;
			if (x[nbit] && bs[i][nbit]) x ^= bs[i];
			else if (x[nbit]) {
				xpos = i;
				xbit = nbit;
				break;
			}
		}

		if (~xpos) {
			for (int i = xpos; i < current_size; i++) swap(bs[i], x);
			swap(bs[current_size++], x);
		}
		else if (x.any()) {
			swap(bs[xpos = current_size++], x);
			xbit = bs[xpos]._Find_first();
		}

		if (~xpos) {
			for (int i = xpos + 1, nbit = xbit; i < current_size; i++) {
				while (!bs[i][nbit]) nbit++;
				if (bs[xpos][nbit]) bs[xpos] ^= bs[i];
			}
			for (int i = 0; i < xpos; i++) if (bs[i][xbit]) bs[i] ^= bs[xpos];
			return true;
		}
		else if (have_zero) return false;
		else return have_zero = true;
	}

	bool Merge(const Linear_Basis<max_bit> &lbs) {
		bool ans = false;
		int sz = lbs.size();
		for (int i = 0; i < sz; i++) ans |= insert(lbs.bs[i]);
		if (lbs.have_zero && !have_zero) return have_zero = true;
		return ans;
	}

	bool can_produce(bitset<max_bit> x) const {
		for (int i = 0, now = 0; i < max_bit && now < current_size; i++) {
			if (x[i]) {
				if (bs[now][i]) x ^= bs[now++];
				else return false;
			}
			else if (bs[now][i]) now++;
		}
		return x.none();
	}

	bitset<max_bit> Biggest() const {
		bitset<max_bit> ans(0);
		for (int i = 0; i < current_size; i++) ans ^= bs[i];
		return ans;
	}
	bitset<max_bit> Smallest() const {return have_zero ? 0 : bs[current_size - 1];}

	bitset<max_bit> Biggest(bitset<max_bit> x) const {
		for (int i = 0, nbit = 0; i < current_size; i++) {
			while (!bs[i][nbit]) nbit++;
			if (!x[nbit]) x ^= bs[i];
		}
		return x;
	}

	bitset<max_bit> kth_Smallest(long long int k) const {
		if (have_zero) k--;
		bitset<max_bit> ans(0);
		for (int i = 0, j = current_size - 1; i < current_size; i++, j--) if (k & (1LL << j)) ans ^= bs[i];
		return ans;
	}
	bitset<max_bit> kth_Biggest(long long int k) const {return kth_Smallest((1LL << current_size) - k);}

	/*
	 * TODO
	 * bitset<max_bit> kth_Smallest(long long int k, bitset<max_bit> x) const{}
	 * bitset<max_bit> kth_Biggest(long long int k, bitset<max_bit> x) const{}
	 */

	bool operator += (bitset<max_bit> x) {return insert(x);}
	bool operator () (bitset<max_bit> x) const {return can_produce(x);}
	bitset<max_bit> operator [](long long int k) const {return kth_Smallest(k);}

	// debug
	void out() {
		cout << "current_size = " << current_size << endl;
		for (int i = 0; i < current_size; i++) cout << bs[i].to_string() << endl;
		return ;
	}
};
