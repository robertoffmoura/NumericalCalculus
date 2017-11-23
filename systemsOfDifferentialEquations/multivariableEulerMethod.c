#include <stdio.h>

#define N 3

/*
Usando o método de Euler, recebe um ponto inicial t0 e o valor da função vetorial x(t0) nesse ponto, o número de iterações e o espaçamento h entre os valores de x. Retorna os pontos seguintes calculados a partir da derivada da função vetorial. Você deve editar o programa e colcoar a derivada da função vetorial (cada coordenada).
*/

long double xLinha0(long double* x, long double t) { return x[0] -4*x[1]; }
long double xLinha1(long double* x, long double t) { return -x[0] + x[1]; }
long double xLinha2(long double* x, long double t) { return 0; }

void iterate(long double *t, long double *x, long double h) {
    long double f[N];
    f[0] = xLinha0(x, *t);
    f[1] = xLinha1(x, *t);
    f[2] = xLinha2(x, *t);
    for (int i=0;i<N;i++) {
        x[i] += h*f[i];
    }
    *t += h;
}

void printVector(long double t0, long double* x) {
    printf("%Lf", t0);
    for (int i=0;i<N;i++) {
        printf("\t%Lf:",x[i]);
    }
    printf("\n");
}

int main() {
    long double t0, h;
    long double x[N];
    int n;
    printf("Bem-vindo ao programa que resolve o problema vetorial de valor inicial\nx' = f(t,x)\nx(t0) = x0\n");
    printf("Digite t0 e em seguida as coordenadas do vetor inicial (x0");
    for (int i=0;i<N-1;i++) {
        printf(", x%d", i+1);
    }
    printf(") conhecido\n");
    scanf("%Lf", &t0);
    for (int i=0;i<N;i++) {
        scanf("%Lf", &x[i]);
    }
    printf("Agora digite o número de iterações\n");
    scanf("%d",&n);
    printf("Dgite o espaçamento h entre cada valor de x\n");
    scanf("%Lf", &h);

    printf("t:");
    for (int i=0;i<n;i++) {
        printf("\t\tx%d:",i);
    }
    printf("\n");
    printVector(t0, x);
    for (int i=0;i<n;i++) {
        iterate(&t0,x,h);
        printVector(t0, x);
    }

}
