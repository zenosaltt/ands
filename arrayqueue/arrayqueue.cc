#include "arrayqueue.h"
#include <cassert>

#define SHRINK 0
#define EXPAND 1

void arrayqueue::resize(bool expand)
{
    int * buffer;
    int new_capacity;

    if (expand) {
        new_capacity = capacity * E_FACTOR;
    } else {
        new_capacity = capacity / 2;
    }

    buffer = new int[new_capacity];

    for (int i = exit, j = 0; i != door; i = succ(i), j++) {
        buffer[j] = A[i];
    }

    delete [] A;
    A = buffer;

                              // NEVER CHANGE THIS SEQUENCE
    door = size();            // #1
    exit = 0;                 // #2

    capacity = new_capacity;  // #3
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
}

int arrayqueue::dequeue()
{
    assert(!this->empty() && "The queue is empty");

    int tmp = A[exit];

    exit = succ(exit);

    if ((float)size() / capacity <= L_FACTOR) {
        resize(SHRINK);
    }

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
    /*
    current size may
    be omitted, if
    some additional
    calculation on
    door and exit is
    carried out
    (modular arithmetic
    is involved though :/ )
    */
    
    //return c_size;

    return (door >= exit ? door - exit : door - exit + capacity);
}

/*
void arrayqueue::print()
{
    std::cout << "Testa coda: ";
    for (int i = exit; i != door; i = succ(i)) {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;
}
*/