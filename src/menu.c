#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <unistd.h> 
#include "menu.h"
#include "vendas.h"

void MSG_MENU_PRINCIPAL(){
      limparConsole();
      for(int i = 0; i < 18 ; i++){
      switch (i){
        case 0 : printf(INTEN AZU AMA"\n");break; 
        case 1 : printf(" ||||||||||||||||||      |||||||        ||||||||||     \n");break;
        case 2 : printf(" ||||||||||||||||||     |||||||||       |||||||||||    \n"); break;
        case 3 : printf("       |||||           |||||  ||||      |||||||||||||  \n"); break;
        case 4 : printf("       |||||          |||||||||||||     ||||     ||||| \n"); break;
        case 5 : printf("       |||||          |||||||||||||     ||||     ||||  \n"); break;
        case 6 : printf("       |||||          |||||||||||||     ||||||||||||   \n"); break;
        case 7 : printf("       |||||          ||||||  |||||     |||||||||||    \n"); break;
        case 8 : printf("       |||||          ||||||  |||||     ||||||||||     \n");break;
        case 9 : printf("Criado por Álvaro Basílio ©‎ 2019 , Todos os direitos reservados\n"); break;
        case 10: printf(DEFAULT GREEN"\n");break;
        case 11: printf(">>>>>>>>>>>>>>>>| DIGITE UMA OPÇÃO |<<<<<<<<<<<<<<<<\n\n");break;
        case 12: printf(DEF_LETRA);break;
        case 13: printf(" → 1 - CLIENTES ☺  ☻  ☺\n\n → 2 - PRODUTOS ☎  ☂  ✎ \n\n → 3 - VENDAS   ＄ ＄ ＄\n\n");break;
        case 14: printf(RED);break;
        case 15: printf(" → 4 -  SAIR    ✘  ✘  ✘"); break;
        case 16: printf(DEF_LETRA"\n");break;
        case 17: printf("\n OPÇÃO -----> "); break;
    }
  }
}
void MSG_SUB(int numeroModulo, char nome[], char menu[]){
  limparConsole();
  printf(GREEN);
  printf(">>>>>>>>>>>>>>>>>>>> MODULO %d <<<<<<<<<<<<<<<<<<<\n", numeroModulo);
  printf(">>>>>>>>>>>>>>>>>>>> %s <<<<<<<<<<<<<<<<<<<<<<<<<<\n", menu);
  printf(DEF_LETRA);
  printf("\n\n\t → 1 - INSERIR %s", nome);
  printf("\n\t → 2 - PESQUISAR %s", nome);
  printf("\n\t → 3 - ALTERAR %s", nome);
  printf("\n\t → 4 - EXCLUIR %s", nome);
  printf(RED);
  printf("\n\t → 5 - RETORNAR AO MENU PRINCIPAL ");
  printf(DEF_LETRA);
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
                printf(GREEN);
                printf("Digite o CPF/CNPJ do clinete: ");
                printf(DEF_LETRA);
                limpezaDoBuffer();
                fgets(clientes.ID, 49, stdin);
                formatador(clientes.ID);
                limparConsole();
                resposta = pesquisarCliente(*Cliente, clientes);
                if(resposta != -1){
                    printf(GREEN);
                    printf("\tCliente encontrado : %s imprimindo informações...", Cliente->listaDeClientes[resposta].nome);
                    imprimeInfoCliente(Cliente->listaDeClientes[resposta]);
                    MSG_SUB(1, "CLIENTE", "CLIENTES");
                }else{
                    limparConsole();
                    printf(RED);
                    printf("\tCliente não encontrado! Retornando ao menu...\n");
                    sleep(2);
                    printf(DEF_LETRA);
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
          case 5: break;
          default:
                limparConsole();
                printf(RED);
                printf("-------------------------\n");
                printf("DIGITE UMA OPÇÃO VÁLIDA!!\n");
                printf("-------------------------\n");
                printf(DEF_LETRA);
                limpezaDoBuffer();
                sleep(2);
                limparConsole();
                MSG_SUB(1, "CLIENTE", "CLIENTES");
                break;
      }
    }while (opcao != 5);
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
                printf(GREEN);
                printf("Digite o código do produto: ");
                printf(DEF_LETRA);
                limpezaDoBuffer();
                scanf("%d", &produtos.codigoDoProd);
                limparConsole();
                resposta = pesquisarProduto(*Produto, produtos);
                if(resposta != -1){
                    printf(GREEN);
                    printf("Produto encontrado: %s  imprimindo informações...", Produto->listaDeProdutos[resposta].nomeDoProd);
                    imprimeInfoProduto(Produto->listaDeProdutos[resposta]);
                    MSG_SUB(2, "PRODUTO", "PRODUTOS");
                }else{
                    limparConsole();
                    printf(RED);
                    printf("\tProduto não encontrado! Retornando ao menu...\n");
                    sleep(2);
                    printf(DEF_LETRA);
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
          case 5: break;
          default:
                limparConsole();
                printf(RED);
                printf("-------------------------\n");
                printf("DIGITE UMA OPÇÃO VÁLIDA!!\n");
                printf("-------------------------\n");
                printf(DEF_LETRA);
                limpezaDoBuffer();
                sleep(2);
                limparConsole();
                MSG_SUB(2, "PRODUTO", "PRODUTOS");
                break;
      }
    }while (opcao != 5);
}

