#include <stdio.h>

#define N 100
int dim;
long double x[N];
long double y[N];

void scanVector(long double *v) {
    for (int i=0;i<dim;i++) {
        scanf("%Lf", v+i);
    }
}

long double l(int k, long double x0) {
    long double r = 1.0;
    for (int i=0;i<dim;i++) {
        if (i != k) {
            r *= (x0 - x[i]);
            r /= (x[k] - x[i]);
        }
    }
    return r;
}

long double getF(long double x0) {
    long double r = 0;
    for (int k=0;k<dim;k++) {
        r += y[k]*l(k, x0);
    }
    return r;
}

void printL(int k) {
    for (int i=0;i<dim;i++) {
        if (i!=k) {
            printf("(x-%.1Lf)",x[i]);
        }
    }
    printf("/");
    long double d = 1;
    for (int i=0;i<dim;i++) {
        if (i!=k) {
            d *= (x[k] - x[i]);
        }
    }
    printf("%.1Lf",d);
}

void printPolynom() {
    for (int k=0;k<dim;k++) {
        printf("%.3Lf ", y[k]);
        printL(k);
        if (k != dim-1) {
            printf(" + ");
        }
    }
}

int main() {
    printf("Digite o número n = ordem do polinômio interpolador\n");
    scanf("%d", &dim);
    dim++;
    printf("Digite os n+1 valores de x dos pontos a serem interpolados, separados por espaço\n");
    scanVector(x);
    printf("Digite os n+1 valores de f(x) dos pontos a serem interpolados, separados por espaço\n");
    scanVector(y);
    printf("polinômio: ");
    printPolynom();
    printf("\n");
    printf("agora digite x para saber o valor de f(x) aproximado pela interpolação\n");
    long double x0;
    while (1) {
        scanf("%Lf", &x0);
        printf("%Lf\n", getF(x0));
    }
}
