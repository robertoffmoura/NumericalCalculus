#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int dim;
long double* A;
long double* b;
long double* x;
long double* alpha;

long double* a(int i, int j) {
    return A+i*dim+j;
}

long double min(long double a, long double b) {
    return a < b ? a : b;
}

long double absoluteValue(long double x) {
    return x > 0 ? x : -x;
}

void swapRows(int i1, int i2) {
    if (i1==i2) {
        return;
    }
    long double temp;
    for (int j=i1;j<dim;j++) {
        temp = *a(i1,j);
        *a(i1,j) = *a(i2,j);
        *a(i2,j) = temp;
    }
    temp = b[i1];
    b[i1] = b[i2];
    b[i2] = temp;
    return;
}

void scanMatrixA() {
    for (int i=0;i<dim;i++) {
        for (int j=0;j<dim;j++) {
            scanf("%Lf", a(i,j));
        }
    }
}

void scanVector(long double *v) {
    for (int i=0;i<dim;i++) {
        scanf("%Lf", v+i);
    }
}

void printMatrixA() {
    for (int i=0;i<dim;i++) {
        for (int j=0;j<dim;j++) {
            printf("%10.6Lf ",*a(i,j));
        }
        //printf("    %.1Lf", b[i]);
        printf("\n");
    }
}

void printVector(long double *v) {
    printf("[ ");
    for (int i=0;i<dim;i++) {
        printf("%10.6Lf ", *(v+i));
    }
    printf("]\n");
}

void printSystem() {
    for (int i=0;i<dim;i++) {
        printf("[ ");
        for (int j=0;j<dim;j++) {
            printf("%10.6Lf ",*a(i,j));
        }
        printf("] [ x%-*d ] = [ %10.6Lf ]\n", (int)log10(dim)+1, i+1, b[i]);
    }
}

long double* nextIteraction(long double* x) {
    long double* xf = malloc(sizeof(long double)*dim);
    for (int i=0; i < dim; i++) {
        xf[i] = b[i];
        for (int j=0;j<i;j++) {
            //Gauss-Seidel:
            xf[i]-=*a(i,j)*xf[j];
            //Gauss-Jacobi:
            //xf[i]-=a[i][j]*x[j];
        }
        for (int j=i+1;j<dim;j++) {
            xf[i]-=*a(i,j)*x[j];
        }
        xf[i] /= *a(i,i);
    }
    free(x);
    return xf;
}

int max(long double* v, int length) {
    int maximumIndex = 0;
    for (int i=0;i<length;i++) {
        if (v[i] > v[maximumIndex]) {
            maximumIndex = i;
        }
    }
    return maximumIndex;
}

long double convergenceCriterion() {
    for (int i=0;i<dim;i++) {
        alpha[i] = 0;
        for (int j=0;j<dim;j++) {
            if (i!=j) {
                alpha[i] += absoluteValue(*a(i,j));
            }
        }
        alpha[i] /= absoluteValue(*a(i,i));
    }
    return alpha[max(alpha, dim)];
}

int main() {
    printf("Bem vindo ao programa que resolve sistemas de equações lineares do tipo Ax=b usando o método de Gauss-Seidel\n");
    printf("Digite o número n = dimensão da matriz A\n");
    scanf("%d",&dim);
    A = malloc(sizeof(long double)*dim*dim);
    x = malloc(sizeof(long double)*dim);
    b = malloc(sizeof(long double)*dim);
    alpha = malloc(sizeof(long double)*dim);

    printf("Agora digite cada entrada da matriz A separada por espaços e separe as linhas pela tecla Enter\n");
    scanMatrixA();

    printf("Digite as entradas do vetor b separadas por espaço. (Ax = b)\n");
    scanVector(b);

    printf("Agora digite as entradas do vetor x inicial separadas por espaço\n");
    scanVector(x);

    printf("Digite a quantidade de iterações\n");
    int n;
    scanf("%d",&n);

    //printf("matriz A:\n");
    //printMatrixA();
    //printf("vetor b:\n");
    //printVector(b);
    printSystem();
    printf("\n");

    long double alphaMax = convergenceCriterion();
    printf("Critério das linhas: ");
    if (alphaMax < 1) {
        printf("alpha = %Lf < 1, O método gera uma sequência convergente independentemente do vetor x inicial\n", alphaMax);
    } else {
        printf("alpha = %Lf ≥ 1, o método pode ou não convergir\n", alphaMax);
    }
    printf("\n");

    printf("%*dª iteração: ", (int)log10(n)+1, 0);
    printVector(x);

    for (int i=0;i<n;i++) {
        x = nextIteraction(x);
        printf("%*dª iteração: ", (int)log10(n)+1, i+1);
        printVector(x);
    }

    return 0;
}
