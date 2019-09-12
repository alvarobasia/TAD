#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include "clientes.h"

void imprimeInfoCliente(TCliente modulo){
    puts("------INFORMA��ES DO CLIENTE---------");
    printf("1- NOME- %s\n", modulo.nome);
    printf("2- Nasc/Cria��o - %d / %d / %d\n",modulo.dataDeNascimento.dia, modulo.dataDeNascimento.mes,
    modulo.dataDeNascimento.ano);
    printf("3- -Endere�o-\n");
    printf("3-a) Cidade: %s\n",modulo.enderecoCompleto.cidade);
    printf("3-b) Bairro: %s\n",modulo.enderecoCompleto.bairro);
    printf("3-c) Rua: %s\n",modulo.enderecoCompleto.rua);
    printf("3-d) CEP: %s\n",modulo.enderecoCompleto.cep);
    printf("3-e) N�mero: %d\n",modulo.enderecoCompleto.numero);
    printf("4- D�bido registrado? ");
    if(modulo.debitoRegistrado == 0)
        printf("N�O\n");
    if(modulo.debitoRegistrado == 1)
        printf("SIM\n");
    printf("5- Tipo de cliente ");
    if(modulo.tipoCliente == 0){
        printf("Pessoa F�sica\n");
        printf("7- CPF: ");
        printf("%s\n", modulo.ID);
        printf("6- RG: ");
        printf("%s\n", modulo.identidade);
    }
    if(modulo.tipoCliente == 1){
        printf("Pessoa Jur�dica\n");
        printf("6- CNPJ: ");
        printf("%s\n", modulo.ID);
    }
    printf("---------------------------------------\n");
}

void lerCliente(TCliente *ModuloClientes){
    limparConsole();
    printf("-------------------------------------------\n");
    printf("--------***REGISTRAR CLIENTE***-------------\n");
    printf("Digite o nome do cliente: \n");
    fgets(ModuloClientes->nome, 49, stdin);
    formatador(ModuloClientes->nome);
    printf("Digite a data de nascimento/Cria��o\n");
    printf("DIA: ");
    scanf("%d", &ModuloClientes->dataDeNascimento.dia);
    printf("M�S: ");
    scanf("%d", &ModuloClientes->dataDeNascimento.mes);
    printf("ANO: ");
    scanf("%d", &ModuloClientes->dataDeNascimento.ano);
    limpezaDoBuffer();
    printf("Digite o endere�o do cliente: \n");
    printf("CIDADE: ");
    limpezaDoBuffer();
    fgets(ModuloClientes->enderecoCompleto.cidade,49,stdin);
    formatador(ModuloClientes->enderecoCompleto.cidade);
    printf("BAIRRO: ");
    limpezaDoBuffer();
    fgets(ModuloClientes->enderecoCompleto.bairro,49,stdin);
    formatador(ModuloClientes->enderecoCompleto.bairro);
    printf("RUA: ");
    limpezaDoBuffer();
    fgets(ModuloClientes->enderecoCompleto.rua, 49,stdin);
    formatador(ModuloClientes->enderecoCompleto.rua);
    printf("CEP: ");
    limpezaDoBuffer();
    fgets(ModuloClientes->enderecoCompleto.cep, 49 , stdin);
    formatador(ModuloClientes->enderecoCompleto.cep);
    printf("N�MERO: ");
    scanf("%d", &ModuloClientes->enderecoCompleto.numero);
    printf("Possui debido registrado? 0-n�o 1 - sim \n");
    scanf("%hd", &ModuloClientes->debitoRegistrado);
    printf("-------------------------------------------\n");
    printf("--------Digite o tipo do clinte-------------\n");
    printf("|0|-FISICO                     |1|-JURIDICO  \n");
    scanf("%hd", &ModuloClientes->tipoCliente);
    if(ModuloClientes->tipoCliente == 0){
        printf("VOC� SELECIONOU PESSOA FISICA!!\n");
        printf("Digite o RG do cliente: \n");
        limpezaDoBuffer();
        fgets(ModuloClientes->identidade, 49, stdin);
        formatador(ModuloClientes->identidade);
        printf("Digite o CPF do clitente \n");
        limpezaDoBuffer();
        fgets(ModuloClientes->ID, 49 , stdin);
        formatador(ModuloClientes->ID);
    }
    if(ModuloClientes->tipoCliente == 1){
        printf("VOC� SELECIONOU PESSOA JURIDICA!!\n");
        printf("Digite o CNPJ do clitente \n");
        limpezaDoBuffer();
        fgets(ModuloClientes->ID, 49, stdin);
        formatador(ModuloClientes->ID);
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
    for(int i = 0; i <= ModuloClientes.indice; i++){
        if(strncmp(Cliente.ID, ModuloClientes.listaDeClientes[i].ID, TAM) == 0){
            printf("Cliente encontrado!");
            return i;
        }
    }
    printf("Cliente inexistente!");
    return -1;
}
void imprimirTodosOsClientes(ModuloClientes Clientes){
    for(int i = 0; i < Clientes.indice; i++){
        imprimeInfoCliente(Clientes.listaDeClientes[i]);
    }
}

void alterarCliente(ModuloClientes* ModuloClientes, TCliente clientes){
  int resposta = pesquisarCliente(*ModuloClientes, clientes);
  if(resposta == -1){
    printf("Cliente não encontrado");
    return;
  }
  printf("Alterar cliente");
  lerCliente(&ModuloClientes->listaDeClientes[resposta]);
}

void excluirCLiente(ModuloClientes* ModuloClientes, TCliente cliente){
  int resposta = pesquisarCliente(*ModuloClientes, cliente);
  if(resposta == -1){
    printf("Cliente não encontrado\n" );
    return;
  }
  for (int j = resposta; j < ModuloClientes->indice ; j++) {
      ModuloClientes->listaDeClientes[j] = ModuloClientes->listaDeClientes[j + 1];
  }
  ModuloClientes->indice--;
  printf("Cliente excluído com sucesso\n");
}