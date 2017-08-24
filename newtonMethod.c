#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long double p(long double x) {
    // coloque sua função aqui
    return exp(x) - 2.0*cos(x);
}

long double pLinha(long double x) {
    // coloque sua derivada da função aqui
    return exp(x) + 2.0*sin(x);
}

long double newton(long double x0, int i) {
    if (i==0) return x0;
    return newton(x0 - p(x0)/pLinha(x0),i-1);
}

int main(int argc, char *argv[]) {
    // como usar:
    // ./a.out <número de iterações> <valor inicial de x>
    // exemplo: ./a.out 3 0.5
    int n = atoi(argv[1]);
    long double x0 = atof(argv[2]);
    printf("root = %3.24Lf\n", newton(x0,n);
    return 0;
}
