template <typename T> class Scapegoat_Tree {
	private:
		static constexpr double kAlpha = 0.75;

		int root;
		vector<tuple<T, int, int, int>> _val; // (val, l, r, size)
		inline T& node_val(int id) {return get<0>(_val[id]);}
		inline int& node_l(int id) {return get<1>(_val[id]);} 
		inline int& node_r(int id) {return get<2>(_val[id]);}
		inline int& node_size(int id) {return get<3>(_val[id]);}
		inline T node_val_c(int id) const {return get<0>(_val[id]);}
		inline int node_l_c(int id) const {return get<1>(_val[id]);} 
		inline int node_r_c(int id) const {return get<2>(_val[id]);}
		inline int node_size_c(int id) const {return id < 0 ? 0 : get<3>(_val[id]);}
		inline void pull(int id) {node_size(id) = node_size_c(node_l_c(id)) + 1 + node_size_c(node_r_c(id));}
		inline void new_node(T n) {return _val.push_back(make_tuple(n, -1, -1, 1));}
		inline void new_node(T n, int l, int r, int sz) {return _val.push_back(make_tuple(n, l, r, sz));}

		vector<int> _buffer; // id

		void inorder(int rt);
		bool need_balance(int rt) const {return node_size_c(rt) * kAlpha < max(node_size_c(node_l_c(rt)), node_size_c(node_r_c(rt)));}
		void flatten(int rt) {
			if (node_l_c(rt) != -1) flatten(node_l_c(rt));
			_buffer.push_back(rt);
			if (node_r_c(rt) != -1) flatten(node_r_c(rt));
			return ;
		}
		void build(int &rt, int l, int r) {
			if (l > r) {
				rt = -1;
				return ;
			}

			int mid = (l + r) >> 1;
			rt = _buffer[mid];
			build(node_l(rt), l, mid - 1);
			build(node_r(rt), mid + 1, r);
			return pull(rt);
		}
		void rebuild(int &rt) {
			_buffer.clear();
			int buffer_size = node_size_c(rt);
			_buffer.reserve(buffer_size);
			flatten(rt);
			return build(rt, 0, buffer_size - 1);
		}
		void insert(int &rt, T n) {
			if (rt < 0) {
				rt = int(_val.size());
				return new_node(n);
			}

			if (n == node_val_c(rt)) return ;

			if (n < node_val_c(rt)) insert(node_l(rt), n);
			else insert(node_r(rt), n);

			pull(rt);
			if (!need_balance(rt)) rebuild(rt);
			return ;
		}

		void erase(int &rt, int n) {
			if (rt < 0) return ;

			if (n == node_val_c(rt)) {
				if (node_l_c(rt) < 0) rt = node_r_c(rt);
				else if (node_r_c(rt) < 0) rt = node_l_c(rt);
				else {
					int nrt = node_l_c(rt), fa = rt;
					while (node_r_c(nrt) >= 0) {
						fa = nrt;
						node_size(fa)--;
						nrt = node_r_c(nrt);
					}

					if (fa == rt) node_r(nrt) = node_r_c(rt);
					else {
						node_r(fa) = node_l_c(nrt);
						node_l(nrt) = node_l_c(rt);
						node_r(nrt) = node_r_c(rt);
					}

					rt = nrt;
				}
			}
			else if (n < node_val_c(rt)) erase(node_l(rt), n);
			else erase(node_r(rt), n);

			if (rt >= 0) {
				pull(rt);
				if (!need_balance(rt)) rebuild(rt);
			}
			return ;
		}

		T lower_bound(int rt, T x) const {
			if (node_val_c(rt) < x) {
				// to right
				if (node_r_c(rt) == -1) return x - 1;
				else return lower_bound(node_r_c(rt), x);
			}
			else {
				// to left
				if (node_l_c(rt) == -1) return node_val_c(rt);
				else {
					T tmp = lower_bound(node_l_c(rt), x);
					if (tmp < x) return node_val_c(rt);
					else return tmp;
				}
			}
		}
		// count the elements < x
		int lower_bound_rank(int rt, T x) const {
			if (node_val_c(rt) < x) {
				// to right
				if (node_r_c(rt) == -1) return node_size_c(rt);
				else return node_size_c(node_l_c(rt)) + 1 + lower_bound_rank(node_r_c(rt), x);
			}
			else {
				// to left
				if (node_l_c(rt) == -1) return 0;
				else return lower_bound_rank(node_l_c(rt), x);
			}
		}
		T upper_bound(int rt, T x) const {
			if (node_val_c(rt) <= x) {
				// to right
				if (node_r_c(rt) == -1) return x;
				else return upper_bound(node_r_c(rt), x);
			}
			else {
				// to left
				if (node_l_c(rt) == -1) return node_val_c(rt);
				else {
					T tmp = upper_bound(node_l_c(rt), x);
					if (tmp <= x) return node_val_c(rt);
					else return tmp;
				}
			}
		}
		// count the elements <= x
		int upper_bound_rank(int rt, T x) const {
			if (node_val_c(rt) <= x) {
				// to right
				if (node_r_c(rt) == -1) return node_size_c(rt);
				else return node_size_c(node_l_c(rt)) + 1 + upper_bound_rank(node_r_c(rt), x);
			}
			else {
				if (node_l_c(rt) == -1) return 0;
				else return upper_bound_rank(node_l_c(rt), x);
			}
		}

		bool contains(int rt, T x) const {
			if (node_val_c(rt) == x) return true;
			else if (node_val_c(rt) < x) return contains(node_r_c(rt), x);
			else return contains(node_l_c(rt), x);
		}

#if not defined(ONLINE_JUDGE)
		void out(int rt) const {
			if (node_l_c(rt) >= 0) {
				out(node_l_c(rt));
				printf(" ");
			}
			_print(node_val_c(rt));
			if (node_r_c(rt) >= 0) {
				printf(" ");
				out(node_r_c(rt));
			}
			return ;
		}
#endif

	public:
		Scapegoat_Tree() : root(-1) {}
		void init() {
			root = -1;
			return _val.clear();
		}
		void reserve(int n) {return _val.reserve(n);}
		inline int size() const {return node_size_c(root);}
		inline bool empty() const {return root == -1;}
		void insert(T x) {
			// !!!
			if (_val.size() == _val.capacity()) _val.reserve((_val.capacity() << 1) + 10);
			return insert(root, x);
		}
		void erase(T x) {return erase(root, x);}
		T lower_bound(T x) const {
			if (root == -1) return x - 1;
			else return lower_bound(root, x);
		}
		int lower_bound_rank(T x) const {
			if (root == -1) return -1;
			else return lower_bound_rank(root, x) + 1;
		}
		T upper_bound(T x) const {
			if (root == -1) return x - 1;
			else return upper_bound(root, x);
		}
		int upper_bound_rank(T x) const {
			if (root == -1) return -1;
			else return upper_bound_rank(root, x) + 1;
		}
		bool contains(T x) const {
			if (root == -1) return false;
			else return contains(root, x);
		}
		void inorder() const;
#if not defined(ONLINE_JUDGE)
		void out() const {
			printf(" scapegoat tree\n");
			if (root == -1) printf("empty");
			else out(root);
			return ;
		}
#endif
};
