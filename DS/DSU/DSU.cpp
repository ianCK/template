// 0-base
class DSU {
	private:
		int *p;
		int size;
		int components;

	public:
		DSU();
		DSU(int n);
		DSU(const DSU& oth);
		~DSU();

		void init(int n);
		void clear();

		int Find(int n);

		inline int union_size(int n);
		inline bool same(int l, int r);
		inline int component_count() const;

		bool Merge(int l, int r);
};

	
DSU::DSU() : components(0), size(0), p(nullptr) {}
DSU::DSU(int n) : components(n), size(n), p(new int[n]) {memset(p, -1, sizeof(int) * n);}
DSU::DSU(const DSU& oth) : components(oth.components), size(oth.size), p(new int[oth.size]) {
	memcpy(p, oth.p, sizeof(int) * size);
}
DSU::~DSU() {delete [] p;}

void DSU::init(int n) {
	components = size = n;
	delete [] p; p = new int[n];
	memset(p, -1, sizeof(int) * n);
	return ;
}

void DSU::clear() {
	components = size;
	memset(p, -1, sizeof(int) * size);
	return ;
}

int DSU::Find(int n) {return p[n] < 0 ? n : p[n] = Find(p[n]);}

inline int DSU::union_size(int n) {return -p[Find(n)];}
inline bool DSU::same(int l, int r) {return Find(l) == Find(r);}
inline int DSU::component_count() const {return components;}

bool DSU::Merge(int l, int r) {
	l = Find(l), r = Find(r);
	if (l != r) {
		components--;
		if (p[l] > p[r]) swap(l, r);
		p[l] += p[r];
		p[r] = l;
		return true;
	}
	else return false;
}
