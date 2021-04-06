constexpr uint64_t kMod = (1LL << 61) - 1;

uint64_t Mul(uint64_t a, uint64_t b) {
	__int128 t = __int128(a) * b;
	t = (t >> 61) + (t & kMod);
	t = (t >> 61) + (t & kMod);
	return uint64_t(t);
}

