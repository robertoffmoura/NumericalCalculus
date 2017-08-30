# Cálculo Numérico

Repositório com algumas soluções de problemas de Cálculo Numérico do 4º semestre do IME

## binaryRootSearch.c
Se há uma raiz de uma funcão em um intervalo [a,b], o programa divide o intervalo pela metade recursivamente um número i de vezes. Você deve editar o programa e colocar a função p.
```
./binaryRootSearch <número_de_iterações> <extremo_esquerdo> <extremo_direito_do_intervalo>
```
## newtonMethod.c
O programa usa o método de Newton para achar uma aproximação de uma raiz de uma função, a partir de um valor inicial de x. Você deve editar o programa e colocar a função p e sua derivada p'.
```
./newtonMethod <número_de_iterações> <valor_incicial_de_x>
```
## solveLinearSystem.c
Serve para resolver sistemas de equações lineares do tipo Ax = b. O programa vai perguntar a dimensão da matriz e depois pedir para preencher a matriz e o vetor independente b. O resultado é o vetor solução x do sistema linear.
```
./solveLinearSystem
```
