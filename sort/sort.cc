#include "sort.h"
#include "../heap/heap.h"
#include <math.h>

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

/*
 * Interesting generalization of
 * insertion sort
 */
void shellsort(int A[], int n)
{
    int tmp, i, j, gap;

    for (gap = n / 2; gap > 0; gap /= 2) {
        for (i = gap; i < n; i++) {
            tmp = A[i];
            for (j = i; j - gap >= 0 && A[j - gap] > tmp; j -= gap) {
                A[j] = A[j - gap];
            }
            A[j] = tmp;
        }
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

void combsort(int A[], int n)
{
    const float SHRINK_FACTOR = 1.3; //suggested value according to the authors

    for (int gap = n / SHRINK_FACTOR; gap > 0; gap /= SHRINK_FACTOR) {
        for (int i = gap; i < n; i++) {
            if (A[i] < A[i - gap])
                swap(A[i], A[i - gap]);
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

void cocktailsort(int A[], int n)
{
    int lower = 0, upper = n - 1, i;

    while (lower < upper) {

        for (i = lower; i < upper; i++) {
            if (A[i] > A[i + 1])
                swap(A[i], A[i + 1]);
        }

        upper--;

        for (i = upper; i > lower; i--) {
            if (A[i] < A[i - 1])
                swap(A[i], A[i - 1]);
        }

        lower++;
    }
}

static int partition(int A[], int l, int u, bool avoid_worst_cases)
{
    if (avoid_worst_cases) {
        int m = (l + u) / 2;

        if (A[l] > A[u])
            swap(A[l], A[u]);
        if (A[m] > A[u])
            swap(A[m], A[u]);
        if (A[m] > A[l])
            swap(A[m], A[l]);
    }

    int pivot = A[l];
    int j = l;

    for (int i = l + 1; i <= u; i++) {
        if (A[i] < pivot) {
            j++;
            swap(A[i], A[j]);
        }
    }

    A[l] = A[j];
    A[j] = pivot;

    return j;
}

static void quicksort_rec(int A[], int i, int j)
{
    if (i < j) {
        int pivot = partition(A, i, j, false);
        quicksort_rec(A, i, pivot - 1);
        quicksort_rec(A, pivot + 1, j);
    }
}

void quicksort(int A[], int n)
{
    quicksort_rec(A, 0, n - 1);
}

void stalinsort(int A[], int n)
{
    for (int i = 0; i < n - 1; i++) {
        if (A[i + 1] < A[i])
            A[i + 1] = A[i];
    }
}

void oddevensort(int A[], int n)
{
    bool sorted = false;

    while (!sorted) {

        sorted = true;

        for (int i = 1; i < n - 1; i += 2) {
            if (A[i] > A[i + 1]) {
                swap(A[i], A[i + 1]);
                sorted = false;
            }
        }

        for (int i = 0; i < n; i += 2) {
            if (A[i] > A[i + 1]) {
                swap(A[i], A[i + 1]);
                sorted = false;
            }
        }
    }
}

static bool ascendingOrder(int A[], int n)
{
    bool sorted = true;
    int i = 0;

    while (i < n - 1 && sorted) {
        if (A[i] > A[i + 1])
            sorted = false;
        i++;
    }

    return sorted;
}

void miraclesort(int A[], int n)
{
    while (!ascendingOrder(A, n));
    //wait for a miracle
}