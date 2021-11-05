//IMPLEMENTAÇÃO DO HISTOGRAMA DO GERADOR 

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
	printf("   0   10   20   30   40   50   60   70   80   90   100\n");
	printf("   +----+----+----+----+----+----+----+----+----+----+\n");
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
	printf("   +----+----+----+----+----+----+----+----+----+----+\n");
}

void limpa_vetor (unsigned long v[]){
	for (long int i=0; i<MAXVET; i++)
		v[i]=0;   //zero todas as posições do meu vetor de contagem
}

//A função gerador será responsável por usar a congruência linear para gerar os números pseudoaleatórios e contar suas repetições
void gerador (unsigned long v[], unsigned long M) {
	int xi;
	xi = lcrandom_seed();
	for (long int i=xi; i<M; i++){
		xi=(lcrandom(xi)%MAXVET); //Gero um número pseudoaleatório
		v[xi]++; //Aloco quantas vezes cada valor repetiu no intervalo de [0..99]
	}
}	

//No main mantenho a chamada de todas as funções com suas respectivas necessidades para sua funcionalidade 
int main () {
	//Inicializo os parâmetros e limites da minha criação de números pseudoaleatórios
	unsigned long a=0,c=0,m=0;
	printf("Entre com parametro A C M nessa ordem\n");
	scanf("%ld %ld %ld", &a, &c, &m);
	lcrandom_parms (a,c, m);
	
	unsigned long v[MAXVET], contmax;
	
	limpa_vetor(v); //Preciso que esteja locado zeros em meus vetor para que não venha lixo de memória	
	gerador(v,1000000); //Gero meus números pseudoaleatórios
	contmax=Acha_maior(v); //contmax recebe o maior numero de repetições de um pseudoaleatório 
	R3(v,contmax); //Normalizo fazendo a regra de 3
	histograma(v); //Imprimo o histograma
	
	return(0);
}
