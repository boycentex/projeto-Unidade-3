#include <stdio.h>
#include <math.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>
#include <ctype.h>
#include "produto.h"

struct produto
{
    char nome[50];
    char tipo[50];
    float peso;
    float preco;
    int quantidade;
    int codigo;
    float avaliacao; // uma media das avalia��es dos clientes do produto, vai de 0 at� 10 //
};

struct no
{
    Produto dado;
    struct no *prox;
};

struct lista
{
    No *inicio;
};

void FimLista(Lista *lista, Produto x)
{
    No *novo = (No *)malloc(sizeof(No));
    novo->dado = x;
    novo->prox = NULL;
    if (novo == NULL)
    {
        printf("Erro: n�o foi poss�vel alocar mem�ria para um novo n�.\n");
        return;
    }

    if (lista->inicio == NULL)
    {
        lista->inicio = novo;
    }
    else
    {
        No *ptr;
        for (ptr = lista->inicio; ptr->prox != NULL; ptr = ptr->prox)
            ;
        ptr->prox = novo;
    }
}

void mostrar(Lista lista)
{
    No *ptr;
    for (ptr = lista.inicio; ptr != NULL; ptr = ptr->prox)
    {
        Produto n = ptr->dado;
        printf("Nome: %s\nTipo: %s\nPre�o: %.2f\nPeso: %.2f\nQuantidade: %d\nC�digo: %d\nAvalia��es: %.1f\n\n",
               n.nome, n.tipo, n.preco, n.peso, n.quantidade, n.codigo, n.avaliacao);
    }
}

void editarPreco(Lista *lista, int codigo)
{
    if (lista->inicio == NULL)
    {
        printf("Lista vazia\n");
    }
    else
    {
        No *ptr;
        for (ptr = lista->inicio; ptr != NULL && ptr->dado.codigo != codigo; ptr = ptr->prox)
            ;
        if (ptr == NULL)
        {
            printf("Produto n�o encontrado\n");
        }
        else
        {
            float price;
            printf("Informe o novo preco:\n");
            scanf("%f", &price);
            ptr->dado.preco = price;
            printf("Preco atualizado: %.2f\n", ptr->dado.preco);
        }
    }
}

void deletar(Lista *lista, int codigo)
{
    if (lista->inicio == NULL)
    {
        printf("Lista vazia\n");
    }
    else
    {
        No *pa = NULL;
        No *ptr;
        for (ptr = lista->inicio; ptr->prox != NULL && ptr->dado.codigo != codigo; ptr = ptr->prox)
        {
            pa = ptr;
        }
        if (pa == NULL)
        {
            if (ptr->dado.codigo == codigo)
            {
                lista->inicio = ptr->prox;
                free(ptr);
            }
            else
            {
                printf("Produto n�o encontrado\n");
            }
        }
        else
        {
            if (ptr->dado.codigo == codigo)
            {
                pa->prox = ptr->prox;
                free(ptr);
            }
            else
            {
                printf("Produto n�o encontrado\n");
            }
        }
    }
}

void ler(Produto *x)
{
    printf("Informe os dados do produto:\n");
    scanf("%s %s %f %f %d %d %f", x->nome, x->tipo, &x->preco, &x->peso, &x->quantidade, &x->codigo, &x->avaliacao);
}

void cadastrar()
{
    FILE *arq = fopen("produto.b", "ab");
    if (arq == NULL)
    {
        printf("Erro ao abrir o arquivo de produtos.\n");
        return;
    }
    Produto n;
    printf("Informe os dados do novo produto:\n");
    printf("Nome: ");
    scanf(" %[^\n]", n.nome);
    printf("Tipo: "); // uma op��o seria suplemento
    scanf(" %[^\n]", n.tipo);
    printf("Pre�o: ");
    scanf("%f", &n.preco);
    printf("Peso em gramas do Produto:\n");
    scanf("%f", &n.peso);
    printf("Quantidade disponivel no estoque:\n");
    scanf("%d", &n.quantidade);
    printf("Informe o codigo do produto:\n");
    scanf("%d", &n.codigo);
    printf("Informe a media de avaliacoes dos clientes pelo produto:\n");
    scanf("%f", &n.avaliacao);
    fwrite(&n, sizeof(Produto), 1, arq);
    printf("Produto cadastrado com sucesso!\n");
    fclose(arq);
}

void listar()
{
    FILE *arq = fopen("produto.b", "rb");
    if (arq == NULL)
    {
        printf("Erro ao abrir o arquivo de produtos.\n");
        return;
    }
    Produto n;
    while (fread(&n, sizeof(Produto), 1, arq))
    {
        printf("Nome: %s\nTipo: %s\nPre�o: %.2f\nPeso: %.2f\nQuantidade: %d\nC�digo: %d\nAvalia��es: %.1f\n\n",
               n.nome, n.tipo, n.preco, n.peso, n.quantidade, n.codigo, n.avaliacao);
    }
    fclose(arq);
}

int tamanho()
{
    FILE *arq = fopen("produto.b", "rb");
    Produto n;
    int cont = 0;
    while (fread(&n, sizeof(Produto), 1, arq))
    {
        cont++;
    }
    fclose(arq);
    return cont;
}

void adicionaFim(Lista *lista, Produto p)
{
    No *novo = (No *)malloc(sizeof(No));
    novo->dado = p;
    novo->prox = NULL;
    if (lista->inicio == NULL)
    {
        lista->inicio = novo;
    }
    else
    {
        No *pi;
        for (pi = lista->inicio; pi->prox != NULL; pi = pi->prox)
            ;
        pi->prox = novo;
    }
}

