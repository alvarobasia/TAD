#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>

void limpezaDoBuffer(){
    __fpurge(stdin);
    fflush(stdin); 
}

void limparConsole(){
    system("clear");
    system("cls");
}
