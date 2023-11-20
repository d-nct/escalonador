/**
 * @file _config.h
 *
 * @brief Aqui estão as principais configurações (regras de negócio) do simulador de escalonador.
 * Unidades:
 * - tempo: milissegundos
 */

#ifndef CONFIG_H
#define CONFIG_H

/* Sessão de Importações
   --------------------- */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/* Sessão de Definições
   -------------------- */

/* Para facilitar a compreensão */
#define FOREVER                           while(1)

/* Configurações gerais do Escalonador */
#define MAX_PROCESSOS                     50  
#define QUANTUM                                   

/* Define o tempo necessário para cada tipo de I/O */
#define IO_DISCO_TEMPO              
#define IO_FITA_TEMPO               
#define IO_IMPRESSORA_TEMPO          

#endif
