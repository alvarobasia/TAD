#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#ifndef VENDAS_H_INCLUDED
#define VENDAS_H_INCLUDED
#include "estoque.h"
#include "clientes.h"
#include "produtos.h"
#define TAM 50

typedef struct Vendas
{
    int codigo;
    char ID[TAM];
    int quantidadeDeVendas;
    TData dataDaVenda;
    int tipoDePagamento; //1 - a vista ou 2 - a prazo
    float totalDaVenda;
    TData prazoParaPagamento;
    TCliente debitosParaVenda;
} TVendas;

typedef struct _ModuloVendas{
    TVendas vendasRealizadas[90];
    int indice;
}ModuloVendas;

void imprimeVendas(ModuloVendas ModuloVendas);

int lerVendas(ModuloVendas *ModuloVendas, ModuloClientes *ModuloClientes, ModuloProdutos *ModuloProdutos);

void iniciarModuloVendas(ModuloVendas *ModuloVendas);

void inserirVendas(ModuloVendas *ModuloVendas, TVendas Vendas);

#endif