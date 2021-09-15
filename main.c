#include "ListaDeAgendas.h"
#include "stdio.h"

//definição de variável global
ListaDeAgendas listaDeAgendas;

//menu de manipulação de arquivo
int menuArquivo()
{
    //definição de variaveis locais
    FILE *pArquivo_entrada;
    Data data_arquivo;
    Horario horario_arquivo;
    Agenda agdlogin_arquivo;
    char nome_arquivo[50], nomeagd_arquivo[50], desc_arquivo[100];
    int nprof_arquivo, ncomp_arquivo, idagd_arquivo, anoagd_arquivo;
    int prio_arquivo, dia_arquivo, mes_arquivo, ano_arquivo, hora_arquivo, minuto_arquivo, dur_arquivo, horadur_arquivo, minutodur_arquivo;

    //especificação e abertura do arquivo
    printf("\nInsira o nome do arquivo (<arq>.txt):");
    scanf("%s", nome_arquivo);
    pArquivo_entrada = fopen(nome_arquivo, "r");

    //verifica se o arquivo é inexistente e retorna 0 caso ocorra
    if(pArquivo_entrada == NULL)
        return 0;

    //leitura do arquivo até o final
    while (!feof(pArquivo_entrada))
    {
        //inserção dos valores e suas respectivas funções
        fscanf(pArquivo_entrada, "%d", &nprof_arquivo);
        for (int i = 0; i < nprof_arquivo; ++i)
        {
            fscanf(pArquivo_entrada, "%d", &ncomp_arquivo);
            fscanf(pArquivo_entrada, "%d", &idagd_arquivo);
            fscanf(pArquivo_entrada, "%s", nomeagd_arquivo);
            fscanf(pArquivo_entrada, "%d", &anoagd_arquivo);
            registrarProfessor(&listaDeAgendas, idagd_arquivo, nomeagd_arquivo, anoagd_arquivo);
            login(&listaDeAgendas, &agdlogin_arquivo, idagd_arquivo);
            for (int j = 0; j < ncomp_arquivo; ++j)
            {
                fscanf(pArquivo_entrada, "%d", &prio_arquivo);
                fscanf(pArquivo_entrada, "%d", &dia_arquivo);
                fscanf(pArquivo_entrada, "%d", &mes_arquivo);
                fscanf(pArquivo_entrada, "%d", &ano_arquivo);
                fscanf(pArquivo_entrada, "%d", &hora_arquivo);
                fscanf(pArquivo_entrada, "%d", &minuto_arquivo);
                fscanf(pArquivo_entrada, "%d", &horadur_arquivo);
                fscanf(pArquivo_entrada, "%d", &minutodur_arquivo);
                fscanf(pArquivo_entrada, "%s", desc_arquivo);
                SetData(&data_arquivo, dia_arquivo, mes_arquivo, ano_arquivo);
                SetHorario(&horario_arquivo, hora_arquivo, minuto_arquivo);
                dur_arquivo = (horadur_arquivo*60)+minutodur_arquivo;
                insereCompromisso(&agdlogin_arquivo, prio_arquivo, data_arquivo, horario_arquivo, dur_arquivo, desc_arquivo);
            }
        }
    }
    fclose(pArquivo_entrada);
    return 1;
}

//menu de registro de novos professores
int menuRegistro()
{
    //definição de variaveis locais
    int idprof_reg, ano_reg;
    char nome_reg[50];
    Agenda agenda_registro;

    //inserção dos valores e suas respectivas funções
    printf("\nInsira seu Identificador:");
    scanf("%d", &idprof_reg);
    //verifica se o professor ja foi cadastrado e retorna valor 0 caso verdade
    if(login(&listaDeAgendas, &agenda_registro, idprof_reg) == 1){
        return 0;}
    printf("Insira seu Nome:");
    scanf("%s", nome_reg);
    printf("Insira o Ano:");
    scanf("%d", &ano_reg);
    registrarProfessor(&listaDeAgendas, idprof_reg, nome_reg, ano_reg);
    return 1;
}

