#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <utility>

class priorityqueue {

    private:
        std::pair<int,int> *A;
        int capacity;
        int current;
    
    public:
        priorityqueue(int size);
        ~priorityqueue();

        void enqueue(int p, int v);
        int dequeue();
        int next();
        bool empty();

        void print();
};

#endif