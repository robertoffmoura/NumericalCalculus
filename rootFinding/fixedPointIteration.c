#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//essa função define a função phi que será iterada
long double phi(long double x) {
    // coloque sua função de iteração logo depois do "return", assim: "return 'sua função'; "
    return sqrt(6-x);
}

//essa função realiza a iteração da função phi
long double iterate(long double x, int i) {
    //x é a sua expressão para o x isolado na equação; na função main ele é o x0
    //i é o número de iterações que você quer fazer; n função main ele é o n
    for (int j=0;j<i;j++) {
        //aqui você está iterando x usando a função phi que você definiu logo acima
        x = phi(x);
    }
    return x;
}

//essa função recebe os dados enviados pelo usuário e devolve ou entrega a aproximação da raiz da função phi definida lá encima
int main(int argc, char *argv[]) {
    if (argc != 3) {
        //a passagem de dados através da linha de comando deve constar de apenas 2 dados, o número n de iterações desejadas e o valor inicial do seu chute x0
        //aqui é dito que foi enviado um número errado de dados
        printf("Número de argumentos incorreto\n");
        //aqui é explicado como é o envio correto
        printf("Uso correto: ./fixedPointMethod <número_de_iterações> <valor_incicial_de_x>\n");
        return 1;
    }
    //aqui é passada à variável inteira n a primeira entrada da linha de comando, por isso É IMPORTANTE ENVIAR NA ORDEM CERTA
    int n = atoi(argv[1]);
    //aqui é passada à variável inteira n a primeira entrada da linha de comando, por isso É IMPORTANTE ENVIAR NA ORDEM CERTA
    long double x0 = atof(argv[2]);
    //mostra na tela o valor aproximado
    printf("raiz = %3.24Lf\n", iterate(x0, n));
    return 0;
}
