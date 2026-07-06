#ifndef listaCircular_h
#define listaCircular_h

#include<stdio.h>

typedef int TipoItem;   // tipo dos elementos da lista

// Declaração da estrutura nó
typedef struct no {
    TipoItem info;
    struct no* prox;
} Lista;


#endif /* listaCircular_h */