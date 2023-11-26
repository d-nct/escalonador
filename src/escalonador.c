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

void rrCheckFimQuantum(int atual){
    return (atual % QUANTUM == 0);

}


void escalona() {
    
}

void roundRobin() {
    PCB* processo_atual;
    int timer = 0;
 
    do {
        //Enquanto pelo menos uma das filas não estiver vazias, RODA
        while(!(estaVazia(&alta)) || !(estaVazia(&baixa))){

        // Verifica se há algum processo na fila de alta prioridade 
            while(!estaVazia(&alta)) {
                processo_atual = filaRemove(&alta); // tira o processo da fila de alta e salva em processo_atual

                // enquanto o tempo de quantum nao acabar ou nao for requisitada nenhum I/O 
                while(timer % QUANTUM == 1){
                    processo_atual->tempo_restante--;
                    timer++; // nao sei se é aqui que poe pq tem que acrescentar tempo na fila de IO tbm ne
                }
                // se faz IO, coloca na fila de IO e faz as operações necessárias
                // se acaba o quantum, pega o proximo na fila de alta
                // quanto o IO acaba coloca na fila de alta dnv

                
        
            } 


           // Se não, verifica se há algum processo de baixa prioridade
         
        }

        printf("Não há processos a serem escalonados.\n");
        
         
        
    } FOREVER;
}

