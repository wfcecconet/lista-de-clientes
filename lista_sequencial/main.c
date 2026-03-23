#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "clientes.h"

#define MAX_PESSOAS         50
#define TAMANHO_MAX_NOME    100
#define TAMANHO_MAX_RG_STR  15
#define TAMANHO_MAX_LINHA   128

int main() {
    Pessoa minhaLista[MAX_PESSOAS];
    
    int totalCarregado = carregarPessoas(minhaLista, MAX_PESSOAS, "dados_rg.txt");

    mostrarLista(minhaLista, totalCarregado);

    return 0;
}