/* File Vector&Matrix.c
Project N2 disperse matrix and disperse vector
(group komp_mat2)
Done by Begisheva Viktoria
Initialize general functions for vector and matrix
*/


//Add Matrices
Matrix add_matrices(Matrix A,Matrix B){
    if ((A.n!=B.n)||(A.m!=B.m)) exit(1);
    Matrix C=initialize_zero_matrix(A.n,A.m);
    for (int i=0;i<A.n;i++){
        for(int j=0;j<A.m;j++){
            C.matr[i][j]=A.matr[i][j]+B.matr[i][j];
        }
    }
    return C;
}

//Product Matrix and Vector
Vector prod_matrix_x_vector(Matrix A,Vector B){
    if (A.m!=B.n) exit(1);
    Vector C=initialize_zero_vector(A.n);
    for (int i=0;i<A.n;i++){
        for(int j=0;j<B.n;j++){
            C.vect[i]+=A.matr[i][j]*B.vect[j];
        }
    }
    return C;
}

//Product Matrix and Matrix
Matrix prod_matrices(Matrix A,Matrix B){
    if (A.m!=B.n) exit(1);
    Matrix C=initialize_zero_matrix(A.n,B.m);
    for (int i=0;i<A.n;i++){
        for(int j=0;j<B.m;j++){
            for (int k=0;k<B.n;k++)
                C.matr[i][j]+=A.matr[i][k]*B.matr[k][j];
        }
    }
    return C;
}

//Product Vector and Vector
Vector prod_vectors(Vector a,Vector b){
    if (a.n!=b.n) exit(1);
    Vector c=initialize_zero_vector(a.n);
    for (int i=0;i<a.n;i++)
        c.vect[i]=a.vect[i]*b.vect[i];
    return c;
}

//Add Vectors
Vector add_vectors(Vector a,Vector b){
    if (a.n!=b.n) exit(1);
    Vector c=initialize_zero_vector(a.n);
    for (int i=0;i<a.n;i++)
        c.vect[i]=a.vect[i]+b.vect[i];
    return c;
}

//Minor: delete i-th row and j-th columne in Matrix
Matrix minor_matrix(Matrix A,int i,int j){
    if (A.m!=A.n) exit(1);
    int new_size=A.n-1;
    Matrix A_new=initialize_zero_matrix(new_size,new_size);
    for(int k=0;k<new_size;k++){
        for (int l=0;l<new_size;l++){
            if ((k<i)&(l<j))
                A_new.matr[k][l]=A.matr[k][l];
            else if ((k<i)&(l>=j))
                A_new.matr[k][l]=A.matr[k][l+1];
            else if ((k>=i)&(l<j))
                A_new.matr[k][l]=A.matr[k+1][l];
            else if ((k>=i)&(l>=j))
                A_new.matr[k][l]=A.matr[k+1][l+1];
        }
    }
    return A_new;
}

//Determinant Matrix
double det_matrix(Matrix A){
    if (A.m!=A.n) exit(1);
    double det=0;
    if (A.n==2){
        det=A.matr[0][0]*A.matr[1][1]-A.matr[1][0]*A.matr[0][1];
    }
    else{
        for(int i=0;i<A.n;i++){
            Matrix C=minor_matrix(A,0,i);
            det+=pow((-1),(i))*A.matr[0][i]*det_matrix(C);
         }
    }
    return det;
}

//Inverse Matrix to Matrix A
Matrix inverse_matrix(Matrix A){
    if ((A.m!=A.n)||(det_matrix(A)==0)) exit(1);
    Matrix A_invers=initialize_zero_matrix(A.n,A.m);
    for(int i=0;i<A.n;i++){
        for(int j=0;j<A.n;j++){
            Matrix A0=minor_matrix(A,i,j);
            A_invers.matr[j][i]=pow(-1,i+j)*det_matrix(A0)/det_matrix(A);
        }
    }
    //print_matrix(A_invers);
    return A_invers;
}

/*
int main(){
    Matrix M=input_disperse_matrix();
    print_matrix(M);
    Vector a=input_disperse_vector();
    print_vector(a);
    print_vector(prod_matrix_x_vector(M,a));
    //printf("%.1lf",det_matrix(M));
    //print_matrix(inverse_matrix(M));
}//*/
