/* File Matrix.c
Project N2 disperse matrix and disperse vector
(group komp_mat2)
Done by Begisheva Viktoria
Initialize matrix
Initialize disperse matrix as matrix of plase and vector of value
*/

Matrix_place initialize_zero_matrix_plase(int n){
    Matrix_place M;
    M.n=n;
    int m=2;
    M.matr=(int**)calloc(n,sizeof (*(M.matr)));
    for (int i=0;i<n;i++){
        M.matr[i]=(int*)calloc(m,sizeof (**(M.matr)));
    }
    return M;
}

Matrix initialize_zero_matrix(int n,int m){
    Matrix M;
    M.n=n;
    M.m=m;
    M.matr=(double**)calloc(n,sizeof (*(M.matr)));
    for (int i=0;i<n;i++){
        M.matr[i]=(double*)calloc(m,sizeof (**(M.matr)));
    }
    return M;
}

void print_matrix(Matrix M){
    for (int i=0;i<M.n;i++){
        for(int j=0;j<M.m;j++){
            printf("%.1lf ",M.matr[i][j]);
        }
        printf("\n");
    }
}

Matrix input_matrix(){
    int n,m; printf("nxm: "); scanf("%d %d",&n,&m);
    Matrix M=initialize_zero_matrix(n,m);
    for (int i=0;i<M.n;i++){
        for(int j=0;j<M.m;j++){
            scanf("%lf",&M.matr[i][j]);
        }
    }
    return M;
}

void delete_matrix(Matrix M){
    for (int i=0;i<M.n;i++)
        free(M.matr[i]);
    free(M.matr);
}

Matrix initialize_disperse_matrix(int n,int m,Matrix_place list_place,Vector list_value){
    Matrix M=initialize_zero_matrix(n,m);

    for (int i=0;i<list_place.n;i++){
        M.matr[list_place.matr[i][0]-1][list_place.matr[i][1]-1]=list_value.vect[i];
    }
    return M;
}

Matrix input_disperse_matrix(){

    int n,m; printf("nxm: "); scanf("%d %d",&n,&m);

    int n_not_zero; printf("n_not_zero: "); scanf("%d",&n_not_zero);
    Matrix_place list_place=initialize_zero_matrix_plase(n_not_zero);
    Vector list_value=initialize_zero_vector(n_not_zero);

    printf("Input row, column and value for not zero elements: \n");
    for (int i=0;i<list_place.n;i++){
        scanf("%d %d %lf",&list_place.matr[i][0],&list_place.matr[i][1],&list_value.vect[i]);
    }

    Matrix M=initialize_disperse_matrix(n,m,list_place,list_value);
    return M;
}


/*
int main(){
    //Matrix_place M=initialize_zero_matrix_plase(5);
    Matrix M=initialize_zero_matrix(5,2);
    //Matrix M=input_disperse_matrix();
    //print_matrix(M);
    //printf("%.1lf\n",det_matrix(M));
    //print_matrix(inverse_matrix(M));
}//*/

