#pragma once

class Undoable_DSU {
	private:
		vector<pair<int, int>> opers;
		int *p;
		int size;

	public:
		Undoable_DSU();
		Undoable_DSU(int n);
		Undoable_DSU(const Undoable_DSU& oth);
		~Undoable_DSU();

		void init(int n);
		void clear();

		int Find(int n);

		inline int union_size(int n);
		inline bool same(int l, int r);
		//inline int component_count() const;

		bool Merge(int l, int r);
		
		inline int cur_time() const;
		void Undo_to_time(int t);
};

	
Undoable_DSU::Undoable_DSU() : size(0), p(nullptr) {}
Undoable_DSU::Undoable_DSU(int n) : size(n), p(new int[n]) {memset(p, -1, sizeof(int) * n);}
Undoable_DSU::Undoable_DSU(const Undoable_DSU& oth) : size(oth.size), p(new int[oth.size]) {
	memcpy(p, oth.p, sizeof(int) * size);
}
Undoable_DSU::~Undoable_DSU() {delete [] p;}

void Undoable_DSU::init(int n) {
	opers.clear();
	size = n;
	delete [] p; p = new int[n];
	memset(p, -1, sizeof(int) * n);
	return ;
}

void Undoable_DSU::clear() {
	opers.clear();
	memset(p, -1, sizeof(int) * size);
	return ;
}

int Undoable_DSU::Find(int n) {
	if (p[n] < 0) return n;
	else {
		opers.push_back(make_pair(n, p[n]));
		return p[n] = Find(p[n]);
	}
}

inline int Undoable_DSU::union_size(int n) {return -p[Find(n)];}
inline bool Undoable_DSU::same(int l, int r) {return Find(l) == Find(r);}

bool Undoable_DSU::Merge(int l, int r) {
	l = Find(l), r = Find(r);
	if (l != r) {
		if (p[l] > p[r]) swap(l, r);
		opers.push_back(make_pair(l, p[l]));
		opers.push_back(make_pair(r, p[r]));
		p[l] += p[r];
		p[r] = l;
		return true;
	}
	else return false;
}

inline int Undoable_DSU::cur_time() const {return int(opers.size());}
void Undoable_DSU::Undo_to_time(int t) {
	int _cur_time = cur_time();
	while (_cur_time-- > t) p[opers[_cur_time].F] = opers[_cur_time].S;
	opers.resize(t);
	return ;
}

