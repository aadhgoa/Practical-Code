#include <stdio.h>

int binSearch(int[], int, int , int );

int main() {
	int arr[10], size, key;

	do
	{
		printf("Number of elements (Max 10) : ");
		scanf("%d", &size);
	} while (size <= 0 && size > 10);


	printf("Enter the elements for Array (Sorted Array): ");
	for (int i = 0; i < size; i++) {
		scanf("%d", &arr[i]);
	}

	printf("Enter the key to search: ");
	scanf("%d", &key);

	int foundIndex = binSearch(arr, 0, size, key);

	if(foundIndex == -1){
		printf("Key not found");
	}
	else {
		printf("Element found at index : %d", foundIndex + 1);
	}

	return 0;
}

int binSearch(int list[], int low, int high, int key) {
	int mid;


	while (low <= high) 
	{
		mid = (low + high) / 2;
		if (key < list[mid]) {
			high = mid - 1;
		}
		else if (key > list[mid]) {
			low = mid + 1;
		}
		else {
			return mid;
		}
	}
	return -1;
}
