#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <unistd.h>
#include "vendas.h"
#include "menu.h"
void imprimeVendas(TVendas Vendas){
    limpezaDoBuffer();
    printf("\nCodigo do produto comprado: ");
    printf("%d\n", Vendas.codigo);
    printf("\nCLiente: ");
    printf("%s\n", Vendas.ID);
    printf("Data da realização da venda: ");
    printf("%d / %d / %d\n", Vendas.dataDaVenda.dia,
    Vendas.dataDaVenda.mes, Vendas.dataDaVenda.ano);
    if(Vendas.tipoDePagamento == 1)
        printf("Tipo de pagamento: Á VISTA\n");
    if (Vendas.tipoDePagamento == 2){
        printf("Tipo de pagamento: Á PRAZO\n");
        printf("Prazo para pagamento: ");
        printf("%d/ %d/ %d\n", Vendas.prazoParaPagamento.dia,
        Vendas.prazoParaPagamento.mes, Vendas.prazoParaPagamento.ano);
    }
    printf("Quantidade da venda: ");
    printf("%d", Vendas.quantidadeDeVendas);
    printf("\n Preço da venda: ");
    printf("%f", Vendas.precoDaVenda);
    printf("------------------------------------------\n");
    printf("PRESSIONE ENTER PARA CONTINUAR!!!!");
    getchar();
}

int lerVendas(TVendas *Vendas,ModuloClientes* ModuloClientes, ModuloProdutos *ModuloProdutos){
    limparConsole();
    printf("-------------------------------------------\n");
    printf("--------***EFETUAR VENDA***-------------\n");
    TCliente cliente;
    TProdutos produto;
    int indiceProduto;
    int indiceCliente;
    int feedbackCliente;
    int feedbackProduto;
    printf("Digite o CPF/CNPJ do cliente: ");
    limpezaDoBuffer();
    fgets(cliente.ID, TAM, stdin);
    formatador(cliente.ID);
    feedbackCliente = pesquisarCliente(*ModuloClientes, cliente);
    if(feedbackCliente == -1){
        limparConsole();
        limpezaDoBuffer();
        printf("Cliente não encontrado, saindo...\n");
        printf("PRESSIONE ENTER PARA CONTINUAR\n");
        getchar();
        return -1;
    }
    printf("Digite o código do produto: ");
    limpezaDoBuffer();
    scanf("%d", &produto.codigoDoProd);
    feedbackProduto = pesquisarProduto(*ModuloProdutos, produto);
    if(feedbackProduto == -1){
        limparConsole();
        limpezaDoBuffer();
        printf("Produto não encontrado, saindo...\n");
        printf("PRESSIONE ENTER PARA CONTINUAR\n");
        getchar();
        return -1; 
    }
    if(ModuloProdutos->listaDeProdutos[feedbackProduto].quantidadeProd == 0){
        limparConsole();
        limpezaDoBuffer();
        printf("produto em falta! Impossivel concluír venda!!\n");
        printf("PRESSIONE ENTER PARA CONTINUAR\n");
        getchar();
        return -1;
    }
    Vendas->codigo = produto.codigoDoProd;
    strcpy(Vendas->ID, cliente.ID );
    printf("Digite a data da realização da venda: \n");
    printf("DIA: ");
    scanf("%d", &Vendas->dataDaVenda.dia);
    printf("MÊS: ");
    scanf("%d", &Vendas->dataDaVenda.mes);
    printf("ANO: ");
    scanf("%d", &Vendas->dataDaVenda.ano);
    printf("Digite o tipo de pagamento: 1 - vista 2- prazo \n");
    scanf("%d", &Vendas->tipoDePagamento);
    if(Vendas->tipoDePagamento == 2){
        printf("----------Á PRAZO-------------\n");
        printf("Digite o prazo da compra da compra: \n");
        printf("DIA: ");
        scanf("%d", &Vendas->prazoParaPagamento.dia);
        printf("MÊS: ");
        scanf("%d", &Vendas->prazoParaPagamento.mes);
        printf("ANO: ");
        scanf("%d", &Vendas->prazoParaPagamento.ano);
        Vendas->tipoDePagamento = 2;
        ModuloClientes->listaDeClientes[feedbackCliente].debitoRegistrado = 1;  
     }
    if(Vendas->tipoDePagamento == 1){
       printf("----------Á VISTA-------------\n"); 
       Vendas->tipoDePagamento = 1;
    }
    printf("Digite a quantidade de produtos que deseja comprar: \n");
    scanf("%d", &Vendas->quantidadeDeVendas);
    ModuloProdutos->listaDeProdutos[feedbackProduto].quantidadeProd--;
    Vendas->precoDaVenda=ModuloProdutos->listaDeProdutos[feedbackProduto].precoUnit * Vendas->quantidadeDeVendas;
    return 0;
    limparConsole();
}

