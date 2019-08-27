#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include "produtos.h"

void imprimeInfoProduto(ModuloProdutos modulo, int indice){
    puts("------INFORMAÇÕES DO PRODUTO---------");
    printf("Codigo do produto: ");
    printf("%d\n", modulo.listaDeProdutos[indice].codigoDoProd);
    printf("Nome do produto: ");
    printf("%s\n", modulo.listaDeProdutos[indice].nomeDoProd);
    printf("Descrição do produto: ");
    printf(" ' %s '\n", modulo.listaDeProdutos[indice].descricaoDoProd);
    printf("Data de fabricação: ");
    printf("%d / %d/ %d\n", modulo.listaDeProdutos[indice].dataFabri.dia,
    modulo.listaDeProdutos[indice].dataFabri.mes,
    modulo.listaDeProdutos[indice].dataFabri.ano);
    printf("Lote do produto: ");
    printf("%s\n", modulo.listaDeProdutos[indice].loteDoProd);
    printf("Preço do produto: ");
    printf("R$ %f\n", modulo.listaDeProdutos[indice].precoUnit);
    printf("Quantidade de produtos no estoque: ");
    printf("%d\n", modulo.listaDeProdutos[indice].quantidadeProd);
    printf("--------------------------------------------------\n");
}

void lerProduto(ModuloProdutos *ModuloProdutos){
    limparConsole();
    int indice = 0;
    int resposta = 1;
    while (1){
        printf("-------------------------------------------\n");
        printf("--------***REGISTRAR PRODUTO***-------------\n");
        printf("Digite o codigo do produto \n");
        scanf("%d", &ModuloProdutos->listaDeProdutos[indice].codigoDoProd);
        limpezaDoBuffer();
        printf("Digite o nome do produto: \n");
        fgets(ModuloProdutos->listaDeProdutos[indice].nomeDoProd, 49, stdin);
        limpezaDoBuffer();
        printf("Digite a descrição do produto: \n");
        fgets(ModuloProdutos->listaDeProdutos[indice].descricaoDoProd, 49, stdin);
        printf("Digite a data de fabricação do produto\n");
        printf("DIA: ");
        scanf("%d", &ModuloProdutos->listaDeProdutos[indice].dataFabri.dia);
        printf("MÊS: ");
        scanf("%d", &ModuloProdutos->listaDeProdutos[indice].dataFabri.mes);
        printf("ANO: ");
        scanf("%d", &ModuloProdutos->listaDeProdutos[indice].dataFabri.ano);
        printf("Digite o lote do produto: \n");
        limpezaDoBuffer();
        fgets(ModuloProdutos->listaDeProdutos[indice].loteDoProd, 49, stdin);
        printf("Digite o preço do produto: \n");
        scanf("%f", &ModuloProdutos->listaDeProdutos[indice].precoUnit);
        printf("Digite a quantidade de produtos que o estoque possui: \n");
        scanf("%d", &ModuloProdutos->listaDeProdutos[indice].quantidadeProd);
        limparConsole();
        imprimeInfoProduto(*ModuloProdutos, indice);
        printf("Você deseja registrar um novo produto? 1 - sim 2 - não\n");
        scanf("%d", &resposta);
        limpezaDoBuffer();
        if (resposta == 1)
            indice++;
        else
            ModuloProdutos->indice += indice;
            break;
    }
}