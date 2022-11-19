#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define FIL 4
#define COL 3

void rellenaMatrizAleatorio(int m[][COL]);
void imprimeMatriz(int m[][COL]);
void maxFilMatriz(int m[][COL],int fila);
void minColMatriz(int m[][COL],int colu);
float mediaTotalMatriz(int m[][COL]);
void imprimeMaxMin(int m[][COL]);


int main() {
    int matriz[FIL][COL];
    rellenaMatrizAleatorio(matriz);
    printf("\nMATRIZ:\n");
    imprimeMatriz(matriz);
    printf("\nLa media de los elementos pares es de %.2f.", mediaTotalMatriz(matriz));
    imprimeMaxMin(matriz);
    return 0;
}

void rellenaMatrizAleatorio(int m[][COL]){
    srand(time(NULL));
    for (int i = 0; i < FIL; ++i) {
        for (int j = 0; j < COL; ++j) {
            m[i][j]=rand()%100;
        }
    }
}

void maxFilMatriz(int m[][COL],int fila){
    int max=m[fila][0];
    for (int i = 0; i < COL; ++i) {
        if (max<m[fila][i])
            max=m[fila][i];
    }
    printf("%d, ",max);
}

void minColMatriz(int m[][COL],int colu){
    int min=m[0][colu];
    for (int i = 0; i < FIL; ++i) {
        if (min>m[i][colu])
            min=m[i][colu];
    }
    printf("%d, ",min);
}

float mediaTotalMatriz(int m[][COL]){
    int pares=0;
    float suma=0;
    for (int i = 0; i < FIL; ++i) {
        for (int j = 0; j < COL; ++j) {
            if (m[i][j]%2==0){
                pares++;
                suma=suma+m[i][j];
            }
        }
    }
    return suma/(float)pares;
}

void imprimeMaxMin(int m[][COL]){
    printf("\nLos maximos elementos de cada fila son: ");
    for (int i = 0; i < FIL; ++i) {
        maxFilMatriz(m,i);
    }
    printf("\nLos minimos elementos de cada columna son: ");
    for (int i = 0; i < COL; ++i) {
        minColMatriz(m,i);
    }
    printf("\n");
}

void imprimeMatriz(int m[][COL]){
    printf("\n|-------|-------|-------|\n");
    for (int i = 0; i < FIL; ++i) {
        printf("|");
        for (int j = 0; j < COL; ++j) {
            printf("%4d   |",m[i][j]);
        }
        printf("\n|-------|-------|-------|\n");
    }
}