#include <stdio.h>

int main() {
    int a = 10;
    int *pA = &a;
    printf("Zmienna bezposrednio: %d\n", a);
    printf("Zmienna przez wskaznik: %d\n\n", *pA);

    *pA = 20;
    printf("Zmienna bezposrednio: %d\n", a);
    printf("Zmienna przez wskaznik: %d\n", *pA);
    return 0;
};