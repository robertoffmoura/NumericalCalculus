# Cálculo Numérico

Repositório com algumas soluções de problemas de Cálculo Numérico do 4º semestre do IME

## Métodos de procura de raízes de funções

### bisectionMethod.c
Se há uma raiz de uma funcão f em um intervalo [a,b], o programa divide o intervalo pela metade recursivamente um número i de vezes. Você deve editar o programa e colocar a função f
```
./bisectionMethod <número_de_iterações> <extremo_esquerdo> <extremo_direito_do_intervalo>
```

### falsePositionMethod.c
Se há uma raiz de uma funcão f em um intervalo [a,b], o programa divide o intervalo recursivamente um número i de vezes, usando a seguinte fórmula:
x = (a*f(b) - b*f(a)) / (f(b) - f(a))
Você deve editar o programa e colocar a função f.
```
./falsePositionMethod <número_de_iterações> <extremo_esquerdo> <extremo_direito_do_intervalo>

```
### fixedPointIteration.c
O programa usa o método do ponto fixo para achar uma aproximação de uma raiz de uma função f(x) = 0, a partir de um valor inicial de x. Você deve editar o programa e colocar a função de iteração phi tal que phi(x) = x
```
./fixedPointIteration <número_de_iterações> <valor_incicial_de_x>
```

### newtonMethod.c
O programa usa o método de Newton para achar uma aproximação de uma raiz de uma função p, a partir de um valor inicial de x. Você deve editar o programa e colocar a função p e sua derivada p'
```
./newtonMethod <número_de_iterações> <valor_incicial_de_x>
```
