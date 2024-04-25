#ifndef H_LOGIN
#define H_LOGIN

typedef struct login Login;
typedef struct lista Lista;
typedef struct no No;

int cadastro();
int VerificacaoLogin(char usuario[50], char senha[15]);
int VerificacaoEmail();

#endif
