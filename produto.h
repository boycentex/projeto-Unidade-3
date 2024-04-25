#ifndef H_PRODUTO
#define H_PRODUTO

typedef struct produto Produto;
typedef struct lista Lista;
typedef struct no No;

void FimLista(Lista *lista, Produto x);
void mostrar(Lista lista);
void editarPreco(Lista *lista, int codigo);
void deletar(Lista *lista, int codigo);
void ler(Produto *x);
void cadastrar();
void listar();
int tamanho();
void adicionaFim(Lista *lista, Produto p);
void lerLista(Lista *lista);
void salvaLista(Lista *lista);
void ordenar();
void excluir();
void editar(int codigo);
void calcularValorTotal(char tipo[]);
void promocao(int codigo);
void MediaDosClientes(int codigo);
void procurarPorPeso(float peso);
void buscar(int codigo);
void ComprarMaisDe1(int codigo, int x);

#endif
