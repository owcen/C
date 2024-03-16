#include <stdio.h>
#include <stdlib.h>

int binomialCoefficient(int n, int k) {
    if (k == 0 || k == n)
        return 1;
    else
        return binomialCoefficient(n - 1, k - 1) + binomialCoefficient(n - 1, k);
}

void printPascalTriangle(int N) {
    int **triangle = (int **)malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++) {
        triangle[i] = (int *)malloc((i + 1) * sizeof(int));
        for (int j = 0; j <= i; j++) {
            triangle[i][j] = binomialCoefficient(i, j);
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++)
            printf("%d ", triangle[i][j]);
        printf("\n");
    }

    for (int i = 0; i < N; i++) {
        free(triangle[i]);
    }
    free(triangle);
}

int main() {
    int N;
    printf("Podaj wysokosc trojkata Pascala: \n");
    scanf("%d", &N);
    printPascalTriangle(N);
    return 0;
}