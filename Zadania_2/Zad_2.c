#include <stdio.h>

void doDouble(float *a){
    *a *= 2;
}

int main() {
    float a = 1;
    printf("Przed zmiana: %.2f\n", a);
    doDouble(&a);
    printf("Po zmianie: %.2f\n", a);

    return 0;
}