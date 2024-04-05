#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void permute(int *array, int start, int end) {
    if (start == end) {
        for (int i = 0; i <= end; i++)
            printf("%d ", array[i]);
        printf("\n");
    } else {
        for (int i = start; i <= end; i++) {
            int is_used = 0;
            for (int j = start; j < i; j++) {
                if (array[j] == array[i]) {
                    is_used = 1;
                    break;
                }
            }

            if (!is_used) {
                swap(&array[start], &array[i]);
                permute(array, start + 1, end);
                swap(&array[start], &array[i]);
            }
        }
    }
}

int main() {
    int array[] = {1, 2, 3};
    int length = sizeof(array) / sizeof(array[0]);

    printf("Permutacje ciagu:\n");
    permute(array, 0, length - 1);

    return 0;
}