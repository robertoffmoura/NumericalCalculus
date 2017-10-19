#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
O programa usa o método do ponto fixo para achar uma aproximação de uma raiz de uma função f(x) = 0, a partir de um valor inicial de x, fazendo um número fixo de iterações. Você deve editar o programa e colocar a função de iteração phi tal que phi(x) = x

Uso:
./fixedPointIteration <número_de_iterações> <valor_incicial_de_x>
*/

//Define a função phi de iteração
long double phi(long double x) {
    //Coloque sua função de iteração logo depois do "return"
    return sqrt(6-x);
}

//Realiza a iteração da função phi, n vezes, a partir de um valor x
long double iterate(long double x, int n) {
    for (int j=0;j<n;j++) {
        x = phi(x);
    }
    return x;
}

//essa função recebe os dados enviados pelo usuário e devolve ou entrega a aproximação da raiz da função f(x)
int main(int argc, char *argv[]) {
    if (argc != 3) {
        //Ao rodar o programa a partir da linha de comando, deve-se especificar dois argumentos: o número n de iterações desejadas e o valor inicial do seu chute x0
        printf("Número de argumentos incorreto\n");
        printf("Uso correto: ./fixedPointMethod <número_de_iterações> <valor_incicial_de_x>\n");
        return 1;
    }
    //armazena os argumentos da linha de comando nas variáveis n e x0
    int n = atoi(argv[1]);
    long double x0 = atof(argv[2]);
    //mostra na tela o valor aproximado
    printf("raiz = %3.24Lf\n", iterate(x0, n));
    return 0;
}
