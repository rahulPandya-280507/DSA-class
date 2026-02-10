#include <stdio.h>

void mergeSort(int arr[], int st, int end);
void merge(int arr[], int st, int mid, int end);
void printArray(int arr[], int size);

int main() {
    int arr[50], size;
    printf("Enter the array size: ");
    scanf("%d", &size);
    printf("Enter the elements of the array: ");
    for(int i = 0; i<size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Unsorted array: ");
    printArray(arr, size);
    printf("Sorting array...");
    mergeSort(arr, 0, size-1);
    printf("Sorted array: ");
    printArray(arr, size);

    return 0;
}

void printArray(int arr[],int size) {
    for(int i=0; i<size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void merge(int arr[], int st, int mid, int end) {
    int i = st, j = mid + 1, idx = 0;
    int temp[50]; 
    while(i <= mid && j <= end) {
        if(arr[i] < arr[j]) {
            temp[idx++] = arr[i++];
        } else {
            temp[idx++] = arr[j++];
        }
    }
    while(i <= mid) {
        temp[idx++] = arr[i++];
    }
    while(j <= end) {
        temp[idx++] = arr[j++];
    }
    for(i = 0; i < idx; i++) {
        arr[st + i] = temp[i];
    }
}


void mergeSort(int arr[], int st, int end) {
    int mid;
    if(st < end) {
        mid = (st + end)/2;
        mergeSort(arr, st, mid);
        mergeSort(arr, mid+1, end);
        merge(arr, st, mid, end);
    }
}
