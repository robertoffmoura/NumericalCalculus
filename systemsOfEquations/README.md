# Cálculo Numérico

Repositório com algumas soluções de problemas de Cálculo Numérico do 4º semestre do IME

## Métodos de resolução de sistemas de equações

### gaussianElimination.c
Serve para resolver sistemas de equações lineares do tipo Ax = b usando o método de eliminação de Gauss. O programa vai perguntar a dimensão da matriz e depois pedir para preencher a matriz e o vetor independente b. O resultado é o vetor solução x do sistema linear
```
./gaussianElimination
```

### gaussJacobi.c
Resolve equações lineares Ax = b usando o método de Gauss-Siedel. O programa pede a dimensão do sistema, as entradas da matriz A, do vetor b, do vetor inicial x, e quantas iterações. Retorna a solução x
```
./gaussJacobi
```

### gaussSiedel.c
Resolve equações lineares Ax = b usando o método de Gauss-Jacobi. O programa pede a dimensão do sistema, as entradas da matriz A, do vetor b, do vetor inicial x, e quantas iterações. Retorna a solução x
```
./gaussSiedel
```

### multivariableFixedPointIteration.c
O programa usa o método do ponto fixo para achar uma aproximação de uma raiz de uma função vetorial f(x0, x1,..., xN) = [0, 0,..., 0], a partir de um valor inicial do vetor x. Você deve editar o programa e colocar a função vetorial de iteração phi tal que phi(x) = x
```
./multivariableFixedPointIteration <número_de_iterações> <valor_incicial_de_x0> <valor_inicial_de_x1> ... <valor_inicial_de_xN>
```

### multivariableNewtonRaphsonMedthod.c
Usa o método de Newthon-Raphson para achar raízes de sistemas de equações. Usando um valor inicial para o vetor x. Você deve editar o programa e colocar a função vetorial f(x) e a matriz jacobiana da função.
```
./multivariableNewtonRaphsonMedthod
```
