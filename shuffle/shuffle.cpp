#include "shuffle.hpp"

#include <random>

static void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

void fisheryates(int A[], int n)
{
    int r;
    srand(time(0x0));

    for (int i = n - 1; i > 0; i--) {
        r = rand() % i;
        swap(A[i], A[r]);
    }
}