/* File Vector&Matrix_file.c
Project N2 disperse matrix and disperse vector
(group komp_mat2)
Done by Begisheva Viktoria
Initialize file functions for vector and matrix
*/



Matrix matrix_from_file(char* filename){
    FILE* finp = fopen(filename, "r");
    if (!finp) exit(1);

    Matrix M;
    fscanf(finp,"%d",&M.n);
    fscanf(finp,"%d",&M.m);
    M=initialize_zero_matrix(M.n,M.m);

    for (int i=0;i<M.n;i++){
        for (int j=0;j<M.m;j++){
            fscanf(finp,"%lf",&M.matr[i][j]);
        }
    }
    fclose(finp);
    return M;
}

Vector vector_from_file(char* filename){
    FILE* finp = fopen(filename, "r");
    if (!finp) exit(1);

    Vector v;
    fscanf(finp,"%d",&v.n);
    v=initialize_zero_vector(v.n);

    for (int i=0;i<v.n;i++){
        fscanf(finp,"%lf",&v.vect[i]);
    }
    fclose(finp);
    return v;
}

void matrix_to_file(Matrix M,char* filename){
    FILE* fout = fopen(filename, "w");
    if (!fout) exit(1);

    fprintf(fout,"%d ",M.n);
    fprintf(fout,"%d \n",M.m);

    for (int i=0;i<M.n;i++){
        for (int j=0;j<M.m;j++){
            fprintf(fout,"%.1lf ",M.matr[i][j]);
        }
        fprintf(fout,"\n");
    }
    fclose(fout);
}

void vector_to_file(Vector v,char* filename){
    FILE* fout = fopen(filename, "w");
    if (!fout) exit(1);

    fprintf(fout,"%d\n",v.n);

    for (int i=0;i<v.n;i++){
        fprintf(fout,"%.1lf ",v.vect[i]);
    }
    fclose(fout);
}

Matrix disperse_matrix_from_file(char* filename){
    FILE* finp = fopen(filename, "r");
    if (!finp) exit(1);

    Matrix M;
    fscanf(finp,"%d",&M.n);
    fscanf(finp,"%d",&M.m);
    //M=initialize_zero_matrix(M.n,M.m);

    Matrix_place P;
    fscanf(finp,"%d",&P.n);
    P=initialize_zero_matrix_plase(P.n);
    Vector val=initialize_zero_vector(P.n);

    for (int i=0;i<P.n;i++){
        fscanf(finp,"%d %d %lf",&P.matr[i][0],&P.matr[i][1],&val.vect[i]);
    }
    M=initialize_disperse_matrix(M.n,M.m,P,val);
    fclose(finp);
    return M;
}

Vector disperse_vector_from_file(char* filename){
    FILE* finp = fopen(filename, "r");
    if (!finp) exit(1);

    Vector v;
    fscanf(finp,"%d",&v.n);
    //v=initialize_zero_vector(v.n);
    Vector_plase p;
    fscanf(finp,"%d",&p.n);
    p=initialize_zero_vector_plase(p.n);
    Vector val=initialize_zero_vector(p.n);

    for (int i=0;i<v.n;i++){
        fscanf(finp,"%d %lf",&p.vect[i],&val.vect[i]);
    }
    v=initialize_disperse_vector(v.n,p,val);
    fclose(finp);
    return v;
}
/*
int main(){
    Matrix A=matrix_from_file("Matrix1.txt");
    print_matrix(A);
    Matrix B=disperse_matrix_from_file("Matrix_new.txt");
    print_matrix(B);
}*/
