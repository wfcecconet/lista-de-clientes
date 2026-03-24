#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include "clientes.h"

//#define MAX_PESSOAS         50
//#define TAMANHO_MAX_NOME    100
//#define TAMANHO_MAX_RG_STR  15
//#define TAMANHO_MAX_LINHA   128

void limpaTela(){
        system("CLS");
}


int main() {

    setlocale(LC_ALL, "Portuguese");

    int menu = 1;

    while(menu != 5 && menu > 0){
        printf("OPERAÇÕES\n");
        printf("1 - Inserção de nó\n");
        printf("2 - Remoção de nó\n");
        printf("3 - Buscar RG\n");
        printf("4 - Mostrar lista\n");
        printf("5 - Sair do sistema\n");
        printf("Escolha uma opção e pressione ENTER\n");

        scanf("%d", &menu);

        limpaTela();

        switch(menu){
            case 1:
                printf("INSERÇÃO\n");
                break;
            case 2:
                printf("REMOÇÃO\n");
                break;
            case 3:
                printf("BUSCAR RG\n");
                break;
            case 4:
                printf("MOSTRAR LISTA\n");
                break;
            case 5:
                printf("SAIR\n");
                break;
            default:
                printf("OPÇÃO INVÁLIDA\n");
                break;
        }



    }


//   Pessoa minhaLista[MAX_PESSOAS];

//    int totalCarregado = carregarPessoas(minhaLista, MAX_PESSOAS, "dados_rg.txt");

//    mostrarLista(minhaLista, totalCarregado);

    return 0;
}
