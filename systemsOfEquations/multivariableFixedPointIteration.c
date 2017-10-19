#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
O programa usa o método do ponto fixo para achar uma aproximação de uma raiz de uma função vetorial f(x0, x1,..., xN) = [0, 0,..., 0], a partir de um valor inicial do vetor x. Você deve editar o programa e colocar a função vetorial de iteração phi tal que phi(x) = x

Uso:
./multivariableFixedPointIteration <número_de_iterações> <valor_incicial_de_x0> <valor_inicial_de_x1> ... <valor_inicial_de_xN>
*/

//N é a dimenão, número de coordenadas da função
#define N 3
long double x[N];

//Define cada coordenada da função de iteração phi(x)
long double phi0(long double* x) { return sqrt(1-x[1]*x[1]); }
long double phi1(long double* x) { return x[0]/2; }
long double phi2(long double* x) { return x[0]+x[1]; }

void printVector(long double *v) {
    printf("[ ");
    for (int i=0;i<N;i++) {
        printf("%10.6Lf ", *(v+i));
    }
    printf("]\n");
}

void iterate(int n) {
    for (int i=0; i<n; i++) {
        long double temp[N];
        temp[0] = phi0(x);
        temp[1] = phi1(x);
        temp[2] = phi2(x);
        for (int j=0;j<N;j++) {
            x[j] = temp[j];
        }
        printf("%*dª iteração: ", (int)log10(n)+1, i);
        printVector(x);
    }
}


int main(int argc, char *argv[]) {
    //Pesquisar: Banach Fixed Point Theorem
    //Se a o módulo do vetor derivada de phi é sempre menor que 1, a sequeência converge
    if (argc != 2+N) {
        printf("Número de argumentos incorreto\n");
        printf("Uso correto: ./fixedPointIteration_SystemOfEquations <número_de_iterações> <valor_incicial_de_x0> ...  <valor_incicial_de_x2>\n");
        return 1;
    }
    int n = atoi(argv[1]);
    for (int i=0;i<N;i++) {
        x[i] = atof(argv[2+i]);
    }
    iterate(n);
    //printVector(x);
    return 0;
}
