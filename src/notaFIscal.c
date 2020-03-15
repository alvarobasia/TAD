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

void inicialNotaFiscal(ModulonotaFiscal* ModulonotaFiscal){
  ModulonotaFiscal->indice = 0;
}