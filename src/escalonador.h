/**
 * @file escalonador.h
 *
 * @brief Implementação do simulador de escalonador em si. 
 */

#ifndef ESCALONADOR_H
#define ESCALONADOR_H

#include "_types.h"
#include "fila.h"

Fila alta;
Fila baixa;
Fila disco;
Fila fita;
Fila impressora;

void escalona();

/* Métodos do Escalonador 
   ---------------------- */

/** 
 * @brief Adiciona um processo ao escalonador.
 *
 * @param novo é o novo processo.
 */
void rrNovoProcesso(PCB novo);

/** 
 * @brief Verifica se a fatia de tempo está esgotada.
 *
 * @param inicio é quando começou a execução.
 * @return um booleano dizendo se terminou ou não .
 */
void rrCheckFimQuantum(int atual);

/** 
 * @brief Inicia o round robin
 */
void roundRobin();

#endif
