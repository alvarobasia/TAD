#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#ifndef PRODUTOS_H_INCLUDED
#define PRODUTOS_H_INCLUDED
#include "estoque.h"
#define TAM 50

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

typedef struct _ModuloProdutos{
    TProdutos listaDeProdutos[80];
    int indice;
}ModuloProdutos;

void imprimeInfoProduto(ModuloProdutos modulo, int indice);

void lerProduto(ModuloProdutos *ModuloProdutos);

#endif