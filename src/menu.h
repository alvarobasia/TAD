#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "estoque.h"
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
#define TAM 50

void MSG_MENU_PRINCIPAL();
void Menu();

#endif