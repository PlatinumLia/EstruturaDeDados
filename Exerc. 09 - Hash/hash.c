#include <stdio.h>
#include <stdlib.h>
#define TAM_HASH 10 //quantidade de listas que serão usadas
				   // neste exemplo

/* OBS: usarei uma lista com alocação dinâmica ordenada no Hash. 
 * 		Pode ser usada qualquer forma de lista 
 * 
 * OBS 2: Precisei copiar o arquivo da lista ordenada para dentro da pasta 
 * 		  para  conseguir usar as funções dela */

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
	
//função que insere um novo elemento na lista
// OBS: essa função sempre coloca o novo elemento
// 		no começo da lista por ser uma lista encadeada
Lista insereLista(Lista l, int e){
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
Lista retiraLista(Lista l, int e){
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

int hash(int chave){ //função hash
					// obtém o índice do vetor
	return (chave % TAM_HASH);
}

//função que cria um hash vazio
void criaHash(Lista *h){
	int i;
	
	for(i = 0; i < TAM_HASH; i++){ //criando uma lista
								  // para cada posição do hash
		h[i] = criaLista();
	}
}

//função que insere o elemento no hash
void insereHash(Lista *h, int valor){
	int i;
	i = hash(valor);
	
	h[i] = insereLista(h[i], valor);
}

//função que busca um elemento no hash
Lista buscaHash(Lista *h, int valor){
	int i;
	i = hash(valor);
	
	return(buscaLista(h[i], valor));
} 

//função que retira um elemento do hash
void retiraHash(Lista *h, int valor){
	int i;
	i = hash(valor);
	
	h[i] = retiraLista(h[i], valor);
}

//função que imprime um elemento do hash
void imprimeHash(Lista *h){
	int i;
	
	printf("\n---- Imprimindo as listas do Hash h ----\n");
	for(i = 0; i < TAM_HASH; i++){
		printf("\nh[%d]: ", i);
		imprimeLista(h[i]);
	}
	printf("\n");
} 

//função para mostrar um menu
int menu(){
	int opc;
	
	do{
		printf("\n===== HASH =====\n\n");
		printf("[1]. Inserir elemento.\n");
		printf("[2]. Retirar elemento.\n");
		printf("[3]. Buscar elemento.\n");
		printf("[4]. Imprimir Hash.\n");
		printf("[0]. Sair.\n");
		
		printf("\nEscolha uma opção: ");
		scanf("%d", &opc);
		if((opc < 0) || (opc > 4)){
			printf("\nOPÇÃO INVÁLIDA!!\n");
		}
	}while((opc < 0) || (opc > 4));
	
	return (opc);
}

int main(){
	Lista h[TAM_HASH];
	criaHash(h);
	int opc, insereValor, retiraValor, buscaValor;
		
	do{
		opc = menu();
		switch(opc){
			case 1:
				printf("\n=*= INSERIR ELEMENTO =*=\n\n");
				printf("Nº que deseja inserir: ");
				scanf("%d", &insereValor);
				insereHash(h, insereValor);
				printf("\n");
				break;	
			
			case 2:
				printf("\n=*= RETIRAR ELEMENTO =*=\n\n");
				printf("Nº que deseja retirar: ");
				scanf("%d", &retiraValor);
				retiraHash(h, retiraValor);
				printf("\n");
				break;
				
			case 3:
				printf("\n=*= BUSCAR ELEMENTO =*=\n\n");
				printf("Nº que deseja buscar: ");
				scanf("%d", &buscaValor);
				buscaHash(h, buscaValor);
				if(h[TAM_HASH] != NULL){
					printf("\nElemento existe no Hash!\n");
				}else{
					printf("\nElemento não existe no Hash!\n");
				}
				printf("\n");
				break;
			
			case 4:
				printf("\n=*= IMPRIMINDO HASH =*=\n");
				imprimeHash(h);
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
