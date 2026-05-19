#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>
#include "lista_sequencial.h"


Metricas contador = {0, 0};

void limparTela(){

    system("cls");
}

void pausaTela(){

    while(getchar() != '\n');
    printf("Aperte ENTER para retornar...\n");
    getchar();
}

double tempoPercorrido(clock_t inicio, clock_t fim){

    return (double)(fim - inicio) / CLOCKS_PER_SEC;
}

void lerPessoaTeclado(char *nome, long int *rg){

    printf("Digite o nome: ");
    scanf(" %99[^\n]", nome);
    printf("Digite o RG: ");
    scanf("%ld", rg);
}

int carregarPessoas(Pessoa lista[], int *tamanho, const char *nomeArquivo){

    FILE *ponteiroDoArquivo = fopen(nomeArquivo, "r");

    if(ponteiroDoArquivo==NULL) {
        perror("Erro ao abrir o arquivo");
        return 0;
    }

    char nome[TAMANHO_MAX_NOME];
    long int rg;

    while(fscanf(ponteiroDoArquivo, " %99[^,],%ld", nome, &rg) == 2){
        if(*tamanho >= MAX_PESSOAS){
            printf("Lista cheia. Não foi possível carregar todos os registros\n");
            break;
        }
        strcpy(lista[*tamanho].nome, nome);
        lista[*tamanho].rg = rg;
        (*tamanho)++;
    }

    fclose(ponteiroDoArquivo);
    printf("Tamanho atual da lista: %d\n\n", *tamanho);
    pausaTela();
    return *tamanho;
}

void menuOrdenacao(Pessoa *lista, int *tamanho){

    int opcao;
    //teste de atualização
    printf("ORDENAÇÃO DE DADOS\n");
    printf("1 - Selection sort\n");
    printf("2 - Insertion sort\n");
    printf("3 - Bubble sort\n");
    printf("4 - Shell sort\n");
    printf("5 - Quick sort\n");
    printf("6 - Merge sort\n");
    scanf("%d", &opcao);
    limparTela();

    switch(opcao){
        case 1:
            selectionSort(lista, *tamanho);
            break;
        case 2:
            insertionSort(lista, *tamanho);
            break;
        case 3:
            bubbleSort(lista, *tamanho);
            break;
        case 4:
            shellSort(lista, *tamanho);
            break;
        case 5:
            contador.comp = 0;
            contador.mov = 0;
            clock_t Begin, End;
            Begin = clock();
            quickSort(lista, 0, (*tamanho)-1);
            End = clock();
            printf("Operação finalizada com sucesso!\n\n");
            printf("Comparações C(n): %d\n", contador.comp);
            printf("Movimentações M(n): %d\n", contador.mov);
            printf("Tempo de execução: %fs\n", tempoPercorrido(Begin, End));
            break;
        case 6:
            contador.comp = 0;
            contador.mov = 0;
            Begin = clock();
            mergeSort(lista, 0, (*tamanho)-1);
            End = clock();
            printf("Operação finalizada com sucesso!\n\n");
            printf("Comparações C(n): %d\n", contador.comp);
            printf("Movimentações M(n): %d\n", contador.mov);
            printf("Tempo de execução: %fs\n", tempoPercorrido(Begin, End));
            break;
        default:
            printf("Opção inválida\n");
            break;

    }
    pausaTela();
}

void selectionSort(Pessoa *lista, int tamanho){
    contador.comp = 0;
    contador.mov = 0;
    clock_t inicio, fim;

    inicio = clock();

    contador.comp++;
    if (tamanho == 0){
        printf("Erro: A lista está vazia!\n");
        return;
    }


    int i, j, min_idx;
    Pessoa temp;

    for(i=0; i<(tamanho-1); i++){
        contador.comp++;
        min_idx = i;

        for(j=i+1; j<tamanho; j++){
            contador.comp++;
            if(lista[j].rg < lista[min_idx].rg){
                min_idx = j;

            }
            contador.comp++;
        }
        contador.comp++;
        temp = lista[i];
        lista[i] = lista[min_idx];
        lista[min_idx] = temp;
        contador.mov+=3;
    }
    contador.comp++;
    fim = clock();

    printf("Operação finalizada com sucesso!\n\n");
    printf("Comparações C(n): %d\n", contador.comp);
    printf("Movimentações M(n): %d\n", contador.mov);
    printf("Tempo de execução: %fs\n", tempoPercorrido(inicio, fim));
}

