#include "arraystack.h"
#include <cassert>

arraystack::arraystack(){}
arraystack::~arraystack(){}

void arraystack::push(int x)
{
    A.add(x);
}

int arraystack::top()
{
    assert(!this->empty());

    return A.get(A.size() - 1);
}

int arraystack::pop()
{
    assert(!this->empty());

    return A.erase(A.size() - 1);
}

bool arraystack::empty()
{
    return A.empty();
}