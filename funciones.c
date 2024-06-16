#include "estructuras.h"
#include <stdio.h>
#include <stdlib.h>


Nodo *crearNodo(Lata lata){
    Nodo *n=(Nodo*)malloc (sizeof(Nodo));
    n->lata=lata;
    n->siguiente=NULL;
    return n;
}

void imprimirNodo(Nodo *n){
    printf("%s\n",n->lata.Marca);
    printf("%s\n",n->lata.Color);
} 
    
Lista *crearLista(){
    Lista *lista=(Lista*)malloc(sizeof(Lista));
    lista->raiz=NULL;
    lista->ultimo=NULL;
    lista->cantidad_nodos=0;
    return lista;
}

int estaVacia(Lista *lista){
    if (lista->cantidad_nodos){
        return 1;
    }else{
        return 0;
    }
}

void insertarFinal(Lista *lista, Nodo *nodo){
    if (estaVacia(lista)){
        lista->raiz=nodo;
        lista->ultimo=nodo;
    }else{
        lista->ultimo->siguiente=nodo;
        lista->ultimo=nodo;
    }
    lista->cantidad_nodos++;
}

void imprimirLista(Lista *lista){
    Nodo *aux=lista->raiz;
    while(aux!=NULL){
        imprimirNodo(aux);
        aux=aux->siguiente;
    }
}

void eliminarPrimero(Lista *lista){
    Nodo *aux;
    if(!estaVacia(lista)){
        if(lista->cantidad_nodos==1){
            aux=lista->raiz;
            lista->raiz=NULL;
            lista->ultimo=NULL;
        }else{
            aux=lista->raiz;
            lista->raiz=lista->raiz->siguiente;
        }
        //free(aux);
        lista->cantidad_nodos--;

    }
}

void eliminarIndice(Lista *l, int indice){
    if (indice>=0 && indice<l->cantidad_nodos-1){
        if(indice==0){

        }
    }
}