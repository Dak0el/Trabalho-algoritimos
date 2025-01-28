#include<stdio.h>
#include<stdlib.h>
#include"cadastro.h"
#include<locale.h>

int count_pecas=0,count_fornecedor=0,count_servico=0,count_clientes=0,count_oficina=0,count_veiculo=0,count_funcionario=0;//contagem de variaveis iniciadas em 0
int typedoc;
//defini��o das extern em null
OFICINA *oficina = NULL;
CLIENTE *cliente = NULL;
VEICULOS *veiculo = NULL;
PECA *pecas = NULL;
FORNECEDOR *fornecedores = NULL;
FUNCIONARIO *funcionarios = NULL;
SERVICO *servicos = NULL;
/*==========================================================
//arrumar comissao da ordem
============================================================*/

/*
codigos e erros erros
     2 = Sa�da
     1 = Falha conclusiva
     0 = Sucesso conclusivo
    -1 = falha na aloca��o de memoria
    -2 = falha no arquivo
    -3 = valor inv�lido
    -4 = falha na gera��o de arquivo
*/
// Define o tipo de documento
int tipo_doc() {

    FILE *tipodoc = fopen("typedoc.txt", "r");

    if (tipodoc) {
        if (fscanf(tipodoc, "%d", &typedoc) == 1) {
            fclose(tipodoc); // Carrega o modo e fecha o arquivo
        }
        fclose(tipodoc);
    } else {
        printf("Tipo de arquivo que deseja usar:\n");
        printf("1 - Texto\n");
        printf("2 - Bin�rio\n");
        if (scanf("%d", &typedoc) != 1) {
            getchar(); // Limpa o buffer
            return -3;
        }
        getchar(); // Limpa o buffer de nova linha
        // Salva a escolha no arquivo
        tipodoc = fopen("typedoc.txt", "w");
        if (tipodoc) {
            fprintf(tipodoc, "%d", typedoc);
            fclose(tipodoc);
        } else {
            perror("Erro ao salvar o tipo de arquivo em 'typedoc.txt'");
        }
    }
    remove(typedoc == 1 ? "oficina.bin" : "oficina.txt");
    remove(typedoc == 1 ? "cliente.bin" : "cliente.txt");
    remove(typedoc == 1 ? "veiculo.bin" : "veiculo.txt");
    remove(typedoc == 1 ? "pecas.bin" : "pecas.txt");
    remove(typedoc == 1 ? "fornecedor.bin" : "fornecedor.txt");
    remove(typedoc == 1 ? "servico.bin" : "servico.txt");
    remove(typedoc == 1 ? "funcionario.bin" : "funcionario.txt");
    remove(typedoc == 1 ? "transacoes.bin" : "transacoes.txt");
    remove(typedoc == 1 ? "recebimentos.bin" : "recebimentos.txt");
    remove(typedoc == 1 ? "pagamentos.bin" : "pagamentos.txt");
    remove(typedoc == 1 ? "fiscal.bin" : "fiscal.txt");
    remove(typedoc == 1 ? "caixa.bin" : "caixa.txt");



    //transa�ao recebimento pagamento fical caixa
    system("cls");
    return typedoc;
}
//inicia a varredura de exist�ncia de arquivos, se n�o tiver, cria um
void inicializa_arquivos() {
    FILE *arquivo;

    // Cria��o do arquivo de oficina
    arquivo = fopen("oficina.txt", "r");
    if (arquivo == NULL) {
        arquivo = fopen("oficina.txt", "w");
        fclose(arquivo);
    } else {
        fclose(arquivo);
    }

    arquivo = fopen("oficina.bin", "rb");
    if (arquivo == NULL) {
        arquivo = fopen("oficina.bin", "wb");
        fclose(arquivo);
    } else {
        fclose(arquivo);
    }

    // Clientes
    arquivo = fopen("cliente.txt", "r");
    if (arquivo == NULL) {
        arquivo = fopen("cliente.txt", "w");
        fclose(arquivo);
    } else {
        fclose(arquivo);
    }

    arquivo = fopen("cliente.bin", "rb");
    if (arquivo == NULL) {
        arquivo = fopen("cliente.bin", "wb");
        fclose(arquivo);
    } else {
        fclose(arquivo);
    }

    // Ve�culos
    arquivo = fopen("veiculo.txt", "r");
    if (arquivo == NULL) {
        arquivo = fopen("veiculo.txt", "w");
        fclose(arquivo);
    } else {
        fclose(arquivo);
    }

    arquivo = fopen("veiculo.bin", "rb");
    if (arquivo == NULL) {
        arquivo = fopen("veiculo.bin", "wb");
        fclose(arquivo);
    } else {
        fclose(arquivo);
    }

    // Pe�as
    arquivo = fopen("pecas.txt", "r");
    if (arquivo == NULL) {
        arquivo = fopen("pecas.txt", "w");
        fclose(arquivo);
    } else {
        fclose(arquivo);
    }

    arquivo = fopen("pecas.bin", "rb");
    if (arquivo == NULL) {
        arquivo = fopen("pecas.bin", "wb");
        fclose(arquivo);
    } else {
        fclose(arquivo);
    }

    // Fornecedores
    arquivo = fopen("fornecedor.txt", "r");
    if (arquivo == NULL) {
        arquivo = fopen("fornecedor.txt", "w");
        fclose(arquivo);
    } else {
        fclose(arquivo);
    }

    arquivo = fopen("fornecedor.bin", "rb");
    if (arquivo == NULL) {
        arquivo = fopen("fornecedor.bin", "wb");
        fclose(arquivo);
    } else {
        fclose(arquivo);
    }

    // Servi�os
    arquivo = fopen("servico.txt", "r");
    if (arquivo == NULL) {
        arquivo = fopen("servico.txt", "w");
        fclose(arquivo);
    } else {
        fclose(arquivo);
    }

    arquivo = fopen("servico.bin", "rb");
    if (arquivo == NULL) {
        arquivo = fopen("servico.bin", "wb");
        fclose(arquivo);
    } else {
        fclose(arquivo);
    }

    // Funcion�rios
    arquivo = fopen("funcionario.txt", "r");
    if (arquivo == NULL) {
        arquivo = fopen("funcionario.txt", "w");
        fclose(arquivo);
    } else {
        fclose(arquivo);
    }

    arquivo = fopen("funcionario.bin", "rb");
    if (arquivo == NULL) {
        arquivo = fopen("funcionario.bin", "wb");
        fclose(arquivo);
    } else {
        fclose(arquivo);
    }

    arquivo = fopen("transacoes.txt", "r");//transa��es
    if (arquivo == NULL) {
        arquivo = fopen("transacoes.txt", "w");
        fclose(arquivo);
    } else {
        fclose(arquivo);
    }

    arquivo = fopen("transacoes.bin", "rb");//transa��es
    if (arquivo == NULL) {
        arquivo = fopen("transacoes.bin", "wb");
        fclose(arquivo);
    } else {
        fclose(arquivo);
    }

    arquivo = fopen("recebimentos.txt", "r");//recebimentos
    if (arquivo == NULL) {
        arquivo = fopen("recebimentos.txt", "w");
        fclose(arquivo);
    } else {
        fclose(arquivo);
    }

    arquivo = fopen("recebimentos.bin", "rb");//recebimentos
    if (arquivo == NULL) {
        arquivo = fopen("recebimentos.bin", "wb");
        fclose(arquivo);
    } else {
        fclose(arquivo);
    }

    arquivo = fopen("pagamentos.txt", "r");//pagamentos
    if (arquivo == NULL) {
        arquivo = fopen("pagamentos.txt", "w");
        fclose(arquivo);
    } else {
        fclose(arquivo);
    }

    arquivo = fopen("pagamentos.bin", "rb");//pagamentos
    if (arquivo == NULL) {
        arquivo = fopen("pagamentos.bin", "wb");
        fclose(arquivo);
    } else {
        fclose(arquivo);
    }

    arquivo = fopen("fiscal.txt", "r");//fiscal
    if (arquivo == NULL) {
        arquivo = fopen("fiscal.txt", "w");
        fclose(arquivo);
    } else {
        fclose(arquivo);
    }

    arquivo = fopen("fiscal.bin", "rb");//fiscal
    if (arquivo == NULL) {
        arquivo = fopen("fiscal.bin", "wb");
        fclose(arquivo);
    } else {
        fclose(arquivo);
    }

    arquivo = fopen("caixa.txt", "r");//caixa
    if (arquivo == NULL) {
        arquivo = fopen("caixa.txt", "w");
        fclose(arquivo);
    } else {
        fclose(arquivo);
    }

    arquivo = fopen("caixa.bin", "rb");//caixa
    if (arquivo == NULL) {
        arquivo = fopen("caixa.bin", "wb");
        fclose(arquivo);
    } else {
        fclose(arquivo);
    }
}

void finalizar_dados() {
    // Libera mem�ria alocada para pe�as
    if (pecas) {
        free(pecas);
        pecas = NULL;  // Evita acessos inv�lidos ap�s a libera��o
    }

    // Libera mem�ria alocada para oficinas
    if (oficina) {
        free(oficina);
        oficina = NULL;
    }

    // Libera mem�ria alocada para fornecedores
    if (fornecedores) {
        free(fornecedores);
        fornecedores = NULL;
    }

    // Libera mem�ria alocada para clientes
    if (cliente) {
        free(cliente);
        cliente = NULL;
    }

    // Libera mem�ria alocada para funcion�rios
    if (funcionarios) {
        free(funcionarios);
        funcionarios = NULL;
    }

    // Libera mem�ria alocada para servi�os
    if (servicos) {
        free(servicos);
        servicos = NULL;
    }
}

int troca(){
    // Salva o formato atual e define o novo formato
    int novo_typedoc = (typedoc == 1) ? 2 : 1;

//==========================================================================================================
    //abrindo arquivos oficina
    FILE *oficinaO = fopen(typedoc == 1 ? "oficina.txt" : "oficina.bin", typedoc == 1 ? "r" : "rb");
    FILE *oficinaD = fopen(novo_typedoc == 1 ? "oficina.txt" : "oficina.bin", novo_typedoc == 1 ? "w" : "wb");

    if (!oficinaO || !oficinaD) {
        if (oficinaO) fclose(oficinaO);
        if (oficinaD) fclose(oficinaD);
        return -2;//erro de abertura
    }

    // L� do formato atual e escreve no novo formato
    if (typedoc == 1) {  // De texto para bin�rio
        OFICINA o;
         while (fscanf(oficinaO, "%49[^,],%19[^,],%49[^,],%19[^,],%19[^,],%f[\n]",
                      o.nome, o.cpf, o.endereco, o.telefone, o.email, &o.lucro) == 6) {
            fwrite(&o, sizeof(OFICINA), 1, oficinaD);
        }
    } else {  // De bin�rio para texto
        OFICINA o;
        while (fread(&o, sizeof(OFICINA), 1, oficinaO) == 1) {
            fprintf(oficinaD, "%s,%s,%s,%s,%s,%.2f\n",
                    o.nome, o.cpf, o.endereco, o.telefone, o.email, o.lucro);
        }
    }

    fclose(oficinaO);
    fclose(oficinaD);

    // Remove o arquivo do formato antigo
    remove(typedoc == 1 ? "oficina.txt" : "oficina.bin");
//==========================================================================================================
    //abrindo arquivos cliente
    FILE *clienteO = fopen(typedoc == 1 ? "cliente.txt" : "cliente.bin", typedoc == 1 ? "r" : "rb");
    FILE *clienteD = fopen(novo_typedoc == 1 ? "cliente.txt" : "cliente.bin", novo_typedoc == 1 ? "w" : "wb");

    if (!clienteO || !clienteD) {
        if (clienteO) fclose(clienteO);
        if (clienteD) fclose(clienteD);
        return -2;//erro de abertura
    }

    // L� do formato atual e escreve no novo formato
    if (typedoc == 1) {  // De texto para bin�rio
        CLIENTE c;
         while (fscanf(clienteO, "%d,%49[^,],%19[^,],%49[^,],%19[^,],%19[^\n]\n",
                      &c.codigo, c.nome, c.cpf, c.endereco, c.telefone, c.email) == 6) {
            fwrite(&c, sizeof(CLIENTE), 1, clienteD);
        }
    } else {  // De bin�rio para texto
        CLIENTE c;
        while (fread(&c, sizeof(CLIENTE), 1, clienteO) == 1) {
            fprintf(clienteD, "%d,%s,%s,%s,%s,%s\n",
                    c.codigo, c.nome, c.cpf, c.endereco, c.telefone, c.email);
        }
    }

    fclose(clienteO);
    fclose(clienteD);

    // Remove o arquivo do formato antigo
    remove(typedoc == 1 ? "cliente.txt" : "cliente.bin");

//==========================================================================================================
    //abrindo arquivos veiculo
    FILE *veiculoO = fopen(typedoc == 1 ? "veiculo.txt" : "veiculo.bin", typedoc == 1 ? "r" : "rb");
    FILE *veiculoD = fopen(novo_typedoc == 1 ? "veiculo.txt" : "veiculo.bin", novo_typedoc == 1 ? "w" : "wb");

    if (!veiculoO || !veiculoD) {
        if (veiculoO) fclose(veiculoO);
        if (veiculoD) fclose(veiculoD);
        return -2;//erro de abertura
    }

    // L� do formato atual e escreve no novo formato
    if (typedoc == 1) {  // De texto para bin�rio
        VEICULOS v;
         while (fscanf(veiculoO, "%29[^,],%49[^,],%49[^,],%d,%19[^,],%19[^\n]",
                      v.placa, v.modelo, v.marca, &v.anof, v.chassi, v.ptt) == 6) {
            fwrite(&v, sizeof(VEICULOS), 1, veiculoD);
        }
    } else {  // De bin�rio para texto
        VEICULOS v;
        while (fread(&v, sizeof(VEICULOS), 1, veiculoO) == 1) {
            fprintf(veiculoD, "%s,%s,%s,%d,%s,%s\n",
                      v.placa, v.modelo, v.marca, &v.anof, v.chassi, v.ptt);
        }
    }

    fclose(veiculoO);
    fclose(veiculoD);

    // Remove o arquivo do formato antigo
    remove(typedoc == 1 ? "veiculo.txt" : "veiculo.bin");

//==========================================================================================================
    //abrindo arquivos pe�as
    FILE *pecasO = fopen(typedoc == 1 ? "pecas.txt" : "pecas.bin", typedoc == 1 ? "r" : "rb");
    FILE *pecasD = fopen(novo_typedoc == 1 ? "pecas.txt" : "pecas.bin", novo_typedoc == 1 ? "w" : "wb");

    if (!pecasO || !pecasD) {
        if (pecasO) fclose(pecasO);
        if (pecasD) fclose(pecasD);
        return -2;//erro de abertura
    }

    // L� do formato atual e escreve no novo formato
    if (typedoc == 1) {  // De texto para bin�rio
        PECA p;
        while (fscanf(pecasO, "%d,%49[^,],%29[^,],%29[^,],%f,%f,%d,%d\n",
                      &p.codigo, p.descricao, p.fabricante, p.fornecedor,
                      &p.p_custo, &p.p_venda, &p.qntd_estoque, &p.qntd_minima) == 8) {
            fwrite(&p, sizeof(PECA), 1, pecasD);
        }
    } else {  // De bin�rio para texto
        PECA p;
        while (fread(&p, sizeof(PECA), 1, pecasO) == 1) {
            fprintf(pecasD, "%d,%s,%s,%s,%f,%f,%d,%d\n",
                    p.codigo, p.descricao, p.fabricante, p.fornecedor,
                    p.p_custo, p.p_venda, p.qntd_estoque, p.qntd_minima);
        }
    }

    fclose(pecasO);
    fclose(pecasD);

    // Remove o arquivo do formato antigo
    remove(typedoc == 1 ? "pecas.txt" : "pecas.bin");
//==========================================================================================================
    //abrindo arquivos fornecedor
    FILE *fornecedorO = fopen(typedoc == 1 ? "fornecedor.txt" : "fornecedor.bin", typedoc == 1 ? "r" : "rb");
    FILE *fornecedorD = fopen(novo_typedoc == 1 ? "fornecedor.txt" : "fornecedor.bin", novo_typedoc == 1 ? "w" : "wb");

    if (!fornecedorO || !fornecedorD) {
        if (fornecedorO) fclose(fornecedorO);
        if (fornecedorD) fclose(fornecedorD);
        return -2;//erro de abertura
    }

    // L� do formato atual e escreve no novo formato
    if (typedoc == 1) {  // De texto para bin�rio
        FORNECEDOR f;
         while (fscanf(fornecedorO, "%d,%49[^,],%49[^,],%19[^,],%19[^,],%99[^,],%19[^,],%49[^\n]\n",//adicionado o [^\n] pois ultima leitura � uma string
                      &f.codigo, f.nome_fantasia, f.razao_social, f.inscricao_est,
                      f.cnpj, f.endereco, f.telefone, f.email) == 8) {
            fwrite(&f, sizeof(FORNECEDOR), 1, fornecedorD);
        }
    } else {  // De bin�rio para texto
        FORNECEDOR f;
        while (fread(&f, sizeof(FORNECEDOR), 1, fornecedorO) == 1) {
            fprintf(fornecedorD, "%d,%s,%s,%s,%s,%s,%s,%s\n",//adicionado o [^\n] pois ultima leitura � uma string
                      f.codigo, f.nome_fantasia, f.razao_social, f.inscricao_est,
                      f.cnpj, f.endereco, f.telefone, f.email);
        }
    }

    fclose(fornecedorO);
    fclose(fornecedorD);

    // Remove o arquivo do formato antigo
    remove(typedoc == 1 ? "fornecedor.txt" : "fornecedor.bin");
//==========================================================================================================
//abrindo arquivos fornecedor
    FILE *servicosO = fopen(typedoc == 1 ? "servico.txt" : "servico.bin", typedoc == 1 ? "r" : "rb");
    FILE *servicosD = fopen(novo_typedoc == 1 ? "servico.txt" : "servico.bin", novo_typedoc == 1 ? "w" : "wb");

    if (!servicosO || !servicosD) {
        if (servicosO) fclose(servicosO);
        if (servicosD) fclose(servicosD);
        return -2;//erro de abertura
    }

    // L� do formato atual e escreve no novo formato
    if (typedoc == 1) {  // De texto para bin�rio
        SERVICO s;
        while (fscanf(servicosO, "%d,%49[^,],%f,%f\n",
                      &s.codigo, s.descricao, &s.preco, &s.comissao) == 4 ) {
            fwrite(&s, sizeof(SERVICO), 1, servicosD);
        }
    } else {  // De bin�rio para texto
        SERVICO s;
        while (fread(&s, sizeof(SERVICO), 1, servicosO) == 1) {
            fprintf(servicosD, "%d,%s,%f,%f\n",
                      s.codigo, s.descricao, &s.preco, &s.comissao);
        }
    }

    fclose(servicosO);
    fclose(servicosD);

    // Remove o arquivo do formato antigo
    remove(typedoc == 1 ? "servico.txt" : "servico.bin");
//==========================================================================================================
//abrindo arquivos funcionario
    FILE *funcionarioO = fopen(typedoc == 1 ? "funcionario.txt" : "funcionario.bin", typedoc == 1 ? "r" : "rb");
    FILE *funcionarioD = fopen(novo_typedoc == 1 ? "funcionario.txt" : "funcionario.bin", novo_typedoc == 1 ? "w" : "wb");

    if (!funcionarioO || !funcionarioD) {
        if (funcionarioO) fclose(funcionarioO);
        if (funcionarioD) fclose(funcionarioD);
        return -2;//erro de abertura
    }

    // L� do formato atual e escreve no novo formato
    if (typedoc == 1) {  // De texto para bin�rio
        FUNCIONARIO f;
        while (fscanf(funcionarioO, "%49[^,],%14[^,],%49[^,],%f\n",
                      f.nome, f.cpf, f.cargo,&f.salario) == 4) {
            fwrite(&f, sizeof(FUNCIONARIO), 1, funcionarioD);
        }
    } else {  // De bin�rio para texto
        FUNCIONARIO f;
        while (fread(&f, sizeof(FUNCIONARIO), 1, funcionarioO) == 1) {
            fprintf(funcionarioD, "%s,%s,%s,%f\n",
                      f.nome, f.cpf, f.cargo,&f.salario);
        }
    }

    fclose(funcionarioO);
    fclose(funcionarioD);

    // Remove o arquivo do formato antigo
    remove(typedoc == 1 ? "funcionario.txt" : "funcionario.bin");
//==========================================================================================================
// Abrindo arquivos transa��es
FILE *trO = fopen(typedoc == 1 ? "transacoes.txt" : "transacoes.bin", typedoc == 1 ? "r" : "rb");
FILE *trD = fopen(novo_typedoc == 1 ? "transacoes.txt" : "transacoes.bin", novo_typedoc == 1 ? "w" : "wb");

if (!trO || !trD) {
    if (trO) fclose(trO);
    if (trD) fclose(trD);
    return -2; // Erro de abertura
}

// L� do formato atual e escreve no novo formato
if (typedoc == 1) {  // De texto para bin�rio
    CAIXA c;
    while (fscanf(trO, "%f,%49[^,],%19[^\n]\n", &c.saldo, c.descricao, c.data) == 3) {
        fwrite(&c, sizeof(CAIXA), 1, trD);
    }
} else {  // De bin�rio para texto
    CAIXA c;
    while (fread(&c, sizeof(CAIXA), 1, trO) == 1) {
        fprintf(trD, "%.2f,%s,%s\n", c.saldo, c.descricao, c.data);
    }
}

fclose(trO);
fclose(trD);

// Remove o arquivo do formato antigo
remove(typedoc == 1 ? "transacoes.txt" : "transacoes.bin");
//==========================================================================================================
// Abrindo arquivos recebimentos
FILE *recO = fopen(typedoc == 1 ? "recebimentos.txt" : "recebimentos.bin", typedoc == 1 ? "r" : "rb");
FILE *recD = fopen(novo_typedoc == 1 ? "recebimentos.txt" : "recebimentos.bin", novo_typedoc == 1 ? "w" : "wb");

if (!recO || !recD) {
    if (recO) fclose(recO);
    if (recD) fclose(recD);
    return -2; // Erro de abertura
}

// L� do formato atual e escreve no novo formato
if (typedoc == 1) {  // De texto para bin�rio
    CONTASR r;
    while (fscanf(recO, "%49[^,],%f,%14[^\n],%d\n", r.descricao, &r.valor, r.data_vencimento, &r.status) == 4) {
        fwrite(&r, sizeof(CONTASR), 1, recD);
    }
} else {  // De bin�rio para texto
    CONTASR r;
    while (fread(&r, sizeof(CONTASR), 1, recO) == 1) {
        fprintf(recD, "%s,%.2f,%s,%d\n", r.descricao, r.valor, r.data_vencimento, r.status);
    }
}

fclose(recO);
fclose(recD);

// Remove o arquivo do formato antigo
remove(typedoc == 1 ? "recebimentos.txt" : "recebimentos.bin");
//==========================================================================================================

// Abrindo arquivos pagamentos
FILE *pagO = fopen(typedoc == 1 ? "pagamentos.txt" : "pagamentos.bin", typedoc == 1 ? "r" : "rb");
FILE *pagD = fopen(novo_typedoc == 1 ? "pagamentos.txt" : "pagamentos.bin", novo_typedoc == 1 ? "w" : "wb");

if (!pagO || !pagD) {
    if (pagO) fclose(pagO);
    if (pagD) fclose(pagD);
    return -2; // Erro de abertura
}

// L� do formato atual e escreve no novo formato
if (typedoc == 1) {  // De texto para bin�rio
    CONTASP p;
    while (fscanf(pagO, "%49[^,],%f,%14[^,],%d\n", p.descricao, &p.valor, p.data_vencimento, &p.status) == 4) {
        fwrite(&p, sizeof(CONTASP), 1, pagD);
    }
} else {  // De bin�rio para texto
    CONTASP p;
    while (fread(&p, sizeof(CONTASP), 1, pagO) == 1) {
        fprintf(pagD, "%s,%.2f,%s,%d\n", p.descricao, p.valor, p.data_vencimento, p.status);
    }
}

fclose(pagO);
fclose(pagD);

// Remove o arquivo do formato antigo
remove(typedoc == 1 ? "pagamentos.txt" : "pagamentos.bin");
//==========================================================================================================
// Abrindo arquivos fiscal
FILE *fisO = fopen(typedoc == 1 ? "fiscal.txt" : "fiscal.bin", typedoc == 1 ? "r" : "rb");
FILE *fisD = fopen(novo_typedoc == 1 ? "fiscal.txt" : "fiscal.bin", novo_typedoc == 1 ? "w" : "wb");

if (!fisO || !fisD) {
    if (fisO) fclose(fisO);
    if (fisD) fclose(fisD);
    return -2; // Erro de abertura
}

// L� do formato atual e escreve no novo formato
if (typedoc == 1) {  // De texto para bin�rio
    PECA f;
    while (fscanf(fisO, "%49[^,],%d,%f\n", f.descricao, &f.qntd_estoque, &f.p_venda) == 3) {
        fwrite(&f, sizeof(PECA), 1, fisD);
    }
} else {  // De bin�rio para texto
    PECA f;
    while (fread(&f, sizeof(PECA), 1, fisO) == 1) {
        fprintf(fisD, "%s,%d,%.2f\n", f.descricao, f.qntd_estoque, f.p_venda);
    }
}

fclose(fisO);
fclose(fisD);

// Remove o arquivo do formato antigo
remove(typedoc == 1 ? "fiscal.txt" : "fiscal.bin");
//==========================================================================================================
// Abrindo arquivos caixa
FILE *caiO = fopen(typedoc == 1 ? "caixa.txt" : "caixa.bin", typedoc == 1 ? "r" : "rb");
FILE *caiD = fopen(novo_typedoc == 1 ? "caixa.txt" : "caixa.bin", novo_typedoc == 1 ? "w" : "wb");

if (!caiO || !caiD) {
    if (caiO) fclose(caiO);
    if (caiD) fclose(caiD);
    return -2; // Erro de abertura
}

// L� do formato atual e escreve no novo formato
if (typedoc == 1) {  // De texto para bin�rio
    CAIXA c;
    while (fscanf(caiO, "%f,%49[^,],%19[^\n]\n", &c.saldo, c.descricao, c.data) == 3) {
        fwrite(&c, sizeof(CAIXA), 1, caiD);
    }
} else {  // De bin�rio para texto
    CAIXA c;
    while (fread(&c, sizeof(CAIXA), 1, caiO) == 1) {
        fprintf(caiD, "%.2f,%s,%s\n", c.saldo, c.descricao, c.data);
    }
}

fclose(caiO);
fclose(caiD);

// Remove o arquivo do formato antigo
remove(typedoc == 1 ? "caixa.txt" : "caixa.bin");
//==========================================================================================================
    typedoc = novo_typedoc;
    FILE *tipodoc = fopen("typedoc.txt","w");
    if(tipodoc){
        fprintf(tipodoc,"%d",novo_typedoc);
    }else{
        fclose(tipodoc);
        return -2;
    }

    fclose(tipodoc);
    return 0;
}