void insertionSort(Pessoa *lista, int tamanho){
    contador.comp = 0;
    contador.mov = 0;
    clock_t inicio, fim;

    inicio = clock();

    contador.comp++;
    if (tamanho == 0){
        printf("Erro: A lista está vazia!\n");
        return;
    }

    int i, j;
    Pessoa chave;

    for(i=1; i<tamanho; i++){
        contador.comp++;
        chave = lista[i];
        contador.mov++;
        j = i-1;

        while(j>=0 && lista[j].rg > chave.rg){
            contador.comp+=2;
            lista[j+1] = lista [j];
            contador.mov++;
            j--;
        }
        contador.comp+=2;
        lista[j+1] = chave;
        contador.mov++;
    }
    contador.comp++;
    fim = clock();
    printf("Operação finalizada com sucesso!\n\n");
    printf("Comparações C(n): %d\n", contador.comp);
    printf("Movimentações M(n): %d\n", contador.mov);
    printf("Tempo de execução: %fs\n", tempoPercorrido(inicio, fim));
}

void bubbleSort(Pessoa *lista, int tamanho){
    contador.comp = 0;
    contador.mov = 0;
    clock_t inicio, fim;
    inicio = clock();

    if (tamanho == 0){
        printf("Erro: A lista está vazia!\n");
        return;
    }
    contador.comp++;

    int i, j, trocou;
    Pessoa temp;

    for(i=0; i<(tamanho-1); i++){
        contador.comp++;
        trocou = 0;
        for(j=0; j<(tamanho-i-1); j++){
            contador.comp++;
            if(lista[j].rg > lista[j+1].rg){
                contador.comp++;
                temp = lista[j];
                lista[j] = lista[j+1];
                lista[j+1] = temp;
                contador.mov+=3;
                trocou = 1;
            }
        contador.comp++;
        }
        contador.comp++;
        if(trocou == 0){
            contador.comp++;
            break;
        }
        contador.comp++;
    }
    fim = clock();
    printf("Operação finalizada com sucesso!\n\n");
    printf("Comparações C(n): %d\n", contador.comp);
    printf("Movimentações M(n): %d\n", contador.mov);
    printf("Tempo de execução: %fs\n", tempoPercorrido(inicio, fim));
}

void shellSort(Pessoa *lista, int tamanho){
    contador.comp = 0;
    contador.mov = 0;
    clock_t inicio, fim;
    inicio = clock();

    int gap, i,j;
    Pessoa temp;

    for(gap = tamanho/2; gap > 0; gap /= 2){
        contador.comp++;
        for(i=gap; i<tamanho; i++){
            contador.comp++;
            temp = lista[i];
            contador.mov++;
            for(j=i; j >= gap && lista[j-gap].rg > temp.rg; j-=gap){
                contador.comp++;
                lista[j] = lista[j-gap];
                contador.mov++;
            }
            contador.comp++;
            lista[j] = temp;
            contador.mov++;
        }
        contador.comp++;
    }
    contador.comp++;

    fim = clock();
    printf("Operação finalizada com sucesso!\n\n");
    printf("Comparações C(n): %d\n", contador.comp);
    printf("Movimentações M(n): %d\n", contador.mov);
    printf("Tempo de execução: %fs\n", tempoPercorrido(inicio, fim));
}

int particiona(Pessoa *lista, int baixo, int alto){

    Pessoa pivo = lista[(baixo+alto)/2];
    int i = baixo - 1;
    int j = alto + 1;
    while(1){
        do{i++;} while(lista[i].rg < pivo.rg);
        do{j--;} while(lista[j].rg > pivo.rg);
        contador.comp+=2;
        if(i>=j){
            contador.comp++;
            return j;
        }
        troca(&lista[i], &lista[j]);
        contador.comp++;
    }
    contador.comp++;
}

void troca (Pessoa *a, Pessoa *b){
    Pessoa temp = *a;
    *a = *b;
    *b = temp;
    contador.mov+=3;
}

void quickSort(Pessoa *lista, int baixo, int alto){

    if(baixo < alto){
        contador.comp++;
        int p = particiona(lista, baixo, alto);
        quickSort(lista, baixo, p);
        quickSort(lista, p+1, alto);
    }
    contador.comp++;

}