void iniciarModuloVendas(ModuloVendas *ModuloVendas){
    ModuloVendas->indice = 0;
}

void inserirVendas(ModuloVendas *ModuloVendas, TVendas Vendas){
    if(ModuloVendas->indice < TAM){
        ModuloVendas->vendasRealizadas[ModuloVendas->indice] = Vendas;
        ModuloVendas->indice++;
    }
}

int pesquisarVendas(ModuloVendas ModuloVendas, ModuloProdutos ModuloProdutos, ModuloClientes ModuloClientes, 
TCliente Cliente, TProdutos Produtos){
    int respostaCliente = pesquisarCliente(ModuloClientes, Cliente);
    if( respostaCliente == -1){
        printf("Cliente não encontrado\n");
        return -1;
    }
    int respostaProdutos = pesquisarProduto(ModuloProdutos, Produtos);
    if( respostaProdutos == -1){
        printf("Produto  não encontrado\n");
        return -1;
    }
    for ( int i = 0; i < ModuloVendas.indice; i++){
        if((strncmp(Cliente.ID, ModuloVendas.vendasRealizadas[i].ID, TAM) == 0) 
        && ModuloVendas.vendasRealizadas[i].codigo == Produtos.codigoDoProd){
            printf("Venda encontrada");
            return i;
        }
    }
    printf("Venda não encontrada");
    return -1;
}


void imprimirTodasAsVendas(ModuloVendas Vendas){
    limparConsole();
    printf("Vendas: \n");
    for(int i = 0; i < Vendas.indice; i++){
        imprimeVendas(Vendas.vendasRealizadas[i]);
    }
    limpezaDoBuffer();
}

void alterarVenda(ModuloVendas* ModuloVendas, ModuloProdutos* ModuloProdutos, ModuloClientes* ModuloCliente, TCliente cliente,
TProdutos produtos){
    limparConsole();
    int respostaVendas = pesquisarVendas(*ModuloVendas, *ModuloProdutos, *ModuloCliente, cliente, produtos);
    int respostaProdutos = pesquisarProduto(*ModuloProdutos, produtos);
    int respostaClientes = pesquisarCliente(*ModuloCliente, cliente);
    ModuloProdutos->listaDeProdutos[respostaProdutos].quantidadeProd++;
    ModuloCliente->listaDeClientes[respostaClientes].debitoRegistrado == 0;
    lerVendas(&ModuloVendas->vendasRealizadas[respostaVendas], ModuloCliente, ModuloProdutos);
    imprimeVendas(ModuloVendas->vendasRealizadas[respostaVendas]);
}

void excluirVendas(ModuloVendas* ModuloVendas, ModuloClientes* ModuloClientes, ModuloProdutos* Produtos, TCliente cliente,
TProdutos produtos){
  int resposta = pesquisarVendas(*ModuloVendas, *Produtos, *ModuloClientes, cliente, produtos);
  for (int j = resposta; j < ModuloVendas->indice ; j++) {
      ModuloVendas->vendasRealizadas[j] = ModuloVendas->vendasRealizadas[j + 1];
  }
  int respostaProdutos = pesquisarProduto(*Produtos, produtos);
  int respostaClientes = pesquisarCliente(*ModuloClientes, cliente);
  Produtos->listaDeProdutos[respostaProdutos].quantidadeProd++;
  ModuloClientes->listaDeClientes[respostaClientes].debitoRegistrado == 0;
  ModuloVendas->indice--;
  printf("Venda excluída com sucesso! \n");
  limpezaDoBuffer();
  printf("PRESSIONE ENTER PARA CONTINUAR\n");
  getchar();
}
