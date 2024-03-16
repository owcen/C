#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int **createAndFillMatrix(int rows, int cols) {
    int **matrix = (int **)malloc(rows * sizeof(int *));
    if (matrix == NULL) {
        printf("Pusta macierz\n");
    }

    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
        if (matrix[i] == NULL) {
            printf("Pusta macierz\n");
        }
    }

    srand(time(NULL));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 90 + 10;
        }
    }

    return matrix;
}

void printMatrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void freeMatrix(int **matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

int main() {
    int rows, cols;

    printf("Podaj liczbe wierszy macierzy: \n");
    scanf("%d", &rows);
    printf("Podaj liczbe kolumn macierzy: \n");
    scanf("%d", &cols);

    int **matrix = createAndFillMatrix(rows, cols);
    printMatrix(matrix, rows, cols);
    freeMatrix(matrix, rows);

    return 0;
}