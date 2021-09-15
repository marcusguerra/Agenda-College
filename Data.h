#ifndef TPTHAIS_DATA_H
#define TPTHAIS_DATA_H
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int dia;
    int mes;
    int ano;
} Data;

//imprime
void ImprimeData(Data data); //Imprime na tela a data
//gets
int GetDia(Data data); //Retorna o dia da data
int GetMes(Data data); //Retorna o mes da data
int GetAno(Data data); //Retorna o ano da data
//sets
void SetData(Data *data, int dia, int mes, int ano); //Atribui o dia, mes e ano a suas respectivas variaveis em *data

#endif
