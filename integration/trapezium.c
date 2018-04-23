#include <stdio.h>
#include <math.h>

long double f(long double x) {
    return x*x;
}

long double integral(long double a, long double b, int n) {
    long double r = 0;
    r += f(a)/2.0;
    for (int i=1; i<n; i++) {
        r += f(a + (b-a)*i/n);
    }
    r += f(b)/2.0;
    r *= (b-a)/n;
    return r;
}

int main() {
    long double a, b;
    int n;
    printf("Digite os extremos do intervalo [a,b] que será integrado\n");
    scanf("%Lf%Lf", &a, &b);
    printf("Agora digite o número de partições do intervalo\n");
    scanf("%d", &n);
    printf("Integral = %Lf\n", integral(a, b, n));
}
