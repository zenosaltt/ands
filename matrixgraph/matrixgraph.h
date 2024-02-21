#ifndef MATRIXGRAPH_H
#define MATRIXGRAPH_H

class matrixgraph {

    private:
        int **M;
        int n;

    public:
        matrixgraph(int n);
        ~matrixgraph();

        void addArrow(int a, int b, int w = 1);
        void addEdge(int a, int b, int w = 1);
        int * adjacent(int a);

        void transpose();

        //void print();
        void bfs(int source);
};

#endif