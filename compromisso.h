#ifndef TPTHAIS_COMPROMISSO_H
#define TPTHAIS_COMPROMISSO_H
#include "Horario.h"
#include "Data.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct{
    Data data;
    Horario horario;
    int prioridade, duracao;
    int id_numerico;
    char descricao[100];
    //definindo as variaveis
}compromisso;


//iniciando as variaveis
void inicia_compromisso(compromisso* comp,int prioridade,Data data,Horario horario, int duracao, char descricao[100]);

//altera a prioridade
void altera_prioridade(compromisso* comp,int nova_prioridade);

//retorna a prioridade
int retorna_prioridade(compromisso* comp);

//verifica se há ou não conflito entre os compromissos
int tem_conflito(compromisso comp, compromisso comp1);

//imprime todos os itens do compromisso
void imprime_compromisso(compromisso comp);

//retorna o ID
int returnID (compromisso comp);

//retorna a data de comp
Data returnData (compromisso comp);

#endif
