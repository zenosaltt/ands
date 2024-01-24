#include "sort.h"
#include "../heap/heap.h"

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
        for (j = i; j > 0 && A[j - 1] > tmp; j--) {
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

/*
 * Merge sort
 */
static void merge(int A[], int start, int mid, int end)
{
    int size = end - start + 1;
    int * s = new int[size];

    int i = start, j = mid + 1, k = 0;

    while (i <= mid && j <= end) {
        
        if (A[i] < A[j]) {
            s[k] = A[i];
            i++;
        } else {
            s[k] = A[j];
            j++;
        }
        
        k++;
    }

    while (i <= mid) {
        s[k] = A[i];
        i++;
        k++;
    }

    while (j <= end) {
        s[k] = A[j];
        j++;
        k++;
    }

    for (i = start, k = 0; i <= end; i++, k++) {
        A[i] = s[k];
    }

    delete [] s;
}

static void mergesort_rec(int A[], int i, int j)
{
    if (i < j) {
        int m = (i + j) / 2;
        mergesort_rec(A, i, m);
        mergesort_rec(A, m + 1, j);
        merge(A, i, m, j);
    }
}

void mergesort(int A[], int n)
{
    mergesort_rec(A, 0, n - 1);
}

void heapsort(int A[], int n)
{
    heapify(A, n);

    for (int i = n - 1; i > 0; i--) {
        swap(A[0], A[i]);
        siftdown(A, i, 0);
    }
}