#include <stdio.h>
#include <stdlib.h>
//#include "gaussianElimination.c"

long double* x;
long double* J;
long double* f;
int dim;
int n;

long double df1dx1(long double* x) { return 2*x[0]; }
long double df1dx2(long double* x) { return 2*x[1]; }
long double df2dx1(long double* x) { return 1; }
long double df2dx2(long double* x) { return -1; }

long double f1(long double* x) { return x[0]*x[0]+x[1]*x[1]-1; }
long double f2(long double* x) { return x[0]-x[1]; }

long double* j(i,j) {
    return J+i*dim+j;
}

void getJ(long double* x) {
    *j(0,0) = df1dx1(x);
    *j(0,1) = df1dx2(x);
    *j(1,0) = df2dx1(x);
    *j(1,1) = df2dx2(x);
}

void getF(long double* x) {
    f[0] = f1(x);
    f[1] = f2(x);
}

void printVector(long double *v) {
    printf("[ ");
    for (int i=0;i<dim;i++) {
        printf("%10.6Lf ", *(v+i));
    }
    printf("]\n");
}

void iterate(int n) {
    for (int i=0;i<n;i++) {
        getJ(x);
        getF(x);
        //long double* s = solve(dim,J,f);
        for (int j=0;j<dim;j++) {
            //x[j] -= s[j];
            ;
        }
        printVector(x);
    }
}


int main() {
    //scanf("%d",&dim);
    dim = 2;
    x = malloc(sizeof(long double)*dim);
    J = malloc(sizeof(long double)*dim*dim);
    f = malloc(sizeof(long double)*dim);
    for (int i=0;i<dim;i++) {
        scanf("%Lf",x+i);
    }
    scanf("%d",&n);
    iterate(n);

}
