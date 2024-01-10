/*
 * Zeno Saletti
 * 2024/01/08
 * 
 * Title: Variable-size array
 * 
 * Purpose: acquire awareness
 * of how amortized time cost
 * is relevant
 * 
 * Version: 1.0
 *          1.1 shrink()
 */

#ifndef ARRAY_H
#define ARRAY_H

class array {

    private:
        const int I_CAPACITY = 1;
        const float E_FACTOR = 2.0;
        const float L_FACTOR = 0.25;

        int capacity;
        int current;
        int *A;

        void shrink();

    public:
        array();
        array(int c);
        ~array();
        bool empty();
        void add(int x);
        int erase(int i);
        int size();
        void resize();
        bool remove(int v);
        int get(int i);
};

#endif