#include "../inc/libmx.h"

static int partition(char **arr, int left, int right, int *swaps) {
    int pivot_len = mx_strlen(arr[(left + right) / 2]);

    while (left <= right) {
        while (mx_strlen(arr[left]) < pivot_len) left++;
        while (mx_strlen(arr[right]) > pivot_len) right--;

        if (left <= right) {
            if (mx_strlen(arr[left]) != mx_strlen(arr[right])) {
                mx_swap_str(&arr[left], &arr[right]);
                (*swaps)++;
            }
            left++;
            right--;
        }
    }

    return left;
}

int mx_quicksort(char **arr, int left, int right) {
    if (!arr) return -1;

    int swaps = 0;

    if (left < right) {
        int pivotIndex = partition(arr, left, right, &swaps);

        swaps += mx_quicksort(arr, left, pivotIndex - 1);
        swaps += mx_quicksort(arr, pivotIndex, right);
    }

    return swaps;
}
