#include <stdio.h>
#include <time.h>
#define TAM 10
#define troca(A, B) { int t = A; A = B; B = t; }


//recebe vetor a[p..r] com p<r.
// Rearranja os elementos do vetor e devolve i em p..r tal que 
// a[p..i-1] <= a[i] <= a[i+1..r]
// OBS: "p..r, p..i+1, etc." -> lê-se "p até r, p até i+1"
int particione(int a[], int p, int r){
	int i = p-1, j = r;
	int v = a[r];
	
	for(;;){
		while(a[++i] < v);
		while(v < a[--j]){
			if(/* X */ j == p){
				break;
			}
		}
		if(i >= j){
			break;
		}
		troca(a[i], a[j]);
	}
	troca(a[i], a[r]);
	
	return i;
}

//a função rearranja o vetor a[p..r], com p <= r+1,
// de modo que ele fique em ordem crescente
void quicksort(int a[], int p, int r){
	int i;
	
	if(p < r){
		i = particione(a, p, r);
		quicksort(a, p, i-1);
		quicksort(a, i+1, r);
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
		printf("| [2]. Ordenar vetor via QuickSort.\n");
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
				printf("\n=*= QUICKSORT =*=\n");
				t = clock(); //armazena o tempo inicial
				quicksort(vet, 0, TAM-1);
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

