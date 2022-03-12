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
