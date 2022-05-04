#include "lista.h"

int main() {

    FILE *fp;
    Lista L;
    Item D;
    char str[NOME_MAXTAM];
    char arquivo[FILE_MAXTAM];

    printf("Nome do arquivo onde esta os nomes: ");
	fgets(arquivo, FILE_MAXTAM-4, stdin);
	strtok(arquivo, "\n");
	strcat(arquivo, ".txt");

    fp = fopen(arquivo, "r");
    if(fp != NULL) {
        while(fgets(str, NOME_MAXTAM, fp) != NULL) {
            strtok(str, '\n');
            strtok(str, ' ');
            strcpy(D.value, str);
            Insere(&L, &D);
        }
    }
    fclose(fp);

    Imprime(&L);

    return 0;
}