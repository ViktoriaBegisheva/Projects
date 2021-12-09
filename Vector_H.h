/* File Matrix.c
Project N2 disperse matrix and disperse vector
(group komp_mat2)
Done by Begisheva Viktoria
Headers for Vector structures
*/

#ifndef VECTOR_H_H_INCLUDED
#define VECTOR_H_H_INCLUDED

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


#endif // VECTOR_H_H_INCLUDED
