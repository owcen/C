#include <stdio.h>

int main(){
    int n;
    printf("Podaj liczbe\n");
    scanf("%i", &n);

    int sum = 0;
    for(int i = 0; i < n; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            sum += i;
        }
    }

    if (sum <= 0){
        sum = 0;
    }

    printf("Suma: %i", sum);
    return 0;
};