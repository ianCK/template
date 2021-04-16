struct DCH {
	static constexpr long long int kInf = 0x3f3f3f3f3f3f3f3f;
	struct Line {
		long long int a, b, l;
		Line() {}
		Line(long long int _a, long long int _b, long long int _l = -kInf) : a(_a), b(_b), l(_l) {}
		Line(const Line& rhs) : a(rhs.a), b(rhs.b), l(rhs.l) {}
		long long int operator () (long long int x) const {return a * x + b;}
	};

	static inline long long int intersect(const Line &l, const Line &r) {
		if (l.b < r.b) return -((r.b - l.b - 1) / (r.a - l.a) + 1);
		else return (l.b - r.b) / (r.a - l.a);
	}

	struct Node {
		static mt19937 rng;
		Node *l, *r;
		Line line;
		unsigned long long int wei;
		Node() {}
		Node(const Line& _line) : line(_line) {l = r = nullptr; wei = rng();}
		Node* Find(long long int x) { // find by line.l
			if (x < line.l) return l -> Find(x);
			else if (r && x >= r -> line.l) return r -> Find(x);
			else return this;
		}
		Node* Leftmost() {return l ? l -> Leftmost() : this;}
		Node* Rightmost() {return r ? r -> Rightmost() : this;}
		void clear() {
			if (l) {
				l -> clear();
				delete l;
			}
			if (r) {
				r -> clear();
				delete r;
			}
			return ;
		}
	};

	static Node* Merge(Node *a, Node *b) {
		if (!a) return b;
		if (!b) return a;
		if (a -> wei > b -> wei) {
			a -> r = Merge(a -> r, b);
			return a;
		}
		else {
			b -> l = Merge(a, b -> l);
			return b;
		}
	}
	static void Split_by_a(Node *s, long long int x, Node *&a, Node *&b) {
		if (!s) a = b = nullptr;
		else if (s -> line.a <= x) {
			a = s;
			Split_by_a(s -> r, x, a -> r, b);
		}
		else {
			b = s;
			Split_by_a(s -> l, x, a, b -> l);
		}
		return ;
	}

	Node *root;
	DCH() {root = nullptr;}
	void init() {root = nullptr;}
	void clear() {if (root) {root -> clear(); delete root; root = nullptr;}}

	void insert(Line line) {
		Node *a, *b;
		Split_by_a(root, line.a, a, b);

		while (b) {
			Node *u = b -> Leftmost();

			long long int x = intersect(line, u -> line);
			if (x < u -> line.l) break;
			else {
				Node *lb, *rb;
				Split_by_a(b, u -> line.a, lb, rb);

				if (!rb) {
					lb -> line.l = x + 1;
					b = Merge(lb, rb);
					break;
				}
				else {
					Node *v = rb -> Leftmost();
					if (x + 1 < v -> line.l) {
						lb -> line.l = x + 1;
						b = Merge(lb, rb);
						break;
					}
					else {
						delete lb;
						b = rb;
					}
				}
			}
		}

		while (a) {
			Node *u = a -> Rightmost();
			long long int x = intersect(u -> line, line);

			if (x < u -> line.l) {
				Node *la, *ra;
				Split_by_a(a, u -> line.a - 1, la, ra);
				delete ra;
				a = la;
			}
			else {
				line.l = x + 1;
				break;
			}
		}

		if (!b || line.l < b -> Leftmost() -> line.l) b = Merge(new Node(line), b);
		root = Merge(a, b);
		return ;
	}
	void insert(long long int a, long long int b) {return insert(Line(a, b));}

	long long int operator () (long long int x) {return root -> Find(x) -> line(x);}
};
mt19937 DCH::Node::rng;
