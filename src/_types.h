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
    int inicio; // inicio do tempo interno do processo em que começa a operação de I/O
    IO tipo; // tipo da operação de I/O
    int tempo_restante; // tempo restante para a conclusão da operação de I/O
} OperacaoIO;

/* Status do processo, sem swapping */
typedef enum {
    NOVO,      /* acabou de chegar, precisa ser alocado */
    PRONTO,    /* aguardando execução */
    EXECUCAO,  /* executando */
    SAIDA,     /* terminada execução */
    BLOQUEADO, /* aguardando I/O */
} Status;

/* Tipos sobre o Process Control Block */
typedef struct {
    int PID;
    Status status;
    int inicio;    
    int fim;      
    int tempo_cpu; //para tempo de serviço, a ser incrementado sempre que status=EXECUCAO
    int tempo_restante // tempo que falta para o processo terminar 
    OperacaoIO* io;     // Ponteiro para lista de operações de I/O do processo, se não tiver será NULL
    int numOperacoesIO; // Número total de operações de I/O realizadas pelo processo 

} PCB;

#endif
