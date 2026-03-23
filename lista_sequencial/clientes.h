#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_PESSOAS         50
#define TAMANHO_MAX_NOME    100
#define TAMANHO_MAX_RG_STR  15
#define TAMANHO_MAX_LINHA   128


typedef struct {
    char nome[TAMANHO_MAX_NOME];
    long int rg;
} Pessoa;

typedef struct {
    int comparacoes;
    int movimentacoes;
    double tempo;
    int posicao;
} Metricas;

int carregarPessoas(Pessoa listaPessoas[], int tamanhoMaximo, const char *nomeArquivo);

void mostrarLista(const Pessoa listaPessoas[], int totalPessoas);