#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fillRandomArray(int array[], int size, int range) {
    for (int i = 0; i < size; i++) {
        array[i] = rand() % range; // Generate a random number between 0 and range X(any number user inputs,
    }
}

void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void linerSearch(int *arrayList, int size, int target) {
    printf ("-LINEAR SEARCH-\n");

    int linCount = 0;

    for (int i = 0; i < size; i++) {
        linCount += 1;

        if (arrayList[i] == target) {
            printf("Found %d at index %d\n", target, i);
            printf("\n");
            return;
        }
    }

    printf("%d not found in the array\n", target);
    printf("\n");
}
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void binarySearch(int *arrayList, int size, int target){
    printf ("-BINARY SEARCH-\n");
    int low = 0;
    int high = sizeof(*arrayList) / sizeof(arrayList[0]);
    int mid = 0;
    int binCount = 0;
    qsort(arrayList, high, sizeof(int), compare);
    
    while(low <= high){
        binCount += 1;
        mid = (low + high) / 2;
        if (target ==  arrayList[mid]) {
            // Returns found number you asked to seach for
            printf ("Found %d\n",target);
            printf("Binary Search for %d took %d steps!\n", target, binCount);
            printf("\n");
            return;
        } else if (target < arrayList[mid]) {
            high = mid - 1;
            
        } else {
            low = mid + 1;
            
        }
        printf("%d not found in the array\n", target);
        printf("\n");

    }
}
    
int main(void) {
    int length;
    int number;
    printf("Enter the size of the array: ");
    scanf("%d", &length);
    printf("What is your favorite number?: ");
    scanf("%d", &number);
    printf("\n");
        
    // allocate memory for the array
    int *arrayList = (int *)malloc(length * sizeof(int));
        
    // Check if memory allocation was successful
    if (arrayList == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
        
    // Populate the array with random numbers 1-100
    fillRandomArray(arrayList, length, 100);  // Assuming a range of 0 to 99 - for the sake of simple, for now.
        
    // Print the random array
    printf("Random Array: ");
    printArray(arrayList, length);
    printf("\n");
    linerSearch(arrayList, length, number);
    binarySearch(arrayList, length, number);
        
    // free sets the allocted momory for this variable free
    free(arrayList);
        
    return 0;
        
    
}
