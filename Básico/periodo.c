//IMPLEMENTAÇÃO DO PERÍODO COM OS VALORES DEFAULT DE A, C E M 

#include <stdio.h>
#include "lcrandom.h"

//Criei essa função para encontrar o pseudoaleatório repetitível 
unsigned long cont_periodo(){
	unsigned long m, x, x_aux;
	unsigned long periodo, i, i_aux=0;

	x=lcrandom_seed();	
	m=lcrandom_max();
	
	do {		
		x=lcrandom(x); //Gero um número pseudoaleatório
		i_aux++; //quantidade de elementos que antecederam valor repetitivel
		x_aux=x; //pego xi para adquirir xi+1
		i=0;
		do { 
			x_aux=lcrandom(x_aux); //aleatorizo o proximo 
			i++;
		}while((i<m) && (x != x_aux)); //comparo se proximo eh igual a atual ate chegar no maximo de iteracoes possiveis
	}while(x != x_aux); //repitirei esse processo enquanto nao encontrar termo que se repete

	periodo=i_aux+i-1; //decremento 1 no final pois ele acaba fazendo uma passo a mais durante as comparacoes devido ao while
	return(periodo); 
}


int main () {
	//Inicializo os parâmetros e limites da minha criação de numeros pseudoaleatŕios
	lcrandom_parms (40692,127,10000000);	

	unsigned long periodo;
	periodo=cont_periodo(); //Faço a contagem do meu período
	printf("Período: %ld\n", periodo);
	
	return 0;
}	
	
		
				
				
