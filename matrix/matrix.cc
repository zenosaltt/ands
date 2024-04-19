#include "matrix.h"
#include <iostream>
//#include <limits.h>

#define INFTY -1

matrix::matrix(int R, int C)
{
    rows = R;
    cols = C;

    M = new int*[R];
    for (int i = 0; i < R; i++) {
        M[i] = new int[C];
        for (int j = 0; j < C; j++) {
            M[i][j] = 0;
        }
    }
}

matrix::~matrix()
{
    for (int i = 0; i < rows; i++) {
        delete [] M[i];
    }

    delete [] M;
}

matrix * prod(matrix &A, matrix &B)
{
    if (A.cols != B.rows) {
        return nullptr;
    }

    int i, j;

    matrix * C = new matrix(A.rows, B.cols);

    for (i = 0; i < C->rows; i++) {
        for (j = 0; j < C->cols; j++) {
            C->M[i][j] = 0;
            for (int k = 0; k < A.cols; k++) {
                C->M[i][j] += A.M[i][k] * B.M[k][j];
            }
        }
    }

    return C;
}

matrix * sum(matrix &A, matrix &B)
{
    if (A.rows != B.rows || A.cols != B.cols) {
        return nullptr;
    }

    int i, j;

    matrix * C = new matrix(A.rows, A.cols);

    for (i = 0; i < C->rows; i++) {
        for (j = 0; j < C->cols; j++) {
            C->M[i][j] = A.M[i][j] + B.M[i][j];
        }
    }

    return C;
}

void matrix::scale(int k)
{
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            M[i][j] *= k;
        }
    }
}


/* PARENTESIZZAZIONE OTTIMA */

void matrix::print()
{
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << M[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int det_rec(int **A, int n)
{
    if (i == j) {
        return A[i][j];
    }

    int sum = 0;

    for (int k = i; k < i; k++) {
        sum += 
    }

    return sum;
}

int det(matrix &A)
{

}