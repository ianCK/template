// !!! This is just a draft

class Linear_Basis {
	private:
		vector<int> base;
	public:
		void insert(int v);
};
vector<int> base;
void insert(int v) {
	for (int i : base) {
		v = min(v, v ^ i);
	}
	if (v) base.push_back(v);
}
