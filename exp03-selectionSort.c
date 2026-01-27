#include <stdio.h>

void selectionSort(int arr[], int size);
void printArray(int arr[],int size);

int main()
{
    // take array input
    int size, arr[100];
    printf("\nEnter the size of the array: ");
    scanf("%d", &size);

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Unsorted array: \n");
    printArray(arr, size);
    printf("Sorting array... \n");
    selectionSort(arr, size);
    printf("Sorted array: \n");
    printArray(arr, size);

    return 0;
}

void selectionSort(int arr[], int size)
{
    int indexOfMin, temp;
    for (int i = 0; i < size - 1; i++)
    {
        indexOfMin = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[indexOfMin])
            {
                indexOfMin = j;
            }
        }
        // swap arr[i] and indexOfMin
        temp = arr[i];
        arr[i] = arr[indexOfMin];
        arr[indexOfMin] = temp;
    }
}

void printArray(int arr[],int size) {
    for(int i=0; i<size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
