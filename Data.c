#include "Data.h"
#include <stdio.h>
#include <stdlib.h>

//imprime
void ImprimeData(Data data){
    printf("Data: %02d/%02d/%d\n", data.dia, data.mes, data.ano); //Imprime a data da forma dd/mm/aaaa
}
//gets
int GetDia(Data data){
    return data.dia;
}
int GetMes(Data data){
    return data.mes;
}
int GetAno(Data data){
    return data.ano;
}
//sets
void SetData(Data *data, int dia, int mes, int ano){
    data->dia = dia;
    data->mes = mes;
    data->ano = ano;
}
