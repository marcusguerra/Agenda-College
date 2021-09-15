#ifndef TPTHAIS_HORARIO_H
#define TPTHAIS_HORARIO_H
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int hora;
    int minutos;
} Horario;

void ImprimeHorario(Horario horario); //Imprime na tela o horario
//gets
int GetHora(Horario horario); //Retorna a hora do horario
int GetMinuto(Horario horario); //Retorna o minuto de horario
//sets
void SetHorario(Horario *horario, int hora, int minutos); //Atribui hora e minutos em a suas respectivas variaveis em *horario

#endif
