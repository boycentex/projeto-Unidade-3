#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "produto.h"
#include "usuario.h"

void BoasVindas()
{
    printf("Seja muito bem vindo a loja de suplementos Suplementa Plus.\nAqui voce encontra uma variedade de suplementos para de ajudar na sua meta.\n");
    printf("Seja ela perda de peso ou ganha de massa muscular.\nTambem temos produtos para de ajudar no seu rendimento durante o treino.\n");
    printf("Contamos com pre�os totalmente em conta para todo tipo de pessoa.\nTambem temos otimas promo��es em quase todos os nossos produtos.\n");
    printf("venha conferir!\n");
}

void menu()
{
    printf("escolha um dos itens abaixo\n");
    printf("1 - Cadastrar\n");
    printf("2 - Listar\n");
    printf("3 - Buscar\n");
    printf("4 - Calcular valor total em estoque de um tipo de produto\n");
    printf("5 - Valor do Item com Promo��o\n");
    printf("6 - Media de Avalia��es de um Produto Especifico\n");
    printf("7 - Procurar Produto com um Peso Espesifico\n");
    printf("8 - Comprar Mais de 1 Produto\n");
    printf("9 - Editar\n");
    printf("10 - excluir\n");
    printf("11 - ordenar\n");
    printf("0 - sair\n");
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    cadastro();
    printf("Agora vamos verificar o seu email.\n");
    printf("Por favor, informe seu email: ");

    int y = VerificacaoEmail();
    while (y == 0)
    {
        printf("Email inv�lido. Por favor, insira novamente: ");
        y = VerificacaoEmail();
    }
    printf("Email v�lido.\n\n");
    BoasVindas();
    int opcao;

    do
    {
        menu();
        printf("Escolha uma op��o: ");
        scanf("%d", &opcao);

        if (opcao == 1)
        {
            cadastrar();
        }
        else if (opcao == 2)
        {
            listar();
        }
        else if (opcao == 9)
        {
            int codigo;
            printf("Informe o c�digo do produto que deseja editar:\n");
            scanf("%d", &codigo);
            editar(codigo);
        }
        else if (opcao == 10)
        {
            int codigo;
            printf("Informe o c�digo do produto que deseja excluir:\n");
            excluir();
        }
        else if (opcao == 3)
        {
            int codigo;
            printf("Informe o c�digo do produto que deseja buscar:\n");
            scanf("%d", &codigo);
            buscar(codigo);
        }
        else if (opcao == 4)
        {
            char tipo[50];
            printf("Informe o tipo do produto para calcular o valor total em estoque:\n");
            scanf(" %[^\n]", tipo);
            calcularValorTotal(tipo);
        }
        else if (opcao == 5)
        {
            int codigo;
            printf("Informe o c�digo do produto para aplicar a promo��o:\n");
            scanf("%d", &codigo);
            promocao(codigo);
        }
        else if (opcao == 6)
        {
            int codigo;
            printf("Informe o c�digo do produto para calcular a m�dia de avalia��es:\n");
            scanf("%d", &codigo);
            MediaDosClientes(codigo);
        }
        else if (opcao == 7)
        {
            float peso;
            printf("Informe o peso espec�fico que deseja procurar:\n");
            scanf("%f", &peso);
            procurarPorPeso(peso);
        }
        else if (opcao == 8)
        {
            int codigo;
            int x;
            printf("Informe o codigo do produto que deseja procurar:\n");
            scanf("%d", &codigo);
            printf("informe a quantidade que deseja comprar desse produto:\n");
            scanf("%d", &x);
            ComprarMaisDe1(codigo, x);
        }
        else if (opcao == 11)
        {
            ordenar();
        }
        else if (opcao == 0)
        {
            printf("Encerrando o programa...\n");
        }
        else
        {
            printf("Op��o inv�lida! Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}
