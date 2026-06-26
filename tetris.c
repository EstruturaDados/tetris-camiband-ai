#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Desafio Tetris Stack
// Tema 3 - Integração de Fila e Pilha
// Este código inicial serve como base para o desenvolvimento do sistema de controle de peças.
// Use as instruções de cada nível para desenvolver o desafio.

//====================================================
// Struct da peça
//====================================================
typedef struct {
    char tipo;
    int id;
} Peca;

//====================================================
// Fila Circular
//====================================================
#define TAM_FILA 5

typedef struct {
    Peca itens[TAM_FILA];
    int frente;
    int tras;
    int quantidade;
} Fila;

//====================================================
// Pilha
//====================================================
#define TAM_PILHA 3

typedef struct {
    Peca itens[TAM_PILHA];
    int topo;
} Pilha;

//====================================================
// Variável global para gerar IDs únicos
//====================================================
int proximoID = 0;

//====================================================
// Protótipos das funções
//====================================================
Peca gerarPeca();

void inicializarFila(Fila *fila);
int filaCheia(Fila *fila);
int filaVazia(Fila *fila);
void enqueue(Fila *fila, Peca peca);
Peca dequeue(Fila *fila);
void mostrarFila(Fila *fila);

void inicializarPilha(Pilha *pilha);
int pilhaCheia(Pilha *pilha);
int pilhaVazia(Pilha *pilha);
void push(Pilha *pilha, Peca peca);
Peca pop(Pilha *pilha);
void mostrarPilha(Pilha *pilha);

void trocarFrenteTopo(Fila *fila, Pilha *pilha);
void trocarTres(Fila *fila, Pilha *pilha);

int main() {

    srand(time(NULL));

    Fila fila;
    Pilha pilha;

    inicializarFila(&fila);
    inicializarPilha(&pilha);

    // Preenche a fila inicialmente
    for(int i=0;i<TAM_FILA;i++){
        enqueue(&fila, gerarPeca());
    }

    int opcao;

    do{

        printf("\n==============================\n");
        printf("Estado Atual\n");
        printf("==============================\n");

        mostrarFila(&fila);
        mostrarPilha(&pilha);

        printf("\nMenu\n");
        printf("1 - Jogar peça\n");
        printf("2 - Reservar peça\n");
        printf("3 - Usar peça reservada\n");
        printf("4 - Trocar frente da fila com topo da pilha\n");
        printf("5 - Trocar 3 primeiras da fila com pilha\n");
        printf("0 - Sair\n");

        printf("\nEscolha: ");
        scanf("%d",&opcao);

        switch(opcao){

            case 1:{
                if(!filaVazia(&fila)){
                    dequeue(&fila);
                    enqueue(&fila, gerarPeca());
                }else{
                    printf("Fila vazia.\n");
                }
                break;
            }

            case 2:{
                if(filaVazia(&fila)){
                    printf("Fila vazia.\n");
                }
                else if(pilhaCheia(&pilha)){
                    printf("Pilha cheia.\n");
                }
                else{
                    push(&pilha, dequeue(&fila));
                    enqueue(&fila, gerarPeca());
                }
                break;
            }

            case 3:{
                if(pilhaVazia(&pilha)){
                    printf("Pilha vazia.\n");
                }else{
                    pop(&pilha);
                }
                break;
            }

            case 4:
                trocarFrenteTopo(&fila,&pilha);
                break;

            case 5:
                trocarTres(&fila,&pilha);
                break;

            case 0:
                printf("Programa encerrado.\n");
                break;

            default:
                printf("Opção inválida.\n");
        }

    }while(opcao!=0);

    // 🧩 Nível Novato: Fila de Peças Futuras
    //
    // - Crie uma struct Peca com os campos: tipo (char) e id (int).
    typedef struct{
        char tipo;
        int id;
    }Peca;
    //
    // - Implemente uma fila circular com capacidade para 5 peças.
    typedef struct{
        Peca itens[TAM_FILA];
        int frente;
        int tras;
        int quantidade;
    }Fila;
    //
    // - Crie funções como inicializarFila(), enqueue(), dequeue(), filaCheia(), filaVazia().
    // Código:
    // inicializarFila(Fila *fila);
    // enqueue(Fila *fila, Peca peca);
    // dequeue(Fila *fila);
    // filaCheia(Fila *fila);
    // filaVazia(Fila *fila);
    //
    // - Cada peça deve ser gerada automaticamente com um tipo aleatório e id sequencial.
    // Código:
    // Peca gerarPeca();
    //
    // - Exiba a fila após cada ação com uma função mostrarFila().
    // Código:
    // mostrarFila(Fila *fila);
    //
    // - Use um menu com opções como:
    //      1 - Jogar peça (remover da frente)
    //      0 - Sair
    // Código implementado no switch do menu.
    //
    // - A cada remoção, insira uma nova peça ao final da fila.
    // Código:
    // dequeue(&fila);
    // enqueue(&fila, gerarPeca());


    // 🧠 Nível Aventureiro: Adição da Pilha de Reserva
    //
    // - Implemente uma pilha linear com capacidade para 3 peças.
    typedef struct{
        Peca itens[TAM_PILHA];
        int topo;
    }Pilha;
    //
    // - Crie funções como inicializarPilha(), push(), pop(), pilhaCheia(), pilhaVazia().
    // Código:
    // inicializarPilha(Pilha *pilha);
    // push(Pilha *pilha, Peca peca);
    // pop(Pilha *pilha);
    // pilhaCheia(Pilha *pilha);
    // pilhaVazia(Pilha *pilha);
    //
    // - Permita enviar uma peça da fila para a pilha (reserva).
    // Código:
    // push(&pilha, dequeue(&fila));
    //
    // - Crie um menu com opção:
    //      2 - Enviar peça da fila para a reserva (pilha)
    //      3 - Usar peça da reserva (remover do topo da pilha)
    // Código implementado no switch do menu.
    //
    // - Exiba a pilha junto com a fila após cada ação com mostrarPilha().
    // Código:
    // mostrarPilha(&pilha);
    //
    // - Mantenha a fila sempre com 5 peças (repondo com gerarPeca()).
    // Código:
    // enqueue(&fila, gerarPeca());


    // 🔄 Nível Mestre: Integração Estratégica entre Fila e Pilha
    //
    // - Implemente interações avançadas entre as estruturas:
    //      4 - Trocar a peça da frente da fila com o topo da pilha
    //      5 - Trocar os 3 primeiros da fila com as 3 peças da pilha
    // Código:
    // trocarFrenteTopo(&fila,&pilha);
    // trocarTres(&fila,&pilha);
    //
    // - Para a opção 4:
    //      Verifique se a fila não está vazia e a pilha tem ao menos 1 peça.
    //      Troque os elementos diretamente nos arrays.
    //
    // - Para a opção 5:
    //      Verifique se a pilha tem exatamente 3 peças e a fila ao menos 3.
    //      Use a lógica de índice circular para acessar os primeiros da fila.
    //
    // - Sempre valide as condições antes da troca e informe mensagens claras ao usuário.
    //
    // - Use funções auxiliares, se quiser, para modularizar a lógica de troca.
    //
    // - O menu deve ficar assim:
    //      4 - Trocar peça da frente com topo da pilha
    //      5 - Trocar 3 primeiros da fila com os 3 da pilha

    return 0;
}

