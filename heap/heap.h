#ifndef HEAP_H
#define HEAP_H

void heapify(int * A, int n);
void siftdown(int * A, int n, int i);
void siftup(int * A, int i);

void print(int * A, int n);

#endif