void merge(Pessoa *lista, int e, int m, int d){

    int n1 = m - e + 1;
    int n2 = d - m;
    Pessoa *E = (Pessoa*) malloc (n1*sizeof(Pessoa));
    Pessoa *D = (Pessoa*) malloc (n2*sizeof(Pessoa));
    contador.mov+=2;

    if(E == NULL || D == NULL){
        contador.comp+=2;
        printf("Não foi possível alocar subvetores!");
        exit(1);
    }
    contador.comp+=2;
    for(int i = 0; i < n1; i++){
        contador.comp++;
        E[i] = lista[e+i];
        contador.mov++;
    }
    contador.comp++;
    for(int j = 0; j < n2; j++){
        contador.comp++;
        D[j] = lista[m+1+j];
        contador.mov++;
    }
    contador.comp++;


    int i = 0, j = 0, k = e;
    while(i < n1 && j < n2){
        contador.comp++;
        if(E[i].rg <= D[j].rg){
            contador.comp++;
            lista[k++] = E[i++];
            contador.mov++;
        }
        else{
            contador.comp++;
            lista[k++] = D[j++];
            contador.mov++;
        }
    }
    contador.comp++;

    while(i<n1){
        contador.comp++;
        lista[k++] = E[i++];
        contador.mov++;
    }
    contador.comp++;
    while(j<n2){
        contador.comp++;
        lista[k++] = D[j++];
        contador.mov++;
    }
    contador.comp++;

    free(E);
    free(D);
    contador.mov+=2;
}


void mergeSort(Pessoa *lista, int e, int d){

    if(e < d){
        contador.comp++;
        int m = e + (d - e) / 2;
        mergeSort(lista, e, m);
        mergeSort(lista, m+1, d);
        merge(lista, e, m, d);
    }
    contador.comp++;
}

void inserir(Pessoa *lista, int *tamanho, int indice){

    contador.comp = 0;
    contador.mov = 0;
    clock_t inicio, fim;

    if(*tamanho >= MAX_PESSOAS){
        printf("A lista está cheia\n");
        pausaTela();
        return;
    }
    contador.comp++;

    char nome[TAMANHO_MAX_NOME];
    long int rg;

    lerPessoaTeclado(nome, &rg);

    inicio = clock();

    for(int i = *tamanho; i>indice; i--){
        lista[i] = lista[i-1];
        contador.mov++;
        contador.comp++;
    }
    contador.comp++;

    strcpy(lista[indice].nome, nome);
    lista[indice].rg = rg;
    (*tamanho)++;

    fim = clock();

    limparTela();
    printf("Nome: %s\n", lista[indice].nome);
    printf("RG: %ld\n", lista[indice].rg);
    printf("Comparações C(n): %d\n", contador.comp);
    printf("Movimentações M(n): %d\n", contador.mov);
    printf("Tempo de execução: %fs\n", tempoPercorrido(inicio, fim));
    printf("Posição na lista: %d\n\n", indice);
    pausaTela();
}

void menuInsercao(Pessoa *lista, int *tamanho){

    int opcao, indice;

    printf("INSERÇÃO\n");
    printf("1 - Inserir no ií�cio\n");
    printf("2 - Inserir no final\n");
    printf("3 - Escolher outro indíce\n");
    scanf("%d", &opcao);
    limparTela();

    switch (opcao) {
        case 1:
            inserir(lista, tamanho, 0);
            break;
        case 2:
            inserir(lista, tamanho, (*tamanho));
            break;
        case 3:
            if(*tamanho == 0) {
                printf("Lista vazia. Insira no início ou no final.\n");
                pausaTela();
                break;
            }
            printf("Tamanho atual: %d\nDigite o índice (1 a %d): ", (*tamanho), (*tamanho)-1);
            scanf("%d", &indice);
            if(indice <= 0 || indice >= *tamanho) {
                printf("Índice inválido.\n");
                pausaTela();
                break;
            }
            inserir(lista, tamanho, indice);
            break;
        default:
            printf("Opção inválida\n");
            pausaTela();
    }
}

void remover(Pessoa *lista, int *tamanho, int indice){

    contador.comp = 0;
    contador.mov = 0;
    clock_t inicio, fim;

    if(*tamanho <= 0) {
        printf("Lista vazia\n");
        pausaTela();
        return;
    }
    contador.comp++;

    inicio = clock();

    for(int i=indice; i<(*tamanho)-1; i++){
        lista[i] = lista[i+1];
        contador.mov++;
        contador.comp++;
    }
    contador.comp++;

    (*tamanho)--;

    fim = clock();

    limparTela();

    printf("Elemento removido com sucesso\n");
    printf("Comparações C(n): %d\n", contador.comp);
    printf("Movimentações M(n): %d\n", contador.mov);
    printf("Tempo de execução: %fs\n", tempoPercorrido(inicio, fim));
    pausaTela();
}

