#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include "clientes.h"
#include "produtos.h"
#include "vendas.h"
#define TAM 50

/*void registrador(ModuloClientes* clientes1, ModuloProdutos* produtos1, ModuloVendas* vendas1){
    int tipoDeAcao;
    printf("VOCÊ DESEJA: \n");
    printf("****************************\n");
    printf("Digite:\n");
    printf("|1| -- REGISTRAR CLIENTE --\n");
    printf("|2| -- REGISTRAR PRODUTO --\n");
    printf("|3| -- EFETUAR UMA VENDA --\n");
    scanf("%d", &tipoDeAcao);
    limpezaDoBuffer();
    if(tipoDeAcao == 1)
        lerCliente(clientes1);
    if(tipoDeAcao == 2)
        lerProduto(produtos1);
    if(tipoDeAcao == 3)
        lerVendas(vendas1, clientes1, produtos1);
    registrador(clientes1, produtos1, vendas1 );
}

*/
int main()

{
    ModuloClientes clientes1;
    ModuloProdutos produtos1;
    ModuloVendas vendas1;
    int erro;
    setlocale(LC_ALL, "portuguese");
    iniciarModuloCliente(&clientes1);
    iniciarModuloProduto(&produtos1);
    iniciarModuloVendas(&vendas1);
    lerCliente(&clientes1.listaDeClientes[clientes1.indice]);
    imprimeInfoCliente(clientes1.listaDeClientes[clientes1.indice]);
    inserirCliente(&clientes1, clientes1.listaDeClientes[clientes1.indice]);
    lerProduto(&produtos1.listaDeProdutos[produtos1.indice]);
    imprimeInfoProduto(produtos1.listaDeProdutos[produtos1.indice]);
    inserirProduto(&produtos1, produtos1.listaDeProdutos[produtos1.indice]);
    limpezaDoBuffer();
    //registrador(&clientes1, &produtos1, &vendas1);
    return 0;
}
