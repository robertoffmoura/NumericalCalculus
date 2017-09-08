#include <stdio.h>
#include <math.h>

#define N 100
int n;
long double x[N];
long double y[N];
long double c0, c1;

void scanVector(long double *v) {
    for (int i=0;i<n;i++) {
        scanf("%Lf", v+i);
    }
}

void getLine() {
    long double sumX = 0;
    long double sumY = 0;
    long double sumX2 = 0;
    long double sumXY = 0;
    for (int i=0;i<n;i++) {
        sumX += x[i];
        sumY += y[i];
        sumX2 += x[i]*x[i];
        sumXY += x[i]*y[i];
    }
    c0 = (sumX2*sumY-sumXY*sumX)/(n*sumX2-sumX*sumX);
    c1 = (sumY*sumX-n*sumXY)/(sumX*sumX-n*sumX2);
}

long double f(long double x) {
    return c1*x + c0;
}

long double average(long double *v) {
    long double r = 0;
    for (int i=0;i<n;i++) {
        r += v[i];
    }
    r /= n;
    return r;
}

long double r2() {
    long double ym = average(y);
    long double sum1 = 0;
    long double sum2 = 0;
    for (int i=0;i<n;i++) {
        sum1 += pow(y[i] - f(x[i]), 2);
        sum2 += pow(y[i] - ym, 2);
    }
    return 1.0-(sum1/sum2);
}

int main() {
    printf("Digite o número de pontos\n");
    scanf("%d", &n);
    printf("Digite os n+1 valores de x dos pontos, separados por espaço\n");
    scanVector(x);
    printf("Digite os n+1 valores de y dos pontos, separados por espaço\n");
    scanVector(y);
    getLine();
    printf("Equação da reta: ");
    printf("y = %Lfx + %Lf\n", c1, c0);
    printf("r2 = %Lf\n", r2());
    printf("agora digite x para saber o valor de f(x)\n");
    long double x0;
    while (1) {
        scanf("%Lf", &x0);
        printf("%Lf\n", f(x0));
    }
}
