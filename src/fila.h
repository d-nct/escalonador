/**
 * @file fila.h
 *
 * @brief Contém a implementação de uma fila encadeada, com ponteiro para o início e para o fim.
 */

#ifndef FILA_H
#define FILA_H

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
void initFila(Fila* fila);

#endif