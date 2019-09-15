#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include "menu.h"
#define RESET "\x1b[0m"	//Todos os atributos desativados (cor na inicialização)
#define INTEN "\x1b[1m"	//Negrito (ativar a intensidade do primeiro plano)
#define SUB "\x1b[4m"	//Sublinhar em
#define PISCAR "\x1b[5m"	//Piscar ativado (ativar a intensidade do plano de fundo)
#define BOLD "\x1b[21m"	//Negrito (desativar a intensidade do primeiro plano)
#define SUBDES "\x1b[24m"	//Sublinhado desativado
#define PISCARDES "\x1b[25m"	//Piscar desativado (desativar a intensidade do fundo)
#define AMA "\x1b[33m"
#define AZU "\x1b[44m"	
#define DEFAULT "\x1b[49m"
#define GREEN "\x1b[32m"
#define AZUL_LETRA "\x1b[34m"		
#define DEF_LETRA "\x1b[39m"
#define RED "\x1b[31m"		

void MSG_MENU_PRINCIPAL(){
    limparConsole();
    for(int i = 0; i < 16 ; i++){
      switch (i){
      case 0 : printf(INTEN AZU AMA"\n");break; 
      case 1 : printf(" ||||||||||||||||||      |||||||        ||||||||||\n");break;
      case 2 : printf(" ||||||||||||||||||     |||||||||       |||||||||||\n"); break;
      case 3 : printf("       |||||           |||||  ||||      |||||||||||||\n"); break;
      case 4 : printf("       |||||          |||||||||||||     ||||     |||||\n"); break;
      case 5 : printf("       |||||          |||||||||||||     ||||     ||||\n"); break;
      case 6 : printf("       |||||          |||||||||||||     ||||||||||||\n"); break;
      case 7 : printf("       |||||          ||||||  |||||     |||||||||||\n"); break;
      case 8 : printf("       |||||          ||||||  |||||     ||||||||||\n");break;
      case 9 : printf("Criado por Álvaro Basílio ©‎ 2019 , Todos os direitos reservados\n"); break;
      case 10: printf(DEFAULT GREEN"\n");break;
      case 11: printf(">>>>>>>>>>>>>>>>| DIGITE UMA OPÇÃO |<<<<<<<<<<<<<<<<\n\n");break;
      case 12: printf(DEF_LETRA);break;
      case 13: printf(" → 1 - CLIENTES ☺  ☻  ☺\n\n → 2 - PRODUTOS ☎  ☂  ✎ \n\n → 3 - VENDAS   ＄ ＄ ＄\n\n");break;
      case 14: printf(RED);break;
      case 15: printf(" → 4 -  SAIR    ✘  ✘  ✘"); break;
    }
}
}
void Menu(){
  int opcao = 0;
  do{
    MSG_MENU_PRINCIPAL();
    scanf("%d", &opcao);
  }while (opcao != 4);
 
  
}
