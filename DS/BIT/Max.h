#include "Monoid.h"

template <typename T> class BIT_max : public BITMonoid<T> {
	private:
		T defaultValue() const override;

		void update(T& lhs, const T& rhs) const override {
			chmax(lhs, rhs);
			return ;
		}
};
