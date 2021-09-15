#include "Horario.h"
#include <stdio.h>
#include <stdlib.h>

//imprime
void ImprimeHorario(Horario horario){
    printf("Hora: %02d:%02d\n", horario.hora, horario.minutos); //Imprime o horario da forma hh:mm
}
//gets
int GetHora(Horario horario){
    return horario.hora;
}
int GetMinuto(Horario horario){
    return horario.minutos;
}
//sets
void SetHorario(Horario *horario, int hora, int minutos){
    horario->hora = hora;
    horario->minutos = minutos;
}
