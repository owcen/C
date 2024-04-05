#include <stdio.h>

int is_sorted(int arr[], int size) {
    for (int i = 1; i < size; i++){
        if (arr[i] < arr[i - 1])
            return 0;
    }
    return 1;
}

void bubble_sort(int arr[], int size){
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1]= temp;
            }
        }
    }
}

int binary_search(int arr[], int left, int right, int target) {
    if (right >= left) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
            return mid;

        if (arr[mid] == target)
            return mid;

        if (arr[mid] > target)
            return binary_search(arr, left, mid - 1, target);
        else
            return binary_search(arr, mid + 1, right, target);
    }
    return -1;
}

int main() {
    int arr[] = {1, 5, 9, 3, 12, 7, 4, 8, 14,0};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 4;

    if (!is_sorted(arr, n))
        bubble_sort(arr, n);

    for (int i = 0; i < n -1; i++ )
        printf("%d ", arr[i]);
    printf("\n");

    int result = binary_search(arr, 0, n-1, target);

    if (result == -1)
        printf("Element %d nie zostal znaleziony.\n", target);
    else
        printf("Element %d zostal znaleziony na indeksie %d.\n", target, result);

    return 0;
}