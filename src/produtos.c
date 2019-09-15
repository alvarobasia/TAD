#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <unistd.h>
#include "produtos.h"
#include "menu.h"

void imprimeInfoProduto(TProdutos modulo){
    printf(AMA);
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
    printf(DEF_LETRA);
    printf("PRESSIONE ENTER PARA CONTINUAR!!!!");
    limpezaDoBuffer();
    getchar();
}

void lerProduto(TProdutos *ModuloProdutos){
    limparConsole();
    printf(GREEN);
    printf("-------------------------------------------\n");
    printf("--------***REGISTRAR PRODUTO***-------------\n");
    printf("Digite o codigo do produto: ");
    printf(DEF_LETRA);
    scanf("%d", &ModuloProdutos->codigoDoProd);
    limpezaDoBuffer();
    printf(GREEN);
    printf("Digite o nome do produto: ");
    printf(DEF_LETRA);
    fgets(ModuloProdutos->nomeDoProd, 49, stdin);
    limpezaDoBuffer();
    printf(GREEN);
    printf("Digite a descrição do produto: ");
    printf(DEF_LETRA);
    fgets(ModuloProdutos->descricaoDoProd, 49, stdin);
    printf(GREEN);
    printf("Digite a data de fabricação do produto: \n");
    printf("DIA: ");
    printf(DEF_LETRA);
    scanf("%d", &ModuloProdutos->dataFabri.dia);
    printf(GREEN);
    printf("MêS: ");
    printf(DEF_LETRA);
    scanf("%d", &ModuloProdutos->dataFabri.mes);
    printf(GREEN);
    printf("ANO: ");
    printf(DEF_LETRA);
    scanf("%d", &ModuloProdutos->dataFabri.ano);
    printf(GREEN);
    printf("Digite o lote do produto: ");
    printf(DEF_LETRA);
    limpezaDoBuffer();
    fgets(ModuloProdutos->loteDoProd, 49, stdin);
    printf(GREEN);
    printf("Digite o preço do produto: ");
    printf(DEF_LETRA);
    scanf("%f", &ModuloProdutos->precoUnit);
    printf(GREEN);
    printf("Digite a quantidade de produtos que o estoque possui: ");
    printf(DEF_LETRA);
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
    printf("Produtos: \n");
    for(int i = 0; i < produtos.indice; i++){
        imprimeInfoProduto(produtos.listaDeProdutos[i]);
    }
}

void alterarProduto(ModuloProdutos* ModuloProdutos, TProdutos Produtos){
  int resposta = pesquisarProduto(*ModuloProdutos, Produtos);
  if(resposta == -1){
    printf(RED);
    limpezaDoBuffer();
    printf("\t Produto não encontrado. Retornando ao menu... \n");
    sleep(2);
    printf(DEF_LETRA);
    limparConsole();
    return;
  }
  printf(GREEN);
  limpezaDoBuffer();
  printf("Produto encontrado: %s, pressione ENTER para alterar ...\n", ModuloProdutos->listaDeProdutos[resposta].nomeDoProd);
  imprimeInfoProduto(ModuloProdutos->listaDeProdutos[resposta]);
  lerProduto(&ModuloProdutos->listaDeProdutos[resposta]);
  imprimeInfoProduto(ModuloProdutos->listaDeProdutos[resposta]);
  printf(DEF_LETRA);
}

void excluirProduto(ModuloProdutos* ModuloProdutos, TProdutos Produtos){
  int resposta = pesquisarProduto(*ModuloProdutos, Produtos);
  if(resposta == -1){
    printf(RED);
    limpezaDoBuffer();
    printf("\t Produto não encontrado. Retornando ao menu... \n");
    sleep(2);
    printf(DEF_LETRA);
    limparConsole();
    return;
  }
  printf(GREEN);
  limpezaDoBuffer();
  printf("Produto %s encontrado, pressione ENTER excluir ...\n", ModuloProdutos->listaDeProdutos[resposta].nomeDoProd);
  imprimeInfoProduto(ModuloProdutos->listaDeProdutos[resposta]);
  for (int j = resposta; j < ModuloProdutos->indice ; j++) {
      ModuloProdutos->listaDeProdutos[j] = ModuloProdutos->listaDeProdutos[j + 1];
  }
  ModuloProdutos->indice--;
  printf(GREEN);
  printf("Produto excluído com sucesso! \n");
  sleep(3);
}