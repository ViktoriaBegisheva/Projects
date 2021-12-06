/* File Vector.c
Project N2 disperse matrix and disperse vector
(group komp_mat2)
Done by Begisheva Viktoria
Initialize vector
Initialize disperse vector as vector of plase and vector of value
*/

Vector_plase initialize_zero_vector_plase(int n){
    Vector_plase v;
    v.n=n;
    v.vect=(int*)calloc(n,sizeof (*(v.vect)));
    return v;
}

Vector initialize_zero_vector(int n){
    Vector v;
    v.n=n;
    v.vect=(double*)calloc(n,sizeof (*(v.vect)));
    return v;
}

Vector initialize_disperse_vector(int n,Vector_plase list_place,Vector list_value){
    Vector v=initialize_zero_vector(n);
    for (int i=0;i<list_place.n;i++){
        v.vect[list_place.vect[i]-1]=list_value.vect[i];
    }
    return v;
}

Vector input_vector(){
    int n; printf("n: "); scanf("%d",&n);
    Vector v=initialize_zero_vector(n);
    for (int i=0;i<v.n;i++){
        scanf("%lf",&v.vect[i]);
    }
    print_vector(v);
    return v;
}

void print_vector(Vector v){
    for (int i=0;i<v.n;i++){
        printf("%.1lf ",v.vect[i]);
    }
}

void delete_vector(Vector v){
    free(v.vect);
}

Vector input_disperse_vector(){

    int n; printf("n_vect: "); scanf("%d",&n);

    int n_not_zero; printf("n_not_zero: "); scanf("%d",&n_not_zero);
    Vector_plase list_place=initialize_zero_vector_plase(n_not_zero);
    Vector list_value=initialize_zero_vector(n_not_zero);

    printf("Input index and value for not zero elements: \n");
    for (int i=0;i<n_not_zero;i++){
        scanf("%d %lf",&list_place.vect[i],&list_value.vect[i]);
    }
    Vector v=initialize_disperse_vector(n,list_place,list_value);
    return v;
}


/*
int main(){
    Vector a=input_disperse_vector();
    print_vector(a);
}//*/
