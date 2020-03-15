#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <unistd.h> 
#include "menu.h"
#include "vendas.h"
#include "clientes.h"
#include "produtos.h"
#include "notaFiscal.h"
#include "prova.h"
void MSG_MENU_PRINCIPAL(){
      limparConsole();
      for(int i = 0; i < 13 ; i++){
      switch (i){
        case 0 : printf(" ||||||||||||||||||      |||||||        ||||||||||     \n");break;
        case 1 : printf(" ||||||||||||||||||     |||||||||       |||||||||||    \n"); break;
        case 2 : printf("       |||||           |||||  ||||      |||||||||||||  \n"); break;
        case 3 : printf("       |||||          |||||||||||||     ||||     ||||| \n"); break;
        case 4 : printf("       |||||          |||||||||||||     ||||     ||||  \n"); break;
        case 5 : printf("       |||||          |||||||||||||     ||||||||||||   \n"); break;
        case 6 : printf("       |||||          ||||||  |||||     |||||||||||    \n"); break;
        case 7 : printf("       |||||          ||||||  |||||     ||||||||||     \n");break;
        case 8 : printf("Criado por Álvaro Basílio ©‎ 2019 , Todos os direitos reservados\n"); break;
        case 9: printf(">>>>>>>>>>>>>>>>| DIGITE UMA OPÇÃO |<<<<<<<<<<<<<<<<\n\n");break;
        case 10: printf(" -> 1 - CLIENTES \n\n -> 2 - PRODUTOS  \n\n -> 3 - VENDAS  \n\n -> 4 - PROVA \n\n");break;
        case 11: printf(" -> 5 -  SAIR   "); break;
        case 12: printf("\n OPÇÃO -----> "); break;
    }
  }
}
void MENU_PROVA(){
    limparConsole();
   printf(">>>>>>>>>>>>>>>>>>>> PROVA <<<<<<<<<<<<<<<<<<<\n");
   printf("\n\n\t 1-> Questão 1 - produto mais Vendido");
   printf("\n\t 2-> Questão 2 - Vendas a vista");
   printf("\n\t 3-> Questão 3 - Mesma venda cliente");
   printf("\n\t 4-> Questão 4a) - Nota fiscal");
   printf("\n\t -> Questao 4b) Esta questão esta no código");
   printf("\n\t -> 5 - RETORNAR AO MENU PRINCIPAL "); 
}
void MSG_SUB(int numeroModulo, char nome[], char menu[]){
  limparConsole();
  printf(">>>>>>>>>>>>>>>>>>>> MODULO %d <<<<<<<<<<<<<<<<<<<\n", numeroModulo);
  printf(">>>>>>>>>>>>>>>>>>>> %s <<<<<<<<<<<<<<<<<<<<<<<<<<\n", menu);
  printf("\n\n\t -> 1 - INSERIR %s", nome);
  printf("\n\t -> 2 - PESQUISAR %s", nome);
  printf("\n\t -> 3 - ALTERAR %s", nome);
  printf("\n\t -> 4 - EXCLUIR %s", nome);
  printf("\n\t -> 5 - IMPRIMIR %s", menu);
  printf("\n\t -> 6 - RETORNAR AO MENU PRINCIPAL ");
}
 void SubMenuProva(ModuloVendas Vendas, ModuloProdutos Produtos){
     limpezaDoBuffer();
     int opcao;
     TCliente c1, c2;
     TData data;
     do{
         printf("\nDIGITE UMA OPÇÃO ------> ");
         scanf("%d", &opcao);
         switch (opcao)
         {
            case 1: produtoMaisVendido(Vendas, Produtos);
                    MENU_PROVA();break;
            case 2: vendasAVista(Vendas);
            MENU_PROVA();break;
            case 3: 
                    limparConsole();
                    printf("Digite o cpf/cnpj do primeiro cliente ");
                    limpezaDoBuffer();
                    fgets(c1.ID, TAM, stdin);
                    formatador(c1.ID);
                    printf("Digite o cpf/cnpj do segundo cliente ");
                    limpezaDoBuffer();
                    fgets(c2.ID, TAM, stdin);
                    formatador(c2.ID);
                    clientesIguais(Vendas, c1, c2, Produtos);
                    MENU_PROVA();break;
            case 4: 
                    printf("Digite o cpf/cnpj do cliente ");
                    limpezaDoBuffer();
                    fgets(c1.ID, TAM, stdin);
                    formatador(c1.ID);
                    printf("Digite o dia ");
                    limpezaDoBuffer();
                    scanf("%d", &data.dia);
                    printf("Digite o mes ");
                    limpezaDoBuffer();
                    scanf("%d", &data.mes);
                    printf("Digite o ano ");
                    limpezaDoBuffer();
                    scanf("%d", &data.ano);
                    NotaFiscal(Vendas, c1, data); 
                    MENU_PROVA();
                    break;
            case 5: break;
            default : printf("Digite uma opção válida");
                    limparConsole();
                    limpezaDoBuffer();
                    getchar();
                    MENU_PROVA();
         }
     } while (opcao != 5);
     
 }
