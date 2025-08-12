#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void imprime_cabec(void)
{
 printf("*******************************\n");
 printf("\t* CALCULADORA *\n");
 printf("*******************************\n");
 return;
}

int soma(int num1, int num2){
    int resultadoSoma;
    resultadoSoma = num1 + num2;

    return resultadoSoma;
}

int produto(int num1, int num2){
    int resultadoProduto;
    resultadoProduto = num1*num2;

    return resultadoProduto;
}

int subtracao(int num1, int num2){
    int resultadoSubtracao;
    resultadoSubtracao = num1 - num2;

    return resultadoSubtracao;
}

int divisao(int num1, int num2){
    int resultadoDivisao;
    resultadoDivisao = num1 / num2;

    return resultadoDivisao;
}

int caracterOperacao(int num1, int num2, char operacao){
    int resultado;
    switch(operacao){
        case '+':
            resultado = soma(num1, num2);
            break;
        case '-':
            resultado = subtracao(num1, num2);
            break;
        case '*':
            resultado = produto(num1, num2);
            break;
        case '/':
            if(0 == num2){
                printf("Impossvel fazer divisão com o número 0!!!\n\n");
                resultado = 0;
                break;
            }
            resultado = divisao(num1, num2);
            break;
    }
    return resultado;
}

int main()
{
    int primeiroValor, segundoValor, resultado;
    char operacao, continuar;

    imprime_cabec();
    printf("\n");

    do{
        printf("1º valor: ");
        scanf("%d", &primeiroValor);
        printf("2º valor: ");
        scanf("%d", &segundoValor);

        printf("\n");

        printf("Operações:\n1. Soma (+)\n2. Subtração (-)\n3. Multiplicação (*)\n4. Divisão (/)\n\n");
        do{
            printf("Operação desejada(+, -, * ou /): ");
            scanf(" %c", &operacao);
            printf("\n");

            if('+' != operacao && '-' != operacao && '*' != operacao && '/' != operacao){
                printf("Digite '+', '-', '*' ou '/' para selecionar a operação!!!\n\n");
            }
        }while('+' != operacao && '-' != operacao && '*' != operacao && '/' != operacao);

        resultado = caracterOperacao(primeiroValor, segundoValor, operacao);
        printf("%d", resultado);

        do{
            printf("\n\nDeseja continuar a fazer operações [S/N]?\n");
            scanf(" %c", &continuar);
            printf("\n");
            continuar = toupper(continuar);
            if('S' != continuar && 'N' != continuar){
                printf("Caractere inválido! Digite [S ou N]\n");
            }
        }while('S' != continuar && 'N' != continuar);
    }while('S' == continuar);

    return 0;
}
