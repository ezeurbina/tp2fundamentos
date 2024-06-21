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
    printf("Producto Agregado\n");
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

/*PUNTO 1*/
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

/*PUNTO 3.A)*/
void insertarNuevaLata(p_lista lista){
    char Marca[20];
    char Color[20];
    float tamanio;
    p_lata nueva_lata = (p_lata)malloc(sizeof(lata));

    printf("Ingrese la Marca: ");
    scanf("%s",Marca);
    printf("Ingrese el color: ");
    scanf("%s",Color);
    printf("Ingrese el tamaño de la lata: ");
    scanf("%f",&tamanio);

    strcpy(nueva_lata->Marca, Marca);
    strcpy(nueva_lata->Color, Color);
    nueva_lata->tamanio = tamanio;
    insertarNodo(lista, crearNodo(nueva_lata));

}

/*se crea la lista necesaria para los strings*/
p_lista_str crearListaStr(){
    p_lista_str lista=(p_lista_str)malloc(sizeof(lista_str));
    if(lista==NULL){
        printf("ERROR");
        return NULL;
    }
    lista->nodo=NULL;
    lista->cantidad_nodos=0;
    return lista;
    
}

p_nodo_str crearNodoStr(char str[]){
    p_nodo_str nodo=(p_nodo_str)malloc (sizeof(nodo_str));
    if (nodo==NULL){
        printf("%s\n","error");
        return NULL;
    }
    strcpy(nodo->str,str); 
    nodo->siguiente=NULL;
    return nodo;
}

void insertarNodoStr(p_lista_str lista, p_nodo_str nodo){
    if(lista->cantidad_nodos==0){
        lista->nodo=nodo;
    }else{
        p_nodo_str aux = lista->nodo;
        while (aux->siguiente != NULL) {
            aux = aux->siguiente;
        }
        aux->siguiente = nodo;
    }
    lista->cantidad_nodos++;
}

void imprimirStr(p_lista_str lista){
    p_nodo_str aux=lista->nodo;

    while(aux!=NULL){
        printf("%s, ",aux->str);
        aux=aux->siguiente;
    }
    printf("\n");
}

int cadenaEnLista(p_lista_str lista, char str[]){
    p_nodo_str aux=lista->nodo;
    while(aux->str!=NULL){
        if ((strcmp(aux->str,str))==0){
            return 1;
        }else{
            aux=aux->siguiente;
        }
    }
    return 0;
}

void totalLatasMarca(p_lista lista, char marca[]){
    p_nodo aux;
    int cantidadLatas=0;
    p_lista_str listaColor=crearListaStr();
    aux=lista->nodo;
    while(aux!=NULL){
        if((strcmp(aux->elemento->Marca,marca))==0){/*strcmp devuelve 0 cuando las cadenas son iguales*/
            if(!cadenaEnLista(listaColor,aux->elemento->Color)){
                insertarNodoStr(listaColor,crearNodoStr(aux->elemento->Color));
                cantidadLatas++;
            }
        }
        aux=aux->siguiente;
    }
    printf("Colores: ");
    imprimirStr(listaColor);
    printf("Cantidad de latas: %i\n",cantidadLatas);
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


void verificarColorCantidad(p_lista lista, char color[],float cantidad){
    if(estaVacia(lista)){
        printf("LISTA VACIA\n");
    }else{
        p_nodo aux=lista->nodo;
        p_lista_str listaStr=crearListaStr();
        while(aux!=NULL){
            if(((strcmp(aux->elemento->Color,color))==0) && (aux->elemento->tamanio==cantidad)){
                if(!cadenaEnLista(listaStr,aux->elemento->Marca)){
                    insertarNodoStr(listaStr,crearNodoStr(aux->elemento->Marca));
                }
            }

            aux=aux->siguiente;
        }
        if(listaStr->cantidad_nodos==0){
            printf("Stock no disponible\n");
        }
        imprimirStr(listaStr);
    }
}

void totalColor(p_lista lista, char color[]){
    p_nodo aux=lista->nodo;
    p_lista_str listaStr=crearListaStr();
    float totalColor=0;
    int totalLatas=0;
    while(aux!=NULL){
        if((strcmp(aux->elemento->Color,color))==0){
            if(!cadenaEnLista(listaStr,aux->elemento->Marca)){
                insertarNodoStr(listaStr,crearNodoStr(aux->elemento->Marca));
            }
            totalColor+=aux->elemento->tamanio;
            totalLatas++;
            }
            aux=aux->siguiente;
        }
    printf("Marcas: ");
    imprimirStr(listaStr);
    printf("Total Color: %f\n",totalColor);
    printf("Cantidad latas: %i\n",totalLatas);    
    }



