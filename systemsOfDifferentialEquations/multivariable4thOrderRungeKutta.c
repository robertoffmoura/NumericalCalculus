#include <stdio.h>
#include <stdlib.h>

/*
Usando o método de Runge Kutta, recebe um ponto inicial t0 e o valor da função vetorial x(t0) nesse ponto, o número de iterações e o espaçamento h entre os valores de t. Retorna os pontos seguintes calculados a partir da derivada da função vetorial. Você deve editar o programa e colcoar a derivada da função vetorial (cada coordenada).
*/

#define N 3

typedef long double (*functionPointer)( long double*, long double );
functionPointer xLinha[N];

long double xLinha0(long double* x, long double t) { return x[0] -4*x[1]; }
long double xLinha1(long double* x, long double t) { return -x[0] + x[1]; }
long double xLinha2(long double* x, long double t) { return 0; }

long double* addVectors(long double* a, long double* b) {
    long double* m = malloc(N*sizeof(long double)+1);
    for (int i=0; i<N; i++) {
        m[i] = a[i] + b[i];
    }
    return m;
}

long double* scaleVector(long double*a, long double alpha) {
    long double* m = malloc(N*sizeof(long double)+1);
    for (int i=0; i<N; i++) {
        m[i] = a[i]*alpha;
    }
    return m;
}

void iterate(long double *t, long double *x, long double h) {
    long double r1[N], r2[N], r3[N], r4[N];

    for (int i=0; i<N; i++) { r1[i] = xLinha[i](x, *t); }

    long double* x2 = addVectors(x,scaleVector(r1,h/2.0));
    for (int i=0; i<N; i++) { r2[i] = xLinha[i](x2, *t + h/2.0); }

    long double* x3 = addVectors(x,scaleVector(r2,h/2.0));
    for (int i=0; i<N; i++) { r3[i] = xLinha[i](x3, *t + h/2.0); }

    long double* x4 = addVectors(x,scaleVector(r3,h));
    for (int i=0; i<N; i++) { r4[i] = xLinha[i](x4, *t + h); }

    for (int i=0; i<N; i++) {
        x[i] += h*(r1[i] + 2.0*r2[i] + 2.0*r3[i] + r4[i])/6.0;
    }
    *t += h;
}

void printVector(long double t0, long double* x) {
    printf("%Lf", t0);
    for (int i=0; i<N; i++) {
        printf("\t%Lf:", x[i]);
    }
    printf("\n");
}

int main() {
    xLinha[0] = xLinha0;
    xLinha[1] = xLinha1;
    xLinha[2] = xLinha2;
    long double t0, h;
    long double x[N];
    int n;
    printf("Bem-vindo ao programa que resolve o problema vetorial de valor inicial\nx' = f(t,x)\nx(t0) = x0\n");
    printf("Digite t0 e em seguida as coordenadas do vetor inicial (x0");
    for (int i=0; i<N-1; i++) {
        printf(", x%d", i+1);
    }
    printf(") conhecido\n");
    scanf("%Lf", &t0);
    for (int i=0; i<N; i++) {
        scanf("%Lf", &x[i]);
    }
    printf("Agora digite o número de iterações\n");
    scanf("%d", &n);
    printf("Dgite o espaçamento h entre cada valor de x\n");
    scanf("%Lf", &h);

    printf("t:");
    for (int i=0; i<n; i++) {
        printf("\t\tx%d:", i);
    }
    printf("\n");
    printVector(t0, x);
    for (int i=0; i<n; i++) {
        iterate(&t0, x, h);
        printVector(t0, x);
    }

}
