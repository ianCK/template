string my_to_string(int len, int val) {
	string s = to_string(val);
	string t;
	
	int tlen = len - int(s.size());
	Assert((to_string(val) + " has length longer than " + to_string(len)), tlen >= 0);

	for (int i = 1; i <= tlen; i++) t += "0";
	
	return t + s;
}
