#include "lista.h"

void FLVazia(Lista *lista) {
    lista->Primeiro = 0;
    lista->Ultimo = 0;
}

void Imprime(Lista *lista) {
    int aux;

    if(lista->Primeiro == lista->Ultimo) {
        printf("LISTA VAZIA!\n");
        return;
    }
    for(int i=0; i<lista->Ultimo; i++) {
        aux = lista->vet[i].ref;
        printf("Nome %d: %s\n", i+1, lista->vet[aux].value);
    }
}

bool Insere(Lista *lista, Item *d) {
    if(lista->Ultimo >= MAXTAM) {
        printf("LISTA CHEIA!\n");
        return false;
    } 
    
    lista->vet[lista->Ultimo].ref = lista->Ultimo;
	strcpy(lista->vet[lista->Ultimo].value, d->value);
	lista->Ultimo++;
    return true;
}

bool Remove(Lista *lista, Item *d) {
    bool ok = false;
    int aux;

    if(lista->Primeiro == lista->Ultimo) {
        printf("LISTA VAZIA!\n");
        return false;
    }
    
    for(int i=0; i<lista->Ultimo; i++){
        if(strcmp(lista->vet[i].value,d->value) == 0) {
            aux = i;
            ok = true;
            i = lista->Ultimo;
        }
    }

    if(ok){
        for(int i=aux; i<=lista->Ultimo; i++) {
            lista->vet[i] = lista->vet[i+1];
        }
        lista->Ultimo--;
    }
    
    return ok;
}

void NoRepeat(Lista *lista) {
    Item aux;
    
    for(int i=0; i<lista->Ultimo; i++) {
        aux = lista->vet[i];

        if(FindRepetition(lista, aux)) {
            for(int j=(i+1); j<lista->Ultimo; j++) {
                if(!(strcmp("", aux.value) == 0) && strcmp(lista->vet[j].value, aux.value) == 0) {
                    strcpy(lista->vet[j].value, "");
                    lista->vet[j].ref = aux.ref;
                }
            }
        }
    }
}

bool FindRepetition(Lista *l, Item d) {
    bool ok = false;

    for(int i=d.ref; i<l->Ultimo; i++) {
        if(strcmp(l->vet[i].value, d.value) == 0) {
            ok = true;
            i = l->Ultimo;
        }
    }
    return ok;
}