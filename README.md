# Geracao-de-Numeros-Aleatorios
Atividade acadêmica da disciplina Oficina de Computação ministrada pelo professor Carlos Maziero com alguma mudanças e melhorias.

Fórmula de congruência linear: xi+1 = (A · xi + C) mod M

Parâmetros que usei para testes básicos A,C e M respectivamente: 40692 127 10000000


Parâmetros que usei para testes complexos A,C e M respectivamente: 1103515245 12345 1073741824

### Como executar:
```bash
Histograma:

gcc lcrandom.c lcrandom.h histograma.c -Wall -g
./a.out

Periodo:
gcc lcrandom.c lcrandom.h periodo.c -Wall -g
./a.out
```
