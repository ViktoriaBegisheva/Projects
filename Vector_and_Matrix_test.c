/* File Vector&Matrix_test.c
Project N2 disperse matrix and disperse vector
(group komp_mat2)
Done by Begisheva Viktoria
Test for all function
*/

#include "Matrix_H.h"
#include "Vector_H.h"
#include "Vector.c"
#include "Matrix.c"
#include "Vector_and_Matrix.c"
#include "Vector_and_Matrix_file.c"


int main(){

    printf("Input disperse vector a:\n");//n = 5
    Vector a=input_disperse_vector();
    printf("Inputed vector a:\n");
    print_vector(a);

    Vector b=disperse_vector_from_file("Vector_disp1.txt");
    printf("\n\nDisperse vector b read from file:\n");
    print_vector(b);

    Vector c=prod_vectors(a,b);
    printf("\n\nVector c = a * b :\n");
    print_vector(c);
    vector_to_file(c,"Vector_product.txt");
    printf("\nVector c written to file 'Vector_product.txt'\n");

    Vector d=vector_from_file("Vector1.txt");
    printf("\nVector d read from file:\n");
    print_vector(d);

    Matrix A=matrix_from_file("Matrix1.txt");
    printf("\n\nMatrix A read from file:\n");
    print_matrix(A);
    printf("\nVector f = A * d :\n");
    print_vector(prod_matrix_x_vector(A,d));

    printf("\n\nInput disperse matrix B :\n"); //nxm = 3 3
    Matrix B=input_disperse_matrix();
    printf("\nInputed matrix B:\n");
    print_matrix(B);
/*1 1 5
2 2 5
3 3 8//*/
    Matrix C=prod_matrices(A,B);
    printf("\n\nMatrix C = A * B :\n");
    print_matrix(C);
    matrix_to_file(C,"Matrix_product.txt");
    printf("Matrix C written to file 'Matrix_product.txt'\n");

    Matrix D=disperse_matrix_from_file("Matrix_disp1.txt");
    printf("\nDisperse matrix D read from file:\n");
    print_matrix(D);
    printf("det (D) = %.1lf\n",det_matrix(D));
    printf("Inverse matrix to matrix D :\n");
    print_matrix(inverse_matrix(D));

    printf("\nMatrix M = B + D :\n");
    print_matrix(add_matrices(B,D));

    delete_vector(a);
    delete_vector(b);
    delete_vector(c);
    delete_vector(d);

    delete_matrix(A);
    delete_matrix(B);
    delete_matrix(C);
    delete_matrix(D);
    //*/

}
