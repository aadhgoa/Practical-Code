#include <stdio.h>


void binSearch(int[], int, int , int );

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

	binSearch(arr, 0, size, key);

	return 0;
}



void binSearch(int list[], int lo, int hi, int key) {
	int mid;

	if (lo > hi)

	{

		printf("Key not found\n");

		return;

	}

	mid = (lo + hi) / 2;

	if (list[mid] == key)

	{

		printf("Key found at location: %d\n", mid+1);

	}

	else if (list[mid] > key)

	{

		binSearch(list, lo, mid - 1, key);

	}

	else if (list[mid] < key)

	{

		binSearch(list, mid + 1, hi, key);

	}
	
}
