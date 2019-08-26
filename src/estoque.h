#include <stdlib.h>
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
    char complemento;
    char cep;
    int numero;
} TEndereco;