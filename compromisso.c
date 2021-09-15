//importe das bibliotecas
#include "compromisso.h"
#include <stdio.h>
#include <math.h>
//inicializando todos os ponteiros
void inicia_compromisso(compromisso* comp,int prioridade,Data data,Horario horario, int duracao, char descricao[100])
{
    comp->prioridade = prioridade;
    comp->duracao = duracao;
    strcpy(comp->descricao, descricao);
    comp->horario = horario;
    comp->data = data;
    comp->id_numerico = ((int)pow(10,8))*(GetAno(comp->data)-2000) + ((int)pow(10,6))*GetMes(comp->data) + ((int)pow(10,4))*GetDia(comp->data) + ((int)pow(10,2))*GetHora(comp->horario) + GetMinuto(comp->horario); //atribui o ID na forma AAMMDDHHMM
}

void altera_prioridade(compromisso* comp,int nova_prioridade)
{
    comp->prioridade = nova_prioridade;
}

//retornando a prioridade
int retorna_prioridade(compromisso* comp)
{
    return comp->prioridade;
}

//compara se a data é a mesma
//depois compara se em algum momento o horario do compromisso 1  a do compromisso
int tem_conflito(compromisso comp, compromisso comp1)
{
    int i, min, min1, q;
    q = 0;
    min = ((GetHora(comp.horario)*60)+GetMinuto(comp.horario));
    min1 = ((GetHora(comp.horario)*60)+GetMinuto(comp.horario)) + comp.duracao;

    if(GetDia(comp1.data) == GetDia(comp.data) && GetAno(comp1.data) == GetAno(comp.data) && GetMes(comp1.data) == GetMes(comp.data))
    {
        for(i = ((GetHora(comp1.horario)*60) + GetMinuto(comp1.horario)) ;i < (((GetHora(comp1.horario)*60) + GetMinuto(comp1.horario)) + comp1.duracao); i++)
        {
            if( i < min1 && i > min)
            {
                q = 1;
                break;
            }
        }
    }


//coincidem retorna 1 //nao coincidem retorna 0
    if (q == 1)
        return 1;
    else
        return 0;
}


//imprimindo_todo o conteudo de comp
void imprime_compromisso(compromisso comp){
    printf("\nIdentificador: %d\n", comp.id_numerico);
    printf("Nivel de prioridade:%d\n", comp.prioridade);
    ImprimeData(comp.data);
    ImprimeHorario(comp.horario);
    printf("Duracao: %d\n",comp.duracao);
    printf("Descricao: %s\n", comp.descricao);
}

//returna o ID de comp
int returnID (compromisso comp){
    return comp.id_numerico;
}

//returna a data de comp
Data returnData (compromisso comp){
    return comp.data;
}
