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
    IMPRESSORA
} IO; 

typedef struct  {
    int inicio;
    IO tipo;
} OperacaoIO;

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
    int inicio;    
    int fim;      
    int tempo_cpu; //para tempo de serviço, a ser incrementado sempre que status=EXECUCAO
    OperacaoIO* io;     // Ponteiro para lista de operações de I/O do processo
    int numOperacoesIO; // Número total de operações de I/O realizadas pelo processo 

} PCB;

#endif
