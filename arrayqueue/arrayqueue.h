/*
 * Zeno Saletti
 * 
 * Array-based, cyclic buffer queue.
 * It expands (and shrinks) when needed.
 * 
 * Version: 1.0
 */

#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H

#define SHRINK 0
#define EXPAND 1

class arrayqueue {

    private:
        const int I_CAPACITY = 10;
        const float E_FACTOR = 2.0;
        const float L_FACTOR = 0.25;

        int * A;
        
        int c_size;
        int door; //A[door]: next slot to be overwritten
        int exit; //A[exit]: head of the queue

        int succ(int i);
        bool full();
        void resize(bool expand);

    public:
        int capacity;
        arrayqueue();
        ~arrayqueue();

        void enqueue(int x);
        int dequeue();
        int next();
        bool empty();
        int size();

        void print();
};

#endif