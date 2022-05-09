#include "DSU.h"

#include <string.h>
#include <algorithm>
using namespace std;

DSU::DSU() : p(nullptr), size(0), components(0) {}
DSU::DSU(int n) : p(new int [n]), size(n), components(n) {memset(p, -1, sizeof(int) * n);}
DSU::DSU(const DSU& oth) : p(new int[oth.size]), size(oth.size), components(oth.components) {
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

int DSU::union_size(int n) {return -p[Find(n)];}
bool DSU::same(int l, int r) {return Find(l) == Find(r);}
int DSU::component_count() const {return components;}

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
