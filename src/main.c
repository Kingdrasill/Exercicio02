#include "lista.h"

int main() {
    Lista l;
    Item i;
    strcpy(i.value, "Fulano");

    FLVazia(&l);
    Insere(&l, &i);
    Imprime(&l);
    Remove(&l, &i);
    Imprime(&l);

    return 0;
}