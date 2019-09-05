#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include "clientes.h"



void imprimeInfoCliente(ModuloClientes modulo){
    puts("------INFORMAÇÕES DO CLIENTE---------");
    printf("1- NOME- %s\n", modulo.listaDeClientes[modulo.indice].nome);
    printf("2- Nasc/Criação - %d / %d / %d\n",modulo.listaDeClientes[modulo.indice].dataDeNascimento.dia,
    modulo.listaDeClientes[modulo.indice].dataDeNascimento.mes,modulo.listaDeClientes[modulo.indice].dataDeNascimento.ano);
    printf("3- -Endereço-\n");
    printf("3-a) Cidade: %s\n",modulo.listaDeClientes[modulo.indice].enderecoCompleto.cidade);
    printf("3-b) Bairro: %s\n",modulo.listaDeClientes[modulo.indice].enderecoCompleto.bairro);
    printf("3-c) Rua: %s\n",modulo.listaDeClientes[modulo.indice].enderecoCompleto.rua);
    printf("3-d) CEP: %s\n",modulo.listaDeClientes[modulo.indice].enderecoCompleto.cep);
    printf("3-e) Número: %d\n",modulo.listaDeClientes[modulo.indice].enderecoCompleto.numero);
    printf("4- Débido registrado? ");
    if(modulo.listaDeClientes[modulo.indice].debitoRegistrado == 0)
        printf("NÃO\n");
    if(modulo.listaDeClientes[modulo.indice].debitoRegistrado == 1)
        printf("SIM\n");
    printf("5- Tipo de cliente ");
    if(modulo.listaDeClientes[modulo.indice].tipoCliente == 0){
        printf("Pessoa Física\n");
        printf("7- CPF: ");
        printf("%s\n", modulo.listaDeClientes[modulo.indice].ID);
        printf("6- RG: ");
        printf("%s\n", modulo.listaDeClientes[modulo.indice].identidade);
    }
    if(modulo.listaDeClientes[modulo.indice].tipoCliente == 1){
        printf("Pessoa Jurídica\n");
        printf("6- CNPJ: ");
        printf("%s\n", modulo.listaDeClientes[modulo.indice].ID);
    }
    printf("---------------------------------------\n");
}

