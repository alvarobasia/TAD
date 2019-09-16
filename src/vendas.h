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

void imprimeVendas(TVendas Vendas);

int lerVendas(TVendas *Vendas, ModuloClientes *ModuloClientes, ModuloProdutos *ModuloProdutos);

void iniciarModuloVendas(ModuloVendas *ModuloVendas);

void inserirVendas(ModuloVendas *ModuloVendas, TVendas Vendas);

int pesquisarVendas(ModuloVendas ModuloVendas, ModuloProdutos ModuloProdutos, ModuloClientes ModuloClientes, 
TCliente Cliente, TProdutos Produtos);

void imprimirTodasAsVendas(ModuloVendas Vendas);

void alterarVenda(ModuloVendas* ModuloVendas, ModuloProdutos* ModuloProdutos, ModuloClientes* ModuloCliente, TCliente cliente,
TProdutos produtos);

void excluirVendas(ModuloVendas* ModuloVendas, ModuloClientes* ModuloClientes, ModuloProdutos* Produtos, TCliente cliente,
TProdutos produtos);

#endif