#include "tmfset.hpp"



TMFSet::TMFSet(int n)
{
    parent = new int[n];
    rank = new int[n];

    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
}


TMFSet::~TMFSet()
{
    delete [] parent;
    delete [] rank;
}


int TMFSet::find(int x)
{
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }

    return parent[x];
}


void TMFSet::merge(int x, int y)
{
    int px = find(x);
    int py = find(y);

    if (px != py) {
        if (rank[px] > rank[py]) {
            parent[py] = px;
        } else if (rank[px] < rank[py]) {
            parent[px] = py;
        } else {
            rank[px]++;
            parent[py] = px;
        }
    }
}