#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> //funcion toupper
#include "estructuras2.h"
#include "funciones2.c"

int main() {
    lata lata1_data = {"Marca1", "Rojo", 355.0};
    lata lata2_data = {"Marca2", "Azul", 500.0};
    p_lata lata1 = &lata1_data;
    p_lata lata2 = &lata2_data;

    imprimirNodo(crearNodo(lata1));

    imprimirNodo(crearNodo(lata2));
    
    


    return 0;
}