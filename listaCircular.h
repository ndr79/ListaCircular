#ifndef listaCircular_h
#define listaCircular_h

#include<stdio.h>

typedef int TipoItem;   // tipo dos elementos da lista

// Declaração da estrutura nó
typedef struct no {
    TipoItem info;
    struct no* prox;
} Lista;

// Verifica se a lista está vazia
// Entrada: lista
// Retorno: 1 se a lista estiver vazia e 0 caso contrário
// Pré-condição: nenhuma
// Pós-condição: nenhuma
int vazia(Lista* l);

// Faz a inserção de um item na cauda da lista
// Entrada: lista e o elemento a ser inserido
// Retorno: lista atualizada
// Pré-condição: nenhuma
// Pós-condição: o elemento é inserido na cauda da lista
Lista* inserir(Lista* l, TipoItem info);

// Libera todos os nós da lista
// Entrada: lista
// Retorno: nenhum
// Pré-condição: nenhuma
// Pós-condição: toda a memória alocada para a lista é liberada
void liberar(Lista* l);


#endif /* listaCircular_h */