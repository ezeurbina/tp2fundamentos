#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> //funcion toupper
#include "estructuras.h"
#include "funciones.c"


int main(){
    p_lista lista=crearLista();
    char color[20];
    float cantidad_color;


    leerArchivo(lista);

    //imprimirLista(lista);

    //insertarNuevaLata(lista);

    //cantidad_color=totalColor(lista,"ROSA");
    //printf("Total Color:%f litros\n",cantidad_color);


    //printf("%i\n",totalLatasMarca(lista,"COLORIN"));

    //disponibilidadColor(lista,"BLANCO");

    //verificarColorCantidad(lista,"BLANCO",0.5);

    /*free listas*/
    //totalColor(lista,"NEGRO");

    totalLatasMarca(lista,"ALBA");

    return 1;
}