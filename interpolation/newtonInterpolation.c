#include <stdio.h>

#define N 100
int dim;
long double x[N];
long double f[N];
long double d[N][N];

void getD() {
    for (int i=0; i<dim; i++) {
        for (int j=0; j<=i; j++) {
            if (j == 0) {
                d[i][j] = f[i];
            } else {
                d[i][j] = (d[i][j-1] - d[i-1][j-1])/(x[i] - x[i-j]);
            }
        }
    }
}

void scanVector(long double *v) {
    for (int i=0; i<dim; i++) {
        scanf("%Lf", v+i);
    }
}

long double term(int i, long double x0) {
    long double t = d[i][i];
    for (int j=0; j<i; j++) {
        t *= (x0-x[j]);
    }
    return t;
}

long double P(long double x0) {
    long double r = 0;
    for (int i=0; i<dim; i++) {
        r += term(i, x0);
    }
    return r;
}

void printTerm(int i) {
    printf("%Lf ", d[i][i]);
    for (int j=0; j<i; j++) {
        printf("(x-%Lf)", x[j]);
    }
}

void printP() {
    for (int i=0; i<dim; i++) {
        printTerm(i);
        if (i != dim-1) {
            printf(" + ");
        }
    }
}

int main() {
    printf("Digite o número n de pontos a serem interpolados\n");
    scanf("%d", &dim);
    printf("Digite os n valores de x dos pontos a serem interpolados, separados por espaço\n");
    scanVector(x);
    printf("Digite os n valores de f(x) dos pontos a serem interpolados, separados por espaço\n");
    scanVector(f);
    getD();
    printf("Polinômio: ");
    printP();
    printf("\n");
    /*
    printf("tabela de diferenças divididas:\n");
    for (int i=0; i<dim; i++) {
        for (int j=0; j<dim; j++) {
            printf("%Lf ", d[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    */
    printf("Agora digite x para saber o valor de f(x) aproximado pela interpolação\n");
    long double x0;
    while (1) {
        scanf("%Lf", &x0);
        printf("%Lf\n", P(x0));
    }
}
