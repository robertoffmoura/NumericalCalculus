#include <stdio.h>

long double yLinha(long double x, long double y) {
    return 2*x;
}

void iterate(long double *x, long double *y, long double h) {
    long double r1 = yLinha(*x, *y);
    long double r2 = yLinha(*x + h/2.0, *y + r1*h/2.0);
    long double r3 = yLinha(*x + h/2.0, *y + r2*h/2.0);
    long double r4 = yLinha(*x + h, *y + r3*h);
    *y += h*(r1 + 2.0*r2 + 2.0*r3 + r4)/6.0;
    *x += h;
}

int main() {
    long double x0, y0, h;
    int n;
    printf("Digite as coordenadas do ponto inicial (x0, y0) conhecido\n");
    scanf("%Lf%Lf", &x0, &y0);
    printf("Agora digite o número de iterações\n");
    scanf("%d", &n);
    printf("Dgite o espaçamento h entre cada valor de x\n");
    scanf("%Lf", &h);

    printf("x:\t\ty:\n");
    printf("%Lf\t%Lf\n", x0, y0);
    for (int i=0; i<n; i++) {
        iterate(&x0, &y0, h);
        printf("%Lf\t%Lf\n", x0, y0);
    }

}
