//IMPLEMENTAÇÃO DAS FUNÇÕES DO GERADOR DE ALEATÓRIOS

#include "lcrandom.h"
#include <stdio.h>

//Minhas variáveis globais definidas para serem vistas apenas nesse escopo
static unsigned long  m, a, c;

//Calcula e devolve valor pseudoaleatório 
unsigned long lcrandom (unsigned long x) {		
	x = (a*x + c) % (int)m;
	return(x);
}

//Define valor inicial
unsigned long lcrandom_seed () {
	unsigned long s=0;
	printf("Entre com a seed\n");
	scanf("%ld", &s); //por default minha seed sera zero, podendo ser alguma outra tambem
	return(s);
}	

//Define o valor máximo a ser gerado
unsigned long lcrandom_max () {
	return(m);
}

//Modifica os parâmetros da equação do gerador
void lcrandom_parms (unsigned long A, unsigned long C, unsigned long M) {
	a=A; 
	c=C;
	m=M;
} 
