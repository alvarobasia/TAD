#include <stdlib.h>
#define TAM 50
#include "estoque.h"

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

typedef struct _ModuloClientes{
  TCliente listaDeClientes[TAM];
  int indice;
}ModuloClientes;

void imprimeInfoCliente(ModuloClientes modulo, int indice);

void lerCliente(ModuloClientes *modulo);