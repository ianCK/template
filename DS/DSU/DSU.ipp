DSU::DSU() : p(nullptr), size(0), components(0) {}
DSU::DSU(int n) : p(new int [n]), size(n), components(n) { memset(p, -1, sizeof(int) * n); }
DSU::DSU(const DSU& oth) : p(new int[oth.size]), size(oth.size), components(oth.components) {
    memcpy(p, oth.p, sizeof(int) * size);
}
DSU::~DSU() { delete [] p; }

void DSU::Init(int n) {
    components = size = n;
    delete [] p; p = new int[n];
    memset(p, -1, sizeof(int) * n);
    return ;
}

void DSU::Clear() {
    components = size;
    memset(p, -1, sizeof(int) * size);
    return ;
}

int DSU::Find(int n) { return p[n] < 0 ? n : p[n] = Find(p[n]); }

int DSU::UnionSize(int n) { return -p[Find(n)]; }
bool DSU::Same(int l, int r) { return Find(l) == Find(r); }
int DSU::ComponentCount() const { return components; }
vector<vector<int>> DSU::Components() {
    vector<int> pos(size);
    int curId = 0;
    for (int i = 0; i < size; i++) if (i == Find(i)) pos[i] = curId++;

    vector<vector<int>> ans(curId);
    for (int i = 0; i < size; i++) ans[pos[Find(i)]].push_back(i);

    return ans;
}

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

void DSU::out(Output& output) const {
	output.WS("DSU\n");
    output.WS("size = "); output.WP(size); output.WS(", components = "); output.WP(components); output.WLine();

    int curId = 0;
    for (const vector<int>& vec : DSU(*this).Components()) {
        output.WP(curId++);
        output.WS(" : [");

        bool first = true;
        for (int i : vec) {
            if (first) first = false;
            else output.WS(", ");
            output.WP(i);
        }

        output.WS("]\n");
    }

    return ;
}
