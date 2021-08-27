template <typename T> class Scapegoat_Tree {
	static constexpr double alpha = 0.75; 

	class Node {
		Node *l, *r;
		int size;

		T val;

		Node();
		Node(T x);
		~Node();

		virtual void pull();
	}

	private:
		Node* root;
		bool need_balance(int rt);
		void flatten(int rt);
		void build(int &rt, int l, int r);
		void rebuild(int &rt);
		void insert(int &rt, Node* n);
		void erase(int &rt, Node* n);
		void inorder(int rt);

	public:
		Scapegoat_Tree();
		~Scapegoat_Tree();
		void init();
		void insert(T x);
		void erase(T x);
		int lower_bound(T x) const;
		int upper_bound(T x) const;
		void inorder() const;
};

template <typename T> Scapegoat_Tree();
