#ifndef ARRAYGRAPH_H
#define ARRAYGRAPH_H

#include "../array/array.h"

class arraygraph {

    private:
        array * adj;
        int n;
        int m;

    public:
        arraygraph(int n);
        arraygraph(int n, int m);
        ~arraygraph();

        void addArrow(int a, int b);
        void addEdge(int a, int b);
        array * adjacent(int a);
};

#endif