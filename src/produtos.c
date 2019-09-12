#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include "produtos.h"

void imprimeInfoProduto(TProdutos modulo){
    puts("------INFORMA��ES DO PRODUTO---------");
    printf("Codigo do produto: ");
    printf("%d\n", modulo.codigoDoProd);
    printf("Nome do produto: ");
    printf("%s\n", modulo.nomeDoProd);
    printf("Descri��o do produto: ");
    printf(" \' %s \'\n", modulo.descricaoDoProd);
    printf("Data de fabrica��o: ");
    printf("%d / %d/ %d\n", modulo.dataFabri.dia,
    modulo.dataFabri.mes,modulo.dataFabri.ano);
    printf("Lote do produto: ");
    printf("%s\n", modulo.loteDoProd);
    printf("Pre�o do produto: ");
    printf("R$ %f\n", modulo.precoUnit);
    printf("Quantidade de produtos no estoque: ");
    printf("%d\n", modulo.quantidadeProd);
    printf("--------------------------------------------------\n");
}

void lerProduto(TProdutos *ModuloProdutos){
    printf("-------------------------------------------\n");
    printf("--------***REGISTRAR PRODUTO***-------------\n");
    printf("Digite o codigo do produto \n");
    scanf("%d", &ModuloProdutos->codigoDoProd);
    limpezaDoBuffer();
    printf("Digite o nome do produto: \n");
    fgets(ModuloProdutos->nomeDoProd, 49, stdin);
    limpezaDoBuffer();
    printf("Digite a descri��o do produto: \n");
    fgets(ModuloProdutos->descricaoDoProd, 49, stdin);
    printf("Digite a data de fabrica��o do produto\n");
    printf("DIA: ");
    scanf("%d", &ModuloProdutos->dataFabri.dia);
    printf("M�S: ");
    scanf("%d", &ModuloProdutos->dataFabri.mes);
    printf("ANO: ");
    scanf("%d", &ModuloProdutos->dataFabri.ano);
    printf("Digite o lote do produto: \n");
    limpezaDoBuffer();
    fgets(ModuloProdutos->loteDoProd, 49, stdin);
    printf("Digite o preço do produto: \n");
    scanf("%f", &ModuloProdutos->precoUnit);
    printf("Digite a quantidade de produtos que o estoque possui: \n");
    scanf("%d", &ModuloProdutos->quantidadeProd);
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
    for(i = 0; i < ModuloProdutos.indice; i++){
        if(ModuloProdutos.listaDeProdutos[i].codigoDoProd == Produtos.codigoDoProd){
            return i;
        }
    }
    return -1;
}
void imprimirTodosOsProdutos(ModuloProdutos produtos){
    printf("Produtos: \n");
    for(int i = 0; i < produtos.indice; i++){
        imprimeInfoProduto(produtos.listaDeProdutos[i]);
    }
}
void alterarProduto(ModuloProdutos* ModuloProdutos, TProdutos produtos){
  int resposta = pesquisarProduto(*ModuloProdutos, produtos);
  if(resposta == -1){
    printf("\nProduto não encontrado para alteração");
    return;
  }
  printf("Alterar Produto");
  lerProduto(&ModuloProdutos->listaDeProdutos[resposta]);
}