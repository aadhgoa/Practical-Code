#include <stdio.h>

int partition(int arr[], int low, int high);
void quickSort(int arr[],int low,int high);
void swap(int *a, int *b);
void printArray(int arr[], int size);



int main(){

    int size, arr[size];

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    printf("Enter the numbers to be sorted: ");
    for(int i = 0; i < size; i++){
        scanf("%d", &arr[i]);
    }

    quickSort(arr, 0, size-1);

    printf("Sorted Array: ");
    printArray(arr, size);

    return 0;
}

int partition(int arr[], int low, int high){
    int pivot = arr[high];

    int i = low - 1;

    for(int j = low; j <= high - 1; j++){
        if(arr[j] < pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[],int low,int high){
    if(low < high){
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high); 
    }
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int arr[], int size){
    for (int i = 0; i < size; i++)
        printf(" %d ", arr[i]);
    printf("\n");
}
