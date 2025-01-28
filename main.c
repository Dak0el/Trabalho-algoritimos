#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "cadastro.h"
/*====================================================
Integrantes: Daniel Machado & Matheus Henrique
Trabalho de Algoritimos II.
Sistema de Gerenciamento para Oficina Mec�nica
======================================================*/
// Menu Principal
int typedoc;

int menu() {
    int op=0,cod,x;

    while (1) {

        printf("\n________________Menu________________\n");
        printf("Digite o n�mero da opera��o que deseja fazer:\n");
        printf("|1-Cadastro\n");
        printf("|2-Consulta\n");
        printf("|3-Sair\n");
        printf("|4-Limpar tela\n");
        printf("|5-Apagar Cadastro\n");
        printf("|6-Alterar Cadastro\n");
        printf("|7-Trocar modo de leitura, modo atual: %s\n", typedoc == 1 ? "Texto" : "Bin�rio");
        printf("|8-Nota fiscal\n");
        printf("|9-Caixa\n");
        printf("|10-Agendamento\n");
        printf("Escolha: ");
        scanf("%d", &op);
        getchar();

        switch (op) {
            case 1:  // Cadastro
                printf("CADASTRO\n");
                printf("O que deseja fazer?\n");
                printf("|1-Oficina\n");
                printf("|2-Cliente\n");
                printf("|3-Ve�culo\n");
                printf("|4-Pe�as\n");
                printf("|5-Fornecedor\n");
                printf("|6-Servi�o\n");
                printf("|7-Funcion�rio\n");
                printf("|8-Voltar\n");
                printf("Escolha: ");
                scanf("%d", &op);
                getchar();

                switch (op) {
                    case 1:
                        do{
                        cod = cadastro_oficina();
                        if (cod==2){
                                printf("Saida do usu�rio.\n");
                        }else if (cod == 0) {
                            printf("Cadastro realizado com sucesso!\n");
                        } else if (cod == -1) {
                            printf("Erro ao alocar mem�ria.\n");
                        } else if (cod == -2) {
                            printf("Erro no arquivo.\n");
                        }
                        printf("Deseja cadastrar outra Oficina?\n");
                        printf("1 - Sim, continuar\n");
                        printf("0 - N�o, finalizar e salvar\n");
                        if (scanf("%d", &x) != 1) {//Verifica se a entrada � valida
                            printf("Entrada inv�lida. Saindo do cadastro.\n");
                            x = 0;//sai do loop
                        }
                        getchar();
                        }while(x==1);
                        cod = salvar_oficina();
                            if (cod == 0) {
                            printf("Cadastro salvo com sucesso!\n");
                        }else if (cod == -2) {
                            printf("Erro no arquivo.\n");
                        }
                        break;
//============================================================================================================
                    case 2:
                    do {
                        cod = cadastro_cliente();
                        if (cod == 2){
                                printf("Saida do usu�rio.\n");
                        }else if (cod == 0){
                                printf("Cadastro feito.\n");
                        }else if (cod == -1) {
                            printf("Erro ao alocar mem�ria.\n");
                        } else if (cod == -2) {
                            printf("Erro no arquivo.\n");
                        }

                        printf("Deseja cadastrar outro Cliente?\n");
                        printf("1 - Sim, continuar\n");
                        printf("0 - N�o, finalizar e salvar\n");

                        if (scanf("%d", &x) != 1) {
                            printf("Entrada inv�lida. Saindo do cadastro.\n");
                            x = 0;
                        }
                        getchar();
                    } while (x == 1);

                    cod = salvar_cliente();
                    if (cod == 0) {
                        printf("Clientes salvos com sucesso!\n");
                    } else if (cod == -2) {
                        printf("Erro no arquivo.\n");
                    }
                    break;
//============================================================================================================
                    case 3:
                        do{
                        cod = cadastro_veiculo();
                        if (cod == 2){
                            printf("Saida do usu�rio.\n");
                        }else if (cod == 0) {
                            printf("Cadastro realizado com sucesso!\n");
                        } else if (cod == -1) {
                            printf("Erro ao alocar mem�ria.\n");
                        } else if (cod == -2) {
                            printf("Erro no arquivo.\n");
                        }
                        printf("Deseja cadastrar outro Veiculo?\n");
                        printf("1 - Sim, continuar\n");
                        printf("0 - N�o, finalizar e salvar\n");

                        if (scanf("%d", &x) != 1) {//Verifica se a entrada � valida
                            printf("Entrada inv�lida. Saindo do cadastro.\n");
                            x = 0;//sai do loop
                        }
                        getchar();

                        }while(x==1);

                        cod = salvar_veiculo();
                            if (cod == 0) {
                            printf("Cadastro salvo com sucesso!\n");
                        }else if (cod == -2) {
                            printf("Erro no arquivo.\n");
                        }

                        break;
//============================================================================================================
                    case 4:  // Cadastro de Pe�as
                        do{
                        cod = cadastro_pecas();
                        if (cod == 2){
                                printf("Saida do usu�rio.\n");
                        }else if (cod == 0){
                                printf("Cadastro feito.\n");
                        }else if (cod == -1) {
                            printf("Erro ao alocar mem�ria.\n");
                        } else if (cod == -2) {
                            printf("Erro no arquivo.\n");
                        }
                        printf("Deseja cadastrar outra pe�a?\n");
                        printf("1 - Sim, continuar\n");
                        printf("0 - N�o, finalizar e salvar\n");

                        if (scanf("%d", &x) != 1) {//Verifica se a entrada � valida
                            printf("Entrada inv�lida. Saindo do cadastro.\n");
                            x = 0;//sai do loop
                        }
                        getchar();

                        }while(x==1);

                        cod = salvar_peca();
                            if (cod == 0) {
                            printf("Cadastro salvo com sucesso!\n");
                        }else if (cod == -2) {
                            printf("Erro no arquivo.\n");
                        }

                        break;
//============================================================================================================
                    case 5:
                        do{
                        cod = cadastro_fornecedor();
                        if (cod == 2){
                                printf("Saida do usu�rio.\n");
                        }else if (cod == 0){
                                printf("Cadastro feito.\n");
                        }else if (cod == -1) {
                            printf("Erro ao alocar mem�ria.\n");
                        } else if (cod == -2) {
                            printf("Erro no arquivo.\n");
                        }
                        printf("Deseja cadastrar outro fornecedor?\n");
                        printf("1 - Sim, continuar\n");
                        printf("0 - N�o, finalizar e salvar\n");

                        if (scanf("%d", &x) != 1) {//Verifica se a entrada � valida
                            printf("Entrada inv�lida. Saindo do cadastro.\n");
                            x = 0;//sai do loop
                        }
                        getchar();

                        }while(x==1);

                        cod = salvar_fornecedor();
                            if (cod == 0) {
                            printf("Cadastro salvo com sucesso!\n");
                        }else if (cod == -2) {
                            printf("Erro no arquivo.\n");
                        }

                        break;
//============================================================================================================
                    case 6:
                        do{
                        cod = cadastro_servico();
                        if (cod == 2){
                                printf("Saida do usu�rio.\n");
                        }else if (cod == 0){
                                printf("Cadastro feito.\n");
                        }else if (cod == -1) {
                            printf("Erro ao alocar mem�ria.\n");
                        } else if (cod == -2) {
                            printf("Erro no arquivo.\n");
                        }
                        printf("Deseja cadastrar outro servi�o?\n");
                        printf("1 - Sim, continuar\n");
                        printf("0 - N�o, finalizar e salvar\n");

                        if (scanf("%d", &x) != 1) {//Verifica se a entrada � valida
                            printf("Entrada inv�lida. Saindo do cadastro.\n");
                            x = 0;//sai do loop
                        }
                        getchar();

                        }while(x==1);

                        cod = salvar_servico();
                            if (cod == 0) {
                            printf("Cadastro salvo com sucesso!\n");
                        }else if (cod == -2) {
                            printf("Erro no arquivo.\n");
                        }

                        break;
//============================================================================================================
                    case 7:
                        do{
                        cod = cadastro_funcionario();
                        if (cod == 2){
                                printf("Saida do usu�rio.\n");
                        }else if (cod == 0){
                                printf("Cadastro feito.\n");
                        }else if (cod == -1) {
                            printf("Erro ao alocar mem�ria.\n");
                        } else if (cod == -2) {
                            printf("Erro no arquivo.\n");
                        }
                        printf("Deseja cadastrar outro funcion�rio?\n");
                        printf("1 - Sim, continuar\n");
                        printf("0 - N�o, finalizar e salvar\n");

                        if (scanf("%d", &x) != 1) {//Verifica se a entrada � valida
                            printf("Entrada inv�lida. Saindo do cadastro.\n");
                            x = 0;//sai do loop
                        }
                        getchar();

                        }while(x==1);

                        cod = salvar_funcionario();
                            if (cod == 0) {
                            printf("Cadastro salvo com sucesso!\n");
                        }else if (cod == -2) {
                            printf("Erro no arquivo.\n");
                        }

                        break;
//============================================================================================================
                    case 8:  // Voltar
                        break;
//============================================================================================================
                    default:
                        printf("Opcao invalida.\n");
                        break;
//============================================================================================================
                }
break;

case 2:  // Consulta
                printf("CONSULTA\n");
                printf("O que deseja fazer?\n");
                printf("|1-Oficina\n");
                printf("|2-Cliente\n");
                printf("|3-Ve�culo\n");
                printf("|4-Pe�as\n");
                printf("|5-Fornecedor\n");
                printf("|6-Servi�o\n");
                printf("|7-Funcion�rio\n");
                printf("|8-Voltar\n");
                printf("Escolha: ");
                scanf("%d", &op);
                getchar();

                switch (op) {
                    case 1:
                        printf("Oficinas Cadastradas:\n");
                        cod = consulta_oficina();
                        if(cod==-2){
                            printf("Erro na abertura do arquivo.\n");
                        }
                        break;
//============================================================================================================
                    case 2:
                        printf("Clientes Cadastrados:\n");
                        cod = consulta_clientes();
                        if(cod==-2){
                            printf("Erro na abertura do arquivo.\n");
                        }
                        break;
//============================================================================================================
                    case 3:
                        printf("Veiculos Cadastrados:\n");
                        cod = consulta_veiculos();
                        if(cod==-2){
                            printf("Erro na abertura do arquivo.\n");
                        }
                        break;
//============================================================================================================
                    case 4:  // Consulta de Pe�as
                        printf("Pe�as Cadastradas:\n");
                        cod = consulta_pecas();
                        if(cod==-2){
                            printf("Erro na abertura do arquivo.\n");
                        }
                        break;
//============================================================================================================
                    case 5:
                        printf("Fornecedores Cadastrados:\n");
                        cod = consulta_fornecedores();
                        if(cod==-2){
                            printf("Erro na abertura do arquivo.\n");
                        }
                        break;
//============================================================================================================
                    case 6:
                        printf("Servi�os Cadastrados:\n");
                        cod = consulta_servicos();
                        if(cod==-2){
                            printf("Erro na abertura do arquivo.\n");
                        }
                        break;
//============================================================================================================
                    case 7:
                        printf("Funcion�rios Cadastrados:\n");
                        cod = consulta_funcionarios();
                        if(cod==-2){
                            printf("Erro na abertura do arquivo.\n");
                        }
                        break;
//============================================================================================================
                    case 8:  // Voltar
                        break;
//============================================================================================================
                    default:
                        printf("Opcao invalida.\n");
                        break;
                }
break;

case 3:  // Sair
                printf("Saindo do programa!");
                return;
break;

case 4:  // Limpar Tela
                system("cls");  // Para Windows
                // system("clear");  // Para Linux/Mac
break;

case 5:
                printf("EXCLUS�O\n");
                printf("O que deseja fazer?\n");
                printf("|1-Oficina\n");
                printf("|2-Cliente\n");
                printf("|3-Ve�culo\n");
                printf("|4-Pe�as\n");
                printf("|5-Fornecedor\n");
                printf("|6-Servi�o\n");
                printf("|7-Funcion�rio\n");
                printf("|8-Voltar\n");
                printf("Escolha: ");
                scanf("%d", &op);
                getchar();

                switch (op) {
             case 1:
                 do{
                 cod = excluir_oficina();
                 if(cod==0){
                    printf("Exlus�o concluida com sucesso.\n");
                 }else if(cod==1){
                    printf("Registro n�o encontrado\n");
                }else if(cod==-2){
                    printf("Erro na abertura do arquivo.\n");
                }else if(cod==-4){
                    printf("Erro na manipula��o do arquivo.\n");
                }
                 printf("Deseja Excluir outra oficina?\n");
                printf("1-Sim 2-N�o\n");
                scanf("%d",&x);
                getchar();
                }while(x==1);
                break;
//============================================================================================================
             case 2:
                 do{
                 cod = excluir_cliente();
                 if(cod==0){
                    printf("Exlus�o concluida com sucesso.\n");
                 }else if(cod==1){
                    printf("Registro n�o encontrado\n");
                }else if(cod==-2){
                    printf("Erro na abertura do arquivo.\n");
                }else if(cod==-4){
                    printf("Erro na manipula��o do arquivo.\n");
                }
                 printf("Deseja Excluir outra oficina?\n");
                printf("1-Sim 2-N�o\n");
                scanf("%d",&x);
                getchar();
                }while(x==1);
                break;
//============================================================================================================
             case 3:
                 do{
                 cod = excluir_veiculo();
                    if(cod==0){
                    printf("Exlus�o concluida com sucesso.\n");
                 }else if(cod==1){
                    printf("Registro n�o encontrado\n");
                }else if(cod==-2){
                    printf("Erro na abertura do arquivo.\n");
                }else if(cod==-4){
                    printf("Erro na manipula��o do arquivo.\n");
                }
                 printf("Deseja Excluir outra oficina?\n");
                printf("1-Sim 2-N�o\n");
                scanf("%d",&x);
                getchar();
                }while(x==1);
                break;
//============================================================================================================
             case 4:
                 do{
                 cod = excluir_peca();
                 if(cod==0){
                    printf("Exlus�o concluida com sucesso.\n");
                 }else if(cod==1){
                    printf("Registro n�o encontrado\n");
                }else if(cod==-2){
                    printf("Erro na abertura do arquivo.\n");
                }else if(cod==-4){
                    printf("Erro na manipula��o do arquivo.\n");
                }
                 printf("Deseja Excluir outra oficina?\n");
                printf("1-Sim 2-N�o\n");
                scanf("%d",&x);
                getchar();
                }while(x==1);
                break;
//============================================================================================================
             case 5:
                 do{
                 cod = excluir_fornecedor();
                 if(cod==0){
                    printf("Exlus�o concluida com sucesso.\n");
                 }else if(cod==1){
                    printf("Registro n�o encontrado\n");
                }else if(cod==-2){
                    printf("Erro na abertura do arquivo.\n");
                }else if(cod==-4){
                    printf("Erro na manipula��o do arquivo.\n");
                }
                 printf("Deseja Excluir outra oficina?\n");
                printf("1-Sim 2-N�o\n");
                scanf("%d",&x);
                getchar();
                }while(x==1);
                break;
//============================================================================================================
             case 6:
                 do{
                cod = excluir_servico();
                if(cod==0){
                    printf("Exlus�o concluida com sucesso.\n");
                 }else if(cod==1){
                    printf("Registro n�o encontrado\n");
                }else if(cod==-2){
                    printf("Erro na abertura do arquivo.\n");
                }else if(cod==-4){
                    printf("Erro na manipula��o do arquivo.\n");
                }
                 printf("Deseja Excluir outra oficina?\n");
                printf("1-Sim 2-N�o\n");
                scanf("%d",&x);
                getchar();
                }while(x==1);
                break;
//============================================================================================================
             case 7:
                 do{
                cod = excluir_funcionario();
                if(cod==0){
                    printf("Exlus�o concluida com sucesso.\n");
                 }else if(cod==1){
                    printf("Registro n�o encontrado\n");
                }else if(cod==-2){
                    printf("Erro na abertura do arquivo.\n");
                }else if(cod==-4){
                    printf("Erro na manipula��o do arquivo.\n");
                }
                 printf("Deseja Excluir outra oficina?\n");
                printf("1-Sim 2-N�o\n");
                scanf("%d",&x);
                getchar();
                }while(x==1);
                break;
//============================================================================================================
             case 8:
                break;
//============================================================================================================
             default:
                printf("Op��o0 inv�lida.\n");
                break;
                }
break;

case 6:
                 printf("ALTERACAO\n");
                printf("O que deseja fazer?\n");
                printf("|1-Oficina\n");
                printf("|2-Cliente\n");
                printf("|3-Ve�culo\n");
                printf("|4-Pe�as\n");
                printf("|5-Fornecedor\n");
                printf("|6-Servi�o\n");
                printf("|7-Funcion�rio\n");
                printf("|8-Voltar\n");
                printf("Escolha: ");
                scanf("%d", &op);
                getchar();
                switch (op) {
                case 1:
                    cod = alterar_oficina();
                    if(cod == 0){
                        printf("Altera��o feita com sucesso.\n");
                    }else if(cod == 1){
                        printf("Cadastro n�o encontrado.\n");
                    }else if(cod == -2){
                        printf("Erro na abertura do arquivo.\n");
                    }else if(cod == -3){
                        printf("Erro entrada inv�lida.\n");
                    }else if(cod == -4){
                        printf("Erro na manipula��o do arquivo.\n");
                    }
                    break;
//============================================================================================================
                case 2:
                    cod = alterar_cliente();
                    if(cod == 0){
                        printf("Altera��o feita com sucesso.\n");
                    }else if(cod == 1){
                        printf("Cadastro n�o encontrado.\n");
                    }else if(cod == -2){
                        printf("Erro na abertura do arquivo.\n");
                    }else if(cod == -3){
                        printf("Erro entrada inv�lida.\n");
                    }else if(cod == -4){
                        printf("Erro na manipula��o do arquivo.\n");
                    }
                    break;
//============================================================================================================
                case 3:
                    cod = alterar_veiculo();
                    if(cod == 0){
                        printf("Altera��o feita com sucesso.\n");
                    }else if(cod == 1){
                        printf("Cadastro n�o encontrado.\n");
                    }else if(cod == -2){
                        printf("Erro na abertura do arquivo.\n");
                    }else if(cod == -3){
                        printf("Erro entrada inv�lida.\n");
                    }else if(cod == -4){
                        printf("Erro na manipula��o do arquivo.\n");
                    }
                    break;
//============================================================================================================
                case 4:
                    cod = alterar_peca();
                    if(cod == 0){
                        printf("Altera��o feita com sucesso.\n");
                    }else if(cod == 1){
                        printf("Cadastro n�o encontrado.\n");
                    }else if(cod == -2){
                        printf("Erro na abertura do arquivo.\n");
                    }else if(cod == -3){
                        printf("Erro entrada inv�lida.\n");
                    }else if(cod == -4){
                        printf("Erro na manipula��o do arquivo.\n");
                    }
                    break;
//============================================================================================================
                case 5:
                    cod = alterar_fornecedor();
                    if(cod == 0){
                        printf("Altera��o feita com sucesso.\n");
                    }else if(cod == 1){
                        printf("Cadastro n�o encontrado.\n");
                    }else if(cod == -2){
                        printf("Erro na abertura do arquivo.\n");
                    }else if(cod == -3){
                        printf("Erro entrada inv�lida.\n");
                    }else if(cod == -4){
                        printf("Erro na manipula��o do arquivo.\n");
                    }
                    break;
//============================================================================================================
                case 6:
                    cod = alterar_servico();
                    if(cod == 0){
                        printf("Altera��o feita com sucesso.\n");
                    }else if(cod == 1){
                        printf("Cadastro n�o encontrado.\n");
                    }else if(cod == -2){
                        printf("Erro na abertura do arquivo.\n");
                    }else if(cod == -3){
                        printf("Erro entrada inv�lida.\n");
                    }else if(cod == -4){
                        printf("Erro na manipula��o do arquivo.\n");
                    }
                    break;
//============================================================================================================
                case 7:
                    cod = alterar_funcionario();
                    if(cod == 0){
                        printf("Altera��o feita com sucesso.\n");
                    }else if(cod == 1){
                        printf("Cadastro n�o encontrado.\n");
                    }else if(cod == -2){
                        printf("Erro na abertura do arquivo.\n");
                    }else if(cod == -3){
                        printf("Erro entrada inv�lida.\n");
                    }else if(cod == -4){
                        printf("Erro na manipula��o do arquivo.\n");
                    }
                    break;
//============================================================================================================
                case 8:
                    break;
//============================================================================================================
                default:
                    printf("Valor inv�lido.\n");
                    break;
                }
break;

case 7:
        troca();
break;

case 8:
        cod=entrada_nota_fiscal();
                    if(cod == 0){
                        printf("Nota feita com sucesso.\n");
                    }else if(cod == 1){
                        printf("Cadastro n�o encontrado.\n");
                    }else if(cod == -2){
                        printf("Erro na abertura do arquivo.\n");
                    }else if(cod == -3){
                        printf("Erro entrada inv�lida.\n");
                    }else if(cod == -4){
                        printf("Erro na manipula��o do arquivo.\n");
                    }
        cod = apply_fiscal();
                    if(cod == 0){
                        printf("Estoque atualizado.\n");
                    }else if(cod == 1){
                        printf("Cadastro n�o encontrado.\n");
                    }else if(cod == -2){
                        printf("Erro na abertura do arquivo.\n");
                    }else if(cod == -3){
                        printf("Erro entrada inv�lida.\n");
                    }else if(cod == -4){
                        printf("Erro na manipula��o do arquivo.\n");
                    }
break;

case 9:
caixa:
        printf("\nCAIXA\n");
         printf("1-Controle de Caixa\n");
         printf("2-Contas a Receber\n");
         printf("3-Contas a Pagar\n");
         printf("4-Sair\n");
         printf("Escolha sua op��o:");
         scanf("%d",&op);
         getchar();
         printf("\n");

             switch(op){
            case 1:
                 do {
            printf("CONTROLE DE CAIXA\n");
            printf("1 - Registrar Transa��o\n");
            printf("2 - Consultar Lan�amentos\n");
            printf("3 - Exibir Saldo Atual\n");
            printf("4 - Voltar\n");
            printf("0 - Sair\n");
            printf("Escolha uma op��o: ");
            scanf("%d", &op);
            getchar(); // Limpa o buffer
            printf("\n");

                    switch (op) {
                        case 1: // Registrar uma transa��o no caixa
                            cod = registrar_transacao();
                            if (cod == 0) {
                                printf("Transa��o registrada com sucesso!\n");
                            } else if (cod == -2) {
                                printf("Erro ao acessar o arquivo de caixa.\n");
                            } else {
                                printf("Erro desconhecido ao registrar a transa��o.\n");
                            }
                            break;
                        case 2: // Consultar lan�amentos do caixa
                            cod = consultar_lancamentos();
                            if (cod == 0) {
                                printf("Consulta de lan�amentos realizada com sucesso!\n");
                            } else if (cod == -2) {
                                printf("Erro ao acessar o arquivo de caixa.\n");
                            } else {
                                printf("Erro desconhecido ao consultar lan�amentos.\n");
                            }
                            break;
                        case 3: // Exibir saldo atual
                            cod = exibir_saldo_atual();
                            if (cod == 0) {
                                printf("Saldo exibido com sucesso!\n");
                            } else if (cod == -2) {
                                printf("Erro ao acessar o arquivo de caixa.\n");
                            } else {
                                printf("Erro desconhecido ao exibir saldo.\n");
                            }
                            break;
                         case 4:
                            goto caixa;
                        break;
                        case 0:
                        break;
                        default:
                            printf("Op��o inv�lida. Tente novamente.\n");
                            break;
                    }
                } while (op != 0);
                break;
            break;
//============================================================================================================
        case 2:
                 do {
            printf("CONTAS A RECEBER\n");
            printf("1 - Registrar Conta a Receber\n");
            printf("2 - Consultar Contas a Receber\n");
            printf("3 - Baixar Conta a Receber\n");
            printf("4 - Voltar\n");
            printf("0 - Sair\n");
            printf("Escolha uma op��o: ");
            scanf("%d", &op);
            getchar(); // Limpa o buffer
            printf("\n");

                    switch (op) {
                        case 1: // Registrar uma nova conta a receber
                            cod = registrar_conta_receber();
                            if (cod == 0) {
                                printf("Conta a receber registrada com sucesso!\n");
                            } else if (cod == -2) {
                                printf("Erro ao acessar o arquivo de contas a receber.\n");
                            } else {
                                printf("Erro desconhecido ao registrar conta a receber.\n");
                            }
                            break;
                        case 2: // Consultar contas a receber
                            printf("Contas a Receber:\n");
                            printf("Descri��o\tValor\tVencimento\tStatus\n");
                            cod = consultar_contas_receber();
                            if (cod == 0) {
                                printf("Consulta realizada com sucesso!\n");
                            } else if (cod == -2) {
                                printf("Erro ao acessar o arquivo de contas a receber.\n");
                            } else {
                                printf("Erro desconhecido ao consultar contas a receber.\n");
                            }
                            break;
                        case 3: // Baixar uma conta a receber
                            cod = baixar_conta_receber();
                            if (cod == 0) {
                                printf("Conta a receber baixada com sucesso!\n");
                            } else if(cod == 1){
                                printf("Conta n�o encontrada.\n");
                            }else if (cod == -2) {
                                printf("Erro ao acessar o arquivo de contas a receber ou de caixa.\n");
                            } else {
                                printf("Erro desconhecido ao baixar conta a receber.\n");
                            }
                            break;
                         case 4:
                            goto caixa;
                        break;
                        case 0:
                        break;
                        default:
                            printf("Op��o inv�lida. Tente novamente.\n");
                            break;
                    }
                } while (op != 0);
        break;
//============================================================================================================
        case 3:
                do {
        printf("CONTAS A PAGAR\n");
        printf("1 - Registrar Conta a Pagar\n");
        printf("2 - Consultar Contas a Pagar\n");
        printf("3 - Baixar Conta a Pagar\n");
        printf("4 - Voltar\n");
        printf("0 - Sair\n");
        printf("Escolha uma op��o: ");
        scanf("%d", &op);
        getchar(); // Limpa o buffer
        printf("\n");

                switch (op) {
                    case 1: // Registrar uma nova conta a pagar
                        cod = registrar_conta_pagar();
                        if (cod == 0) {
                            printf("Conta a pagar registrada com sucesso!\n");
                        } else if (cod == -2) {
                            printf("Erro ao acessar o arquivo de contas a pagar.\n");
                        } else {
                            printf("Erro desconhecido ao registrar conta a pagar.\n");
                        }
                        break;

                    case 2: // Consultar contas a pagar
                        cod = consultar_contas_pagar();
                        if (cod == 0) {
                            printf("Consulta realizada com sucesso!\n");
                        } else if (cod == -2) {
                            printf("Erro ao acessar o arquivo de contas a pagar.\n");
                        } else {
                            printf("Erro desconhecido ao consultar contas a pagar.\n");
                        }
                        break;

                    case 3: // Baixar uma conta a pagar
                        cod = baixar_conta_pagar();
                        if (cod == 0) {
                            printf("Conta a pagar baixada com sucesso!\n");
                        } else if(cod == 1){
                            printf("Conta n�o encontrada.\n");
                        }else if (cod == -2) {
                            printf("Erro ao acessar o arquivo de contas a pagar ou de caixa.\n");
                        } else {
                            printf("Erro desconhecido ao baixar conta a pagar.\n");
                        }
                        break;

                    case 4:
                        goto caixa;
                        break;
                    case 0:
                        break;
                    default:
                        printf("Op��o inv�lida. Tente novamente.\n");
                        break;
                }
            } while (op != 0);
        break;
         default:
            break;
//============================================================================================================
            case 4:
            break;
             }
        break;
            case 10:
                        do {
                printf("AGENDAMENTO\n");
                printf("1 - Registrar Agendamento\n");
                printf("2 - Consultar Agendamentos\n");
                printf("3 - Ordem de Servi�o\n");
                printf("4 - Finalizar Ordem de Servi�o\n");
                printf("5 - Consultar Ordens de Servi�os\n");
                printf("0 - Sair\n");
                printf("Escolha uma op��o: ");
                scanf("%d", &op);
                getchar(); // Limpa o buffer
                printf("\n");

                        switch (op) {
                            case 1: // Registrar uma nova conta a pagar
                                agendamento();
                            case 2: // Consultar contas a pagar
                                consulta_agendamento();
                                break;
                            case 3:
                                ordem_servico();
                                break;
                            case 4:
                                finalizar_ordem();
                                break;
                            case 5:
                                consulta_ordens();
                                break;
                            case 0:
                                break;
                            default:
                                printf("Op��o inv�lida. Tente novamente.\n");
                                break;
                        }
                    } while (op != 0);
                break;
            default:
                printf("Op��o inv�lida.\n");
    break;
        }
    }
}

