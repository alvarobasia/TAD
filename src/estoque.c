#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>

void limpezaDoBuffer(){
    #ifdef unix
        __fpurge(stdin);
    #elif _WIN32 
        fflush(stdin);
    #endif
}

void limparConsole(){
    #ifdef unix
       system("clear");
    #elif _WIN32
       system("cls");
    #endif
}

void formatador(char string[]){
    int i = strlen(string);
    string[i-1] = '\0';   
}