#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void BubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
void InsertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
void SelectionSort(int arr[], int n) {
    int i, j, min_idx;

    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
}
void generateRandomArray(int arr[], int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100; 
    }
}
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main() {
    int n, i;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr_bubble[n], arr_insertion[n], arr_selection[n];
    generateRandomArray(arr_bubble, n);
    for (i = 0; i < n; i++) {
        arr_insertion[i] = arr_bubble[i];
        arr_selection[i] = arr_bubble[i];
    }
    clock_t start_time, end_time;
    double cpu_time_used_bubble, cpu_time_used_insertion, cpu_time_used_selection;
    start_time = clock();
    BubbleSort(arr_bubble, n);
    end_time = clock();
    cpu_time_used_bubble = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    start_time = clock();
    InsertionSort(arr_insertion, n);
    end_time = clock();
    cpu_time_used_insertion = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    start_time = clock();
    SelectionSort(arr_selection, n);
    end_time = clock();
    cpu_time_used_selection = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Sorted array: ");
    printArray(arr_selection, n);
    printf("Time required by bubble sort: %f seconds\n", cpu_time_used_bubble);
    printf("Time required by insertion sort: %f seconds\n", cpu_time_used_insertion);
    printf("Time required by selection sort: %f seconds\n", cpu_time_used_selection);
    return 0;
}