#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> //funcion toupper
#include "estructuras.h"
#include "funciones.c"


int main(){
    p_lista lista=crearLista();
    char color[20];
    char marcaBuscada[] = "NEGRONI";
    float cantidad_color;


    leerArchivo(lista);

    imprimirLista(lista);

    cantidad_color=totalColor(lista,"NEGRO");
    printf("Total Color:%f litros\n",cantidad_color);


    printf("%i\n",totalLatasMarca(lista,marcaBuscada));

    return 1;
}