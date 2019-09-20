#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <unistd.h>
#include "produtos.h"
#include "menu.h"

void imprimeInfoProduto(TProdutos modulo){
    puts("\n------INFORMAÇÕES DO PRODUTO---------");
    printf("Codigo do produto: ");
    printf("%d\n", modulo.codigoDoProd);
    printf("Nome do produto: ");
    printf("%s\n", modulo.nomeDoProd);
    printf("Descrição do produto: ");
    printf("  %s ", modulo.descricaoDoProd);
    printf("Data de fabricação: ");
    printf("%d / %d/ %d\n", modulo.dataFabri.dia,
    modulo.dataFabri.mes,modulo.dataFabri.ano);
    printf("Lote do produto: ");
    printf("%s\n", modulo.loteDoProd);
    printf("Preço do produto: ");
    printf("R$ %.2f\n", modulo.precoUnit);
    printf("Quantidade de produtos no estoque: ");
    printf("%d\n", modulo.quantidadeProd);
    printf("--------------------------------------------------\n");
    printf("PRESSIONE ENTER PARA CONTINUAR!!!!");
    limpezaDoBuffer();
    getchar();
}

void lerProduto(TProdutos *ModuloProdutos){
    limparConsole();
    printf("-------------------------------------------\n");
    printf("--------***REGISTRAR PRODUTO***-------------\n");
    printf("Digite o codigo do produto: ");
    scanf("%d", &ModuloProdutos->codigoDoProd);
    limpezaDoBuffer();
    printf("Digite o nome do produto: ");
    fgets(ModuloProdutos->nomeDoProd, 49, stdin);
    limpezaDoBuffer();
    printf("Digite a descrição do produto: ");
    fgets(ModuloProdutos->descricaoDoProd, 49, stdin);
    printf("Digite a data de fabricação do produto: \n");
    printf("DIA: ");
    scanf("%d", &ModuloProdutos->dataFabri.dia);
    printf("MêS: ");
    scanf("%d", &ModuloProdutos->dataFabri.mes);
    printf("ANO: ");
    scanf("%d", &ModuloProdutos->dataFabri.ano);
    printf("Digite o lote do produto: ");
    limpezaDoBuffer();
    fgets(ModuloProdutos->loteDoProd, 49, stdin);
    printf("Digite o preço do produto: ");
    scanf("%f", &ModuloProdutos->precoUnit);
    printf("Digite a quantidade de produtos que o estoque possui: ");
    scanf("%d", &ModuloProdutos->quantidadeProd);
    limparConsole();
    limpezaDoBuffer();
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
    limparConsole();
    printf("Produtos: \n");
    for(int i = 0; i < produtos.indice; i++){
        imprimeInfoProduto(produtos.listaDeProdutos[i]);
    }
}

void alterarProduto(ModuloProdutos* ModuloProdutos, TProdutos Produtos){
  int resposta = pesquisarProduto(*ModuloProdutos, Produtos);
  if(resposta == -1){
    limpezaDoBuffer();
    printf("\t Produto não encontrado. Retornando ao menu... \n");
    printf("PRESSIONE ENTER PARA CONTINUAR\n");
    getchar();
    limparConsole();
    return;
  }
  limpezaDoBuffer();
  printf("Produto encontrado: %s, pressione ENTER para alterar ...\n", ModuloProdutos->listaDeProdutos[resposta].nomeDoProd);
  imprimeInfoProduto(ModuloProdutos->listaDeProdutos[resposta]);
  lerProduto(&ModuloProdutos->listaDeProdutos[resposta]);
  imprimeInfoProduto(ModuloProdutos->listaDeProdutos[resposta]);
}

void excluirProduto(ModuloProdutos* ModuloProdutos, TProdutos Produtos){
  int resposta = pesquisarProduto(*ModuloProdutos, Produtos);
  if(resposta == -1){
    limpezaDoBuffer();
    printf("\t Produto não encontrado. Retornando ao menu... \n");
    printf("PRESSIONE ENTER PARA CONTINUAR\n");
    getchar();
    limparConsole();
    return;
  }
  limpezaDoBuffer();
  printf("Produto %s encontrado, pressione ENTER excluir ...\n", ModuloProdutos->listaDeProdutos[resposta].nomeDoProd);
  imprimeInfoProduto(ModuloProdutos->listaDeProdutos[resposta]);
  for (int j = resposta; j < ModuloProdutos->indice ; j++) {
      ModuloProdutos->listaDeProdutos[j] = ModuloProdutos->listaDeProdutos[j + 1];
  }
  ModuloProdutos->indice--;
  printf("Produto excluído com sucesso! \n");
  limpezaDoBuffer();
  printf("PRESSIONE ENTER PARA CONTINUAR\n");
  getchar();
}