/*come�o das rotinas de cadastro:
Oficina,Cliente,Veiculo,Pe�a,Fornecedor,Servi�o e Funcionario
*/

int cadastro_oficina() {
    int duplicado = 0;

    // Realoca mem�ria
    OFICINA *temp = realloc(oficina, (count_oficina + 1) * sizeof(OFICINA));
    if (!temp) return -1;
    oficina = temp;

    // Novo oficina
    OFICINA *o = &oficina[count_oficina];

    // Entrada de dados
    printf("Nome: ");
    fgets(o->nome, sizeof(o->nome), stdin);
    strtok(o->nome, "\n");

    // Valida��o e duplica��o
    do {
        duplicado = 0;
        printf("CNPJ: ");
        fgets(o->cpf, sizeof(o->cpf), stdin);
        strtok(o->cpf, "\n");

        // Verifica duplica��o em mem�ria
        for (int i = 0; i < count_oficina; i++) {
            if (strcmp(oficina[i].cpf, o->cpf) == 0 && i != count_oficina) {
                int x = copy_element();
                if (x == 1) return 2;  // Usu�rio optou por sair
                duplicado = 1;
                break;
            }
        }

        // Verifica duplica��o no arquivo
        if (!duplicado) {
            FILE *file = fopen(typedoc == 1 ? "oficina.txt" : "oficina.bin", typedoc == 1 ? "r" : "rb");
            if (!file) return -2;

            if (typedoc == 1) {
                char analy[20];
                while (fscanf(file, "%*[^,],%19[^,],%*[^,],%*[^,],%*[^\n],%*f\n", analy) == 1) {
                    if (strcmp(analy, o->cpf) == 0) {
                        int x = copy_element();
                        if (x == 1) {
                            fclose(file);
                            return 2;  // Usu�rio optou por sair
                        }
                        duplicado = 1;
                        break;
                    }
                }
            } else {
                OFICINA temp;
                while (fread(&temp, sizeof(OFICINA), 1, file) == 1) {
                    if (strcmp(temp.cpf, o->cpf) == 0) {
                        int x = copy_element();
                        if (x == 1) {
                            fclose(file);
                            return 0;  // Usu�rio optou por sair
                        }
                        duplicado = 1;
                        break;
                    }
                }
            }
            fclose(file);
        }
    } while (duplicado);

    printf("Endere�o: ");
    fgets(o->endereco, sizeof(o->endereco), stdin);
    strtok(o->endereco, "\n");

    printf("Telefone: ");
    fgets(o->telefone, sizeof(o->telefone), stdin);
    strtok(o->telefone, "\n");

    printf("E-mail: ");
    fgets(o->email, sizeof(o->email), stdin);
    strtok(o->email, "\n");

    printf("%% de lucro:\n");
    scanf("%f",&o->lucro);

    count_oficina++;
    return 0;
}

int salvar_oficina() {
    FILE *file = fopen(typedoc == 1 ? "oficina.txt" : "oficina.bin", typedoc == 1 ? "a" : "ab");
    if (!file) return -2;

    for (int i = 0; i < count_oficina; i++) {
        OFICINA *o = &oficina[i];
        if (typedoc == 1) {
            fprintf(file, "%s,%s,%s,%s,%s,%.2f\n", o->nome, o->cpf, o->endereco, o->telefone, o->email, o->lucro);
        } else {
            fwrite(o, sizeof(OFICINA), 1, file);
        }
    }

    fclose(file);
    free(oficina);
    return 0;
}

int cadastro_cliente() {
    int mc = 0, duplicado = 0;

    // Coleta o maior c�digo em arquivo
    FILE *client_file = fopen(typedoc == 1 ? "cliente.txt" : "cliente.bin", typedoc == 1 ? "r" : "rb");
    if (client_file) {
        if (typedoc == 1) {
            int codigo;
            while (fscanf(client_file, "%d,%*[^,],%*[^,],%*[^,],%*[^,],%*[^\n]\n", &codigo) == 1) {
                if (codigo > mc) mc = codigo;
            }
        } else {
            CLIENTE temp;
            while (fread(&temp, sizeof(CLIENTE), 1, client_file) == 1) {
                if (temp.codigo > mc) mc = temp.codigo;
            }
        }
        fclose(client_file);
    }

    // Coleta o maior c�digo em mem�ria
    for (int i = 0; i < count_clientes; i++) {
        if (cliente[i].codigo > mc) mc = cliente[i].codigo;
    }

    // Realoca mem�ria
    CLIENTE *temp = realloc(cliente, (count_clientes + 1) * sizeof(CLIENTE));
    if (!temp) return -1;
    cliente = temp;

    // Novo cliente
    CLIENTE *c = &cliente[count_clientes];
    c->codigo = ++mc;

    // Entrada de dados
    printf("Cod: %d\n", c->codigo);
    printf("Nome: ");
    fgets(c->nome, sizeof(c->nome), stdin);
    strtok(c->nome, "\n");

    // Valida��o e duplica��o
    do {
        duplicado = 0;
        printf("CPF/CNPJ: ");
        fgets(c->cpf, sizeof(c->cpf), stdin);
        strtok(c->cpf, "\n");

        // Verifica duplica��o em mem�ria
        for (int i = 0; i < count_clientes; i++) {
            if (strcmp(cliente[i].cpf, c->cpf) == 0 && cliente[i].codigo != c->codigo) {
                int x = copy_element();
                if (x == 1) return 2;  // Usu�rio optou por sair
                duplicado = 1;
                break;
            }
        }

        // Verifica duplica��o no arquivo
        if (!duplicado) {
            client_file = fopen(typedoc == 1 ? "cliente.txt" : "cliente.bin", typedoc == 1 ? "r" : "rb");
            if (!client_file) return -2;

            if (typedoc == 1) {
                char analy[20];
                while (fscanf(client_file, "%*d,%*[^,],%19[^,],%*[^,],%*[^,],%*[^\n]\n", analy) == 1) {
                    if (strcmp(analy, c->cpf) == 0) {
                        int x = copy_element();
                        if (x == 1) {
                            fclose(client_file);
                            return 2;  // Usu�rio optou por sair
                        }
                        duplicado = 1;
                        break;
                    }
                }
            } else {
                CLIENTE temp;
                while (fread(&temp, sizeof(CLIENTE), 1, client_file) == 1) {
                    if (strcmp(temp.cpf, c->cpf) == 0) {
                        int x = copy_element();
                        if (x == 1) {
                            fclose(client_file);
                            return 2;  // Usu�rio optou por sair
                        }
                        duplicado = 1;
                        break;
                    }
                }
            }
            fclose(client_file);
        }
    } while (duplicado);

    printf("Endere�o: ");
    fgets(c->endereco, sizeof(c->endereco), stdin);
    strtok(c->endereco, "\n");

    printf("Telefone: ");
    fgets(c->telefone, sizeof(c->telefone), stdin);
    strtok(c->telefone, "\n");

    printf("E-mail: ");
    fgets(c->email, sizeof(c->email), stdin);
    strtok(c->email, "\n");

    // Incrementa o contador de clientes
    count_clientes++;
    return 0;
}

int salvar_cliente() {
    // Abre o arquivo no modo de escrita
    FILE *file = fopen(typedoc == 1 ? "cliente.txt" : "cliente.bin", typedoc == 1 ? "a" : "ab");
    if (!file) return -2;

    // Salva todos os clientes em mem�ria no arquivo
    for (int i = 0; i < count_clientes; i++) {
        CLIENTE *c = &cliente[i];
        if (typedoc == 1) {
            fprintf(file, "%d,%s,%s,%s,%s,%s\n", c->codigo, c->nome, c->cpf, c->endereco, c->telefone, c->email);
        } else {
            fwrite(c, sizeof(CLIENTE), 1, file);
        }
    }

    fclose(file);
    free(cliente);
    return 0;  // Opera��o bem-sucedida
}

int cadastro_veiculo() {
    int duplicado = 0;

    // Realoca mem�ria
    VEICULOS *temp = realloc(veiculo, (count_veiculo + 1) * sizeof(VEICULOS));
    if (!temp) return -1;
    veiculo = temp;

    // Novo ve�culo
    VEICULOS *v = &veiculo[count_veiculo];
placa:
    // Entrada de dados
    printf("Placa: ");
    fgets(v->placa, sizeof(v->placa), stdin);
    strtok(v->placa, "\n");

    // Valida��o e duplica��o
    do {
        duplicado = 0;

        // Verifica duplica��o em mem�ria
        for (int i = 0; i < count_veiculo; i++) {
            if (strcmp(veiculo[i].placa, v->placa) == 0 && i != count_veiculo) {
                int x = copy_element();
                if (x == 1) return 2;  // Usu�rio optou por sair
                duplicado = 1;
                break;
            }
        }

        // Verifica duplica��o no arquivo
        if (!duplicado) {
            FILE *file = fopen(typedoc == 1 ? "veiculo.txt" : "veiculo.bin", typedoc == 1 ? "r" : "rb");
            if (!file) return -2;

            if (typedoc == 1) {
                char analy[30];
                while (fscanf(file, "%29[^,],%*[^,],%*[^,],%*d,%*[^\n]\n", analy) == 1) {
                    if (strcmp(analy, v->placa) == 0) {
                        int x = copy_element();
                        if (x == 1) {
                            fclose(file);
                            return 2;  // Usu�rio optou por sair
                        }
                        duplicado = 1;
                        goto placa;//retorna para a coleta de placa
                        break;
                    }
                }
            } else {
                VEICULOS temp;
                while (fread(&temp, sizeof(VEICULOS), 1, file) == 1) {
                    if (strcmp(temp.placa, v->placa) == 0) {
                        int x = copy_element();
                        if (x == 1) {
                            fclose(file);
                            return 2;  // Usu�rio optou por sair
                        }
                        duplicado = 1;
                        break;
                    }
                }
            }
            fclose(file);
        }
    } while (duplicado);

    printf("Modelo: ");
    fgets(v->modelo, sizeof(v->modelo), stdin);
    strtok(v->modelo, "\n");

    printf("Marca: ");
    fgets(v->marca, sizeof(v->marca), stdin);
    strtok(v->marca, "\n");

    printf("Ano de Fabrica��o: ");
    scanf("%d", &v->anof);
    getchar();

    printf("Chassi: ");
    fgets(v->chassi, sizeof(v->chassi), stdin);
    strtok(v->chassi, "\n");

     do {
        duplicado = 0;
        printf("CPF do Propriet�rio: ");
        fgets(v->ptt, sizeof(v->ptt), stdin);
        strtok(v->ptt, "\n");

        // Verifica se o propriet�rio existe
        FILE *cliente_file = fopen(typedoc == 1 ? "cliente.txt" : "cliente.bin", typedoc == 1 ? "r" : "rb");
        if (!cliente_file) return -2;

        if (typedoc == 1) {
            char cpf[20];
            while (fscanf(cliente_file, "%*d,%*[^,],%19[^,],%*[^,],%*[^,],%*[^\n]\n", cpf) == 1) {
                if (strcmp(cpf, v->ptt) == 0) {
                    duplicado = 1;
                    break;
                }
            }
        } else {
            CLIENTE temp;
            while (fread(&temp, sizeof(CLIENTE), 1, cliente_file) == 1) {
                if (strcmp(temp.cpf, v->ptt) == 0) {
                    duplicado = 1;
                    break;
                }
            }
        }
        fclose(cliente_file);

        if (!duplicado) {
            int x = not_found();
            if (x == 1) return 0; // Usu�rio optou por sair
        }
    } while (!duplicado);

    count_veiculo++;
    return 0;
}

int salvar_veiculo() {
    FILE *file = fopen(typedoc == 1 ? "veiculo.txt" : "veiculo.bin", typedoc == 1 ? "a" : "ab");
    if (!file) return -2;

    for (int i = 0; i < count_veiculo; i++) {
        VEICULOS *v = &veiculo[i];
        if (typedoc == 1) {
            fprintf(file, "%s,%s,%s,%d,%s,%s\n", v->placa, v->modelo, v->marca, v->anof, v->chassi, v->ptt);
        } else {
            fwrite(v, sizeof(VEICULOS), 1, file);
        }
    }

    fclose(file);
    free(veiculo);
    return 0;
}

int cadastro_pecas() {
    int mc = 0, duplicado = 0,x;

    // Coleta o maior c�digo em arquivo
    FILE *pecas_file = fopen(typedoc == 1 ? "pecas.txt" : "pecas.bin", typedoc == 1 ? "r" : "rb");
    if (pecas_file) {
        if (typedoc == 1) {
            int codigo;
            while (fscanf(pecas_file, "%d,%*[^,],%*[^,],%*[^,],%*f,%*f,%*d,%*d\n", &codigo) == 1) {
                if (codigo > mc) mc = codigo;
            }
        } else {
            PECA temp;
            while (fread(&temp, sizeof(PECA), 1, pecas_file) == 1) {
                if (temp.codigo > mc) mc = temp.codigo;
            }
        }
        fclose(pecas_file);
    }

    // Coleta o maior c�digo em mem�ria
    for (int i = 0; i < count_pecas; i++) {
        if (pecas[i].codigo > mc) mc = pecas[i].codigo;
    }

    // Realoca mem�ria
    PECA *temp = realloc(pecas, (count_pecas + 1) * sizeof(PECA));
    if (!temp) return -1;
    pecas = temp;

    // Nova pe�a
    PECA *p = &pecas[count_pecas];
    p->codigo = ++mc;

    // Entrada de dados
    printf("Cod: %d\n", p->codigo);
    do {
            duplicado = 0; // Reseta a flag de duplica��o

            printf("Descri��o: ");
            fgets(p->descricao, sizeof(p->descricao), stdin);
            strtok(p->descricao, "\n");

            // Verifica duplica��o na mem�ria
            for (int i = 0; i < count_pecas; i++) {
                if (strcmp(pecas[i].descricao, p->descricao) == 0) { // Compara o CPF
                    x = copy_element();
                    if(x == 1) return 2;
                    duplicado = 1; // Marca como duplicado
                    break;
                }
            }

            // Verifica duplica��o no arquivo
            if (!duplicado) {
                FILE *check_file = fopen(typedoc == 1 ? "pecas.txt" : "pecas.bin", typedoc == 1 ? "r" : "rb");
                if (!check_file) {
                    return -2;
                }

                if (typedoc == 1) { // Modo texto
                    char analy[50];
                    while (fscanf(check_file, "%*d,%49[^,],%*[^,],%*[^,],%*f,%*f,%*d,%*d\n", analy) == 1) {
                        if (strcmp(analy, p->descricao) == 0) { // Compara o CPF
                            x = copy_element();
                            if(x == 1) return 2;
                            duplicado = 1; // Marca como duplicado
                            break;
                        }
                    }
                } else { // Modo bin�rio
                    PECA temp;
                    while (fread(&temp, sizeof(PECA), 1, check_file) == 1) {
                        if (strcmp(temp.descricao, p->descricao) == 0) { // Compara o CPF
                             x = copy_element();
                            if(x == 1) return 2;
                            duplicado = 1; // Marca como duplicado
                            break;
                        }
                    }
                }

                fclose(check_file); // Fecha o arquivo ap�s a verifica��o
            }
        } while (duplicado);
//==================================================================================================
    printf("Fabricante: ");
    fgets(p->fabricante, sizeof(p->fabricante), stdin);
    strtok(p->fabricante, "\n");

    do {
    duplicado = 0;  // Reseta a flag de duplica��o

    printf("Fornecedor: ");
    fgets(p->fornecedor, sizeof(p->fornecedor), stdin);  // L� o nome do fornecedor
    strtok(p->fornecedor, "\n");  // Remove o '\n' do final da string

    // Abre o arquivo de fornecedores para verificar
    FILE *check_file = fopen(typedoc == 1 ? "fornecedor.txt" : "fornecedor.bin", typedoc == 1 ? "r" : "rb");
    if (!check_file) {
        return -2;  // Encerra a fun��o em caso de falha
    }

    if (typedoc == 1) {  // Modo texto
        char analy[50];  // Buffer para armazenar o nome do fornecedor
        while (fscanf(check_file, "%*d,%49[^,],%*[^,],%*[^,],%*[^,],%*[^,],%*[^,],%*[^\n]\n", analy) == 1) {
            if (strcmp(analy, p->fornecedor) == 0) {  // Fornecedor encontrado
                duplicado = 1;  // Marca como duplicado
                break;
            }
        }
    } else {  // Modo bin�rio
        FORNECEDOR temp;  // Estrutura tempor�ria para o fornecedor
        while (fread(&temp, sizeof(FORNECEDOR), 1, check_file) == 1) {
            if (strcmp(temp.nome_fantasia, p->fornecedor) == 0) {  // Fornecedor encontrado
                duplicado = 1;  // Marca como duplicado
                break;
            }
        }
    }
    fclose(check_file);  // Fecha o arquivo ap�s a verifica��o

        if (!duplicado) {  // Se n�o encontrou o fornecedor
            x = not_found();
                if(x==1){
                return 2;
                }
        }
} while (!duplicado);

    // Valida��o e duplica��o
    do {
        duplicado = 0;
        printf("Pre�o de custo: ");
        if (scanf("%f", &p->p_custo) != 1 || p->p_custo < 0) {
            duplicado = 1;
            invalid_in();
        }
        getchar();
    } while (duplicado);

    do {
        duplicado = 0;
        printf("Pre�o de venda: ");
        if (scanf("%f", &p->p_venda) != 1 || p->p_venda < p->p_custo) {
            duplicado = 1;
            invalid_in();
        }
        getchar();
    } while (duplicado);

    do {
        duplicado = 0;
        printf("Quantidade em estoque: ");
        if (scanf("%d", &p->qntd_estoque) != 1 || p->qntd_estoque < 0) {
            duplicado = 1;
            invalid_in();
        }
        getchar();
    } while (duplicado);

    do {
        duplicado = 0;
        printf("Quantidade m�nima em estoque: ");
        if (scanf("%d", &p->qntd_minima) != 1 || p->qntd_minima < 0) {
            duplicado = 1;
            invalid_in();
        }
        getchar();
    } while (duplicado);

    // Incrementa o contador de pe�as
    count_pecas++;
    return 0;
}

int salvar_peca(){
    FILE *pecas_file = fopen(typedoc == 1 ? "pecas.txt" : "pecas.bin", typedoc == 1 ? "a" : "ab");
    if (!pecas_file) {
        return -2;
    }

    for (int i = 0; i < count_pecas; i++) {
        PECA *p = &pecas[i];
        if (typedoc == 1) {  // Modo texto
            fprintf(pecas_file, "%d,%s,%s,%s,%.2f,%.2f,%d,%d\n",
                    p->codigo, p->descricao, p->fabricante, p->fornecedor,
                    p->p_custo, p->p_venda, p->qntd_estoque, p->qntd_minima);
        } else {  // Modo bin�rio
            fwrite(p, sizeof(PECA), 1, pecas_file);
        }
    }

    fclose(pecas_file);
    free(pecas);
    return 0;
}

