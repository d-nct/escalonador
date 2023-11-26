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

void filaInsere(Fila* fila, PCB* processo) {
    // cria o novo nó 
    No* novo = (No*)malloc(sizeof(No));
    if (novo == NULL) {
        printf("Sem memória disponível\n");
        exit(1);
    }

    // configura o nó 
    novo->processo = processo;
    novo->prox = NULL;

    // coloca na fila 
    if (fila->inicio == NULL) {
        // caso fila vazia 
        fila->inicio = novo;
        fila->fim = novo;
    } else {
    //caso fila não vazia 
        fila->fim->prox = novo; // linka na fila 
        fila->fim = novo;       // atualiza a referência do fim para o novo 
    }
}

PCB* filaRemove(Fila* fila) {
    PCB* primeiro;
    No* tmp;

    // verifica se há pelo menos um nó 
    if (fila->inicio == NULL) {
        printf("Fila vazia!!!\n");
        return NULL;
    }

    // pega o primeiro nó
    tmp = fila->inicio; // aux p/ futura remoção
    primeiro = fila->inicio->processo;

    fila->inicio = fila->inicio->prox;

    // checa se a fila ficou vazia 
    if (fila->inicio == NULL) {
        fila->fim = NULL;
    }

    free(tmp);

    return primeiro;
}

int estaVazia(Fila *fila) {
    return (fila->inicio == NULL) ? 1 : 0; // Retorna 1 se estiver vazia e 0 se estiver com pelo menos um processo
}
