#include "arrayqueue.h"
#include <cassert>
#include <iostream>

void arrayqueue::resize(bool expand)
{
    if (expand) {

        int * buffer = new int[(int)(capacity * E_FACTOR)];

        for (int i = exit, j = 0; i != door; i = succ(i), j++) {
            buffer[j] = A[i];
        }

        delete [] A;
        A = buffer;

        capacity *= E_FACTOR;

        exit = 0;
        door = c_size;

    } else {

        int * buffer = new int[capacity / 2];

        for (int i = exit, j = 0; i != door; i = succ(i), j++) {
            buffer[j] = A[i];
        }

        delete [] A;
        A = buffer;

        capacity /= 2;

        exit = 0;
        door = c_size;
    }
}

int arrayqueue::succ(int i)
{
    return (i + 1) % capacity;
}

bool arrayqueue::full()
{
    return succ(door) == exit;
}

arrayqueue::arrayqueue()
{
    A = new int[I_CAPACITY];
    
    capacity = I_CAPACITY;
    c_size = 0;

    door = 0;
    exit = 0;
}

arrayqueue::~arrayqueue()
{
    delete [] A;
}

void arrayqueue::enqueue(int x)
{
    //assert(!this->full() && "The queue is full");

    if (this->full()) {
        resize(EXPAND);
    }

    A[door] = x;
    door = succ(door);
    c_size++;
}

int arrayqueue::dequeue()
{
    assert(!this->empty() && "The queue is empty");

    int tmp = A[exit];

    exit = succ(exit);
    c_size--;

    //if ((float)c_size / capacity <= L_FACTOR) {
    //    resize(SHRINK);
    //}

    return tmp;
}

//Return value of the next
//element to be dequeued
int arrayqueue::next()
{
    assert(!this->empty() && "The queue is empty");

    return A[exit];
}

bool arrayqueue::empty()
{
    return exit == door;
}

int arrayqueue::size()
{
    //current size may
    //be omitted, if
    //some additional
    //calculation on
    //door and exit is
    //carried out
    //(modular arithmetic
    //is involved though :/ ) 
    return c_size;
}


void arrayqueue::print()
{
    std::cout << "Testa coda: ";
    for (int i = exit; i != door; i = succ(i)) {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;
}
