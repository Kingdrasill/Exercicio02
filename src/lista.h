#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAXTAM 100
#define NOME_MAXTAM 30
#define FILE_MAXTAM 50

typedef struct Item Item;
typedef struct Lista Lista;

struct Item
{
    char value[NOME_MAXTAM];
    int ref;
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

void NoRepeat(Lista *lista);

bool FindRepetition(Lista *l, Item d);