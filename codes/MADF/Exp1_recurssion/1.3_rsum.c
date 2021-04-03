#include <stdio.h>

int count = 0;

int RSum(int a[], int n);
int main()
{
    int n, i, a[n], sum = 0;
    count++;
    printf("Enter the number of elements : ");
    count++;
    scanf("%d", &n);
    count++;
    printf("Enter the array values: ");

    count++;
    for (i = 0; i < n; i++)
    {
        count++;
        scanf("%d", &a[i]);
    }
    count++;
    printf("THe sum of elements in array is: %d\n", RSum(a, n));
    count++;
    printf("Time required forcomputation: %d", count);
}

int RSum(int a[], int n)
{
    count++;
    if (n <= 0)
    {
        count++;
        return 0;
    }

    else
    {
        count++;
        
        return RSum(a, n-1) + a[n-1];
    }
}