int cadastro_fornecedor() {
    int x,mc=0,duplicado;

            FILE *fornecedor_file=fopen(typedoc== 1?"fornecedor.txt":"fornecedor.bin",typedoc==1?"r":"rb");
    if (fornecedor_file) {
        if (typedoc == 1) {  // Texto
            int codigo;
            while (fscanf(fornecedor_file, "%d,%*[^,],%*[^,],%*[^,],%*[^,],%*[^,],%*[^,],%*[^\n]\n", &codigo) == 1) {
                if (codigo > mc) {
                    mc = codigo;
                }
            }
        } else {  // Bin�rio
            FORNECEDOR temp;
            while (fread(&temp, sizeof(FORNECEDOR), 1, fornecedor_file) == 1) {
                if (temp.codigo > mc) {
                    mc = temp.codigo;
                }
            }
        }
        fclose(fornecedor_file);
    }

        for (int i = 0; i < count_fornecedor; i++) {//analisa maior codigo em memoria
        if (fornecedores[i].codigo > mc) {
            mc = fornecedores[i].codigo;
        }
    }

        // Realoca a mem�ria para o novo fornecedor
        FORNECEDOR *temp = realloc(fornecedores, (count_fornecedor + 1) * sizeof(FORNECEDOR));
        if (!temp) return -1;
        fornecedores = temp;

        // Preenche os dados do novo fornecedor
        FORNECEDOR *f = &fornecedores[count_fornecedor];
        f->codigo = ++mc;

        printf("Cod:%d\n", f->codigo);

//==================================================================
        do {
            duplicado = 0; // Reseta a flag de duplica��o

            printf("Nome Fantasia: ");
            fgets(f->nome_fantasia, sizeof(f->nome_fantasia), stdin);
            strtok(f->nome_fantasia, "\n");

            // Verifica duplica��o na mem�ria
            for (int i = 0; i < count_fornecedor; i++) {
                if (strcmp(fornecedores[i].nome_fantasia, f->nome_fantasia) == 0) { // Compara o CPF
                     x = copy_element();
                    if(x == 1) return 2;
                    duplicado = 1; // Marca como duplicado
                    break;
                }
            }

            // Verifica duplica��o no arquivo
            if (!duplicado) {
                FILE *check_file = fopen(typedoc == 1 ? "fornecedor.txt" : "fornecedor.bin", typedoc == 1 ? "r" : "rb");
                if (!check_file) {
                    return -2;
                }

                if (typedoc == 1) { // Modo texto
                    char analy[50];
                    while (fscanf(check_file, "%*d,%49[^,],%*[^,],%*[^,],%*[^,],%*[^,],%*[^,],%*[^\n]\n", analy) == 1) {
                        if (strcmp(analy, f->nome_fantasia) == 0) { // Compara o CPF
                            printf("Fornecedor j� cadastrado no arquivo. Digite novamente ou saia.\n");
                            printf("Deseja sair? 1-Sim 2-N�o\n");
                                x = copy_element();
                                if(x == 1) return 2;
                                duplicado = 1; // Marca como duplicado
                                break;
                        }
                    }
                } else { // Modo bin�rio
                    FORNECEDOR temp;
                    while (fread(&temp, sizeof(FORNECEDOR), 1, check_file) == 1) {
                        if (strcmp(temp.nome_fantasia, f->nome_fantasia) == 0) { // Compara o CPF
                            x = copy_element();
                            if(x == 1) return 2;
                            duplicado = 1; // Marca como duplicado
                            break;
                        }
                    }
                }
                fclose(check_file); // Fecha o arquivo ap�s a verifica��o
            }
        } while (duplicado);

        printf("Raz�o Social: ");
        fgets(f->razao_social, sizeof(f->razao_social), stdin);
        strtok(f->razao_social, "\n");
//========================================================================================================================
        do {
            duplicado = 0; // Reseta a flag de duplica��o

            printf("Inscri��o Estadual: ");
            fgets(f->inscricao_est, sizeof(f->inscricao_est), stdin);
            strtok(f->inscricao_est, "\n");

            // Verifica duplica��o na mem�ria
            for (int i = 0; i < count_fornecedor; i++) {
                if (strcmp(fornecedores[i].inscricao_est, f->inscricao_est) == 0) { // Compara o CPF
                    x = copy_element();
                        if(x == 1) return 2;
                        duplicado = 1; // Marca como duplicado
                        break;
                }
            }

            // Verifica duplica��o no arquivo
            if (!duplicado) {
                FILE *check_file = fopen(typedoc == 1 ? "fornecedor.txt" : "fornecedor.bin", typedoc == 1 ? "r" : "rb");
                if (!check_file) {
                    return -2;
                }

                if (typedoc == 1) { // Modo texto
                    char analy[20];
                    while (fscanf(check_file, "%*d,%*[^,],%*[^,],%19[^,],%*[^,],%*[^,],%*[^,],%*[^\n]\n", analy) == 1) {
                        if (strcmp(analy, f->inscricao_est) == 0) { // Compara o CPF
                            x = copy_element();
                            if(x == 1) return 2;
                            duplicado = 1; // Marca como duplicado
                            break;
                        }
                    }
                } else { // Modo bin�rio
                    FORNECEDOR temp;
                    while (fread(&temp, sizeof(FORNECEDOR), 1, check_file) == 1) {
                        if (strcmp(temp.inscricao_est, f->inscricao_est) == 0) { // Compara o CPF
                            x = copy_element();
                            if(x == 1) return 2;
                            duplicado = 1; // Marca como duplicado
                            break;
                        }
                    }
                }

                fclose(check_file); // Fecha o arquivo ap�s a verifica��o
            }
        } while (duplicado);
//======================================================================================================
        do {
            duplicado = 0; // Reseta a flag de duplica��o

            printf("CNPJ: ");
            fgets(f->cnpj, sizeof(f->cnpj), stdin); // L� o CNPJ
            strtok(f->cnpj, "\n"); // Remove a quebra de linha

            // Verifica duplica��o na mem�ria
            for (int i = 0; i < count_fornecedor; i++) {
                if (strcmp(fornecedores[i].cnpj, f->cnpj) == 0) { // Compara o CNPJ
                    x = copy_element();
                        if(x == 1) return 2;
                        duplicado = 1; // Marca como duplicado
                        break;
                }
            }

            // Verifica duplica��o no arquivo
            if (!duplicado) {
                FILE *fornecedor_file = fopen(typedoc == 1 ? "fornecedor.txt" : "fornecedor.bin", typedoc == 1 ? "r" : "rb");
                if (!fornecedor_file) {
                    return -2;
                }

                if (typedoc == 1) { // Modo texto
                    char analy[20];
                    while (fscanf(fornecedor_file, "%*d,%*[^,],%*[^,],%*[^,],%20[^,],%*[^,],%*[^\n]\n", analy) == 1) {
                        if (strcmp(analy, f->cnpj) == 0) { // Compara o CNPJ
                            x = copy_element();
                            if(x == 1) return 2;
                            duplicado = 1; // Marca como duplicado
                            break;
                        }
                    }
                } else { // Modo bin�rio
                    FORNECEDOR temp;
                    while (fread(&temp, sizeof(FORNECEDOR), 1, fornecedor_file) == 1) {
                        if (strcmp(temp.cnpj, f->cnpj) == 0) { // Compara o CNPJ
                            x = copy_element();
                            if(x == 1) return 2;
                            duplicado = 1; // Marca como duplicado
                            break;
                        }
                    }
                }

                fclose(fornecedor_file); // Fecha o arquivo ap�s a verifica��o
            }

        } while (duplicado);
//==================================================================================
        printf("Endere�o: ");
        fgets(f->endereco, sizeof(f->endereco), stdin);
        strtok(f->endereco, "\n");
//============================================================================
        printf("Telefone: ");
        fgets(f->telefone, sizeof(f->telefone), stdin);
        strtok(f->telefone, "\n");
//===========================================================================
        printf("E-mail: ");
        fgets(f->email, sizeof(f->email), stdin);
        strtok(f->email, "\n");
//==========================================================================
        count_fornecedor++;  // Incrementa o contador de fornecedores
return 0;
}

int salvar_fornecedor(){
    FILE *fornecedor_file = fopen(typedoc == 1 ? "fornecedor.txt" : "fornecedor.bin", typedoc == 1 ? "a" : "ab");
    if (!fornecedor_file) {
        return -2;
    }

    for (int i = 0; i < count_fornecedor; i++) {
        FORNECEDOR *f = &fornecedores[i];
        if (typedoc == 1) {  // Modo texto
            fprintf(fornecedor_file, "%d,%s,%s,%s,%s,%s,%s,%s\n",
                    f->codigo,f->nome_fantasia, f->razao_social, f->inscricao_est, f->cnpj, f->endereco, f->telefone, f->email);
        } else {  // Modo bin�rio
            fwrite(f, sizeof(FORNECEDOR), 1, fornecedor_file);
        }
    }

    fclose(fornecedor_file);
    free(fornecedores);
    return 0;
}

int cadastro_servico() {
    int x,mc,duplicado=0;

            FILE *servico_file=fopen(typedoc== 1?"servico.txt":"servico.bin",typedoc==1?"r":"rb");
    if (servico_file) {
        if (typedoc == 1) {  // Texto
            int codigo;
            while (fscanf(servico_file, "%d,%*[^,],%*f,%*f\n", &codigo) == 1) {
                if (codigo > mc) {
                    mc =codigo;
                }
            }
        } else {  // Bin�rio
            SERVICO temp;
            while (fread(&temp, sizeof(SERVICO), 1, servico_file) == 1) {
                if (temp.codigo > mc) {
                    mc = temp.codigo;
                }
            }
        }
        fclose(servico_file);
    }

    // Coleta o maior c�digo em mem�ria
    for (int i = 0; i < count_servico; i++) {
        if (servicos[i].codigo > mc) mc = servicos[i].codigo;
    }

        // Realoca a mem�ria para o novo servi�o
        servicos = realloc(servicos, (count_servico + 1) * sizeof(SERVICO));
        if (!servicos) {
            return -1;
        }

        SERVICO *temp = realloc(servicos, (count_servico + 1) * sizeof(SERVICO));
        if (!temp) return -1;
        servicos = temp;

        // Preenche os dados do novo servi�o
        SERVICO *s = &servicos[count_servico];
        s->codigo = ++mc;
//================================================================================================
        printf("Cod:%d\n", s->codigo);
//================================================================================
        do {
            duplicado = 0; // Reseta a flag de duplica��o

            printf("Descri��o: ");
            fgets(s->descricao, sizeof(s->descricao), stdin);
            strtok(s->descricao, "\n");

            // Verifica duplica��o na mem�ria
            for (int i = 0; i < count_servico; i++) {
                if (strcmp(servicos[i].descricao, s->descricao) == 0) { // Compara o CNPJ
                        x = copy_element();
                        if(x == 1) return 2;
                        duplicado = 1; // Marca como duplicado
                        break;
                }
            }

            // Verifica duplica��o no arquivo
            if (!duplicado) {
                FILE *check_file = fopen(typedoc == 1 ? "servico.txt" : "servico.bin", typedoc == 1 ? "r" : "rb");
                if (!check_file) {
                    return -2;
                }

                if (typedoc == 1) { // Modo texto
                    char analy[50];
                    while (fscanf(check_file, "%*d,%49[^,],%*f,%*f\n", analy) == 1) {
                        if (strcmp(analy, s->descricao) == 0) { // Compara o CNPJ
                           x = copy_element();
                            if(x == 1) return 2;
                            duplicado = 1; // Marca como duplicado
                            break;
                        }
                    }
                } else { // Modo bin�rio
                    SERVICO temp;
                    while (fread(&temp, sizeof(SERVICO), 1, check_file) == 1) {
                        if (strcmp(temp.descricao, s->descricao) == 0) { // Compara o CNPJ
                            x = copy_element();
                            if(x == 1) return 2;
                            duplicado = 1; // Marca como duplicado
                            break;
                        }
                    }
                }

                fclose(check_file); // Fecha o arquivo ap�s a verifica��o
            }

        } while (duplicado);
//================================================================================================
        printf("Pre�o: ");
        scanf("%f", &s->preco);
//================================================================================================
        printf("%% de Comiss�o: ");
        scanf("%f", &s->comissao);
        getchar();  // Limpa o buffer
//================================================================================================
        count_servico++;  // Incrementa o contador de servi�os
return 0;
}

int salvar_servico(){
    FILE *servico_file = fopen(typedoc == 1 ? "servico.txt" : "servico.bin", typedoc == 1 ? "a" : "ab");
    if (!servico_file) {
        return -1;
    }

    for (int i = 0; i < count_servico; i++) {
        SERVICO *s = &servicos[i];
        if (typedoc == 1) {  // Modo texto
            fprintf(servico_file, "%d,%s,%.2f,%.2f\n",s->codigo, s->descricao, s->preco, s->comissao);
        } else {  // Modo bin�rio
            fwrite(s, sizeof(SERVICO), 1, servico_file);
        }
    }

    fclose(servico_file);
    free(servicos);
    return 0;
}

int cadastro_funcionario() {
    int x,duplicado=0;

        FUNCIONARIO *temp = realloc(funcionarios, (count_funcionario + 1) * sizeof(FUNCIONARIO));
        if (!temp) return -1;
        funcionarios = temp;

        // Preenche os dados do novo funcion�rio
        FUNCIONARIO *f = &funcionarios[count_funcionario];
//================================================================================================
            printf("Nome: ");
            fgets(f->nome, sizeof(f->nome), stdin);
            strtok(f->nome, "\n"); // Remove a quebra de linha
//================================================================================================
        do {
            duplicado = 0; // Reseta a flag de duplica��o

            printf("CPF: ");
            fgets(f->cpf, sizeof(f->cpf), stdin); // L� o CPF
            strtok(f->cpf, "\n"); // Remove a quebra de linha

            // Verifica duplica��o na mem�ria
            for (int i = 0; i < count_funcionario; i++) {
                if (strcmp(funcionarios[i].cpf, f->cpf) == 0) { // Compara o CPF
                    printf("CPF j� cadastrado na mem�ria. Digite novamente ou saia.\n");
                    printf("Deseja sair? 1-Sim 2-N�o\n");
                                scanf("%d",&x);
                                getchar();
                                if(x==1){
                                return;
                                }
                    duplicado = 1; // Marca como duplicado
                    break;
                }
            }

            // Verifica duplica��o no arquivo
            if (!duplicado) {
                FILE *funcionario_file = fopen(typedoc == 1 ? "funcionario.txt" : "funcionario.bin", typedoc == 1 ? "r" : "rb");
                if (!funcionario_file) {
                    perror("Erro ao abrir o arquivo de funcion�rio para verificar CPF");
                    return;
                }

                if (typedoc == 1) { // Modo texto
                    char analy[15];
                    while (fscanf(funcionario_file, "%*[^,],%14[^,],%*[^,],%*f\n", analy) == 1) {
                        if (strcmp(analy, f->cpf) == 0) { // Compara o CPF
                            printf("CPF j� cadastrado no arquivo. Digite novamente ou saia.\n");
                            printf("Deseja sair? 1-Sim 2-N�o\n");
                                scanf("%d",&x);
                                getchar();
                                if(x==1){
                                return;
                                }
                            duplicado = 1; // Marca como duplicado
                            break;
                        }
                    }
                } else { // Modo bin�rio
                    FUNCIONARIO temp;
                    while (fread(&temp, sizeof(FUNCIONARIO), 1, funcionario_file) == 1) {
                        if (strcmp(temp.cpf, f->cpf) == 0) { // Compara o CPF
                            printf("CPF j� cadastrado no arquivo. Digite novamente ou saia.\n");
                            printf("Deseja sair? 1-Sim 2-N�o\n");
                                scanf("%d",&x);
                                getchar();
                                if(x==1){
                                return;
                                }
                            duplicado = 1; // Marca como duplicado
                            break;
                        }
                    }
                }

                fclose(funcionario_file); // Fecha o arquivo ap�s a verifica��o
            }

        } while (duplicado);
//================================================================================================
        printf("Cargo: ");
        fgets(f->cargo, sizeof(f->cargo), stdin);
        strtok(f->cargo, "\n");
//================================================================================================
        printf("Sal�rio: ");
        scanf("%f", &f->salario);
        getchar();  // Limpa o buffer

        count_funcionario++;  // Incrementa o contador de funcion�rios
return 0;
}

int salvar_funcionario(){
    FILE *funcionario_file = fopen(typedoc == 1 ? "funcionario.txt" : "funcionario.bin", typedoc == 1 ? "a" : "ab");
    if (!funcionario_file) {
        return -1;
    }

    for (int i = 0; i < count_funcionario; i++) {
        FUNCIONARIO *f = &funcionarios[i];
        if (typedoc == 1) {  // Modo texto
            fprintf(funcionario_file, "%s,%s,%s,%.2f\n", f->nome, f->cpf, f->cargo, f->salario);
        } else {  // Modo bin�rio
            fwrite(f, sizeof(FUNCIONARIO), 1, funcionario_file);
        }
    }
    fclose(funcionario_file);
    free(funcionarios);
    return 0;
}
/*come�o das rotinas de Consulta:
Oficina,Cliente,Veiculo,Pe�a,Fornecedor,Servi�o e Funcionario
*/

int consulta_oficina() {
    FILE *oficina_file = fopen(typedoc == 1 ? "oficina.txt" : "oficina.bin", typedoc == 1 ? "r" : "rb");
    if (!oficina_file) {
        return -2;
    }

    if (typedoc == 1) {  // Texto
            OFICINA temp;

        while (fscanf(oficina_file, "%49[^,],%19[^,],%49[^,],%19[^,],%19[^,],%f\n",
                      temp.nome, temp.cpf, temp.endereco, temp.telefone, temp.email, &temp.lucro) == 6) {
        print_oficina(temp);
        }
    } else {  // Bin�rio
        OFICINA o;
        while (fread(&o, sizeof(OFICINA), 1, oficina_file) == 1) {
            print_oficina(o);
        }
    }
    fclose(oficina_file);
    return 0;
}

int consulta_clientes() {
    FILE *client_file = fopen(typedoc == 1 ? "cliente.txt" : "cliente.bin", typedoc == 1 ? "r" : "rb");
    if (!client_file) {
        return -2;
    }

    if (typedoc == 1) {  // Texto
            CLIENTE temp;

        while (fscanf(client_file, "%d,%49[^,],%19[^,],%49[^,],%19[^,],%19[^\n]\n",//leitura minimizada para evitar overflow do buffer
                      &temp.codigo, temp.nome, temp.cpf, temp.endereco, temp.telefone, temp.email) == 6) {//leitura continua at� entregar 8 valores
        print_cliente(temp);
        }
    } else {  // Bin�rio
        CLIENTE c;
        while (fread(&c, sizeof(CLIENTE), 1, client_file) == 1) {
           print_cliente(c);
        }
    }

    fclose(client_file);
    return 0;
}

int consulta_veiculos() {
    FILE *veiculo_file = fopen(typedoc == 1 ? "veiculo.txt" : "veiculo.bin", typedoc == 1 ? "r" : "rb");
    if (!veiculo_file) {
        return -2;
    }

    if (typedoc == 1) {  // Texto
            VEICULOS temp;
        while (fscanf(veiculo_file, "%29[^,],%49[^,],%49[^,],%d,%19[^,],%19[^\n]",
                      temp.placa, temp.modelo, temp.marca, &temp.anof, temp.chassi, temp.ptt) == 6) {
            print_veiculo(temp);
        }
    } else {  // Bin�rio
        VEICULOS v;
        while (fread(&v, sizeof(VEICULOS), 1, veiculo_file) == 1) {
            print_veiculo(v);
        }
    }
    fclose(veiculo_file);
}

int consulta_pecas() {
    FILE *pecas_file = fopen(typedoc == 1 ? "pecas.txt" : "pecas.bin", typedoc == 1 ? "r" : "rb");
    if (!pecas_file) {
        return -2;
    }
    if (typedoc == 1) {  // Texto
            PECA temp;

        while (fscanf(pecas_file, "%d,%49[^,],%29[^,],%29[^,],%f,%f,%d,%d\n",//leitura minimizada para evitar overflow do buffer
                      &temp.codigo, temp.descricao, temp.fabricante, temp.fornecedor,
                      &temp.p_custo, &temp.p_venda, &temp.qntd_estoque, &temp.qntd_minima) == 8) {//leitura continua at� entregar 8 valores
           print_pecas(temp);
        }
    } else {  // Bin�rio
        PECA p;
        while (fread(&p, sizeof(PECA), 1, pecas_file) == 1) {
            print_pecas(p);
        }
    }
    fclose(pecas_file);
}

int consulta_fornecedores() {
    FILE *fornecedor_file = fopen(typedoc == 1 ? "fornecedor.txt" : "fornecedor.bin", typedoc == 1 ? "r" : "rb");
    if (!fornecedor_file) {
        return -2;
    }
    if (typedoc == 1) {  // Texto
            FORNECEDOR temp;

        while (fscanf(fornecedor_file, "%d,%49[^,],%49[^,],%19[^,],%19[^,],%99[^,],%19[^,],%49[^\n]\n",//adicionado o [^\n] pois ultima leitura � uma string
                      &temp.codigo, temp.nome_fantasia, temp.razao_social, temp.inscricao_est,
                      temp.cnpj, temp.endereco, temp.telefone, temp.email) == 8) {
            print_fornecedor(temp);
        }
    } else {  // Bin�rio
        FORNECEDOR f;
        while (fread(&f, sizeof(FORNECEDOR), 1, fornecedor_file) == 1) {
            print_fornecedor(f);
        }
    }
    fclose(fornecedor_file);
}

int consulta_servicos() {
    FILE *servico_file = fopen(typedoc == 1 ? "servico.txt" : "servico.bin", typedoc == 1 ? "r" : "rb");
    if (!servico_file) {
        return -2;
    }
    if (typedoc == 1) {  // Texto
            SERVICO temp;

        while (fscanf(servico_file, "%d,%49[^,],%f,%f\n",
                      &temp.codigo, temp.descricao, &temp.preco, &temp.comissao) == 4 ) {//leitura continua at� entregar 4 valores
            print_servico(temp);
        }
    } else {  // Bin�rio
        SERVICO s;
        while (fread(&s, sizeof(SERVICO), 1, servico_file) == 1) {
           print_servico(s);
        }
    }

    fclose(servico_file);
}

int consulta_funcionarios() {
    FILE *funcionarios_file = fopen(typedoc == 1 ? "funcionario.txt" : "funcionario.bin", typedoc == 1 ? "r" : "rb");
    if (!funcionarios_file) {
        return -2;
    }
    if (typedoc == 1) {  // Texto
            FUNCIONARIO temp;

        while (fscanf(funcionarios_file, "%49[^,],%14[^,],%49[^,],%f\n",
                      temp.nome, temp.cpf, temp.cargo, &temp.salario) == 4) {//leitura continua at� entregar 5 valores
            print_funcionario(temp);
        }
    } else {  // Bin�rio
        FUNCIONARIO f;
        while (fread(&f, sizeof(FUNCIONARIO), 1, funcionarios_file) == 1) {
            print_funcionario(f);
        }
    }

    fclose(funcionarios_file);
}

//come�o das rotinas de exclus�o

int excluir_oficina() {
    int encontrado = 0,x; // Vari�vel para verificar se o registro foi encontrado
    char cnpj_remover[20]; // Nome da oficina a ser removida

    printf("Digite o cnpj da oficina que deseja remover: ");
    fgets(cnpj_remover, sizeof(cnpj_remover), stdin);
    strtok(cnpj_remover, "\n"); // Remove o caractere de nova linha

    // Abrir arquivo de entrada para leitura
    FILE *oficina_file = fopen(typedoc == 1 ? "oficina.txt" : "oficina.bin", typedoc == 1 ? "r" : "rb");
    if (!oficina_file) {
        return -2;
    }

    // Abrir arquivo tempor�rio para escrita
    FILE *temp_file = fopen(typedoc == 1 ? "temp.txt" : "temp.bin", typedoc == 1 ? "w" : "wb");
    if (!temp_file) {
        fclose(oficina_file);
        return -4;//erro pra gerar arquivo
    }

    if (typedoc == 1) { // Exclus�o em arquivo de texto
        char nome[50], cpf[20], endereco[50], telefone[20], email[20];
        float lucro;

        while (fscanf(oficina_file, "%49[^,],%19[^,],%49[^,],%19[^,],%19[^,],%f\n",
                      nome, cpf, endereco, telefone, email, &lucro) == 6) {
            if (strcmp(cpf, cnpj_remover) == 0) {//strcmp compara o cnpj lido com o cnpj inserido,0 se forem iguais
                encontrado = 1; // Marca que o registro foi encontrado
            } else {
                fprintf(temp_file, "%s,%s,%s,%s,%s,%.2f\n",
                        nome, cpf, endereco, telefone, email, lucro);//salva no temporario os dados diferentes do requerido
            }
        }
    } else { // Exclus�o em arquivo bin�rio
        OFICINA o;

        while (fread(&o, sizeof(OFICINA), 1, oficina_file) == 1) {
            if (strcmp(o.cpf, cnpj_remover) == 0) {
                encontrado = 1; // Marca que o registro foi encontrado
            } else {
                fwrite(&o, sizeof(OFICINA), 1, temp_file);//salva no temporario os dados diferentes do requerido
            }
        }
    }

    fclose(oficina_file);
    fclose(temp_file);

    if (encontrado) {
        // Substituir o arquivo original pelo arquivo tempor�rio
        if (remove(typedoc == 1 ? "oficina.txt" : "oficina.bin") != 0 ||//remove o arquivo da oficina,retorna 0 se bem sucedido
            rename(typedoc == 1 ? "temp.txt" : "temp.bin", typedoc == 1 ? "oficina.txt" : "oficina.bin") != 0) {//renomeia o arquivo temp para oficina,retorna 0 se bem sucedido
            return -4;
        } else {
            return 0;
        }
    } else {
        // Remover o arquivo tempor�rio se nenhum dado foi exclu�do
        remove(typedoc == 1 ? "temp.txt" : "temp.bin");
        return 1;
    }
}

