#include <stdio.h>
#include <math.h>
#include <stdlib.h>

long double f(long double x) {
    return x*x*x*x;
}

long double integral(long double a, long double b, int n) {
    long double r = 0;
    r += f(a);
    for (int i=1; i<n; i+=2) {
        r += 4*f(a + (b-a)*i/n);
    }
    for (int i=2; i<n; i+=2) {
        r += 2*f(a + (b-a)*i/n);
    }
    r += f(b);
    r *= (b-a)/(3*n);
    return r;
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Número de argumentos incorreto\n");
        printf("Uso correto: ./simpson <extremo_esquerdo> <extremo_direito_do_intervalo> <número_de_partições>\n");
        return 1;
    }
    long double a, b;
    int n;
    /*
    printf("Digite os extremos do intervalo [a,b] que será integrado\n");
    scanf("%Lf%Lf", &a, &b);
    printf("Agora digite o número de partições do intervalo\n");
    scanf("%d", &n);
    */
    a = atof(argv[1]);
    b = atof(argv[2]);
    n = 2*atoi(argv[3]);
    printf("Integral = %Lf\n", integral(a, b, n));
}
