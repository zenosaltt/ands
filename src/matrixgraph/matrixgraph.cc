#include "matrixgraph.h"
#include "../arrayqueue/arrayqueue.h"


matrixgraph::matrixgraph(int n)
{
    this->n = n;
    M = new int*[n];

    for (int i = 0; i < n; i++)
        M[i] = new int[n];
}

matrixgraph::~matrixgraph()
{
    for (int i = 0; i < n; i++)
        delete [] M[i];
    delete [] M;
}

void matrixgraph::transpose()
{
    for (int i = 0; i < n - 1; i++) {
        for (int j = 1 + i; j < n; j++) {
            int tmp = M[i][j];
            M[i][j] = M[j][i];
            M[j][i] = tmp;
        }
    }
}

void matrixgraph::addArrow(int a, int b, int w)
{
    if (0 <= a && a < n && 0 <= b && b < n) {
        M[a][b] = w;
    }
}

void matrixgraph::addEdge(int a, int b, int w)
{
    if (0 <= a && a < n && 0 <= b && b < n) {
        M[a][b] = w;
        M[b][a] = w;
    }
}

int * matrixgraph::adjacent(int a)
{
    return M[a];
}

void matrixgraph::bfs(int source)
{
    arrayqueue Q;
    bool * visited = new bool[n];

    int tmp;

    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }

    visited[source] = true;
    Q.enqueue(source);

    while (!Q.empty()) {
        tmp = Q.dequeue();

        for (int i = 0; i < n; i++) {
        }
    }
}

/*
void matrixgraph::print()
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << M[i][j] << " ";
        }
        cout << endl;
    }
}
*/