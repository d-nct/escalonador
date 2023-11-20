# Simulador de Escalonador de Processos
O objetivo do repositório é a implementação de um escalonador utilizando _Round Robin_ com _Feedback_.

O algoritmo Round Robin com feedback é uma variação do algoritmo de escalonamento Round Robin utilizado em sistemas operacionais. O Round Robin é um algoritmo de escalonamento de processos que atribui a cada processo um intervalo de tempo fixo (quantum) durante o qual o processo pode executar. Após o término desse intervalo, o sistema operacional passa para o próximo processo na fila de prontidão.

O Round Robin com feedback acrescenta uma camada adicional de complexidade ao Round Robin tradicional, introduzindo múltiplas filas de prontidão e a capacidade de os processos se movimentarem entre essas filas com base em seu comportamento de execução. Cada fila representa um nível de prioridade diferente, e os processos podem ser promovidos ou rebaixados entre as filas.

A ideia principal do Round Robin com feedback é fornecer maior prioridade a processos que estão executando há menos tempo ou que tiveram menos oportunidades de execução recentemente. Isso é feito usando filas de prontidão diferentes para diferentes níveis de prioridade. Se um processo não conseguir ser concluído dentro de seu quantum atual, ele é movido para uma fila de prioridade mais baixa. Se um processo for concluído em seu quantum, ele permanece na mesma fila. Isso permite que processos que não estão sendo concluídos rapidamente tenham oportunidades mais frequentes de execução.

Aqui está um resumo do funcionamento do Round Robin com feedback:

1. Inicialização:
Os processos são inicialmente colocados na fila de prontidão de maior prioridade.

2. Execução:
Os processos são executados em ordem de chegada na fila de prontidão de maior prioridade.
Cada processo tem um quantum para a execução.

3. Promoção e Rebaixamento:
Se um processo não concluir dentro do quantum, ele é movido para a próxima fila de prontidão com uma prioridade mais baixa.
Se um processo concluir dentro do quantum, ele permanece na mesma fila.

4. Retorno ao Início:
Processos podem eventualmente retornar à fila de prontidão de maior prioridade, permitindo que processos que estiveram em espera tenham uma chance mais rápida de serem executados.

O Round Robin com feedback busca equilibrar a justiça e a eficiência na execução de processos, dando mais oportunidades a processos que não estão sendo concluídos rapidamente. Isso é especialmente útil em sistemas com uma variedade de tipos de processos, alguns dos quais podem ser mais demorados que outros.

# Premissas do Simulador
- [ ] Limite máximo de processos criados;
- [ ] O valor da fatia de tempo dada aos processos em execução;
- [ ] Tempos de serviço e de I/O aleatórios para cada processo criado;
- [ ] Tempos de duração de cada tipo de I/O (disco, fita magnética e impressora);

## Gerência de Processos
- [ ] Definição do PID de cada processo,
- [ ] Informações do PCB (contexto de software – prioridade, PID, PPID, status);
- [ ] Escalonador (pelo menos 3 filas, sendo uma fila de alta e uma de baixa prioridade para execução na CPU, e 1 fila de I/O, que pode ser implementada com filas diferentes para cada tipo de dispositivo);

## Tipos de I/O
- [ ] Disco – retorna para a fila de baixa prioridade;
- [ ] Fita magnética - retorna para a fila de alta prioridade;
- [ ] Impressora - retorna para a fila de alta prioridade;

## Ordem de entrada na fila de prontos
- [ ] Processos novos - entram na fila de alta prioridade;
- [ ] Processos que retornam de I/O – dependente do tipo de I/O solicitado;
- [ ] Processos que sofreram preempção – retornam na fila de baixa prioridade.

# Esqueleto e Estrutura Hierárquica

| Nome do Arquivo | Conteúdo | Inclui |
| :-------------- | :------- | :--------: |
| \_config.h | Configurações gerais do simulador | |
| main.c | Arquivo principal, que organiza a execução do simulador | |
| \_types.h | Definição dos tipos usados pelo simulador | |

# Exemplo de Uso
TODO
