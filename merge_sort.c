#include <stdio.h> 
void merge(int arr[], int l, int m, int r, int *comparisons, int *swaps) { 
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
        (*comparisons)++; 
        if (L[i] <= R[j]) { 
            arr[k] = L[i]; 
            i++; 
        } else { 
            arr[k] = R[j]; 
            j++; 
        } 
        (*swaps)++; 
        k++; 
    } 
    while (i < n1) { 
        arr[k] = L[i]; 
        i++; 
        k++; 
        (*swaps)++; 
    } 
    while (j < n2) { 
        arr[k] = R[j]; 
        j++; 
        k++; 
        (*swaps)++; 
    } 
} 
void merge_sort(int arr[], int l, int r, int *comparisons, int *swaps) { 
    if (l < r) { 
        int m = l + (r - l) / 2; 
        merge_sort(arr, l, m, comparisons, swaps); 
        merge_sort(arr, m + 1, r, comparisons, swaps); 
        merge(arr, l, m, r, comparisons, swaps); 
    } 
} 
void print_array(int arr[], int size) { 
    for (int i = 0; i < size; i++) 
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
    print_array(arr, n) 
merge_sort(arr, 0, n - 1, &comparisons, &swaps); 
printf("Sorted array (Merge Sort): "); 
print_array(arr, n); 
printf("Number of comparisons (Merge Sort): %d\n", comparisons); 
printf("Number of swaps (Merge Sort): %d\n", swaps); 
return 0; 
}
