#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>
#include "listaSequencial.h"

int main() {
    setlocale(LC_ALL, "Portuguese");

    Pessoa *minhaLista = (Pessoa*) malloc(MAX_PESSOAS * sizeof(Pessoa));
    if (minhaLista == NULL) {
        printf("Memória insuficiente!\n");
        return 1;
    }

    int totalCarregado=0;
    int opcao;

    do{
        printf("=== MENU DE OPERAÇÕES ===\n\n");
        printf("1 - Carregar lista de um arquivo\n");
        printf("2 - Inserir pessoa\n");
        printf("3 - Remover pessoa\n");
        printf("4 - Mostrar lista\n");
        printf("5 - Buscar por RG\n");
        printf("6 - Salvar lista\n");
        printf("7 - Ordenar dados\n");
        printf("0 - Sair\n\n");
        printf("Digite sua opção: ");
        scanf("%d", &opcao);
        limparTela();

        switch (opcao) {
            case 1:
                carregarPessoas(minhaLista, &totalCarregado, NOME_ARQUIVO);
                break;
            case 2:
                menuInsercao(minhaLista, &totalCarregado);
                break;
            case 3:
                menuRemocao(minhaLista, &totalCarregado);
                break;
            case 4:
                mostrarLista(minhaLista, totalCarregado);
                break;
            case 5:
                buscaRG(minhaLista, totalCarregado);
                limparTela();
                break;
            case 6:
                salvarLista(minhaLista, totalCarregado);
                break;
            case 7:
                menuOrdenacao(minhaLista, &totalCarregado);
                break;
            case 0:
                break;
            default:
                printf("Opção inválida\n");
                pausaTela();
        }

        limparTela();

    } while(opcao!=0);

    liberaLista(minhaLista);
    minhaLista = NULL;

    return 0;
}
