#include "dynvector.hpp"



void Dynvector::init(int capacity)
{
    this->capacity = capacity;
    items = 0;

    A = new int[this->capacity];
}


Dynvector::Dynvector()
{
    init(2);
}


Dynvector::Dynvector(int capacity)
{
    init(capacity);
}


Dynvector::~Dynvector()
{
    delete [] A;
}


int Dynvector::space()
{
    return capacity;
}


int Dynvector::size()
{
    return items;
}


void Dynvector::print(bool verbose)
{
    std::cout << "[";

    //print the content of the internal
    //array except the last item (pretty
    //printing)
    for (int i = 0; i < items - 1; i++) {
        std::cout << A[i] << ", ";
    }

    //print the last item (without comma+space)
    if (items > 0) {
        std::cout << A[items - 1];
    }

    std::cout << "]\n";

    if (verbose) {
        std::cout << "Size: " << items << ", capacity: " << capacity << std::endl;
    }
}


bool Dynvector::full()
{
    return items == capacity;
}


bool Dynvector::empty()
{
    return items == 0;
}


void Dynvector::copy()
{
    int *B = new int[capacity];

    for (int i = 0; i < items; i++) {
        B[i] = A[i];
    }

    delete [] A;
    A = B;
}


void Dynvector::expand()
{
    capacity *= EXPANSION_F;
    copy();
}


void Dynvector::push_back(int item)
{
    if (full()) {
        expand();
    }

    A[items] = item;
    items++;
}


void Dynvector::shrink()
{
    capacity *= SHRINKING_F;
    copy();
}


void Dynvector::pop()
{
    if (!empty()) {

        items--;

        if ((float)items / capacity <= LOAD_BOUNDARY) {
            shrink();
        }
    }
}

/* WARNING
 */
void Dynvector::resize()
{
}