#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort/bubbleSort.h"
#include "sort/mergeSort.h"
#include "sort/quickSort.h"
#define TAM 10000

//compilar o arquivo: "gcc nomeArq.c -c"
//compilar todos os arquivos: "gcc *.c -c"

//gerar o executável do programa: "gcc nomeArq.c pasta/arquivo(s -> *).c -o nomeArqExecutavel"

int numeroAleatorio(int menor, int maior){
	int k;
	
	//srand((unsigned)time(NULL));
	k = (rand() % maior) + menor;
	
	return k;
}


void imprimirVetor(int *vet){
	int i;
	
	for(i = 0; i < TAM; i++){
		printf("[%d] - ", vet[i]);
	}
}

int menu(){
	int opc;
	
	do{
		printf("\n=*= MENU =*=\n\n");
		printf("| [1]. Tempo de execução do BubbleSort.\n");
		printf("| [2]. Tempo de execução do MergeSort.\n");
		printf("| [3]. Tempo de execução do QuickSort.\n");
		printf("| [0]. Sair. \n\n");
		printf("Sua opção: ");
		scanf("%d", &opc);
		
		if((opc < 0) || (opc > 3)){
			printf("\nOpção inválida!\n");
		}
	}while(opc < 0 || opc > 3);
	
	return (opc);
}

int main(){
	clock_t t;
	int i, opc, vet[TAM], vetAux[TAM], vetAuxB[TAM];
	
	for(i = 0; i < TAM; i++){ //inserir os valores aleatórios no vetor
		vet[i] = numeroAleatorio(0, TAM);
		vetAux[i] = vet[i];
	}
	
	//imprimirVetor(vet);
	
	do{
		opc = menu();
		
		switch(opc){
			case 1:
				printf("\n=== BUBBLESORT ===\n");
				t = clock(); //armazena o tempo inicial
				bubbleSort(vet, TAM);
				t = clock() - t; //tempo final (clock()) - tempo inicial (t)
				printf("Tempo de execução: %lf", ((double)t)/((CLOCKS_PER_SEC)));
				printf("\n");
				//imprimirVetor(vet);
			break;
			
			case 2:
				printf("\n=== MERGESORT ===\n");
				for(i = 0; i < TAM; i++){ //copiar os valores do vetAux para o vet
					vet[i] = vetAux[i];
				}
				t = clock(); //armazena o tempo inicial
				mergeSort(vet, vetAuxB, 0, TAM-1);
				t = clock() - t; //tempo final (clock()) - tempo inicial (t)
				printf("Tempo de execução: %lf", ((double)t)/((CLOCKS_PER_SEC)));
				printf("\n");
			break;
			
			case 3:
				printf("\n=== QUICKSORT ===\n");
				for(i = 0; i < TAM; i++){ //copiar os valores do vetAux para o vet
					vet[i] = vetAux[i];
				}
				t = clock(); //armazena o tempo inicial
				quicksort(vet, 0, TAM-1);
				t = clock() - t; //tempo final (clock()) - tempo inicial (t)
				printf("Tempo de execução: %lf", ((double)t)/((CLOCKS_PER_SEC)));
				printf("\n");
			break;
			
			case 0:
				printf("\nSAINDO...");
			break;
			
			default:
				printf("\nOpção inválida!\n");
		}
	}while(opc != 0);
	
	return 0;
}