int excluir_cliente(){

    int encontrado = 0,x; // Vari�vel para verificar se o registro foi encontrado
    int cod_remover; // codigo da pe�a a ser removida

    printf("Digite o c�digo do cliente que deseja remover: ");
    scanf("%d",&cod_remover);
    getchar();

    // Abrir arquivo de entrada para leitura
    FILE *client_file = fopen(typedoc == 1 ? "cliente.txt" : "cliente.bin", typedoc == 1 ? "r" : "rb");
    if (!client_file) {
        return -2;
    }

    // Abrir arquivo tempor�rio para escrita
    FILE *temp_file = fopen(typedoc == 1 ? "temp.txt" : "temp.bin", typedoc == 1 ? "w" : "wb");
    if (!temp_file) {
        fclose(client_file);
        return -4;
    }
if (typedoc == 1) {  // Texto

        int codigo;
        char nome[50],cpf[20],endereco[50],telefone[20],email[20];

        while (fscanf(client_file, "%d,%49[^,],%19[^,],%49[^,],%19[^,],%19[^\n]\n",
                      &codigo,nome,cpf,endereco,telefone,email) == 6) {
            if (codigo==cod_remover) {
                encontrado = 1; // Marca que o registro foi encontrado
            } else {
                fprintf(temp_file, "%d,%s,%s,%s,%s,%s\n",
                        codigo,nome,cpf,endereco,telefone,email);
            }
        }
    } else { // Exclus�o em arquivo bin�rio
        CLIENTE c;

        while (fread(&c, sizeof(CLIENTE), 1, client_file) == 1) {
            if (c.codigo==cod_remover) {
                encontrado = 1; // Marca que o registro foi encontrado
            } else {
                fwrite(&c, sizeof(CLIENTE), 1, client_file);
            }
        }
    }

    fclose(client_file);
    fclose(temp_file);

    if (encontrado) {
        // Substituir o arquivo original pelo arquivo tempor�rio
        if (remove(typedoc == 1 ? "cliente.txt" : "cliente.bin") != 0 ||
            rename(typedoc == 1 ? "temp.txt" : "temp.bin", typedoc == 1 ? "cliente.txt" : "cliente.bin") != 0) {//renomeia o arquivo temp para oficina,retorna 0 se bem sucedido
            return -4;
        } else {
            return 0;
        }
    } else {
        // Remover o arquivo tempor�rio se nenhum dado foi exclu�do
        remove(typedoc == 1 ? "temp.txt" : "temp.bin");
       return 1;
    }
}

int excluir_veiculo() {
    int encontrado = 0,x; // Vari�vel para verificar se o registro foi encontrado
    char placa_remover[30]; // Placa do ve�culo a ser removido

    printf("Digite a placa do ve�culo que deseja remover: ");
    fgets(placa_remover, sizeof(placa_remover), stdin);
    strtok(placa_remover, "\n"); // Remove o '\n' do final da entrada

    // Abrir arquivo de entrada para leitura
    FILE *veicle_file = fopen(typedoc == 1 ? "veiculo.txt" : "veiculo.bin", typedoc == 1 ? "r" : "rb");
    if (!veicle_file) {
        return -2;
    }

    // Abrir arquivo tempor�rio para escrita
    FILE *temp_file = fopen(typedoc == 1 ? "temp.txt" : "temp.bin", typedoc == 1 ? "w" : "wb");
    if (!temp_file) {
        fclose(veicle_file);
        return -4;
    }

    if (typedoc == 1) {  // Exclus�o em arquivo de texto
        char placa[30], modelo[50], marca[50], chassi[20];
        int anof;

        while (fscanf(veicle_file, "%29[^,],%49[^,],%49[^,],%d,%19[^\n]\n",
                      placa, modelo, marca, &anof, chassi) == 5) {
            if (strcmp(placa, placa_remover) == 0) {
                encontrado = 1; // Marca que o registro foi encontrado
            } else {
                // Escreve corretamente os dados no arquivo tempor�rio
                fprintf(temp_file, "%s,%s,%s,%d,%s\n", placa, modelo, marca, anof, chassi);
            }
        }
    } else {  // Exclus�o em arquivo bin�rio
        VEICULOS v;

        while (fread(&v, sizeof(VEICULOS), 1, veicle_file) == 1) {
            if (strcmp(v.placa, placa_remover) == 0) {
                encontrado = 1; // Marca que o registro foi encontrado
            } else {
                fwrite(&v, sizeof(VEICULOS), 1, temp_file);
            }
        }
    }

    fclose(veicle_file);
    fclose(temp_file);

    if (encontrado) {
        // Substituir o arquivo original pelo arquivo tempor�rio
        if (remove(typedoc == 1 ? "veiculo.txt" : "veiculo.bin") != 0 ||
            rename(typedoc == 1 ? "temp.txt" : "temp.bin", typedoc == 1 ? "veiculo.txt" : "veiculo.bin") != 0) {
            return -4;
        } else {
            return 0;
        }
    } else {
        // Remover o arquivo tempor�rio se nenhum dado foi exclu�do
        remove(typedoc == 1 ? "temp.txt" : "temp.bin");
        return 1;
    }
}

int excluir_peca() {
    int encontrado = 0,x; // Vari�vel para verificar se o registro foi encontrado
    int cod_remover; // codigo da pe�a a ser removida

    printf("Digite o codigo da peca que deseja remover: ");
    scanf("%d",&cod_remover);
    getchar();

    // Abrir arquivo de entrada para leitura
    FILE *pecas_file = fopen(typedoc == 1 ? "pecas.txt" : "pecas.bin", typedoc == 1 ? "r" : "rb");
    if (!pecas_file) {
        return -2;
    }

    // Abrir arquivo tempor�rio para escrita
    FILE *temp_file = fopen(typedoc == 1 ? "temp.txt" : "temp.bin", typedoc == 1 ? "w" : "wb");
    if (!temp_file) {
        fclose(pecas_file);
        return -4;
    }
if (typedoc == 1) {  // Texto
        int codigo, qntd_estoque, qntd_minima;
        char descricao[50], fabricante[30], fornecedor[30];
        float p_custo, p_venda;

        while (fscanf(pecas_file, "%d,%49[^,],%29[^,],%29[^,],%f,%f,%d,%d\n",//leitura minimizada para evitar overflow do buffer
                      &codigo, descricao, fabricante, fornecedor,
                      &p_custo, &p_venda, &qntd_estoque, &qntd_minima) == 8) {
            if (codigo==cod_remover) {
                encontrado = 1; // Marca que o registro foi encontrado
            } else {
                fprintf(temp_file, "%d,%s,%s,%s,%.2f,%.2f,%d,%d\n",
                        codigo, descricao, fabricante, fornecedor,
                      p_custo, p_venda, qntd_estoque, qntd_minima);
            }
        }
    } else { // Exclus�o em arquivo bin�rio
        PECA p;

        while (fread(&p, sizeof(PECA), 1, pecas_file) == 1) {
            if (p.codigo==cod_remover) {
                encontrado = 1; // Marca que o registro foi encontrado
            } else {
                fwrite(&p, sizeof(PECA), 1, temp_file);
            }
        }
    }

    fclose(pecas_file);
    fclose(temp_file);

    if (encontrado) {
        // Substituir o arquivo original pelo arquivo tempor�rio
        if (remove(typedoc == 1 ? "pecas.txt" : "pecas.bin") != 0 ||
            rename(typedoc == 1 ? "temp.txt" : "temp.bin", typedoc == 1 ? "pecas.txt" : "pecas.bin") != 0) {//renomeia o arquivo temp para oficina,retorna 0 se bem sucedido
            return -4;
        } else {
            return 0;
        }
    } else {
        // Remover o arquivo tempor�rio se nenhum dado foi exclu�do
        remove(typedoc == 1 ? "temp.txt" : "temp.bin");
        return 1;
    }
}

int excluir_fornecedor() {
    int encontrado = 0,x; // Vari�vel para verificar se o registro foi encontrado
    int cod_remover; // codigo da pe�a a ser removida

    printf("Digite o codigo do fornecedor que deseja remover: ");
    scanf("%d",&cod_remover);
    getchar();

    // Abrir arquivo de entrada para leitura
    FILE *fornecedor_file = fopen(typedoc == 1 ? "fornecedor.txt" : "fornecedor.bin", typedoc == 1 ? "r" : "rb");
    if (!fornecedor_file) {
        return -2;
    }

    // Abrir arquivo tempor�rio para escrita
    FILE *temp_file = fopen(typedoc == 1 ? "temp.txt" : "temp.bin", typedoc == 1 ? "w" : "wb");
    if (!temp_file) {
        fclose(fornecedor_file);
        return -4;
    }
   if (typedoc == 1) {  // Texto
        int codigo;
        char nome_fantasia[50],razao_social[50],inscricao_est[20],cnpj[20],endereco[100],telefone[20],email[50];

        while (fscanf(fornecedor_file, "%d,%49[^,],%49[^,],%19[^,],%19[^,],%99[^,],%19[^,],%49[^\n]\n",//adicionado o [^\n] pois ultima leitura � uma string
                      &codigo, nome_fantasia, razao_social, inscricao_est,
                      cnpj, endereco, telefone, email) == 8) {
            if (codigo == cod_remover) {
                encontrado = 1; // Marca que o registro foi encontrado
            } else {
                fprintf(temp_file, "%d,%s,%s,%s,%s,%s,%s,%s\n",
                        codigo, nome_fantasia, razao_social, inscricao_est,
                      cnpj, endereco, telefone, email);
            }
        }
    } else { // Exclus�o em arquivo bin�rio
        FORNECEDOR f;

        while (fread(&f, sizeof(FORNECEDOR), 1, fornecedor_file) == 1) {
            if (f.codigo==cod_remover) {
                encontrado = 1; // Marca que o registro foi encontrado
            } else {
                fwrite(&f, sizeof(FORNECEDOR), 1, temp_file);
            }
        }
    }

    fclose(fornecedor_file);
    fclose(temp_file);

    if (encontrado) {
        // Substituir o arquivo original pelo arquivo tempor�rio
        if (remove(typedoc == 1 ? "fornecedor.txt" : "fornecedor.bin") != 0 ||
            rename(typedoc == 1 ? "temp.txt" : "temp.bin", typedoc == 1 ? "fornecedor.txt" : "fornecedor.bin") != 0) {//renomeia o arquivo temp para oficina,retorna 0 se bem sucedido
            return -4;
        } else {
            return 0;
        }
    } else {
        // Remover o arquivo tempor�rio se nenhum dado foi exclu�do
        remove(typedoc == 1 ? "temp.txt" : "temp.bin");
        return 1;
    }
}

int excluir_servico() {
    int encontrado = 0,x; // Vari�vel para verificar se o registro foi encontrado
    int cod_remover; // codigo da pe�a a ser removida

    printf("Digite o codigo do servico que deseja remover: ");
    scanf("%d",&cod_remover);
    getchar();

    // Abrir arquivo de entrada para leitura
    FILE *servico_file = fopen(typedoc == 1 ? "servico.txt" : "servico.bin", typedoc == 1 ? "r" : "rb");
    if (!servico_file) {
        return -2;
    }

    // Abrir arquivo tempor�rio para escrita
    FILE *temp_file = fopen(typedoc == 1 ? "temp.txt" : "temp.bin", typedoc == 1 ? "w" : "wb");
    if (!temp_file) {
        fclose(servico_file);
        return -4;
    }
   if (typedoc == 1) {  // Texto
        int codigo;
        char descricao[50];
        float preco,comissao;

        while (fscanf(servico_file, "%d,%49[^,],%f,%f\n",
                      &codigo, descricao, &preco, &comissao) == 4 ) {
            if (codigo==cod_remover) {
                encontrado = 1; // Marca que o registro foi encontrado
            } else {
                fprintf(temp_file, "%d,%s,%s,%.2f,%.2f\n",
                        codigo,descricao,preco,comissao);
            }
        }
    } else { // Exclus�o em arquivo bin�rio
        SERVICO s;

        while (fread(&s, sizeof(SERVICO), 1, servico_file) == 1) {
            if (s.codigo==cod_remover) {
                encontrado = 1; // Marca que o registro foi encontrado
            } else {
                fwrite(&s, sizeof(SERVICO), 1, temp_file);
            }
        }
    }

    fclose(servico_file);
    fclose(temp_file);

    if (encontrado) {
        // Substituir o arquivo original pelo arquivo tempor�rio
        if (remove(typedoc == 1 ? "servico.txt" : "servico.bin") != 0 ||
            rename(typedoc == 1 ? "temp.txt" : "temp.bin", typedoc == 1 ? "servico.txt" : "servico.bin") != 0) {//renomeia o arquivo temp para oficina,retorna 0 se bem sucedido
            return -4;
        } else {
           return 0;
        }
    } else {
        // Remover o arquivo tempor�rio se nenhum dado foi exclu�do
        remove(typedoc == 1 ? "temp.txt" : "temp.bin");
        return 1;
    }
}

int excluir_funcionario() {
    int encontrado = 0,x; // Vari�vel para verificar se o registro foi encontrado
    char cpf_remover[15]; // codigo da pe�a a ser removida

    printf("Digite o cpf do funcionario que deseja remover: ");
    fgets(cpf_remover, sizeof(cpf_remover), stdin);
    strtok(cpf_remover, "\n");

    // Abrir arquivo de entrada para leitura
    FILE *funcionario_file = fopen(typedoc == 1 ? "funcionario.txt" : "funcionario.bin", typedoc == 1 ? "r" : "rb");
    if (!funcionario_file) {
        return -2;
    }

    // Abrir arquivo tempor�rio para escrita
    FILE *temp_file = fopen(typedoc == 1 ? "temp.txt" : "temp.bin", typedoc == 1 ? "w" : "wb");
    if (!temp_file) {
        fclose(funcionario_file);
        return -4;
    }
   if (typedoc == 1) {  // Texto
        char nome[50],cpf[15],cargo[30];
        float salario;

        while (fscanf(funcionario_file, "%49[^,],%14[^,],%29[^,],%f\n",
                      nome, cpf, cargo,&salario) == 4) {
            if (strcmp(cpf, cpf_remover) == 0) {
                encontrado = 1; // Marca que o registro foi encontrado
            } else {
                fprintf(temp_file, "%s,%s,%s,%.2f\n",
                        nome,cpf,cargo,salario);
            }
        }
    } else { // Exclus�o em arquivo bin�rio
        FUNCIONARIO f;

        while (fread(&f, sizeof(FUNCIONARIO), 1, funcionario_file) == 1) {
            if (strcmp(f.cpf, cpf_remover) == 0) {
                encontrado = 1; // Marca que o registro foi encontrado
            } else {
                fwrite(&f, sizeof(FUNCIONARIO), 1, temp_file);
            }
        }
    }

    fclose(funcionario_file);
    fclose(temp_file);

    if (encontrado) {
        // Substituir o arquivo original pelo arquivo tempor�rio
        if (remove(typedoc == 1 ? "funcionario.txt" : "funcionario.bin") != 0 ||
            rename(typedoc == 1 ? "temp.txt" : "temp.bin", typedoc == 1 ? "funcionario.txt" : "funcionario.bin") != 0) {//renomeia o arquivo temp para oficina,retorna 0 se bem sucedido
            return -4;
        } else {
            return 0;
        }
    } else {
        // Remover o arquivo tempor�rio se nenhum dado foi exclu�do
        remove(typedoc == 1 ? "temp.txt" : "temp.bin");
        return 1;
    }
}

//come�o das rotinas de altera��o

int alterar_oficina() {
    int encontrado = 0,op,x,duplicado=0;  // Vari�vel para verificar se o registro foi encontrado
    char cpf_busca[20];  // CNPJ da oficina a ser alterada

    printf("Digite o CPF/CNPJ da oficina que deseja alterar: ");
    fgets(cpf_busca, sizeof(cpf_busca), stdin);
    strtok(cpf_busca, "\n");  // Remove o '\n' do final da entrada

    // Abrir arquivo de entrada para leitura
    FILE *oficina_file = fopen(typedoc == 1 ? "oficina.txt" : "oficina.bin", typedoc == 1 ? "r" : "rb");
    if (!oficina_file) {
        return -2;
    }

    // Abrir arquivo tempor�rio para escrita
    FILE *temp_file = fopen(typedoc == 1 ? "temp.txt" : "temp.bin", typedoc == 1 ? "w" : "wb");
    if (!temp_file) {
        fclose(oficina_file);
        return -4;
    }

    if (typedoc == 1) {  // Texto
            OFICINA temp;

        while (fscanf(oficina_file, "%49[^,],%19[^,],%49[^,],%19[^,],%19[^,],%f\n",
                      temp.nome, temp.cpf, temp.endereco, temp.telefone, temp.email, &temp.lucro) == 6) {
            if (strcmp(temp.cpf, cpf_busca) == 0) {  // Compara o CPF
                encontrado = 1;  // Marca que o registro foi encontrado
                print_oficina(temp);//printa na tela os dados
            do{
            printf("O que deseja alterar?\n");
            printf("|1-Nome 2-CPF\CNPJ 3-Endereco 4-Telefone 5- E-mail 6-Lucro|\n");
            scanf("%d",&op);
            getchar();
//============================================================================================
            switch(op){
                case 1:
                    do {
                        duplicado = 0;  // Reseta a flag
                        printf("Novo Nome: ");
                        fgets(temp.nome, sizeof(temp.nome), stdin);
                        strtok(temp.nome, "\n");
                            // Verifica duplica��o no arquivo
                            FILE *check_file = fopen("oficina.txt","r");//abre arquivo de oficina
                            if (!check_file) {
                                return -4;
                                }
                            char analy[50];
                            while (fscanf(check_file, "%49[^,],%*[^,],%*[^,],%*[^,],%*[^,],%*f\n", analy) == 1) {//pega string de cpf
                                if (strcmp(analy, temp.nome) == 0 && strcmp(analy, cpf_busca) != 0) {//analisa se cpf j� existe no cadastro,mas n�o conta com o cpf de busca
                                    int x = copy_element();
                                    if (x == 1) {
                                        fclose(check_file);
                                        return 2;  // Usu�rio optou por sair
                                    }
                                    duplicado = 1;  // Marca como duplicado
                                    break;
                                }
                            }
                        fclose(check_file);  // Fecha o arquivo de verifica��o
                    } while (duplicado);
                break;
//============================================================================================
                case 2:
                    do {
                        duplicado = 0;  // Reseta a flag
                        printf("Novo CPF/CNPJ: ");
                        fgets(temp.cpf, sizeof(temp.cpf), stdin);
                            strtok(temp.cpf, "\n");
                            // Verifica duplica��o no arquivo
                            FILE *check_file = fopen("oficina.txt","r");//abre arquivo de oficina
                            if (!check_file) {
                                return -2;
                                }
                            char analy[20];
                            while (fscanf(check_file, "%*[^,],%19[^,],%*[^,],%*[^,],%*[^,],%*f\n", analy) == 1) {//pega string de cpf
                                if (strcmp(analy, temp.cpf) == 0 && strcmp(analy, cpf_busca) != 0) {//analisa se cpf j� existe no cadastro,mas n�o conta com o cpf de busca
                                    int x = copy_element();
                                    if (x == 1) {
                                        fclose(check_file);
                                        return 2;  // Usu�rio optou por sair
                                    }
                                    duplicado = 1;  // Marca como duplicado
                                    break;
                                }
                            }
                        fclose(check_file);  // Fecha o arquivo de verifica��o
                    } while (duplicado);
                break;
//============================================================================================
                case 3:
                    printf("Novo Endere�o: ");
                    fgets(temp.endereco, sizeof(temp.endereco), stdin);
                    strtok(temp.endereco, "\n");
                break;
//============================================================================================
                case 4:
                    printf("Novo Telefone: ");
                    fgets(temp.telefone, sizeof(temp.telefone), stdin);
                    strtok(temp.telefone, "\n");
                break;
//============================================================================================
                case 5:
                    printf("Novo E-mail: ");
                    fgets(temp.email, sizeof(temp.email), stdin);
                    strtok(temp.email, "\n");
                break;
//============================================================================================
                case 6:
                    printf("Nova Porcentagem de Lucro: ");
                    scanf("%f", &temp.lucro);
                break;
//============================================================================================
                default:
                    return -3;
                    break;
            }
           x=repeat();
            }while(x==1);
            }
            // Salva no arquivo tempor�rio (alterado ou n�o)
            fprintf(temp_file, "%s,%s,%s,%s,%s,%.2f\n", temp.nome, temp.cpf, temp.endereco, temp.telefone, temp.email, temp.lucro);
        }
    } else {  // Bin�rio
        OFICINA o;
        while (fread(&o, sizeof(OFICINA), 1, oficina_file) == 1) {
            if (strcmp(o.cpf, cpf_busca) == 0) {
                encontrado = 1;  // Marca que o registro foi encontrado
                print_oficina(o);
                do{
                printf("O que deseja alterar?\n");
            printf("|1-Nome 2-CPF\CNPJ 3-Endereco 4-Telefone 5- E-mail 6-Lucro|\n");
            scanf("%d",&op);
            getchar();
//============================================================================================
            switch(op){
                case 1:
                    do {
                    duplicado = 0;
                    printf("Novo Nome: ");
                    fgets(o.nome, sizeof(o.nome), stdin);
                    strtok(o.nome, "\n");

                    FILE *check_file = fopen("oficina.bin","rb");
                    if (!check_file) {
                        return -2;
                    }

                        OFICINA temp;
                        while (fread(&temp, sizeof(OFICINA), 1, check_file) == 1) {
                            if (strcmp(temp.nome, o.nome) == 0 && strcmp(temp.cpf, cpf_busca) != 0) {
                               int x = copy_element();
                                    if (x == 1) {
                                        fclose(check_file);
                                        return 2;  // Usu�rio optou por sair
                                    }
                                duplicado = 1;
                                break;
                            }
                        }

                    fclose(check_file);
                } while (duplicado);
                break;
//============================================================================================
                case 2:
                do {
                    duplicado = 0;
                    printf("Novo CPF/CNPJ: ");
                    fgets(o.cpf, sizeof(o.cpf), stdin);
                    strtok(o.cpf, "\n");

                    FILE *check_file = fopen("oficina.bin","rb");
                    if (!check_file) {
                        return -2;
                    }

                        OFICINA temp;
                        while (fread(&temp, sizeof(OFICINA), 1, check_file) == 1) {
                            if (strcmp(temp.cpf, o.cpf) == 0 && strcmp(temp.cpf, cpf_busca) != 0) {
                                int x = copy_element();
                                    if (x == 1) {
                                        fclose(check_file);
                                        return 2;  // Usu�rio optou por sair
                                    }
                                duplicado = 1;
                                break;
                            }
                        }

                    fclose(check_file);
                } while (duplicado);
                break;
//============================================================================================
                case 3:
                    printf("Novo Endere�o: ");
                    fgets(o.endereco, sizeof(o.endereco), stdin);
                    strtok(o.endereco, "\n");
                break;
//============================================================================================
                case 4:
                    printf("Novo Telefone: ");
                    fgets(o.telefone, sizeof(o.telefone), stdin);
                    strtok(o.telefone, "\n");
                break;
//============================================================================================
                case 5:
                    printf("Novo E-mail: ");
                    fgets(o.email, sizeof(o.email), stdin);
                    strtok(o.email, "\n");
                break;
//============================================================================================
                case 6:
                    printf("Nova Porcentagem de Lucro: ");
                    scanf("%f", &o.lucro);
                break;
//============================================================================================
                default:
                    return -3;
            }
            x=repeat();
            }while(x==1);
            }

            fwrite(&o, sizeof(OFICINA), 1, temp_file);
        }
    }

    fclose(oficina_file);
    fclose(temp_file);

    if (encontrado) {
        if (remove(typedoc == 1 ? "oficina.txt" : "oficina.bin") != 0 ||
            rename(typedoc == 1 ? "temp.txt" : "temp.bin", typedoc == 1 ? "oficina.txt" : "oficina.bin") != 0) {
            return -4;
        } else {
            return 0;
        }
    } else {
        remove(typedoc == 1 ? "temp.txt" : "temp.bin");
        return 1;
    }
}

