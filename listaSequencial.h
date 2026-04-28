#ifndef LISTA_SEQUENCIAL_H
#define LISTA_SEQUENCIAL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>

#define MAX_PESSOAS         12000000
#define TAMANHO_MAX_NOME    100
#define TAMANHO_MAX_LINHA   128
#define NOME_ARQUIVO        "NomeRG10.txt"

typedef struct {
    char nome[TAMANHO_MAX_NOME];
    long int rg;
} Pessoa;

typedef struct {
    int mov;
    int comp;
} Metricas;

void limparTela();

void pausaTela();

double tempoPercorrido(clock_t inicio, clock_t fim);

int carregarPessoas(Pessoa lista[], int *tamanho, const char *nomeArquivo);

void menuOrdenacao(Pessoa *lista, int *tamanho);
void selectionSort(Pessoa *lista, int tamanho);
void insertionSort(Pessoa *lista, int tamanho);
void bubbleSort(Pessoa *lista, int tamanho);

void lerPessoaTeclado(char *nome, long int *rg);
void menuInsercao(Pessoa *lista, int *tamanho);
void inserir(Pessoa *lista, int *tamanho, int indice);
void menuRemocao(Pessoa *lista, int *tamanho);
void remover(Pessoa *lista, int *tamanho, int indice);

void mostrarLista(const Pessoa lista[], int tamanho);

void buscaRG(Pessoa *lista, int tamanho);

void salvarLista(Pessoa *lista, int tamanho);

void liberaLista(Pessoa *lista);

#endif
