#include "lista.h"

int main() {

    FILE *fp;
    Lista L;
    Item D;
    int aux, opt;
    char str[NOME_MAXTAM];
    char arquivo[FILE_MAXTAM];
    bool cont = true;
    FLVazia(&L);

    printf("Nome do arquivo onde esta os nomes iniciais: ");
	fgets(arquivo, FILE_MAXTAM-4, stdin);
	strtok(arquivo, "\n");
	strcat(arquivo, ".txt");

    fp = fopen(arquivo, "r");
    if (fp == NULL) {
        printf("\nErro!Nao foi possivel abrir o arquivo!\n");
        exit(1);
    } else {
        while(fgets(str, NOME_MAXTAM, fp) != NULL) {
            strtok(str, "\n");
            strtok(str, " ");
            D.ref = -1;
            strcpy(D.value, str);
            Insere(&L, &D);
        }
        NoRepeat(&L);
        printf("\nLista de nomes iniciais: \n\n");
        Imprime(&L);
    }
    fclose(fp);

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
                D.ref = -1;
                strcpy(D.value, str);
                Insere(&L, &D);
                NoRepeat(&L);
                break;

            case 2:
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

    fp = fopen(arquivo, "w+");
    if(fp != NULL) {
        for(int i=0; i<L.Ultimo; i++) {
            aux = L.vet[i].ref;
            fprintf(fp, "%s", L.vet[aux].value);
            if(i < L.Ultimo-1)
                fprintf(fp, "\n");
        }
    }
    fclose(fp);

    return 0;
}