#include "lista.h"

int main() {

    Lista L;
    Item D;
    char str[NOME_MAXTAM];
    bool cont = true;
    int opt;
    FLVazia(&L);

    if(!LerArquivo(&L)) {
        exit(1);
    }
    NoRepeat(&L);
    printf("\nLista de nomes com repeticoes retiradas: \n\n");
    Imprime(&L);

    while(cont) {
        printf("\n1 - Inserir nome na lista\n");
        printf("2 - Remover ultimo nome da lista\n");
        printf("3 - Imprimir lista\n");
        printf("4 - Sair\n");
        printf("\nOpcao: ");
        scanf("%d", &opt);

        switch(opt) {
            case 1:
                printf("\nNome a ser inserido: ");
                scanf("%c", (char *) stdin);
                fgets(str, NOME_MAXTAM, stdin);
                strtok(str, "\n");
                strtok(str, " ");
                strcpy(D.value, str);
                Insere(&L, &D);
                NoRepeat(&L);
                break;

            case 2:
                printf("\nNome a ser removido(Se for repetido a ultima aparicao dele sera apagada): ");
                scanf("%c", (char *) stdin);
                fgets(str, NOME_MAXTAM, stdin);
                strtok(str, "\n");
                strtok(str, " ");
                strcpy(D.value, str);
                Remove(&L, &D);
                break;

            case 3:
                printf("\nLista de nomes: \n\n");
                Imprime(&L);
                break;

            case 4:
                cont = false;
                break;

            default:
                printf("\nOpcao nao existe!\n");
                break;
        }
    }

    return 0;
}