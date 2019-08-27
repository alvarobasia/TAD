#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
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
    char cep[TAM];
    int numero;
} TEndereco;

typedef struct Cliente
{
    char nome[TAM];
    char ID[TAM];//CPF E CNPJ
    char identidade[TAM];
    TData dataDeNascimento;
    TEndereco enderecoCompleto;
    short int tipoCliente; //0 - pessoa Fisica 1 - Pessoa juridica
    short int debitoRegistrado; //0 - não tem 1 - tem
} TCliente;

typedef struct _ModuloClientes{
    TCliente listaDeClientes[80];
    int indice;
}ModuloClientes;

void imprimeInfoCliente(ModuloClientes modulo, int indice);

void lerCliente(ModuloClientes *ModuloClientes);