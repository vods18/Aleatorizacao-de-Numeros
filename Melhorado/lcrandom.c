//Vinícius Oliveira dos Santos    GRR20182592
//IMPLEMENTAÇÃO DAS FUNÇÕES DO GERADOR DE ALEATÓRIOS

#include "lcrandom.h"

//Minhas variáveis globais definidas para serem "vistas" apenas nesse escopo
static unsigned long x, m, a, c;

//Calcula e devolve valor pseudoaleatório 
unsigned long lcrandom () {		
	x = (a*x + c) % (int)m;
	return(x);
}

//Defini valor inicial
void lcrandom_seed (unsigned long s) {
	s=0;
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
