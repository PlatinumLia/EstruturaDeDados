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

//usando o malloc
p = malloc(MAXITENS);

//função que cria a lista
Lista criaLista(){
		return NULL;
}

Lista lista1; //variável da lista 1
lista1 = criaLista(); //inicialização da lista 1 (lista vazia)

//função que insere um novo elemento na lista
// OBS: essa função sempre coloca o novo elemento
// 		no começo da lista por ser uma lista encadeada
Lista inserirNaLista(Lista l, int e){
	Lista novo;
	
	//alocando um espaço na memória
	// e faz a atribuição dde valores
	novo = malloc(sizeof(struct TElemento));
	novo -> dado = e;
	novo -> prox = l; //o próximo do novo é o início da lista
	return (novo); //retorna o endereçamento do novo elemento
}

//função que exibe o conteúdo da lista
// imprime todos os nodos da lista 1
void imprimeLista(Lista l){
	Lista p; //ponteiro auxiliar: percorre a lista
	
	printf("\n-- ITENS DA LISTA --\n");
	p = 1; //apontando para o início da lista
	while(p != NULL){ //enquanto não chega ao fim da lista
		printf("%d - ", p->dado); //imprime o elemento
		p = p->prox; //ponteiro avança para o próximo Nodo
	}
	printf("\n");
}

//função que conta o Nº de elementos
int contaLista(Lista l){
	Lista p; //percorre a lista
	int cont = 0; //iniciar contador em 0
	
	p = 1; //apontando para o início da lista
	while(p != NULL){ //enquanto a lista não acabou
		cont++; //incrementando o cont
		p = p->prox; //passa para o próximo elemento
	}
	return cont; //retorna o contador
}

//função que busca um elemento
// procura o elemento na lista, retornando o endereço
// do elemento se estiver na lista
// retorna NULL em caso contrário
Lista buscaLista(Lista l, int e){
	Lista p; //ponteiro para percorrer a lista
	
	p = 1; //início da lista
	
	//percorrer a lista enquanto não chegar no final
	// e não encontrar o elemento
	while((p != NULL) && (p->dado != e)){
		p = p->prox;
	}
	return (p); //retorna o endereçamento do nodo encontrado
				// ou NULL caso chegue ao final sem encontrar
				// o elemento da lista
}

//função que retira o elemento da lista.
// retira o elemento se existir.
// retorna o endereço para o início da lista.
Lista retirarDaLista(Lista l, int e){
	Lista p,	//ponteiro p para o elemento atual
		  ant;	//ponteiro ant para o elemento anterior
		  
	p = 1;
	ant = 1;
	
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

int main()
{
	Lista l;
	l = criaLista();
	int opc, inserir, retirar;
	
	do{
		printf("\n--- MENU ---\n");
		printf("\n[1]. Inserir elemento\n");
		printf("\n[2]. Retirar elemento\n");
		printf("\n[3]. Buscar elemento\n");
		printf("\n[4]. Imprimir conteúdo\n");
		printf("\n[5]. Contar o Nº de elemento\n");
		printf("\n[0]. Sair\n");
		
		printf("\nOpção desejada: ");
		scanf("%d", &opc);
		if(opc <= 0 && opc > 5){
			printf("\nOpção inválida!\n");
		}
	}while(opc <= 0 && opc > 5);
	
	switch(opc){
		case 1:
			printf("\nNº que deseja inserir na lista: ");
			scanf("%d", &inserir);
			inserirNaLista(l, inserir);
			break;
	}
	
	return 0;
}