int alterar_cliente() {
    int encontrado = 0,op,x,duplicado=0;  // Vari�vel para verificar se o registro foi encontrado
    int cod_busca;

    printf("Digite o codigo do cliente que deseja alterar: ");
    scanf("%d",&cod_busca);
    getchar();  // Remove o '\n' do final da entrada
    // Abrir arquivo de entrada para leitura
    FILE *cliente_file = fopen(typedoc == 1 ? "cliente.txt" : "cliente.bin", typedoc == 1 ? "r" : "rb");
    if (!cliente_file) {
        return -2;
    }

    // Abrir arquivo tempor�rio para escrita
    FILE *temp_file = fopen(typedoc == 1 ? "temp.txt" : "temp.bin", typedoc == 1 ? "w" : "wb");
    if (!temp_file) {
        fclose(cliente_file);
        return -4;
    }

    if (typedoc == 1) {  // Texto
        CLIENTE c;

        while (fscanf(cliente_file, "%d,%49[^,],%19[^,],%49[^,],%19[^,],%19[^\n]\n",
                      &c.codigo, c.nome, c.cpf, c.endereco, c.telefone, c.email) == 6) {
            if (c.codigo==cod_busca) {  // Compara o codigo
                encontrado = 1;  // Marca que o registro foi encontrado
                print_cliente(c);
            do{
            printf("O que deseja alterar?\n");
            printf("|1-Nome 2-CPF 3-Endereco 4-Telefone 5- E-mail|\n");
            scanf("%d",&op);
            getchar();
//============================================================================================
            switch(op){
                case 1:
                    printf("Novo Nome: ");
                    fgets(c.nome, sizeof(c.nome), stdin);
                    strtok(c.nome, "\n");
                break;
//============================================================================================
                case 2:
                    do {
                        duplicado = 0;
                        printf("Novo CPF: ");
                        fgets(c.cpf, sizeof(c.cpf), stdin);
                        strtok(c.cpf, "\n");

                        // Verifica duplica��o no arquivo
                        FILE *check_file = fopen("cliente.txt","r");
                        if (!check_file) {
                            return -2;
                        }

                            int temp_codigo;
                            char temp_cpf[15];
                            while (fscanf(check_file, "%d,%*[^,],%14[^,],%*[^,],%*[^,],%*[^\n]\n",
                                            &temp_codigo, temp_cpf) == 2) {
                                if (strcmp(temp_cpf, c.cpf) == 0 && temp_codigo != c.codigo) {//verifica se o codigo � repitido e possui codigo diferente de procura
                                   int x = copy_element();
                                    if (x == 1) {
                                        fclose(check_file);
                                        return 2;  // Usu�rio optou por sair
                                    }
                                    duplicado = 1;  // Marca como duplicado
                                    break;
                                }
                            }
                        fclose(check_file);  // Fecha o arquivo ap�s a verifica��o
                    } while (duplicado);
                    break;
//============================================================================================
                case 3:
                    printf("Novo Endere�o: ");
                    fgets(c.endereco, sizeof(c.endereco), stdin);
                    strtok(c.endereco, "\n");
                break;
//============================================================================================
                case 4:
                    printf("Novo Telefone: ");
                    fgets(c.telefone, sizeof(c.telefone), stdin);
                    strtok(c.telefone, "\n");
                break;
//============================================================================================
                case 5:
                    printf("Novo E-mail: ");
                    fgets(c.email, sizeof(c.email), stdin);
                    strtok(c.email, "\n");
                break;
//============================================================================================
                default:
                    return -3;;
                    break;
//============================================================================================
            }
           x=repeat();
            }while(x==1);
            }

            // Salva no arquivo tempor�rio (alterado ou n�o)
            fprintf(temp_file, "%d,%s,%s,%s,%s,%s\n", c.codigo, c.nome, c.cpf, c.endereco, c.telefone, c.email);
        }
    } else {  // Bin�rio
        CLIENTE c;
        while (fread(&c, sizeof(CLIENTE), 1, cliente_file) == 1) {
            if (c.codigo==cod_busca) {
                encontrado = 1;  // Marca que o registro foi encontrado
                print_cliente(c);
                do{
                printf("O que deseja alterar?\n");
            printf("|1-Nome 2-CPF 3-Endereco 4-Telefone 5- E-mail|\n");
            scanf("%d",&op);
            getchar();
//============================================================================================
            switch(op){
                case 1:
                    printf("Novo Nome: ");
                    fgets(c.nome, sizeof(c.nome), stdin);
                    strtok(c.nome, "\n");
                break;
//============================================================================================
                case 2:
                    do {
                        duplicado = 0;
                        printf("Novo CPF: ");
                        fgets(c.cpf, sizeof(c.cpf), stdin);
                        strtok(c.cpf, "\n");

                        FILE *check_file = fopen("cliente.bin","rb");
                        if (!check_file) {
                            return -2;
                        }
                            CLIENTE temp;
                            while (fread(&temp, sizeof(CLIENTE), 1, check_file) == 1) {
                                if (strcmp(temp.cpf, c.cpf) == 0 && temp.codigo != c.codigo) {
                                   int x = copy_element();
                                    if (x == 1) {
                                        fclose(check_file);
                                        return 2;  // Usu�rio optou por sair
                                    }
                                    duplicado = 1;
                                    break;
                                }
                            }
                    fclose(check_file);
                } while (duplicado);
                break;
//============================================================================================
                case 3:
                    printf("Novo Endere�o: ");
                    fgets(c.endereco, sizeof(c.endereco), stdin);
                    strtok(c.endereco, "\n");
                break;
//============================================================================================
                case 4:
                    printf("Novo Telefone: ");
                    fgets(c.telefone, sizeof(c.telefone), stdin);
                    strtok(c.telefone, "\n");
                break;
//============================================================================================
                case 5:
                    printf("Novo E-mail: ");
                    fgets(c.email, sizeof(c.email), stdin);
                    strtok(c.email, "\n");
                break;
//============================================================================================
                default:
                    return -3;
            }
           x=repeat();
            }while(x==1);
            }

            fwrite(&c, sizeof(CLIENTE), 1, temp_file);
        }
    }

    fclose(cliente_file);
    fclose(temp_file);

    if (encontrado) {
        if (remove(typedoc == 1 ? "cliente.txt" : "cliente.bin") != 0 ||
            rename(typedoc == 1 ? "temp.txt" : "temp.bin", typedoc == 1 ? "cliente.txt" : "cliente.bin") != 0) {
            return -4;
        } else {
            return 0;
        }
    } else {
        remove(typedoc == 1 ? "temp.txt" : "temp.bin");
        return 1;
    }
}

int alterar_veiculo() {
    int encontrado = 0, op, x,duplicado=0; // Vari�vel para verificar se o registro foi encontrado
    char placa_busca[30];

    printf("Digite a placa do ve�culo que deseja alterar: ");
    fgets(placa_busca, sizeof(placa_busca), stdin);
    strtok(placa_busca, "\n"); // Remove o '\n' da entrada

    // Abrir arquivo de entrada para leitura
    FILE *veicle_file = fopen(typedoc == 1 ? "veiculo.txt" : "veiculo.bin", typedoc == 1 ? "r" : "rb");
    if (!veicle_file) {
        return -2;
    }

    // Abrir arquivo tempor�rio para escrita
    FILE *temp_file = fopen(typedoc == 1 ? "temp.txt" : "temp.bin", typedoc == 1 ? "w" : "wb");
    if (!temp_file) {
        fclose(veicle_file);
        return -4;
    }

    if (typedoc == 1) { // Modo texto
        VEICULOS v;

        while (fscanf(veicle_file, "%29[^,],%49[^,],%49[^,],%d,%19[^,],%19[^\n]\n",
                      v.placa, v.modelo, v.marca, &v.anof, v.chassi, v.ptt) == 5) {
            if (strcmp(v.placa, placa_busca) == 0) { // Ve�culo encontrado
                encontrado = 1;

            print_veiculo(v);

                do {
                    printf("O que deseja alterar?\n");
                    printf("|1-Placa 2-Modelo 3-Marca 4-Chassi 5-Ano de fabrica��o 6-Propriet�rio|\n");
                    scanf("%d", &op);
                    getchar(); // Limpa o buffer
//============================================================================================
                    switch (op) {
                        case 1:
                            do {
                        duplicado = 0;
                        printf("Nova Placa: ");
                        fgets(v.placa, sizeof(v.placa), stdin);
                        strtok(v.placa, "\n");

                        // Verifica duplica��o no arquivo
                        FILE *check_file = fopen("veiculo.txt","r");
                        if (!check_file) {
                            return -2;
                        }

                            char temp_chassi[20];
                            char temp_placa[30];
                            while (fscanf(check_file, "%29[^,],%*[^,],%*[^,],%*d,%19[^\n]\n",
                                            temp_placa, temp_chassi) == 2) {
                                if (strcmp(temp_placa, v.placa) == 0 && strcmp(temp_chassi, v.chassi) != 0) {//verifica se a placa � repitida e se possui mesmo chassi
                                    int x = copy_element();
                                    if (x == 1) {
                                        fclose(check_file);
                                        return 2;  // Usu�rio optou por sair
                                    }
                                    duplicado = 1;  // Marca como duplicado
                                    break;
                                }
                            }
                        fclose(check_file);  // Fecha o arquivo ap�s a verifica��o
                    } while (duplicado);
                        break;
//============================================================================================
                        case 2:
                            printf("Novo Modelo: ");
                            fgets(v.modelo, sizeof(v.modelo), stdin);
                            strtok(v.modelo, "\n");
                            break;
//============================================================================================
                        case 3:
                            printf("Nova Marca: ");
                            fgets(v.marca, sizeof(v.marca), stdin);
                            strtok(v.marca, "\n");
                            break;
//============================================================================================
                        case 4:
                            do {
                        duplicado = 0;
                        printf("Novo Chassi: ");
                        fgets(v.chassi, sizeof(v.chassi), stdin);
                        strtok(v.chassi, "\n");

                        // Verifica duplica��o no arquivo
                        FILE *check_file = fopen("veiculo.txt","r");
                        if (!check_file) {
                            return -2;
                        }

                            char temp_chassi[20];
                            char temp_placa[30];
                            while (fscanf(check_file, "%29[^,],%*[^,],%*[^,],%*d,%19[^\n]\n",
                                            temp_placa, temp_chassi) == 2) {
                                if (strcmp(temp_chassi, v.chassi) == 0 && strcmp(temp_placa, v.placa) != 0) {//verifica se a chassi � repitida e se possui mesma placa
                                    int x = copy_element();
                                    if (x == 1) {
                                        fclose(check_file);
                                        return 2;  // Usu�rio optou por sair
                                    }
                                    duplicado = 1;  // Marca como duplicado
                                    break;
                                }
                            }
                        fclose(check_file);  // Fecha o arquivo ap�s a verifica��o
                    } while (duplicado);
                            break;
//============================================================================================
                        case 5:
                            printf("Novo Ano de Fabrica��o: ");
                            scanf("%d", &v.anof);
                            getchar(); // Limpa o buffer
                            break;
//============================================================================================
                        case 6:
                            do{
                                printf("Novo propriet�rio: ");
                            fgets(v.ptt, sizeof(v.ptt), stdin);
                            strtok(v.ptt, "\n");
                            // Verifica duplica��o no arquivo
                                         // Verifica se o propriet�rio existe
                        FILE *cliente_file = fopen(typedoc == 1 ? "cliente.txt" : "cliente.bin", typedoc == 1 ? "r" : "rb");
                        if (!cliente_file) return -2;

                        if (typedoc == 1) {
                            char cpf[20];
                            while (fscanf(cliente_file, "%*d,%*[^,],%19[^,],%*[^,],%*[^,],%*[^\n]\n", cpf) == 1) {
                                if (strcmp(cpf, v.ptt) == 0) {
                                    duplicado = 1;
                                    break;
                                }
                            }
                        } else {
                            CLIENTE temp;
                            while (fread(&temp, sizeof(CLIENTE), 1, cliente_file) == 1) {
                                if (strcmp(temp.cpf, v.ptt) == 0) {
                                    duplicado = 1;
                                    break;
                                }
                            }
                        }
                        fclose(cliente_file);

                        if (!duplicado) {
                            int x = not_found();
                            if (x == 1) return 0; // Usu�rio optou por sair
                        }
                            }while(duplicado);
                            break;
//============================================================================================
                        default:
                            return -3;
                    }

                   x=repeat();
                } while (x == 1);
            }

            // Salva o registro (alterado ou n�o) no arquivo tempor�rio
            fprintf(temp_file, "%s,%s,%s,%d,%s\n", v.placa, v.modelo, v.marca, v.anof, v.chassi);
        }
    } else { // Modo bin�rio
        VEICULOS v;

        while (fread(&v, sizeof(VEICULOS), 1, veicle_file) == 1) {
            if (strcmp(v.placa, placa_busca) == 0) {
                encontrado = 1;
                print_veiculo(v);

                do {
                    printf("O que deseja alterar?\n");
                    printf("|1-Placa 2-Modelo 3-Marca 4-Chassi 5-Ano de fabrica��o|\n");
                    scanf("%d", &op);
                    getchar(); // Limpa o buffer
//============================================================================================
                    switch (op) {
                        case 1:
                            do {
                            printf("Nova Placa: ");
                            fgets(v.placa, sizeof(v.placa), stdin);
                            strtok(v.placa, "\n");

                        duplicado = 0;

                        FILE *check_file = fopen("veiculo.bin","rb");
                        if (!check_file) {
                            return -2;
                        }
                            VEICULOS temp;
                            while (fread(&temp, sizeof(VEICULOS), 1, check_file) == 1) {
                                if (strcmp(temp.placa, v.placa) == 0 && strcmp(temp.chassi, v.chassi) != 0) {
                                    int x = copy_element();
                                    if (x == 1) {
                                        fclose(check_file);
                                        return 2;  // Usu�rio optou por sair
                                    }
                                    duplicado = 1;
                                    break;
                                }
                            }
                    fclose(check_file);
                }while (duplicado);
                            break;
//============================================================================================
                        case 2:
                            printf("Novo Modelo: ");
                            fgets(v.modelo, sizeof(v.modelo), stdin);
                            strtok(v.modelo, "\n");
                            break;
//============================================================================================
                        case 3:
                            printf("Nova Marca: ");
                            fgets(v.marca, sizeof(v.marca), stdin);
                            strtok(v.marca, "\n");
                            break;
//============================================================================================
                        case 4:
                            do {
                            printf("Novo Chassi: ");
                            fgets(v.chassi, sizeof(v.chassi), stdin);
                            strtok(v.chassi, "\n");

                        duplicado = 0;

                        FILE *check_file = fopen("veiculo.bin","rb");
                        if (!check_file) {
                            return -2;
                        }
                            VEICULOS temp;
                            while (fread(&temp, sizeof(VEICULOS), 1, check_file) == 1) {
                                if (strcmp(temp.chassi, v.chassi) == 0 && strcmp(temp.placa, v.placa) != 0) {
                                     int x = copy_element();
                                    if (x == 1) {
                                        fclose(check_file);
                                        return 2;  // Usu�rio optou por sair
                                    }
                                    duplicado = 1;
                                    break;
                                }
                            }
                    fclose(check_file);
                }while (duplicado);
                            break;
//============================================================================================
                        case 5:
                            printf("Novo Ano de Fabrica��o: ");
                            scanf("%d", &v.anof);
                            getchar(); // Limpa o buffer
                            break;
//============================================================================================
                        default:
                            return -3;
                    }
                    x=repeat();
                } while (x == 1);
            }

            fwrite(&v, sizeof(VEICULOS), 1, temp_file);
        }
    }

    fclose(veicle_file);
    fclose(temp_file);

    if (encontrado) {
        // Atualiza o arquivo original
        if (remove(typedoc == 1 ? "veiculo.txt" : "veiculo.bin") != 0 ||
            rename(typedoc == 1 ? "temp.txt" : "temp.bin", typedoc == 1 ? "veiculo.txt" : "veiculo.bin") != 0) {
            return -4;
        } else {
            return 0;
        }
    } else {
        remove(typedoc == 1 ? "temp.txt" : "temp.bin"); // Remove arquivo tempor�rio
        return 1;
    }
}

int alterar_peca() {

    int encontrado = 0,op,x,duplicado=0;  // Vari�vel para verificar se o registro foi encontrado
    int cod_busca;

    printf("Digite o codigo da peca que deseja alterar: ");
    scanf("%d",&cod_busca);
    getchar();  // Remove o '\n' do final da entrada

    // Abrir arquivo de entrada para leitura
    FILE *peca_file = fopen(typedoc == 1 ? "pecas.txt" : "pecas.bin", typedoc == 1 ? "r" : "rb");
    if (!peca_file) {
        return -2;
    }

    // Abrir arquivo tempor�rio para escrita
    FILE *temp_file = fopen(typedoc == 1 ? "temp.txt" : "temp.bin", typedoc == 1 ? "w" : "wb");
    if (!temp_file) {
        fclose(peca_file);
        return -4;
    }

    if (typedoc == 1) {  // Texto
        PECA p;

        while (fscanf(peca_file, "%d,%49[^,],%29[^,],%29[^,],%f,%f,%d,%d\n",//leitura minimizada para evitar overflow do buffer
                      &p.codigo, p.descricao, p.fabricante, p.fornecedor,
                      &p.p_custo, &p.p_venda, &p.qntd_estoque, &p.qntd_minima) == 8) {
            if (cod_busca==p.codigo) {  // Compara o codigo
                encontrado = 1;  // Marca que o registro foi encontrado
                print_pecas(p);
            do{
            printf("O que deseja alterar?\n");
            printf("|1-Descricao 2-Fabricante 3-Fornecedor 4-Preco de custo 5-Preco de venda 6-Quantidade em estoque 7-Quantidade minima|\n");
            scanf("%d",&op);
            getchar();
//============================================================================================
            switch(op){
                case 1:
                    do {
                        duplicado = 0;
                        printf("Nova Descricao: ");
                    fgets(p.descricao, sizeof(p.descricao), stdin);
                    strtok(p.descricao, "\n");

                        // Verifica duplica��o no arquivo
                        FILE *check_file = fopen("pecas.txt","r");
                        if (!check_file) {
                            return -2;
                        }

                            int temp_cod;
                            char temp_desc[50];
                            while (fscanf(check_file, "%d,%49[^,],%*[^,],%*[^,],%*f,%*f,%*d,%*d\n",
                                            &temp_cod, temp_desc) == 2) {
                                if (strcmp(temp_desc, p.descricao) == 0 && temp_cod != p.codigo) {//verifica se pe�a tem descri��o repetida e codigo diferente
                                    int x = copy_element();
                                    if (x == 1) {
                                        fclose(check_file);
                                        return 2;  // Usu�rio optou por sair
                                    }
                                    duplicado = 1;  // Marca como duplicado
                                    break;
                                }
                            }
                        fclose(check_file);  // Fecha o arquivo ap�s a verifica��o
                    } while (duplicado);
                break;
//============================================================================================
                case 2:
                    printf("Novo Fabricante: ");
                    fgets(p.fabricante, sizeof(p.fabricante), stdin);
                    strtok(p.fabricante, "\n");
                break;
//============================================================================================
                case 3:
                    printf("Novo Fornecedor: ");
                    fgets(p.fornecedor, sizeof(p.fornecedor), stdin);
                    strtok(p.fornecedor, "\n");
                break;
//============================================================================================
                case 4:
                    printf("Novo preco de custo: ");
                    scanf("%f",&p.p_custo);
                    getchar();
                break;
//============================================================================================
                case 5:
                    printf("Novo preco de venda: ");
                    scanf("%f",&p.p_venda);
                    getchar();
                break;
//============================================================================================
                case 6:
                    printf("Nova quantidade de estoque: ");
                    scanf("%d",&p.qntd_estoque);
                    getchar();
                break;
//============================================================================================
                case 7:
                    printf("Nova quantidade minima: ");
                    scanf("%d",&p.qntd_minima);
                    getchar();
                break;
//============================================================================================
                default:
                    return -3;
            }
            x=repeat();
            }while(x==1);
            }

            // Salva no arquivo tempor�rio (alterado ou n�o)
            fprintf(temp_file, "%d,%s,%s,%s,%.2f,%.2f,%d,%d\n", p.codigo, p.descricao, p.fabricante, p.fornecedor,
                      p.p_custo, p.p_venda, p.qntd_estoque, p.qntd_minima);
        }
    } else {  // Bin�rio
        PECA p;
        while (fread(&p, sizeof(PECA), 1, peca_file) == 1) {
            if (p.codigo==cod_busca) {
                encontrado = 1;  // Marca que o registro foi encontrado
                print_pecas(p);
            do{
            printf("O que deseja alterar?\n");
            printf("|1-Descricao 2-Fabricante 3-Fornecedor 4-Preco de custo 5-Preco de venda 6-Quantidade em estoque 7-Quantidade minima|\n");
            scanf("%d",&op);
            getchar();
//============================================================================================
            switch(op){
                case 1:
                    do {
                    printf("Nova Descricao: ");
                    fgets(p.descricao, sizeof(p.descricao), stdin);
                    strtok(p.descricao, "\n");

                        duplicado = 0;

                        FILE *check_file = fopen("pecas.bin","rb");
                        if (!check_file) {
                            return -2;
                        }
                            PECA temp;
                            while (fread(&temp, sizeof(PECA), 1, check_file) == 1) {
                                if (strcmp(temp.descricao, p.descricao) == 0 && temp.codigo != p.codigo) {
                                     int x = copy_element();
                                    if (x == 1) {
                                        fclose(check_file);
                                        return 2;  // Usu�rio optou por sair
                                    }
                                    duplicado = 1;
                                    break;
                                }
                            }
                    fclose(check_file);
                } while (duplicado);
                break;
//============================================================================================
                case 2:
                    printf("Novo Fabricante: ");
                    fgets(p.fabricante, sizeof(p.fabricante), stdin);
                    strtok(p.fabricante, "\n");
                break;
//============================================================================================
                case 3:
                    printf("Novo Fornecedor: ");
                    fgets(p.fornecedor, sizeof(p.fornecedor), stdin);
                    strtok(p.fornecedor, "\n");
                break;
//============================================================================================
                case 4:
                    printf("Novo preco de custo: ");
                    scanf("%f",&p.p_custo);
                    getchar();
                break;
//============================================================================================
                case 5:
                    printf("Novo preco de venda: ");
                    scanf("%f",&p.p_venda);
                    getchar();
                break;
//============================================================================================
                case 6:
                    printf("Nova quantidade de estoque: ");
                    scanf("%d",&p.qntd_estoque);
                    getchar();
                break;
//============================================================================================
                case 7:
                    printf("Nova quantidade minima: ");
                    scanf("%d",&p.qntd_minima);
                    getchar();
                break;
//============================================================================================
                default:
                    return -3;
            }
            x=repeat();
            }while(x==1);
            }

            fwrite(&p, sizeof(PECA), 1, temp_file);
        }
    }

    fclose(peca_file);
    fclose(temp_file);

    if (encontrado) {
        if (remove(typedoc == 1 ? "pecas.txt" : "pecas.bin") != 0 ||
            rename(typedoc == 1 ? "temp.txt" : "temp.bin", typedoc == 1 ? "pecas.txt" : "pecas.bin") != 0) {
            return -4;
        } else {
            return 0;
        }
    } else {
        remove(typedoc == 1 ? "temp.txt" : "temp.bin");
        return 1;
    }
}

