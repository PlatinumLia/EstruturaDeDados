#include<stdio.h>
#define TAM 10

// Busca sequencial de um valor em um vetor
// vet é o vetor de inteiros
// tam é o tamanho do vetor
// valor é o número a ser buscado
// Retorna o índice do vetor onde está o valor, ou -1 se não encontrado
/* ----> versão que procura até o fim do vetor, mesmo depois de achar o elemento
int buscaSeq(int *vet, int tam, int valor){
    int i;
    int pos = -1;

    for (i=0; i<tam; i++){
        if (valor == vet[i]){
            pos = i;
        }
    }
    return (pos);
}
*/

int buscaSeq(int *vet, int tam, int valor) {
    int i=0;
    int pos = -1;
    while ((i<tam) && (pos==-1)) {
        if (valor == vet[i]) {
            pos = i;
        }
        i++;
    }
    return (pos);
}

void inserir(int *vet) {
    int i; 
    for(i = 0; i < TAM; i++){
        printf("Nº [%d]: ", i);
        scanf("%d", &valor);
    }
}

//função para mostrar um menu
int menu() {
    int opc;

    do {
        printf("\n===== BUSCA SEQUENCIAL E BINÁRIA =====\n\n");
        printf("[1]. Inserir elemento.\n");
        printf("[2]. Busca sequencial.\n");
        printf("[3]. Busca bunária.\n");
        printf("[0]. Sair.\n");

        printf("\nEscolha uma opção: ");
        scanf("%d", &opc);
        if((opc < 0) || (opc > 3)) {
            printf("\nOPÇÃO INVÁLIDA!!\n");
        }
    } while((opc < 0) || (opc > 3));

    return (opc);
}

//funcão principal
int main()
{
    int i, opc, vet[TAM], valor, s;
    
    do{
        opc = menu();
        
        switch(opc){
            case 1:
                printf("\n=*= INSERIR ELEMENTOS =*=\n\n");
                inserir(vet);            
                break;
            
            case 2:
                printf("\n=*= BUSCA SEQUENCIAL =*=\n\n");
                printf("Nº que deseja buscar: ");
                scanf("%d", &valor);
                s = buscaSeq(vet, TAM, valor);
                
                if(!s){
                    printf("Valor não encontrado!\n\n");
                }else{
                    printf("Elemento encontrado!\nPosição do elemento: [%d]", s);
                }
                
                break;
        }
    }while(opc != 0);
    
    return 0;

}
