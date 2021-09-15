#include <stdio.h>
#include <stdlib.h>
#include "listacompromisso.h"

//cria lista de compromissos vazia
void criaLista(ListaCompromisso* lstcmp)
{

    lstcmp->pPrimeiro = (struct Celula*) malloc(sizeof(CelulaCompromisso));
    lstcmp->pUltimo = lstcmp->pPrimeiro;
    lstcmp->pPrimeiro->pProx = NULL;
}

//insere um compromisso no final da lista
void inserirCompNaLista(ListaCompromisso* lista, int prioridade, Data data, Horario horario, int duracao, char descricao[100])
{
    compromisso compromissoInsere;
    inicia_compromisso(&compromissoInsere,prioridade, data, horario, duracao, descricao);
    if (VerificaConflito(compromissoInsere, lista) == 0)
    {
        CelulaCompromisso *celulanova = (CelulaCompromisso*)malloc(sizeof(CelulaCompromisso));
        celulanova->ItemCompromisso = compromissoInsere;
        celulanova->pProx = NULL;
        lista->pUltimo->pProx = celulanova;
        lista->pUltimo = celulanova;
        printf("Compromisso Inserido!\n");
        printf("Id do compromisso: %d\n", returnID(compromissoInsere));
    }
    else{
        printf("Falha na operacao: Compromissos Conflitantes.\n");}
}

//verifica se há algum conflito na lista entre dois compromissos
int VerificaConflito(compromisso comp, ListaCompromisso *lista)
{
    CelulaCompromisso* ponteiroauxiliar;
    ponteiroauxiliar = lista->pPrimeiro;
    int digitoverificador = 0;
    while (ponteiroauxiliar != NULL)
    {
        if (tem_conflito(ponteiroauxiliar->ItemCompromisso, comp))
        {digitoverificador = 1;}
        ponteiroauxiliar = ponteiroauxiliar->pProx;
    }
    return digitoverificador;
}

//retorna numero de compromissos totais da agenda
int retornaNCompromissosDaLista(ListaCompromisso* lista)
{
    CelulaCompromisso* ponteiroauxiliar;
    ponteiroauxiliar = lista->pPrimeiro;
    int contador = -1;
    while (ponteiroauxiliar != NULL)
    {
        contador += 1;
        ponteiroauxiliar = ponteiroauxiliar->pProx;
    }
    return contador;
}

//remove compromisso da lista
int removeCompromissoLista(ListaCompromisso* lista, int idcomp)
{
    CelulaCompromisso* ptrCelulaExcluida;
    CelulaCompromisso* ponteiroanterior;
    ptrCelulaExcluida = lista->pPrimeiro->pProx;
    ponteiroanterior = lista->pPrimeiro;
    while (ptrCelulaExcluida != NULL && returnID(ptrCelulaExcluida->ItemCompromisso) != idcomp){
        ponteiroanterior = ponteiroanterior->pProx;
        ptrCelulaExcluida = ptrCelulaExcluida->pProx;
    }
    if (ptrCelulaExcluida == NULL) return 0; //retorna 0, para demonstrar que nao foi identificado este ID na lista
    else {
        //exclui a celula desejada
        CelulaCompromisso* ptrauxiliar;
        ptrauxiliar = ptrCelulaExcluida;
        ponteiroanterior->pProx = ptrCelulaExcluida->pProx;
        free(ptrauxiliar);
        return 1; // retorna 1, para demonstrar que a exclusao foi um sucesso
    }
}

//imprime todos os compromissos em ordem decrescente(em relacao a prioridade)
void imprimeCompromissos(ListaCompromisso lista){
    for (int prioridadeAtual = 1; prioridadeAtual <= 5;prioridadeAtual++){
        CelulaCompromisso* compromissoAtual = lista.pPrimeiro->pProx;
        while (compromissoAtual != NULL){
            if(retorna_prioridade(&(compromissoAtual->ItemCompromisso)) == prioridadeAtual){
                imprime_compromisso(compromissoAtual->ItemCompromisso);
            }
            compromissoAtual = compromissoAtual->pProx;
        }
    }
}

//imprime depois da data especificada
void imprimeDpsData(ListaCompromisso comps, Data inputdata){
    int contador;
    CelulaCompromisso* ponteiroauxiliar;
    ponteiroauxiliar = comps.pPrimeiro->pProx;
    contador = 0;
    while (ponteiroauxiliar != NULL)
    {
        if (GetAno(returnData(ponteiroauxiliar->ItemCompromisso)) > GetAno(inputdata)){
            contador += 1;
        }
        else if (GetAno(returnData(ponteiroauxiliar->ItemCompromisso)) == GetAno(inputdata)){
            if (GetMes(returnData(ponteiroauxiliar->ItemCompromisso)) > GetMes(inputdata)){
                contador += 1;
            }
            else if (GetMes(returnData(ponteiroauxiliar->ItemCompromisso)) == GetMes(inputdata)){
                if (GetDia(returnData(ponteiroauxiliar->ItemCompromisso)) >= GetDia(inputdata)){
                    contador +=1;
                }
            }
        }
        ponteiroauxiliar = ponteiroauxiliar->pProx;
    }
    printf("\nNumero de compromissos apos a data: %d\n",contador);
}
