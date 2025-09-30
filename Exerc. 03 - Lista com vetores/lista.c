#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MaxItens 10
#define TamItens 20

typedef char tpLista[MaxItens][TamItens];

/* Função que cria a lista */
void criarLista(tpLista l){
	int i; //usado no loop for
	
	for(i=0; i<MaxItens; i++){
		l[i][0] = '\0';
	}
}

/* Função de contar os elementos da lista */
int contarLista(tpLista l){
	int i; //usado no loop for
	
	//laço que percorre a lista 
	// até encontrar um elemento vazio 
	for(i=0; i<MaxItens && strlen(l[i])>0; i++);
	//retorna a posição do elemento vazio  
	return (i);
}

/* Função para inserir elementos na lista */
void inserirNaLista(tpLista l, char *item){
	int i; //usado no loop for
	
	for(i=0; i<MaxItens && strlen(l[i])>0; i++);
	
	//verifica se há espaço na lista
	if(i<MaxItens){
		strcpy(l[i], item);
		printf("\nInserido com sucesso!\n");
	}else{
		printf("\nLista cheia!\n");
	}
}

/* Função para retirar da lista */
void retirarDaLista(tpLista l, char *item){
	int i; //usado no loop for
	
	//procura o elemento "item"
	for(i=0; i<MaxItens && strlen(l[i])>0 && (strcmp(l[i], item) != 0); i++){
		//sai do loop por 3 razões
		if(i<MaxItens && (strcmp(l[i], item) == 0)){ //elemento desejado encontrado
			printf("\nRemovendo o item %s...\n", item);
			
			if(i<(MaxItens - 1)){ //puxa todos os elementos depois do item removido para cima
				for(;i<(MaxItens - 1) && strlen(l[i])>0; i++){
					strcpy(l[i], l[i+1]);
				}
				//zera('\0') o último elemento do espaço da lista
				l[MaxItens - 1][0] = '\0';
			}
		}else{
			printf("\nItem %s não encontrado!\n\n", item);
		}
	}
}

/* Função que imprime a lista */
void exibirLista(tpLista l){
	int i; //usado no loop for
	
	for(i=0; i<MaxItens && strlen(l[i])>0; i++){
		printf("| %s |\n", l[i]);
	}
	printf("\n");
}

/* Função principal e menu*/
int main()
{
	tpLista l1;	
	int opc, qtdItens;
	char item[20];
	
	criarLista(l1);
	do{
		printf("\n--- MENU ---\n\n");
		
		printf("| [1]. Inserir elemento(s).        |\n");
		printf("| [2]. Retirar elemento(s).        |\n");
		printf("| [3]. Contar elemento(s) da lista.|\n");
		printf("| [4]. Exibir elemento(s) da lista.|\n");
		printf("| [0]. Sair.                       |\n");
		printf("\nOpção desejada: ");
		scanf("%d", &opc);
		getchar(); //limpa o ENTER
		
		switch(opc){
			case 1:
				printf("\n--- INSERIR ELEMENTO ---\n");
				printf("\nDigite o item que deseja adicionar na lista: ");
				fgets(item, sizeof(item), stdin);
				item[strlen(item)-1] = '\0';
				inserirNaLista(l1, item);
				break;
			case 2:
				printf("\n--- RETIRAR DA LISTA ---\n");
				printf("\nDigite o item que deseja retirar da lista: ");
				fgets(item, sizeof(item), stdin);
				item[strlen(item)-1] = '\0';
				retirarDaLista(l1, item);
				break;
			case 3:
				qtdItens = contarLista(l1);
				printf("\nHá %d itens na lista\n\n", qtdItens);
				break;
			case 4:
				exibirLista(l1);
				break;
			case 0:
				printf("\nSAINDO...\n\n");
				break;
			default:
				printf("\nOpção inválida!\n");
		}
	}while(opc != 0);
	
	return 0;
}
