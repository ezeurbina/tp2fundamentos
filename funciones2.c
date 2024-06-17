#include "estructuras2.h"
#include <stdio.h>
#include <stdlib.h>


p_nodo crearNodo(p_lata lata){
    p_nodo n=(p_nodo)malloc (sizeof(nodo)); //n es el nuevo nodo 
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

p_lista crearLista(){
    p_lista l=(p_lista)malloc(sizeof(lista));
    l->nodo=NULL;
    l->cantidad_nodos=0;
    return l;

}
int estaVacia(p_lista l){
    if((l->cantidad_nodos==0)&&(l->nodo==NULL)){
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
    p_nodo anterior,aux;
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

}
    
