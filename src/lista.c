#include "lista.h"

void FLVazia(Lista *lista) {
    lista->Primeiro = 0;
    lista->Ultimo = 0;
}

void Imprime(Lista *lista) {

    if(lista->Primeiro == lista->Ultimo) {
        printf("LISTA VAZIA!\n");
        return;
    }
    for(int i=0; i<lista->Ultimo; i++) {
        if(lista->vet[i].rep != -1) {
            printf("%s\tRepeticoes %d\n", lista->vet[i].value, lista->vet[i].rep);
        }
    }
}

bool Insere(Lista *lista, Item *d) {
    if(lista->Ultimo >= MAXTAM) {
        printf("LISTA CHEIA!\n");
        return false;
    } 
    
	strcpy(lista->vet[lista->Ultimo].value, d->value);
    lista->vet[lista->Ultimo].rep = 0;
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
    
    for(int i=(lista->Ultimo-1); i>=0; i--){
        if(strcmp(lista->vet[i].value,d->value) == 0) {
            aux = i;
            ok = true;
            i = -1;
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

void NoRepeat(Lista *l) {
    for(int i=0; i<l->Ultimo; i++) {
        if(!(strcmp(l->vet[i].value, "") == 0)) {
            RemoveRepetition(l, &l->vet[i], i);
        }
    }
}

void RemoveRepetition(Lista *l, Item *d, int pos) {
    for(int i=(pos+1); i<l->Ultimo; i++) {
        if(strcmp(d->value, l->vet[i].value) == 0) {
            d->rep++;
            strcpy(l->vet[i].value, "");
            l->vet[i].rep = -1;
        }
    }
}

bool LerArquivo(Lista *l) {
    FILE *fp;
    Item D;
    char str[NOME_MAXTAM];
    char arquivo[FILE_MAXTAM];

    printf("Nome do arquivo onde esta os nomes iniciais(com extensao): ");
	fgets(arquivo, FILE_MAXTAM, stdin);
	strtok(arquivo, "\n");

    fp = fopen(arquivo, "r");
    if (fp == NULL) {
        printf("\nErro!Nao foi possivel abrir o arquivo!\n");
        exit(1);
    } else {
        while(fgets(str, NOME_MAXTAM, fp) != NULL) {
            strtok(str, "\n");
            strcpy(D.value, str);
            Insere(l, &D);
        }
        printf("\nLista de nomes iniciais: \n\n");
        Imprime(l);
    }
    fclose(fp);
    return true;
}