int alterar_fornecedor() {
    int encontrado = 0,op,x,duplicado=0;
    int cod_busca;

    printf("Digite o codigo do fornecedor que deseja alterar: ");
    scanf("%d",&cod_busca);
    getchar();  // Remove o '\n' do final da entrada

    // Abrir arquivo de entrada para leitura
    FILE *fornecedor_file = fopen(typedoc == 1 ? "fornecedor.txt" : "fornecedor.bin", typedoc == 1 ? "r" : "rb");
    if (!fornecedor_file) {
        return -2;
    }

    // Abrir arquivo tempor�rio para escrita
    FILE *temp_file = fopen(typedoc == 1 ? "temp.txt" : "temp.bin", typedoc == 1 ? "w" : "wb");
    if (!temp_file) {
        fclose(fornecedor_file);
        return -4;
    }

    if (typedoc == 1) {  // Texto
        FORNECEDOR f;
        while (fscanf(fornecedor_file, "%d,%49[^,],%49[^,],%19[^,],%19[^,],%99[^,],%19[^,],%49[^\n]\n",
                      &f.codigo, f.nome_fantasia, f.razao_social, f.inscricao_est, f.cnpj, f.endereco, f.telefone, f.email) == 8) {
            if (cod_busca==f.codigo) {  // Compara o codigo
                encontrado = 1;  // Marca que o registro foi encontrado
                print_fornecedor(f);
            do{
            printf("O que deseja alterar?\n");
            printf("|1-Nome Fantasia 2-Raz�o Social 3-Inscri��o estadual 4-CNPJ 5-Endere�o completo 6- Telefone 7-E-mail|\n");
            scanf("%d",&op);
            getchar();
//============================================================================================
            switch(op){
                case 1:
                    do {
                        duplicado = 0;
                        printf("Novo Nome Fantasia: ");
                        fgets(f.nome_fantasia, sizeof(f.nome_fantasia), stdin);
                        strtok(f.nome_fantasia, "\n");

                        // Verifica duplica��o no arquivo
                        FILE *check_file = fopen("fornecedor.txt","r");
                        if (!check_file) {
                            return -2;
                        }

                            int temp_codigo;
                            char temp_nome[50];
                            while (fscanf(check_file, "%d,%49[^,],%*[^,],%*[^,],%*[^,],%*[^,],%*[^,],%*[^\n]\n",
                                            &temp_codigo, temp_nome) == 2) {
                                if (strcmp(temp_nome, f.nome_fantasia) == 0 && temp_codigo != f.codigo) {//verifica se o codigo � repitido e possui codigo diferente de procura
                                   int x = copy_element();
                                    if (x == 1) {
                                        fclose(check_file);
                                        return 2;  // Usu�rio optou por sair
                                    }
                                    duplicado = 1;  // Marca como duplicado
                                    break;
                                }
                            }
                        fclose(check_file);  // Fecha o arquivo ap�s a verifica��o
                    } while (duplicado);
                break;
//============================================================================================
                case 2:
                    printf("Nova Raz�o Social: ");
                    fgets(f.razao_social, sizeof(f.razao_social), stdin);
                    strtok(f.razao_social, "\n");
                break;
//============================================================================================
                case 3:
                    do {
                        duplicado = 0;
                        printf("Nova Inscri��o estadual: ");
                        fgets(f.inscricao_est, sizeof(f.inscricao_est), stdin);
                        strtok(f.inscricao_est, "\n");

                        // Verifica duplica��o no arquivo
                        FILE *check_file = fopen("fornecedor.txt","r");
                        if (!check_file) {
                            return -2;
                        }

                            int temp_codigo;
                            char temp_insc[20];
                            while (fscanf(check_file, "%d,%*[^,],%*[^,],%19[^,],%*[^,],%*[^,],%*[^,],%*[^\n]\n",
                                            &temp_codigo, temp_insc) == 2) {
                                if (strcmp(temp_insc, f.nome_fantasia) == 0 && temp_codigo != f.codigo) {//verifica se o codigo � repitido e possui codigo diferente de procura
                                    int x = copy_element();
                                    if (x == 1) {
                                        fclose(check_file);
                                        return 2;  // Usu�rio optou por sair
                                    }
                                    duplicado = 1;  // Marca como duplicado
                                    break;
                                }
                            }
                        fclose(check_file);  // Fecha o arquivo ap�s a verifica��o
                    } while (duplicado);

                break;
//============================================================================================
                case 4:
                    do {
                        duplicado = 0;
                        printf("Novo CNPJ: ");
                    fgets(f.cnpj, sizeof(f.cnpj), stdin);
                    strtok(f.cnpj, "\n");

                        // Verifica duplica��o no arquivo
                        FILE *check_file = fopen("fornecedor.txt","r");
                        if (!check_file) {
                            return -2;;
                        }

                            int temp_codigo;
                            char temp_cnpj[20];
                            while (fscanf(check_file, "%d,%*[^,],%*[^,],%*[^,],%19[^,],%*[^,],%*[^,],%*[^\n]\n",
                                            &temp_codigo, temp_cnpj) == 2) {
                                if (strcmp(temp_cnpj, f.cnpj) == 0 && temp_codigo != f.codigo) {//verifica se o codigo � repitido e possui codigo diferente de procura
                                    int x = copy_element();
                                    if (x == 1) {
                                        fclose(check_file);
                                        return 2;  // Usu�rio optou por sair
                                    }
                                    duplicado = 1;  // Marca como duplicado
                                    break;
                                }
                            }
                        fclose(check_file);  // Fecha o arquivo ap�s a verifica��o
                    } while (duplicado);

                break;
//============================================================================================
                case 5:
                    printf("Novo endereco: ");
                    fgets(f.endereco, sizeof(f.endereco), stdin);
                    strtok(f.endereco, "\n");
                    break;
//============================================================================================
                case 6:
                    printf("Novo Telefone: ");
                    fgets(f.telefone, sizeof(f.telefone), stdin);
                    strtok(f.telefone, "\n");
                    break;
//============================================================================================
                case 7:
                    printf("Novo E-mail: ");
                    fgets(f.email, sizeof(f.email), stdin);
                    strtok(f.email, "\n");
                break;
//============================================================================================
                default:
                    return -3;
            }
            x=repeat();
            }while(x==1);
            }

            // Salva no arquivo tempor�rio (alterado ou n�o)
            fprintf(temp_file, "%d,%s,%s,%s,%s,%s,%s,%s\n",f.codigo,f.nome_fantasia,f.razao_social,f.inscricao_est,f.cnpj,f.endereco,f.telefone,f.email);
        }
    } else {  // Bin�rio
        FORNECEDOR f;
        while (fread(&f, sizeof(FORNECEDOR), 1, fornecedor_file) == 1) {
            if (f.codigo==cod_busca) {
                encontrado = 1;  // Marca que o registro foi encontrado
                print_fornecedor(f);
                do{
                printf("O que deseja alterar?\n");
            printf("|1-Nome Fantasia 2-Raz�o Social 3-Inscri��o estadual 4-CNPJ 5-Endere�o completo 6- Telefone 7-E-mail|\n");
            scanf("%d",&op);
            getchar();
//============================================================================================
             switch(op){
                case 1:
                    do {
                        duplicado = 0;
                        printf("Novo Nome Fantasia: ");
                    fgets(f.nome_fantasia, sizeof(f.nome_fantasia), stdin);
                    strtok(f.nome_fantasia, "\n");

                        FILE *check_file = fopen("fornecedor.bin","rb");
                        if (!check_file) {
                           return -2;
                        }
                            FORNECEDOR temp;
                            while (fread(&temp, sizeof(FORNECEDOR), 1, check_file) == 1) {
                                if (strcmp(temp.nome_fantasia, f.nome_fantasia) == 0 && temp.codigo != f.codigo) {
                                    int x = copy_element();
                                    if (x == 1) {
                                        fclose(check_file);
                                        return 2;  // Usu�rio optou por sair
                                    }
                                    duplicado = 1;
                                    break;
                                }
                            }
                    fclose(check_file);
                } while (duplicado);
                break;
//============================================================================================
                case 2:
                    printf("Nova Raz�o Social: ");
                    fgets(f.razao_social, sizeof(f.razao_social), stdin);
                    strtok(f.razao_social, "\n");
                break;
//============================================================================================
                case 3:
                    do {
                        duplicado = 0;
                    printf("Nova Inscri��o estadual: ");
                    fgets(f.inscricao_est, sizeof(f.inscricao_est), stdin);
                    strtok(f.inscricao_est, "\n");

                        FILE *check_file = fopen("fornecedor.bin","rb");
                        if (!check_file) {
                            return -2;;
                        }
                            FORNECEDOR temp;
                            while (fread(&temp, sizeof(FORNECEDOR), 1, check_file) == 1) {
                                if (strcmp(temp.inscricao_est, f.inscricao_est) == 0 && temp.codigo != f.codigo) {
                                    int x = copy_element();
                                    if (x == 1) {
                                        fclose(check_file);
                                        return 2;  // Usu�rio optou por sair
                                    }
                                    duplicado = 1;
                                    break;
                                }
                            }
                    fclose(check_file);
                } while (duplicado);
                break;
//============================================================================================
                case 4:
                    do {
                        duplicado = 0;
                    printf("Novo CNPJ: ");
                    fgets(f.cnpj, sizeof(f.cnpj), stdin);
                    strtok(f.cnpj, "\n");

                        FILE *check_file = fopen("fornecedor.bin","rb");
                        if (!check_file) {
                            return -2;
                        }
                            FORNECEDOR temp;
                            while (fread(&temp, sizeof(FORNECEDOR), 1, check_file) == 1) {
                                if (strcmp(temp.cnpj, f.cnpj) == 0 && temp.codigo != f.codigo) {
                                    int x = copy_element();
                                    if (x == 1) {
                                        fclose(check_file);
                                        return 2;  // Usu�rio optou por sair
                                    }
                                    duplicado = 1;
                                    break;
                                }
                            }
                    fclose(check_file);
                } while (duplicado);
                break;
//============================================================================================
                case 5:
                    printf("Novo endereco: ");
                    fgets(f.endereco, sizeof(f.endereco), stdin);
                    strtok(f.endereco, "\n");
                    break;
//============================================================================================
                case 6:
                    printf("Novo Telefone: ");
                    fgets(f.telefone, sizeof(f.telefone), stdin);
                    strtok(f.telefone, "\n");
                    break;
//============================================================================================
                case 7:
                    printf("Novo E-mail: ");
                    fgets(f.email, sizeof(f.email), stdin);
                    strtok(f.email, "\n");
                break;
//============================================================================================
                default:
                    return -3;
            }
            x=repeat();
            }while(x==1);
            }

            fwrite(&f, sizeof(FORNECEDOR), 1, temp_file);
        }
    }

    fclose(fornecedor_file);
    fclose(temp_file);

    if (encontrado) {
        if (remove(typedoc == 1 ? "fornecedor.txt" : "fornecedor.bin") != 0 ||
            rename(typedoc == 1 ? "temp.txt" : "temp.bin", typedoc == 1 ? "fornecedor.txt" : "fornecedor.bin") != 0) {
            return -4;
        } else {
           return 0;
        }
    } else {
        remove(typedoc == 1 ? "temp.txt" : "temp.bin");
        return 1;
}
}

int alterar_servico() {

    int encontrado = 0,op,x,duplicado=0;  // Vari�vel para verificar se o registro foi encontrado
    int cod_busca;

    printf("Digite o codigo do servi�o que deseja alterar: ");
    scanf("%d",&cod_busca);
    getchar();  // Remove o '\n' do final da entrada

    // Abrir arquivo de entrada para leitura
    FILE *servico_file = fopen(typedoc == 1 ? "servico.txt" : "servico.bin", typedoc == 1 ? "r" : "rb");
    if (!servico_file) {
        return -2;
    }

    // Abrir arquivo tempor�rio para escrita
    FILE *temp_file = fopen(typedoc == 1 ? "temp.txt" : "temp.bin", typedoc == 1 ? "w" : "wb");
    if (!temp_file) {
        fclose(servico_file);
        return -4;
    }

    if (typedoc == 1) {  // Texto
       SERVICO s;

        while (fscanf(servico_file, "%d,%49[^,],%f,%f\n",//leitura minimizada para evitar overflow do buffer
                      &s.codigo, s.descricao, &s.preco, &s.comissao) == 4) {
            if (cod_busca==s.codigo) {  // Compara o codigo
                encontrado = 1;  // Marca que o registro foi encontrado
                print_servico(s);
            do{
            printf("O que deseja alterar?\n");
            printf("|1-Descricao 2-Preco 3-Comissao |\n");
            scanf("%d",&op);
            getchar();
//============================================================================================
            switch(op){
                case 1:
                    do {
                        duplicado = 0;
                        printf("Nova Descricao: ");
                        fgets(s.descricao, sizeof(s.descricao), stdin);
                        strtok(s.descricao, "\n");
                        // Verifica duplica��o no arquivo
                        FILE *check_file = fopen("servico.txt","r");
                        if (!check_file) {
                            return -2;
                        }
                            int temp_cod;
                            char temp_desc[50];
                            while (fscanf(check_file, "%d,%49[^,],%*f,%*f\n",
                                            &temp_cod, temp_desc) == 2) {
                                if (strcmp(temp_desc, s.descricao) == 0 && temp_cod != s.codigo) {//verifica se pe�a tem descri��o repetida e codigo diferente
                                    int x = copy_element();
                                    if (x == 1) {
                                        fclose(check_file);
                                        return 2;  // Usu�rio optou por sair
                                    }
                                    duplicado = 1;  // Marca como duplicado
                                    break;
                                }
                            }
                        fclose(check_file);  // Fecha o arquivo ap�s a verifica��o
                    } while (duplicado);

                break;
//============================================================================================
                case 2:
                    printf("Novo preco: ");
                    scanf("%f",&s.preco);
                    getchar();
                break;
//============================================================================================
                case 3:
                    printf("Nova Comissao: ");
                    scanf("%f",&s.comissao);
                    getchar();
                break;
//============================================================================================
                default:
                    return -3;
            }
            x=repeat();
            }while(x==1);
            }

            // Salva no arquivo tempor�rio (alterado ou n�o)
            fprintf(temp_file, "%d,%s,%.2f,%.2f\n",s.codigo,s.descricao,s.preco,s.comissao);
        }
    } else {  // Bin�rio
        SERVICO s;
        while (fread(&s, sizeof(SERVICO), 1, servico_file) == 1) {
            if (s.codigo==cod_busca) {
                encontrado = 1;  // Marca que o registro foi encontrado
                print_servico(s);
            do{
            printf("O que deseja alterar?\n");
            printf("|1-Descricao 2-Preco 3-Comissao |\n");
            scanf("%d",&op);
            getchar();
//============================================================================================
            switch(op){
                case 1:
                    do {
                    printf("Nova Descricao: ");
                    fgets(s.descricao, sizeof(s.descricao), stdin);
                    strtok(s.descricao, "\n");

                        duplicado = 0;

                        FILE *check_file = fopen("servico.bin","rb");
                        if (!check_file) {
                            return -2;
                        }
                            SERVICO temp;
                            while (fread(&temp, sizeof(SERVICO), 1, check_file) == 1) {
                                if (strcmp(temp.descricao, s.descricao) == 0 && temp.codigo != s.codigo) {
                                    int x = copy_element();
                                    if (x == 1) {
                                        fclose(check_file);
                                        return 2;  // Usu�rio optou por sair
                                    }
                                    duplicado = 1;
                                    break;
                                }
                            }
                    fclose(check_file);
                } while (duplicado);
                break;
//============================================================================================
                case 2:
                    printf("Novo Preco: ");
                    scanf("%f",&s.preco);
                    getchar();
                break;
//============================================================================================
                case 3:
                    printf("Nova Comissao: ");
                    scanf("%f",&s.comissao);
                    getchar();
                break;
//============================================================================================
                default:
                    return -3;
            }
            printf("Outra alteracao? 1-Sim 2-Nao\n");
            scanf("%d",&x);
            }while(x==1);
                printf("Alteracao feita.\n");
            }

            fwrite(&s, sizeof(SERVICO), 1, temp_file);
        }
    }

    fclose(servico_file);
    fclose(temp_file);

    if (encontrado) {
        if (remove(typedoc == 1 ? "servico.txt" : "servico.bin") != 0 ||
            rename(typedoc == 1 ? "temp.txt" : "temp.bin", typedoc == 1 ? "servico.txt" : "servico.bin") != 0) {
            return -4;
        } else {
           return 0;
        }
    } else {
        remove(typedoc == 1 ? "temp.txt" : "temp.bin");
        return 1;
    }
}

int alterar_funcionario() {
    int encontrado = 0, op, x, duplicado;  // Vari�veis de controle
    char cpf_busca[15];                   // CPF a ser buscado

    printf("Digite o CPF do funcion�rio que deseja alterar: ");
    fgets(cpf_busca, sizeof(cpf_busca), stdin);
    strtok(cpf_busca, "\n");  // Remove o '\n' do final da entrada

    // Abrir arquivo de entrada para leitura
    FILE *funcionario_file = fopen(typedoc == 1 ? "funcionario.txt" : "funcionario.bin", typedoc == 1 ? "r" : "rb");
    if (!funcionario_file) {
        return -2;
    }

    // Abrir arquivo tempor�rio para escrita
    FILE *temp_file = fopen(typedoc == 1 ? "temp.txt" : "temp.bin", typedoc == 1 ? "w" : "wb");
    if (!temp_file) {
        fclose(funcionario_file);
        return -4;
    }

    if (typedoc == 1) {  // Modo texto
        FUNCIONARIO f;

        while (fscanf(funcionario_file, "%49[^,],%14[^,],%49[^,],%f\n",
                      f.nome, f.cpf, f.cargo, &f.salario) == 4) {
            if (strcmp(f.cpf, cpf_busca) == 0) {  // Compara o CPF buscado
                encontrado = 1;  // Marca que o registro foi encontrado
                print_funcionario(f);

                do {
                    printf("O que deseja alterar?\n");
                    printf("|1-Nome 2-CPF 3-Cargo 4-Sal�rio |\n");
                    scanf("%d", &op);
                    getchar();
//============================================================================================
                    switch (op) {
                        case 1:
                                printf("Novo Nome: ");
                                fgets(f.nome, sizeof(f.nome), stdin);
                                strtok(f.nome, "\n");
//============================================================================================
                        case 2:
                            do {
                                duplicado = 0;
                                printf("Novo CPF: ");
                                fgets(f.cpf, sizeof(f.cpf), stdin);
                                strtok(f.cpf, "\n");

                                FILE *check_file = fopen("funcionario.txt", "r");
                                if (!check_file) {
                                    return -2;
                                }

                                char temp_cpf[15];
                                while (fscanf(check_file, "%*[^,],%14[^,],%*[^,],%*f\n", temp_cpf) == 1) {
                                    if (strcmp(temp_cpf, f.cpf) == 0 && strcmp(temp_cpf, cpf_busca) != 0) {
                                         int x = copy_element();
                                    if (x == 1) {
                                        fclose(check_file);
                                        return 2;  // Usu�rio optou por sair
                                    }
                                        duplicado = 1;
                                        break;
                                    }
                                }
                                fclose(check_file);
                            } while (duplicado);
                            break;
//============================================================================================
                        case 3:
                            printf("Novo Cargo: ");
                            fgets(f.cargo, sizeof(f.cargo), stdin);
                            strtok(f.cargo, "\n");
                            break;
//============================================================================================
                        case 4:
                            printf("Novo Sal�rio: ");
                            scanf("%f", &f.salario);
                            getchar();
                            break;
//============================================================================================
                        default:
                            return -3;
                    }

                    printf("Outra altera��o? 1-Sim 2-N�o\n");
                    scanf("%d", &x);
                    getchar();
                } while (x == 1);
            }

            // Salva no arquivo tempor�rio (alterado ou n�o)
            fprintf(temp_file, "%s,%s,%s,%.2f\n", f.nome, f.cpf, f.cargo, f.salario);
        }
    } else {  // Modo bin�rio
        FUNCIONARIO f;

        while (fread(&f, sizeof(FUNCIONARIO), 1, funcionario_file) == 1) {
            if (strcmp(f.cpf, cpf_busca) == 0) {  // Compara o CPF buscado
                encontrado = 1;  // Marca que o registro foi encontrado
                printf("=============================================================\n");
                printf("Nome: %s\nCPF: %s\nCargo: %s\nSal�rio: %.2f\n",
                       f.nome, f.cpf, f.cargo, f.salario);
                printf("=============================================================\n");

                do {
                    printf("O que deseja alterar?\n");
                    printf("|1-Nome 2-CPF 3-Cargo 4-Sal�rio |\n");
                    scanf("%d", &op);
                    getchar();
//============================================================================================
                    switch (op) {
                        case 1:
                            do {
                                duplicado = 0;
                                printf("Novo Nome: ");
                                fgets(f.nome, sizeof(f.nome), stdin);
                                strtok(f.nome, "\n");

                                FILE *check_file = fopen("funcionario.bin", "rb");
                                if (!check_file) {
                                    return -2;;
                                }
                                FUNCIONARIO temp;
                                while (fread(&temp, sizeof(FUNCIONARIO), 1, check_file) == 1) {
                                    if (strcmp(temp.nome, f.nome) == 0) {
                                        printf("Nome j� cadastrado. Digite novamente ou saia.\n");
                                         int x = copy_element();
                                    if (x == 1) {
                                        fclose(check_file);
                                        return 2;  // Usu�rio optou por sair
                                    }
                                        duplicado = 1;
                                        break;
                                    }
                                }
                                fclose(check_file);
                            } while (duplicado);
                            break;
//============================================================================================
                        case 2:
                            do {
                                duplicado = 0;
                                printf("Novo CPF: ");
                                fgets(f.cpf, sizeof(f.cpf), stdin);
                                strtok(f.cpf, "\n");

                                FILE *check_file = fopen("funcionario.bin", "rb");
                                if (!check_file) {
                                    return -2;
                                }

                                FUNCIONARIO temp;
                                while (fread(&temp, sizeof(FUNCIONARIO), 1, check_file) == 1) {
                                    if (strcmp(temp.cpf, f.cpf) == 0 && strcmp(temp.cpf, cpf_busca) != 0) {
                                        printf("CPF j� cadastrado. Digite novamente ou saia.\n");
                                        printf("Deseja sair? 1-Sim 2-N�o\n");
                                    scanf("%d",&x);
                                    getchar();
                                    if(x==1){
                                        return;
                                    }
                                        duplicado = 1;
                                        break;
                                    }
                                }
                                fclose(check_file);
                            } while (duplicado);
                            break;
//============================================================================================
                        case 3:
                            printf("Novo Cargo: ");
                            fgets(f.cargo, sizeof(f.cargo), stdin);
                            strtok(f.cargo, "\n");
                            break;
//============================================================================================
                        case 4:
                            printf("Novo Sal�rio: ");
                            scanf("%f", &f.salario);
                            getchar();
                            break;
//============================================================================================
                        default:
                            return -3;
                    }

                    printf("Outra altera��o? 1-Sim 2-N�o\n");
                    scanf("%d", &x);
                    getchar();
                } while (x == 1);
            }

            fwrite(&f, sizeof(FUNCIONARIO), 1, temp_file);
        }
    }

    fclose(funcionario_file);
    fclose(temp_file);

    if (encontrado) {
        if (remove(typedoc == 1 ? "funcionario.txt" : "funcionario.bin") != 0 ||
            rename(typedoc == 1 ? "temp.txt" : "temp.bin", typedoc == 1 ? "funcionario.txt" : "funcionario.bin") != 0) {
            return -4;
        } else {
            return 0;
        }
    } else {
        remove(typedoc == 1 ? "temp.txt" : "temp.bin");
        return 1;
    }
}

