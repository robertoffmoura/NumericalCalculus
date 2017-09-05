#include <stdio.h>
#include <math.h>
#include <stdlib.h>

unsigned long int fromBaseBtoBase10(unsigned int n, unsigned int b) {
    if (b == 10) return n;
    unsigned long int result = 0;
    for (int i=0; n>0; i++) {
        result += (n-(n/10)*10)*pow(b,i);
        n /= 10;
    }
    return result;
}

unsigned long int fromBase10toBaseB(unsigned int n, unsigned int b) {
    if (b == 10) return n;
    unsigned long int result = 0;
    for (int i=log(n)/log(b); i>=0; i--) {
        int r = n/pow(b,i);
        result *= 10;
        result += r;
        n -= pow(b,i)*r;
    }
    return result;
}

int checkRange(unsigned long int x) {
    return (2 <= x && x <= 10);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Número incorreto de argumentos\n");
        printf("Uso correto: ./baseChange <número> <base_inicial> <base_final>\n");
        return 1;
    }
    unsigned long int numero1, base1, base2;
    numero1 = atoi(argv[1]);
    base1 = atoi(argv[2]);
    base2 = atoi(argv[3]);
    if (!checkRange(base1) || !checkRange(base2)) {
        printf("As bases devem ser inteiros no intervalo [2, 10]\n");
        return 1;
    }
    printf("%lu\n", fromBase10toBaseB(fromBaseBtoBase10(numero1, base1), base2));
    return 0;
}
