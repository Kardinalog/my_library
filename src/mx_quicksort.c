#include "../inc/libmx.h"

int mx_partition(char** arr, int left, int right) {
    int i = left, j = right;
    int swaps = 0;
    int pivot = mx_strlen(arr[(left + right) / 2]);

    while (i <= j) {
        while (mx_strlen(arr[i]) < pivot)
            i++;
        while (mx_strlen(arr[j]) > pivot)
            j--;

        if (i <= j) {
            char* temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            swaps++;
            i++;
            j--;
        }
    }

    return swaps;
}

int mx_quicksort(char** arr, int left, int right) {
    if (arr == NULL)
        return -1;

    int swaps = 0;

    if (left < right) {
        int pivot_index = mx_partition(arr, left, right);
        swaps += mx_quicksort(arr, left, pivot_index);
        swaps += mx_quicksort(arr, pivot_index + 1, right);
    }

    return swaps;
}
