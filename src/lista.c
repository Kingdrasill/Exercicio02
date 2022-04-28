#include "lista.h"

void FLVazia(Lista *lista) {
    lista->Primeiro = 0;
    lista->Ultimo = 0;
}

bool Vazia(Lista *lista) {
    if(lista->Primeiro == lista->Ultimo) {
        printf("LISTA VAZIA!");
        return true;
    }
    return false;
}

bool Cheia(Lista *lista) {
    if(lista->Ultimo >= MAXTAM) {
        printf("LISTA CHEIA!");
        return true;
    }
    return false;
}

bool Insere(Lista *lista, Item *d) {
    if(Cheia(lista)){
        return false;
	}else{
		lista->vet[lista->Ultimo].value = d->value;
		lista->Ultimo++;
        return true;
	}
}

bool Remove(Lista *lista, Item *d) {
    bool ok = false;
    int p;
    if(Vazia(lista)) {
        return ok;
    } else {
        ok = Procura(lista, d, &p);
        if(ok) {
            for(int i=p; i<=lista->Ultimo; i++) {
                lista->vet[i] = lista->vet[i+1];
            }
        }
    }
    return ok;
}

bool Procura(Lista *lista, Item *d, int *p) {
    bool achou = false;
    for(int i=0; i<lista->Ultimo; i++) {
        if(lista->vet[i].value == d->value) {
            *p = i;
            achou = true;
        }
    }
    return achou;
}