template <int kSigma> struct Trie {
	vector<vector<int>> nxt;
	Trie() {nxt = vector<vector<int>>(1, vector<int>(kSigma, 0));}
	void new_node() {
		nxt.push_back(vector<int>(kSigma, 0));
	}
};
