#include <stdio.h>
#include <ctype.h>
#define TAM 5

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

void inserir(int *vet){
	int i;
	
	for(i = 0; i < TAM; i++){
		printf("Elemento [%d] do vetor: ", i);
		scanf("%d", &vet[i]);
	}
}

int main(){
	int vetor[TAM], vetorAux[TAM], i;
	char opc;
	
	do{
		printf("\n=*= MERGESORT =*=\n\n");
		printf("Inserir vetor:\n");
		inserir(vetor);
		
		printf("\nDeseja ordenar o vetor por MergeSort? [S/N]\n");
		scanf(" %c", &opc);
		opc = toupper(opc);
		
		if(opc == 'S'){
			printf("\n=*= ELEMENTOS NO VETOR (PRÉ-ORDENAÇÃO) =*=\n");
			for(i=0; i < TAM; i++){
				printf("[%d] ", vetor[i]);
			}
			printf("\n");
			
			mergeSort(vetor, vetorAux, 0, TAM-1);
			
			printf("\n=*= ELEMENTOS NO VETOR (PÓS-ORDENAÇÃO) =*=\n");
			for(i=0; i < TAM; i++){
				printf("[%d] ", vetor[i]);
			}
			printf("\n");
			printf("\nDeseja adicionar e ordenar um novo vetor? [S/N]\n");
			scanf(" %c", &opc);
			opc = toupper(opc);
				
			if((opc != 'S') && (opc != 'N')){
				printf("\nOpção inválida!\n\n");
			}else if((opc == 'N')){
				printf("\nSAINDO...");
			}	
		}else{
			printf("\nSAINDO...");
		}
	}while(opc != 'N');
	
	return 0;
}