int copy_element(){
    int x;
     printf("Item j� cadastrado. Deseja repetir a a��o?\n");
    printf("1-Sair, 2-Repetir: ");
    scanf("%d", &x);
    getchar();
    return x;
}

int not_found(){
    int x;
     printf("Item n�o encontrado. Deseja repetir a a��o?\n");
    printf("1-Sair, 2-Repetir: ");
    scanf("%d", &x);
    getchar();
    return x;
}

int repeat(){
    int x;
    printf("Deseja repetir a a��o?\n 1-Sim 2-N�o\n");
    scanf("%d",&x);
    return x;
}

int invalid_in(){
    printf("Valor de entrada inv�lido.\n");
}

void print_oficina(OFICINA o){
     printf("Nome: %s, CPF/CNPJ: %s, Endere�o: %s, \nTelefone: %s, E-mail: %s, Percentual de lucro: %.2f\n",
            o.nome, o.cpf, o.endereco, o.telefone, o.email, o.lucro);
    printf("===========================================================================================\n");
}

void print_cliente(CLIENTE c){
     printf("Codigo: %d, Nome: %s, CPF: %s, Endere�o: %s, \nTelefone: %s, email: %s\n",
                   c.codigo, c.nome, c.cpf, c.endereco, c.telefone, c.email);
            printf("===========================================================================================\n");
}

