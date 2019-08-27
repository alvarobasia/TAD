#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include "clientes.h"
#define TAM 50
// typedef struct Data
// {
//     int dia;
//     int mes;
//     int ano;
// } TData;

// typedef struct _endereco
// {
//     char cidade[TAM];
//     char bairro[TAM];
//     char rua[TAM];
//     char cep[TAM];
//     int numero;
// } TEndereco;

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

// typedef struct Cliente
// {
//     char nome[TAM];
//     char ID[TAM];//CPF E CNPJ
//     char identidade[TAM];
//     TData dataDeNascimento;
//     TEndereco enderecoCompleto;
//     short int tipoCliente; //0 - pessoa Fisica 1 - Pessoa juridica
//     short int debitoRegistrado; //0 - não tem 1 - tem
// } TCliente;

typedef struct Vendas
{
    int codigo;
    char ID[TAM];
    int quantidadeDeVendas;
    TData dataDaVenda;
    int tipoDePagamento; //1 - a vista ou 2 - a prazo
    float totalDaVenda;
    TData prazoParaPagamento;
    TCliente debitosParaVenda;
} TVendas;

typedef struct _ModuloProdutos{
    TProdutos listaDeProdutos[80];
    int indice;
}ModuloProdutos;

// typedef struct _ModuloClientes{
//     TCliente listaDeClientes[80];
//     int indice;
// }ModuloClientes;

typedef struct _ModuloVendas{
    TVendas vendasRealizadas[90];
    int indice;
}ModuloVendas;
void limpezaDoBuffer(){
    __fpurge(stdin);
    fflush(stdin); 
}

void limparConsole(){
    system("clear");
    system("cls");
}
// void imprimeInfoCliente(ModuloClientes modulo, int indice){
//     puts("------INFORMAÇÕES DO CLIENTE---------");
//     printf("1- NOME- %s\n", modulo.listaDeClientes[indice].nome);
//     printf("2- Nasc/Criação - %d / %d / %d\n",modulo.listaDeClientes[indice].dataDeNascimento.dia,
//     modulo.listaDeClientes[indice].dataDeNascimento.mes,modulo.listaDeClientes[indice].dataDeNascimento.ano);
//     printf("3- -Endereço-\n");
//     printf("3-a) Cidade: %s\n",modulo.listaDeClientes[indice].enderecoCompleto.cidade);
//     printf("3-b) Bairro: %s\n",modulo.listaDeClientes[indice].enderecoCompleto.bairro);
//     printf("3-c) Rua: %s\n",modulo.listaDeClientes[indice].enderecoCompleto.rua);
//     printf("3-d) CEP: %s\n",modulo.listaDeClientes[indice].enderecoCompleto.cep);
//     printf("3-e) Número: %d\n",modulo.listaDeClientes[indice].enderecoCompleto.numero);
//     printf("4- Débido registrado? ");
//     if(modulo.listaDeClientes[indice].debitoRegistrado == 0)
//         printf("NÃO\n");
//     if(modulo.listaDeClientes[indice].debitoRegistrado == 1)
//         printf("SIM\n");
//     printf("5- Tipo de cliente ");
//     if(modulo.listaDeClientes[indice].tipoCliente == 0){
//         printf("Pessoa Física\n");
//         printf("7- CPF: ");
//         printf("%s\n", modulo.listaDeClientes[indice].ID);
//         printf("6- RG: ");
//         printf("%s\n", modulo.listaDeClientes[indice].identidade);
//     }
//     if(modulo.listaDeClientes[indice].tipoCliente == 1){
//         printf("Pessoa Jurídica\n");
//         printf("6- CNPJ: ");
//         printf("%s\n", modulo.listaDeClientes[indice].ID);
//     }
//     printf("---------------------------------------\n");
// }

