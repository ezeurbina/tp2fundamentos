#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> //funcion toupper
#include "estructuras.h"
#include "funciones.c"

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

float totalColor(p_lista lista){
    p_nodo aux;
    float suma;
    aux=lista->nodo;
    while(aux->siguiente!=NULL){
        suma+=aux->elemento->tamanio;
        aux=aux->siguiente;
    }
    suma+=aux->elemento->tamanio;
    
    return suma;
}

int totalLatasMarca(p_lista lista, char dato){
    p_nodo aux;
    int suma=0;
    aux=lista->nodo;
    while(aux->siguiente!=NULL){
        if(strcmp(aux->elemento->Marca,&dato)){
            suma++;
        }
        aux=aux->siguiente;
    }
    //if(strcmp(aux->elemento->Marca,dato)){
      //  suma++;
    //}
    return suma;

}


int main(){
    p_lista lista=crearLista();
    char color[20];
    float cantidad_color;


    leerArchivo(lista);

    imprimirLista(lista);

    cantidad_color=totalColor(lista);
    printf("Total Color:%f litros\n",cantidad_color);


    //printf("%i\n",totalLatasMarca(lista,"POLACRIN"));

    return 1;
}