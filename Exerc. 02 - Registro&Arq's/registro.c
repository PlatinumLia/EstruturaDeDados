#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TAM 40 // Define o tamanho (usado para saber a qtd máxima da turma)

struct Taluno{
    char nome[40];
    char situacao[10];
    int matricula;
    int faltas;
    float nota1;
    float nota2;
    float media;
};

struct Tturma{
    struct Taluno turma[TAM]; //aluno pertence a uma turma
    int qtdAlunos;
};

struct Tturma dt; //variável "dt" que contém os dados da turma

/* Função para cadastrar a turma */
void inserirAlunos(){
    int numCadastros;
    int i; //será usado no loop FOR
    
    printf("\n\n---- CADASTRO DA TURMA ----\n\n"); // Informações da turma
    do{ 
        printf("Informe o número de alunos: ");
        scanf("%d", &numCadastros);
        if(numCadastros > TAM){
            printf("\n************************\n");
            printf("ERRO: Número de cadastros\n");
            printf("maior que o limite máximo\n");
            printf("*************************\n\n");
        }
    }while(numCadastros > TAM && numCadastros <= 0); //não loopa se digitar algum caractere
    dt.qtdAlunos = numCadastros; //salva a quantidade de alunos cadastrados
    printf("\n..........................\n");

    printf("\n--- CADASTRO DOS ALUNOS ---\n");
    //inserindo os dados dos alunos
    for(i = 0; i < numCadastros; i++){
        printf("\n--- %dº aluno ---\n", i+1);
        printf("| Nome: ");
        getchar(); //apaga o ENTER deixado pelo scanf no buffer
        fgets(dt.turma[i].nome, 40, stdin);
        dt.turma[i].nome[strlen(dt.turma[i].nome)-1] = '\0'; //remove o fim da linha da string
        printf("| Matricula: ");
        scanf("%d", &dt.turma[i].matricula);
        printf("| Nota 1: ");
        scanf("%f", &dt.turma[i].nota1);
        printf("| Nota 2: ");
        scanf("%f", &dt.turma[i].nota2);
        printf("| Numero faltas: ");
        scanf("%d", &dt.turma[i].faltas);

        //determinando a situação do aluno
        dt.turma[i].media = (dt.turma[i].nota1 + dt.turma[i].nota2) / 2;
        if(dt.turma[i].media >= 6 && dt.turma[i].faltas <= 20){
           //insere um valor na string previamente declarada
           strcpy(dt.turma[i].situacao, "Aprovado\n");
        }
        else{
			strcpy(dt.turma[i].situacao, "Reprovado\n");
		}
    }
    printf("\n..........................\n");
}

//função para listar os alunos da turma
void exibirAlunos(){
    int i;
    printf("\n\n---- LISTA DE ALUNOS ----\n\n");
    printf("Nº alunos: %d\n", dt.qtdAlunos);
    for(i = 0; i < dt.qtdAlunos; i++){
        printf("--- %dº aluno ---\n", i+1);
        printf("| Nome: \t%s\n", dt.turma[i].nome);
        printf("| Matricula: \t%d\n", dt.turma[i].matricula);
        printf("| Faltas: \t%d\n", dt.turma[i].faltas);
        printf("| Nota 1: \t%2.1f\n", dt.turma[i].nota1);
        printf("| Nota 2: \t%2.1f\n", dt.turma[i].nota2);
        printf("| Media: \t%2.1f\n", dt.turma[i].media);
        printf("| Situação: \t%s\n", dt.turma[i].situacao);
    }
}

//função para salvar em arquivo os alunos
void salvarAlunos(){
    FILE *arq = fopen("aluno.bin", "wb"); //abre o arquivo com escrita(se nao existir cria); 

	//se não abrir o arquivo
    if(!arq){
        printf("ERRO: ao abrir/criar o arquivo!");
        return;
    }
    fwrite(&dt, sizeof(struct Tturma), 1, arq); //Salva a quantidade de alunos
    fclose(arq); //Fecha o arquivo

    printf("\nDados salvos em 'aluno.bin'!\n");
}

//função para carregar um arquivo de dados dos alunos
void carregarAlunos(){
    FILE *arq = fopen("aluno.bin", "rb");
    
    //se não houver arquivo
    if(!arq){ 
        printf("\nNenhum arquivo encontrado!\nPrimeiro salve os dados.\n"); 
        return;
	}
	
	fread(&dt, sizeof(struct Tturma), 1, arq); //Carrega a quantidade de turmas
    fclose(arq);

    printf("\nDados carregados de 'aluno.bin'!\n");
}

//função principal
int main(){
    int opcao;
    
    //validação da opção do menu
    do{
		printf("\n---- MENU ----\n");
		printf("| [1] - Inserir alunos\n");
		printf("| [2] - Exibir alunos\n");
        printf("| [3] - Salvar alunos\n");
        printf("| [4] - Carregar alunos\n");
        printf("| [0] - Sair\n");
        printf("|.....................\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); //limpa o ENTER
        
        switch(opcao){
			case 1:
				inserirAlunos();
				break;
			case 2:
				exibirAlunos();
				break;
			case 3:
				salvarAlunos();
				break;
			case 4:
				carregarAlunos();
				break;
			case 0:
				printf("\nSAINDO...\n");
				break;
			default:
				printf("\nOpção inválida!\n");
		}
	}while(opcao != 0 || opcao > 4);
    
    return 0;
}
