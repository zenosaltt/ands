#ifndef ARRAY_H
#define ARRAY_H

class array {

    private:
        const int I_CAPACITY = 1;
        const float E_FACTOR = 2.0;
        int capacity;
        int current;
        int *A;

    public:
        array();
        ~array();
        int size();
        void resize();
        void add(int x);
        void remove(int v);
};

#endif