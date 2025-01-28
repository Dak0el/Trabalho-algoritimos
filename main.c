#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "cadastro.h"
/*====================================================
Integrantes: Daniel Machado & Matheus Henrique
Trabalho de Algoritimos II.
Sistema de Gerenciamento para Oficina Mecânica
======================================================*/
// Menu Principal
int typedoc;

int menu() {
    int op=0,cod,x;

    while (1) {

        printf("\n________________Menu________________\n");
        printf("Digite o número da operação que deseja fazer:\n");
        printf("|1-Cadastro\n");
        printf("|2-Consulta\n");
        printf("|3-Sair\n");
        printf("|4-Limpar tela\n");
        printf("|5-Apagar Cadastro\n");
        printf("|6-Alterar Cadastro\n");
        printf("|7-Trocar modo de leitura, modo atual: %s\n", typedoc == 1 ? "Texto" : "Binário");
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
                printf("|3-Veículo\n");
                printf("|4-Peças\n");
                printf("|5-Fornecedor\n");
                printf("|6-Serviço\n");
                printf("|7-Funcionário\n");
                printf("|8-Voltar\n");
                printf("Escolha: ");
                scanf("%d", &op);
                getchar();

                switch (op) {
                    case 1:
                        do{
                        cod = cadastro_oficina();
                        if (cod==2){
                                printf("Saida do usuário.\n");
                        }else if (cod == 0) {
                            printf("Cadastro realizado com sucesso!\n");
                        } else if (cod == -1) {
                            printf("Erro ao alocar memória.\n");
                        } else if (cod == -2) {
                            printf("Erro no arquivo.\n");
                        }
                        printf("Deseja cadastrar outra Oficina?\n");
                        printf("1 - Sim, continuar\n");
                        printf("0 - Não, finalizar e salvar\n");
                        if (scanf("%d", &x) != 1) {//Verifica se a entrada é valida
                            printf("Entrada inválida. Saindo do cadastro.\n");
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
                                printf("Saida do usuário.\n");
                        }else if (cod == 0){
                                printf("Cadastro feito.\n");
                        }else if (cod == -1) {
                            printf("Erro ao alocar memória.\n");
                        } else if (cod == -2) {
                            printf("Erro no arquivo.\n");
                        }

                        printf("Deseja cadastrar outro Cliente?\n");
                        printf("1 - Sim, continuar\n");
                        printf("0 - Não, finalizar e salvar\n");

                        if (scanf("%d", &x) != 1) {
                            printf("Entrada inválida. Saindo do cadastro.\n");
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
                            printf("Saida do usuário.\n");
                        }else if (cod == 0) {
                            printf("Cadastro realizado com sucesso!\n");
                        } else if (cod == -1) {
                            printf("Erro ao alocar memória.\n");
                        } else if (cod == -2) {
                            printf("Erro no arquivo.\n");
                        }
                        printf("Deseja cadastrar outro Veiculo?\n");
                        printf("1 - Sim, continuar\n");
                        printf("0 - Não, finalizar e salvar\n");

                        if (scanf("%d", &x) != 1) {//Verifica se a entrada é valida
                            printf("Entrada inválida. Saindo do cadastro.\n");
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
                    case 4:  // Cadastro de Peças
                        do{
                        cod = cadastro_pecas();
                        if (cod == 2){
                                printf("Saida do usuário.\n");
                        }else if (cod == 0){
                                printf("Cadastro feito.\n");
                        }else if (cod == -1) {
                            printf("Erro ao alocar memória.\n");
                        } else if (cod == -2) {
                            printf("Erro no arquivo.\n");
                        }
                        printf("Deseja cadastrar outra peça?\n");
                        printf("1 - Sim, continuar\n");
                        printf("0 - Não, finalizar e salvar\n");

                        if (scanf("%d", &x) != 1) {//Verifica se a entrada é valida
                            printf("Entrada inválida. Saindo do cadastro.\n");
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
                                printf("Saida do usuário.\n");
                        }else if (cod == 0){
                                printf("Cadastro feito.\n");
                        }else if (cod == -1) {
                            printf("Erro ao alocar memória.\n");
                        } else if (cod == -2) {
                            printf("Erro no arquivo.\n");
                        }
                        printf("Deseja cadastrar outro fornecedor?\n");
                        printf("1 - Sim, continuar\n");
                        printf("0 - Não, finalizar e salvar\n");

                        if (scanf("%d", &x) != 1) {//Verifica se a entrada é valida
                            printf("Entrada inválida. Saindo do cadastro.\n");
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
                                printf("Saida do usuário.\n");
                        }else if (cod == 0){
                                printf("Cadastro feito.\n");
                        }else if (cod == -1) {
                            printf("Erro ao alocar memória.\n");
                        } else if (cod == -2) {
                            printf("Erro no arquivo.\n");
                        }
                        printf("Deseja cadastrar outro serviço?\n");
                        printf("1 - Sim, continuar\n");
                        printf("0 - Não, finalizar e salvar\n");

                        if (scanf("%d", &x) != 1) {//Verifica se a entrada é valida
                            printf("Entrada inválida. Saindo do cadastro.\n");
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
                                printf("Saida do usuário.\n");
                        }else if (cod == 0){
                                printf("Cadastro feito.\n");
                        }else if (cod == -1) {
                            printf("Erro ao alocar memória.\n");
                        } else if (cod == -2) {
                            printf("Erro no arquivo.\n");
                        }
                        printf("Deseja cadastrar outro funcionário?\n");
                        printf("1 - Sim, continuar\n");
                        printf("0 - Não, finalizar e salvar\n");

                        if (scanf("%d", &x) != 1) {//Verifica se a entrada é valida
                            printf("Entrada inválida. Saindo do cadastro.\n");
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
                printf("|3-Veículo\n");
                printf("|4-Peças\n");
                printf("|5-Fornecedor\n");
                printf("|6-Serviço\n");
                printf("|7-Funcionário\n");
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
                    case 4:  // Consulta de Peças
                        printf("Peças Cadastradas:\n");
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
                        printf("Serviços Cadastrados:\n");
                        cod = consulta_servicos();
                        if(cod==-2){
                            printf("Erro na abertura do arquivo.\n");
                        }
                        break;
//============================================================================================================
                    case 7:
                        printf("Funcionários Cadastrados:\n");
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
                printf("EXCLUSÃO\n");
                printf("O que deseja fazer?\n");
                printf("|1-Oficina\n");
                printf("|2-Cliente\n");
                printf("|3-Veículo\n");
                printf("|4-Peças\n");
                printf("|5-Fornecedor\n");
                printf("|6-Serviço\n");
                printf("|7-Funcionário\n");
                printf("|8-Voltar\n");
                printf("Escolha: ");
                scanf("%d", &op);
                getchar();

                switch (op) {
             case 1:
                 do{
                 cod = excluir_oficina();
                 if(cod==0){
                    printf("Exlusão concluida com sucesso.\n");
                 }else if(cod==1){
                    printf("Registro não encontrado\n");
                }else if(cod==-2){
                    printf("Erro na abertura do arquivo.\n");
                }else if(cod==-4){
                    printf("Erro na manipulação do arquivo.\n");
                }
                 printf("Deseja Excluir outra oficina?\n");
                printf("1-Sim 2-Não\n");
                scanf("%d",&x);
                getchar();
                }while(x==1);
                break;
//============================================================================================================
             case 2:
                 do{
                 cod = excluir_cliente();
                 if(cod==0){
                    printf("Exlusão concluida com sucesso.\n");
                 }else if(cod==1){
                    printf("Registro não encontrado\n");
                }else if(cod==-2){
                    printf("Erro na abertura do arquivo.\n");
                }else if(cod==-4){
                    printf("Erro na manipulação do arquivo.\n");
                }
                 printf("Deseja Excluir outra oficina?\n");
                printf("1-Sim 2-Não\n");
                scanf("%d",&x);
                getchar();
                }while(x==1);
                break;
//============================================================================================================
             case 3:
                 do{
                 cod = excluir_veiculo();
                    if(cod==0){
                    printf("Exlusão concluida com sucesso.\n");
                 }else if(cod==1){
                    printf("Registro não encontrado\n");
                }else if(cod==-2){
                    printf("Erro na abertura do arquivo.\n");
                }else if(cod==-4){
                    printf("Erro na manipulação do arquivo.\n");
                }
                 printf("Deseja Excluir outra oficina?\n");
                printf("1-Sim 2-Não\n");
                scanf("%d",&x);
                getchar();
                }while(x==1);
                break;
//============================================================================================================
             case 4:
                 do{
                 cod = excluir_peca();
                 if(cod==0){
                    printf("Exlusão concluida com sucesso.\n");
                 }else if(cod==1){
                    printf("Registro não encontrado\n");
                }else if(cod==-2){
                    printf("Erro na abertura do arquivo.\n");
                }else if(cod==-4){
                    printf("Erro na manipulação do arquivo.\n");
                }
                 printf("Deseja Excluir outra oficina?\n");
                printf("1-Sim 2-Não\n");
                scanf("%d",&x);
                getchar();
                }while(x==1);
                break;
//============================================================================================================
             case 5:
                 do{
                 cod = excluir_fornecedor();
                 if(cod==0){
                    printf("Exlusão concluida com sucesso.\n");
                 }else if(cod==1){
                    printf("Registro não encontrado\n");
                }else if(cod==-2){
                    printf("Erro na abertura do arquivo.\n");
                }else if(cod==-4){
                    printf("Erro na manipulação do arquivo.\n");
                }
                 printf("Deseja Excluir outra oficina?\n");
                printf("1-Sim 2-Não\n");
                scanf("%d",&x);
                getchar();
                }while(x==1);
                break;
//============================================================================================================
             case 6:
                 do{
                cod = excluir_servico();
                if(cod==0){
                    printf("Exlusão concluida com sucesso.\n");
                 }else if(cod==1){
                    printf("Registro não encontrado\n");
                }else if(cod==-2){
                    printf("Erro na abertura do arquivo.\n");
                }else if(cod==-4){
                    printf("Erro na manipulação do arquivo.\n");
                }
                 printf("Deseja Excluir outra oficina?\n");
                printf("1-Sim 2-Não\n");
                scanf("%d",&x);
                getchar();
                }while(x==1);
                break;
//============================================================================================================
             case 7:
                 do{
                cod = excluir_funcionario();
                if(cod==0){
                    printf("Exlusão concluida com sucesso.\n");
                 }else if(cod==1){
                    printf("Registro não encontrado\n");
                }else if(cod==-2){
                    printf("Erro na abertura do arquivo.\n");
                }else if(cod==-4){
                    printf("Erro na manipulação do arquivo.\n");
                }
                 printf("Deseja Excluir outra oficina?\n");
                printf("1-Sim 2-Não\n");
                scanf("%d",&x);
                getchar();
                }while(x==1);
                break;
//============================================================================================================
             case 8:
                break;
//============================================================================================================
             default:
                printf("Opção0 inválida.\n");
                break;
                }
break;

case 6:
                 printf("ALTERACAO\n");
                printf("O que deseja fazer?\n");
                printf("|1-Oficina\n");
                printf("|2-Cliente\n");
                printf("|3-Veículo\n");
                printf("|4-Peças\n");
                printf("|5-Fornecedor\n");
                printf("|6-Serviço\n");
                printf("|7-Funcionário\n");
                printf("|8-Voltar\n");
                printf("Escolha: ");
                scanf("%d", &op);
                getchar();
                switch (op) {
                case 1:
                    cod = alterar_oficina();
                    if(cod == 0){
                        printf("Alteração feita com sucesso.\n");
                    }else if(cod == 1){
                        printf("Cadastro não encontrado.\n");
                    }else if(cod == -2){
                        printf("Erro na abertura do arquivo.\n");
                    }else if(cod == -3){
                        printf("Erro entrada inválida.\n");
                    }else if(cod == -4){
                        printf("Erro na manipulação do arquivo.\n");
                    }
                    break;
//============================================================================================================
                case 2:
                    cod = alterar_cliente();
                    if(cod == 0){
                        printf("Alteração feita com sucesso.\n");
                    }else if(cod == 1){
                        printf("Cadastro não encontrado.\n");
                    }else if(cod == -2){
                        printf("Erro na abertura do arquivo.\n");
                    }else if(cod == -3){
                        printf("Erro entrada inválida.\n");
                    }else if(cod == -4){
                        printf("Erro na manipulação do arquivo.\n");
                    }
                    break;
//============================================================================================================
                case 3:
                    cod = alterar_veiculo();
                    if(cod == 0){
                        printf("Alteração feita com sucesso.\n");
                    }else if(cod == 1){
                        printf("Cadastro não encontrado.\n");
                    }else if(cod == -2){
                        printf("Erro na abertura do arquivo.\n");
                    }else if(cod == -3){
                        printf("Erro entrada inválida.\n");
                    }else if(cod == -4){
                        printf("Erro na manipulação do arquivo.\n");
                    }
                    break;
//============================================================================================================
                case 4:
                    cod = alterar_peca();
                    if(cod == 0){
                        printf("Alteração feita com sucesso.\n");
                    }else if(cod == 1){
                        printf("Cadastro não encontrado.\n");
                    }else if(cod == -2){
                        printf("Erro na abertura do arquivo.\n");
                    }else if(cod == -3){
                        printf("Erro entrada inválida.\n");
                    }else if(cod == -4){
                        printf("Erro na manipulação do arquivo.\n");
                    }
                    break;
//============================================================================================================
                case 5:
                    cod = alterar_fornecedor();
                    if(cod == 0){
                        printf("Alteração feita com sucesso.\n");
                    }else if(cod == 1){
                        printf("Cadastro não encontrado.\n");
                    }else if(cod == -2){
                        printf("Erro na abertura do arquivo.\n");
                    }else if(cod == -3){
                        printf("Erro entrada inválida.\n");
                    }else if(cod == -4){
                        printf("Erro na manipulação do arquivo.\n");
                    }
                    break;
//============================================================================================================
                case 6:
                    cod = alterar_servico();
                    if(cod == 0){
                        printf("Alteração feita com sucesso.\n");
                    }else if(cod == 1){
                        printf("Cadastro não encontrado.\n");
                    }else if(cod == -2){
                        printf("Erro na abertura do arquivo.\n");
                    }else if(cod == -3){
                        printf("Erro entrada inválida.\n");
                    }else if(cod == -4){
                        printf("Erro na manipulação do arquivo.\n");
                    }
                    break;
//============================================================================================================
                case 7:
                    cod = alterar_funcionario();
                    if(cod == 0){
                        printf("Alteração feita com sucesso.\n");
                    }else if(cod == 1){
                        printf("Cadastro não encontrado.\n");
                    }else if(cod == -2){
                        printf("Erro na abertura do arquivo.\n");
                    }else if(cod == -3){
                        printf("Erro entrada inválida.\n");
                    }else if(cod == -4){
                        printf("Erro na manipulação do arquivo.\n");
                    }
                    break;
//============================================================================================================
                case 8:
                    break;
//============================================================================================================
                default:
                    printf("Valor inválido.\n");
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
                        printf("Cadastro não encontrado.\n");
                    }else if(cod == -2){
                        printf("Erro na abertura do arquivo.\n");
                    }else if(cod == -3){
                        printf("Erro entrada inválida.\n");
                    }else if(cod == -4){
                        printf("Erro na manipulação do arquivo.\n");
                    }
        cod = apply_fiscal();
                    if(cod == 0){
                        printf("Estoque atualizado.\n");
                    }else if(cod == 1){
                        printf("Cadastro não encontrado.\n");
                    }else if(cod == -2){
                        printf("Erro na abertura do arquivo.\n");
                    }else if(cod == -3){
                        printf("Erro entrada inválida.\n");
                    }else if(cod == -4){
                        printf("Erro na manipulação do arquivo.\n");
                    }
break;

case 9:
caixa:
        printf("\nCAIXA\n");
         printf("1-Controle de Caixa\n");
         printf("2-Contas a Receber\n");
         printf("3-Contas a Pagar\n");
         printf("4-Sair\n");
         printf("Escolha sua opção:");
         scanf("%d",&op);
         getchar();
         printf("\n");

             switch(op){
            case 1:
                 do {
            printf("CONTROLE DE CAIXA\n");
            printf("1 - Registrar Transação\n");
            printf("2 - Consultar Lançamentos\n");
            printf("3 - Exibir Saldo Atual\n");
            printf("4 - Voltar\n");
            printf("0 - Sair\n");
            printf("Escolha uma opção: ");
            scanf("%d", &op);
            getchar(); // Limpa o buffer
            printf("\n");

                    switch (op) {
                        case 1: // Registrar uma transação no caixa
                            cod = registrar_transacao();
                            if (cod == 0) {
                                printf("Transação registrada com sucesso!\n");
                            } else if (cod == -2) {
                                printf("Erro ao acessar o arquivo de caixa.\n");
                            } else {
                                printf("Erro desconhecido ao registrar a transação.\n");
                            }
                            break;
                        case 2: // Consultar lançamentos do caixa
                            cod = consultar_lancamentos();
                            if (cod == 0) {
                                printf("Consulta de lançamentos realizada com sucesso!\n");
                            } else if (cod == -2) {
                                printf("Erro ao acessar o arquivo de caixa.\n");
                            } else {
                                printf("Erro desconhecido ao consultar lançamentos.\n");
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
                            printf("Opção inválida. Tente novamente.\n");
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
            printf("Escolha uma opção: ");
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
                            printf("Descrição\tValor\tVencimento\tStatus\n");
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
                                printf("Conta não encontrada.\n");
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
                            printf("Opção inválida. Tente novamente.\n");
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
        printf("Escolha uma opção: ");
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
                            printf("Conta não encontrada.\n");
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
                        printf("Opção inválida. Tente novamente.\n");
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
                printf("3 - Ordem de Serviço\n");
                printf("4 - Finalizar Ordem de Serviço\n");
                printf("5 - Consultar Ordens de Serviços\n");
                printf("0 - Sair\n");
                printf("Escolha uma opção: ");
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
                                printf("Opção inválida. Tente novamente.\n");
                                break;
                        }
                    } while (op != 0);
                break;
            default:
                printf("Opção inválida.\n");
    break;
        }
    }
}

int copy_element(){
    int x;
     printf("Item já cadastrado. Deseja repetir a ação?\n");
    printf("1-Sair, 2-Repetir: ");
    scanf("%d", &x);
    getchar();
    return x;
}

int not_found(){
    int x;
     printf("Item não encontrado. Deseja repetir a ação?\n");
    printf("1-Sair, 2-Repetir: ");
    scanf("%d", &x);
    getchar();
    return x;
}

int repeat(){
    int x;
    printf("Deseja repetir a ação?\n 1-Sim 2-Não\n");
    scanf("%d",&x);
    return x;
}

int invalid_in(){
    printf("Valor de entrada inválido.\n");
}

void print_oficina(OFICINA o){
     printf("Nome: %s, CPF/CNPJ: %s, Endereço: %s, \nTelefone: %s, E-mail: %s, Percentual de lucro: %.2f\n",
            o.nome, o.cpf, o.endereco, o.telefone, o.email, o.lucro);
    printf("===========================================================================================\n");
}

void print_cliente(CLIENTE c){
     printf("Codigo: %d, Nome: %s, CPF: %s, Endereço: %s, \nTelefone: %s, email: %s\n",
                   c.codigo, c.nome, c.cpf, c.endereco, c.telefone, c.email);
            printf("===========================================================================================\n");
}

void print_veiculo(VEICULOS v){
    printf("Placa: %s, Modelo: %s, Marca: %s, \nAno de Fabricação: %d, Chassi: %s ,CPF do Proprietário: %s\n",
            v.placa, v.modelo, v.marca, v.anof, v.chassi, v.ptt);
    printf("===========================================================================================\n");
}

void print_pecas(PECA p){
     printf("Código: %d, Descrição: %s, Fabricante: %s, Fornecedor: %s, \nPreço de Custo: %.2f, Preço de Venda: %.2f, Quantidade: %d, Estoque Mínimo: %d\n",
                   p.codigo, p.descricao, p.fabricante, p.fornecedor,
                   p.p_custo, p.p_venda, p.qntd_estoque, p.qntd_minima);
                   if(p.qntd_estoque<=p.qntd_minima){
                    printf("ESTOQUE BAIXO!\n");
                   }
            printf("===========================================================================================\n");
}

void print_fornecedor(FORNECEDOR f){
    printf("Código: %d, Nome Fantasia: %s, Razão Social: %s, \nInscrição Est. : %s, CNPJ: %s, Endereço: %s, Telefone: %s, Email: %s\n",
                   f.codigo, f.nome_fantasia, f.razao_social, f.inscricao_est,
                      f.cnpj, f.endereco, f.telefone, f.email);
    printf("===========================================================================================\n");
}

void print_servico(SERVICO s){
    printf("Código: %d, Descrição: %s, Preço: %.2f, Comissão: %.2f\n",
                       s.codigo, s.descricao, s.preco, s.comissao);
    printf("===========================================================================================\n");
}

void print_funcionario(FUNCIONARIO f){
    printf("Nome: %s, CPF: %s, Cargo: %s, Salário: %.2f\n",
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
  setlocale(LC_ALL, "Portuguese");//permite uso de acentuação e caracteres especiais
  setlocale(LC_NUMERIC, "C");//padrao numerico americano para manter.
    inicializa_arquivos();
    // Configura o tipo de arquivo
    typedoc = tipo_doc();

    // Chama o menu principal
    menu();
    //libera memoria não usada
    finalizar_dados();
    return 0;
}
