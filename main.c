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
    char ID[TAM];
    int quantidadeDeVendas;
    TData dataDaVenda;
    int tipoDePagamento; //1 - a vista ou 2 - a prazo
    float totalDaVenda;
    TData prazoParaPagamento;
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

void lerCliente(TModulo *modulo){
    int resposta = 1;
    int indice = 0;
    while(1){
        printf("-------------------------------------------\n");
        printf("--------***REGISTRAR CLIENTE***-------------\n");
        printf("Digite o nome do cliente: ");
        fgets(modulo->listaDeClientes[indice].nome,49, stdin);
        printf("Digite a data de nascimento/Criação\n");
        printf("DIA: ");
        scanf("%d", &modulo->listaDeClientes[indice].dataDeNascimento.dia);
        printf("MÊS: ");
        scanf("%d", &modulo->listaDeClientes[indice].dataDeNascimento.mes);
        printf("ANO: ");
        limpezaDoBuffer();
        scanf("%d", &modulo->listaDeClientes[indice].dataDeNascimento.ano);
        printf("Digite o endereço do cliente: ");
        printf("CIDADE: ");
        limpezaDoBuffer();
        fgets(modulo->listaDeClientes[indice].enderecoCompleto.cidade,49,stdin);
        printf("BAIRRO: ");
        limpezaDoBuffer();
        fgets(modulo->listaDeClientes[indice].enderecoCompleto.bairro,49,stdin);
        printf("RUA: ");
        limpezaDoBuffer();
        fgets(modulo->listaDeClientes[indice].enderecoCompleto.rua, 49,stdin);
        printf("CEP: ");
        limpezaDoBuffer();
        fgets(modulo->listaDeClientes[indice].enderecoCompleto.cep, 49 , stdin);
        printf("NÚMERO: ");
        scanf("%d", &modulo->listaDeClientes[indice].enderecoCompleto.numero);
        printf("Possui debido registrado? 0-não 1 - sim ");
        scanf("%hd", &modulo->listaDeClientes[indice].debitoRegistrado);
        printf("-------------------------------------------\n");
        printf("--------Digite o tipo do clinte-------------\n");
        printf("|0|-FISICO                     |1|-JURIDICO  \n");
        scanf("%hd", &modulo->listaDeClientes[indice].tipoCliente);
        if(modulo->listaDeClientes[indice].tipoCliente == 0){
            printf("VOCÊ SELECIONOU PESSOA FISICA!!\n");
            printf("Digite o RG do cliente: ");
            limpezaDoBuffer();
            fgets(modulo->listaDeClientes[indice].identidade, 49, stdin);
            printf("Digite o CPF do clitente");
            limpezaDoBuffer();
            fgets(modulo->listaDeClientes[indice].ID, 49 , stdin);
        }
        if(modulo->listaDeClientes[indice].tipoCliente == 1){
            printf("VOCÊ SELECIONOU PESSOA JURIDICA!!\n");
            printf("Digite o CNPJ do clitente");
            limpezaDoBuffer();
            fgets(modulo->listaDeClientes[indice].ID, 49, stdin);
        }
        limparConsole();
        imprimeInfoCliente(*modulo, indice);
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

void lerProduto(TModulo *modulo){
    int indice = 0;
    int resposta = 1;
    while (1){
        printf("-------------------------------------------\n");
        printf("--------***REGISTRAR PRODUTO***-------------\n");
        printf("Digite o codigo do produto");
        scanf("%d", &modulo->listaDeProdutos[indice].codigoDoProd);
        limpezaDoBuffer();
        printf("Digite o nome do produto: ");
        fgets(modulo->listaDeProdutos[indice].nomeDoProd, 49, stdin);
        limpezaDoBuffer();
        printf("Digite a descrição do produto: ");
        fgets(modulo->listaDeProdutos[indice].descricaoDoProd, 49, stdin);
        printf("Digite a data de fabricação do produto\n");
        printf("DIA: ");
        scanf("%d", &modulo->listaDeProdutos[indice].dataFabri.dia);
        printf("MÊS: ");
        scanf("%d", &modulo->listaDeProdutos[indice].dataFabri.mes);
        printf("ANO: ");
        scanf("%d", &modulo->listaDeProdutos[indice].dataFabri.ano);
        printf("Digite o lote do produto: ");
        limpezaDoBuffer();
        fgets(modulo->listaDeProdutos[indice].loteDoProd, 49, stdin);
        printf("Digite o preço do produto: ");
        scanf("%f", &modulo->listaDeProdutos[indice].precoUnit);
        printf("Digite a quantidade de produtos que o estoque possui: ");
        scanf("%d", &modulo->listaDeProdutos[indice].quantidadeProd);
        limparConsole();
        imprimeInfoProduto(*modulo, indice);
        printf("Você deseja registrar um novo produto? 1 - sim 2 - não");
        scanf("%d", &resposta);
        limpezaDoBuffer();
        if (resposta == 1)
            indice++;
        else
            break;
    }
}

TProdutos* buscarProduto (int codigo, TModulo *modulo, int* indice){
    for (int i = 0; i < 80; i++){
       if(codigo == modulo->listaDeProdutos[i].codigoDoProd){
           *indice = i;
           return &modulo->listaDeProdutos[i];
           break;
       }     
    }
}
    

TCliente* buscarCliente (char ID[], TModulo *modulo, int* indice){
    for (int i = 0; i < 80; i++){
       if(strncmp(ID, modulo->listaDeClientes[i].ID, TAM) == 0){
           *indice = i;
           return &modulo->listaDeClientes[i];
           break;
       }     
    }
    return NULL;
}



void lerVendas(TModulo *modulo){
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
        printf("Digite o CPF/CNPJ do cliente");
        fgets(ID, 49, stdin);
        limpezaDoBuffer();
        cliente = buscarCliente(ID, modulo, &indiceCliente);
        if(cliente == NULL){
            printf("Cliente inexistente");
            break;
        }
        if (cliente->debitoRegistrado == 1){
            printf("Cliente possui debito registrado");
            break;
        }
        printf("Digite o código do produto: ");
        limpezaDoBuffer();
        scanf("%d", &codigo);
        produto = buscarProduto(codigo, modulo, &indiceProduto);
        if(produto == NULL){
            printf("Produto inexistente\n");
            break;
        }
        if(produto->quantidadeProd == 0){
            printf("Em falta!");
            break;
        }
        modulo->vendasRealizadas[indice].codigo = produto->codigoDoProd;
        strcpy(cliente->ID, modulo->vendasRealizadas[indice].ID );
        printf("DIA: ");
        scanf("%d", &modulo->vendasRealizadas[indice].dataDaVenda.dia);
        printf("MÊS: ");
        scanf("%d", &modulo->vendasRealizadas[indice].dataDaVenda.mes);
        printf("ANO: ");
        scanf("%d", &modulo->vendasRealizadas[indice].dataDaVenda.ano);
        printf("Digite o tipo de pagamento: 1 - vista 2- prazo");
        scanf("%d", &modulo->vendasRealizadas[indice].tipoDePagamento);
        if(modulo->vendasRealizadas[indice].tipoDePagamento == 2){
            printf("----------Á PRAZO-------------\n");
            printf("Digite o prazo da compra da compra: ");
            printf("DIA: ");
            scanf("%d", &modulo->vendasRealizadas[indice].prazoParaPagamento.dia);
            printf("MÊS: ");
            scanf("%d", &modulo->vendasRealizadas[indice].prazoParaPagamento.mes);
            printf("ANO: ");
            scanf("%d", &modulo->vendasRealizadas[indice].prazoParaPagamento.mes);
            modulo->vendasRealizadas[indice].tipoDePagamento = 2;
            cliente->debitoRegistrado = 1;  
        }
        if(modulo->vendasRealizadas[indice].tipoDePagamento == 1){
           printf("----------Á VISTA-------------\n"); 
           modulo->vendasRealizadas[indice].tipoDePagamento = 1;
        }
        limparConsole();
        printf("Deseja realizar outra compra? 1 - sim , 2 - não");
        scanf("%d", &resposta);
        limpezaDoBuffer();
        if(resposta == 1)
            indice++;
        if(resposta == 2)
            break;
    }
      
}

void registrador(TModulo modulo){
    int tipoDeAcao;
    printf("VOCÊ DESEJA: \n");
    printf("****************************\n");
    printf("Digite:");
    printf("|1| -- REGISTRAR CLIENTE --\n");
    printf("|2| -- REGISTRAR PRODUTO --\n");
    printf("|3| -- EFETUAR UMA VENDA --\n");
    scanf("%d", &tipoDeAcao);
    limpezaDoBuffer();
    if(tipoDeAcao == 1) 
        lerCliente(&modulo);
    if(tipoDeAcao == 2)
        lerProduto(&modulo);
    if(tipoDeAcao == 3)
        lerVendas(&modulo);
    registrador(modulo);
}

TModulo instanciar(){
    TModulo modulo;
    return modulo;
}

void copyRight(){
    printf("Criado por Álvaro Basílio , 2019 ");
    printf("©Todos os direitos reservados\n");
    printf("VOCÊ NÃO DEVE USAR UMA CÓPIA PIRATA DESSE SOFTWARE\n");
}
int main()
{
    TModulo modulo = instanciar();
    setlocale(LC_ALL, "portuguese");
    copyRight();
    registrador(modulo);
    return 0;
}