void print_veiculo(VEICULOS v){
    printf("Placa: %s, Modelo: %s, Marca: %s, \nAno de Fabrica��o: %d, Chassi: %s ,CPF do Propriet�rio: %s\n",
            v.placa, v.modelo, v.marca, v.anof, v.chassi, v.ptt);
    printf("===========================================================================================\n");
}

void print_pecas(PECA p){
     printf("C�digo: %d, Descri��o: %s, Fabricante: %s, Fornecedor: %s, \nPre�o de Custo: %.2f, Pre�o de Venda: %.2f, Quantidade: %d, Estoque M�nimo: %d\n",
                   p.codigo, p.descricao, p.fabricante, p.fornecedor,
                   p.p_custo, p.p_venda, p.qntd_estoque, p.qntd_minima);
                   if(p.qntd_estoque<=p.qntd_minima){
                    printf("ESTOQUE BAIXO!\n");
                   }
            printf("===========================================================================================\n");
}

void print_fornecedor(FORNECEDOR f){
    printf("C�digo: %d, Nome Fantasia: %s, Raz�o Social: %s, \nInscri��o Est. : %s, CNPJ: %s, Endere�o: %s, Telefone: %s, Email: %s\n",
                   f.codigo, f.nome_fantasia, f.razao_social, f.inscricao_est,
                      f.cnpj, f.endereco, f.telefone, f.email);
    printf("===========================================================================================\n");
}

void print_servico(SERVICO s){
    printf("C�digo: %d, Descri��o: %s, Pre�o: %.2f, Comiss�o: %.2f\n",
                       s.codigo, s.descricao, s.preco, s.comissao);
    printf("===========================================================================================\n");
}

void print_funcionario(FUNCIONARIO f){
    printf("Nome: %s, CPF: %s, Cargo: %s, Sal�rio: %.2f\n",
            f.nome, f.cpf, f.cargo, f.salario);
    printf("===========================================================================================\n");
}

void print_saldo(float x){
    printf("Saldo:%.2f\n",x);
    return;
}

void print_contasreceber(CONTASR c){
    printf("%s\t%.2f\t%s\t%s\n", c.descricao, c.valor, c.data_vencimento, c.status ? "Pago" : "Pendente");
}

int main() {
  setlocale(LC_ALL, "Portuguese");//permite uso de acentua��o e caracteres especiais
  setlocale(LC_NUMERIC, "C");//padrao numerico americano para manter.
    inicializa_arquivos();
    // Configura o tipo de arquivo
    typedoc = tipo_doc();

    // Chama o menu principal
    menu();
    //libera memoria n�o usada
    finalizar_dados();
    return 0;
}
