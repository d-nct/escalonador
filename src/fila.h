/**
 * @file fila.h
 *
 * @brief Contém a implementação de uma fila encadeada, com ponteiro para o início e para o fim.
 */

#ifndef FILA_H
#define FILA_H

#include "_config.h"

/* Definição da estrutura do nó da fila */
typedef struct _No {
    int processo; /* PID */
    struct _No* prox;
} No;

/* Definição da estrutura da fila */
typedef struct {
    No* inicio; 
    No* fim; 
} Fila;

/* Definição dos métodos da fila */

/**
 * @brief inicializa uma fila vazia.
 * 
 * @param fila é um ponteiro vazio para um objeto do tipo Fila.
 */
void filaInit(Fila* fila);

/**
 * @brief Insere um elemento na fila.
 * 
 * @param fila é um ponteiro para a fila.
 * @param processo é o número do processo a ser inserido na fila.
 */
void filaInsere(Fila* fila, int processo);

/**
 * @brief Remove o primeiro elemento da fila.
 * 
 * @param fila é um ponteiro para a fila.
 * @return o primeiro elemento que foi removido.
 */
int filaRemove(Fila* fila);

int estaVazia(Fila *fila);

#endif
