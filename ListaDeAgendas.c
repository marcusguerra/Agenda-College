#include "ListaDeAgendas.h"

//inicializa a lista com o cabecalho
void inicializarAgendas(ListaDeAgendas* agendas){
    agendas->primeiro = (CelulaDoProf*) malloc(sizeof(CelulaDoProf));
    agendas->ultimo = agendas->primeiro;
    agendas->primeiro->prox = NULL;
}

//recebe o id do professor, se ele ainda nao tiver sido registrado, retorna 0, se ele tiver, retorna 1 e armazena na variavel agenda a agenda desse professor
int login(ListaDeAgendas* agendas, Agenda* agenda,int idProf){
    CelulaDoProf* celulaAtual = agendas->primeiro->prox;
    while (celulaAtual != NULL){

        if(returnIDProf(celulaAtual->agenda) == idProf){
            *agenda = celulaAtual->agenda;
            return 1;
        }

        celulaAtual = celulaAtual->prox;
    }
    agenda = NULL;
    return 0;
}

//registra o professor e cria sua agenda
void registrarProfessor(ListaDeAgendas* agendas, int idProf, char nomeProf[50], int ano){
    agendas->ultimo->prox = (CelulaDoProf*) malloc(sizeof(CelulaDoProf));
    criaAgenda(&(agendas->ultimo->prox->agenda),idProf,nomeProf,ano);
    agendas->ultimo = agendas->ultimo->prox;
    agendas->ultimo->prox = NULL;
}
