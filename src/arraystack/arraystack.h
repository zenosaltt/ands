/*
 * Zeno Saletti
 * 2024/01/09 (ASD exam day, let's gooo :D)
 *
 *
 * Version: 1.0
 */

#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

#include "../array/array.h"

class arraystack {

    private:
        array A;
    
    public:
        arraystack();
        ~arraystack();

        void push(int x);
        int top();
        int pop();
        bool empty();
};

#endif