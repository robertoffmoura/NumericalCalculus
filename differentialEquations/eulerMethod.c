#include <stdio.h>

long double yLinha(long double x, long double y) {
    // Coloque a derivada da sua função aqui
    return 2*x;
}

void iterate(long double *x, long double *y, long double h) {
    *y += h*yLinha(*x, *y);
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
        //y0 += h*yLinha(x0, y0);
        //x0 += h;
        printf("%Lf\t%Lf\n", x0, y0);
    }

}
