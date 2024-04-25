#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "usuario.h"

#define USUARIO "vicente123"
#define SENHA "123456"
#define EMAIL "vicenteneto159@gmail.com"

struct login
{
    char usuario[50];
    char senha[15];
    char email[80];
};

int cadastro()
{

    char usuario[50];
    char senha[15];

    printf("Digite o nome de usu�rio: ");
    scanf("%s", usuario);
    printf("Digite a sua senha: ");
    scanf("%s", senha);

    int x = VerificacaoLogin(usuario, senha);
    while (x != 0)
    {
        printf("Nome de usu�rio ou senha incorreto. Tente novamente.\n");
        printf("Digite o nome de usu�rio novamente: ");
        scanf("%s", usuario);
        printf("Digite a sua senha novamente: ");
        scanf("%s", senha);
        x = VerificacaoLogin(usuario, senha);
    }
    printf("Verifica��o do login conclu�da com sucesso.\n\n");
}

int VerificacaoLogin(char usuario[50], char senha[15])
{
    if (strcmp(USUARIO, usuario) != 0 || strcmp(SENHA, senha) != 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int VerificacaoEmail()
{
    char email[80];
    scanf("%s", email);
    if (strcmp(EMAIL, email) == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
