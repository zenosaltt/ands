#include "heap.h"
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

static void swap(int &i, int &j)
{
    int tmp = i;
    i = j;
    j = tmp;
}

/* RECURSIVE
void siftdown(int A[], int n, int i)
{
    int min = i;

    if (l(i) < n && A[l(i)] < A[min])
        min = l(i);

    if (r(i) < n && A[r(i)] < A[min])
        min = r(i);

    if (min != i) {
        swap(A, i, min);
        siftdown(A, n, min);
    }
}
*/

void siftdown(int * A, int n, int i)
{
    int max;
    bool fixed;

    do {

        fixed = true;
        max = i;

        if (l(i) < n && A[l(i)] > A[max])
            max = l(i);
        if (r(i) < n && A[r(i)] > A[max])
            max = r(i);

        if (max != i) {
            swap(A[i], A[max]);
            i = max;
            fixed = false;
        }

    } while (!fixed);
}

void siftup(int * A, int i)
{
    while (i > 0 && A[i] > A[p(i)]) {
        swap(A[i], A[p(i)]);
        i = p(i);
    }
}

void heapify(int * A, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        siftdown(A, n, i);
}


static void prnt(int * A, int n, int space, int i)
{
    if (i < n) {
        space += 5;
        prnt(A, n, space, r(i));
        std::cout << std::endl;
        for (int j = 5; j < space; j++)
            std::cout << " ";
        std::cout << A[i] << std::endl;
        prnt(A, n, space, l(i));
    }
}

void print(int * A, int n)
{
    prnt(A, n, 0, 0);
}
