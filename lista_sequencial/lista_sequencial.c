#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "clientes.h"


int carregarPessoas(Pessoa listaPessoas[], int tamanhoMaximo, const char *nomeArquivo) {
    
    FILE *ponteiroDoArquivo = fopen(nomeArquivo, "r");
    
    if (ponteiroDoArquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return 0;
    }

    char linha[TAMANHO_MAX_LINHA];
    int contador = 0;

    while (contador < tamanhoMaximo && fgets(linha, sizeof(linha), ponteiroDoArquivo)) {
        char nome_temp[TAMANHO_MAX_NOME];
        char rg_string_temp[TAMANHO_MAX_RG_STR];

        if (sscanf(linha, "%99[^,],%14s", nome_temp, rg_string_temp) == 2) {
            strcpy(listaPessoas[contador].nome, nome_temp);
            listaPessoas[contador].rg = atol(rg_string_temp);
            contador++;
        }
    }

    fclose(ponteiroDoArquivo);
    return contador;
}

void mostrarLista(const Pessoa listaPessoas[], int totalPessoas) {

     printf("--- Lista de Pessoas ---\n\n");
     if (totalPessoas == 0) {
        printf("Nenhuma pessoa para exibir.\n");
        return;
     }

     for (int i = 0; i < totalPessoas; i++) {
        printf("Nome: %s\n", listaPessoas[i].nome);
        printf("RG:   %ld\n", listaPessoas[i].rg);
        printf("-----------------------------------\n");
     }
}
