void Assert(bool b, string s) {
	if (!b) {
		cerr << s << "\n";
		assert(b);
	}
	return ;
}
