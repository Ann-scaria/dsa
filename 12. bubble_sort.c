#include <stdio.h> 
void bubble_sort(int arr[], int n, int *comparisons, int *swaps) { 
    int i, j, temp; 
    for (i = 0; i < n - 1; i++) { 
        for (j = 0; j < n - i - 1; j++) { 
            (*comparisons)++; 
            if (arr[j] > arr[j + 1]) { 
                temp = arr[j]; 
                arr[j] = arr[j + 1]; 
                arr[j + 1] = temp; 
                (*swaps)++; 
            } 
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
bubble_sort(arr, n, &comparisons, &swaps); 
printf("Sorted array (Bubble Sort): "); 
print_array(arr, n); 
printf("Number of comparisons (Bubble Sort): %d\n", comparisons); 
printf("Number of swaps (Bubble Sort): %d\n", swaps); 
return 0; 
} 
