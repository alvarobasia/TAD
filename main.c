#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#define TAM 50

typedef struct Data
{
    int dia;
    int mes;
    int ano;
} TData;

typedef struct _endereco
{
    char cidade[TAM];
    char bairro[TAM];
    char rua[TAM];
    char cep[TAM];
    int numero;
} TEndereco;

typedef struct Produtos
{
    int codigoDoProd;
    char nomeDoProd[TAM];
    char descricaoDoProd[TAM];
    TData dataFabri;
    char loteDoProd[TAM];
    float precoUnit;
    int quantidadeProd;
} TProdutos;

typedef struct Cliente
{
    char nome[TAM];
    char ID[TAM];//CPF E CNPJ
    char identidade[TAM];
    TData dataDeNascimento;
    TEndereco enderecoCompleto;
    short int tipoCliente; //0 - pessoa Fisica 1 - Pessoa juridica
    short int debitoRegistrado; //0 - não tem 1 - tem
} TCliente;

typedef struct Vendas
{
    int codigo;
    char ID;
    int quantidadeDeVendas;
    TData dataDaVenda;
    int tipoDePagamanto; //a vista ou a prazo
    float totalDaVenda;
    char dataRealizacaoCompra[TAM];
    char prazoParaPagamento[TAM];
    TCliente debitosParaVenda;
} TVendas;

typedef struct modulo{
    TProdutos listaDeProdutos[80];
    TCliente listaDeClientes[80];
    TVendas vendasRealizadas[90];
}TModulo;

void lerCliente(){
    printf("iokok");
    TModulo modulo;
    int indice = 0;
    int resposta = 1;
    while(1){
        printf("-------------------------------------------\n");
        printf("--------***REGISTRAR CLIENTE***-------------\n");
        printf("Criado por Álvaro Basílio , 2019 ");
        printf("©Todos os direitos reservados\n");
        printf("VOCÊ NÃO DEVE USAR UMA CÓPIA PIRATA DESSE SOFTWARE\n");
        printf("Digite o nome do cliente: ");
        fgets(modulo.listaDeClientes[indice].nome,49, stdin);
        printf("Digite a data de nascimento/Criação\n");
        printf("DIA: ");
        scanf("%d", &modulo.listaDeClientes[indice].dataDeNascimento.dia);
        printf("MÊS: ");
        scanf("%d", &modulo.listaDeClientes[indice].dataDeNascimento.mes);
        printf("ANO: ");
        __fpurge(stdin);
        fflush(stdin);
        scanf("%d", &modulo.listaDeClientes[indice].dataDeNascimento.ano);
        printf("Digite o endereço do cliente: ");
        printf("CIDADE: ");
        __fpurge(stdin);
        fflush(stdin);
        fgets(modulo.listaDeClientes[indice].enderecoCompleto.cidade,49,stdin);
        printf("BAIRRO: ");
        __fpurge(stdin);
        fflush(stdin);
        fgets(modulo.listaDeClientes[indice].enderecoCompleto.bairro,49,stdin);
        printf("RUA: ");
        __fpurge(stdin);
        fflush(stdin);
        fgets(modulo.listaDeClientes[indice].enderecoCompleto.rua, 49,stdin);
        printf("CEP: ");
        __fpurge(stdin);
        fflush(stdin);
        fgets(modulo.listaDeClientes[indice].enderecoCompleto.cep, 49 , stdin);
        printf("NÚMERO: ");
        scanf("%d", &modulo.listaDeClientes[indice].enderecoCompleto.numero);
        printf("Possui debido registrado? 0-não 1 - sim ");
        scanf("%hd", &modulo.listaDeClientes[indice].debitoRegistrado);
        printf("-------------------------------------------\n");
        printf("--------Digite o tipo do clinte-------------\n");
        printf("|0|-FISICO                     |1|-JURIDICO  \n");
        scanf("%hd", &modulo.listaDeClientes[indice].tipoCliente);
        if(modulo.listaDeClientes[indice].tipoCliente == 0){
            printf("VOCÊ SELECIONOU PESSOA FISICA!!\n");
            printf("Digite o RG do cliente: ");
            __fpurge(stdin);
            fflush(stdin);
            fgets(modulo.listaDeClientes[indice].identidade, 49, stdin);
            printf("Digite o CPF do clitente");
            __fpurge(stdin);
            fflush(stdin);
            fgets(modulo.listaDeClientes[indice].ID, 49 , stdin);
        }
        if(modulo.listaDeClientes[indice].tipoCliente == 1){
            printf("VOCÊ SELECIONOU PESSOA JURIDICA!!\n");
            printf("Digite o CNPJ do clitente");
            __fpurge(stdin);
            fflush(stdin);
            fgets(modulo.listaDeClientes[indice].ID, 49, stdin);
        }
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
            printf("6- RG: ");
            printf("%s\n", modulo.listaDeClientes[indice].identidade);
            printf("7- CPF: ");
            printf("%s\n", modulo.listaDeClientes[indice].ID);
        }
        if(modulo.listaDeClientes[indice].tipoCliente == 1){
            printf("Pessoa Jurídica\n");
            printf("6- CNPJ: ");
            printf("%s\n", modulo.listaDeClientes[indice].ID);
        }
        printf("---------------------------------------\n");
        printf("DESEJA REGISTRAR UM NOVO CLIENTE? 1-sim 2 - não ");
        scanf("%d", &resposta);
        __fpurge(stdin);
        fflush(stdin);
        if(resposta == 1)
            indice++;
        else
            break;

    }
}

int main()
{
    printf("mmo");
    setlocale(LC_ALL, "portuguese");
    lerCliente();
    return 0;
}
