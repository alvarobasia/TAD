#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#ifndef ESTOQUE_H_INCLUDED
#define ESTOQUE_H_INCLUDED
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

void limpezaDoBuffer();

void limparConsole();

void formatador(char string[]);

#endif