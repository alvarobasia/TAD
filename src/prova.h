#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <unistd.h> 
#include "clientes.h"
#include "menu.h"
#ifndef PROVA_H_INCLUDED
#define PROVA_H_INCLUDED

void produtoMaisVendido(ModuloVendas Vendas, ModuloProdutos Produtos);
void vendasAVista(ModuloVendas vendas);
void clientesIguais(ModuloVendas vendas, TCliente c1, TCliente c2, ModuloProdutos Produtos);
void NotaFiscal(ModuloVendas Vendas, TCliente Cliente, TData data);

#endif