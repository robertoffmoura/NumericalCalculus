#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long double phi(long double x) {
    // coloque sua função de iteração aqui
    return sqrt(6-x);
}

long double getRoot(long double x, int i) {
    for (int j=0; j<i; j++) {
        x = phi(x);
    }
    return x;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Número de argumentos incorreto\n");
        printf("Uso correto: ./fixedPointMethod <número_de_iterações> <valor_incicial_de_x>\n");
        return 1;
    }
    int n = atoi(argv[1]);
    long double x0 = atof(argv[2]);
    printf("root = %3.24Lf\n", getRoot(x0,n));
    return 0;
}
