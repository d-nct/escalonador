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



#include "escalonador.h"

void rrNovoProcesso(PCB novo){
    /*

        LEITURA DO ARQUIVO

    */

    //filaInsere(&alta, &novo);
}


void escalona(PCB* processo) {
    // Verifica se o tempo processo acabou
    if(processo->tempo_restante == 0){
        processo = filaRemove(&alta);
        filaInsere(&baixa, processo);
    }
    // Se ele tem I/O
    if(processo->io != NULL){
        // Verifica se o processo tá no tempo de pedir I/O
        if(processo->io->inicio == processo->tempo_interno){
            processo = filaRemove(&alta);
            // switch case pra ver qual IO e por no final da fila com processo_atual->io->tipo
            // dentro do inserir na fila de I/O: tempo restante do processo vai ser o tempo que ele fica fazendo io

        }

    }
    processo->tempo_restante--;
    processo->tempo_interno++;
               
}

void roundRobin() {
    PCB* processo_atual;

    int timer_processo = 0;
    int timer_disco = 0;
    int timer_fita = 0;
    int timer_impressora = 0;
 
    do {

        //Enquanto pelo menos uma das filas não estiver vazias, RODA
        while(!(estaVazia(&alta)) || !(estaVazia(&baixa)) || !(estaVazia(&fita)) || !(estaVazia(&disco)) || !(estaVazia(&impressora))){

            // verifica se há algum processo na fila de alta prioridade 
            if(!estaVazia(&alta)) {
               processo_atual = alta.inicio;
               escalona(processo_atual);
               
            } 
            // Fila de baixa
            else if(!estaVazia(&baixa)){
                processo_atual = baixa.inicio;
                escalona(processo_atual);
            }

           timer_processo++;
           timer_disco++;
           timer_fita++;
           timer_impressora++;

        }

        printf("Não há processos a serem escalonados.\n");
        
    } FOREVER;
}

