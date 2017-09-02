#include <stdio.h>
#include <math.h>

#define N 100
int dim;

long double a[N][N];
long double x[N];
long double xf[N];
long double b[N];

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
        temp = a[i1][j];
        a[i1][j] = a[i2][j];
        a[i2][j] = temp;
    }
    temp = b[i1];
    b[i1] = b[i2];
    b[i2] = temp;
    return;
}

int max(int column) {
    int maxIndex = column;
    int max=a[column][column];
    for (int i=column;i<dim;i++) {
        if (absoluteValue(a[i][column]) > absoluteValue(max)) {
            max = a[i][column];
            maxIndex = i;
        }
    }
    return maxIndex;
}

void scanMatrixA() {
    for (int i=0;i<dim;i++) {
        for (int j=0;j<dim;j++) {
            scanf("%Lf", &a[i][j]);
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
            printf("%10.6Lf ",a[i][j]);
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
            printf("%10.6Lf ",a[i][j]);
        }
        printf("] [ x%-*d ] = [ %10.6Lf ]\n", (int)log10(dim)+1, i+1, b[i]);
    }
}

void nextIteraction() {
    for (int i=0; i < dim; i++) {
        xf[i] = b[i];
        for (int j=0;j<i;j++) {
            //Gauss-Seidel:
            xf[i]-=a[i][j]*xf[j];
            //Gauss-Jacobi:
            //xf[i]-=a[i][j]*x[j];
        }
        for (int j=i+1;j<dim;j++) {
            xf[i]-=a[i][j]*x[j];
        }
        xf[i] /= a[i][i];
    }
    for (int i = 0;i<dim;i++) {
        x[i] = xf[i];
    }
}

int main() {
    int n;
    printf("Bem vindo ao programa que resolve sistemas de equações lineares do tipo Ax=b usando o método de Gauss-Seidel\n");
    printf("Digite o número n = dimensão da matriz A\n");
    scanf("%d",&dim);

    printf("Agora digite cada entrada da matriz A separada por espaços e separe as linhas pela tecla Enter\n");
    scanMatrixA();

    printf("Digite as entradas do vetor b separadas por espaço. (Ax = b)\n");
    scanVector(b);

    printf("Agora digite as entradas do vetor x inicial separadas por espaço\n");
    scanVector(x);

    printf("Digite a quantidade de iterações\n");
    scanf("%d",&n);

    //printf("matriz A:\n");
    //printMatrixA();
    //printf("vetor b:\n");
    //printVector(b);
    printSystem();
    printf("\n");

    printf("%*dª iteração: ", (int)log10(n)+1, 0);
    printVector(x);

    for (int i=0;i<n;i++) {
        nextIteraction();
        printf("%*dª iteração: ", (int)log10(n)+1, i+1);
        printVector(x);
    }

    return 0;
}
