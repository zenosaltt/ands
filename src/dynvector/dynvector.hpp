/* Zeno Saletti, 2024
 * 
 * ON AMORTIZED COST
 */

#ifndef DYNVECTOR_H
#define DYNVECTOR_H

#include <iostream>

class Dynvector {

    private:
        const float EXPANSION_F = 2.0;
        const float SHRINKING_F = 0.5;
        const float LOAD_BOUNDARY = 0.25;

        int capacity;
        int items;

        int *A;


        void init(int capacity);
        
        bool full();
        bool empty();

        void copy();
        void expand();
        void shrink();

    public:
        Dynvector();
        Dynvector(int capacity);
        ~Dynvector();

        int space();
        int size();
        void resize();

        void push_back(int item);
        void pop();

        void print(bool verbose);
};

#endif