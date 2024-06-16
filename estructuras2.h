#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

typedef struct lista {
p_nodo nodo;
int cantidad_nodos;
} lista, *p_lista;


typedef struct nodo {
p_lata elemento;
p_nodo siguiente;
} nodo, *p_nodo;


typedef struct lata {
char Marca[20];
char Color[20];
float tamanio;
} lata, *p_lata;

#endif