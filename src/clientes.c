#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include "clientes.h"



void imprimeInfoCliente(ModuloClientes modulo, int indice){
    puts("------INFORMAÇÕES DO CLIENTE---------");
    printf("1- NOME- %s\n", modulo.listaDeClientes[indice].nome);
    printf("2- Nasc/Criação - %d / %d / %d\n",modulo.listaDeClientes[indice].dataDeNascimento.dia,
    modulo.listaDeClientes[indice].dataDeNascimento.mes,modulo.listaDeClientes[indice].dataDeNascimento.ano);
    printf("3- -Endereço-\n");
    printf("3-a) Cidade: %s\n",modulo.listaDeClientes[indice].enderecoCompleto.cidade);
    printf("3-b) Bairro: %s\n",modulo.listaDeClientes[indice].enderecoCompleto.bairro);
    printf("3-c) Rua: %s\n",modulo.listaDeClientes[indice].enderecoCompleto.rua);
    printf("3-d) CEP: %s\n",modulo.listaDeClientes[indice].enderecoCompleto.cep);
    printf("3-e) Número: %d\n",modulo.listaDeClientes[indice].enderecoCompleto.numero);
    printf("4- Débido registrado? ");
    if(modulo.listaDeClientes[indice].debitoRegistrado == 0)
        printf("NÃO\n");
    if(modulo.listaDeClientes[indice].debitoRegistrado == 1)
        printf("SIM\n");
    printf("5- Tipo de cliente ");
    if(modulo.listaDeClientes[indice].tipoCliente == 0){
        printf("Pessoa Física\n");
        printf("7- CPF: ");
        printf("%s\n", modulo.listaDeClientes[indice].ID);
        printf("6- RG: ");
        printf("%s\n", modulo.listaDeClientes[indice].identidade);
    }
    if(modulo.listaDeClientes[indice].tipoCliente == 1){
        printf("Pessoa Jurídica\n");
        printf("6- CNPJ: ");
        printf("%s\n", modulo.listaDeClientes[indice].ID);
    }
    printf("---------------------------------------\n");
}

void lerCliente(ModuloClientes *ModuloClientes){
    FILE *arquivoCliente;
    limparConsole();
    int resposta = 1;
    int indice  = 0;
    arquivoCliente = fopen("clientes.txt", "a");
    while(1){
        printf("-------------------------------------------\n");
        printf("--------***REGISTRAR CLIENTE***-------------\n");
        printf("Digite o nome do cliente: \n");
        fgets(ModuloClientes->listaDeClientes[indice].nome, 49, stdin);
        fprintf(arquivoCliente, "Nome do cliente : %s\n", ModuloClientes->listaDeClientes[indice].nome );
        printf("Digite a data de nascimento/Criação\n");
        printf("DIA: ");
        scanf("%d", &ModuloClientes->listaDeClientes[indice].dataDeNascimento.dia);
        printf("MÊS: ");
        scanf("%d", &ModuloClientes->listaDeClientes[indice].dataDeNascimento.mes);
        printf("ANO: ");
        scanf("%d", &ModuloClientes->listaDeClientes[indice].dataDeNascimento.ano);
        fprintf(arquivoCliente, "Data de nascimento: %d/ %d/%d \n", ModuloClientes->listaDeClientes[indice].dataDeNascimento.dia,
        ModuloClientes->listaDeClientes[indice].dataDeNascimento.mes, ModuloClientes->listaDeClientes[indice].dataDeNascimento.ano);
        limpezaDoBuffer();
        printf("Digite o endereço do cliente: \n");
        printf("CIDADE: ");
        limpezaDoBuffer();
        fgets(ModuloClientes->listaDeClientes[indice].enderecoCompleto.cidade,49,stdin);
        printf("BAIRRO: ");
        limpezaDoBuffer();
        fgets(ModuloClientes->listaDeClientes[indice].enderecoCompleto.bairro,49,stdin);
        printf("RUA: ");
        limpezaDoBuffer();
        fgets(ModuloClientes->listaDeClientes[indice].enderecoCompleto.rua, 49,stdin);
        printf("CEP: ");
        limpezaDoBuffer();
        fgets(ModuloClientes->listaDeClientes[indice].enderecoCompleto.cep, 49 , stdin);
        printf("NÚMERO: ");
        scanf("%d", &ModuloClientes->listaDeClientes[indice].enderecoCompleto.numero);
        fprintf(arquivoCliente, "Endereço: Cidade %s Bairro: %s rua: %s CEP: %s numero: %d\n",ModuloClientes->listaDeClientes[indice].enderecoCompleto.cidade,
         ModuloClientes->listaDeClientes[indice].enderecoCompleto.bairro,ModuloClientes->listaDeClientes[indice].enderecoCompleto.rua,
         ModuloClientes->listaDeClientes[indice].enderecoCompleto.cep, ModuloClientes->listaDeClientes[indice].enderecoCompleto.numero);
        printf("Possui debido registrado? 0-não 1 - sim \n");
        scanf("%hd", &ModuloClientes->listaDeClientes[indice].debitoRegistrado);
        if(ModuloClientes->listaDeClientes[indice].debitoRegistrado == 0){
            fprintf(arquivoCliente, "Não possui debito\n");
        }else{
            fprintf(arquivoCliente, "Possui\n");
        }
        
        printf("-------------------------------------------\n");
        printf("--------Digite o tipo do clinte-------------\n");
        printf("|0|-FISICO                     |1|-JURIDICO  \n");
        scanf("%hd", &ModuloClientes->listaDeClientes[indice].tipoCliente);
        if(ModuloClientes->listaDeClientes[indice].tipoCliente == 0){
            printf("VOCÊ SELECIONOU PESSOA FISICA!!\n");
            fprintf(arquivoCliente, "PESSOA FISICA \n");
            printf("Digite o RG do cliente: \n");
            limpezaDoBuffer();
            fgets(ModuloClientes->listaDeClientes[indice].identidade, 49, stdin);
            fprintf(arquivoCliente, "RG: %s\n",ModuloClientes->listaDeClientes[indice].identidade );
            printf("Digite o CPF do clitente \n");
            limpezaDoBuffer();
            fgets(ModuloClientes->listaDeClientes[indice].ID, 49 , stdin);
            fprintf(arquivoCliente, "CPF: %s\n", ModuloClientes->listaDeClientes[indice].ID );
        }
        if(ModuloClientes->listaDeClientes[indice].tipoCliente == 1){
            printf("VOCÊ SELECIONOU PESSOA JURIDICA!!\n");
            fprintf(arquivoCliente, "PESSOA JURIDICA \n");
            printf("Digite o CNPJ do clitente \n");
            limpezaDoBuffer();
            fgets(ModuloClientes->listaDeClientes[indice].ID, 49, stdin);
            fprintf(arquivoCliente, "CNPJ: %s\n", ModuloClientes->listaDeClientes[indice].ID );
        }
        limparConsole();
        imprimeInfoCliente(*ModuloClientes, indice);
        limpezaDoBuffer();
        printf("DESEJA REGISTRAR UM NOVO CLIENTE? 1-sim 2 - não \n");
        scanf("%d", &resposta);
        limpezaDoBuffer();
        if(resposta == 1){
            fprintf(arquivoCliente, "--------------------------\n");
            indice++;
        }else{
            fclose(arquivoCliente);
            ModuloClientes->indice += indice;
            break;
        }
    }
}
