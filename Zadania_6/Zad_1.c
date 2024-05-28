#include <stdio.h>

union Types {
    int i;
    float f;
    char c;
};

int main() {

    union Types type;

    type.i = 42;
    printf("Przechowywana wartosc int: %d\n", type.i);

    type.f = 3.14;
    printf("Przechowywana wartosc float: %.2f\n", type.f);

    type.c = 'A';
    printf("Przechowywana wartosc char: %c\n", type.c);

    //printf("Przechowywana wartosc int: %d\n", type.i);

    return 0;
}
