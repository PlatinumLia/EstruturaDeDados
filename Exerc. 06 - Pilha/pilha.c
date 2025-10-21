#include <stdio.h>
#include <stdlib.h>

//não há valores booleanos em C
// esses defines servirão como "bool"
#define TRUE 1
#define  FALSE 0


//estrutura que armazena os itens da pilha
struct Telemento{
	int dado; //contéudo (inteiro)
	struct Telemento *prox; //ponteiro para o próx. elemento
};
typedef struct Telemento *Pilha;

//função que cria a pilha
Pilha criaPilha(){
	return NULL; //aponta para NULL caso não haja elementos gravados
}

//função que testa se a pilha está vazia
int pilhaVazia(Pilha p){
	if(p == NULL){
		return (TRUE);
	}else{
		return (FALSE);
	}
}

//função que empilha um elemento
// (insere o elemento dentro da estrutura da pilha)
Pilha empilhar(Pilha p, int e){
	Pilha novo;
	
	novo = malloc(sizeof(struct Telemento)); //alocando espaço
	novo -> dado = e; //atribui os dados ao novo elemento
	novo -> prox = p; //o próximo elemento inserido do novo é o topo do elemento anterior
	return (novo); //o novo elemento passa a ser o topo da pilha
}

//função que desempilha um item da pilha
// (desempilha apenas o elemento do topo)
Pilha desempilhar(Pilha p, int *e){
	Pilha ap; //ponteiro auxiliar
	
	if(!pilhaVazia(p)){ //caso a pilha não esteja vazia
		*e = p->dado; //retorna o valor do elemento que está no topo da pilha
		ap = p; //salva o endereço do topo para a liberação
		p = p->prox; //faz o topo apontar para o próximo elemento
		free(ap); //libera o espaço ocupado pelo elemento removido
	}else{	// caso a pilha esteja vazia
		//retorna valor -1
		*e = -1;
		printf("\nA PILHA ESTÁ VAZIA!\n");
	}
	return (p);
}

//função que imprime os dados contidos na pilha
// imprime todos os nodos da pilha p
void imprimePilha(Pilha p){
	Pilha ap;
	
	printf("\nItens da Pilha:\n");
	ap = p;
	while(ap != NULL){
		printf("|%d\n", ap->dado);
		ap = ap->prox;
	}
	printf("\n");
}

//função principal com menu
int main()
{
	Pilha p; //declaração da variável p
	p = criaPilha(); //inicializando a pilha com a variável p (pilha vazia)
	int opc, inserir;
	
	do{
		printf("\n====! MENU !====\n\n");
		printf("[1]. Empilhar elemento.\n");
		printf("[2]. Desempilhar elemento.\n");
		printf("[3]. Imprimir conteúdo da pilha.\n");
		printf("[0]. Sair\n");
		
		printf("\nOpção desejada: ");
		scanf("%d", &opc);
		if(opc < 0 || opc > 3){
			printf("\nOPÇÂO INVÁLIDA!\n");
		}
		
		switch(opc){
			case 1:
				printf("\n=*= EMPILHANDO =*=\n\n");
				printf("Nº que deseja inserir: ");
				scanf("%d", &inserir);
				p = empilhar(p, inserir);
				printf("\n");
				break;
			case 2:
				printf("\n=*= DESEMPILHANDO =*=\n");
				p = desempilhar(p, &inserir); //passando o endereço 
											 // do último elemento inserido
											//  com a variável "inserir" usando o "&"
				printf("\n");
				break;
			case 3:
				printf("\n=*= IMPRIMINDO CONTEÚDO DA PILHA =*=\n");
				imprimePilha(p);
				printf("\n");
				break;
			case 0:
				printf("\nSAINDO...\n");
				break;
			default:
				printf("\nOPÇÂO INVÁLIDA!\n");
		}
	}while(opc != 0);
	
	return 0;
}

