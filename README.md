# Cálculo Numérico

Repositório com algumas soluções de problemas de Cálculo Numérico do 4º semestre do IME

## baseChange.c
Pega um número em uma base e retorna ele em outra base
```
./baseChange <número> <base_inicial> <base_final>
```

## bisectionMethod.c
Se há uma raiz de uma funcão f em um intervalo [a,b], o programa divide o intervalo pela metade recursivamente um número i de vezes. Você deve editar o programa e colocar a função f
```
./bisectionMethod <número_de_iterações> <extremo_esquerdo> <extremo_direito_do_intervalo>
```

## falsePositionMethod.c
Se há uma raiz de uma funcão f em um intervalo [a,b], o programa divide o intervalo recursivamente um número i de vezes, usando a seguinte fórmula:
x = (a*f(b) - b*f(a)) / (f(b) - f(a))
Você deve editar o programa e colocar a função f.
```
./falsePositionMethod <número_de_iterações> <extremo_esquerdo> <extremo_direito_do_intervalo>

```
## fixedPointIteration.c
O programa usa o método do ponto fixo para achar uma aproximação de uma raiz de uma função f(x) = 0, a partir de um valor inicial de x. Você deve editar o programa e colocar a função de iteração phi tal que phi(x) = x
```
./fixedPointIteration <número_de_iterações> <valor_incicial_de_x>
```

## gaussianElimination.c
Serve para resolver sistemas de equações lineares do tipo Ax = b usando o método de eliminação de Gauss. O programa vai perguntar a dimensão da matriz e depois pedir para preencher a matriz e o vetor independente b. O resultado é o vetor solução x do sistema linear
```
./gaussianElimination
```

## gaussJacobi.c
Resolve equações lineares Ax = b usando o método de Gauss-Siedel. O programa pede a dimensão do sistema, as entradas da matriz A, do vetor b, do vetor inicial x, e quantas iterações. Retorna a solução x
```
./gaussJacobi
```

## gaussSiedel.c
Resolve equações lineares Ax = b usando o método de Gauss-Jacobi. O programa pede a dimensão do sistema, as entradas da matriz A, do vetor b, do vetor inicial x, e quantas iterações. Retorna a solução x
```
./gaussSiedel
```

## multivariableFixedPointIteration.c
O programa usa o método do ponto fixo para achar uma aproximação de uma raiz de uma função vetorial f(x0, x1,..., xN) = [0, 0,..., 0], a partir de um valor inicial do vetor x. Você deve editar o programa e colocar a função vetorial de iteração phi tal que phi(x) = x
```
./multivariableFixedPointIteration <número_de_iterações> <valor_incicial_de_x0> <valor_inicial_de_x1> ... <valor_inicial_de_xN>
```

## multivariableNewtonRaphsonMedthod.c
Usa o método de Newthon-Raphson para achar raízes de sistemas de equações. Usando um valor inicial para o vetor x. Você deve editar o programa e colocar a função vetorial f(x) e a matriz jacobiana da função.
```
./multivariableNewtonRaphsonMedthod
```

## newtonMethod.c
O programa usa o método de Newton para achar uma aproximação de uma raiz de uma função p, a partir de um valor inicial de x. Você deve editar o programa e colocar a função p e sua derivada p'
```
./newtonMethod <número_de_iterações> <valor_incicial_de_x>
```
