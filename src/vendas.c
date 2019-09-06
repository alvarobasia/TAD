#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <unistd.h>
#include "vendas.h"

void imprimeVendas(ModuloVendas ModuloVendas){
    // puts("------INFORMAÇÕES DO PRODUTO---------\n");
    // printf("----Comprador----\n");
    // imprimeInfoCliente(ModuloClientes);
    // printf("----Produto-------\n");
    // imprimeInfoProduto(ModuloProdutos);
    printf("Codigo do produto comprado: ");
    printf("%d\n", ModuloVendas.vendasRealizadas[ModuloVendas.indice].codigo);
    // if(ModuloClientes.listaDeClientes[ModuloClientes.indice].tipoCliente == 0){
    //     printf("Comprador: Pessoa Fisica\n");
    //     printf("CPF: ");
    //     printf("%s\n", ModuloVendas.vendasRealizadas[ModuloVendas.indice].ID);
    // }
    // if(ModuloClientes.listaDeClientes[ModuloClientes.indice].tipoCliente == 1){
    //     printf("Comprador: Pessoa Jurídica\n");
    //     printf("CNPJ: ");
    //     printf("%s\n", ModuloVendas.vendasRealizadas[ModuloVendas.indice].ID);
    // }
    printf("Data da realização da venda: ");
    printf("%d / %d / %d\n", ModuloVendas.vendasRealizadas[ModuloVendas.indice].dataDaVenda.dia,
    ModuloVendas.vendasRealizadas[ModuloVendas.indice].dataDaVenda.mes, ModuloVendas.vendasRealizadas[ModuloVendas.indice].dataDaVenda.ano);
    if(ModuloVendas.vendasRealizadas[ModuloVendas.indice].tipoDePagamento == 1)
        printf("Tipo de pagamento: Á VISTA\n");
    if (ModuloVendas.vendasRealizadas[ModuloVendas.indice].tipoDePagamento == 2){
        printf("Tipo de pagamento: Á PRAZO\n");
        printf("Prazo para pagamento: ");
        printf("%d/ %d/ %d\n", ModuloVendas.vendasRealizadas[ModuloVendas.indice].prazoParaPagamento.dia,
        ModuloVendas.vendasRealizadas[ModuloVendas.indice].prazoParaPagamento.mes, ModuloVendas.vendasRealizadas[ModuloVendas.indice].prazoParaPagamento.ano);
    }
    printf("------------------------------------------\n");
}

int lerVendas(ModuloVendas *ModuloVendas, ModuloClientes* ModuloClientes, ModuloProdutos *ModuloProdutos){
    printf("-------------------------------------------\n");
    printf("--------***EFETUAR VENDA***-------------\n");
    TCliente cliente;
    TProdutos produto;
    int indiceProduto;
    int indiceCliente;
    int feedbackCliente;
    int feedbackProduto;
    printf("Digite o CPF/CNPJ do cliente \n");
    fgets(cliente.ID, 49, stdin);
    limpezaDoBuffer();
    feedbackCliente = pesquisarCliente(*ModuloClientes, cliente);
    if(feedbackCliente == -1){
        //limparConsole();
        printf("Saindo da função");
        //sleep(5);
        return -1;
    }
    if (ModuloClientes->listaDeClientes[feedbackCliente].debitoRegistrado == 1){
        printf("Cliente possui debito registrado\n");
        return -1;
    }
    printf("Digite o código do produto: \n");
    limpezaDoBuffer();
    scanf("%d", &produto.codigoDoProd);
    feedbackProduto = pesquisarProduto(*ModuloProdutos, produto);
    if(feedbackProduto == -1){
        limparConsole();
        printf("Saindo da função");
        return -1; 
    }
    if(ModuloProdutos->listaDeProdutos[feedbackProduto].quantidadeProd == 0){
        printf("Em falta!\n");
        return -1;
    }
    ModuloVendas->vendasRealizadas[ModuloVendas->indice].codigo = produto.codigoDoProd;
    strcpy(ModuloVendas->vendasRealizadas[ModuloVendas->indice].ID, cliente.ID );
    printf("Digite a data da realização da venda: \n");
    printf("DIA: ");
    scanf("%d", &ModuloVendas->vendasRealizadas[ModuloVendas->indice].dataDaVenda.dia);
    printf("MÊS: ");
    scanf("%d", &ModuloVendas->vendasRealizadas[ModuloVendas->indice].dataDaVenda.mes);
    printf("ANO: ");
       scanf("%d", &ModuloVendas->vendasRealizadas[ModuloVendas->indice].dataDaVenda.ano);
    printf("Digite o tipo de pagamento: 1 - vista 2- prazo \n");
    scanf("%d", &ModuloVendas->vendasRealizadas[ModuloVendas->indice].tipoDePagamento);
    if(ModuloVendas->vendasRealizadas[ModuloVendas->indice].tipoDePagamento == 2){
        printf("----------Á PRAZO-------------\n");
        printf("Digite o prazo da compra da compra: \n");
        printf("DIA: ");
        scanf("%d", &ModuloVendas->vendasRealizadas[ModuloVendas->indice].prazoParaPagamento.dia);
        printf("MÊS: ");
        scanf("%d", &ModuloVendas->vendasRealizadas[ModuloVendas->indice].prazoParaPagamento.mes);
        printf("ANO: ");
        scanf("%d", &ModuloVendas->vendasRealizadas[ModuloVendas->indice].prazoParaPagamento.mes);
        ModuloVendas->vendasRealizadas[ModuloVendas->indice].tipoDePagamento = 2;
        ModuloClientes->listaDeClientes[feedbackCliente].debitoRegistrado = 1;  
     }
    if(ModuloVendas->vendasRealizadas[ModuloVendas->indice].tipoDePagamento == 1){
       printf("----------Á VISTA-------------\n"); 
       ModuloVendas->vendasRealizadas[ModuloVendas->indice].tipoDePagamento = 1;
    }
    ModuloProdutos->listaDeProdutos[feedbackProduto].quantidadeProd--;
    return 0;
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