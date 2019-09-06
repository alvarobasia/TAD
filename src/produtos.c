#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <unistd.h>
#include "produtos.h"

void imprimeInfoProduto(ModuloProdutos modulo){
    puts("------INFORMAÇÕES DO PRODUTO---------");
    printf("Codigo do produto: ");
    printf("%d\n", modulo.listaDeProdutos[modulo.indice].codigoDoProd);
    printf("Nome do produto: ");
    printf("%s\n", modulo.listaDeProdutos[modulo.indice].nomeDoProd);
    printf("Descrição do produto: ");
    printf(" ' %s '\n", modulo.listaDeProdutos[modulo.indice].descricaoDoProd);
    printf("Data de fabricação: ");
    printf("%d / %d/ %d\n", modulo.listaDeProdutos[modulo.indice].dataFabri.dia,
    modulo.listaDeProdutos[modulo.indice].dataFabri.mes,
    modulo.listaDeProdutos[modulo.indice].dataFabri.ano);
    printf("Lote do produto: ");
    printf("%s\n", modulo.listaDeProdutos[modulo.indice].loteDoProd);
    printf("Preço do produto: ");
    printf("R$ %f\n", modulo.listaDeProdutos[modulo.indice].precoUnit);
    printf("Quantidade de produtos no estoque: ");
    printf("%d\n", modulo.listaDeProdutos[modulo.indice].quantidadeProd);
    printf("--------------------------------------------------\n");
}

void lerProduto(ModuloProdutos *ModuloProdutos){
    printf("-------------------------------------------\n");
    printf("--------***REGISTRAR PRODUTO***-------------\n");
    printf("Digite o codigo do produto \n");
    scanf("%d", &ModuloProdutos->listaDeProdutos[ModuloProdutos->indice].codigoDoProd);
    limpezaDoBuffer();
    printf("Digite o nome do produto: \n");
    fgets(ModuloProdutos->listaDeProdutos[ModuloProdutos->indice].nomeDoProd, 49, stdin);
    limpezaDoBuffer();
    printf("Digite a descrição do produto: \n");
    fgets(ModuloProdutos->listaDeProdutos[ModuloProdutos->indice].descricaoDoProd, 49, stdin);
    printf("Digite a data de fabricação do produto\n");
    printf("DIA: ");
    scanf("%d", &ModuloProdutos->listaDeProdutos[ModuloProdutos->indice].dataFabri.dia);
    printf("MÊS: ");
    scanf("%d", &ModuloProdutos->listaDeProdutos[ModuloProdutos->indice].dataFabri.mes);
    printf("ANO: ");
    scanf("%d", &ModuloProdutos->listaDeProdutos[ModuloProdutos->indice].dataFabri.ano);
    printf("Digite o lote do produto: \n");
    limpezaDoBuffer();
    fgets(ModuloProdutos->listaDeProdutos[ModuloProdutos->indice].loteDoProd, 49, stdin);
    printf("Digite o preço do produto: \n");
    scanf("%f", &ModuloProdutos->listaDeProdutos[ModuloProdutos->indice].precoUnit);
    printf("Digite a quantidade de produtos que o estoque possui: \n");
    scanf("%d", &ModuloProdutos->listaDeProdutos[ModuloProdutos->indice].quantidadeProd);
    imprimeInfoProduto(*ModuloProdutos);
    //imprimeInfoProduto(*ModuloProdutos); 
}

void iniciarModuloProduto(ModuloProdutos *ModuloProdutos){
    ModuloProdutos->indice = 0;
}

void inserirProduto(ModuloProdutos *ModuloProdutos, TProdutos Produtos){
    if (ModuloProdutos->indice < TAM)
    {
        ModuloProdutos->listaDeProdutos[ModuloProdutos->indice] = Produtos;
        ModuloProdutos->indice++;
    }
}

int pesquisarProduto(ModuloProdutos ModuloProdutos, TProdutos  Produtos){
    int i;
    for(i = 0; i <= ModuloProdutos.indice; i++){
        if(ModuloProdutos.listaDeProdutos[i].codigoDoProd == Produtos.codigoDoProd){
            printf("Produto encontrado");
            sleep(5);
            return i;
        }
    }
    printf("Produto inexistente\n");
    sleep(5000);
    return -1;
}