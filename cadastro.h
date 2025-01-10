#ifndef CADASTRO_H
#define CADASTRO_H

// Estruturas de registro

typedef struct {
    char nome[50];
    char cpf[20];
    char endereco[50];
    char telefone[20];
    char email[20];
    float lucro;
}OFICINA;

typedef struct{
    int codigo;
    char nome[50];
    char cpf[20];
    char endereco[50];
    char telefone [20];
    char email[20];
}CLIENTE;

typedef struct {
    char placa[30];
    char modelo[50];
    char marca[50];
    int anof;
    char chassi[20];
    char ptt[20];
}VEICULOS;

typedef struct {
    int codigo;
    char descricao[50];
    char fabricante[30];
    char fornecedor[30];
    float p_custo;
    float p_venda;
    int qntd_estoque;
    int qntd_minima;
} PECA;

typedef struct {
    int codigo;
    char nome_fantasia[50];
    char razao_social[50];
    char inscricao_est[20];
    char cnpj[20];
    char endereco[100];
    char telefone[20];
    char email[50];
} FORNECEDOR;

typedef struct {
    int codigo;
    char descricao[50];
    float preco;
    float comissao;
} SERVICO;

typedef struct {
    char nome[50];
    char cpf[15];
    char cargo[50];
    float salario;
} FUNCIONARIO;

typedef struct Caixa {
    float saldo;            // Valor da transação
    char descricao[50];     // Descrição da transação
    char data[15];
}CAIXA;

typedef struct ContasReceber {
    char descricao[50];       // Descrição da conta a receber
    char data_vencimento[11]; // Data de vencimento no formato DD/MM/AAAA
    float valor;              // Valor da conta a receber
    int status;               // Status da conta (0 = Pendente, 1 = Pago)
} CONTASR;

typedef struct ContasPagar {
    char descricao[50];
    char data_vencimento[15];
    float valor;
    int status; // 0: pendente, 1: paga
} CONTASP;

//variaveis globais
extern OFICINA *oficina;
extern CLIENTE *cliente;
extern VEICULOS *veiculo;
extern PECA *pecas;
extern FORNECEDOR *fornecedores;
extern FUNCIONARIO *funcionarios;
extern SERVICO *servicos;


// Declaração de funções
int troca();
void inicializa_arquivos();
void finalizar_dados();
int copy_element();
int not_found();
int invalid_in();

int cadastro_oficina();
int consulta_oficina();
int excluir_oficina();
int alterar_oficina();

int salvar_oficina();
int salvar_cliente();
int salvar_veiculo();
int salvar_peca();
int salvar_fornecedor();
int salvar_funcionario();
int salvar_servico();

int cadastro_cliente();
int consulta_clientes();
int exluir_cliente();
int alterar_cliente();

int cadastro_veiculo();
int consulta_veiculos();
int exluir_veiculo();
int alterar_veiculo();

int cadastro_pecas();
int consulta_pecas();
int exluir_peca();
int alterar_peca();

int cadastro_fornecedor();
int consulta_fornecedores();
int excluir_fornecedor();

int cadastro_servico();
int consulta_servicos();
int excluir_servico();

int cadastro_funcionario();
int consulta_funcionarios();
int excluir_funcionario();
int alterar_funcionario();

//funções de escrita

int copy_element();
int not_found();
int repeat();
int invalid_in();
void print_oficina (OFICINA o);
void print_cliente (CLIENTE c);
void print_veiculo (VEICULOS v);
void print_pecas (PECA p);
void print_fornecedor (FORNECEDOR f);
void print_servico (SERVICO s);
void print_funcionario (FUNCIONARIO f);
void print_saldo (float x);

#endif // CADASTRO_H
