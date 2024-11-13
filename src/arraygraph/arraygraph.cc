#include "arraygraph.h"
#include <cassert>

arraygraph::arraygraph(int n)
{
    this->n = n;
    adj = new array[n];
}

arraygraph::arraygraph(int n, int m)
{
    this->n = n;
    this->m = m;
    adj = new array[n];
}

arraygraph::~arraygraph()
{
    delete [] adj;
}

void arraygraph::addArrow(int a, int b)
{
    assert(0 <= a && a < n && 0 <= b && b < n && "Unknown node identifiers for this graph");

    adj[a].add(b);
}

void arraygraph::addEdge(int a, int b)
{
    assert(0 <= a && a < n && 0 <= b && b < n && "Unknown node identifiers for this graph");

    adj[a].add(b);
    adj[b].add(a);
}

array * arraygraph::adjacent(int a)
{
    assert(0 <= a && a < n && "Unknown node identifier for this graph");

    return &adj[a];
}