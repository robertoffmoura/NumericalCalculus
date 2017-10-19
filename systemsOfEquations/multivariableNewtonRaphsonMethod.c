#include <stdio.h>
#include <math.h>

/*
Usa o método de Newthon-Raphson para achar raízes de sistemas de equações. Usando um valor inicial para o vetor x. Você deve editar o programa e colocar a função vetorial f(x) e a matriz jacobiana da função, ou seja, cada uma das derivadas parciais de cada uma das coordenadas da função f(x)
*/

//N é a dimenão, número de coordenadas da função f(x)
#define N 3

long double a[N][N];
long double s[N];
long double b[N];
long double x[N];

//Define as derivadas parciais de cada coordenada da função f(x)
//exemplo: df2dx3 é a derivada de f2 em relação a x3, ou seja, a derivada da segunda coordenada de f em relação à terceira variável da função
long double df1dx1(long double* x) { return -1.0/1; }
long double df1dx2(long double* x) { return sin(1+x[2]); }
long double df1dx3(long double* x) { return x[1]*cos(1+x[2]); }
long double df2dx1(long double* x) { return -1.0/2; }
long double df2dx2(long double* x) { return sin(2+x[2]); }
long double df2dx3(long double* x) { return x[1]*cos(2+x[2]); }
long double df3dx1(long double* x) { return -1.0/3; }
long double df3dx2(long double* x) { return sin(3+x[2]); }
long double df3dx3(long double* x) { return x[1]*cos(3+x[2]); }

//Define cada coordenada da função f
long double f1(long double* x) { return 1.0+x[1]*sin(1+x[2]) - x[0]/1; }
long double f2(long double* x) { return 1.0+x[1]*sin(2+x[2]) - x[0]/2; }
long double f3(long double* x) { return 1.0+x[1]*sin(3+x[2]) - x[0]/3; }

void getJ(long double* x) {
    a[0][0] = df1dx1(x);
    a[0][1] = df1dx2(x);
    a[0][2] = df1dx3(x);
    a[1][0] = df2dx1(x);
    a[1][1] = df2dx2(x);
    a[1][2] = df2dx3(x);
    a[2][0] = df3dx1(x);
    a[2][1] = df3dx2(x);
    a[2][2] = df3dx3(x);
}

void getF(long double* x) {
    b[0] = f1(x);
    b[1] = f2(x);
    b[2] = f3(x);
}

long double absoluteValue(long double x) { return x > 0 ? x : -x; }

void swapRows(int i1, int i2) {
    if (i1==i2) return;
    long double temp;
    for (int j=i1;j<N;j++) {
        temp = a[i1][j];
        a[i1][j] = a[i2][j];
        a[i2][j] = temp;
    }
    temp = b[i1];
    b[i1] = b[i2];
    b[i2] = temp;
    return;
}

int max(int column) {
    int maxIndex = column;
    for (int i=column;i<N;i++) {
        if (absoluteValue(a[i][column]) > absoluteValue(a[maxIndex][column])) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

void getUpperTriangularMatrix() {
    for (int j=0;j<N;j++) {
        int maxItemInColumnIndex = max(j);
        if (a[maxItemInColumnIndex][j] == 0) {
            printf("determinant is zero");
            return;
        }
        swapRows(j,maxItemInColumnIndex);
        for (int i=j+1;i<N;i++) {
            long double aij = a[i][j];
            for (int j2=j;j2<N;j2++) {
                a[i][j2]-=a[j][j2]*aij/a[j][j];
            }
            b[i]-=b[j]*aij/a[j][j];
        }
    }
}

void getS() {
    long double r;
    for (int i=N-1;i>-1;i--) {
        r = b[i];
        for (int j=N-1;j>i;j--) {
            r -= a[i][j]*s[j];
        }
        s[i] = r/a[i][i];
    }
}

void scanVector(long double *v) {
    for (int i=0;i<N;i++) {
        scanf("%Lf", v+i);
    }
}

void printVector(long double *v) {
    printf("[ ");
    for (int i=0;i<N;i++) {
        printf("%10.6Lf ", *(v+i));
    }
    printf("]\n");
}

void iterate(int n) {
    for (int i=0;i<n;i++) {
        getJ(x);
        getF(x);

        //Solve the linear system: J(X) S = F(X)
        getUpperTriangularMatrix();
        getS();
        //
        for (int j=0;j<N;j++) {
            x[j] -= s[j];
            ;
        }
        printVector(x);
    }
}


int main() {
    int n;
    printf("digite as coordenadas do vetor x inicial separadas por espaço\n");
    scanVector(x);
    printf("digite o número de iterações\n");
    scanf("%d",&n);
    iterate(n);
    return 0;
}
