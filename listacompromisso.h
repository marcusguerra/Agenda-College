#ifndef TPTHAIS_LISTACOMPROMISSO_H
#define TPTHAIS_LISTACOMPROMISSO_H
#include <stdio.h>
#include <stdlib.h>
#include "compromisso.h"

//estrutura da celula da lista de compromissos
typedef struct Celula {
    compromisso ItemCompromisso;
    struct Celula* pProx;
}CelulaCompromisso;

//estrutura da lista de compromissos
typedef struct {
    struct Celula* pPrimeiro;
    struct Celula* pUltimo;
}ListaCompromisso;

//=====================================================================

//cria lista de compromissos vazia
void criaLista(ListaCompromisso* lstcmp);

//insere compromisso no espaço alocado
void inserirCompNaLista(ListaCompromisso* lista, int prioridade, Data data, Horario horario, int duracao, char descricao[100]);

//verifica se há algum conflito na lista entre dois compromissos
int VerificaConflito(compromisso comp, ListaCompromisso *lista);

//retorna numero de compromissos totais da agenda
int retornaNCompromissosDaLista(ListaCompromisso* lista);

//remove compromisso da lista
int removeCompromissoLista(ListaCompromisso* lista, int idcomp);

//imprime todos os compromissos em ordem decrescente(em relacao a prioridade)
void imprimeCompromissos(ListaCompromisso lista);

//imprime depois da data especificada
void imprimeDpsData(ListaCompromisso comps, Data inputdata);

#endif
