/**
 * @file escalonador.c
 *
 * @brief Contém a implementação do escalonador round robin.
 */


/*  

Formato do arquivo:

PID TEMPO_CPU INSTANTE_IO-TIPO_IO /

1 80 17-1 30-2 60-1 76-3
34 50 5-2 20-1 30-3 49-2



*/

#include "_config.h"


// Função para adicionar um novo nó à lista
void addOperacaoIO(OperacaoIO *inicio_io, OperacaoIO *final_io, int inicio, int codigo) {
    OperacaoIO *novoIO = (OperacaoIO *)malloc(sizeof(OperacaoIO));
    novoIO->inicio = inicio;
    switch(codigo){
        case 1:
            novoIO->tipo = DISCO;
        break;
        case 2:
            novoIO->tipo = FITA;
        break;
        case 3:
            novoIO->tipo = IMPRESSORA;
        break;
    }
    novoIO->tempo_restante = 0;
    final_io->prox = novoIO;
    final_io = novoIO;
    novoIO->prox = NULL; 
}


#include "escalonador.h"

void LeProcessos(FILE *file){

    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    int pid, tempo_cpu, inicio_io, codigo;

    while (fscanf(file, "%d %d", &pid, &tempo_cpu) == 2) {
        PCB* novo = (PCB*)malloc(sizeof(PCB));
        novo->PID = pid;
        novo->tempo_cpu = tempo_cpu;
        while (fscanf(file, "%d-%d", &inicio_io, &codigo) == 2) {
            addOperacaoIO(&novo->inicio_io, &novo->final_io, inicio_io, codigo); // Adiciona o nó para o instante e código de I/O
        }
        filaInsere(&alta, &novo);
    }

    fclose(file);

}

void displayProcessos(PCB* processo) {
    printf("PID: %d\n", processo->PID);
    printf("Tempo CPU: %d\n", processo->tempo_cpu);

    OperacaoIO* noIO = processo->inicio_io;
    while (noIO != NULL) {
        // se ele printar o enum TIPO vai aparecer o numero? me confundi
        printf("Início I/O: %d, Código: %d\n", noIO->inicio, noIO->tipo); 
        noIO = noIO->prox;
    }

    printf("\n");
}


void escalona(PCB* processo, Fila* fila) {
    if(processo->tempo_interno == processo->tempo_cpu){
        processo = filaRemove(&fila);
        processo->fim = tempoSistema;
    }


    // Verifica se o QUANTUM acabou
    if(processo->tempo_restante == 0){
        processo = filaRemove(&alta);
        filaInsere(&baixa, processo);
    }
    // Se ele tem I/O
    if(processo->inicio_io != NULL){
        // Verifica se o processo tá no tempo de pedir I/O
        if(processo->inicio_io->inicio == processo->tempo_interno){
            processo = filaRemove(&alta);
            // switch case pra ver qual IO e por no final da fila com processo_atual->io->tipo
            switch(processo->inicio_io->tipo){
                case DISCO:
                    filaInsere(&disco,processo);
                    processo->tempo_restante = IO_DISCO_TEMPO; 
                    processo->inicio_io = processo->inicio_io->prox;
                break;

                case FITA:
                    filaInsere(&fita,processo);
                    processo->tempo_restante = IO_FITA_TEMPO;
                    processo->inicio_io = processo->inicio_io->prox;
                break;

                case IMPRESSORA: 
                    filaInsere(&impressora,processo);
                    processo->tempo_restante = IO_IMPRESSORA_TEMPO;
                    processo->inicio_io = processo->inicio_io->prox;

                break;

                default:

            }
        
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
               escalona(processo_atual, &alta);
               
            } 
            // Fila de baixa
            else if(!estaVazia(&baixa)){
                processo_atual = baixa.inicio;
                escalona(processo_atual, &baixa);
            }

           timer_processo++;
           timer_disco++;
           timer_fita++;
           timer_impressora++;

        }

        tempoSistema++;

        printf("Não há processos a serem escalonados.\n");
        
    } FOREVER;
}