void SubMenuModulo1(ModuloClientes* Cliente, TCliente clientes){
    int opcao;
    int resposta;
    do{
      printf("\nDIGITE UMA OPÇÃO ------> ");
      scanf("%d", &opcao);
      switch (opcao){
          case 1: lerCliente(&clientes);
                  imprimeInfoCliente(clientes);
                  inserirCliente(Cliente, clientes);
                  MSG_SUB(1, "CLIENTE", "CLIENTES");
                  break;
          case 2: 
                limparConsole();
                printf("Digite o CPF/CNPJ do clinete: ");
                limpezaDoBuffer();
                fgets(clientes.ID, 49, stdin);
                formatador(clientes.ID);
                limparConsole();
                resposta = pesquisarCliente(*Cliente, clientes);
                if(resposta != -1){
                    printf("\tCliente encontrado : %s imprimindo informações...", Cliente->listaDeClientes[resposta].nome);
                    imprimeInfoCliente(Cliente->listaDeClientes[resposta]);
                    MSG_SUB(1, "CLIENTE", "CLIENTES");
                }else{
                    limpezaDoBuffer();
                    limparConsole();
                    printf("\tCliente não encontrado! Retornando ao menu...\n");
                    printf("PRESSIONE ENTER PARA CONTINUAR");
                    getchar();
                    MSG_SUB(1, "CLIENTE", "CLIENTES");
                }
                break;
          case 3: 
                  limparConsole();
                  printf("Digite o CPF/CNPJ do clinte para ser alterado: ");
                  limpezaDoBuffer();
                  fgets(clientes.ID, TAM, stdin);
                  formatador(clientes.ID);
                  alterarCliente(Cliente,clientes);
                  MSG_SUB(1, "CLIENTE", "CLIENTES");
                  break;
          case 4: 
                  limparConsole();
                  printf("Digite o CPF/CNPJ do clinte para ser excluído: ");
                  limpezaDoBuffer();
                  fgets(clientes.ID, TAM, stdin);
                  formatador(clientes.ID);
                  excluirCliente(Cliente, clientes);
                  MSG_SUB(1, "CLIENTE", "CLIENTES");
                  break;
          case 5: imprimirTodosOsClientes(*Cliente);
                  MSG_SUB(1, "CLIENTE", "CLIENTES");
                  break;
          case 6: break;
          default:
                limparConsole();
                printf("-------------------------\n");
                printf("DIGITE UMA OPÇÃO VÁLIDA!!\n");
                printf("-------------------------\n");
                limpezaDoBuffer();
                printf("PRESSIONE ENTER PARA CONTINUAR");
                getchar();
                limparConsole();
                MSG_SUB(1, "CLIENTE", "CLIENTES");
                break;
      }
    }while (opcao != 6);
}
    
