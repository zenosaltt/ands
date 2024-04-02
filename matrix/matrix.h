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
};

matrix * prod(matrix &A, matrix &B);
matrix * strassen(matrix &A, matrix &B);

#endif