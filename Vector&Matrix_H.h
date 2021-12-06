/* File Matrix.c
Project N2 disperse matrix and disperse vector
(group komp_mat2)
Done by Begisheva Viktoria
Headers for Matrix and Vector structures
*/

#ifndef VECTOR&MATRIX_H_H_INCLUDED
#define VECTOR&MATRIX_H_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

//Structure of vector of floats
typedef struct {
    int n;
    double* vect;
}Vector;

//Vector of plase not zero elements
typedef struct {
    int n;  //number not zero elements
    int* vect;
}Vector_plase;

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

extern Vector input_disperse_vector();

extern Vector vector_from_file(char* filename);

extern Vector disperse_vector_from_file();

extern void vector_to_file(Vector v,char* filename);

//Product Vector and Vector
extern Vector prod_vectors(Vector a,Vector b);

//Add Vectors
extern Vector add_vectors(Vector a,Vector b);

//Product Matrix and Vector
extern Vector prod_matrix_x_vector(Matrix A,Vector B);

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
