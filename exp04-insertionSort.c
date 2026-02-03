#include <stdio.h>

void insertionSort(int arr[], int size);
void printArray(int arr[],int size);

int main() {
    int arr[50], size;
    printf("Enter the array size: ");
    scanf("%d", &size);
    printf("Enter the elements of the array: ");
    for(int i = 0; i<size; i++) {
        scanf("%d", &arr[i]);
    }
    printf("\nUnsorted array: ");
    printArray(arr, size);
    printf("Sorting array...");
    insertionSort(arr, size);
    printf("\nSorted array: ");
    printArray(arr, size);return 0;
}

void insertionSort(int arr[], int size) {
    int key, j;
    // loop for passes
    for(int i = 1; i<size; i++) {
        key = arr[i];
        j = i-1;
        // loop for each pass
        while(j>=0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}


void printArray(int arr[],int size) {
    for(int i=0; i<size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}