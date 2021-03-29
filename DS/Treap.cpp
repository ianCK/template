mt19937_64 rng;
template <typename T> struct Treap {
	struct Node {
		Node *l, *r;
		int sz;
		ll wei;
		T val;
		// bool reverse;
		// ll pre_Hs, suf_Hs;

		Node() {}
		Node(T x) {
			l = r = nullptr;
			val = x;
			sz = 1;
			wei = rng();
		}
	};

	inline static int size(Node* s) {return s ? s -> sz : 0;}
	//inline static ll pre(Node* s) {return s ? s -> pre_Hs : 0;}
	//inline static ll suf(Node *s) {return s ? s -> suf_Hs : 0;}
	inline static void pull(Node *s) {
		s -> sz = 1 + size(s -> l) + size(s -> r);
		//s -> pre_Hs = (pre(s -> l) * pw[size(s -> r) + 1] + s -> val * pw[size(s -> r)] + pre(s -> r)) % kMod;
		//s -> suf_Hs = (suf(s -> r) * pw[size(s -> l) + 1] + s -> val * pw[size(s -> l)] + suf(s -> l)) % kMod;
		return ;
	}

	static Node* Merge(Node* a, Node* b) {
		if (!a) return b;
		if (!b) return a;
		if (a -> wei > b -> wei) {
			a -> r = Merge(a -> r, b);
			pull(a);
			return a;
		}
		else {
			b -> l = Merge(a, b -> l);
			pull(b);
			return b;
		}
	}

	static void Split_by_Size(Node *s, int x, Node *&a, Node *&b) { // a get x nodes
		if (!s) a = b = nullptr;
		else if (size(s -> l) + 1 <= x) {
			a = s;
			Split_by_Size(s -> r, x - size(s -> l) - 1, a -> r, b);
			pull(a);
		}
		else {
			b = s;
			Split_by_Size(s -> l, x, a, b -> l);
			pull(b);
		}
		return ;
	}

	static void Split_by_Val(Node *s, T x, Node *&a, Node *&b) { // a get all <= x
		if (!s) a = b = nullptr;
		else if (s -> val <= x) {
			a = s;
			Split_by_Size(s -> r, x, a -> r, b);
			pull(a);
		}
		else {
			b = s;
			Split_by_Size(s -> l, x, a, b -> l);
			pull(b);
		}
		return ;
	}

	static void InOrder(Node* s) {
		if (s -> l) {
			InOrder(s -> l);
			printf(" ");
		}
		printf("%d", s -> val); // %d
		if (s -> r) {
			printf(" ");
			InOrder(s -> r);
		}
		return ;
	}

	Node* rt;
	Treap() {rt = nullptr;}

	void Out() {
		InOrder(rt);
		printf("\n");
		return ;
	}

	void Insert(T x) {
		Node *l, *r;
		Split_by_Val(rt, x, l, r);
		rt = Merge(Merge(l, new Node(x)), r);
		return ;
	}
	void Insert_at_Position(int idx, T x) {
		Node *l, *r;
		Split_by_Size(rt, idx - 1, l, r);
		rt = Merge(Merge(l, new Node(x)), r);
		return ;
	}

	void Erase_Segment(int l, int r) {
		Node *a, *L, *M, *R;
		Split_by_Size(rt, r, a, R);
		Split_by_Size(a, l - 1, L, M);
		rt = Merge(L, R);
		return ;
	}

	void Swap_Segments(int l1, int r1, int l2, int r2) {
		Node *a, *b, *c, *L, *M, *R, *lpart, *rpart;
		Split_by_Size(rt, r2, a, R);
		Split_by_Size(a, l2 - 1, b, rpart);
		Split_by_Size(b, r1, c, M);
		Split_by_Size(c, l1 - 1, L, lpart);
		rt = Merge(Merge(L, rpart), Merge(M, Merge(lpart, R)));
		return ;
	}

	//bool Is_Palindrome(int l, int r) {
	//	Node *a, *L, *M, *R;
	//	Split_by_Size(rt, r, a, R);
	//	Split_by_Size(a, l - 1, L, M);

	//	bool ans = (M -> pre_Hs == M -> suf_Hs);
	//	rt = Merge(L, Merge(M, R));
	//	return ans;
	//}
};
