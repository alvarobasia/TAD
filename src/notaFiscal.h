#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <unistd.h> 
#include "menu.h"
#include "vendas.h"
#include "clientes.h"
#include "produtos.h"
#ifndef NOTAFISCAL_H_INCLUDED
#define NOTAFISCAL_H_INCLUDED
typedef struct _notaFiscal
{
  TCliente Cliente;
  TData data;
  TVendas Vendas[TAM];
}notaFiscal;

typedef struct _ModulonotaFiscal
{
  int indice;
  notaFiscal notasfiscais[TAM];
}ModulonotaFiscal;

void inicialNotaFiscal(ModulonotaFiscal* ModulonotaFiscal);

#endif