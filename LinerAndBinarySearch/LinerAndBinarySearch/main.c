//
//  main.c
//  LinerAndBinarySearch
//
//  Created by Joe Laporte on 11/28/23.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fillRandomArray(int array[], int size, int range) {
    for (int i = 0; i < size; i++) {
        array[i] = rand() % range; // Generate a random number between 0 and range x
    }
}

void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void linerSearch(int *arrayList, int size, int target) {
    int linCount = 0;

    for (int i = 0; i < size; i++) {
        linCount += 1;

        if (arrayList[i] == target) {
            printf("Found %d at index %d\n", target, i);
            return;
        }
    }

    printf("%d not found in the array\n", target);
}


int main(void) {
    int length;
    int number;
    printf("Enter the size of the array: ");
    scanf("%d", &length);
    printf("What is your favorite number?: ");
    scanf("%d", &number);

    // Dynamically allocate memory for the array
    // Dynamically allocate memory for the array
       int *arrayList = (int *)malloc(length * sizeof(int));
       
       // Check if memory allocation was successful
       if (arrayList == NULL) {
           fprintf(stderr, "Memory allocation failed\n");
           exit(EXIT_FAILURE);
       }

       // Populate the array with random numbers
       fillRandomArray(arrayList, length, 100);  // Assuming a range of 0 to 99

       // Print the generated array
       printf("Random Array: ");
       printArray(arrayList, length);

       // Example usage
       linerSearch(arrayList, length, number);

       // Don't forget to free the dynamically allocated memory
       free(arrayList);

       return 0;
}