//====================================================
// Implementação das funções
//====================================================

Peca gerarPeca(){

    char tipos[]={'I','O','T','L'};

    Peca p;

    p.tipo=tipos[rand()%4];
    p.id=proximoID++;

    return p;
}

void inicializarFila(Fila *fila){
    fila->frente=0;
    fila->tras=0;
    fila->quantidade=0;
}

int filaCheia(Fila *fila){
    return fila->quantidade==TAM_FILA;
}

int filaVazia(Fila *fila){
    return fila->quantidade==0;
}

void enqueue(Fila *fila,Peca p){

    if(filaCheia(fila))
        return;

    fila->itens[fila->tras]=p;
    fila->tras=(fila->tras+1)%TAM_FILA;
    fila->quantidade++;
}

Peca dequeue(Fila *fila){

    Peca p=fila->itens[fila->frente];

    fila->frente=(fila->frente+1)%TAM_FILA;
    fila->quantidade--;

    return p;
}

void mostrarFila(Fila *fila){

    printf("Fila: ");

    for(int i=0;i<fila->quantidade;i++){

        int indice=(fila->frente+i)%TAM_FILA;

        printf("[%c %d] ",fila->itens[indice].tipo,fila->itens[indice].id);
    }

    printf("\n");
}

void inicializarPilha(Pilha *pilha){
    pilha->topo=-1;
}

int pilhaCheia(Pilha *pilha){
    return pilha->topo==TAM_PILHA-1;
}

int pilhaVazia(Pilha *pilha){
    return pilha->topo==-1;
}

void push(Pilha *pilha,Peca p){

    pilha->topo++;
    pilha->itens[pilha->topo]=p;
}

Peca pop(Pilha *pilha){

    return pilha->itens[pilha->topo--];
}

void mostrarPilha(Pilha *pilha){

    printf("Pilha (Topo -> Base): ");

    for(int i=pilha->topo;i>=0;i--){

        printf("[%c %d] ",pilha->itens[i].tipo,pilha->itens[i].id);
    }

    printf("\n");
}

void trocarFrenteTopo(Fila *fila,Pilha *pilha){

    if(filaVazia(fila) || pilhaVazia(pilha)){
        printf("Troca impossível.\n");
        return;
    }

    Peca aux=fila->itens[fila->frente];

    fila->itens[fila->frente]=pilha->itens[pilha->topo];
    pilha->itens[pilha->topo]=aux;
}

void trocarTres(Fila *fila,Pilha *pilha){

    if(fila->quantidade<3 || pilha->topo<2){
        printf("Não há peças suficientes para trocar.\n");
        return;
    }

    for(int i=0;i<3;i++){

        int indice=(fila->frente+i)%TAM_FILA;

        Peca aux=fila->itens[indice];

        fila->itens[indice]=pilha->itens[pilha->topo-i];
        pilha->itens[pilha->topo-i]=aux;
    }
}