#include <stdio.h>
#include <math.h>

#define N 100
int dim;

long double a[N][N];
long double x[N];
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

void getUpperTriangularMatrix() {
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
/*
void getLowerTriangularMatrix() {
    for (int j=0;j<dim;j++) {
        int maxItemInColumnIndex = max(j);
        if (a[maxItemInColumnIndex][j] == 0) {
            printf("determinant is zero");
            return;
        }
        swapRows(j,maxItemInColumnIndex);
        for (int i=dim-1-j-1;i>=0;i--) {
            long double aij = a[i][j];
            for (int j2=j;j2<dim;j2++) {
                a[i][j2]-=a[dim-1-j][j2]*aij/a[dim-1-j][j];
            }
            b[i]-=b[dim-i-j]*aij/a[dim-1-j][j];
        }
    }
}
*/

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
        printf("] [ x%d ] = [ %10.6Lf ]\n", i+1, b[i]);
    }
}

int main() {
    printf("Bem vindo ao programa que resolve sistemas de equações lineares do tipo Ax=b\n");
    printf("Digite o número n = dimensão da matriz A\n");
    scanf("%d",&dim);

    printf("Agora digite cada entrada da matriz A separada por espaços e separe as linhas pela tecla Enter\n");
    scanMatrixA();

    printf("Agora digite as entradas do vetor b separadas por espaço. (Ax = b)\n");
    scanVector(b);

    //printf("matriz A:\n");
    //printMatrixA();
    //printf("vetor b:\n");
    //printVector(b);
    printSystem();

    getUpperTriangularMatrix();
    //getLowerTriangularMatrix();
    //printf("Matriz escalonada inferior:\n");
    //printMatrixA();
    getX();

    printf("Solução x: ");
    printVector(x);

    return 0;
}
