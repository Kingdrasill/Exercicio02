#include "lista.h"

void FLVazia(Lista *lista) {
    lista->Primeiro = 0;
    lista->Ultimo = 0;
}

void Imprime(Lista *lista) {
    if(Vazia(lista))
        return;
    for(int i=0; i<lista->Ultimo; i++)
        printf("Nome %d: %s\n", i+1, lista->vet[i].value);
}

bool Vazia(Lista *lista) {
    if(lista->Primeiro == lista->Ultimo) {
        printf("LISTA VAZIA!\n");
        return true;
    }
    return false;
}

bool Cheia(Lista *lista) {
    if(lista->Ultimo >= MAXTAM) {
        printf("LISTA CHEIA!\n");
        return true;
    }
    return false;
}

bool Insere(Lista *lista, Item *d) {
    if(Cheia(lista)){
        return false;
	}else{
		strcpy(lista->vet[lista->Ultimo].value, d->value);
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
        p =  Procura(lista, d);
        if(p >= 0) {
            for(int i=p; i<=lista->Ultimo; i++) {
                lista->vet[i] = lista->vet[i+1];
            }
        }
        lista->Ultimo--;
    }
    return ok;
}

int Procura(Lista *lista, Item *d) {
    int p = -1;
    bool achou = false;
    for(int i=0; i<lista->Ultimo; i++) {
        if(strcmp(lista->vet[i].value, d->value) == 0) {
            p = i;
            achou = true;
        }
        if(achou)
            i=lista->Ultimo;
    }
    return p;
}