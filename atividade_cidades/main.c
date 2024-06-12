#include <stdio.h>
#include <stdlib.h>
#include "cidades.h"
#include "cidades.c"

int main() {
    
    const char *arquivo = "arquivo.txt";
    
    Estrada *estrada = getEstrada(arquivo);
    
    calcularMenorVizinhanca(arquivo);
    
    cidadeMenorVizinhanca(arquivo);

	return 0;
    
}
