#include<time.h>
#include <stdio.h>
#include <stdlib.h>
int binarySearch(int arr[], int l, int r, int x)
{
	while (l <= r) {
		int m = l + (r - l) / 2;
		if (arr[m] == x)
			return m;
		if (arr[m] < x)
			l = m + 1;
		else
			r = m - 1;
	}
	return -1;
}
void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;
	int L[n1], R[n2];
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];
	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}
	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}
void mergeSort(int arr[], int l, int r)
{
	if (l < r) {
		int m = l + (r - l) / 2;
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}
void printArray(int A[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", A[i]);
	printf("\n");
}
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
int partition(int arr[], int low, int high)
{
	int pivot = arr[high];
	int i = (low - 1);
	for (int j = low; j <= high - 1; j++) {
		if (arr[j] < pivot) {
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}
void quickSort(int arr[], int low, int high)
{
	if (low < high) {
		int pi = partition(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}
void generateRandomArray(int arr[], int N) 
{
    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        arr[i] = rand() % 1000; 
    }
}
int main()
{
	int N, i, x=34;
    printf("Enter the size of the array: ");
    scanf("%d", &N);
    int arr[N];
    generateRandomArray(arr, N);
    clock_t start_time, end_time;
    double cpu_time_used_quick;
    double cpu_time_used_merge;
    double cpu_time_used_binary;
    start_time=clock();
	int result = binarySearch(arr, 0, N - 1, x);
    end_time=clock();
	if(result==-1)
     printf("Element not present in array.");
    else 
     printf("Element is present in array.");
    cpu_time_used_binary = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    start_time = clock();
	quickSort(arr, 0, N - 1);
    end_time = clock();
    cpu_time_used_quick = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    start_time = clock();
	mergeSort(arr, 0, N - 1);
    end_time = clock();
    cpu_time_used_merge = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("\nExecution time of Binary Searching : %f seconds.",cpu_time_used_binary);
    printf("\nExecution time of Quick Sort : %f seconds.",cpu_time_used_quick);
    printf("\nExecution time of Merge Sort : %f seconds.",cpu_time_used_merge);
	return 0;
}
 