#include "estructuras.h"
#include <stdio.h>
#include <stdlib.h>


p_nodo crearNodo(p_lata lata){
    p_nodo nodo=(p_nodo)malloc (sizeof(nodo));
    if (nodo==NULL){
        printf("%s\n","error");
    }
    nodo->elemento=lata;
    nodo->siguiente=NULL;
    return nodo;
}

void imprimirNodo(p_nodo nodo){
    printf("%s\n",nodo->elemento->Marca);
    printf("%s\n",nodo->elemento->Color);
    printf("%f\n",nodo->elemento->tamanio);
    printf("\n");
} 

p_lista crearLista(){
    p_lista lista=(p_lista)malloc(sizeof(lista));
    lista->nodo=NULL;
    lista->cantidad_nodos=0;
    return lista;

}
int estaVacia(p_lista lista){
    if((lista->cantidad_nodos==0)&&(lista->nodo==NULL)){
        return 1;
    }
    return 0;
}

void insertarNodo(p_lista lista, p_nodo nodo){
    if(estaVacia(lista)){
        lista->nodo=nodo;
    }else{
        p_nodo aux = lista->nodo;
        while (aux->siguiente != NULL) {
            aux = aux->siguiente;
        }
        aux->siguiente = nodo;
    }
    lista->cantidad_nodos++;

}

void imprimirLista(p_lista lista){
    p_nodo aux=lista->nodo;
    while(aux!=NULL){
        imprimirNodo(aux);
        aux=aux->siguiente;
    }
}

void eliminarNodo(p_lista lista,int indice){
    if(!estaVacia(lista)){
        p_nodo aux,anterior;
        if(indice>=0 && indice<lista->cantidad_nodos-1){
            aux=lista->nodo;
            for (int i=0;i<indice;i++){
                anterior=aux;
                aux=aux->siguiente;
            }
            anterior->siguiente=aux->siguiente;
            free(aux);
            lista->cantidad_nodos--;
        }
    }else{
        printf("La lista está vacia\n");
    }


}


    
