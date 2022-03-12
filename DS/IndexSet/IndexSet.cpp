// Source: https://topcoder-tomerun.hatenablog.jp/entry/2021/06/12/134643
// Used in HTTF 2019 final
// val -> the indexset
// pos -> -1 : doesn't exist / val[pos[i]] = i
class IndexSet {
	private:
		vector<int> _val, _pos;

	public:
		IndexSet();
		IndexSet(int n);
		~IndexSet();

		void init(int n);
		void resize(int n);
		void clear();
		bool contains(int n) const;
		int size() const;
		bool empty() const;
		int any() const;

		void insert(int v);
		void erase(int v);

		int operator [](int x) const;
		const vector<int>& operator ()() const&;

		void out() const;
};

IndexSet::IndexSet() {}
IndexSet::IndexSet(int n) : _pos(n, -1) {_val.reserve(n);}
IndexSet::~IndexSet() {}

void IndexSet::init(int n) {
	_pos.clear(); _pos.resize(n, -1);
	_val.clear(); _val.reserve(n);
	return ;
}

void IndexSet::resize(int n) {
	_pos.resize(n, -1);
	_val.reserve(n);
	return ;
}

void IndexSet::clear() {
	fill(_pos.begin(), _pos.end(), -1);
	_val.clear();
	return ;
}

bool IndexSet::contains(int v) const {return _pos[v] != -1;}
int IndexSet::size() const {return int(_val.size());}
bool IndexSet::empty() const {return _val.empty();}
int IndexSet::any() const {return _val.back();}

void IndexSet::insert(int v) {
	if (!this -> contains(v)) {
		_pos[v] = int(_val.size());
		_val.push_back(v);
	}
	return ;
}

void IndexSet::erase(int v) {
	if (this -> contains(v)) {
		_val[_pos[v]] = _val.back();
		_pos[_val.back()] = _pos[v];

		_val.pop_back();
		_pos[v] = -1;
	}
	return ;
}

int IndexSet::operator [](int x) const {return _val[x];}
const vector<int>& IndexSet::operator ()() const& {return _val;}

void IndexSet::out() const {
	if (this -> empty()) printf("empty");
	else {
		int sz = this -> size();
		printf("(%d", _val[0]);
		for (int i = 1; i < sz; i++) printf(", %d", _val[i]);
		printf(")");
	}
	return ;
}
