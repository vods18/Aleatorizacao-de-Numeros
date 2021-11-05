//Vinícius Oliveira dos Santos    GRR20182592
//IMPLEMENTAÇÃO DO HISTOGRAMA DO GERADOR COM OS VALORES DEFAULT DE A, C E M

#include <stdio.h>
#include "lcrandom.h"
#define MAXVET 100

//A função Acha_maior serve pra achar o maior número de repetições de um pseudoaleatório para que eu possa usar na R3 como contmax
unsigned long Acha_maior(unsigned long v[]){
	unsigned long maior=v[0];
	for (long int i=1; i<MAXVET; i++)
		if (v[i]>maior)
			maior=v[i];
	return(maior);
}

/*
Criei uma função genérica para que normalize meus valores calculando a regra de três, na seguinte lógica: 

contmax    100

v[x]      v[x] (normalizado) 

*/
void R3 (unsigned long v[], unsigned long contmax){
	for (long int i=0; i<MAXVET; i++){	
		v[i]=((v[i]*MAXVET)/contmax)/2; //divido por 2 também para que se adeque a quantidade de asteriscos
	}
}

//A função histograma é responsável pela impressão adequada do meu gráfico
void histograma (unsigned long v[]){
	for (long int i=0; i<MAXVET; i++){  //Controla a variação vertical do gráfico
		if (i/10<1)
			printf(" %ld|", i);
		else 
			printf("%ld|", i);
		for (long int j=0; j<v[i]; j++){ //Controla a variação horizontal do gráfico
			printf("*"); 
		}
		
		printf("\n");
	}
}

void limpa_vetor (unsigned long v[]){
	for (long int i=0; i<MAXVET; i++)
		v[i]=0;   //zero todas as posições do meu vetor de contagem
}

//A função gerador será responsável por usar a congruência linear para gerar os números pseudoaleatórios e contar suas repetições
void gerador (unsigned long v[], unsigned long M, unsigned long s) {
	int xi;
	for (long int i=s; i<M; i++){
		xi=(lcrandom()%MAXVET); //Gero um número pseudoaleatório
		v[xi]++; //Loco quantas vezes cada valor repetiu no intervalo de [0..99]
	}
}	

//No main mantenho a chamada de todas as funções com suas respectivas necessidades para sua funcionalidade 
int main () {
	//Inicializo os parâmetros e limites da minha criação de números pseudoaleatórios
	lcrandom_parms (40692,127,10000000);	
	unsigned long v[MAXVET], contmax, s=0;
	lcrandom_seed(s);
	
	printf("   0   10   20   30   40   50   60   70   80   90   100\n");
	printf("   +----+----+----+----+----+----+----+----+----+----+\n");
	
	limpa_vetor(v); //Preciso que esteja locado zeros em meus vetor para que não venha lixo de memória	
	gerador(v,1000000,s); //Gero meus números pseudoaleatórios
	contmax=Acha_maior(v); //contmax recebe o maior numero de repetições de um pseudoaleatório 
	R3(v,contmax); //Normalizo fazendo a regra de 3
	histograma(v); //Imprimo o histograma
	
	printf("   +----+----+----+----+----+----+----+----+----+----+\n");
	
	return(0);
}
