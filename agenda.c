#include "agenda.h"
#include <string.h>
#include <stdio.h>

//cria uma nova agenda
void criaAgenda(Agenda* agd, int idProf, char nomeProf[50], int ano)
{
    agd->idProf = idProf;
    strcpy(agd->nomeProf, nomeProf);
    agd->ano = ano;
    criaLista(&(agd->listaCompromisso));
}

//retorna numero de compromissos apos a data especificada
void recuperaAgenda(Agenda* agenda, Data inputdata)
{
    printf("\nProfessor: %s", agenda->nomeProf);
    printf("\nAno: %d",agenda->ano);
    imprimeDpsData(agenda->listaCompromisso,inputdata);
}

//insere um compromisso na agenda
void insereCompromisso(Agenda* agenda, int prioridade, Data data, Horario horario, int duracao, char descricao[100]){
    inserirCompNaLista(&(agenda->listaCompromisso),prioridade,data,horario,duracao,descricao);
}

//remove um compromisso da agenda
int removeCompromisso(Agenda* agenda, int id){
    return removeCompromissoLista(&(agenda->listaCompromisso),id);
}

//imprime compromissos ordenados por prioridade
void imprimeAgenda(Agenda agenda)
{
    imprimeCompromissos(agenda.listaCompromisso);
}

//retorna o numero de compromissos da agenda
int retornaNCompromissos(Agenda agenda){
    return retornaNCompromissosDaLista(&(agenda.listaCompromisso));
}

//Retorna o id do professor
int returnIDProf(Agenda agenda){
    return agenda.idProf;
}
