#include <stdio.h>
#include <stdlib.h>

#define MAXITENS 10

/* Será usado alocação dinâmica de memória. 
 * tratar cada definição de estrutra
 * como um nodo(célula ou elemento)*/

struct TElemento{
	int dado; //conteúdo (inteiro)
	struct TElemento *prox;	//ponteiro para o próximo registro 
};

//tratar os nodos como novos tipos de dados
// atribuir um novo nome a esse tipo
typedef struct TElemento Nodo;

//declarando um Nodo n 
// e um ponteiro p para o Nodo
Nodo n;
Nodo *p;

//definindo uma Lista com ponteiro para nodo
typedef Nodo *Lista;

//função que cria a lista
Lista criaLista(){
	return NULL;
}

/*	
 * 	Lista lista1;
	lista1 = criaLista();*/
	
//função que insere um novo elemento na lista
// OBS: essa função sempre coloca o novo elemento
// 		no começo da lista por ser uma lista encadeada
Lista inserirNaLista(Lista l, int e){
	Lista p, ant, novo;
	
	//alocando um espaço na memória e atribuindo valores
	novo = malloc(sizeof(struct TElemento));
	novo -> dado = e;
	
	//procura o ponto de inserção na lista
	p = l;
	ant = p;
	
	while((p != NULL) && (p->dado < e)){
		ant = p;
		p = p -> prox;
	}
	if(p != ant){ //não insere antes do 1°, insere entre os ponteiros ant e p
		ant -> prox = novo;
	}else{ //lista vazia ou inserindo antes do 1º elemento
		l = novo;
	}
	novo -> prox = p;
	
	return l; //retorna o endereçamento da lista 
}

//função que retira o elemento da lista.
// retira o elemento se existir.
// retorna o endereço para o início da lista.
Lista retirarDaLista(Lista l, int e){
	Lista p,	//ponteiro p para o elemento atual
		  ant;	//ponteiro ant para o elemento anterior
		  
	p = l;
	ant = l;
	
	//procurando elemento até o fim da lista ou até o encontrar
	while((p != NULL) && (p->dado != e)){//procura o elemento e
		ant = p;
		p = p->prox;
	}
	if(p != NULL){//encontrou o elemento e, remove-o
		if(p == ant){ //removendo o primeiro elemento
			l = p->prox;
			free(p);
		}else{ //não é o primeiro elemento da lista
			ant->prox = p->prox;
			free(p);
		}
	}
	return (l);
}

//função que busca um elemento
// procura o elemento na lista, retornando o endereço
// do elemento se estiver na lista
// retorna NULL em caso contrário
Lista buscaLista(Lista l, int e){
	Lista p; //ponteiro para percorrer a lista
	
	p = l; //início da lista
	
	//percorrer a lista enquanto não chegar no final
	// e não encontrar o elemento
	while((p != NULL) && (p->dado != e)){
		p = p->prox;
	}
	return (p); //retorna o endereçamento do nodo encontrado
				// ou NULL caso chegue ao final sem encontrar
				// o elemento da lista
}

//função que conta o Nº de elementos
int contaLista(Lista l){
	Lista p; //percorre a lista
	int cont = 0; //iniciar contador em 0
	p = l; //apontando para o início da lista
	
	while(p != NULL){ //enquanto a lista não acabou
		cont++; //incrementando o cont
		p = p->prox; //passa para o próximo elemento
	}
	return cont; //retorna o contador
}

//função que exibe o conteúdo da lista
// imprime todos os nodos da lista 1
void imprimeLista(Lista l){
	Lista p; //ponteiro auxiliar: percorre a lista
	
	printf("\n-- ITENS DA LISTA --\n");
	p = l; //apontando para o início da lista
	while(p != NULL){ //enquanto não chega ao fim da lista
		printf("%d - ", p->dado); //imprime o elemento
		p = p->prox; //ponteiro avança para o próximo Nodo
	}
	printf("\n");
}

int main()
{
	Lista lista1;
	lista1 = criaLista();
	int opc, num, retirar, conta;
	
	do{
		printf("\n--- MENU ---\n");
		printf("\n[1]. Inserir elemento\n");
		printf("[2]. Retirar elemento\n");
		printf("[3]. Buscar elemento\n");
		printf("[4]. Imprimir conteúdo\n");
		printf("[5]. Contar o Nº de elemento\n");
		printf("[0]. Sair\n");
		
		printf("\nOpção desejada: ");
		scanf("%d", &opc);
		if(opc <= 0 && opc > 5){
			printf("\nOpção inválida!\n");
		}
		
		switch(opc){
			case 1:
				printf("\n---- INSERINDO ----\n");
				printf("\nNº que deseja inserir na lista: ");
				scanf("%d", &num);
				lista1 = inserirNaLista(lista1, num);
				printf("\n");
				break;
			case 2:
				printf("\n---- REMOVENDO ----\n");
				printf("\nNº que deseja retirar da lista: ");
				scanf("%d", &retirar);
				lista1 = retirarDaLista(lista1, retirar);
				printf("\n");
				break;
			case 3:
				printf("\n---- BUSCANDO ----\n");
				printf("\nNº que deseja buscar na lista: ");
				scanf("%d", &num);
				p = buscaLista(lista1, num);
				if(p != NULL){
					printf("Número: %d\n", p->dado);	
				}else{
					printf("\nNº não encontrado!\n");
				}
				printf("\n");
				break;
			case 4:
				printf("\n ---- IMPRIMINDO CONTEÚDO ----\n\n");
				imprimeLista(lista1);
				break;
			case 5:
				printf("\n---- CONTANDO ITENS DA LISTA ----\n\n");
				conta = contaLista(lista1);
				printf("Quantidade de itens na lista: %d", conta);
				printf("\n");
				break;
			case 0:
				printf("SAINDO...");
				break;
			default:
				printf("OPÇÃO INVÁLIDA!");
		}
	}while(opc != 0);
	
	return 0;
}
