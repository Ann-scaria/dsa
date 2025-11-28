#include <stdio.h> 
void insertion_sort(int arr[], int n, int *comparisons, int *swaps) { 
    int i, j, key; 
    for (i = 1; i < n; i++) { 
        key = arr[i]; 
        j = i - 1; 
        while (j >= 0) { 
            (*comparisons)++; 
            if (arr[j] > key) { 
                arr[j + 1] = arr[j]; 
                (*swaps)++; 
                j--; 
            } else { 
                break; 
            } 
        } 
        if (j + 1 != i) { 
            arr[j + 1] = key; 
            (*swaps)++; 
        } 
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
insertion_sort(arr, n, &comparisons, &swaps); 
printf("Sorted array (Insertion Sort): "); 
print_array(arr, n); 
printf("Number of comparisons (Insertion Sort): %d\n", comparisons); 
printf("Number of swaps (Insertion Sort): %d\n", swaps); 
return 0; 
} 
