#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
Se há uma raiz de uma funcão f em um intervalo [a,b], o programa divide o intervalo recursivamente um número i de vezes, usando a seguinte fórmula:
x = (a*f(b) - b*f(a)) / (f(b) - f(a))
Você deve editar o programa e colocar a função f.

Uso:
./falsePositionMethod <número_de_iterações> <extremo_esquerdo> <extremo_direito_do_intervalo>
*/

long double f(long double x) {
    //Coloque sua função logo depois do "return"
    return x*x*x - 3.2*x*x + 0.21*x + 4.41;
}

long double root(int i, long double m, long double n) {
    if (f(m)*f(n) > 0) {
        printf("Não há raizes ou há um número par de raízes no intervalo [%Lf, %Lf]\n",m,n);
        return 0;
    }
    if (i < 1) {
        printf("Número de iterações inválido\n");
        return 0;
    }
    long double fn = f(n);
    long double fm = f(m);
    long double c = (m*fn-n*fm)/(fn-fm);
    if (i == 1) {
        return c;
    }
    if ((f(m) < 0 && f(c) > 0) || (f(m) > 0 && f(c) < 0)) {
        return root(i-1,m,c);
    }
    if ((f(c) < 0 && f(n) > 0) || (f(c) > 0 && f(n) < 0)) {
        return root(i-1,c,n);
    }
    if (f(c) == 0) {
        return c;
    }
    return 0;
}

long double error(int i, long double m, long double n) {
    return (n-m)/pow(2,i);
}

void table(int x, long double m, long double n) {
    for (long double c = m; c < n; c += x) {
        printf("%3.6Lf : %3.6Lf\n", c, f(c));
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Número de argumentos incorreto\n");
        printf("Uso correto: ./falsePositionMethod <número_de_iterações> <extremo_esquerdo> <extremo_direito_do_intervalo>\n");
        return 1;
    }
    int n = atoi(argv[1]);
    long double a = atoi(argv[2]);
    long double b = atoi(argv[3]);
    //table(n, a, b);
    printf("raiz = %3.24Lf ± %3.6Le\n", root(n, a, b), error(n, a, b));
    return 0;
}
