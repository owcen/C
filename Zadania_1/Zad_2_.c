#include <stdio.h>

int main() {
    int grades[][5]= {{1,2,3,4,5},
                       {1,2,3,4,5}};

    int sum = 0;
    for (int j=0; j <2; j++) {
        for (int i = 0; i < 5; i++) {
            sum += grades[j][i];
        }
    }

    int length = sizeof(grades)/sizeof(grades[0][0]);

    double avg = (double)sum/(double)length;
    printf("Suma: %i\n", sum);
    printf("Srednia: %.2f\n", avg);

    return 0;
}