void SubMenuModulo2(ModuloProdutos* Produto, TProdutos produtos){
    int opcao;
    int resposta;
    do{
      printf("\nDIGITE UMA OPÇÃO ------> ");
      scanf("%d", &opcao);
      switch (opcao){
          case 1: lerProduto(&produtos);
                  imprimeInfoProduto(produtos);
                  inserirProduto(Produto, produtos);
                  MSG_SUB(2, "PRODUTO", "PRODUTOS");
                  break;
          case 2: 
                limparConsole();
                printf("Digite o código do produto: ");
                limpezaDoBuffer();
                scanf("%d", &produtos.codigoDoProd);
                limparConsole();
                resposta = pesquisarProduto(*Produto, produtos);
                if(resposta != -1){
                    printf("Produto encontrado: %s  imprimindo informações...", Produto->listaDeProdutos[resposta].nomeDoProd);
                    imprimeInfoProduto(Produto->listaDeProdutos[resposta]);
                    MSG_SUB(2, "PRODUTO", "PRODUTOS");
                }else{
                    limpezaDoBuffer();
                    limparConsole();
                    printf("\tProduto não encontrado! Retornando ao menu...\n");
                    printf("PRESSIONE ENTER PARA CONTINUAR");
                    getchar();
                    MSG_SUB(2, "PRODUTO", "PRODUTOS");
                }
                break;
          case 3: 
                  limparConsole();
                  printf("Digite o código do produto para ser alterado: ");
                  limpezaDoBuffer();
                  scanf("%d", &produtos.codigoDoProd);
                  alterarProduto(Produto, produtos);
                  MSG_SUB(2, "PRODUTO", "PRODUTOS");
                  break;
          case 4: 
                  limparConsole();
                  printf("Digite o código do produto para ser excluído: ");
                  limpezaDoBuffer();
                  scanf("%d", &produtos.codigoDoProd);
                  excluirProduto(Produto, produtos);
                  MSG_SUB(2, "PRODUTO", "PRODUTOS");
                  break;
          case 5: imprimirTodosOsProdutos(*Produto); 
                  MSG_SUB(2, "PRODUTO", "PRODUTOS");
                  break;
          case 6: break;
          default:
                limparConsole();
                printf("-------------------------\n");
                printf("DIGITE UMA OPÇÃO VÁLIDA!!\n");
                printf("-------------------------\n");
                limpezaDoBuffer();
                printf("PRESSIONE ENTER PARA CONTINUAR");
                getchar();
                limparConsole();
                MSG_SUB(2, "PRODUTO", "PRODUTOS");
                break;
      }
    }while (opcao != 6);
}

