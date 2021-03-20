#include<stdio.h>
#include<conio.h>

int count = 0;

void towerofHanoi(int, char, char, char);


int main() {
	int number;
	printf("Enter the number of disk: ");
	count++;
	scanf_s("%d", &number);
	count++;

	towerofHanoi(number, 'A','B', 'C');
	count++;
	printf("The value of count is : %d", count);
	_getch();

	return 0;
}


void towerofHanoi(int n, char x, char y, char z) {
	if (n >= 1) {
		towerofHanoi(n - 1, x, z, y);
		printf("move top disk from tower %c to top of tower %c\n", x, y);
		count++;
		towerofHanoi(n - 1, z, y, x);
	}
}
