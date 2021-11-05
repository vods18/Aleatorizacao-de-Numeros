//Vinícius Oliveira dos Santos    GRR20182592
//IMPLEMENTAÇÃO DO PERÍODO COM OS VALORES DEFAULT DE A, C E M 

#include <stdio.h>
#include "lcrandom.h"

//Criei essa função para encontrar o pseudoaleatório repetitível que virá depois de gerar os 4 números inciais 
unsigned long acha_sortudo(){
	unsigned long xi;	
	for (long int i=0; i<5; i++){ //"Aleatorizo" até 5
		xi=lcrandom(); //Gero um número pseudoaleatório
	}
	return(xi); //Retorno sortudo 
}

//Criei essa função para contar o valor do período
unsigned long cont_periodo (unsigned long sortudo){
	unsigned long xi=0, cont=4; //Inicializo xi em zero por que é garantido que meu sortudo não será zero visto q a seed ja é zero, e inicializo o cont em 4 pois ele gera 4 números antes de gerar a sequência que repete
	
	while ((xi=lcrandom()) != sortudo) {  //Confiro se meu pseudoaleatório atual é igual ao sortudo, quando for eu cheguei no final do período 
		cont++; //Vou contando pra definir o período
	}  
	cont--; 
	return(cont);
}

int main () {
	//Inicializo os parâmetros e limites da minha criação de numeros pseudoaleatŕios
	lcrandom_parms (40692,127,10000000);	
	unsigned long periodo, sortudo;

	sortudo=acha_sortudo(); //Pego meu pseudoaleatório "posicionado" após os 4 primeiros da minha sequência, apelidado como sortudo
	periodo=cont_periodo(sortudo); //Faço a contagem do meu período a partir de sortudo
	printf("%ld\n", periodo);
	
	return(0);
}	
	
		
				
				
