#include "_config.h"
#include "escalonador.h"
#include "fila.h"


int main(int argc, char *argv[]) {

    if (argc != 2) {
        fprintf(stderr, "Uso: %s <nome_do_arquivo>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }
    
    filaInit(&alta);
    filaInit(&baixa);
    filaInit(&disco);
    filaInit(&fita);
    filaInit(&impressora);
    
    LeProcessos(file);
    displayProcessos(&alta);

    
    return 0; 
}