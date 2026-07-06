#include "listaCircular.h"

#include<stdlib.h>

// Verifica se a lista está vazia
// Entrada: lista
// Retorno: 1 se a lista estiver vazia e 0 caso contrário
// Pré-condição: nenhuma
// Pós-condição: nenhuma
int vazia(Lista* l) {
    return (l == NULL);
}

// Faz a inserção de um item na cauda da lista
// Entrada: lista e o elemento a ser inserido
// Retorno: lista atualizada
// Pré-condição: nenhuma
// Pós-condição: o elemento é inserido na cauda da lista
Lista* inserir(Lista* l, TipoItem info) {
    Lista* aux = malloc(sizeof(Lista));

    if(aux == NULL) {
        printf("Erro de alocação.\n");
        return l;
    }

    aux->info = info;
    if(vazia(l)) {
        aux->prox = aux;
        return aux;
    }

    Lista* p = l;

    while(p->prox != l)
        p = p->prox;

    p->prox = aux;
    aux->prox = l;

    return l;
}

// Libera todos os nós da lista
// Entrada: lista
// Retorno: nenhum
// Pré-condição: nenhuma
// Pós-condição: toda a memória alocada para a lista é liberada
void liberar(Lista* l) {
    if(vazia(l)) 
        return;

    Lista* p = l->prox;

    while(p != l) {
        Lista* aux = p;
        p = p->prox;
        free(aux);
    }
    free(l);
}