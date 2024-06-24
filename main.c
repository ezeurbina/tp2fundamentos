#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 
#include "estructuras.h"
#include "funciones.c"


void menu(){
    printf("a) Agregar producto\n");
    printf("b) Remover producto\n");
    printf("c) Verificar disponibilidad\n");
    printf("d) Verificar color y cantidad\n");
    printf("e) Total color\n");
    printf("f) Total Marca\n");
    printf("g) Total por Marca y color\n");
    printf("h) Salir\n");
}

int opcion_valida (char opcion){
    char opciones_validas[8]= {'a','b','c','d','e','f','g','h'};
    for (int i=0;i<8;i++){
        if(opcion == opciones_validas[i]){
            return 1;
        }
    }
    return 0;
}

int main(){
    p_lista lista=crearLista();
    int seguir=1;
    char opcion;

    leerArchivo(lista);

    while(seguir==1){
        char Marca[20];
        char Color[20];
        float tamanio;
        menu();
        scanf(" %c",&opcion);
        if(opcion_valida(opcion)){
            switch(opcion){
                case 'a': 
                    insertarNuevaLata(lista);
                    break;
                
                case 'b': 
                    borrarLata(lista);
                    break;
                
                case 'c':
                    printf("Ingrese el color: ");
                    scanf("%s",Color);
                    mayuscula(Color);
                    disponibilidadColor(lista,Color);
                    break;

                case 'd':
                    printf("Ingrese el color: ");
                    scanf("%s",Color);
                    mayuscula(Color);
                    printf("Ingrese la cantidad: ");
                    scanf("%f",&tamanio);
                    verificarColorCantidad(lista,Color,tamanio);
                    break;

                case 'e':
                    printf("Ingrese el color: ");
                    scanf("%s",Color);
                    mayuscula(Color);
                    totalColor(lista,Color);
                    break;

                case 'f':
                    printf("Ingrese la marca: ");
                    scanf("%s",Marca);
                    mayuscula(Marca);
                    totalLatasMarca(lista,Marca);
                    break;


                case 'g':
                    printf("Ingrese la marca: ");
                    scanf("%s",Marca);
                    mayuscula(Marca);
                    printf("Ingrese el color: ");
                    scanf("%s",Color);
                    mayuscula(Color);
                    totalLatasMarcaColor(lista,Marca,Color);
                    break;

                case 'h': 
                    seguir=0;
                    break;
                
                default:
                    break;
                    
            } 
        }else{
            printf("OPCION INVALIDA\n");
        }

    }

    vaciarLista(lista);
    
    return 0;
}