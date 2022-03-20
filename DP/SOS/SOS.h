#pragma once

// just a wrapper
template <typename T> class tSOS {
	private:
		virtual void oper(T& lhs, const T& rhs) const = 0;

	public:
		tSOS();

		void solve(int tot, T* arr) const;
		void operator () (int tot, T* arr) const;
};