//menu de manipulação da agenda
void menuAgenda(Agenda* agenda)
{
    //definição de variaveis locais
    Data data_agd;
    Horario horario_agd;
    int dia_agd, mes_agd, ano_agd;
    int hora_agd, minuto_agd, duracao_agd, hora_duracao_agd, minuto_duracao_agd;
    int idcomp_agd, prioridade_agd;
    char descricao_agd[100];
    int opcao_menuAgenda = 1;

    //escolha de opções
    do{
        printf("\nAgenda\n");
        printf("1. Recuperar a Agenda\n");
        printf("2. Inserir Compromisso\n");
        printf("3. Remover Compromisso\n");
        printf("4. Imprimir Agenda\n");
        printf("5. Numero total de Compromissos\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao:");
        scanf("%d", &opcao_menuAgenda);

        switch(opcao_menuAgenda){
            //inserção dos valores e suas respectivas funções
            case 1:
                printf("Insira uma data (dd/mm/aaaa):");
                scanf("%d/%d/%d", &dia_agd, &mes_agd, &ano_agd);
                SetData(&data_agd, dia_agd, mes_agd, ano_agd);
                recuperaAgenda(agenda, data_agd);
                break;

            case 2:
                printf("Insira a prioridade:");
                scanf("%d", &prioridade_agd);
                printf("Insira o dia do Compromisso:");
                scanf("%d", &dia_agd);
                printf("Insira o mes do Compromisso:");
                scanf("%d", &mes_agd);
                printf("Insira o ano do Compromisso:");
                scanf("%d", &ano_agd);
                printf("Insira a hora do Compromisso:");
                scanf("%d", &hora_agd);
                printf("Insira o minuto do Compromisso:");
                scanf("%d", &minuto_agd);
                printf("Insira as horas de duracao:");
                scanf("%d", &hora_duracao_agd);
                printf("Insira os minutos de duracao:");
                scanf("%d", &minuto_duracao_agd);
                printf("Insira a descricao:");
                scanf("%s", descricao_agd);
                SetData(&data_agd, dia_agd, mes_agd, ano_agd);
                SetHorario(&horario_agd, hora_agd, minuto_agd);
                duracao_agd = (hora_duracao_agd*60)+minuto_duracao_agd;
                insereCompromisso(agenda, prioridade_agd, data_agd, horario_agd, duracao_agd, descricao_agd);
                break;

            case 3:
                printf("Insira o ID do compromisso: ");
                scanf("%d", &idcomp_agd);
                if (removeCompromisso(agenda, idcomp_agd) == 0){
                    printf("Compromisso nao localizado.");}
                else
                    printf("Compromisso Removido!");
                break;

            case 4:
                imprimeAgenda(*agenda);
                break;

            case 5:
                printf("\n(%d) Compromisso(s) no total.\n", retornaNCompromissos(*agenda));
                break;

            case 0:
                break;

            default:
                printf("\nOpcao Invalida.\n");}
    } while (opcao_menuAgenda);
}

int main()
{
    //definição de variaveis locais
    int opcao_menuprincipal = 1, opcao_manual = 1;
    int idprof_login;
    Agenda agenda_login;

    //criação de uma lista de agendas
    inicializarAgendas(&listaDeAgendas);

    printf("\nSistema de Gerenciamento de Tempo\n");
    do
    {
        //opções de entrada
        printf("\n1. Entrada Manual\n");
        printf("2. Entrada por Arquivo\n");
        printf("0. Sair do Sistema\n");
        printf("Escolha uma opcao:");
        scanf("%d", &opcao_menuprincipal);

        switch (opcao_menuprincipal)
        {
            case 1:
                do
                {
                    //opções de entrada manual
                    printf("\n1. Registrar\n");
                    printf("2. Logar\n");
                    printf("0. Voltar\n");
                    printf("Escolha uma opcao:");
                    scanf("%d", &opcao_manual);
                    switch (opcao_manual)
                    {
                        case 1:
                            if(menuRegistro()==1)
                                printf("\nCadastro feito!\n");
                            else
                                printf("\nProfessor ja cadastrado!\n");
                            break;

                        case 2:
                            //verifica se o identificador inserido existe ou não no sistema
                            //caso exista, chama a função menuAgenda
                            printf("\nInsira seu Identificador:");
                            scanf("%d", &idprof_login);
                            if(login(&listaDeAgendas, &agenda_login, idprof_login) == 0){
                                printf("\nProfessor nao registrado.\n");}
                            else{
                                menuAgenda(&agenda_login);}
                            break;

                        case 0:
                            break;

                        default:
                            printf("\nOpcao Invalida.\n");
                    }
                }
                while (opcao_manual);
                break;

                case 2:
                    if (menuArquivo() == 0)
                        printf("\nArquivo Inexistente\n");
                    else
                        printf("\nArquivo Inserido\n");

                    break;

                case 0:
                    break;

                default:
                    printf("\nOpcao Invalida.\n");

        }
    }
    while (opcao_menuprincipal);
}