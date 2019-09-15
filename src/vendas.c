#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <unistd.h>
#include "vendas.h"
#include "menu.h"
void imprimeVendas(TVendas Vendas){
    limpezaDoBuffer();
    printf(AMA);
    printf("Codigo do produto comprado: ");
    printf("%d\n", Vendas.codigo);
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
    printf("------------------------------------------\n");
    printf(DEF_LETRA);
    printf("PRESSIONE ENTER PARA CONTINUAR!!!!");
    getchar();
}

int lerVendas(TVendas *Vendas,ModuloClientes* ModuloClientes, ModuloProdutos *ModuloProdutos){
    limparConsole();
    printf(GREEN);
    printf("-------------------------------------------\n");
    printf("--------***EFETUAR VENDA***-------------\n");
    TCliente cliente;
    TProdutos produto;
    int indiceProduto;
    int indiceCliente;
    int feedbackCliente;
    int feedbackProduto;
    printf("Digite o CPF/CNPJ do cliente \n");
    printf(DEF_LETRA);
    limpezaDoBuffer();
    fgets(cliente.ID, TAM, stdin);
    formatador(cliente.ID);
    feedbackCliente = pesquisarCliente(*ModuloClientes, cliente);
    if(feedbackCliente == -1){
        limparConsole();
        printf(RED);
        printf("Cliente não encontrado, saindo...\n");
        sleep(2);
        return -1;
    }
    if (ModuloClientes->listaDeClientes[feedbackCliente].debitoRegistrado == 1){
        printf(RED);
        printf("Cliente possui debito registrado!! Inpossível concluír venda!\n");
        sleep(2);
        return -1;
    }
    printf(GREEN);
    printf("Digite o código do produto: \n");
    limpezaDoBuffer();
    printf(DEF_LETRA);
    scanf("%d", &produto.codigoDoProd);
    feedbackProduto = pesquisarProduto(*ModuloProdutos, produto);
    if(feedbackProduto == -1){
        limparConsole();
        printf(RED);
        printf("Produto não encontrado, saindo...\n");
        sleep(2);
        return -1; 
    }
    if(ModuloProdutos->listaDeProdutos[feedbackProduto].quantidadeProd == 0){
        limparConsole();
        printf(RED);
        printf("produto em falta! Impossivel concluír venda!!\n");
        sleep(2);
        return -1;
    }
    Vendas->codigo = produto.codigoDoProd;
    strcpy(Vendas->ID, cliente.ID );
    printf(GREEN);
    printf("Digite a data da realização da venda: \n");
    printf("DIA: ");
    printf(DEF_LETRA);
    scanf("%d", &Vendas->dataDaVenda.dia);
    printf(GREEN);
    printf("MÊS: ");
    printf(DEF_LETRA);
    scanf("%d", &Vendas->dataDaVenda.mes);
    printf(GREEN);
    printf("ANO: ");
    printf(DEF_LETRA);
    scanf("%d", &Vendas->dataDaVenda.ano);
    printf(GREEN);
    printf("Digite o tipo de pagamento: 1 - vista 2- prazo \n");
    scanf("%d", &Vendas->tipoDePagamento);
    if(Vendas->tipoDePagamento == 2){
        printf(GREEN);
        printf("----------Á PRAZO-------------\n");
        printf("Digite o prazo da compra da compra: \n");
        printf("DIA: ");
        printf(DEF_LETRA);
        scanf("%d", &Vendas->prazoParaPagamento.dia);
        printf(GREEN);
        printf("MÊS: ");
        printf(DEF_LETRA);
        scanf("%d", &Vendas->prazoParaPagamento.mes);
        printf(GREEN);
        printf("ANO: ");
        printf(DEF_LETRA);
        scanf("%d", &Vendas->prazoParaPagamento.ano);
        Vendas->tipoDePagamento = 2;
        ModuloClientes->listaDeClientes[feedbackCliente].debitoRegistrado = 1;  
     }
    if(Vendas->tipoDePagamento == 1){
       printf(GREEN);
       printf("----------Á VISTA-------------\n"); 
       printf(DEF_LETRA);
       Vendas->tipoDePagamento = 1;
    }
    ModuloProdutos->listaDeProdutos[feedbackProduto].quantidadeProd--;
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

int pesquisarVendas(ModuloVendas ModuloVendas, ModuloProdutos ModuloProdutos, ModuloClientes ModuloClientes){
    printf("Digite o CPF/CNPJ do comprador: ");
    TCliente Cliente;
    fgets(Cliente.ID, TAM, stdin);
    int respostaCliente = pesquisarCliente(ModuloClientes, Cliente);
    if( respostaCliente == -1){
        printf("Cliente não encontrado");
        return -1;
    }
    TProdutos Produtos;
    printf("Digite o código do produto: ");
    scanf("%d", &Produtos.codigoDoProd);
    int respostaProdutos = pesquisarProduto(ModuloProdutos, Produtos);
    if( respostaProdutos == -1){
        printf("Produto  não encontrado");
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
    for(int i = 0; i < Vendas.indice; i++){
        imprimeVendas(Vendas.vendasRealizadas[i]);
    }
}

void alterarVenda(ModuloVendas* ModuloVendas, ModuloProdutos* ModuloProdutos, ModuloClientes* ModuloCliente){
    printf("Digite o CPF/CNPJ do comprador: ");
    TCliente Cliente;
    fgets(Cliente.ID, TAM, stdin);
    int respostaCliente = pesquisarCliente(*ModuloCliente, Cliente);
    if( respostaCliente == -1){
        printf("Cliente não encontrado");
        return;
    }
    TProdutos Produtos;
    printf("Digite o código do produto: ");
    scanf("%d", &Produtos.codigoDoProd);
    int respostaProdutos = pesquisarProduto(*ModuloProdutos, Produtos);
    if( respostaProdutos == -1){
        printf("Produto  não encontrado");
        return;
    }
    int respostaVendas = pesquisarVendas(*ModuloVendas, *ModuloProdutos, *ModuloCliente);
    if (respostaVendas == -1){
        printf("Venda não encontrada");
        return;
    }
    
    lerVendas(&ModuloVendas->vendasRealizadas[respostaVendas], ModuloCliente, ModuloProdutos);
}