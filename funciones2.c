#include "estructuras2.h"
#include <stdio.h>
#include <stdlib.h>


p_nodo crearNodo(p_lata lata){
    p_nodo n=(p_nodo)malloc (sizeof(nodo));
    if (n==NULL){
        printf("%s\n","error");
    }
    n->elemento=lata;
    n->siguiente=NULL;
    return n;
}

void imprimirNodo(p_nodo n){
    printf("%s\n",n->elemento->Marca);
    printf("%s\n",n->elemento->Color);
    printf("%f\n",n->elemento->tamanio);
} 
    
