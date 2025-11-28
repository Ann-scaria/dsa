#include <stdio.h> 
void swap(int *a, int *b, int *swaps) { 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
    (*swaps)++; 
} 
int partition(int arr[], int low, int high, int *comparisons, int *swaps) { 
    int pivot = arr[high]; 
    int i = low - 1; 
    for (int j = low; j < high; j++) { 
        (*comparisons)++; 
        if (arr[j] <= pivot) { 
            i++; 
            if (i != j) 
                swap(&arr[i], &arr[j], swaps); 
        } 
    } 
    if (i + 1 != high) 
        swap(&arr[i + 1], &arr[high], swaps); 
    return i + 1; 
} 
void quick_sort(int arr[], int low, int high, int *comparisons, int *swaps) { 
    if (low < high) { 
        int pi = partition(arr, low, high, comparisons, swaps); 
        quick_sort(arr, low, pi - 1, comparisons, swaps); 
        quick_sort(arr, pi + 1, high, comparisons, swaps); 
    } 
} 
void print_array(int arr[], int n) { 
    for (int i = 0; i < n; i++) 
printf("%d ", arr[i]); 
printf("\n"); 
} 
int main() { 
int n; 
int comparisons = 0, swaps = 0; 
printf("Enter the number of elements: "); 
scanf("%d", &n); 
int arr[n]; 
printf("Enter %d elements: ", n); 
for (int i = 0; i < n; i++) 
scanf("%d", &arr[i]); 
printf("\nOriginal array: "); 
print_array(arr, n); 
quick_sort(arr, 0, n - 1, &comparisons, &swaps); 
printf("Sorted array (Quick Sort): "); 
print_array(arr, n); 
printf("Number of comparisons (Quick Sort): %d\n", comparisons); 
printf("Number of swaps (Quick Sort): %d\n", swaps); 
return 0; 
} 
