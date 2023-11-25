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
typedef struct IO {
    DISCO,
    FITA,
    IMPRESSORA,
} IO;

typedef struct  {
    int inicio;
    IO tipo;
} process_IO;

/* Status do processo, sem swapping */
typedef enum {
    NOVO,      /* acabou de chegar, precisa ser alocado */
    PRONTO,    /* aguardando execução */
    EXECUCAO,  /* executando */
    SAIDA,     /* terminada execução */
    BLOQUEADO, /* aguardando IO */
} Status;

/* Tipos sobre o Process Control Block */
typedef struct {
    int PID;
    Status status;
    int inicio;    /* para tempo de execução */
    int fim;       /* para tempo de execução */
    int tempo_cpu; /* para tempo de serviço, a ser incrementado sempre que status=EXECUCAO
    
     */
} PCB;

#endif
