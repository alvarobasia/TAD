#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include "clientes.h"
#include "produtos.h"
#include "vendas.h"
#define TAM 50

void registrador(ModuloClientes* clientes1, ModuloProdutos* produtos1, ModuloVendas* vendas1){
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

void copyRight(){
    printf("Criado por Álvaro Basílio , 2019 ");
    printf("©Todos os direitos reservados\n");
    printf("VOCÊ NÃO DEVE USAR UMA CÓPIA PIRATA DESSE SOFTWARE\n");
}
int main()

{
    ModuloClientes clientes1;
    ModuloProdutos produtos1;
    ModuloVendas vendas1;
    setlocale(LC_ALL, "portuguese");
    copyRight();
    clientes1.indice = 0;
    produtos1.indice = 0;
    vendas1.indice = 0;
    registrador(&clientes1, &produtos1, &vendas1);
    return 0;
}
