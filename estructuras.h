#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

typedef struct lata {
    char Marca[20];
    char Color[20];
    float tamanio;
} Lata;

typedef struct nodo {
    Lata lata;
    struct nodo *siguiente;
}Nodo;

typedef struct lista {
    Nodo *raiz;
    Nodo *ultimo;
    int cantidad_nodos;
}Lista;

//enum status = {status_ok, status_fail};

#endif