void imprimeInfoProduto(ModuloProdutos modulo, int indice){
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

// void lerCliente(ModuloClientes *ModuloClientes){
//     FILE *arquivoCliente;
//     limparConsole();
//     int resposta = 1;
//     int indice  = 0;
//     arquivoCliente = fopen("clientes.txt", "a");
//     while(1){
//         printf("-------------------------------------------\n");
//         printf("--------***REGISTRAR CLIENTE***-------------\n");
//         printf("Digite o nome do cliente: \n");
//         fgets(ModuloClientes->listaDeClientes[indice].nome, 49, stdin);
//         fprintf(arquivoCliente, "Nome do cliente : %s\n", ModuloClientes->listaDeClientes[indice].nome );
//         printf("Digite a data de nascimento/Criação\n");
//         printf("DIA: ");
//         scanf("%d", &ModuloClientes->listaDeClientes[indice].dataDeNascimento.dia);
//         printf("MÊS: ");
//         scanf("%d", &ModuloClientes->listaDeClientes[indice].dataDeNascimento.mes);
//         printf("ANO: ");
//         scanf("%d", &ModuloClientes->listaDeClientes[indice].dataDeNascimento.ano);
//         fprintf(arquivoCliente, "Data de nascimento: %d/ %d/%d \n", ModuloClientes->listaDeClientes[indice].dataDeNascimento.dia,
//         ModuloClientes->listaDeClientes[indice].dataDeNascimento.mes, ModuloClientes->listaDeClientes[indice].dataDeNascimento.ano);
//         limpezaDoBuffer();
//         printf("Digite o endereço do cliente: \n");
//         printf("CIDADE: ");
//         limpezaDoBuffer();
//         fgets(ModuloClientes->listaDeClientes[indice].enderecoCompleto.cidade,49,stdin);
//         printf("BAIRRO: ");
//         limpezaDoBuffer();
//         fgets(ModuloClientes->listaDeClientes[indice].enderecoCompleto.bairro,49,stdin);
//         printf("RUA: ");
//         limpezaDoBuffer();
//         fgets(ModuloClientes->listaDeClientes[indice].enderecoCompleto.rua, 49,stdin);
//         printf("CEP: ");
//         limpezaDoBuffer();
//         fgets(ModuloClientes->listaDeClientes[indice].enderecoCompleto.cep, 49 , stdin);
//         printf("NÚMERO: ");
//         scanf("%d", &ModuloClientes->listaDeClientes[indice].enderecoCompleto.numero);
//         fprintf(arquivoCliente, "Endereço: Cidade %s Bairro: %s rua: %s CEP: %s numero: %d\n",ModuloClientes->listaDeClientes[indice].enderecoCompleto.cidade,
//          ModuloClientes->listaDeClientes[indice].enderecoCompleto.bairro,ModuloClientes->listaDeClientes[indice].enderecoCompleto.rua,
//          ModuloClientes->listaDeClientes[indice].enderecoCompleto.cep, ModuloClientes->listaDeClientes[indice].enderecoCompleto.numero);
//         printf("Possui debido registrado? 0-não 1 - sim \n");
//         scanf("%hd", &ModuloClientes->listaDeClientes[indice].debitoRegistrado);
//         if(ModuloClientes->listaDeClientes[indice].debitoRegistrado == 0){
//             fprintf(arquivoCliente, "Não possui debito\n");
//         }else{
//             fprintf(arquivoCliente, "Possui\n");
//         }
        
//         printf("-------------------------------------------\n");
//         printf("--------Digite o tipo do clinte-------------\n");
//         printf("|0|-FISICO                     |1|-JURIDICO  \n");
//         scanf("%hd", &ModuloClientes->listaDeClientes[indice].tipoCliente);
//         if(ModuloClientes->listaDeClientes[indice].tipoCliente == 0){
//             printf("VOCÊ SELECIONOU PESSOA FISICA!!\n");
//             fprintf(arquivoCliente, "PESSOA FISICA \n");
//             printf("Digite o RG do cliente: \n");
//             limpezaDoBuffer();
//             fgets(ModuloClientes->listaDeClientes[indice].identidade, 49, stdin);
//             fprintf(arquivoCliente, "RG: %s\n",ModuloClientes->listaDeClientes[indice].identidade );
//             printf("Digite o CPF do clitente \n");
//             limpezaDoBuffer();
//             fgets(ModuloClientes->listaDeClientes[indice].ID, 49 , stdin);
//             fprintf(arquivoCliente, "CPF: %s\n", ModuloClientes->listaDeClientes[indice].ID );
//         }
//         if(ModuloClientes->listaDeClientes[indice].tipoCliente == 1){
//             printf("VOCÊ SELECIONOU PESSOA JURIDICA!!\n");
//             fprintf(arquivoCliente, "PESSOA JURIDICA \n");
//             printf("Digite o CNPJ do clitente \n");
//             limpezaDoBuffer();
//             fgets(ModuloClientes->listaDeClientes[indice].ID, 49, stdin);
//             fprintf(arquivoCliente, "CNPJ: %s\n", ModuloClientes->listaDeClientes[indice].ID );
//         }
//         limparConsole();
//         imprimeInfoCliente(*ModuloClientes, indice);
//         limpezaDoBuffer();
//         printf("DESEJA REGISTRAR UM NOVO CLIENTE? 1-sim 2 - não \n");
//         scanf("%d", &resposta);
//         limpezaDoBuffer();
//         if(resposta == 1){
//             fprintf(arquivoCliente, "--------------------------\n");
//             indice++;
//         }else{
//             fclose(arquivoCliente);
//             ModuloClientes->indice += indice;
//             break;
//         }
//     }
// }

void lerProduto(ModuloProdutos *ModuloProdutos){
    limparConsole();
    int indice = 0;
    int resposta = 1;
    while (1){
        printf("-------------------------------------------\n");
        printf("--------***REGISTRAR PRODUTO***-------------\n");
        printf("Digite o codigo do produto \n");
        scanf("%d", &ModuloProdutos->listaDeProdutos[indice].codigoDoProd);
        limpezaDoBuffer();
        printf("Digite o nome do produto: \n");
        fgets(ModuloProdutos->listaDeProdutos[indice].nomeDoProd, 49, stdin);
        limpezaDoBuffer();
        printf("Digite a descrição do produto: \n");
        fgets(ModuloProdutos->listaDeProdutos[indice].descricaoDoProd, 49, stdin);
        printf("Digite a data de fabricação do produto\n");
        printf("DIA: ");
        scanf("%d", &ModuloProdutos->listaDeProdutos[indice].dataFabri.dia);
        printf("MÊS: ");
        scanf("%d", &ModuloProdutos->listaDeProdutos[indice].dataFabri.mes);
        printf("ANO: ");
        scanf("%d", &ModuloProdutos->listaDeProdutos[indice].dataFabri.ano);
        printf("Digite o lote do produto: \n");
        limpezaDoBuffer();
        fgets(ModuloProdutos->listaDeProdutos[indice].loteDoProd, 49, stdin);
        printf("Digite o preço do produto: \n");
        scanf("%f", &ModuloProdutos->listaDeProdutos[indice].precoUnit);
        printf("Digite a quantidade de produtos que o estoque possui: \n");
        scanf("%d", &ModuloProdutos->listaDeProdutos[indice].quantidadeProd);
        limparConsole();
        imprimeInfoProduto(*ModuloProdutos, indice);
        printf("Você deseja registrar um novo produto? 1 - sim 2 - não\n");
        scanf("%d", &resposta);
        limpezaDoBuffer();
        if (resposta == 1)
            indice++;
        else
            ModuloProdutos->indice += indice;
            break;
    }
}

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

void registrador(ModuloClientes* clientes1, ModuloProdutos* produtos1, ModuloVendas* vendas1){
    int tipoDeAcao;
    printf("VOCÊ DESEJA: \n");
    printf("****************************\n");
    printf("Digite:\n");
    printf("|1| -- REGISTRAR CLIENTE --\n");
    printf("|2| -- REGISTRAR PRODUTO --\n");
    printf("|3| -- EFETUAR UMA VENDA --\n");
    scanf("%d", &tipoDeAcao);
    limpezaDoBuffer();
    if(tipoDeAcao == 1)
        lerCliente(clientes1);
    if(tipoDeAcao == 2)
        lerProduto(produtos1);
    if(tipoDeAcao == 3)
        lerVendas(vendas1, clientes1, produtos1);
    registrador(clientes1, produtos1, vendas1 );
}

void copyRight(){
    printf("Criado por Álvaro Basílio , 2019 ");
    printf("©Todos os direitos reservados\n");
    printf("VOCÊ NÃO DEVE USAR UMA CÓPIA PIRATA DESSE SOFTWARE\n");
}
int main()

{
    ModuloClientes clientes1;
    ModuloProdutos produtos1;
    ModuloVendas vendas1;
    setlocale(LC_ALL, "portuguese");
    copyRight();
    clientes1.indice = 0;
    produtos1.indice = 0;
    vendas1.indice = 0;
    registrador(&clientes1, &produtos1, &vendas1);
    return 0;
}
