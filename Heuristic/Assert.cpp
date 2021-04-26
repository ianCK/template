void Assert(const char *c, bool b) {
	if (!b) cerr << c << "\n";
	assert(b);
	return ;
}
void Assert(string s, bool b) {return Assert(s.c_str(), b);}