void SubMenuModulo3(ModuloVendas* Vendas, TVendas vendas, ModuloProdutos *Produtos, ModuloClientes *Cliente){
    int opcao;
    int resposta;
    TCliente cliente;
    TProdutos produtos;
    do{
      printf("\nDIGITE UMA OPÇÃO ------> ");
      scanf("%d", &opcao);
      switch (opcao){
          case 1: resposta = lerVendas(&vendas, Cliente, Produtos);
                  if(resposta != -1){
                    imprimeVendas(vendas);
                    inserirVendas(Vendas, vendas);
                    MSG_SUB(3, "VENDA", "VENDAS");
                  }else{
                      printf("\nIMPOSSÍVEL CONCLUIR VENDA");
                      printf("\nPRESSIONER ENTER PARA CONTINUAR");
                      getchar();
                      limparConsole();
                      MSG_SUB(3, "VENDA", "VENDAS");
                  }
                  break;
          case 2: 
                limparConsole();
                limpezaDoBuffer();
                printf("Digite o CPF/CNPJ do comprador: ");
                fgets(cliente.ID, TAM, stdin);
                formatador(cliente.ID);
                printf("Digite o código do produto: ");
                scanf("%d", &produtos.codigoDoProd);
                resposta = pesquisarVendas(*Vendas, *Produtos, *Cliente, cliente, produtos);
                if(resposta != -1){
                    printf("\tVenda encontrada: %d  imprimindo informações...", Vendas->vendasRealizadas[resposta].codigo);
                    imprimeVendas(Vendas->vendasRealizadas[resposta]);
                    MSG_SUB(3, "VENDA", "VENDAS");
                }else{
                    limpezaDoBuffer();
                    limparConsole();
                    printf("\tVenda não encontrada! Retornando ao menu...\n");
                    printf("PRESSIONE ENTER PARA CONTINUAR");
                    getchar();
                    MSG_SUB(3, "VENDA", "VENDAS");
                }
                break;
          case 3: 
                limparConsole();
                limpezaDoBuffer();
                printf("Digite o CPF/CNPJ do comprador: ");
                fgets(cliente.ID, TAM, stdin);
                formatador(cliente.ID);
                printf("Digite o código do produto: ");
                scanf("%d", &produtos.codigoDoProd);
                resposta = pesquisarVendas(*Vendas, *Produtos, *Cliente, cliente, produtos);
                if(resposta != -1){
                    printf("\nVenda encontrada: %d  pressione ENTER para alterar a mesma...\n", Vendas->vendasRealizadas[resposta].codigo);
                    imprimeVendas(Vendas->vendasRealizadas[resposta]);
                    alterarVenda(Vendas, Produtos, Cliente, cliente, produtos);
                    MSG_SUB(3, "VENDA", "VENDAS");
                }else{
                    limpezaDoBuffer();
                    limparConsole();
                    printf("\tVenda não encontrada! Retornando ao menu...\n");
                    printf("PRESSIONE ENTER PARA CONTINUAR");
                    getchar();
                    MSG_SUB(3, "VENDA", "VENDAS");
                }
                break;
          case 4: 
                limparConsole();
                limpezaDoBuffer();
                printf("Digite o CPF/CNPJ do comprador: ");
                fgets(cliente.ID, TAM, stdin);
                formatador(cliente.ID);
                printf("Digite o código do produto: ");
                scanf("%d", &produtos.codigoDoProd);
                resposta = pesquisarVendas(*Vendas, *Produtos, *Cliente, cliente, produtos);
                if(resposta != -1){
                    printf("\nVenda encontrada: %d  pressione ENTER para excluir a mesma...\n", Vendas->vendasRealizadas[resposta].codigo);
                    imprimeVendas(Vendas->vendasRealizadas[resposta]);
                    excluirVendas(Vendas, Cliente, Produtos, cliente, produtos);
                    MSG_SUB(3, "VENDA", "VENDAS");
                }else{
                    limparConsole();
                    limpezaDoBuffer();
                    printf("\tVenda não encontrada! Retornando ao menu...\n");
                    printf("PRESSIONE ENTER PARA CONTINUAR");
                    getchar();
                    MSG_SUB(3, "VENDA", "VENDAS");
                }
                break;
          case 5: imprimirTodasAsVendas(*Vendas);
                  MSG_SUB(3, "VENDA", "VENDAS");
                  break;
          case 6: break;
          default:
                limparConsole();
                printf("-------------------------\n");
                printf("DIGITE UMA OPÇÃO VÁLIDA!!\n");
                printf("-------------------------\n");
                limpezaDoBuffer();
                printf("PRESSIONE ENTER PARA CONTINUAR");
                getchar();
                limparConsole();
                MSG_SUB(3, "VENDA", "VENDAS");
                break;
      }
    }while (opcao != 6);
}  

void Menu(ModuloClientes* Cliente, TCliente Clientes, ModuloProdutos* Produtos,
TProdutos Produto, ModuloVendas* Vendas, TVendas Venda){
    int opcao;
    do{
        MSG_MENU_PRINCIPAL();
        scanf("%d", &opcao);
        switch (opcao){
            case 1:
                MSG_SUB(opcao, "CLIENTE", "CLIENTES");
                SubMenuModulo1(Cliente, Clientes);
                break;
            case 2:
                MSG_SUB(opcao, "PRODUTO", "PRODUTOS");
                SubMenuModulo2(Produtos, Produto);
                break;
            case 3:
                MSG_SUB(opcao, "VENDA", "VENDAS");
                SubMenuModulo3(Vendas, Venda, Produtos, Cliente);
                break;
            case 4:
                MENU_PROVA();
                SubMenuProva(*Vendas, *Produtos);
                break;
            case 5:
                printf("\n\n");
                printf("SAINDO DO PROGRAMA...\n");
                printf("Obrigado por utilizar!!!!!\n");
                printf("...\n");
                break;
            default:
                limparConsole();
                printf("-------------------------\n");
                printf("DIGITE UMA OPÇÃO VÁLIDA!!\n");
                printf("-------------------------\n");
                limpezaDoBuffer();
                printf("\nPRESSIONE ENTER PARA CONTINUAR");
                getchar();
                limparConsole();
                break;
        }
    } while (opcao != 5);
  
}