void lerCliente(ModuloClientes *ModuloClientes){
    FILE *arquivoCliente;
    limparConsole();
    arquivoCliente = fopen("clientes.txt", "a");
    printf("-------------------------------------------\n");
    printf("--------***REGISTRAR CLIENTE***-------------\n");
    printf("Digite o nome do cliente: \n");
    fgets(ModuloClientes->listaDeClientes[ModuloClientes->indice].nome, 49, stdin);
    fprintf(arquivoCliente, "Nome do cliente : %s\n", ModuloClientes->listaDeClientes[ModuloClientes->indice].nome );
    printf("Digite a data de nascimento/Criação\n");
    printf("DIA: ");
    scanf("%d", &ModuloClientes->listaDeClientes[ModuloClientes->indice].dataDeNascimento.dia);
    printf("MÊS: ");
    scanf("%d", &ModuloClientes->listaDeClientes[ModuloClientes->indice].dataDeNascimento.mes);
    printf("ANO: ");
    scanf("%d", &ModuloClientes->listaDeClientes[ModuloClientes->indice].dataDeNascimento.ano);
    fprintf(arquivoCliente, "Data de nascimento: %d/ %d/%d \n", ModuloClientes->listaDeClientes[ModuloClientes->indice].dataDeNascimento.dia,
    ModuloClientes->listaDeClientes[ModuloClientes->indice].dataDeNascimento.mes, ModuloClientes->listaDeClientes[ModuloClientes->indice].dataDeNascimento.ano);
    limpezaDoBuffer();
    printf("Digite o endereço do cliente: \n");
    printf("CIDADE: ");
    limpezaDoBuffer();
    fgets(ModuloClientes->listaDeClientes[ModuloClientes->indice].enderecoCompleto.cidade,49,stdin);
    printf("BAIRRO: ");
    limpezaDoBuffer();
    fgets(ModuloClientes->listaDeClientes[ModuloClientes->indice].enderecoCompleto.bairro,49,stdin);
    printf("RUA: ");
    limpezaDoBuffer();
    fgets(ModuloClientes->listaDeClientes[ModuloClientes->indice].enderecoCompleto.rua, 49,stdin);
    printf("CEP: ");
    limpezaDoBuffer();
    fgets(ModuloClientes->listaDeClientes[ModuloClientes->indice].enderecoCompleto.cep, 49 , stdin);
    printf("NÚMERO: ");
    scanf("%d", &ModuloClientes->listaDeClientes[ModuloClientes->indice].enderecoCompleto.numero);
    fprintf(arquivoCliente, "Endereço: Cidade %s Bairro: %s rua: %s CEP: %s numero: %d\n",ModuloClientes->listaDeClientes[ModuloClientes->indice].enderecoCompleto.cidade,
     ModuloClientes->listaDeClientes[ModuloClientes->indice].enderecoCompleto.bairro,ModuloClientes->listaDeClientes[ModuloClientes->indice].enderecoCompleto.rua,
     ModuloClientes->listaDeClientes[ModuloClientes->indice].enderecoCompleto.cep, ModuloClientes->listaDeClientes[ModuloClientes->indice].enderecoCompleto.numero);
    printf("Possui debido registrado? 0-não 1 - sim \n");
    scanf("%hd", &ModuloClientes->listaDeClientes[ModuloClientes->indice].debitoRegistrado);
    if(ModuloClientes->listaDeClientes[ModuloClientes->indice].debitoRegistrado == 0){
        fprintf(arquivoCliente, "Não possui debito\n");
    }else{
         fprintf(arquivoCliente, "Possui\n");
    }
    
    printf("-------------------------------------------\n");
    printf("--------Digite o tipo do clinte-------------\n");
    printf("|0|-FISICO                     |1|-JURIDICO  \n");
    scanf("%hd", &ModuloClientes->listaDeClientes[ModuloClientes->indice].tipoCliente);
    if(ModuloClientes->listaDeClientes[ModuloClientes->indice].tipoCliente == 0){
        printf("VOCÊ SELECIONOU PESSOA FISICA!!\n");
        fprintf(arquivoCliente, "PESSOA FISICA \n");
        printf("Digite o RG do cliente: \n");
        limpezaDoBuffer();
        fgets(ModuloClientes->listaDeClientes[ModuloClientes->indice].identidade, 49, stdin);
        fprintf(arquivoCliente, "RG: %s\n",ModuloClientes->listaDeClientes[ModuloClientes->indice].identidade );
        printf("Digite o CPF do clitente \n");
        limpezaDoBuffer();
        fgets(ModuloClientes->listaDeClientes[ModuloClientes->indice].ID, 49 , stdin);
        fprintf(arquivoCliente, "CPF: %s\n", ModuloClientes->listaDeClientes[ModuloClientes->indice].ID );
    }
    if(ModuloClientes->listaDeClientes[ModuloClientes->indice].tipoCliente == 1){
        printf("VOCÊ SELECIONOU PESSOA JURIDICA!!\n");
        fprintf(arquivoCliente, "PESSOA JURIDICA \n");
        printf("Digite o CNPJ do clitente \n");
        limpezaDoBuffer();
        fgets(ModuloClientes->listaDeClientes[ModuloClientes->indice].ID, 49, stdin);
        fprintf(arquivoCliente, "CNPJ: %s\n", ModuloClientes->listaDeClientes[ModuloClientes->indice].ID );
    }
        limparConsole();
        //imprimeInfoCliente(*ModuloClientes);
        limpezaDoBuffer();
}

void iniciarModuloCliente(ModuloClientes *ModuloClientes){
    ModuloClientes->indice = 0;
}

void inserirCliente(ModuloClientes *ModuloClientes, TCliente Cliente){
    if(ModuloClientes->indice < TAM){
        ModuloClientes->listaDeClientes[ModuloClientes->indice] = Cliente;
        ModuloClientes->indice++;
    }
}

int pesquisarCliente(ModuloClientes ModuloClientes, TCliente Cliente){
    for(int i = 0; i < ModuloClientes.indice; i++){
        if(strncmp(Cliente.ID, ModuloClientes.listaDeClientes[i].ID, TAM) == 0){
            printf("Cliente encontrado!");
            return i;
        }
    }
    printf("Cliente inexistente!");
    return -1;
}