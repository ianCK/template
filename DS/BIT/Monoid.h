#pragma once

template <typename T> class BITMonoid {
	private:
		int _size; // n + 1
		T* val;

		virtual T defaultValue() const = 0;
		virtual void update(T& lhs, const T& rhs) const = 0;

	public:
		BITMonoid() : _size(0), val(nullptr) {}
		~BITMonoid() {delete [] val;}

		inline int size() const {return _size;}

		void init(int n) {
			delete [] val; val = new T[_size = n + 1];
			for (int i = 1; i <= n; i++) val[i] = defaultValue();
			return ;
		}

		void init(int n, T *a) {
			delete [] val; val = new T[_size = n + 1];
			memcpy(val + 1, a + 1, sizeof(T) * n);
			for (int i = 1; i <= n; i++) if (i + (i & -i) <= n) update(val[i + (i & -i)], val[i]);
			return ;
		}

		void fix(int pos, T x) {
			for (int i = pos; i < _size; i += i & -i) update(val[i], x);
			return ;
		}

		T ask(int pos) const {
			T ans = defaultValue();
			for (int i = pos; i; i ^= i & -i) update(ans, val[i]);
			return ans;
		}

		void clear() {
			for (int i = 1; i < _size; i++) val[i] = defaultValue();
			return ;
		}
};
