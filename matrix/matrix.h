#ifndef MATRIX_H
#define MATRIX_H

class matrix {
    
    public:
        int **M;
        int rows;
        int cols;

        matrix(int R, int C);
        ~matrix();
        void print();
        void scale(int k);
};

matrix * sum(matrix &A, matrix &B);
matrix * prod(matrix &A, matrix &B);
matrix * strassen(matrix &A, matrix &B);
int det(matrix &A);

#endif