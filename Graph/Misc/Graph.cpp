// 0 based
class Graph {
	private:
		vector<vector<int>> _graph;

	public:
		Graph();
		Graph(int n);
		~Graph();

		int size() const;
		void init(int n);

		void clear();
		void AddEdge(int u, int v);
		void AddEdge_B(int u, int v);

		vector<int> & operator [](int n); 
		vector<int> const & operator [](int n) const;
		void out() const;
};

Graph::Graph() {}
Graph::Graph(int n) : _graph(n) {}
Graph::~Graph() {}

int Graph::size() const {return int(_graph.size());}
void Graph::init(int n) {
	clear();
	return _graph.resize(n);
}

void Graph::clear() {return _graph.clear();}

void Graph::AddEdge(int u, int v) {return _graph[u].push_back(v);}
void Graph::AddEdge_B(int u, int v) {return _graph[u].push_back(v), _graph[v].push_back(u);}

vector<int> & Graph::operator [](int n) {return _graph[n];}
vector<int> const & Graph::operator [](int n) const {return _graph[n];}

void Graph::out() const {
	int sz = int(_graph.size());
	printf("Graph :\n");
	for (int i = 0; i < sz; i++) {
		printf("%d :", i);

		bool first = true;
		for (int j : _graph[i]) {
			if (first) first = false;
			else printf(",");
			printf(" %d", j);
		}

		printf("\n");
	}
	printf("------");
	return ;
}
