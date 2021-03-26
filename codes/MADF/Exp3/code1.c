#include <stdio.h>
#include <conio.h>

void MergeSort(int [], int, int);
void Merge(int [], int, int, int);
void printArray(int [], int);

int main()
{
    int arr_size, arr[arr_size];
    
    printf("Enter the number of elements: ");
    scanf("%d", &arr_size);

    printf("Enter the number to be sorted: ");
    for(int i = 0; i < arr_size; i++){
        scanf("%d", &arr[i]);
    }
 
    printf("Given array is \n");
    printArray(arr, arr_size);
 
    MergeSort(arr, 0, arr_size - 1);
 
    printf("\nSorted array is \n");
    printArray(arr, arr_size);
    return 0;
}


void Merge(int arr[], int low, int mid, int high) {
	int i, j,  k = low;

    int n1 = mid - low + 1;
    int n2 = high - mid;

    int Arr1[n1], Arr2[n2];

    for ( i = 0; i < n1; i++)
        Arr1[i] = arr[low + i];

    for( j = 0; j < n2; j++)
        Arr2[j] = arr[ mid + 1 + j];


    i = 0;
    j = 0;
    
    while (i < n1 && j < n2)
    {
        if(Arr1[i] <= Arr2[j]){
            arr[k] = Arr1[i];
            i++;
        }

        else{
            arr[k] = Arr2[j];
            j++;
        }
        k++;
    }

    while(i < n1){
        arr[k] = Arr1[i];
        i++;
        k++;
    }
    
    while(j < n2){
        arr[k] = Arr2[j];
        j++;
        k++;
    }
}


void MergeSort(int arr[], int low, int high) {
	if (low < high) {
		int mid = (low + (high - 1)) / 2;

		MergeSort(arr, low, mid);
		MergeSort(arr, mid + 1, high);

		Merge(arr, low, mid, high);
	}
}

void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}











