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
int inserirAlunos(){
    int numCadastros;
    int i; //será usado no loop FOR
    printf("\n---- CADASTRO DA TURMA ----\n"); // Informações da turma
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

    printf("--- CADASTRO DOS ALUNOS ---");
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
    return numCadastros;

}

//função para listar os alunos da turma
int exibirAlunos(){
    char temp;
    int i;
    printf("---- LISTA DE ALUNOS ----\n");
    printf("Nº alunos: %d\n", dt.qtdAlunos);
    for(i = 0; i < dt.qtdAlunos; i++){
        printf(".......................\n");
        printf("--- %dº aluno ---\n", i+1);
        printf("| Nome: \t%s\n", dt.turma[i].nome);
        printf("| Matricula: \t%d\n", dt.turma[i].matricula);
        printf("| Faltas: \t%d\n", dt.turma[i].faltas);
        printf("| Nota 1: \t%2.1f\n", dt.turma[i].nota1);
        printf("| Nota 2: \t%2.1f\n", dt.turma[i].nota2);
        printf("| Media: \t%2.1f\n", dt.turma[i].media);
        printf("| Situação: \t%s\n", dt.turma[i].situacao);
    }
    
    //essa leitura serve para que o menu só apareça
    // quando o usuario terminar de analisar a lista
    printf("aperte ENTER para voltar: ");
    temp = getchar();
    return 0;
}

//função para salvar em arquivo os alunos
// retorna 1 se der erro ao abrir/criar o arquivo
// retorna 2 se os dados não foram gravados de forma correta
// retorna 0 se os dados forem salvos sem erros
int salvarAlunos(){
    FILE *arq; //ponteiro do arquivo
    arq = fopen("aluno.txt", "w"); //abre o arquivo com escrita(se nao existir cria)
    size_t salvo;

    if(!arq) {
        printf("\n----------------------------------\n");
        printf("ERRO: ao abrir/criar o arquivo!");
        printf("\n----------------------------------\n");
        fflush(stdout);
        return 1;
    }
    salvo = fwrite(&dt, sizeof(struct Tturma), 1, arq);  
    
    if(salvo != 1 || ferror(arq) != 0){
        printf("\n-----------------------------------\n");
        printf("ERRO: dados gravados incorretamente!");
        printf("\n-------------------------------------\n");
        
        return 2;
    }
    fclose(arq); //fecha o arquivo
    printf("\n-------------------------------\n");
    printf("SUCESSO: os dados foram salvos!\n");
    printf("\n----------------------------------\n");
    return 0;
}
//função para carregar um arquivo de dados dos alunos
int carregarAlunos(){
    FILE *arq;
    size_t lido;
    arq = fopen("aluno.txt", "rb");
    
    if(arq == NULL){
        printf("\n-----------------------------\n");
        printf("ERRO: arquivo inexistente!\n");
        printf("------------------------------\n");
    }else{
        lido = fread(&dt, sizeof(struct Tturma), 1, arq);
        fclose(arq);      
        if(lido == 1){
            printf("\n-----------------------------\n");
            printf("SUCESSO: dados carregados!");
            printf("------------------------------n");
            return dt.qtdAlunos; //retorna o número de alunos registrados
        }else{
            printf("\n---------------------------------\n");
            printf("ERRO: não foi possível carregar!\n");
            printf("\n----------------------------------\n");
        }
	}
    return 1;
}

//função que mostra o menu
int menu(int n){
    int opcao;
    
    //validação da opção do menu
    do{
		printf("---- MENU ----\n");
		printf("| [1] - Inserir alunos\n");
		printf("| [2] - Exibir alunos\n");
        printf("| [3] - Salvar alunos\n");
        printf("| [4] - Carregar alunos\n");
        printf("| [0] - Sair\n");
        printf("|.....................\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); //limpa o ENTER

        if(opcao == 0){
			break;
		}
        if(opcao < 0 || opcao > 4){
            printf("\n************************\n");
            printf("ERRO: Entrada Invalida!!\n");
            printf("************************\n\n");
        }else if(n == 0 && opcao != 1 && opcao != 4){
            printf("\n----------------------------\n");
            printf("ERRO: Nenhum cadastro feito!");
            printf("\n------------------------------\n\n");
            opcao = -1; //impede a saída do loop por ter erro
        }
	}while(opcao < 0 || opcao > 4);
	return opcao;
}

//função principal
int main(){
    int opcao, numCadastros = 0;
    printf("\n---- REGISTRO DE TURMA ----\n\n");

	//menu em loop
    do{
        opcao = menu(numCadastros);
        switch(opcao){
            case 1: 
				//chama a função de cadastro
                numCadastros = inserirAlunos();
                break;

            case 2: 
				//chama a função para listar os alunos
				exibirAlunos();
                break;

            case 3:
				//chama a função para gravar os dados
				salvarAlunos();
                break;

            case 4: 
				//chama a função para armazenar na memoria os registros
                numCadastros = carregarAlunos();
                break;
            
            case 0: 
				printf("\nSAINDO...\n\n");
                break;
        }
    }while(opcao != 0);
    
    return 0;
}
