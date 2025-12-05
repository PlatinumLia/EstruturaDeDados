#include <stdio.h>
#include <stdlib.h>
#include <time.h> //clock(), CLOCKS_PER_SEC e clock_t
#define TAM 10

void bubbleSort(int *vet, int n){
	int i, j, trocou, aux;
	j = 1;
	trocou = 1; //sinalizador.
			   // se houve trocas é porque há algo fora de ordem e precisa continuar
	
	while((j < n) && trocou){ //continua enquanto houve trocas e não esgotou o vetor
		trocou = 0; //não houve trocas na passada pelo vetor
		
		for(i = 0; i < (n-j); i++){
			if(vet[i] > vet[i+1]){ //se for maior que o próximo elemento, troca
				aux = vet[i];
				vet[i] = vet[i+1];
				vet[i+1] = aux;
				trocou = 1; //sinalizando que houve troca
			}
		}
		j++;
	}
}

