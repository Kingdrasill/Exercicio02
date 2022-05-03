#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAXTAM 100

typedef struct Item Item;
typedef struct Lista Lista;

struct Item
{
    char value[20];
};

struct Lista
{
    Item vet[MAXTAM];
    int Primeiro;
    int Ultimo;
};

void FLVazia(Lista *lista);

void Imprime(Lista *lista);

bool Insere(Lista *lista, Item *d);

bool Remove(Lista *lista, Item *d);