// Entrada da nota fiscal
int entrada_nota_fiscal() {
    char cnpj[20],fornecedor[50];
    float frete_total, imposto_total,margem_lucro,lucrotot,p_venda;
    int num_produtos,found,x,totquant;

    // Coleta de dados iniciais
    do {
    found = 0;
    printf("CNPJ da Oficina: ");
    fgets(cnpj, sizeof(cnpj), stdin);
    strtok(cnpj, "\n");
    // Abre o arquivo de fornecedores para verificar
    FILE *check_file = fopen(typedoc == 1 ? "oficina.txt" : "oficina.bin", typedoc == 1 ? "r" : "rb");
    if (!check_file) {
        return -2;  // Encerra a fun��o em caso de falha
    }

    if (typedoc == 1) {  // Modo texto
        char analy[20];
        float ml;  // Buffer para armazenar o nome do fornecedor
        while (fscanf(check_file, "%*[^,],%19[^,],%*[^,],%*[^,],%*[^,],%f\n", analy,&ml) == 2) {
            if (strcmp(analy, cnpj) == 0) {  // Fornecedor encontrado
                found = 1;  // Marca como duplicado
                ml = margem_lucro;
                break;
            }
        }
    } else {  // Modo bin�rio
        OFICINA temp;  // Estrutura tempor�ria para o fornecedor
        while (fread(&temp, sizeof(OFICINA), 1, check_file) == 1) {
            if (strcmp(temp.cpf, cnpj) == 0) {  // Fornecedor encontrado
                found = 1;  // Marca como duplicado
                break;
            }
        }
    }
    fclose(check_file);  // Fecha o arquivo ap�s a verifica��o

        if (!found) {  // Se n�o encontrou o fornecedor
            x = not_found();
                if(x==1){
                return 2;
                }
        }
} while (!found);

    do {
    found = 0;
    printf("Nome do Fornecedor: ");
    fgets(fornecedor, sizeof(fornecedor), stdin);
    strtok(fornecedor, "\n");
    // Abre o arquivo de fornecedores para verificar
    FILE *check_file = fopen(typedoc == 1 ? "fornecedor.txt" : "fornecedor.bin", typedoc == 1 ? "r" : "rb");
    if (!check_file) {
        return -2;  // Encerra a fun��o em caso de falha
    }

    if (typedoc == 1) {  // Modo texto
        char analy[50];  // Buffer para armazenar o nome do fornecedor
        while (fscanf(check_file, "%*d,%49[^,],%*[^,],%*[^,],%*[^,],%*[^,],%*[^,],%*[^\n]\n", analy) == 1) {
            if (strcmp(analy,fornecedor)==0) {  // Fornecedor encontrado
                found = 1;  // Marca como duplicado
                break;
            }
        }
    } else {  // Modo bin�rio
        FORNECEDOR temp;  // Estrutura tempor�ria para o fornecedor
        while (fread(&temp, sizeof(OFICINA), 1, check_file) == 1) {
            if (temp.codigo==fornecedor) {  // Fornecedor encontrado
                found = 1;  // Marca como duplicado
                break;
            }
        }
    }
    fclose(check_file);  // Fecha o arquivo ap�s a verifica��o

        if (!found) {  // Se n�o encontrou o fornecedor
            x = not_found();
                if(x==1){
                return 2;
                }
        }
} while (!found);

    printf("Frete total: ");
    scanf("%f", &frete_total);
    getchar();

    printf("Imposto total: ");
    scanf("%f", &imposto_total);
    getchar();

    printf("Quantidade de produtos na nota fiscal: ");
    scanf("%d", &num_produtos);
    getchar();

    //processando produtos

    FILE *fiscal_file=fopen(typedoc == 1 ? "fiscal.txt" : "fiscal.bin",typedoc == 1 ? "w" : "wb");
    if(!fiscal_file) return -2;

    // Aloca��o para armazenar as pe�as da nota fiscal
    char descricao[50];
    float preco_custo;
    int quantidade;

    // Processar cada pe�a da nota fiscal
    for (int i = 0; i < num_produtos; i++) {
        printf("\n--- Produto %d ---\n", i + 1);

        do {
    found = 0;
    printf("Descri��o: ");
        fgets(descricao, sizeof(descricao), stdin);
        strtok(descricao, "\n");
    //valida��o de descri��o
    FILE *check_file = fopen(typedoc == 1 ? "pecas.txt" : "pecas.bin", typedoc == 1 ? "r" : "rb");
    if (!check_file) {
        return -2;  // Encerra a fun��o em caso de falha
    }

    if (typedoc == 1) {  // Modo texto
        char analy[50];
        float p_c;  //pre�o de custo
        while (fscanf(check_file, "%*d,%49[^,],%*[^,],%*[^,],%f,%*f,%*d,%*d", analy,&p_c) == 2) {
            if (strcmp(analy,descricao) == 0) {  // Fornecedor encontrado
                found = 1;  // Marca como duplicado
                preco_custo = p_c;
                break;
            }
        }
    } else {  // Modo bin�rio
        PECA temp;  // Estrutura tempor�ria para o fornecedor
        while (fread(&temp, sizeof(PECA), 1, check_file) == 1) {
            if (strcmp(temp.descricao,descricao) == 0) {  // Fornecedor encontrado
                found = 1;  // Marca como duplicado
                preco_custo == temp.p_custo;
                break;
            }
        }
    }
    fclose(check_file);  // Fecha o arquivo ap�s a verifica��o

        if (!found) {  // Se n�o encontrou o fornecedor
            x = not_found();
                if(x==1){
                return 2;
                }
        }
} while (!found);


        printf("Quantidade: ");
        scanf("%d", &quantidade);
        getchar();

        totquant += quantidade;

        // Calcular pre�o de venda
        float fpp = frete_total / totquant;
        float ipp = imposto_total / totquant;
        p_venda = preco_custo + fpp + ipp + ((preco_custo + fpp + ipp) * (margem_lucro / 100));

        // Escrever no arquivo fiscal
        if (typedoc == 1) {
            fprintf(fiscal_file, "%s,%d,%.2f\n", descricao, quantidade, p_venda);
        } else {
            PECA nova_peca = {descricao, preco_custo, quantidade, p_venda};
            fwrite(&nova_peca, sizeof(PECA), 1, fiscal_file);
        }
    }

    fclose(fiscal_file);
    return 0;
}

int apply_fiscal() {
    char descricao[50];
    int qntd;
    float p_v;

    // Abrir arquivos fiscal e pe�as
    FILE *fiscal_file = fopen(typedoc == 1 ? "fiscal.txt" : "fiscal.bin", typedoc == 1 ? "r" : "rb");
    if (!fiscal_file) {
        return -2;
    }

    FILE *pecas_file = fopen(typedoc == 1 ? "pecas.txt" : "pecas.bin", typedoc == 1 ? "r" : "rb");
    if (!pecas_file) {
        fclose(fiscal_file);
        return -2;
    }

    FILE *temp_file = fopen(typedoc == 1 ? "temp.txt" : "temp.bin", typedoc == 1 ? "w" : "wb");
    if (!temp_file) {
        fclose(fiscal_file);
        fclose(pecas_file);
        return -2;
    }

    if (typedoc == 1) {  // Modo texto
        char linha[256];
        while (fgets(linha, sizeof(linha), pecas_file)) {
            PECA p;
            if (sscanf(linha, "%d,%49[^,],%29[^,],%29[^,],%f,%f,%d,%d",
                       &p.codigo, p.descricao, p.fabricante, p.fornecedor,
                       &p.p_custo, &p.p_venda, &p.qntd_estoque, &p.qntd_minima) == 8) {

                int updated = 0;

                // Reprocessar o arquivo fiscal para encontrar correspond�ncias
                FILE *fiscal_temp = fopen(typedoc == 1 ? "fiscal.txt" : "fiscal.bin", typedoc == 1 ? "r" : "rb");
                if (!fiscal_temp) {;
                    fclose(temp_file);
                    fclose(fiscal_file);
                    fclose(pecas_file);
                    return -2;
                }

                char fiscal_line[256];
                while (fgets(fiscal_line, sizeof(fiscal_line), fiscal_temp)) {
                    char fiscal_desc[50];
                    int fiscal_qntd;
                    float fiscal_p_v;

                    if (sscanf(fiscal_line, "%49[^,],%d,%f", fiscal_desc, &fiscal_qntd, &fiscal_p_v) == 3) {
                        if (strcmp(p.descricao, fiscal_desc) == 0) {
                            // Atualizar os valores
                            p.qntd_estoque += fiscal_qntd;
                            p.p_venda = fiscal_p_v;
                            updated = 1;
                            break;
                        }
                    }
                }

                fclose(fiscal_temp);

                // Escrever no arquivo tempor�rio
                fprintf(temp_file, "%d,%s,%s,%s,%.2f,%.2f,%d,%d\n",
                        p.codigo, p.descricao, p.fabricante, p.fornecedor,
                        p.p_custo, p.p_venda, p.qntd_estoque, p.qntd_minima);
            }
        }
    } else {  // Modo bin�rio
        PECA temp;
        while (fread(&temp, sizeof(PECA), 1, pecas_file) == 1) {
            FILE *fiscal_temp = fopen(typedoc == 1 ? "fiscal.txt" : "fiscal.bin", typedoc == 1 ? "r" : "rb");
            if (!fiscal_temp) {
                fclose(temp_file);
                fclose(fiscal_file);
                fclose(pecas_file);
                return -2;
            }

            PECA fiscal_data;
            while (fread(&fiscal_data, sizeof(PECA), 1, fiscal_temp) == 1) {
                if (strcmp(temp.descricao, fiscal_data.descricao) == 0) {
                    // Atualizar os valores
                    temp.qntd_estoque += fiscal_data.qntd_estoque;
                    temp.p_venda = fiscal_data.p_venda;
                }
            }

            fclose(fiscal_temp);

            // Escrever no arquivo tempor�rio
            fwrite(&temp, sizeof(PECA), 1, temp_file);
        }
    }

    // Fechar os arquivos
    fclose(fiscal_file);
    fclose(pecas_file);
    fclose(temp_file);

    // Substituir o arquivo original pelo tempor�rio
    if (remove(typedoc == 1 ? "pecas.txt" : "pecas.bin") != 0 ||
        rename(typedoc == 1 ? "temp.txt" : "temp.bin", typedoc == 1 ? "pecas.txt" : "pecas.bin") != 0) {
        return -4;
    }
    return 0;
}

// Financeiro

int registrar_transacao() {
    int x; // Dinheiro ou Cart�o
    float valor;
    char descricao[50];
    char data_vencimento[11];
    FILE *caixa_file, *contasr_file;

    printf("Digite o tipo de pagamento (1-dinheiro/2-cartao): ");
    scanf("%d",&x);
    getchar();

    CAIXA c;

    if (x == 1) {
    printf("Descri��o da transa��o: ");
    fgets(c.descricao, sizeof(c.descricao), stdin);
    strtok(c.descricao, "\n");

    printf("Data:(dd/mm/aaaa)\n");
    fgets(c.data, sizeof(c.descricao), stdin);
    strtok(c.descricao, "\n");

    printf("Valor da transa��o: ");
    scanf("%f", &c.saldo);
    getchar();


        caixa_file = fopen(typedoc == 1 ? "caixa.txt" : "caixa.bin", typedoc == 1 ? "a" : "ab");
        if (!caixa_file) return -2;

            if (typedoc == 1) {
        fprintf(caixa_file, "%.2f,%s,%s\n", c.saldo, c.descricao, c.data);
    } else {
        fwrite(&c,sizeof(CAIXA),1, caixa_file);
    }
        fclose(caixa_file);

    } else if (x == 2) {
        registrar_conta_receber();
    } else {
        return -3;//valor invalido
    }

    return 0;
}

int consultar_lancamentos() {
    FILE *caixa_file = fopen(typedoc == 1 ? "caixa.txt" : "caixa.bin", typedoc == 1 ? "r" : "rb");
    if (!caixa_file) return -2;

           if (typedoc == 1) {
                CAIXA c;
            while (fscanf(caixa_file, "%f,%49[^,],%14[^\n]\n", &c.saldo, c.descricao, c.data) == 3) {
                printf("Valor:%.2f\tDescri��o:%s\tData:%s\n", c.saldo, c.descricao, c.data);
            }
        } else {
            CAIXA transacao;
            while (fread(&transacao, sizeof(CAIXA), 1, caixa_file) == 1) {
                printf("%.2f\t%s\t%s\n", transacao.saldo, transacao.descricao, transacao.data);
            }
        }
    fclose(caixa_file);
    printf("\n");
    return 0;
}

int exibir_saldo_atual() {
    FILE *caixa_file = fopen(typedoc == 1 ? "caixa.txt" : "caixa.bin", typedoc == 1 ? "r" : "rb");
    if (!caixa_file) return -2;

    float saldo = 0, valor;

    if (typedoc == 1) {  // Modo texto
        while (fscanf(caixa_file, "%f,%*[^,],%*[^\n]\n", &valor) == 1) {
            saldo += valor;
        }
    } else {  // Modo bin�rio
        CAIXA transacao;
        while (fread(&transacao, sizeof(CAIXA), 1, caixa_file) == 1) {
            saldo += transacao.saldo;
        }
    }

    fclose(caixa_file);
    print_saldo(saldo);
    return 0;
}

//contas a receber

int registrar_conta_receber() {

    CONTASR c;

    printf("Descri��o: ");
    fgets(c.descricao, sizeof(c.descricao), stdin);
    strtok(c.descricao, "\n");

    printf("Data de vencimento (DD/MM/AAAA): ");
    fgets(c.data_vencimento, sizeof(c.data_vencimento), stdin);
    strtok(c.data_vencimento, "\n");

    printf("Valor da conta: ");
    scanf("%f", &c.valor);
    getchar();

    FILE *contasr_file = fopen(typedoc == 1 ? "recebimentos.txt" : "recebimentos.bin", typedoc == 1 ? "a" : "ab");
    if (!contasr_file) return -2;

    if (typedoc == 1) {
        fprintf(contasr_file, "%s,%.2f,%s,0\n", c.descricao, c.valor, c.data_vencimento);
    } else {
        CONTASR conta = {c.descricao, c.data_vencimento, c.valor, 0};
        fwrite(&conta, sizeof(CONTASR), 1, contasr_file);
    }
    fclose(contasr_file);

    return 0;
}

int consultar_contas_receber() {
    FILE *contasr_file = fopen(typedoc == 1 ? "recebimentos.txt" : "recebimentos.bin", typedoc == 1 ? "r" : "rb");
    if (!contasr_file) return -2;

    if (typedoc == 1) {//modo texto
        CONTASR c;

        while (fscanf(contasr_file, "%49[^,],%f,%10[^,],%d\n", c.descricao, &c.valor, c.data_vencimento, &c.status) == 4) {
            print_contasreceber(c);//printa na tela
        }
    } else {//modo bin�rio
        CONTASR conta;
        printf("Contas a Receber:\n");
        while (fread(&conta, sizeof(CONTASR), 1, contasr_file) == 1) {
            printf("%s\t%.2f\t%s\t%s\n", conta.descricao, conta.valor, conta.data_vencimento, conta.status ? "Pago" : "Pendente");
            print_contasreceber(conta);
        }
    }

    fclose(contasr_file);
    return 0;
}

int baixar_conta_receber() {
    char descricao[50];
    printf("Digite a descri��o da conta a ser baixada: ");
    fgets(descricao, sizeof(descricao), stdin);
    strtok(descricao, "\n");

    FILE *contasr_file = fopen(typedoc == 1 ? "recebimentos.txt" : "recebimentos.bin", typedoc == 1 ? "r" : "rb");
    FILE *temp_file = fopen(typedoc == 1 ? "temp.txt" : "temp.bin", typedoc == 1 ? "w" : "wb"); // Arquivo tempor�rio
    if (!contasr_file || !temp_file) return -2;

    int encontrado = 0;
    float valor_recebido = 0.0;
    char data[15] = "";

    if (typedoc == 1) {
        CONTASR c;

        while (fscanf(contasr_file, "%49[^,],%f,%14[^,],%d\n", c.descricao, &c.valor, c.data_vencimento, &c.status) == 4) {
            if (strcmp(c.descricao, descricao) == 0 && !c.status) {
                c.status = 1;
                encontrado = 1;
                valor_recebido = c.valor;
                strncpy(data, c.data_vencimento, sizeof(data));
            }
            fprintf(temp_file, "%s,%.2f,%s,%d\n", c.descricao, c.valor, c.data_vencimento, c.status);
        }
    } else {
        CONTASR conta;
        while (fread(&conta, sizeof(CONTASR), 1, contasr_file) == 1) {
            if (strcmp(conta.descricao, descricao) == 0 && !conta.status) {
                conta.status = 1;
                encontrado = 1;
                valor_recebido = conta.valor;
                strncpy(data, conta.data_vencimento, sizeof(data));
            }
            fwrite(&conta, sizeof(CONTASR), 1, temp_file);
        }
    }

    fclose(contasr_file);
    fclose(temp_file);

    remove(typedoc == 1 ? "recebimentos.txt" : "recebimentos.bin");
    rename(typedoc == 1 ? "temp.txt" : "temp.bin", typedoc == 1 ? "recebimentos.txt" : "recebimentos.bin");

    if (encontrado) {
        // Adicionar a transa��o ao caixa
        FILE *caixa_file = fopen(typedoc == 1 ? "caixa.txt" : "caixa.bin", typedoc == 1 ? "a" : "ab");
        if (!caixa_file) return -2;

        if (typedoc == 1) {
            fprintf(caixa_file, "%.2f,%s,%s\n", valor_recebido, descricao, data);
        } else {
            CAIXA transacao;
            transacao.saldo = valor_recebido;
            strncpy(transacao.descricao, descricao, sizeof(transacao.descricao));
            strncpy(transacao.data, data, sizeof(transacao.data));
            fwrite(&transacao, sizeof(CAIXA), 1, caixa_file);
        }

        fclose(caixa_file);
        return 0;
    } else {
        return 1;
    }
}


int registrar_conta_pagar() {
    char descricao[50], data_vencimento[11];
    float valor;

    printf("Descri��o da conta: ");
    fgets(descricao, sizeof(descricao), stdin);
    strtok(descricao, "\n");

    printf("Data de vencimento (DD/MM/AAAA): ");
    fgets(data_vencimento, sizeof(data_vencimento), stdin);
    strtok(data_vencimento, "\n");

    printf("Valor da conta: ");
    scanf("%f", &valor);
    getchar();

    FILE *contasp_file = fopen(typedoc == 1 ? "pagamentos.txt" : "pagamentos.bin", typedoc == 1 ? "a" : "ab");
    if (!contasp_file) return -2;

    if (typedoc == 1) {
        fprintf(contasp_file, "%s,%.2f,%s,0\n", descricao, valor, data_vencimento);
    } else {
        CONTASP conta = {0};
        strcpy(conta.descricao, descricao);
        strcpy(conta.data_vencimento, data_vencimento);
        conta.valor = valor;
        conta.status = 0; // Inicialmente pendente
        fwrite(&conta, sizeof(CONTASP), 1, contasp_file);
    }

    fclose(contasp_file);
    return 0;
}

int consultar_contas_pagar() {
    FILE *contasp_file = fopen(typedoc == 1 ? "pagamentos.txt" : "pagamentos.bin", typedoc == 1 ? "r" : "rb");
    if (!contasp_file) return -2;

    printf("Contas a Pagar:\n");
    printf("Descri��o\tValor\tVencimento\tStatus\n");

    if (typedoc == 1) {
        char descricao[50], data_vencimento[11];
        float valor;
        int status;

        while (fscanf(contasp_file, "%49[^,],%f,%10[^,],%d\n", descricao, &valor, data_vencimento, &status) == 4) {
            printf("%s\t%.2f\t%s\t%s\n", descricao, valor, data_vencimento, status ? "Paga" : "Pendente");
        }
    } else {
        CONTASP conta;
        while (fread(&conta, sizeof(CONTASP), 1, contasp_file) == 1) {
            printf("%s\t%.2f\t%s\t%s\n", conta.descricao, conta.valor, conta.data_vencimento, conta.status ? "Paga" : "Pendente");
        }
    }

    fclose(contasp_file);
    return 0;
}

int baixar_conta_pagar() {
    char descricao[50];
    printf("Digite a descri��o da conta a ser baixada: ");
    fgets(descricao, sizeof(descricao), stdin);
    strtok(descricao, "\n");

    FILE *contasp_file = fopen(typedoc == 1 ? "pagamentos.txt" : "pagamentos.bin", typedoc == 1 ? "r" : "rb");
    FILE *temp_file = fopen(typedoc == 1 ? "temp.txt" : "temp.bin", typedoc == 1 ? "w" : "wb");
    if (!contasp_file || !temp_file) return -2;

    int encontrado = 0;
    if (typedoc == 1) {
        char descr[50], data_venc[11];
        float valor;
        int status;

        while (fscanf(contasp_file, "%49[^,],%f,%10[^,],%d\n", descr, &valor, data_venc, &status) == 4) {
            if (strcmp(descr, descricao) == 0 && !status) {
                status = 1;
                encontrado = 1;

                // Registrar retirada no caixa
                FILE *caixa_file = fopen(typedoc == 1 ? "caixa.txt" : "caixa.bin", typedoc == 1 ? "a" : "ab");
                if (caixa_file) {
                    if (typedoc == 1) {
                        fprintf(caixa_file, "-%.2f,%s,%s\n", valor, descr, data_venc);
                    } else {
                        CAIXA transacao = {-valor};
                        strcpy(transacao.descricao, descr);
                        strcpy(transacao.data, data_venc);
                        fwrite(&transacao, sizeof(CAIXA), 1, caixa_file);
                    }
                    fclose(caixa_file);
                }
            }
            fprintf(temp_file, "%s,%.2f,%s,%d\n", descr, valor, data_venc, status);
        }
    } else {
        CONTASP conta;
        while (fread(&conta, sizeof(CONTASP), 1, contasp_file) == 1) {
            if (strcmp(conta.descricao, descricao) == 0 && !conta.status) {
                conta.status = 1;
                encontrado = 1;

                // Registrar retirada no caixa
                FILE *caixa_file = fopen(typedoc == 1 ? "caixa.txt" : "caixa.bin", typedoc == 1 ? "a" : "ab");
                if (caixa_file) {
                    if (typedoc == 1) {
                        fprintf(caixa_file, "-%.2f,%s,%s\n", conta.valor, conta.descricao, conta.data_vencimento);
                    } else {
                        CAIXA transacao = {-conta.valor};
                        strcpy(transacao.descricao, conta.descricao);
                        strcpy(transacao.data, conta.data_vencimento);
                        fwrite(&transacao, sizeof(CAIXA), 1, caixa_file);
                    }
                    fclose(caixa_file);
                }
            }
            fwrite(&conta, sizeof(CONTASP), 1, temp_file);
        }
    }

    fclose(contasp_file);
    fclose(temp_file);
    remove(typedoc == 1 ? "pagamentos.txt" : "pagamentos.bin");
    rename(typedoc == 1 ? "temp.txt" : "temp.bin", typedoc == 1 ? "pagamentos.txt" : "pagamentos.bin");

    return encontrado ? 0 : 1;
}

//agendamentos

int verificar_concorrencia(char *cpf_funcionario, char *data, char *hora) {
    FILE *arquivo = fopen(typedoc == 1 ? "agendamento.txt" : "agendamento.bin", typedoc == 1 ? "r" : "rb");
    if (!arquivo) {
        perror("Erro ao abrir arquivo de agendamentos");
        return -1; // Erro ao abrir o arquivo
    }

    AGENDAMENTO a;
    int conflito = 0;

    if (typedoc == 1) { // Modo texto
        while (fscanf(arquivo, "%d,%19[^,],%d,%19[^,],%19[^,],%19[^,],%d,%d\n",
                      &a.codigocliente, a.placaveiculo, &a.servico, a.data, a.hora, a.cpf, &a.peca, &a.qntd_pecas) == 8) {
            if (strcmp(a.cpf, cpf_funcionario) == 0 &&
                strcmp(a.data, data) == 0 &&
                strcmp(a.hora, hora) == 0) {
                conflito = 1; // Conflito encontrado
                break;
            }
        }
    } else { // Modo bin�rio
        while (fread(&a, sizeof(AGENDAMENTO), 1, arquivo) == 1) {
            if (strcmp(a.cpf, cpf_funcionario) == 0 &&
                strcmp(a.data, data) == 0 &&
                strcmp(a.hora, hora) == 0) {
                conflito = 1; // Conflito encontrado
                break;
            }
        }
    }

    fclose(arquivo);
    return conflito;
}