void SubMenuModulo3(ModuloVendas* Vendas, TVendas vendas, ModuloProdutos *Produtos, ModuloClientes *Cliente){
    int opcao;
    int resposta;
    do{
      printf("\nDIGITE UMA OPÇÃO ------> ");
      scanf("%d", &opcao);
      switch (opcao){
          case 1: lerVendas(&vendas, &Cliente, &Produtos);
                  imprimeVendas(vendas);
                  inserirVendas(&Vendas, vendas);
                  MSG_SUB(3, "VENDA", "VENDAS");
                  break;
          case 2: 
                limparConsole();
                printf(GREEN);
                resposta = pesquisarVendas(*Vendas, *Produtos, *Cliente);
                if(resposta != -1){
                    printf(GREEN);
                    printf("Venda encontrada: %s  imprimindo informações...", Vendas->vendasRealizadas[resposta].codigo);
                    imprimeVendas(Vendas->vendasRealizadas[resposta]);
                    MSG_SUB(3, "VENDA", "VENDAS");
                    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!
                }else{
                    limparConsole();
                    printf(RED);
                    printf("\tProduto não encontrado! Retornando ao menu...\n");
                    sleep(2);
                    printf(DEF_LETRA);
                    MSG_SUB(2, "PRODUTO", "PRODUTOS");
                }
                break;
                break;
          /*case 3: 
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
          case 5: break;
          default:
                limparConsole();
                printf(RED);
                printf("-------------------------\n");
                printf("DIGITE UMA OPÇÃO VÁLIDA!!\n");
                printf("-------------------------\n");
                printf(DEF_LETRA);
                limpezaDoBuffer();
                sleep(2);
                limparConsole();
                MSG_SUB(2, "PRODUTO", "PRODUTOS");
                break;*/
      }
    }while (opcao != 5);
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
                printf(DEF_LETRA);
                SubMenuModulo1(Cliente, Clientes);
                break;
            case 2:
                MSG_SUB(opcao, "PRODUTO", "PRODUTOS");
                printf(DEF_LETRA);
                SubMenuModulo2(Produtos, Produto);
                break;
            case 3:
                MSG_SUB(opcao, "VENDA", "VENDAS");
                printf(DEF_LETRA);
                SubMenuModulo3(Vendas, Venda, Produtos, Cliente);
                break;
            case 4:
                printf("\n\n");
                printf("SAINDO DO PROGRAMA...\n");
                sleep(1);
                printf("...\n");
                sleep(2);
                break;
            default:
                limparConsole();
                printf(RED);
                printf("-------------------------\n");
                printf("DIGITE UMA OPÇÃO VÁLIDA!!\n");
                printf("-------------------------\n");
                printf(DEF_LETRA);
                limpezaDoBuffer();
                sleep(3);
                limparConsole();
                break;
        }
    } while (opcao != 4);
  
}
