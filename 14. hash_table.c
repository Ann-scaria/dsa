#include <stdio.h> 
#define TABLE_SIZE 10 
#define EMPTY -1 
int main() { 
    int hashTable[TABLE_SIZE]; 
    int n, key; 
    for (int i = 0; i < TABLE_SIZE; i++) 
      hashTable[i] = EMPTY; 
    printf("Enter number of elements to insert: "); 
    scanf("%d", &n); 
    printf("Enter %d integers:\n", n); 
    for (int i = 0; i < n; i++) { 
        scanf("%d", &key); 
        int index = key % TABLE_SIZE; 
        int originalIndex = index; 
        while (hashTable[index] != EMPTY) { 
            index = (index + 1) % TABLE_SIZE; 
            if (index == originalIndex) 
                break; 
         } 
         if (hashTable[index] == EMPTY) { 
            hashTable[index] = key; 
            printf("Inserted %d at index %d\n", key, index); 
        } 
    } 
    printf("\nHash Table:\n"); 
    for (int i = 0; i < TABLE_SIZE; i++) { 
        if (hashTable[i] == EMPTY) 
            printf("Index %d: EMPTY\n", i); 
        else 
            printf("Index %d: %d\n", i, hashTable[i]); 
 }  return 0; 
} 
