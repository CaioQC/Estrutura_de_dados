#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define a struct Ponto para as coordenadas x e y.
typedef struct {
    float x;
    float y;
} Ponto;

// Faz a chamada das funções.
float AreaTriangulo(Ponto A, Ponto B, Ponto C);
Ponto* LerVertice(int* num_vertices);
float AreaPoligono(Ponto* vertices, int num_vertices);

// Função para calcular a área dos triângulos.
float AreaTriangulo(Ponto A, Ponto B, Ponto C) {
    float det = A.x * (B.y - C.y) + B.x * (C.y - A.y) + C.x * (A.y - B.y);
    return fabs(det / 2);
}

// Função para ler o número de vértices do polígono.
Ponto* LerVertice(int* num_vertices) {
    
// Abre o arquivo em modo de leitura.
    FILE *fp;
    fp = fopen("vertices.txt", "r");
    if(fp == NULL) {
        printf("Erro na abertura do arquivo!\n");
        exit(1);
    }

// Escaneia a quantidade de vértices do polígono.
    fscanf(fp, "%d", num_vertices);
    Ponto* vertices = malloc(sizeof(Ponto) * (*num_vertices));

// Escaneia as coordenadas dos vértices do polígono.
    for(int i = 0; i < *num_vertices; i++){
        fscanf(fp, "%f %f", &vertices[i].x, &vertices[i].y);
    }

//  Fecha o arquivo.
    fclose(fp);
    return vertices;
}

// Função para calcular a área do polígono.
float AreaPoligono(Ponto* vertices, int num_vertices) {
    float areaTotal = 0;

// Calcula a somatória da área dos triângulos que formam o polígono.
    for(int i = 0; i < num_vertices - 2; i++){
        areaTotal += AreaTriangulo(vertices[0], vertices[i+1], vertices[i+2]);
    }

// Retorna a área total do polígono.
    return areaTotal;
}

int main() {
    int num_vertices;
    Ponto* vertices = LerVertice(&num_vertices);

//  Imprime a área do polígono.
    if(num_vertices > 0){
        float area = AreaPoligono(vertices, num_vertices);
        printf("A área do polígono é: %.2f\n", area);
    } else {
        printf("Não foi possível ler os vertices do arquivo.");
    }

// Libera a memória alocada para os vértices.
    free(vertices);
    return 0;
}