void menuRemocao(Pessoa *lista, int *tamanho){
    int opcao, indice;

    printf("REMOÇÃO\n");
    printf("1 - Remover do início\n");
    printf("2 - Remover do final\n");
    printf("3 - Escolher outro índice\n");
    scanf("%d", &opcao);
    limparTela();

    switch(opcao) {
        case 1:
            remover(lista, tamanho, 0);
            break;
        case 2:
            remover(lista, tamanho, *tamanho - 1);
            break;
        case 3:
            if ((*tamanho)==0) {
                printf("Lista vazia\n");
                pausaTela();
                break;
            }
            printf("Tamanho atual: %d\nDigite o índice (1 a %d): ", (*tamanho), (*tamanho)-1);
            scanf("%d", &indice);
            if (indice<0 || indice>=(*tamanho)) {
                printf("Indice invalido\n");
                pausaTela();
                break;
            }
            remover(lista, tamanho, indice);
            break;
        default:
            printf("Opção inválida\n");
            pausaTela();
    }
}

void mostrarLista(const Pessoa lista[], int tamanho){
    printf("--- Lista de Pessoas ---\n\n");
    if (tamanho == 0) {
        printf("Nenhuma pessoa para exibir.\n");
        pausaTela();
        return;
    }
    for (int i = 0; i < tamanho; i++) {
        printf("Posição %d\n", i);
        printf("Nome: %s\n", lista[i].nome);
        printf("RG:   %ld\n\n", lista[i].rg);
    }
    pausaTela();
}

void menuBusca(Pessoa *lista, int tamanho){
    int opcao;

    printf("BUSCA\n");
    printf("1 - Busca sequencial\n");
    printf("2 - Busca binária\n");
    scanf("%d", &opcao);
    limparTela();

    switch(opcao) {
        case 1:
            buscaRG(lista, tamanho);
            break;
        case 2:
            buscaBinaria(lista, tamanho);
            break;
        default:
            printf("Opção inválida\n");
            pausaTela();
    }


}

void buscaRG(Pessoa *lista, int tamanho){

    contador.comp = 0;
    contador.mov = 0;
    clock_t inicio, fim;
    long int rg;
    int encontrado = 0;
    int i;

    printf("Digite o RG: ");
    scanf("%ld", &rg);

    inicio = clock();

    for(i=0; i<tamanho; i++){
        contador.comp++;
        if (lista[i].rg == rg){
            encontrado = 1;
            break;
        }
        contador.comp++;
    }
    contador.comp++;

    limparTela();

    if(encontrado){
        contador.comp++;

        printf("Posição na lista: %d\n", i);
        printf("Nome: %s\n", lista[i].nome);
        printf("RG: %ld\n", lista[i].rg);
    }
    else{
        contador.comp++;
        printf("RG não encontrado\n");

    }
    fim = clock();

    printf("Comparações C(n): %d\n", contador.comp);
    printf("Movimentações M(n): %d\n", contador.mov);
    printf("Tempo de execução: %fs\n", tempoPercorrido(inicio, fim));
    pausaTela();
}
void buscaBinaria(Pessoa *lista, int tamanho){

    contador.comp = 0;
    contador.mov = 0;
    clock_t inicio, fim;

    int esq = 0;
    int dir = tamanho - 1;
    long int rg;
    int i;
    int encontrou = 0;

    printf("Digite o RG: ");
    scanf("%ld", &rg);
    inicio = clock();

    while(esq <= dir && !encontrou){
        contador.comp+=2;
        i = esq + (dir - esq) / 2;

        if(lista[i].rg == rg){
            contador.comp++;
            encontrou = 1;
        }
        else if(lista[i].rg > rg){
            contador.comp++;
            dir = i - 1;
        }
        else{
            contador.comp++;
            esq = i + 1;
        };
    }
    contador.comp+=2;


    if(encontrou){
        contador.comp++;
        printf("Posição na lista: %d\n", i);
        printf("Nome: %s\n", lista[i].nome);
        printf("RG: %ld\n", lista[i].rg);
    }
    else{
        contador.comp++;
        printf("RG não encontrado\n");
    }
    fim = clock();
    printf("Comparações C(n): %d\n", contador.comp);
    printf("Movimentações M(n): %d\n", contador.mov);
    printf("Tempo de execução: %fs\n", tempoPercorrido(inicio, fim));
    pausaTela();
}

void salvarLista(Pessoa *lista, int tamanho){

    FILE *ponteiroDoArquivo = fopen("NovaLista.txt", "w");
    if(ponteiroDoArquivo== NULL){
        perror("Erro ao salvar o arquivo");
        pausaTela();
        return;
    }

    for(int i=0; i<tamanho; i++)
        fprintf(ponteiroDoArquivo, "%s,%ld\n", lista[i].nome, lista[i].rg);

    fclose(ponteiroDoArquivo);
    printf("Lista salva em 'NovaLista.txt'\n");
    pausaTela();
}

void liberaLista(Pessoa *lista){

    free(lista);
}
