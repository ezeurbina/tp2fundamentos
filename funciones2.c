#include "estructuras2.h"
#include <stdio.h>
#include <stdlib.h>


p_nodo crearNodo(p_lata lata){
    p_nodo n=(p_nodo*)malloc (sizeof(p_nodo));
    n->elemento=lata;
    n->siguiente=NULL;
    return n;
}

void imprimirNodo(p_nodo n){
    printf("%s\n",n->elemento->Marca);
    printf("%s\n",n->elemento->Color);
} 
    
