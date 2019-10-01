#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <unistd.h> 
#include "clientes.h"
#include "menu.h"

void produtoMaisVendido(ModuloVendas Vendas, ModuloProdutos Produtos){
  int max, qtd=0, cod;
  TProdutos prod;
  for (int i = 0; i < Vendas.indice; i++){
    qtd = 0;
    for (int j = i + 1 ; j < Vendas.indice; j++){
      if(Vendas.vendasRealizadas[i].codigo == Vendas.vendasRealizadas[j].codigo){
          qtd += Vendas.vendasRealizadas[i].quantidadeDeVendas;
      }
      if(i == 0){
        max = qtd;
        cod = Vendas.vendasRealizadas[i].codigo;
      }else{
        if(qtd > max){
          max = qtd;
          cod = Vendas.vendasRealizadas[i].codigo;
        }
      }
    }
  }
  prod.codigoDoProd = cod;
  int resposta = pesquisarProduto(Produtos, prod);
  imprimeInfoProduto(Produtos.listaDeProdutos[resposta]);
}

void vendasAVista(ModuloVendas vendas){
  int qtd = 0;
  float preco = 0;
  for (int i = 0; i < vendas.indice; i++)
  {
    if(vendas.vendasRealizadas[i].tipoDePagamento == 1){
      qtd++;
      preco += vendas.vendasRealizadas[i].precoDaVenda;
    }
  }
  limparConsole();
  printf("Número de Vendas: %d Total: %f", qtd, preco);
  
}

void clientesIguais(ModuloVendas vendas, TCliente c1, TCliente c2, ModuloProdutos Produtos){
    int cod;
    TProdutos prod;
    for (int i = 0; i < vendas.indice; i++)
    {
      if(strncmp(c1.ID, vendas.vendasRealizadas[i].ID, TAM) == 0){
        cod = vendas.vendasRealizadas[i].codigo;
        for (int j = 0; j < vendas.indice; j++){
          if(strncmp(c2.ID, vendas.vendasRealizadas[j].ID, TAM) == 0 && vendas.vendasRealizadas[j].codigo == cod){
            prod.codigoDoProd = cod;
            int z = pesquisarProduto(Produtos, prod);
            imprimeInfoProduto(Produtos.listaDeProdutos[z]);
          }
        } 
      }
    }
    
}

void NotaFiscal(ModuloVendas Vendas, TCliente Cliente, TData data){
  float total=0;
  for(int i =0; i < Vendas.indice; i++){
    if(strncmp(Cliente.ID, Vendas.vendasRealizadas[i].ID, TAM) == 0 
    && Vendas.vendasRealizadas[i].dataDaVenda.dia == data.dia
    && Vendas.vendasRealizadas[i].dataDaVenda.mes == data.mes
    && Vendas.vendasRealizadas[i].dataDaVenda.ano == data.ano)
    total += Vendas.vendasRealizadas[i].precoDaVenda;
  }
  for(int i =0; i < Vendas.indice; i++){
    if(strncmp(Cliente.ID, Vendas.vendasRealizadas[i].ID, TAM) == 0 
    && Vendas.vendasRealizadas[i].dataDaVenda.dia == data.dia
    && Vendas.vendasRealizadas[i].dataDaVenda.mes == data.mes
    && Vendas.vendasRealizadas[i].dataDaVenda.ano == data.ano)
    imprimeVendas(Vendas.vendasRealizadas[i]);
  }
  printf("\t %f \n", total);
  printf("DIGITE ENTER PARA CONTINUAR");
  limpezaDoBuffer();
  getchar();
}
