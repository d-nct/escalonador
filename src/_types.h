/**
 * @file _types.h
 *
 * @brief Aq estão tipos declarados a serem usados no programa.
 */

#ifndef TYPES_H
#define TYPES_H

#include "_config.h"

typedef int bool_t;

/* sobre o IO */
typedef enum {
    DISCO,
    FITA,
    IMPRESSORA,
} IO_t;

/* Serão apenas duas filas de prioridade */
typedef enum {
    BAIXA,
    ALTA,
} Prioridade_t;

/* Status do processo, sem swapping */
typedef enum {
    NOVO,      /* acabou de chegar, precisa ser alocado */
    PRONTO,    /* aguardando execução */
    EXECUCAO,  /* executando */
    SAIDA,     /* terminada execução */
    BLOQUEADO, /* aguardando IO */
} Status_t;

/* Tipos sobre o Process Control Block */
typedef struct {
    int PID;
    int PPID;
    Prioridade_t prioridade;
    Status_t status;
    clock_t inicio;    /* para tempo de execução */
    clock_t fim;       /* para tempo de execução */
    clock_t tempo_cpu; /* para tempo de serviço, a ser incrementado sempre que status=EXECUCAO */
} PCB;

#endif
