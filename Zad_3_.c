#include <stdio.h>

int main() {
    int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int size = sizeof(array) / sizeof(array[0]);

    int silnia;
    for(int i = 0; i < 10; i++){
        if (array[i] == 0 || array[i] == 1)
            silnia = 1;
        else
            silnia = array[i] * silnia;
            printf("Silnia %i\n",silnia);
    }
}