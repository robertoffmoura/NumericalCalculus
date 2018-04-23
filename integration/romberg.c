#include <stdio.h>
#include <math.h>

#define N 100
long double I[N][N];

long double f(long double x) {
    return 6-6*pow(x,5);
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

void getI(long double a, long double b, int m) {
    for (int j=0; j<=m; j++) {
        for (int i=0; i<=m-j; i++) {
            if (j == 0) {
                I[i][j] = integral(a, b, (int)pow(2, i));
            } else {
                I[i][j] = ( pow(4,j)*I[i+1][j-1] - I[i][j-1] ) / ( pow(4,j) - 1.0 );
            }
        }
    }
}

int main() {
    long double a,b;
    int m;
    printf("Digite os extremos do intervalo [a,b] que será integrado\n");
    scanf("%Lf%Lf", &a, &b);
    printf("Agora digite o número de iterações\n");
    scanf("%d", &m);
    getI(a, b, m);
    printf("Integral = %Lf\n", I[0][m]);
}
