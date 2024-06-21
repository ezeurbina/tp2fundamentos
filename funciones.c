#include "estructuras.h"
#include <stdio.h>
#include <stdlib.h>

/* crea un nodo al que se le asigna memoria con malloc, si no puede asignarse
esa memoria imprime "Error" y devuelve NULL*/
p_nodo crearNodo(p_lata lata){
    p_nodo nodo=(p_nodo)malloc (sizeof(nodo));
    if (nodo==NULL){
        printf("%s\n","error");
        return NULL;
    }
    nodo->elemento=lata;
    nodo->siguiente=NULL;
    return nodo;
}

/*imprime el nodo*/
void imprimirNodo(p_nodo nodo){
    printf("%s\n",nodo->elemento->Marca);
    printf("%s\n",nodo->elemento->Color);
    printf("%f\n",nodo->elemento->tamanio);
    printf("\n");
} 

/*crea la lista inicializando la cantidad de nodos en 0 y le da ele elemento NULL a nodo
si no puede asignarse la memoria imprime "ERROR" y devuelve NULL*/
p_lista crearLista(){
    p_lista lista=(p_lista)malloc(sizeof(lista));
    if(lista==NULL){
        printf("ERROR");
        return NULL;
    }
    lista->nodo=NULL;
    lista->cantidad_nodos=0;
    return lista;

}
/*devuelve 1(TRUE) si la lista está vacia y 0(FALSE) si no lo está
La lista está vacía cuando el nodo es null y la cantidad de los mismos es cero*/
int estaVacia(p_lista lista){
    if((lista->cantidad_nodos==0)&&(lista->nodo==NULL)){
        return 1;
    }
    return 0;
}
/*Cuando la lista está vacia, insertar el primer nodo al principio pero, si no está vacía, inserta 
el nodo al siguiente del anterior*/
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
    //printf("Producto Agregado");
    lista->cantidad_nodos++;

}
/*muestra la lista por pantalla*/
void imprimirLista(p_lista lista){
    p_nodo aux=lista->nodo;
    while(aux!=NULL){
        imprimirNodo(aux);
        aux=aux->siguiente;
    }
}
/*elimina un nodo según el indice que reciba, luego, se libera la memoria*/
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
void leerArchivo(p_lista lista) {
    FILE *archivo = fopen("latas.txt", "r");
    if (archivo == NULL) {
        printf("Error al abrir el archivo");
    }else{
        char Marca[20];
        char Color[20];
        float tamanio;
        while (fscanf(archivo, "%s %s %f", Marca, Color, &tamanio) == 3) {
            p_lata nueva_lata = (p_lata)malloc(sizeof(lata));
            strcpy(nueva_lata->Marca, Marca);
            strcpy(nueva_lata->Color, Color);
            nueva_lata->tamanio = tamanio;
            insertarNodo(lista, crearNodo(nueva_lata));
        }
        fclose(archivo);
        }
}


float totalColor(p_lista lista,char color[]){
    p_nodo aux;
    float suma=0;
    aux=lista->nodo;
    while(aux!=NULL){
        if ((strcmp(aux->elemento->Color,color))==0){
            suma+=aux->elemento->tamanio;
        }
        aux=aux->siguiente;
    }
    return suma;

}

int totalLatasMarca(p_lista lista, char marca[]){
    p_nodo aux;
    int suma=0;
    aux=lista->nodo;
    while(aux!=NULL){
        if((strcmp(aux->elemento->Marca,marca))==0){/*strcmp devuelve 0 cuando las cadenas son iguales*/
            suma++;
        }
        aux=aux->siguiente;
    }
    return suma;

}

void disponibilidadColor(p_lista lista, char color[]){
    p_nodo aux;
    int cantidad=0;
    aux=lista->nodo;
    while(aux!=NULL){
        if((strcmp(aux->elemento->Color, color))==0){
            printf("%s, %f litros\n",aux->elemento->Marca,aux->elemento->tamanio);
            cantidad++;
        }
        aux=aux->siguiente;
    }
    if(cantidad==0){
        printf("Color no disponible\n");
        }
}

void verificarColorCantidad(p_lista lista, char color[],char cantidad[]){
    p_nodo aux;
}


