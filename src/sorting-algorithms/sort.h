/*
 * This library contains some
 * popular sorting algorithms,
 * some of which may be less
 * useful than others but
 * nonetheless funny.
 */

#ifndef SORT_H
#define SORT_H

void selectionsort(int A[], int n);
void bubblesort(int A[], int n);
void insertionsort(int A[], int n);
void gnomesort(int A[], int n);
void cocktailsort(int A[], int n);
void oddevensort(int A[], int n);

void combsort(int A[], int n);
void shellsort(int A[], int n);

void quicksort(int A[], int n);
void mergesort(int A[], int n);
void heapsort(int A[], int n);

void bubblesort2(int A[], int n);

void stalinsort(int A[], int n);
void miraclesort(int A[], int n);

#endif