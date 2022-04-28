#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#define MAXTAM 100

typedef struct Item Item;
typedef struct Lista Lista;

struct Item
{
    int value;
};

struct Lista
{
    Item vet[MAXTAM];
    int Primeiro;
    int Ultimo;
};

void FLVazia(Lista *lista);

bool Vazia(Lista *lista);

bool Cheia(Lista *lista);

bool Insere(Lista *lista, Item *d);

bool Remove(Lista *lista, Item *d);

bool Procura(Lista *lista, Item *d, int *p);