#include "array.h"
#include <cassert>

#define EXPAND 1
#define SHRINK 0

void array::resize(bool expand)
{
    if (expand) {
        capacity *= E_FACTOR;
    } else {
        capacity /= 2;
    }

    int * buffer = new int[capacity];

    for (int i = 0; i < current; i++) {
        buffer[i] = A[i];
    }

    delete [] A;
    A = buffer;
}

//Array constructor
array::array()
{
    A = new int[I_CAPACITY];
    capacity = I_CAPACITY;
    current = 0;
}

//Constructor overload with
//personalized initial capacity
array::array(int c)
{
    A = new int[c];
    capacity = c;
    current = 0;
}

//Array destructor
array::~array()
{
    delete [] A;
}

//Resize the array capacity so that it
//matches the number of elements
//currently stored
void array::resize()
{
    capacity = current;
    int * buffer = new int[capacity];

    for (int i = 0; i < current; i++) {
        buffer[i] = A[i];
    }

    delete [] A;
    A = buffer;
}

//Add a new element with value x
//to the array. Expand the array
//if space is needed (x is appended
//to the back of A)
void array::add(int x)
{
    if (current >= capacity) {
        resize(EXPAND);
    }

    A[current] = x;
    current++;
}

//Return the number of elements
//that are currently stored in
//the array
int array::size()
{
    return current;
}

//Remove the first occurrence of
//the element with value v. Return
//false whenever nothing changes
//(i.e. no element has been removed)
//The array shrinks (capacity is halved)
//when the current amount of elements
//is 1/4 of the capacity
bool array::remove(int v)
{
    bool found = false;

    for (int i = 0; !found && i < current; i++) {
        if (A[i] == v) {
            found = true;
            A[i] = A[current - 1];
            current--;
        }
    }

    if ((float)current / capacity <= L_FACTOR) {
        resize(SHRINK);
    }

    return found;
}

//Return the i-th element
//of the array. WARNING:
//beware of bad reads, i.e.
//the value of 'i' must not
//exceed the current amount
//of elements (don't you wanna
//make your machine explode)
int array::get(int i)
{
    assert(0 <= i && i < current && "Specified index exceeds boundaries.");

    return A[i];
}

//Remove the i-th element
//Return its value
int array::erase(int i)
{
    assert(0 <= i && i < current && "Specified index exceeds boundaries.");

    int tmp = A[i];

    A[i] = A[current - 1];
    current--;

    if ((float)current / capacity <= L_FACTOR) {
        resize(SHRINK);
    }

    return tmp;
}

bool array::empty()
{
    return current == 0;
}