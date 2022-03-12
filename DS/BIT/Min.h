#include "Monoid.h"

template <typename T> class BIT_min : public BITMonoid<T> {
	private:
		T defaultValue() const override;

		void update(T& lhs, const T& rhs) const override {
			chmin(lhs, rhs);
			return ;
		}
};

