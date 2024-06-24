#include "estructuras.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h> 
#include <stdlib.h>

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
/*elimina un nodo según el indice que reciba, luego, se libera la memoria*/
void eliminarNodo(p_lista lista,int indice){
    if(!estaVacia(lista)){
        p_nodo aux=lista->nodo;
        if(indice==0){
            lista->nodo=aux->siguiente;
        }else if(indice>=0 && indice<lista->cantidad_nodos-1){
            p_nodo anterior;
            for (int i=0;i<indice;i++){
                anterior=aux;
                aux=aux->siguiente;
            }
            anterior->siguiente=aux->siguiente;
        }else if(indice==lista->cantidad_nodos-1){
            for (int i=0;i<lista->cantidad_nodos-1;i++){
            aux=aux->siguiente;
        }
        }else{
            printf("El indice no correspondee\n");
            lista->cantidad_nodos++;/*está puesto de esta forma para que, si no corresponde el indice, contrarreste la reduccion de la cantidad total*/
        }
        lista->cantidad_nodos--;
        free(aux);
    }else{
        printf("La lista está vacia\n");
    }
}
/*cambia todos los caracteres a mayuscula*/
void mayuscula(char palabra[]){
    for (int i=0;i<strlen(palabra);i++){
        palabra[i]=toupper(palabra[i]);
    }
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
/*crea el nodo de la lista string*/
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
/*inserta el nodo string*/
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
/*imprime la lista de strings*/
void imprimirStr(p_lista_str lista){
    p_nodo_str aux=lista->nodo;
    while(aux!=NULL){
        printf("%s, ",aux->str);
        aux=aux->siguiente;
    }
    printf("\n");
}
/*revisa si un string esta en la lista*/
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
/*vacia la lista*/
void vaciarLista(p_lista lista){
    while(!estaVacia){
        eliminarNodo(lista,0);
}
}
/*vacia la lista de strings*/
void vaciarListaStr(p_lista_str listaStr){
    p_nodo_str aux;
    while(listaStr->nodo!=NULL){
        aux=listaStr->nodo;
        listaStr->nodo=listaStr->nodo->siguiente;
        free(aux);
    }
}
/*PUNTO 1
Lee el archivo, y luego almacena los tres primeros renglones con su reséctiva variable
luego cierra el archivo*/
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
/*PUNTO 3.A)
Añade una lata usando las funciones mayuscula, insertarnodo y crearnodo*/
void insertarNuevaLata(p_lista lista){
    char Marca[20];
    char Color[20];
    float tamanio;
    p_lata nueva_lata = (p_lata)malloc(sizeof(lata));
    printf("Ingrese la Marca: ");
    scanf("%s",Marca);
    mayuscula(Marca);
    printf("Ingrese el color: ");
    scanf("%s",Color);
    mayuscula(Color);
    printf("Ingrese el tamaño de la lata: ");
    scanf("%f",&tamanio);
    strcpy(nueva_lata->Marca, Marca);
    strcpy(nueva_lata->Color, Color);
    nueva_lata->tamanio = tamanio;
    insertarNodo(lista, crearNodo(nueva_lata));
}
/*PUNTO 3.B)
borra la lata usando la funcion mayuscula para que no haya problemas con el strcmp
y usando la funcion eliminarnodo, con  el indice necesario*/
void borrarLata(p_lista lista){
    char Marca[20];
    char Color[20];
    float tamanio;
    int indice=0;
    int encontrado=0;
    p_nodo aux=lista->nodo;
    printf("Ingrese la Marca: ");
    scanf("%s",Marca);
    mayuscula(Marca);
    printf("Ingrese el color: ");
    scanf("%s",Color);
    mayuscula(Color);
    printf("Ingrese el tamaño de la lata: ");
    scanf("%f",&tamanio); 
    while(aux!=NULL){
        if(((strcmp(aux->elemento->Color,Color))==0) &&
        ((strcmp(aux->elemento->Marca,Marca))==0)&&
        (aux->elemento->tamanio)==tamanio){
            encontrado=1;
            break;
        }else{
            indice++;
            aux=aux->siguiente;
        }
    }
    if(!encontrado){
        printf("Producto no encontrado\n");
    } else {
        eliminarNodo(lista,indice);
        printf("Producto removido!\n");
    }
}
/*Apartir de ahora todos tienen la funcion de guardar la entrada y la salida en un archivo
Esto se logra pidiendo el nombre del archivo por teclado, luego, dependiendo la funcion,
se usa el fprintf con la variable o variables a guardar
Tambien, se usan listas enlazadas para cuando se necesite almacenar varias marcas o pinturas.*/
/*PUNTO 3.C)*/
void disponibilidadColor(p_lista lista, char color[]){
    p_nodo aux=lista->nodo;
    p_nodo inicio=aux;
    int cantidad=0; 
    int opcion;
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
    printf("Desea guardarlo en un archivo?SI(1) NO(0)\n");
    scanf("%i",&opcion);
    if(opcion){
        aux=inicio;
        char nombreArchivo[24];
        printf("Ingrese el nombre del archivo(20 caracteres maximo y agregue el .txt): ");
        scanf("%s", nombreArchivo);
        FILE *archivo=fopen(nombreArchivo,"w");
        if(archivo==NULL){
            printf("Hubo un error al abrir el archivo\n");
        } else {
            fprintf(archivo,"Entrada: \n");
            fprintf(archivo,"Ingrese el color: %s\n",color);
            fprintf(archivo,"Salida: \n");
            if(cantidad==0){
                fprintf(archivo,"Color no disponible");
            }else{
                while(aux!=NULL){
                if((strcmp(aux->elemento->Color, color))==0){
                fprintf(archivo,"%s, %f litros\n",aux->elemento->Marca,aux->elemento->tamanio);
                }   
                aux=aux->siguiente;
                }
            }
            fclose(archivo);
        }
    }
}

/*PUNTO 3.D)*/
void verificarColorCantidad(p_lista lista, char color[],float cantidad){
    if(estaVacia(lista)){
        printf("LISTA VACIA\n");
    }else{
        p_nodo aux=lista->nodo;
        int opcion;
        p_lista_str listaMarca=crearListaStr();
        while(aux!=NULL){
            if(((strcmp(aux->elemento->Color,color))==0) && (aux->elemento->tamanio==cantidad)){
                if(!cadenaEnLista(listaMarca,aux->elemento->Marca)){
                    insertarNodoStr(listaMarca,crearNodoStr(aux->elemento->Marca));
                }
            }
            aux=aux->siguiente;
        }
        if(listaMarca->cantidad_nodos==0){
            printf("Stock no disponible\n");
        }
        printf("Marcas disponibles: ");
        imprimirStr(listaMarca);
        printf("Desea guardarlo en un archivo?SI(1) NO(0)\n");
        scanf("%i",&opcion);
        if(opcion){
            p_nodo_str auxStr=listaMarca->nodo;
            char nombreArchivo[24];
            printf("Ingrese el nombre del archivo(20 caracteres maximo y agregue el .txt): ");
            scanf("%s", nombreArchivo);
            FILE *archivo=fopen(nombreArchivo,"w");
            if(archivo==NULL){
                printf("Hubo un error al abrir el archivo\n");
            } else {
                fprintf(archivo,"Entrada: \n");
                fprintf(archivo,"Ingrese el color: %s\n",color);
                fprintf(archivo,"Ingrese el tamaño: %f\n",cantidad);
                fprintf(archivo,"Salida: \n");
                if(listaMarca->cantidad_nodos==0){
                    fprintf(archivo,"No hay stock\n");
                }else{
                    fprintf(archivo,"Marcas disponibles: ");
                    while(auxStr!=NULL){
                    fprintf(archivo,"%s, ",auxStr->str);
                    auxStr=auxStr->siguiente;
                    }
                }
                free(auxStr);
                fclose(archivo);
            }
    }
        vaciarListaStr(listaMarca);
    }
}
/*PUNTO 3.E)*/
void totalColor(p_lista lista, char color[]){
    int opcion;
    p_nodo aux=lista->nodo;
    p_lista_str listaMarca=crearListaStr();
    float totalcolor=0;
    int totalLatas=0;
    while(aux!=NULL){
        if((strcmp(aux->elemento->Color,color))==0){
            if(!cadenaEnLista(listaMarca,aux->elemento->Marca)){
                insertarNodoStr(listaMarca,crearNodoStr(aux->elemento->Marca));
            }
            totalcolor+=aux->elemento->tamanio;
            totalLatas++;
            }
            aux=aux->siguiente;
        }
    printf("Marcas: ");
    imprimirStr(listaMarca);
    printf("Total Color: %f\n",totalcolor);
    printf("Cantidad latas: %i\n",totalLatas); 
    printf("Desea guardarlo en un archivo?SI(1) NO(0)\n");
    scanf("%i",&opcion);
    if(opcion){
        p_nodo_str auxStr=listaMarca->nodo;
        char nombreArchivo[24];
        printf("Ingrese el nombre del archivo(20 caracteres maximo y agregue el .txt): ");
        scanf("%s", nombreArchivo);
        FILE *archivo=fopen(nombreArchivo,"w");
        if(archivo==NULL){
            printf("Hubo un error al abrir el archivo\n");
        } else {
            fprintf(archivo,"Entrada: \n");
            fprintf(archivo,"Ingrese el color: %s\n",color);
            fprintf(archivo,"Salida: \n");
            fprintf(archivo,"Marcas: ");
            while(auxStr!=NULL){
            fprintf(archivo,"%s, ",auxStr->str);
            auxStr=auxStr->siguiente;
            }
            fprintf(archivo,"\nTotal Color: %f\n",totalcolor);
            fprintf(archivo,"Cantidad latas: %i",totalLatas);
        }
        free(auxStr);
        fclose(archivo);
    }
    vaciarListaStr(listaMarca);
}

/*PUNTO 3.F)*/
void totalLatasMarca(p_lista lista, char marca[]){
    int opcion;
    p_nodo aux;
    int cantidadLatas=0;
    p_lista_str listaColor=crearListaStr();
    aux=lista->nodo;
    while(aux!=NULL){
        if((strcmp(aux->elemento->Marca,marca))==0){
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
    printf("Desea guardarlo en un archivo?SI(1) NO(0)\n");
    scanf("%i",&opcion);
    if(opcion){
        p_nodo_str auxStr=listaColor->nodo;
        char nombreArchivo[24];
        printf("Ingrese el nombre del archivo(20 caracteres maximo y agregue el .txt): ");
        scanf("%s", nombreArchivo);
        FILE *archivo=fopen(nombreArchivo,"w");
        if(archivo==NULL){
            printf("Hubo un error al abrir el archivo\n");
        } else {
                    fprintf(archivo,"Entrada: \n");
            fprintf(archivo,"Ingrese el color: %s\n",marca);
            fprintf(archivo,"Salida: \n");
            fprintf(archivo,"Marcas: ");
            while(auxStr!=NULL){
            fprintf(archivo,"%s, ",auxStr->str);
            auxStr=auxStr->siguiente;
            }
            fprintf(archivo,"\nCantidad latas: %i",cantidadLatas);
        }
        free(auxStr);
        fclose(archivo);
    }
    vaciarListaStr(listaColor);
}
/*PUNTO 3.G)*/
void totalLatasMarcaColor(p_lista lista,char Marca[],char Color[]){
    int opcion;
    p_nodo aux=lista->nodo;
    int cantidadLatas=0;
    float cantidadColor=0;
    while(aux!=NULL){
        if(((strcmp(aux->elemento->Marca,Marca))==0)&&
        ((strcmp(aux->elemento->Color,Color))==0)){/*strcmp devuelve 0 cuando las cadenas son iguales*/
                cantidadLatas++;
                cantidadColor+=aux->elemento->tamanio;
            }  
        aux=aux->siguiente;
    }
    printf("Cantidad de litros: %f\n",cantidadColor);
    printf("Cantidad de latas: %i\n",cantidadLatas);
        printf("Desea guardarlo en un archivo?SI(1) NO(0)\n");
    scanf("%i",&opcion);
    if(opcion){
        char nombreArchivo[24];
        printf("Ingrese el nombre del archivo(20 caracteres maximo y agregue el .txt): ");
        scanf("%s", nombreArchivo);
        FILE *archivo=fopen(nombreArchivo,"w");
        if(archivo==NULL){
            printf("Hubo un error al abrir el archivo\n");
        } else {
            fprintf(archivo,"Entrada: \n");
            fprintf(archivo,"Ingrese la marca: %s\n",Marca);
            fprintf(archivo,"Ingrese el color: %s\n",Color);
            fprintf(archivo,"Salida: \n");
            fprintf(archivo,"Cantidad de litros: %f\n",cantidadColor);
            fprintf(archivo,"Cantidad de latas: %i\n",cantidadLatas);
        }
        fclose(archivo);
    }
}

