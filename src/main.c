#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include "clientes.h"
#include "produtos.h"
#include "vendas.h"
#include "menu.h"
#define TAM 50

int main()

{
    setlocale(LC_ALL, "portuguese");
    ModuloClientes clientes1;
    ModuloProdutos produtos1;
    ModuloVendas vendas1;
    iniciarModuloCliente(&clientes1);
    iniciarModuloProduto(&produtos1);
    iniciarModuloVendas(&vendas1);
    Menu();
    return 0;
}