int debitar_estoque(int codigo_peca, int quantidade) {
    FILE *pecas = fopen(typedoc == 1 ? "pecas.txt" : "pecas.bin", "r");
    if (!pecas) {
        perror("Erro ao abrir arquivo de pe�as");
        return -1;
    }

    FILE *temp = fopen(typedoc == 1 ? "pecas_temp.txt" : "pecas_temp.bin", "w");
    if (!temp) {
        perror("Erro ao criar arquivo tempor�rio");
        fclose(pecas);
        return -1;
    }

    int codigo, estoque_atual, estoque_minimo;
    char descricao[50], fabricante[30], fornecedor[30];
    float preco_custo, preco_venda;

    int encontrado = 0;
    while (typedoc == 1
           ? fscanf(pecas, "%d,%49[^,],%29[^,],%29[^,],%f,%f,%d,%d\n",
                    &codigo, descricao, fabricante, fornecedor,
                    &preco_custo, &preco_venda, &estoque_atual, &estoque_minimo) == 8
           : fread(&codigo, sizeof(int), 1, pecas) &&
             fread(&descricao, sizeof(descricao), 1, pecas) &&
             fread(&estoque_atual, sizeof(int), 1, pecas)) {
        if (codigo == codigo_peca) {
            encontrado = 1;
            if (estoque_atual < quantidade) {
                printf("Erro: Estoque insuficiente para a pe�a %d. Dispon�vel: %d, Necess�rio: %d\n",
                       codigo_peca, estoque_atual, quantidade);
                fclose(pecas);
                fclose(temp);
                remove(typedoc == 1 ? "pecas_temp.txt" : "pecas_temp.bin");
                return -2; // Estoque insuficiente
            }
            estoque_atual -= quantidade;
        }

        if (typedoc == 1) {
            fprintf(temp, "%d,%s,%s,%s,%.2f,%.2f,%d,%d\n",
                    codigo, descricao, fabricante, fornecedor,
                    preco_custo, preco_venda, estoque_atual, estoque_minimo);
        } else {
            fwrite(&codigo, sizeof(int), 1, temp);
            fwrite(&descricao, sizeof(descricao), 1, temp);
            fwrite(&estoque_atual, sizeof(int), 1, temp);
        }
    }

    fclose(pecas);
    fclose(temp);

    if (!encontrado) {
        printf("Erro: Pe�a %d n�o encontrada no estoque.\n", codigo_peca);
        remove(typedoc == 1 ? "pecas_temp.txt" : "pecas_temp.bin");
        return -3; // Pe�a n�o encontrada
    }

    // Substituir o arquivo original pelo tempor�rio
    remove(typedoc == 1 ? "pecas.txt" : "pecas.bin");
    rename(typedoc == 1 ? "pecas_temp.txt" : "pecas_temp.bin", typedoc == 1 ? "pecas.txt" : "pecas.bin");
    return 0; // Sucesso
}

int agendamento() {
    AGENDAMENTO a = {0};
    int encontrado = 0;

    // Abrir o arquivo de agendamentos para leitura
    FILE *agendamento_file = fopen(typedoc == 1 ? "agendamento.txt" : "agendamento.bin", typedoc == 1 ? "r" : "rb");
    if (!agendamento_file) {
        perror("Erro ao abrir arquivo de agendamentos para leitura");
        return -2;
    }

    // Verificar o maior c�digo
    int codigo, mc = 0; // Inicializa o maior c�digo com 0
    if (typedoc == 1) { // Arquivo texto
        while (fscanf(agendamento_file, "%d,%*d,%*[^,],%*d,%*[^,],%*[^,],%*[^,],%*d,%*d\n", &codigo) == 1) {
            if (codigo > mc) mc = codigo;
        }
    } else { // Arquivo bin�rio
        AGENDAMENTO temp;
        while (fread(&temp, sizeof(AGENDAMENTO), 1, agendamento_file) == 1) {
            if (temp.codigo > mc) mc = temp.codigo;
        }
    }
    fclose(agendamento_file); // Fechar o arquivo ap�s leitura
    a.codigo = mc + 1; // Define o pr�ximo c�digo dispon�vel

    // Valida��o do cliente
    FILE *cliente_file = fopen(typedoc == 1 ? "cliente.txt" : "cliente.bin", typedoc == 1 ? "r" : "rb");
    if (!cliente_file) {
        perror("Erro ao abrir arquivo de clientes");
        return -2;
    }

    printf("Novo Agendamento:\n");
    printf("C�digo do cliente:\n");
    scanf("%d", &a.codigocliente);
    getchar();

    if (typedoc == 1) {
        while (fscanf(cliente_file, "%d,%*[^,],%*[^,],%*[^,],%*[^,],%*[^\n]\n", &codigo) == 1) {
            if (codigo == a.codigocliente) {
                encontrado = 1;
                break;
            }
        }
    } else {
        CLIENTE cli;
        while (fread(&cli, sizeof(CLIENTE), 1, cliente_file) == 1) {
            if (cli.codigo == a.codigocliente) {
                encontrado = 1;
                break;
            }
        }
    }
    fclose(cliente_file);

    if (!encontrado) {
        printf("Cliente n�o encontrado.\n");
        return -1;
    }

    // Valida��o do ve�culo
    FILE *veiculo_file = fopen(typedoc == 1 ? "veiculo.txt" : "veiculo.bin", typedoc == 1 ? "r" : "rb");
    if (!veiculo_file) {
        perror("Erro ao abrir arquivo de ve�culos");
        return -2;
    }

    printf("Placa do ve�culo:\n");
    fgets(a.placaveiculo, sizeof(a.placaveiculo), stdin);
    strtok(a.placaveiculo, "\n");

    encontrado = 0;
    if (typedoc == 1) {
        char placa[30];
        while (fscanf(veiculo_file, "%29[^,],%*[^,],%*[^,],%*d,%*[^,],%*[^\n]\n", placa) == 1) {
            if (strcmp(placa, a.placaveiculo) == 0) {
                encontrado = 1;
                break;
            }
        }
    } else {
        VEICULOS vei;
        while (fread(&vei, sizeof(VEICULOS), 1, veiculo_file) == 1) {
            if (strcmp(vei.placa, a.placaveiculo) == 0) {
                encontrado = 1;
                break;
            }
        }
    }
    fclose(veiculo_file);

    if (!encontrado) {
        printf("Ve�culo n�o encontrado.\n");
        return -1;
    }

    // Valida��o do servi�o
    FILE *servico_file = fopen(typedoc == 1 ? "servico.txt" : "servico.bin", typedoc == 1 ? "r" : "rb");
    if (!servico_file) {
        perror("Erro ao abrir arquivo de servi�os");
        return -2;
    }

    printf("C�digo do servi�o:\n");
    scanf("%d", &a.servico);
    getchar();

    encontrado = 0;
    if (typedoc == 1) {
        while (fscanf(servico_file, "%d,%*[^,],%*f,%*f\n", &codigo) == 1) {
            if (codigo == a.servico) {
                encontrado = 1;
                break;
            }
        }
    } else {
        SERVICO ser;
        while (fread(&ser, sizeof(SERVICO), 1, servico_file) == 1) {
            if (ser.codigo == a.servico) {
                encontrado = 1;
                break;
            }
        }
    }
    fclose(servico_file);

    if (!encontrado) {
        printf("Servi�o n�o encontrado.\n");
        return -1;
    }

    // Valida��o do funcion�rio
    FILE *funcionario_file = fopen(typedoc == 1 ? "funcionario.txt" : "funcionario.bin", typedoc == 1 ? "r" : "rb");
    if (!funcionario_file) {
        perror("Erro ao abrir arquivo de funcion�rios");
        return -2;
    }

    printf("CPF do funcion�rio:\n");
    fgets(a.cpf, sizeof(a.cpf), stdin);
    strtok(a.cpf, "\n");

    encontrado = 0;
    if (typedoc == 1) {
        char cpf[20];
        while (fscanf(funcionario_file, "%*[^,],%19[^,],%*[^,],%*f\n", cpf) == 1) {
            if (strcmp(cpf, a.cpf) == 0) {
                encontrado = 1;
                break;
            }
        }
    } else {
        FUNCIONARIO func;
        while (fread(&func, sizeof(FUNCIONARIO), 1, funcionario_file) == 1) {
            if (strcmp(func.cpf, a.cpf) == 0) {
                encontrado = 1;
                break;
            }
        }
    }
    fclose(funcionario_file);

    if (!encontrado) {
        printf("Funcion�rio n�o encontrado.\n");
        return -1;
    }

    // Valida��o de data e hora
    printf("Data (DD/MM/AAAA):\n");
    fgets(a.data, sizeof(a.data), stdin);
    strtok(a.data, "\n");

    printf("Hora (HH:MM):\n");
    fgets(a.hora, sizeof(a.hora), stdin);
    strtok(a.hora, "\n");

    if (verificar_concorrencia(a.cpf, a.data, a.hora)) {
        printf("Erro: J� existe um agendamento para este hor�rio.\n");
        return -1;
    }

    // Valida��o de pe�a
    printf("C�digo da pe�a utilizada:\n");
    scanf("%d", &a.peca);
    getchar();

    printf("Quantidade de pe�as:\n");
    scanf("%d", &a.qntd_pecas);
    getchar();

    // Abrir arquivo de agendamentos para grava��o
    agendamento_file = fopen(typedoc == 1 ? "agendamento.txt" : "agendamento.bin", typedoc == 1 ? "a" : "ab");
    if (!agendamento_file) {
        perror("Erro ao abrir arquivo de agendamentos para escrita");
        return -2;
    }

    if (typedoc == 1) {
        fprintf(agendamento_file, "%d,%d,%s,%d,%s,%s,%s,%d,%d\n",
                a.codigo, a.codigocliente, a.placaveiculo, a.servico, a.data, a.hora, a.cpf, a.peca, a.qntd_pecas);
    } else {
        fwrite(&a, sizeof(AGENDAMENTO), 1, agendamento_file);
    }

    fclose(agendamento_file);
    printf("Agendamento realizado com sucesso.\n");

    return 0;
}

int consulta_agendamento() {
    // Abrindo o arquivo conforme o tipo
    FILE *agendamento_file = fopen(typedoc == 1 ? "agendamento.txt" : "agendamento.bin", typedoc == 1 ? "r" : "rb");
    if (!agendamento_file) {
        perror("Erro ao abrir o arquivo de agendamentos");
        return -2;
    }

    if (typedoc == 1) { // Arquivo texto
        AGENDAMENTO a;

        printf("Exibindo agendamentos do arquivo texto:\n");
        printf("===========================================================================================\n");

        while (fscanf(agendamento_file, "%d,%d,%19[^,],%d,%19[^,],%19[^,],%19[^,],%d,%d\n",
                      &a.codigo, &a.codigocliente, a.placaveiculo, &a.servico, a.data, a.hora, a.cpf,&a.peca,&a.qntd_pecas) == 9) {
            printf("Agendamento:\n");
            printf("C�digo do agendamento: %d, C�digo do Cliente: %d, Placa do Ve�culo: %s, C�digo do Servi�o: %d,\nData: %s, Hora: %s, Funcion�rio: %s\nPe�as: %d Quantidade: %d\n",
                   a.codigo, a.codigocliente, a.placaveiculo, a.servico, a.data, a.hora, a.cpf, a.peca, a.qntd_pecas);
            printf("===========================================================================================\n");
        }

        fclose(agendamento_file); // Fechando o arquivo
    } else if (typedoc == 2) { // Arquivo bin�rio
        AGENDAMENTO ab;

        printf("Exibindo agendamentos do arquivo bin�rio:\n");
        printf("===========================================================================================\n");

        while (fread(&ab, sizeof(AGENDAMENTO), 1, agendamento_file) == 1) {
            printf("Agendamento:\n");
            printf("C�digo do agendamento: %d, C�digo do Cliente: %d, Placa do Ve�culo: %s, C�digo do Servi�o: %d,\nData: %s, Hora: %s, Funcion�rio: %s\nPe�as: %d Quantidade: %d\n",
                   ab.codigo, ab.codigocliente, ab.placaveiculo, ab.servico, ab.data, ab.hora, ab.cpf, ab.peca, ab.qntd_pecas);
            printf("===========================================================================================\n");
        }

        fclose(agendamento_file); // Fechando o arquivo
    } else {
        printf("Tipo de arquivo inv�lido. Digite 1 para texto ou 2 para bin�rio.\n");
        fclose(agendamento_file); // Fechando o arquivo em caso de erro
        return -1;
    }

    return 0; // Retorna 0 em caso de sucesso
}

int ordem_servico() {
    FILE *agendamento_file = fopen(typedoc == 1 ? "agendamento.txt" : "agendamento.bin", typedoc == 1 ? "r" : "rb");
    FILE *ordem_file = fopen(typedoc == 1 ? "ordem.txt" : "ordem.bin", typedoc == 1 ? "a+" : "ab");

    if (!agendamento_file || !ordem_file) {
        perror("Erro ao abrir os arquivos necess�rios");
        if (agendamento_file) fclose(agendamento_file);
        if (ordem_file) fclose(ordem_file);
        return -2;
    }

    AGENDAMENTO agendamento;
    ORDEM ordem;
    int encontrado = 0;

    printf("Digite o c�digo do agendamento: ");
    int codigo_aged;
    scanf("%d", &codigo_aged);
    getchar();

    // Localizar o agendamento no arquivo
    if (typedoc == 1) { // Arquivo texto
        while (fscanf(agendamento_file, "%d,%d,%19[^,],%d,%19[^,],%19[^,],%19[^,],%d,%d\n",
                      &agendamento.codigo, &agendamento.codigocliente, agendamento.placaveiculo, &agendamento.servico,
                      agendamento.data, agendamento.hora, agendamento.cpf,
                      &agendamento.peca, &agendamento.qntd_pecas) == 9) {
            if (agendamento.codigo == codigo_aged) {
                encontrado = 1;
                break;
            }
        }
    } else { // Arquivo bin�rio
        while (fread(&agendamento, sizeof(AGENDAMENTO), 1, agendamento_file) == 1) {
            if (agendamento.codigo == codigo_aged) {
                encontrado = 1;
                break;
            }
        }
    }

    if (!encontrado) {
        printf("Agendamento n�o encontrado.\n");
        fclose(agendamento_file);
        fclose(ordem_file);
        return -1;
    }

    // Preencher a ordem de servi�o
    ordem.codigoservico = agendamento.servico;
    ordem.codigopeca = agendamento.peca;
    ordem.qntd_pecas = agendamento.qntd_pecas;
    strcpy(ordem.veiculo, agendamento.placaveiculo);

    // Obter o valor do servi�o e comiss�o
    FILE *servico_file = fopen(typedoc == 1 ? "servico.txt" : "servico.bin", typedoc == 1 ? "r" : "rb");
    if (!servico_file) {
        perror("Erro ao abrir arquivo de servi�os");
        fclose(agendamento_file);
        fclose(ordem_file);
        return -2;
    }

    SERVICO servico;
    while (typedoc == 1
           ? fscanf(servico_file, "%d,%49[^,],%f,%f\n", &servico.codigo, servico.descricao, &servico.preco, &servico.comissao) == 4 : fread(&servico, sizeof(SERVICO), 1, servico_file) == 1) {
        if (servico.codigo == agendamento.servico) {
            ordem.vtotal = servico.preco - (servico.preco * (servico.comissao / 100.0));
            ordem.comissao = servico.preco - ordem.vtotal;
            break;
        }
    }

    fclose(servico_file);

    // Coletar o maior c�digo j� utilizado
    int codigo, mc = 0; // Inicializa mc com 0
    if (typedoc == 1) { // Arquivo texto
        rewind(ordem_file);
        while (fscanf(ordem_file, "%d,%*[^,],%*d,%*d,%*d,%*d,%*f,%*f\n", &codigo) == 1) {
            if (codigo > mc) mc = codigo;
        }
    } else { // Arquivo bin�rio
        ORDEM temp;
        while (fread(&temp, sizeof(ORDEM), 1, ordem_file) == 1) {
            if (temp.codigo > mc) mc = temp.codigo;
        }
    }
    ordem.codigo = mc + 1; // Define o novo c�digo

    // Escrever a ordem de servi�o
    if (typedoc == 1) {
        fprintf(ordem_file, "%d,%s,%d,%d,%d,%.2f,%.2f\n",
                ordem.codigo, ordem.veiculo, ordem.codigoservico, ordem.codigopeca, ordem.qntd_pecas, ordem.vtotal, ordem.comissao);
    } else {
        fwrite(&ordem, sizeof(ORDEM), 1, ordem_file);
    }

    fclose(ordem_file);

    // Reabrir o arquivo de agendamento para reescrever
    FILE *temp_file = fopen("temp_agendamento.bin", typedoc == 1 ? "w" : "wb");
    if (!temp_file) {
        perror("Erro ao abrir arquivo tempor�rio");
        fclose(agendamento_file);
        return -2;
    }

    rewind(agendamento_file); // Volta para o in�cio do arquivo
    if (typedoc == 1) { // Arquivo texto
        while (fscanf(agendamento_file, "%d,%d,%19[^,],%d,%19[^,],%19[^,],%19[^,],%d,%d\n",
                      &agendamento.codigo, &agendamento.codigocliente, agendamento.placaveiculo, &agendamento.servico,
                      agendamento.data, agendamento.hora, agendamento.cpf,
                      &agendamento.peca, &agendamento.qntd_pecas) == 9) {
            if (agendamento.codigo != codigo_aged) {
                fprintf(temp_file, "%d,%d,%s,%d,%s,%s,%s,%d,%d\n",
                        agendamento.codigo, agendamento.codigocliente, agendamento.placaveiculo, agendamento.servico,
                        agendamento.data, agendamento.hora, agendamento.cpf,
                        agendamento.peca, agendamento.qntd_pecas);
            }
        }
    } else { // Arquivo bin�rio
        while (fread(&agendamento, sizeof(AGENDAMENTO), 1, agendamento_file) == 1) {
            if (agendamento.codigo != codigo_aged) {
                fwrite(&agendamento, sizeof(AGENDAMENTO), 1, temp_file);
            }
        }
    }

    fclose(agendamento_file);
    fclose(temp_file);

    // Substituir o arquivo original pelo tempor�rio
    remove(typedoc == 1 ? "agendamento.txt" : "agendamento.bin");
    rename("temp_agendamento.bin", typedoc == 1 ? "agendamento.txt" : "agendamento.bin");

    printf("Ordem de servi�o emitida e agendamento removido com sucesso!\n");
    return 0;
}

int finalizar_ordem() {
    FILE *ordem_file = fopen(typedoc == 1 ? "ordem.txt" : "ordem.bin", typedoc == 1 ? "r" : "rb");
    FILE *temp_ordem = fopen(typedoc == 1 ? "ordem_temp.txt" : "ordem_temp.bin", typedoc == 1 ? "w" : "wb");
    FILE *caixa_file = fopen(typedoc == 1 ? "caixa.txt" : "caixa.bin", typedoc == 1 ? "a" : "ab");

    if (!ordem_file || !temp_ordem || !caixa_file) {
        perror("Erro ao abrir os arquivos necess�rios");
        if (ordem_file) fclose(ordem_file);
        if (temp_ordem) fclose(temp_ordem);
        if (caixa_file) fclose(caixa_file);
        return -2;
    }

    printf("Digite o c�digo da ordem que deseja finalizar: ");
    int codigo_ordem;
    scanf("%d", &codigo_ordem);
    getchar();

    printf("Data da finaliza��o (dd/mm/aa): ");
    char data[15];
    fgets(data, sizeof(data), stdin);
    strtok(data, "\n");

    ORDEM ordem;
    int encontrado = 0;

    while (typedoc == 1
           ? fscanf(ordem_file, "%d,%19[^,],%d,%d,%d,%f,%f\n",
                    &ordem.codigo, ordem.veiculo, &ordem.codigoservico, &ordem.codigopeca, &ordem.qntd_pecas, &ordem.vtotal, &ordem.comissao) == 7
           : fread(&ordem, sizeof(ORDEM), 1, ordem_file) == 1) {
        if (ordem.codigo == codigo_ordem) {
            encontrado = 1;

            // Atualizar o caixa
            CAIXA transacao = {ordem.vtotal, "Finaliza��o de ordem", ""};
            strcpy(transacao.data, data);

            if (typedoc == 1) {
                fprintf(caixa_file, "%.2f,%s,%s\n", transacao.saldo, transacao.descricao, transacao.data);
            } else {
                fwrite(&transacao, sizeof(CAIXA), 1, caixa_file);
            }

            // Atualizar estoque
            int resultado_estoque = debitar_estoque(ordem.codigopeca, ordem.qntd_pecas);
            if (resultado_estoque != 0) {
                printf("Erro ao debitar estoque para a pe�a %d. C�digo de erro: %d\n", ordem.codigopeca, resultado_estoque);
            }
        } else {
            if (typedoc == 1) {
                fprintf(temp_ordem, "%d,%s,%d,%d,%d,%f,%f\n",
                        ordem.codigo, ordem.veiculo, ordem.codigoservico, ordem.codigopeca, ordem.qntd_pecas, ordem.vtotal, ordem.comissao);
            } else {
                fwrite(&ordem, sizeof(ORDEM), 1, temp_ordem);
            }
        }
    }

    fclose(ordem_file);
    fclose(temp_ordem);
    fclose(caixa_file);

    // Substituir o arquivo original
    remove(typedoc == 1 ? "ordem.txt" : "ordem.bin");
    rename(typedoc == 1 ? "ordem_temp.txt" : "ordem_temp.bin", typedoc == 1 ? "ordem.txt" : "ordem.bin");

    if (encontrado) {
        printf("Ordem de servi�o finalizada com sucesso!\n");
        return 0;
    } else {
        printf("Ordem de servi�o n�o encontrada.\n");
        return -1;
    }
}

int consulta_ordens() {
    // Abrindo o arquivo de ordens conforme o tipo
    FILE *ordem_file = fopen(typedoc == 1 ? "ordem.txt" : "ordem.bin", typedoc == 1 ? "r" : "rb");
    if (!ordem_file) {
        perror("Erro ao abrir o arquivo de ordens de servi�o");
        return -2;
    }

    printf("Ordens de Servi�o Ativas:\n");
    printf("===========================================================================================\n");

    if (typedoc == 1) { // Arquivo texto
        ORDEM o;
        while (fscanf(ordem_file, "%d,%19[^,],%d,%d,%d,%f,%f\n",
                      &o.codigo, o.veiculo, &o.codigoservico, &o.codigopeca,
                      &o.qntd_pecas, &o.vtotal, &o.comissao) == 7) {
            printf("C�digo da ordem: %d\n", o.codigo);
            printf("Placa do veiculo: %s\n", o.veiculo);
            printf("C�digo do Servi�o: %d\n", o.codigoservico);
            printf("C�digo da Pe�a: %d\n", o.codigopeca);
            printf("Quantidade de Pe�as: %d\n", o.qntd_pecas);
            printf("Valor Total: %.2f\n", o.vtotal);
            printf("Comiss�o do funcion�rio: %.2f\n", o.comissao);
            printf("-------------------------------------------------------------------------------------------\n");
        }
    } else { // Arquivo bin�rio
        ORDEM ordem;
        while (fread(&ordem, sizeof(ORDEM), 1, ordem_file) == 1) {
            printf("C�digo da ordem: %d\n", ordem.codigo);
            printf("Placa do veiculo: %s\n", ordem.veiculo);
            printf("C�digo do Servi�o: %d\n", ordem.codigoservico);
            printf("C�digo da Pe�a: %d\n", ordem.codigopeca);
            printf("Quantidade de Pe�as: %d\n", ordem.qntd_pecas);
            printf("Valor Total: %.2f\n", ordem.vtotal);
            printf("Comiss�o do funcion�rio: %.2f\n", ordem.comissao);
            printf("-------------------------------------------------------------------------------------------\n");
        }
    }

    fclose(ordem_file); // Fechando o arquivo
    return 0; // Retorna 0 em caso de sucesso
}


