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

int contador = 0;

#include "escalonador.h"

void escalona() {
    
}

void roundRobin() {
    PCB* processo_atual;

    do {
        //Enquanto pelo menos uma das filas não estiver vazias, RODA
        while(!(estaVazia(&alta)) || !(estaVazia(&baixa))){

        // Verifica se há algum processo na fila de alta prioridade
            if (!estaVazia(&alta)) {
                processo_atual = filaRemove(&alta);
                // Marca a primeira vez que o processo é executado
                if (processo_atual->inicio == 0) {
                    processo_atual->inicio = contador;
                }

                /* Verifica se o processo já terminou
                if (processo_atual->tempo_restante <= 0) {
                    processo_atual->status = SAIDA; */ 
        

                 /* Verifica se o quantum foi esgotado
                if (rrCheckFimQuantum( SEI LA , contador)) {
                    // Move o processo para a fila de baixa prioridade
                    filaInsere(&baixa, processo_atual);

                */
        
            } 
        // Se não, V=verifica se há algum processo de baixa prioridade
            else if (!estaVazia(&baixa)) {
                
            }

        }
        
         
        
    } FOREVER;
}

void rrNovoProcesso(PCB novo){
    /*

        LEITURA DO ARQUIVO

    */

    //filaInsere(&alta, &novo);
}

void rrCheckFimQuantum(int inicio, int atual){
    return ((atual - inicio) % QUANTUM) == 0;

}