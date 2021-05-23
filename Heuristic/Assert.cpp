void Assert(bool b, const char *c) {
	if (!b) cerr << c << "\n";
	assert(b);
	return ;
}
void Assert(bool b, string s) {return Assert(b, s.c_str());}
