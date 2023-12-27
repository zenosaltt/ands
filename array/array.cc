#include "array.h"
#include <iostream>

array::array()
{
    A = new int[I_CAPACITY];
    capacity = I_CAPACITY;
    current = 0;
}

array::~array()
{
    delete [] A;
}

void array::resize()
{
    capacity = current;
    int *buffer = new int[capacity];

    for (int i = 0; i < current; i++) {
        buffer[i] = A[i];
    }

    delete [] A;
    A = buffer;
}

void array::add(int x)
{
    if (current >= capacity) {

        capacity *= E_FACTOR;
        int * buffer = new int[capacity];

        for (int i = 0; i < current; i++) {
            buffer[i] = A[i];
        }

        delete [] A;
        A = buffer;
    }

    A[current] = x;
    current++;
}

int array::size()
{
    return current;
}

void array::remove(int v)
{
    bool found = false;

    for (int i = 0; !found && i < current; i++) {
        if (A[i] == v) {
            found = true;
            A[i] = A[current - 1];
            current--;
        }
    }
}