#include <stdio.h>
#include <math.h>

#define N 100
int dim;

long double a[N][N];
long double x[N];
long double b[N];

long double absoluteValue(long double x) { return x > 0 ? x : -x; }

void swapRows(int i1, int i2) {
    if (i1==i2) return;
    long double temp;
    for (int j=i1; j<dim; j++) {
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
    for (int i=column; i<dim; i++) {
        if (absoluteValue(a[i][column]) > absoluteValue(max)) {
            max = a[i][column];
            maxIndex = i;
        }
    }
    return maxIndex;
}

void getUpperTriangularMatrix() {
    for (int j=0; j<dim; j++) {
        int maxItemInColumnIndex = max(j);
        if (a[maxItemInColumnIndex][j] == 0) {
            printf("determinant is zero");
            return;
        }
        swapRows(j,maxItemInColumnIndex);
        for (int i=j+1; i<dim; i++) {
            long double aij = a[i][j];
            for (int j2=j; j2<dim; j2++) {
                a[i][j2] -= a[j][j2]*aij/a[j][j];
            }
            b[i] -= b[j]*aij/a[j][j];
        }
    }
}

void getX() {
    long double r;
    for (int i=dim-1; i>-1; i--) {
        r = b[i];
        for (int j=dim-1; j>i; j--) {
            r -= a[i][j]*x[j];
        }
        x[i] = r/a[i][i];
    }
}

void scanMatrixA() {
    for (int i=0; i<dim; i++) {
        for (int j=0; j<dim; j++) {
            scanf("%Lf", &a[i][j]);
        }
    }
}

void scanVector(long double *v) {
    for (int i=0; i<dim; i++) {
        scanf("%Lf", v+i);
    }
}

void printMatrixA() {
    for (int i=0; i<dim; i++) {
        for (int j=0; j<dim; j++) {
            printf("%10.6Lf ", a[i][j]);
        }
        //printf("    %.1Lf", b[i]);
        printf("\n");
    }
}

void printVector(long double *v) {
    printf("[ ");
    for (int i=0; i<dim; i++) {
        printf("%10.6Lf ", *(v+i));
    }
    printf("]\n");
}

void printSystem() {
    for (int i=0; i<dim; i++) {
        printf("[ ");
        for (int j=0; j<dim; j++) {
            printf("%10.6Lf ", a[i][j]);
        }
        printf("] [ a%d ] = [ %10.6Lf ]\n", i+1, b[i]);
    }
}

long double getF(long double x0) {
    long double r = 0;
    for (int i=0; i<dim; i++) {
        r += x[i]*pow(x0,i);
    }
    return r;
}

int main() {
    printf("Bem vindo ao programa que encontra um polinômio interpolador usando eliminção de Gauss\n");
    printf("Digite o número n = ordem do polinômio\n");
    scanf("%d", &dim);
    dim++;
    printf("Digite os n+1 valores de x dos pontos a serem interpolados, separados por espaço\n");
    scanVector(x);
    for (int i=0; i<dim; i++) {
        for (int j=0; j<dim; j++) {
            a[i][j] = pow(x[i], j);
        }
    }
    printf("Digite os n+1 valores de f(x) dos pontos a serem interpolados, separados por espaço\n");
    scanVector(b);

    printSystem();

    getUpperTriangularMatrix();
    getX();

    printf("Solução: ");
    for (int i=0; i<dim; i++) {
        printf("%10.6Lf x^%d", *(x+i), i);
        if (i != dim-1) printf(" + ");
    }
    printf("\n");
    printf("agora digite x para saber o valor de f(x) aproximado pela interpolação\n");
    long double x0;
    while (1) {
        scanf("%Lf", &x0);
        printf("%Lf\n", getF(x0));
    }
}
