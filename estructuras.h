#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

struct nodo;
typedef struct nodo* p_nodo;

struct lata;
typedef struct lata* p_lata;

struct nodo_str;
typedef struct nodo_str* p_nodo_str;

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

typedef struct nodo_str {
    char str[20];
    p_nodo_str siguiente;
} nodo_str, *p_nodo_str;

typedef struct lista_str {
p_nodo_str nodo;
int cantidad_nodos;
} lista_str, *p_lista_str;


#endif