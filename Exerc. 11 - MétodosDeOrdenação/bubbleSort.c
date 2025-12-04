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

void inserir(int *vet){
	int i;
	
	printf("\n=*= INSERIR VALOR(ES) =*=\n\n");
	for(i = 0; i < TAM; i++){
		printf("| Nº [%d]: ", i);
		scanf("%d", &vet[i]);
	}
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
		printf("| [1]. Imprimir vetor.\n");
		printf("| [2]. Ordenar vetor via BubbleSort.\n");
		printf("| [0]. Sair.\n\n");
		printf("Sua opção: ");
		scanf("%d", &opc);
		
		if((opc < 0) || (opc > 2)){
			printf("\nOpção inválida!\n");
		}
	}while(opc < 0 || opc > 2);

	return (opc);
}

int main(){
	clock_t t; //variável para armazenar tempo
	int i, opc, vet[TAM];
	
	printf("\n=*= INSERIR VALORES =*=\n\n");
	for(i = 0; i < TAM; i++){
		printf("| Nº [%d]: ", i);
		scanf("%d", &vet[i]);
	}
	
	do{
		opc = menu();
		
		switch(opc){	
			case 1:
				imprimirVetor(vet);
			break;
			
			case 2:
				printf("\n=*= BUBBLESORT =*=\n");
				t = clock(); //armazena tempo
				bubbleSort(vet, TAM);
				t = clock() - t; //tempo final (clock()) - tempo inicial (t)
				printf("\nVetor ordenado!\n");
				printf("Tempo de execução: %lf", ((double)t)/((CLOCKS_PER_SEC/1000))); //convertendo para double e mostrando na tela
				
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

