#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> //funcion toupper
#include "estructuras.h"
#include "funciones.c"

int main() {
    Lata lata1, lata2, lata3;
    Nodo *nodo;
    Lista *lista;

    // Llenando datos para la lata1
    strcpy(lata1.Marca, "Marca1");
    strcpy(lata1.Color, "Rojo");
    lata1.tamanio = 355.0; // Suponiendo que el tamaño es de 355 ml

    // Llenando datos para la lata2
    strcpy(lata2.Marca, "Marca2");
    strcpy(lata2.Color, "Azul");
    lata2.tamanio = 500.0; // Suponiendo que el tamaño es de 500 ml

    // Llenando datos para la lata3
    //strcpy(lata3.Marca, "Marca3");
    //strcpy(lata3.Color, "Azul");
    //lata3.tamanio = 500.0; // Suponiendo que el tamaño es de 500 ml

    
    lista=crearLista();
    
    insertarFinal(lista,crearNodo(lata1));
    insertarFinal(lista,crearNodo(lata2));
    //insertarFinal(lista,crearNodo(lata3));
    
    imprimirLista(lista);

    return 0;
}

