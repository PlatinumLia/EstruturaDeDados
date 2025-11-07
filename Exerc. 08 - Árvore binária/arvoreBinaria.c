#include <stdio.h>
#include <stdlib.h>

struct TElemento{
	int dado;
	struct TElemento *esq;
	struct TElemento *dir;
};

typedef struct TElemento *Arvore;

//função que cria a árvore binária
Arvore criaArvore(){
	return NULL;
}

//função que insere um elemento na árvore
// será usado recursividade nessa função e nas demais
void insereArvore(Arvore *a, int valor){
	if((*a) == NULL){ //se a árvore for vazia
		//aloca o espaço para novo registro
		(*a) = (Arvore)malloc(sizeof(struct TElemento));
		
		//preenche os valores:
		(*a)->dado = valor;
		(*a)->esq = NULL;
		(*a)->dir = NULL;
	}else if(valor < (*a)->dado){
		//insere na subárvore da esquerda 
		// se o elemento for menor que a raiz
		insereArvore(&((*a)->esq), valor); //aplicando a recursividade
	}else if(valor > (*a)->dado){
		//insere na subárvore da direita 
		// se o elemento for maior que a raiz
		insereArvore(&((*a) -> dir), valor); //aplicando a recursividade
	}else{
		//se o elemento for o mesmo que a raiz
		// não deixa inserir
		printf("\nValor já existente na árvore! Tente inserir outro...\n");
	}
}

//função que busca um elemento da árvore
Arvore buscaArvore(Arvore a, int valor){
	if(a == NULL){ //árvore vazia, não encontrou um elemento
		return NULL; //retorna NULL
	}else if(valor < a->dado){ //se menor que a raiz, busca à esquerda
		return buscaArvore(a->esq, valor); //aplicando recursividade
	}else if(valor > a->dado){ //se maior que a raiz, busca à direita
		return buscaArvore(a->dir, valor); //recursividade
	}else{ //nem maior, nem menor
		return a; //retorna o endereço do elemento
	}
}

//função que exibe os elementos em pré-ordem
void preOrdem(Arvore a){
	if(a != NULL){
		printf("\n%d", a->dado);
		preOrdem(a->esq);
		preOrdem(a->dir);
	}
}

//funções para mostrar os elementos em ordem crescente e decrescente
void inOrdemAsc(Arvore a){ //ordem ascendente
	if(a != NULL){
		inOrdemAsc(a->esq);
		printf("\n%d", a->dado);
		inOrdemAsc(a->dir);
	}
}

/* não será usada essa função no exercício proposto
void inOrdemDesc(Arvore a){ //ordem descendente
	if(a != NULL){
		inOrdemDesc(a->dir);
		printf("\n%d", a->dado);
		inOrdemDesc(a->esq);
	}
}
*/

//função que exibe os elementos em pós-ordem
void posOrdem(Arvore a){
	if(a != NULL){
		posOrdem(a->esq);
		posOrdem(a->dir);
		printf("\n%d", a->dado);
	}
}

//função para buscar o elemento antecessor
// (criada depois do retiraArvore())
//Recebe por parâmetro o endereço do elemento a ser retirado, e endereço
// do ponteiro para um candidato a substituir o elemento a ser retirado da árvore. 
// Essa função deve buscar o maior elemento nessa subárvore (o elemento mais à direita), 
// pois é o mais próximo numericamente ao elemento que será retirado.
void antecessor(Arvore a, Arvore *x){
	//coloca no elemento "a" o maior elemento da subárvore "*x"
	// "a" é o endereço do elemento a ser retirado
	// "x" é o endereço do ponteiro para o candidato substituto de "a"
	Arvore aux;
	
	if((*x)->dir != NULL){
		// "*x" tem "filho" da direita, logo não é o maior
		antecessor(a, &((*x)->dir));
	}else{
		// "*x" não tem "filho" da direita, logo é o substituto
		a->dado = (*x)->dado; //move o dado substituto para o retirado
		
		//promove o filho da esquerda do substituto ao lugar dele
		aux = *x; 
		*x = aux->esq;
		free(aux); //libera o espaço usado pelo substituto (já movido para "a")
	}
}


//função para mostrar um menu
int menu(){
	int opc;
	
	do{
		printf("\n===== ÁRVORE BINÁRIA =====\n\n");
		printf("[1]. Inserir elemento.\n");
		printf("[2]. Retirar elemento.\n");
		printf("[3]. Buscar elemento.\n");
		printf("[4]. Imprimir em pré-ordem.\n");
		printf("[5]. Imprimir em ordem crescente.\n");
		printf("[6]. Imprimir em pós-ordem.\n");
		printf("[0]. Sair.\n");
		
		printf("\nEscolha uma opção: ");
		scanf("%d", &opc);
		if((opc < 0) || (opc > 6)){
			printf("\nOPÇÃO INVÁLIDA!!\n");
		}
	}while((opc < 0) || (opc > 6));
	return (opc);
}

int main(){
	Arvore a;
	a = criaArvore();
	int opc, insereValor, retiraValor, buscaValor;
	
	do{
		opc = menu();
		switch(opc){
			case 1:
				printf("\n=*= INSERIR ELEMENTO =*=\n\n");
				printf("Nº que deseja inserir: ");
				scanf("%d", &insereValor);
				a = insereArvore(a, insereValor);
				printf("\n");
				break;

			case 2:
				printf("\n=*= RETIRAR ELEMENTO =*=\n\n");
				printf("Nº que deseja retirar: ");
				scanf("%d", &retiraValor);
				a = retiraArvore(a, retiraValor);
				printf("\n");
				break;
				
			case 3:
				printf("\n=*= BUSCAR ELEMENTO =*=\n\n");
				printf("Nº que deseja buscar: ");
				scanf("%d", &buscaValor);
				a = buscaArvore(a, buscaValor);
				if(a != NULL){
					printf("\nElemento existe!\n");
				}else{
					printf("\nElemento não existe\n");
				}
				printf("\n");
				break;
				
			case 4:
				printf("\n=*= PRÉ-ORDEM =*=\n\n");
				preOrdem(a);
				printf("\n");
				break;
				
			case 5:
				printf("\n=*= ORDEM CRESCENTE =*=\n\n");
				inOrdemAsc(a);
				printf("\n");
				break;
				
			case 6:
				printf("\n=*= PÓS-ORDEM =*=\n\n");
				posOrdem(a);
				printf("\n");
				break;
				
			case 0:
				printf("SAINDO...");
				break;
				
			default:
				printf("\nOPÇÃO INVÁLIDA\n");
		}
	}while(opc != 0);
	
	return 0;
}

