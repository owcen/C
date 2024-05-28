#include <stdio.h>

int dodaj(int a, int b) {
    return a + b;
}

int mnoz(int a, int b) {
    return a * b;
}

int odejmij(int a, int b) {
    return a - b;
}

int main() {
    int wybor;
    int a, b;
    int wynik;

    int (*operacja)(int, int);

    printf("Wybierz operacje do wykonania:\n1. Dodawanie\n2. Mnozenie\n3. Odejmowanie\n");
    scanf("%d", &wybor);

    printf("Podaj dwie liczby: \n");
    scanf("%d %d", &a, &b);

    switch (wybor) {
        case 1:
            operacja = &dodaj;
            break;
        case 2:
            operacja = &mnoz;
            break;
        case 3:
            operacja = &odejmij;
            break;
        default:
            printf("Nieprawidłowy wybór.\n");
            return 1;
    }

    wynik = operacja(a, b);
    printf("Wynik: %d\n", wynik);

    return 0;
}
