/**
 * @file fila.c
 *
 * @brief Contém a implementação de uma fila encadeada, com ponteiro para o início e para o fim, das funções contidas em fila.h.
 */

#include "fila.h"

void filaInit(Fila* fila) {
    fila->inicio = NULL;
    fila->fim = NULL;
}

void filaInsere(Fila* fila, int processo) {
    /* cria o novo no */
    No* novo = (No*) malloc(sizeof(No));
    if (novo == NULL) {
        printf("Sem memória disponível\n");
        exit(1);
    }
    
    /* configura o no */
    novo->processo = processo;
    novo->prox = NULL;

    /* poe na fila */
    if (fila->inicio == NULL) {
        /* caso fila vazia */
        fila->inicio = novo;
        fila->fim = novo;
    } else {
        /* caso fila não vazia */
        fila->fim->prox = novo; /* linka na fila */
        fila->fim = novo; /* atualiza a ref do fim para o novo */
    }
}

int filaRemove(Fila* fila) {
    int primeiro;
    No* tmp;

    /* verifica se há pelo menos um cara */
    if (fila->inicio == NULL) {
        printf("Fila vazia!!!\n");
        return 0;
    }

    /* pega o primeiro cara */
    tmp = fila->inicio; /* para futura remoção*/
    primeiro = fila->inicio->processo;

    /* atualiza a ref do inicio */
    fila->inicio = fila->inicio->prox;

    /* vê se a fila ficou vazia */
    if (fila->inicio == NULL) {
        fila->fim = NULL;
    }

    /* libera a memória do nó */
    free(tmp);

    return primeiro;
}
int estaVazia(Fila *fila) {
    return (fila->inicio == NULL) ? 1 : 0; // Retorna 1 se estiver vazia e 0 se estiver com pelo menos um processo
}
