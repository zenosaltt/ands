#include "sort.h"

static void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

static int minIndex(int A[], int i, int j)
{
    int m = i;
    i++;
    
    while (i <= j) {
        
        if (A[i] < A[m]) {
            m = i;
        }

        i++;
    }

    return m;
}

void selectionsort(int A[], int n)
{
    int m;

    for (int i = 0; i < n - 1; i++) {
        m = minIndex(A, i, n - 1);
        swap(A[i], A[m]);
    }
}