void lerlista(Lista *lista)
{
    FILE *arq = fopen("produto.b", "rb");
    Produto n;
    while (fread(&n, sizeof(Produto), 1, arq))
    {
        adicionaFim(lista, n);
    }
    fclose(arq);
}

void salvaLista(Lista *lista)
{
    FILE *arq = fopen("produto.b", "wb");
    No *ptr;
    for (ptr = lista->inicio; ptr != NULL; ptr = ptr->prox)
    {
        fwrite(&ptr->dado, sizeof(Produto), 1, arq);
    }
    fclose(arq);
}

void ordenar()
{
    Lista lista;
    lista.inicio = NULL;
    lerlista(&lista);
    No *p1;
    No *p2;
    No *fim = NULL;
    if (lista.inicio == NULL)
    {
        return;
    }
    for (p1 = lista.inicio; p1->prox != NULL; p1 = p1->prox)
    {

        for (p2 = lista.inicio; p2->prox != NULL; p2 = p2->prox)
        {
            if (p2->dado.codigo > p2->prox->dado.codigo)
            {
                struct produto temp = p2->dado;
                p2->dado = p2->prox->dado;
                p2->prox->dado = temp;
            }
        }
    }
    salvaLista(&lista);
}

void excluir()
{

    int a;
    printf("Digite o código do item que deseja excluir: ");
    scanf("%d", &a);
    Lista lista;
    lista.inicio = NULL;
    lerlista(&lista);
    deletar(&lista, a);
    salvaLista(&lista);
}

void editar(int codigo)
{
    Lista lista;
    lista.inicio = NULL;
    lerlista(&lista);
    editarPreco(&lista, codigo);
    salvaLista(&lista);
}

void calcularValorTotal(char tipo[])
{
    FILE *arq = fopen("produto.b", "rb");
    if (arq == NULL)
    {
        printf("Erro ao abrir o arquivo de produtos.\n");
        return;
    }
    Produto n;
    int valor = 0;
    while (fread(&n, sizeof(Produto), 1, arq))
    {
        if (strcmp(n.tipo, tipo) == 0)
        {
            valor = n.quantidade;
        }
    }
    printf("O valor total em estoque do tipo %s �: %d unidades\n", tipo, valor);
    fclose(arq);
}

void promocao(int codigo)
{
    FILE *arq = fopen("produto.b", "rb");
    if (arq == NULL)
    {
        printf("Erro ao abrir o arquivo de produtos.\n");
        return;
    }
    Produto n;
    float valor;
    while (fread(&n, sizeof(Produto), 1, arq))
    {
        if (n.codigo == codigo)
        {
            valor = n.preco - (0.2 * n.preco);
        }
    }
    printf("o valor do produto na promo��o � de %.2f reais\n", valor);
    fclose(arq);
}

void MediaDosClientes(int codigo)
{ // media dos clientes sobre um determinado produto//
    FILE *arq = fopen("produto.b", "rb");
    if (arq == NULL)
    {
        printf("Erro ao abrir o arquivo de produtos.\n");
        return;
    }
    Produto n;
    float media;
    while (fread(&n, sizeof(Produto), 1, arq))
    {
        if (n.codigo == codigo)
        {
            media = n.avaliacao;
        }
    }
    printf("a media de avalia��es de 0 a 5 desse produto � de %.1f\n", media);
    fclose(arq);
}

void procurarPorPeso(float peso)
{
    FILE *arq = fopen("produto.b", "rb");
    if (arq == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }
    Produto n;
    int encontrado = 0;
    while (fread(&n, sizeof(Produto), 1, arq))
    {
        if (n.peso == peso)
        {

            encontrado = 1;
            printf("um produto com esse peso foi encontrado seu nome � %s do tipo %s\n", n.nome, n.tipo);
        }
    }
    if (!encontrado)
    {
        printf("Nenhum produto encontrado com o peso especificado.\n");
    }
    fclose(arq);
}

void buscar(int codigo)
{
    FILE *arq = fopen("produto.b", "rb");
    if (arq == NULL)
    {
        printf("Erro ao abrir o arquivo de produtos.\n");
        return;
    }
    No *ptr;
    Produto n = ptr->dado;
    int dx = 0;
    while (fread(&n, sizeof(Produto), 1, arq))
    {
        if (n.codigo == codigo)
        {
            printf("nome:%s\ntipo:%s\npre�o:%.2f reais\npeso:%.2f gramas\nquantidade:%d\ncodigo:%d\nmedia de avalia��es dos clientes:%.2f\n", n.nome, n.tipo, n.preco, n.peso, n.quantidade, n.codigo, n.avaliacao);
            dx = 1;
        }
    }
    if (dx == 0)
    {
        printf("Produto n�o Encontrado\n");
    }
    fclose(arq);
}

void ComprarMaisDe1(int codigo, int x)
{
    FILE *arq = fopen("produto.b", "rb");
    if (arq == NULL)
    {
        printf("Erro ao abrir o arquivo de produtos.\n");
        return;
    }
    Produto n;
    float soma = 0;
    int encontrado = 0; // Vari�vel para verificar se o Produto foi encontrado
    while (fread(&n, sizeof(Produto), 1, arq))
    {
        if (n.codigo == codigo)
        {
            soma = x * n.preco;
            encontrado = 1;
            break;
        }
    }

    if (encontrado)
    {
        printf("O valor final da compra vai ser igual a %.2f reais\n", soma);
    }
    else
    {
        printf("Produto n�o encontrado.\n");
    }

    fclose(arq);
}
