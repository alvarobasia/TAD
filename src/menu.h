#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "estoque.h"	
#include "clientes.h"
#include "produtos.h"
#include "vendas.h"
#include "notaFiscal.h"
#define TAM 50

void MENU_PROVA();

void MSG_MENU_PRINCIPAL();

void MSG_SUB(int numeroModulo, char nome[], char menu[]);

void SubMenuModulo1(ModuloClientes* Cliente, TCliente clientes);

void SubMenuModulo2(ModuloProdutos* Produto, TProdutos produtos);

void SubMenuModulo3(ModuloVendas* Vendas, TVendas vendas, ModuloProdutos *Produtos, ModuloClientes *Cliente);

void Menu(ModuloClientes* Cliente, TCliente Clientes, ModuloProdutos* Produtos,
TProdutos Produto, ModuloVendas* Vendas, TVendas Venda);
void Menu();

#endif