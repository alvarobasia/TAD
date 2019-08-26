#include <stdlib.h>
#include <stdio.h>
#define TAM 50

typedef struct Data
{
    int dia;
    int mes;
    int ano;
} TData;

typedef struct _endereco
{
    char cidade[TAM];
    char bairro[TAM];
    char rua[TAM];
    char complemento;
    char cep;
    int numero;
} TEndereco;

typedef struct Produtos
{
    int codigoDoProd;
    char nomeDoProd[TAM];
    char descricaoDoProd[TAM];
    TData dataFabri;
    char loteDoProd[TAM];
    float precoUnit;
    int quantidadeProd;
} TProdutos;

typedef struct Cliente
{
    char nome[TAM];
    char ID[TAM];//CPF E CNPJ
    char identidade[TAM];
    TData dataDeNascimento;
    TEndereco enderecoCompleto;
    short int tipoCliente; //0 - pessoa Fisica 1 - Pessoa juridica
    int debitoRegistrado; //0 - n�o tem 1 - tem
} TCliente;

typedef struct Vendas
{
    int codigo;
    char ID;
    int quantidadeDeVendas;
    TData dataDaVenda;
    int tipoDePagamanto; //a vista ou a prazo
    float totalDaVenda;
    char dataRealizacaoCompra[TAM];
    char prazoParaPagamento[TAM];
    TCliente debitosParaVenda;
} TVendas;


int main()
{
    return 0;
}
