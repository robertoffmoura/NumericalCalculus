#include <stdio.h>
#include <math.h>

#define N 100
int dim;

long double a[100][100];
long double x[100];
long double b[100];

float min(float a, float b) {
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

void reduceRows() {
    for (int j=0;j<dim;j++) {
        int maxItemInColumnIndex = max(j);
        if (a[maxItemInColumnIndex][j] == 0) {
            printf("determinant is zero");
            return;
        }
        swapRows(j,maxItemInColumnIndex);
        for (int i=j+1;i<dim;i++) {
            long double aij = a[i][j];
            for (int j2=j;j2<dim;j2++) {
                a[i][j2]-=a[j][j2]*aij/a[j][j];
            }
            b[i]-=b[j]*aij/a[j][j];
        }
    }
}

void getX() {
    long double r;
    for (int i=dim-1;i>-1;i--) {
        r = b[i];
        for (int j=dim-1;j>i;j--) {
            r -= a[i][j]*x[j];
        }
        x[i] = r/a[i][i];
    }
}

void scanMatrixA() {
    for (int i=0;i<dim;i++) {
        for (int j=0;j<dim;j++) {
            scanf("%Lf", &a[i][j]);
        }
    }
}

void scanVectorB() {
    for (int i=0;i<dim;i++) {
        scanf("%Lf", &b[i]);
    }
}

void printMatrixA() {
    for (int i=0;i<dim;i++) {
        for (int j=0;j<dim;j++) {
            printf("%.1Lf ",a[i][j]);
        }
        //printf("    %.1Lf", b[i]);
        printf("\n");
    }
}

void printVector(long double *v) {
    for (int i=0;i<dim;i++) {
        printf("%.1Lf\n", *(v+i));
    }
}

int main() {
    printf("Bem vindo ao programa que resolve sistemas de equações lineares do tipo Ax=b\n");
    printf("digite o número n = dimensão da matriz A\n");
    scanf("%d",&dim);

    printf("agora digite cada entrada da matriz A separada por espaços e separe as linhas pela tecla Enter\n");
    scanMatrixA();

    printf("agora digite as entradas do vetor b separadas por espaço. (Ax = b)\n");
    scanVectorB();

    printf("matriz A:\n");
    printMatrixA();

    printf("vetor b:\n");
    printVector(b);

    reduceRows();
    //printMatrixA();
    getX();

    printf("solução x:\n");
    printVector(x);

    return 0;
}
