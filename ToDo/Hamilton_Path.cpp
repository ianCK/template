// O(n)
// Finds a Hamilton from "from" to "to" in Q_n
// assert(__builtin_parity(from ^ to))
void Hamilton_Path(int from, int to, int mask) {
	if (mask == (mask & -mask)) ans.PB(to);
	else {
		int x = (from ^ to) & (-(from ^ to));
		int c = from ^ ((mask ^ x) & (-(mask ^ x)));
		Hamilton_Path(from, c, mask ^ x);
		ans.PB(c ^ x);
		Hamilton_Path(c ^ x, to, mask ^ x);
	}
	return ;
}
