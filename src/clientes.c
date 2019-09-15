#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <unistd.h> 
#include "clientes.h"
#include "menu.h"
void imprimeInfoCliente(TCliente modulo){
    printf(AMA);
    puts("\n------INFORMAÇÕES DO CLIENTE---------");
    printf("1- NOME- %s\n", modulo.nome);
    printf("2- Nasc/Criação - %d / %d / %d\n",modulo.dataDeNascimento.dia, modulo.dataDeNascimento.mes,
    modulo.dataDeNascimento.ano);
    printf("3- -Endereço-\n");
    printf("3-a) Cidade: %s\n",modulo.enderecoCompleto.cidade);
    printf("3-b) Bairro: %s\n",modulo.enderecoCompleto.bairro);
    printf("3-c) Rua: %s\n",modulo.enderecoCompleto.rua);
    printf("3-d) CEP: %s\n",modulo.enderecoCompleto.cep);
    printf("3-e) Número: %d\n",modulo.enderecoCompleto.numero);
    printf("4- Débido registrado? ");
    if(modulo.debitoRegistrado == 0)
        printf("NÃO\n");
    if(modulo.debitoRegistrado == 1)
        printf("SIM\n");
    printf("5- Tipo de cliente ");
    if(modulo.tipoCliente == 0){
        printf("Pessoa Física\n");
        printf("7- CPF: ");
        printf("%s\n", modulo.ID);
        printf("6- RG: ");
        printf("%s\n", modulo.identidade);
    }
    if(modulo.tipoCliente == 1){
        printf("Pessoa Jurídica\n");
        printf("6- CNPJ: ");
        printf("%s\n", modulo.ID);
    }
    printf("---------------------------------------\n");
    printf(DEF_LETRA);
    printf("PRESSIONE ENTER PARA CONTINUAR!!!!");
    getchar();
}

void lerCliente(TCliente *ModuloClientes){
    limparConsole();
    printf(GREEN);
    printf("-------------------------------------------\n");
    printf("--------***REGISTRAR CLIENTE***-------------\n");
    printf("Digite o nome do cliente: ");
    printf(DEF_LETRA);
    limpezaDoBuffer();
    fgets(ModuloClientes->nome, 49, stdin);
    formatador(ModuloClientes->nome);
    printf(GREEN);
    printf("Digite a data de nascimento/Criação: \n");
    printf("DIA: ");
    printf(DEF_LETRA);
    scanf("%d", &ModuloClientes->dataDeNascimento.dia);
    printf(GREEN);
    printf("MêS: ");
    printf(DEF_LETRA);
    scanf("%d", &ModuloClientes->dataDeNascimento.mes);
    printf(GREEN);
    printf("ANO: ");
    printf(DEF_LETRA);
    scanf("%d", &ModuloClientes->dataDeNascimento.ano);
    limpezaDoBuffer();
    printf(GREEN);
    printf("Digite o endereço do cliente: \n");
    printf("CIDADE: ");
    printf(DEF_LETRA);
    limpezaDoBuffer();
    fgets(ModuloClientes->enderecoCompleto.cidade,49,stdin);
    formatador(ModuloClientes->enderecoCompleto.cidade);
    printf(GREEN);
    printf("BAIRRO: ");
    printf(DEF_LETRA);
    limpezaDoBuffer();
    fgets(ModuloClientes->enderecoCompleto.bairro,49,stdin);
    formatador(ModuloClientes->enderecoCompleto.bairro);
    printf(GREEN);
    printf("RUA: ");
    printf(DEF_LETRA);
    limpezaDoBuffer();
    fgets(ModuloClientes->enderecoCompleto.rua, 49,stdin);
    formatador(ModuloClientes->enderecoCompleto.rua);
    printf(GREEN);
    printf("CEP: ");
    printf(DEF_LETRA);
    limpezaDoBuffer();
    fgets(ModuloClientes->enderecoCompleto.cep, 49 , stdin);
    formatador(ModuloClientes->enderecoCompleto.cep);
    printf(GREEN);
    printf("NÚMERO: ");
    printf(DEF_LETRA);
    scanf("%d", &ModuloClientes->enderecoCompleto.numero);
    printf(GREEN);
    printf("Possui debido registrado? 0-não 1 - sim \n");
    printf(DEF_LETRA);
    scanf("%hd", &ModuloClientes->debitoRegistrado);
    printf(GREEN);
    printf("-------------------------------------------\n");
    printf("--------Digite o tipo do clinte-------------\n");
    printf("|0|-FÍSICO                     |1|-JURÍDICO  \n");
    printf(DEF_LETRA);
    scanf("%hd", &ModuloClientes->tipoCliente);
    if(ModuloClientes->tipoCliente == 0){
        printf(GREEN);
        printf("VOCÊ SELECIONOU PESSOA FISICA!!\n");
        printf("Digite o RG do cliente: ");
        printf(DEF_LETRA);
        limpezaDoBuffer();
        fgets(ModuloClientes->identidade, 49, stdin);
        formatador(ModuloClientes->identidade);
        printf(GREEN);
        printf("Digite o CPF do clitente ");
        printf(DEF_LETRA);
        limpezaDoBuffer();
        fgets(ModuloClientes->ID, 49 , stdin);
        formatador(ModuloClientes->ID);
    }
    if(ModuloClientes->tipoCliente == 1){
        printf(GREEN);
        printf("VOCÊ SELECIONOU PESSOA JURIDICA!!\n");
        printf("Digite o CNPJ do clitente: ");
        printf(DEF_LETRA);
        limpezaDoBuffer();
        fgets(ModuloClientes->ID, 49, stdin);
        formatador(ModuloClientes->ID);
    }
        limparConsole();
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
            return i;
        }
    }
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
    printf(RED);
    limpezaDoBuffer();
    printf("\t Cliente não encontrado. Retornando ao menu... \n");
    sleep(2);
    printf(DEF_LETRA);
    limparConsole();
    return;
  }
  printf(GREEN);
  limpezaDoBuffer();
  printf("Cliente %s encontrado, pressione ENTER para alterar ...\n", ModuloClientes->listaDeClientes[resposta].nome);
  imprimeInfoCliente(ModuloClientes->listaDeClientes[resposta]);
  lerCliente(&ModuloClientes->listaDeClientes[resposta]);
  imprimeInfoCliente(ModuloClientes->listaDeClientes[resposta]);
  printf(DEF_LETRA);
}

void excluirCliente(ModuloClientes* ModuloClientes, TCliente cliente){
  int resposta = pesquisarCliente(*ModuloClientes, cliente);
  if(resposta == -1){
    printf(RED);
    limpezaDoBuffer();
    printf("\t Cliente não encontrado. Retornando ao menu... \n");
    sleep(2);
    printf(DEF_LETRA);
    limparConsole();
    return;
  }
  printf(GREEN);
  limpezaDoBuffer();
  printf("Cliente %s encontrado, pressione ENTER excluir ...\n", ModuloClientes->listaDeClientes[resposta].nome);
  imprimeInfoCliente(ModuloClientes->listaDeClientes[resposta]);
  for (int j = resposta; j < ModuloClientes->indice ; j++) {
      ModuloClientes->listaDeClientes[j] = ModuloClientes->listaDeClientes[j + 1];
  }
  ModuloClientes->indice--;
  printf(GREEN);
  printf("Cliente excluído com sucesso! \n");
  sleep(3);
}