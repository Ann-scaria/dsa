#include <stdio.h> 
#define MAX 100 
int main() { 
    int n_blocks, n_processes; 
    int block_size[MAX], block_status[MAX]; 
    int process_size[MAX]; 
    int i, j; 
    printf("Enter number of memory blocks: "); 
    scanf("%d", &n_blocks); 
    printf("Enter sizes of each block:\n"); 
    for (i = 0; i < n_blocks; i++) { 
        scanf("%d", &block_size[i]); 
        block_status[i] = 0; 
    } 
    printf("Enter number of processes: "); 
    scanf("%d", &n_processes); 
    printf("Enter sizes of each process:\n"); 
    for (i = 0; i < n_processes; i++) 
        scanf("%d", &process_size[i]); 
    for (i = 0; i < n_processes; i++) { 
        int allocated = 0; 
        for (j = 0; j < n_blocks; j++) { 
            if (block_status[j] == 0 && block_size[j] >= process_size[i]) { 
                block_status[j] = 1; 
                printf("Allocated process %d in block %d\n", i + 1, block_size[j]); 
                allocated = 1; 
                break; 
            } 
        } 
        if (!allocated) 
            printf("Could not allocate process %d\n", i + 1); 
    } 
    printf("\nBlock\tSize\tStatus\n"); 
    for (i = 0; i < n_blocks; i++) 
        printf("%d\t%d\t%s\n", i + 1, block_size[i], block_status[i] ? "Used" : "Free"); 
    int free_count; 
    int to_free[MAX]; 
    printf("\nEnter number of blocks to free: "); 
    scanf("%d", &free_count); 
    printf("Enter block numbers to free:\n"); 
    for (i = 0; i < free_count; i++) 
        scanf("%d", &to_free[i]); 
    for (i = 0; i < free_count; i++) { 
        int idx = to_free[i] - 1; 
        if (idx >= 0 && idx < n_blocks && block_status[idx] == 1) { 
            block_status[idx] = 0; 
            printf("Freed block %d\n", to_free[i]); 
        } 
    } 
    printf("\nBefore GC:\n"); 
    printf("Block\tSize\tStatus\n"); 
    for (i = 0; i < n_blocks; i++) 
        printf("%d\t%d\t%s\n", i + 1, block_size[i], block_status[i] ? "Used" : "Free"); 
    int new_block_size[MAX], new_block_status[MAX]; 
    int new_n_blocks = 0; 
    int free_sum = 0; 
    for (i = 0; i < n_blocks; i++) { 
        if (block_status[i] == 0) { 
            free_sum += block_size[i]; 
        } else { 
            if (free_sum > 0) { 
                new_block_size[new_n_blocks] = free_sum; 
                new_block_status[new_n_blocks] = 0; 
                new_n_blocks++; 
                free_sum = 0; 
            } 
            new_block_size[new_n_blocks] = block_size[i]; 
            new_block_status[new_n_blocks] = 1; 
            new_n_blocks++; 
        } 
    } 
    if (free_sum > 0) { 
        new_block_size[new_n_blocks] = free_sum; 
        new_block_status[new_n_blocks] = 0; 
        new_n_blocks++; 
    } 
    n_blocks = new_n_blocks; 
    for (i = 0; i < n_blocks; i++) { 
        block_size[i] = new_block_size[i]; 
        block_status[i] = new_block_status[i]; 
    } 
    printf("\nAfter GC:\n"); 
    printf("Block\tSize\tStatus\n"); 
    for (i = 0; i < n_blocks; i++) 
        printf("%d\t%d\t%s\n", i + 1, block_size[i], block_status[i] ? "Used" : "Free"); 
    int compact_block_size[MAX], compact_block_status[MAX]; 
    int compact_n_blocks = 0; 
    int total_free = 0; 
    for (i = 0; i < n_blocks; i++) { 
        if (block_status[i] == 1) { 
            compact_block_size[compact_n_blocks] = block_size[i]; 
            compact_block_status[compact_n_blocks] = 1; 
            compact_n_blocks++; 
        } else { 
            total_free += block_size[i]; 
        } 
    } 
    if (total_free > 0) { 
        compact_block_size[compact_n_blocks] = total_free; 
        compact_block_status[compact_n_blocks] = 0; 
        compact_n_blocks++; 
    } 
    n_blocks = compact_n_blocks; 
    for (i = 0; i < n_blocks; i++) { 
        block_size[i] = compact_block_size[i]; 
        block_status[i] = compact_block_status[i]; 
    } 
    printf("\nAfter Compaction:\n"); 
    printf("Block\tSize\tStatus\n"); 
    for (i = 0; i < n_blocks; i++) 
        printf("%d\t%d\t%s\n", i + 1, block_size[i], block_status[i] ? "Used" : "Free"); 
    return 0; 
} 
