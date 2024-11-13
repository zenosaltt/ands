#include "priorityqueue.hpp"
#include <cassert>

#include <iostream>

static int p(int i)
{
    return (i - 1) / 2;
}

static int l(int i)
{
    return 2 * i + 1;
}

static int r(int i)
{
    return 2 * i + 2;
}


static void swap(std::pair<int,int> &a, std::pair<int,int> &b)
{
    std::pair<int,int> tmp = a;
    a = b;
    b = tmp;
}

priorityqueue::priorityqueue(int size)
{
    A = new std::pair<int,int>[size];
    capacity = size;
    current = 0;
}

priorityqueue::~priorityqueue()
{
    delete [] A;
}

static void siftup(std::pair<int,int> * A, int i)
{
    while (i > 0 && A[i].first > A[p(i)].first) {
        swap(A[i], A[p(i)]);
        i = p(i);
    }
}

void priorityqueue::enqueue(int p, int v)
{
    if (current < capacity) {
        A[current] = {p, v};
        siftup(A, current);
        current++;
    }
}

static void siftdown(std::pair<int,int> * A, int n, int i)
{
    int max;
    bool fixed;

    do {
        fixed = true;
        max = i;

        if (r(i) < n && A[r(i)].first > A[max].first)
            max = r(i);
        if (l(i) < n && A[l(i)].first > A[max].first)
            max = l(i);
        
        if (max != i) {
            swap(A[i], A[max]);
            i = max;
            fixed = false;
        }

    } while (!fixed);
}

int priorityqueue::dequeue()
{
    /*
    an interesting scenario should be taken
    into account: assume that the same value
    p is enqueued multiple times.
    The following implementation of dequeue
    is not fair when the operation is carried
    out on elements with the same priority p.

    Suppose 2 is enqueued 3 times. The queue
    is still fair: 2A was inserted first and
    is the first element of the queue.

         2A
        /  \
      2B    2C
    
    2D  2E 2F 2G
    
                   current
    2A | 2B | 2C |    V

    See what happens when 2A is dequeued.

    Siftdown should be reimplemented to
    extend fairness to elements with the
    same priority.
    */

    assert(current > 0);

    swap(A[0], A[current - 1]);
    current--;
    siftdown(A, current, 0);
    
    return A[current].second;
}

int priorityqueue::next()
{
    assert(current > 0);

    return A[0].second;
}

bool priorityqueue::empty()
{
    return current <= 0;
}

void priorityqueue::print()
{
    for (int i = 0; i < current; i++) {
        std::cout << A[i].second << " ";
    }
    std::cout << std::endl;
}