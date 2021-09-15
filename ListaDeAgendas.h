#ifndef TPTHAIS_LISTADEAGENDAS_H
#define TPTHAIS_LISTADEAGENDAS_H
#include "agenda.h"

typedef struct ACelula{
    Agenda agenda;
    struct ACelula* prox;
} CelulaDoProf;

typedef struct {
    CelulaDoProf *primeiro;
    CelulaDoProf *ultimo;
}ListaDeAgendas;

//inicializa a lista com o cabecalho
void inicializarAgendas(ListaDeAgendas* agendas);

//recebe o id do professor, se ele ainda nao tiver sido registrado, retorna 0, se ele tiver, retorna 1 e armazena na variavel agenda a agenda desse professor
int login(ListaDeAgendas* agendas, Agenda* agenda,int idProf);

//registra o professor e cria sua agenda
void registrarProfessor(ListaDeAgendas* agendas, int idProf, char nomeProf[50], int ano);

#endif
