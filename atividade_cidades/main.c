#include <stdio.h>
#include <stdlib.h>
#include "cidades.h"
#include "cidades.c"

int main() {
    
    const char *arquivo = "arquivo.txt";
    
    Estrada *estrada = getEstrada(arquivo);
    
    if (estrada == NULL) {
        printf("Erro ao ler arquivo\n");
        return 1;
    }
    
    double menorVizinhanca = calcularMenorVizinhanca(arquivo);
    char *cidade = cidadeMenorVizinhanca(arquivo);
    
    printf("Comprimento da estrada: %d\n", estrada->T);
    printf("Número de cidades: %d\n", estrada->N);
    
    for(int i = 0; i < estrada->N; i++){
        printf("Posição: %d, Cidade: %s\n", estrada->C[i].Posicao, estrada->C[i].Nome);
    }
    
    printf("Menor vizinhança: %.2f\n", menorVizinhanca);
    printf("Cidade com menor vizinhança: %s\n", cidade);
    
    free(estrada->C);
    free(estrada);
    
    return 0;
}
