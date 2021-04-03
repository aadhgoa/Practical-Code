#include<stdio.h>
#include<string.h>

int counts=0;

void perm(char *a, int k,int n)
{
	int i;
	counts=counts+1;
	if (k == n)
	{
		counts++;
		printf("\t%s\n", a);
		counts++;
	}
	else
	{
		for (i = k;i < n;i++)
		{
			counts++;
			char temp;
			temp = a[k];
			a[k] = a[i];
			a[i] = temp;
			perm(a, k + 1, n);
			temp = a[k];
			a[k] = a[i];
			a[i] = temp;

		}
	}
 }
int main()
{
	char str[] = "ABC";
	counts++;
	int n = strlen(str);
	
	counts++;
	perm(str, 0, n);
	counts++;
	printf("the time taken for computation is %d", counts);
	
    
	return 0;
 }
