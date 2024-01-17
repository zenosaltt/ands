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

void insertionsort(int A[], int n)
{
    int tmp, i, j;

    for (i = 1; i < n; i++) {
        tmp = A[i];
        for (j = i; j - 1 >= 0 && A[j - 1] > tmp; j--) {
            A[j] = A[j - 1];
        }
        A[j] = tmp;
    }
}

void bubblesort(int A[], int n)
{
    for (int i = n - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (A[j] > A[j + 1])
                swap(A[j], A[j + 1]);
        }
    }
}

/*
 * The problem with bubble sort is
 * that it is incapable of detecting
 * portions of the array that are
 * already sorted. The following
 * optimization, however, does not
 * decrease the time complexity
 * (yes, bubble sort still sucks)
 */
void bubblesort2(int A[], int n)
{
    bool sorted = false;

    for (int i = n - 1; i > 0 && !sorted; i--) {

        sorted = true;

        for (int j = 0; j < i; j++) {

            if (A[j] > A[j + 1]) {
                swap(A[j], A[j + 1]);
                sorted = false;
            }
        }
    }
}

/*
 * Carrying out a sorting operation
 * with only one 'while' cycle may
 * be regarded as the most remarkable
 * characteristic of this algorithm.
 * Don't be fooled by this, however:
 * you should convince yourself that
 * a time complexity of O(n) will
 * be a dream. According to the
 * authors, this is a common algorighm
 * used by garden gnomes to sort their
 * rows of flower pots
 */
void gnomesort(int A[], int n)
{
    int i = 0;

    while (i < n) {
        if (i == 0 || A[i] >= A[i - 1]) {
            i++;
        } else {
            swap(A[i], A[i - 1]);
            i--;
        }
    }
}