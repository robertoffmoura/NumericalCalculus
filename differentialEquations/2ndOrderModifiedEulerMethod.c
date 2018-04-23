#include <stdio.h>

long double y2Linha(long double x, long double y, long double yLinha) {
    return -y;
}

void iterate(long double *x, long double *y, long double *yLinha,long double h) {
    long double yn = *y + h*(*yLinha) + h*h/2.0*y2Linha(*x,*y,*yLinha); //taylor series
    long double ynLinha = *yLinha + h*(y2Linha(*x,*y,*yLinha) + y2Linha(*x+h, *y+h*(*yLinha), *yLinha + h*y2Linha(*x,*y,*yLinha)))/2.0;
    *y = yn;
    *yLinha = ynLinha;
    *x += h;
}

int main() {
    long double x0, y0, yLinha0, h;
    int n;
    printf("Digite x0, depois y(x0) e depois y`(x0)\n");
    scanf("%Lf%Lf%Lf", &x0, &y0, &yLinha0);
    printf("Agora digite o número de iterações\n");
    scanf("%d", &n);
    printf("Dgite o espaçamento h entre cada valor de x\n");
    scanf("%Lf", &h);

    printf("x:\t\ty:\t\ty`:\n");
    printf("%Lf\t%Lf\t%Lf\n", x0, y0, yLinha0);
    for (int i=0; i<n; i++) {
        iterate(&x0, &y0, &yLinha0, h);
        printf("%Lf\t%Lf\t%Lf\n", x0, y0, yLinha0);
    }

}
