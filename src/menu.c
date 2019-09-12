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
#define AZU "\x1b[32m"

void MSG_MENU_PRINCIPAL(){
    for(int i = 0; i < 9 ; i++){
      switch (i){
      case 0 : printf(INTEN AZU "\n");break; 
      case 1 : printf(" |----------------|              |-----|             |---------|\n");break;
      case 2 : printf(" |------   -------|             |   --  |            |          |\n"); break;
      case 3 : printf("       |   |                   |   |  |  |           |  |---|    |\n"); break;
      case 4 : printf("       |   |                  |     --    |          |  |    |    |\n"); break;
      case 5 : printf("       |   |                  |           |          |  |     |  |\n"); break;
      case 6 : printf("       |   |                  |    |--|   |          |  |----|  |\n"); break;
      case 7 : printf("       |   |                  |    |  |   |          |         |\n"); break;
      case 8 : printf("       |---|                  |----|  |---|          |--------|\n" SUBDES BOLD);break;
    }
}
}
void Menu(){
  MSG_MENU_PRINCIPAL();
}
