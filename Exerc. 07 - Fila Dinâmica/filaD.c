#include <stdio.h>
#include <stdlib.h>
#define TRUE 1 	//"defines" usados para:
#define FALSE 0	// testar se fila estará vazia (1) ou não estará vazia (0)

struct TElemento{
	int dado; //conteúdo(inteiro)
	struct TElemento *prox; //ponteiro para o próximo registro
};
typedef struct TElemento *ApElemento; 

typedef struct{
	ApElemento inicio; //ponteiro para o início da fika
	ApElemento fim; //ponteiro  para o fim da fila
} Fila;

//função que cria uma fila
Fila criarFila(){
	Fila f;
	f.inicio = NULL; //não haverá elemento(s) no inicio
	f.fim = NULL;	 // e no final quando a fila for criada
	return (f); //retorna a fila criada
}

//função usada para testar se a fila está vazia
int isVazia(Fila f){
	if(f.inicio == NULL){
		return (TRUE);
	}else{
		return (FALSE);
	}
}

//função que exibe o conteúdo de uma fila
// imprime todos os nodos da fila p
void imprimeFila(Fila f){
	ApElemento ap;
	
	printf("\n---- Itens da lista ----\n");
	ap = f.inicio; //variável "ap" apontando para o início da fila
	while(ap != NULL){ //percorrendo a fila enquanto for diferente de "NULL"
		printf("%d - ", ap->dado);
		ap = ap->prox;
	}
	printf("\n");
}

//função que insere um elemento na fila (no final dela)
Fila inserirElemento(Fila f, int e){
	ApElemento novo; //ponteiro para o novo elemento
	
	novo = malloc(sizeof(struct TElemento)); //alocando espaço para o novo elemento
	
	//atribuição de valores
	novo -> dado = e;
	novo -> prox = NULL; //não haverá elemento após a inserção do novo elemento
	if(isVazia(f)){ //caso a fila esteja vazia
		f.inicio = novo; //o início
		f.fim = novo;	 // e o fim serão os mesmos valores
	}else{ //caso a fila não esteja vazia
		f.fim -> prox = novo;
		f.fim = novo; //o fim (sempre) será o novo elemento inserido
	}
	return (f); //retornando a fila f
}

//função que retira um elemento da lista
// tem duas formas de fazer
// 1ª:
Fila retirarElemento(Fila f, int *e){
	ApElemento ap;
	
	if(!isVazia(f)){ //caso a fila não esteja vazia
		*e = f.inicio -> dado; //retorna o valor do elemento que está no início da fila
		ap = f.inicio; //salva o endereço do início para liberação
		f.inicio = f.inicio -> prox; //aponta para o segundo elemento
		free(ap); //libera o espaço ocupado pelo elemento removido
		
		if(isVazia(f)){ //atualiza o fim caso tenha retirado um único elemento
			f.fim = NULL;
		}
	}else{ //caso a fila esteja vazia
		*e = -1;
		printf("\n----------------------------\n");
		printf("|------- FILA VAZIA -------|");
		printf("\n----------------------------\n");
	}
	return (f); //retorna a fila f
}

//2ª forma de fazer:
/*
int retiraFila (Fila *f)
{
	ApElemento ap;
	int ret;
	
	if (!filaVazia(*f))
	{
		ret = f->ini->dado; // Copia o valor do elemento que está no inicio da fila
		ap = f->ini; // Salva o endereço do inicio para liberação
		f->ini = f->ini->prox; // Faz o inicio apontar para o segundo elemento
		free(ap); // Libera o espaço ocupado pelo elemento removido
		if(filaVazia(*f)){ // Se retirou o único elemento, atualiza f->fim
			f->fim = NULL;
		}
	}else{
		ret = -1;
		printf("\nFila Vazia");
	}
	return (ret);
}
*/

//função principal
int main()
{
	Fila f;
	f = criarFila();
	int opc, num;
	
	do{
		printf("\n====! MENU !====\n\n");
		printf("[1]. | Inserir elemento no final.\n");
		printf("[2]. | Retirar elemento do início da fila.\n");
		printf("[3]. | Imprimir conteúdo da fila.\n");
		printf("[0]. | Sair\n");
		
		printf("\nOpção desejada: ");
		scanf("%d", &opc);
		if(opc < 0 || opc > 3){
			printf("\nOPÇÂO INVÁLIDA!\n");
		}
		
		switch(opc){
			case 1:
				printf("\n=*= INSERIR ELEMENTO NO FINAL DA FILA =*=\n");
				printf("\nNº que deseja inserir: ");
				scanf("%d", &num);
				f = inserirElemento(f, num);
				break;
				
			case 2:
				printf("\n=*= RETIRAR ELEMENTO DO COMEÇO DA LISTA =*=\n");
				f = retirarElemento(f, &num);
				break;
				
			case 3:
				printf("\n=*= IMPRIMINDO ITENS DA FILA =*=\n");
				imprimeFila(f);
				printf("\n");
				break;
				
			case 0:
				printf("\nSAINDO...\n");
				break;
			
			default:
				printf("\nOPÇÃO INVÁLIDA!\n");
		}
	}while(opc != 0);
	
	return 0;
}

