#include <stdio.h>

unsigned long long factorial(int n){
    if (n == 0 || n ==1)
        return 1;
    else
        return n * factorial(n - 1);
}

int main(){
    int n;
    printf("Podaj liczbe calkowita\n");
    scanf("%d", &n);
    printf("Silnia z liczby %d wynosi %llu\n", n, factorial(n));

    return 0;
}