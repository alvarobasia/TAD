#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED
#include "estoque.h"
#define TAM 50



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

void imprimeInfoCliente(TCliente modulo);

void lerCliente(TCliente *ModuloClientes);

void iniciarModuloCliente(ModuloClientes *ModuloClientes);

void inserirCliente(ModuloClientes *ModuloClientes, TCliente Cliente);

int pesquisarCliente(ModuloClientes ModuloClientes, TCliente Cliente);

void imprimirTodosOsClientes(ModuloClientes ModuloClientes);

void alterarCliente(ModuloClientes* ModuloClientes, TCliente clientes);

void excluirCliente(ModuloClientes* ModuloClientes, TCliente cliente);


#endif