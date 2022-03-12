// 0-based
// un directional

class Graph {
	private:
		int n, m;
		int *ed, *to;

	public:
		Graph();
		Graph(int _n);
		~Graph();

		void clear();
		void setN(int _n);

		void AddEdge(int u, int v);

		void out() const;
};

Graph::Graph() : n(0), m(0), ed(nullptr), to(nullptr) {}
Graph::Graph(int _n, int _m) : n(_n), m(_m), ed(nullptr), to(nullptr) {}
Graph::~Graph() {
	delete [] ed;
	delete [] to;
}

void Graph::clear() {
	n = 0, m = 0;
	delete [] ed;
	delete [] to;
	return ;
}

void Graph::setN(int _n, int _m) {
	n = _n;
	return ;
}

void AddEdge(int u, int v) {
}
