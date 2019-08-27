#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include "vendas.h"

void imprimeVendas(ModuloVendas ModuloVendas, ModuloClientes ModuloClientes, ModuloProdutos ModuloProdutos,  
int indice, int indiceProduto, int indiceCLiente){
    puts("------INFORMAÇÕES DO PRODUTO---------\n");
    printf("----Comprador----\n");
    imprimeInfoCliente(ModuloClientes, indiceCLiente);
    printf("----Produto-------\n");
    imprimeInfoProduto(ModuloProdutos, indiceProduto);
    printf("Codigo do produto comprado: ");
    printf("%d\n", ModuloVendas.vendasRealizadas[indice].codigo);
    if(ModuloClientes.listaDeClientes[indiceCLiente].tipoCliente == 0){
        printf("Comprador: Pessoa Fisica\n");
        printf("CPF: ");
        printf("%s\n", ModuloVendas.vendasRealizadas[indice].ID);
    }
    if(ModuloClientes.listaDeClientes[indiceCLiente].tipoCliente == 1){
        printf("Comprador: Pessoa Jurídica\n");
        printf("CNPJ: ");
        printf("%s\n", ModuloVendas.vendasRealizadas[indice].ID);
    }
    printf("Data da realização da venda: ");
    printf("%d / %d / %d\n", ModuloVendas.vendasRealizadas[indice].dataDaVenda.dia,
    ModuloVendas.vendasRealizadas[indice].dataDaVenda.mes, ModuloVendas.vendasRealizadas[indice].dataDaVenda.ano);
    if(ModuloVendas.vendasRealizadas[indice].tipoDePagamento == 1)
        printf("Tipo de pagamento: Á VISTA\n");
    if (ModuloVendas.vendasRealizadas[indice].tipoDePagamento == 2){
        printf("Tipo de pagamento: Á PRAZO\n");
        printf("Prazo para pagamento: ");
        printf("%d/ %d/ %d\n", ModuloVendas.vendasRealizadas[indice].prazoParaPagamento.dia,
        ModuloVendas.vendasRealizadas[indice].prazoParaPagamento.mes, ModuloVendas.vendasRealizadas[indice].prazoParaPagamento.ano);
    }
    printf("------------------------------------------\n");
}

TProdutos* buscarProduto (int codigo, ModuloProdutos *ModuloProdutos, int* indice){
    for (int i = 0; i <= ModuloProdutos->indice; i++){
       if(codigo == ModuloProdutos->listaDeProdutos[i].codigoDoProd){
           *indice = i;
           return &ModuloProdutos->listaDeProdutos[i];
           break;
       }     
    }
}
    

TCliente* buscarCliente (char ID[], ModuloClientes *ModuloClientes, int* indice){
    for (int i = 0; i <= ModuloClientes->indice; i++){
       if(strncmp(ID, ModuloClientes->listaDeClientes[i].ID, TAM) == 0){
           *indice = i;
           return &ModuloClientes->listaDeClientes[i];
           break;
       }     
    }
    return NULL;
}

void lerVendas(ModuloVendas *ModuloVendas, ModuloClientes* ModuloClientes, ModuloProdutos* ModuloProdutos){
    limparConsole();
    int indice = 0;
    int codigo;
    char ID[TAM];
    int resposta = 1;
    while(1){
        printf("-------------------------------------------\n");
        printf("--------***EFETUAR VENDA***-------------\n");
        TCliente* cliente;
        TProdutos* produto;
        int indiceProduto;
        int indiceCliente;
        printf("Digite o CPF/CNPJ do cliente \n");
        fgets(ID, 49, stdin);
        limpezaDoBuffer();
        cliente = buscarCliente(ID, ModuloClientes, &indiceCliente);
        if(cliente == NULL){
            printf("Cliente inexistente\n");
            break;
        }
        if (cliente->debitoRegistrado == 1){
            printf("Cliente possui debito registrado\n");
            break;
        }
        printf("Digite o código do produto: \n");
        limpezaDoBuffer();
        scanf("%d", &codigo);
        produto = buscarProduto(codigo, ModuloProdutos, &indiceProduto);
        if(produto == NULL){
            printf("Produto inexistente\n");
            break;
        }
        if(produto->quantidadeProd == 0){
            printf("Em falta!\n");
            break;
        }
        ModuloVendas->vendasRealizadas[indice].codigo = produto->codigoDoProd;
        strcpy(ModuloVendas->vendasRealizadas[indice].ID, cliente->ID );
        printf("Digite a data da realização da venda: \n");
        printf("DIA: ");
        scanf("%d", &ModuloVendas->vendasRealizadas[indice].dataDaVenda.dia);
        printf("MÊS: ");
        scanf("%d", &ModuloVendas->vendasRealizadas[indice].dataDaVenda.mes);
        printf("ANO: ");
        scanf("%d", &ModuloVendas->vendasRealizadas[indice].dataDaVenda.ano);
        printf("Digite o tipo de pagamento: 1 - vista 2- prazo \n");
        scanf("%d", &ModuloVendas->vendasRealizadas[indice].tipoDePagamento);
        if(ModuloVendas->vendasRealizadas[indice].tipoDePagamento == 2){
            printf("----------Á PRAZO-------------\n");
            printf("Digite o prazo da compra da compra: \n");
            printf("DIA: ");
            scanf("%d", &ModuloVendas->vendasRealizadas[indice].prazoParaPagamento.dia);
            printf("MÊS: ");
            scanf("%d", &ModuloVendas->vendasRealizadas[indice].prazoParaPagamento.mes);
            printf("ANO: ");
            scanf("%d", &ModuloVendas->vendasRealizadas[indice].prazoParaPagamento.mes);
            ModuloVendas->vendasRealizadas[indice].tipoDePagamento = 2;
            cliente->debitoRegistrado = 1;  
        }
        if(ModuloVendas->vendasRealizadas[indice].tipoDePagamento == 1){
           printf("----------Á VISTA-------------\n"); 
           ModuloVendas->vendasRealizadas[indice].tipoDePagamento = 1;
        }
        limparConsole();
        imprimeVendas(*ModuloVendas, *ModuloClientes, *ModuloProdutos, indice,
        indiceProduto, indiceCliente);
        printf("Deseja realizar outra compra? 1 - sim , 2 - não \n");
        scanf("%d", &resposta);
        limpezaDoBuffer();
        if(resposta == 1)
            indice++;
        if(resposta == 2)
            ModuloVendas->indice += indice;
            break;
    }
      
}
