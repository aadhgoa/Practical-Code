#include <stdio.h>

void quickSort(int [], int, int);
int Partition(int [], int, int);
void interchange(int *, int *);
void printArray(int [], int);

int main(){

    int size, arr[size];

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    printf("Enter the numbers to be sorted \n");
    for(int i = 0; i < size; i++){
        printf("Enter Number %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    quickSort(arr, 0, size-1);

    printf("Sorted Array: ");
    printArray(arr, size);
    return 0;
}

void quickSort(int arr[], int low, int high){
    if(low < high){
        int partition = Partition(arr, low, high);
        quickSort(arr, low, partition -1);
        quickSort(arr, partition + 1, high);
    }
}

int Partition(int arr[], int low, int high){
    int i = low + 1;
    int j = high;
    int pivot = arr[low];
    int stepCounter = 0;

    while (i <= j)
    {
        while((arr[i]< pivot) && (i < high)){
            i++;
        }while (arr[j] > pivot)
        {
            j--;
        }

        if (i < j){
            printf("\n********************\n");
            printf("Interchange done \n");
            printf("i = %d \t j = %d \t pivot = %d\n", i, j, pivot);

            for(int count = 0; count <= high; count++){
                printf(" %d ", arr[count]); 
            }
            printf("\n\n");
            
            interchange(&arr[i], &arr[j]);
        }else{
            
            printf("\n********************\n");
            printf("NO Interchange done \n");
            printf("i = %d \t j = %d \t pivot = %d\n", i, j, pivot);

            for(int count = 0; count <= high; count++){
                printf(" %d ", arr[count]); 
            }
            printf("\n\n");
            i++;
            }
    }

    arr[low] = arr[j];
    arr[j] = pivot;

    printf("\n********************\n");
    printf("Interchange done \n");
    printf("i = %d \t j = %d \t pivot = %d\n", i, j, pivot);

    for(int count = 0; count <= high; count++){
        printf(" %d ", arr[count]); 
    }
    printf("\n\n");
    return j;
}

void interchange(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int arr[], int size){
    for (int i = 0; i < size; i++)
        printf(" %d ", arr[i]);
    printf("\n");
}