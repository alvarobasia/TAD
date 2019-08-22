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

void limpezaDoBuffer(){
    __fpurge(stdin);
    fflush(stdin); 
}

void limparConsole(){
    system("clear");
    system("cls");
}
void imprimeInfoCliente(TModulo modulo, int indice){
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
}

void imprimeInfoProduto(TModulo modulo, int indice){
    puts("------INFORMAÇÕES DO PRODUTO---------");
    printf("Codigo do produto: ");
    printf("%d\n", modulo.listaDeProdutos[indice].codigoDoProd);
    printf("Nome do produto: ");
    printf("%s\n", modulo.listaDeProdutos[indice].nomeDoProd);
    printf("Descrição do produto: ");
    printf(" ' %s '\n", modulo.listaDeProdutos[indice].descricaoDoProd);
    printf("Data de fabricação: ");
    printf("%d / %d/ %d\n", modulo.listaDeProdutos[indice].dataFabri.dia,
    modulo.listaDeProdutos[indice].dataFabri.mes,
    modulo.listaDeProdutos[indice].dataFabri.ano);
    printf("Lote do produto: ");
    printf("%s\n", modulo.listaDeProdutos[indice].loteDoProd);
    printf("Preço do produto: ");
    printf("R$ %f\n", modulo.listaDeProdutos[indice].precoUnit);
    printf("Quantidade de produtos no estoque: ");
    printf("%d\n", modulo.listaDeProdutos[indice].quantidadeProd);
    printf("--------------------------------------------------\n");
}

void lerCliente(){
    int resposta = 1;
    int indice = 0;
    TModulo modulo;
    while(1){
        printf("-------------------------------------------\n");
        printf("--------***REGISTRAR CLIENTE***-------------\n");
        printf("Digite o nome do cliente: ");
        fgets(modulo.listaDeClientes[indice].nome,49, stdin);
        printf("Digite a data de nascimento/Criação\n");
        printf("DIA: ");
        scanf("%d", &modulo.listaDeClientes[indice].dataDeNascimento.dia);
        printf("MÊS: ");
        scanf("%d", &modulo.listaDeClientes[indice].dataDeNascimento.mes);
        printf("ANO: ");
        limpezaDoBuffer();
        scanf("%d", &modulo.listaDeClientes[indice].dataDeNascimento.ano);
        printf("Digite o endereço do cliente: ");
        printf("CIDADE: ");
        limpezaDoBuffer();
        fgets(modulo.listaDeClientes[indice].enderecoCompleto.cidade,49,stdin);
        printf("BAIRRO: ");
        limpezaDoBuffer();
        fgets(modulo.listaDeClientes[indice].enderecoCompleto.bairro,49,stdin);
        printf("RUA: ");
        limpezaDoBuffer();
        fgets(modulo.listaDeClientes[indice].enderecoCompleto.rua, 49,stdin);
        printf("CEP: ");
        limpezaDoBuffer();
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
            limpezaDoBuffer();
            fgets(modulo.listaDeClientes[indice].identidade, 49, stdin);
            printf("Digite o CPF do clitente");
            limpezaDoBuffer();
            fgets(modulo.listaDeClientes[indice].ID, 49 , stdin);
        }
        if(modulo.listaDeClientes[indice].tipoCliente == 1){
            printf("VOCÊ SELECIONOU PESSOA JURIDICA!!\n");
            printf("Digite o CNPJ do clitente");
            limpezaDoBuffer();
            fgets(modulo.listaDeClientes[indice].ID, 49, stdin);
        }
        limparConsole();
        imprimeInfoCliente(modulo, indice);
        limpezaDoBuffer();
        printf("DESEJA REGISTRAR UM NOVO CLIENTE? 1-sim 2 - não ");
        scanf("%d", &resposta);
        limpezaDoBuffer();
        if(resposta == 1)
            indice++;
        else
            break;

    }
}

void lerProduto(){
    TModulo modulo;
    int indice = 0;
    int resposta = 1;
    while (1){
        printf("-------------------------------------------\n");
        printf("--------***REGISTRAR PRODUTO***-------------\n");
        printf("Digite o codigo do produto");
        scanf("%d", &modulo.listaDeProdutos[indice].codigoDoProd);
        limpezaDoBuffer();
        printf("Digite o nome do produto: ");
        fgets(modulo.listaDeProdutos[indice].nomeDoProd, 49, stdin);
        limpezaDoBuffer();
        printf("Digite a descrição do produto: ");
        fgets(modulo.listaDeProdutos[indice].descricaoDoProd, 49, stdin);
        printf("Digite a data de fabricação do produto\n");
        printf("DIA: ");
        scanf("%d", &modulo.listaDeProdutos[indice].dataFabri.dia);
        printf("MÊS: ");
        scanf("%d", &modulo.listaDeProdutos[indice].dataFabri.mes);
        printf("ANO: ");
        scanf("%d", &modulo.listaDeProdutos[indice].dataFabri.ano);
        printf("Digite o lote do produto: ");
        limpezaDoBuffer();
        fgets(modulo.listaDeProdutos[indice].loteDoProd, 49, stdin);
        printf("Digite o preço do produto: ");
        scanf("%f", &modulo.listaDeProdutos[indice].precoUnit);
        printf("Digite a quantidade de produtos que o estoque possui: ");
        scanf("%d", &modulo.listaDeProdutos[indice].quantidadeProd);
        limparConsole();
        imprimeInfoProduto(modulo, indice);
        printf("Você deseja registrar um novo produto? 1 - sim 2 - não");
        scanf("%d", &resposta);
        limpezaDoBuffer();
        if (resposta == 1)
            indice++;
        else
            break;
    }

}
void registrador(){
    int tipoDeAcao;
    printf("VOCÊ DESEJA: \n");
    printf("****************************\n");
    printf("Digite:");
    printf("|1| -- REGISTRAR CLIENTE --\n");
    printf("|2| -- REGISTRAR PRODUTO --\n");
    scanf("%d", &tipoDeAcao);
    limpezaDoBuffer();
    if(tipoDeAcao == 1) 
        lerCliente();
    if(tipoDeAcao == 2)
        lerProduto();
}
int main()
{
    setlocale(LC_ALL, "portuguese");
    printf("Criado por Álvaro Basílio , 2019 ");
    printf("©Todos os direitos reservados\n");
    printf("VOCÊ NÃO DEVE USAR UMA CÓPIA PIRATA DESSE SOFTWARE\n");
    registrador();
    return 0;
}
//Observação: esta versão está incompleta para correção de bugs
