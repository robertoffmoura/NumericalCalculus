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

## eulerMethod.c
Usando o método de Euler, recebe um ponto inicial (x0, y0), o número de iterações e o espaçamento h entre os valores de x. Retorna os pontos seguintes calculados a partir da derivada da função. Você deve editar o programa e colcoar a derivada da função
```
./eulerMethod
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
Resolve equações lineares Ax = b usando o método de Gauss-Jacobi. O programa pede a dimensão do sistema, as entradas da matriz A, do vetor b, do vetor inicial x, e quantas iterações. Retorna a solução x
```
./gaussJacobi
```

## gaussSiedel.c
Resolve equações lineares Ax = b usando o método de Gauss-Siedel. O programa pede a dimensão do sistema, as entradas da matriz A, do vetor b, do vetor inicial x, e quantas iterações. Retorna a solução x
```
./gaussSiedel
```

## interpolationGaussianElimination.c
Pega n+1 pontos e retorna o polinômio interpolador de grau n resolvendo um sistema linear pelo método de eliminação de Gauss
```
./interpolationGaussianElimination
```

## lagrangeMethod.c
Pega n+1 pontos e retorna o polinômio interpolador de grau n usando o método de Lagrange
```
./lagrangeMethod
```

## linearRegression.c
Pega n pontos, faz uma regressão linear e retorna a equação da reta e o valor de r2.
```
./linearRegression
```

## modifiedEulerMethod.c
Usando o método de Euler modificado, recebe um ponto inicial (x0, y0), o número de iterações e o espaçamento h entre os valores de x. Retorna os pontos seguintes calculados a partir da derivada da função. Você deve editar o programa e colcoar a derivada da função
```
./modifiedEulerMethod
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

## newtonInterpolation.c
Pega n+1 pontos e retorna o polinômio interpolador de grau n usando o método de Newton
```
./newtonInterpolation
```

## newtonMethod.c
O programa usa o método de Newton para achar uma aproximação de uma raiz de uma função p, a partir de um valor inicial de x. Você deve editar o programa e colocar a função p e sua derivada p'
```
./newtonMethod <número_de_iterações> <valor_incicial_de_x>
```

## piApproximation.c
Imprime uma tabela com valores de pi aproximados por diferentes séries de Taylor da função arcotangente
```
./piApproximation <número_de_iterações>
```

## romberg.c
Utiliza o método de Romberg para calcular a integral de uma função f(x). Você deve editar o programa para colocar a função f(x).
```
./romberg

```

## simpson.c
Utiliza o método de Simpson para calcular a integral de uma função f(x). Você deve editar o programa para colocar a função f(x).
```
./simpson <extremo_esquerdo> <extremo_direito_do_intervalo> <número_de_partições>

```

## trapezium.c
Utiliza o método dos trapézios para calcular a integral de uma função f(x). Você deve editar o programa para colocar a função f(x).
```
./trapezium
```

## 2ndOrderEulerMethod.c
Usando o método de Euler, recebe um valor de x0, o valor da função y0, o valor da derivada da função y'0, o número de iterações e o espaçamento h entre os valores de x. Retorna os pontos seguintes calculados a partir da derivadas de primeira e segunda ordem da função. Você deve editar o programa e colcoar a derivada de segunda ordem da função
```
./2ndOrderEulerMethod
```

## 4thOrderRungeKutta.c
Usando o método de Runge Kutta, recebe um ponto inicial (x0, y0), o número de iterações e o espaçamento h entre os valores de x. Retorna os pontos seguintes calculados a partir da derivada da função. Você deve editar o programa e colcoar a derivada da função
```
./4thOrderRungeKutta
```
