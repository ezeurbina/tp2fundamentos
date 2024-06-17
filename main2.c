#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> //funcion toupper
#include "estructuras2.h"
#include "funciones2.c"

int main() {
    p_lista lista=crearLista();

    lata lata1_data = {"Marca1", "Rojo", 355.0};
    lata lata2_data = {"Marca2", "Azul", 500.0};
    lata lata3_data = {"Marca3", "Verde", 235.0};
    lata lata4_data = {"Marca4", "Violeta", 400.0};
    p_lata lata1 = &lata1_data;
    p_lata lata2 = &lata2_data;
    p_lata lata3 = &lata3_data;
    p_lata lata4 = &lata4_data;
    //imprimirNodo(crearNodo(lata1));
    //imprimirNodo(crearNodo(lata2));

    insertarNodo(lista,crearNodo(lata1));
    insertarNodo(lista,crearNodo(lata2));
    insertarNodo(lista,crearNodo(lata3));
    insertarNodo(lista,crearNodo(lata4));

    imprimirLista(lista);
    eliminarNodo(lista,1);
    imprimirLista(lista);

    return 0;
}