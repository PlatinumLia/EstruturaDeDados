#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 10
#define troca(A, B) { int t = A; A = B; B = t; }

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

// Intercala dois subvetores do vetor vet no vetor aux.
// O primeiro subvetor inicia na posição esq, e vai até meio
// O segundo subvetor inicia na posição meio+1 e vai até dir
void merge(int *vet, int *aux, int esq, int meio, int dir){
	int l1, l2, i;
	
	// Percorre os dois subvetores, comparando os elementos
	// Escolhe o menor elemento para mover para o vetor auxiliar
	// Até acabar um dos vetores
	for(l1=esq, l2=meio+1, i=esq; l1<=meio && l2<=dir; i++){
		if(vet[l1] <= vet[l2]){
			aux[i] = vet[l1++];
		}else{
			aux[i] = vet[l2++];
		}
	}
	
	// Quando encerrou o for, é porque um dos subvetores a ou b chegou ao fim
	while(l1 <= meio){ // Se houver dados restantes no primeiro subvetor, copia
		aux[i++] = vet[l1++];
	}
	
	while(l2 <= dir){ //Se houver dados restantes no segundo subvetor, copia
		aux[i++] = vet[l2++];
	}
	
	for(i=esq; i<=dir; i++){ // Move os dados do vetor auxiliar novamente para o vetor original vet.
		vet[i] = aux[i];
	}
}

void mergeSort(int *vet, int *aux, int esq, int dir){
	int meio;
	
	if(esq < dir){ // Só continua se o vetor tem pelo menos 2 elementos
		meio = (esq + dir) / 2; // Divide o vetor ao meio
		mergeSort(vet, aux, esq, meio); // Ordena por mergeSort a primeira metade
		mergeSort(vet, aux, meio+1, dir); // Ordena por mergeSort a segunda metade
		merge(vet, aux, esq, meio, dir); // Intercala os dois subvetores
	}
}

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

