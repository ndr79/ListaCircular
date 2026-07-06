#include<stdio.h>
#include<stdlib.h>

#include "listaCircular.h"

int main(int argc, const char* argv[]) {
    Lista* l = NULL;

    l = inserir(l, 1);
    l = inserir(l, 4);
    l = inserir(l, 8);
    l = inserir(l, 15);

    imprimir(l);

    l = retirar(l, 4);

    imprimir(l);

    liberar(l);
    l = NULL;

    printf("\n");
    return 0;
}