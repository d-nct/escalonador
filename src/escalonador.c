/**
 * @file escalonador.c
 *
 * @brief Contém a implementação do escalonador round robin.
 */

    // Na inicialização todos os processos novos entram na fila de alta prioridade

    /*  Criar a função principal de escalonador
        - Checar o Limite máximo de processos criados;
        - Checar o Quantum;
        - Contador geral
        - Contador do I/O para cada tipo baseado no tempo de cada um deles
        - Bool que indica se as filas de I/O estão vazias ou não (Criar função de checagem de I/O)
        - Os Processos que sofreram preempção – retornam na fila de baixa prioridade.
    */

    // enquanto VERDADEIRO:
    //     se tem gente na fila com prioridade:
    //         executa o cara da fila com prioridade.
    //     se não:
    //         se tem gente na fila sem prioridade:
    //             executa o cara da fila sem prioridade.

    

   /*


   */

#include "escalonador.h"

void roundRobin() {
    PCB processo;

    do {
        
    } FOREVER;
}
