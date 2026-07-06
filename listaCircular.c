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

// Imprime os elementos da lista
// Entrada: lista
// Retorno: nenhum
// Pré-condição: nenhuma
// Pós-condição: os elementos da lista são exibidos na tela
void imprimir(Lista* l) {
    if(vazia(l))
        printf("Lista vazia.\n");
    else {
        Lista* p = l;
        printf("[ ");
        do {
            printf("%d ", p->info);
            p = p->prox;
        }while(p != l);
        printf("]\n");
    }
}

// Remove um item da lista
// Entrada: lista e o elemento a ser retirado
// Retorno: lista atualizada
// Pré-condição: nenhuma
// Pós-condição: o elemento é retirado da lista
Lista* retirar(Lista* l, TipoItem x) {
    if(vazia(l)) {
        printf("Lista vazia.\n");
        return l;
    }

    Lista* ant = NULL;
    Lista* p = l;

    do {
        if(p->info == x)
            break;
        ant = p;
        p = p->prox;
    } while(p != l);

    if(p->info != x) {
        printf("Elemento não encontrado.\n");
        return l;
    }

    if(p == l && p->prox == l) {    // lista com um único elemento
        free(p);
        return NULL;
    }

    if(p == l) {    // Remoção na cabeça
        Lista* ultimo = l;

        while(ultimo->prox != l)
            ultimo = ultimo->prox;

        l = l->prox;
        ultimo->prox = l;
        free(p);
        return l;
    }

    // remoção do meio ou cauda
    ant->prox = p->prox;
    free(p);
    return l;
}