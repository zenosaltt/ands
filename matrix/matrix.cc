#include "matrix.h"
#include <iostream>

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

    matrix * C = new matrix(A.rows, B.cols);

    for (int i = 0; i < C->rows; i++) {
        for (int j = 0; j < C->cols; j++) {
            C->M[i][j] = 0;
            for (int k = 0; k < A.cols; k++) {
                C->M[i][j] += A.M[i][k] * B.M[k][j];
            }
        }
    }

    return C;
}

void matrix::print()
{
    std::cout << std::endl;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << M[i][j] << " ";
        }
        std::cout << std::endl;
    }
}