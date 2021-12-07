/* File Matrix.c
Project N2 disperse matrix and disperse vector
(group komp_mat2)
Done by Begisheva Viktoria
Headers for Matrix structures
*/

#ifndef VECTOR&MATRIX_H_H_INCLUDED
#define VECTOR&MATRIX_H_H_INCLUDED

//Structure of matrix of floats
typedef struct {
    int n; //row
    int m; //column
    double** matr;
}Matrix;

//Matrix of plase not zero elements
typedef struct {
    int n; //number not zero elements
    int** matr; //matrix nx2: n[0]-row, n[1]-column
}Matrix_place;

extern Matrix input_disperse_matrix();

extern Matrix matrix_from_file(char* filename);

extern void matrix_to_file(Matrix M,char* filename);

extern Matrix disperse_matrix_from_file(char* filename);

//Add Matrices
extern Matrix add_matrices(Matrix A,Matrix B);

//Product Matrix and Matrix
extern Matrix prod_matrices(Matrix A,Matrix B);

//Determinant Matrix
extern double det_matrix(Matrix A);

//Inverse Matrix to Matrix A
extern Matrix inverse_matrix(Matrix A);

extern void delete_matrix(Matrix M);

#endif // VECTOR&MATRIX_H_H_INCLUDED
