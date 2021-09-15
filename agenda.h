#ifndef TPTHAIS_AGENDA_H
#define TPTHAIS_AGENDA_H
#include <stdio.h>
#include <stdlib.h>
#include "listacompromisso.h"

//TAD Agenda
typedef struct{
    int idProf;
    char nomeProf[50];
    int ano;
    ListaCompromisso listaCompromisso;
}Agenda;

//=====================================================================

//cria uma nova agenda
void criaAgenda(Agenda* agd, int idProf, char nomeProf[50], int ano);

//retorna numero de compromissos apos a data especificada
void recuperaAgenda(Agenda* agenda, Data data);

//insere um compromisso na agenda
void insereCompromisso(Agenda* Agenda, int prioridade, Data data, Horario horario, int duracao, char descricao[100]);

//remove um compromisso da agenda
int removeCompromisso(Agenda* agenda, int id);

//imprime compromissos ordenados por prioridade
void imprimeAgenda(Agenda agenda);

//Retorna o numero de compromissos na agenda
int retornaNCompromissos(Agenda agenda);

//Retorna o id do professor
int returnIDProf(Agenda agenda);

#endif
