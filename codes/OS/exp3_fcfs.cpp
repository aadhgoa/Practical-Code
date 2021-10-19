#include<iostream>
#include<conio.h>
using namespace std;

void printarr(int prono, float at[], float bt[], int n, int pid[], float ft[], float tat[], float wt[])
{
	int i, j;
	int temp, tempid,tempbt;
	for (i = 0;i < prono;i++)
	{
		for (j = i + 1; j < prono;j++)
		{
			if (at[j] < at[i])
			{
				temp = at[i];
				tempid = pid[i];
				tempbt = bt[i];
				at[i] = at[j]; 
				pid[i] = pid[j];
				bt[i] = bt[j];

				at[j] = temp;
				pid[j] = tempid;
				bt[j] = tempbt;

			}
		}

		
	}


	for (i = 0;i < prono;i++)
	{
		if (i == 0)
		{
			ft[0] = bt[0];
		}
		else
		{
			ft[i] = ft[i - 1] + bt[i];
		}
	}

	for (i = 0;i <prono;i++)
	{
		tat[i] = ft[i] - at[i];
		wt[i] = tat[i] - bt[i];
	}

	cout << "pid\t at\t bt\t ft\t tat\t wt\t" << endl;
	for (i = 0;i < prono;i++)
	{
		cout  << pid[i] << "\t" << at[i] << "\t" << bt[i] << "\t" << ft[i] << "\t" << tat[i] << "\t" << wt[i] << endl;
	}

	float avgtat = 0, avgwt = 0;
	for (i = 0;i < prono;i++)
	{
		avgtat = avgtat + tat[i];
		avgwt = avgwt + wt[i];
	}
	avgtat = avgtat / (prono);
	avgwt = avgwt / (prono);
	cout << "avg tat is :" << avgtat << "time units" << endl;
	cout << "avg wt is :" << avgwt << "time units" << endl;
}
int main()
{
	int pid[10] = { 0,1,2,3,4,5,6,7,8,9 };
	int prono;
	int i = 0;
	cout << "enter info" << endl;
	float arrtime[50], bursttime[50], finishtime[50], turnatime[50], waittime[50];
	float lowtempat;

	cout << "enter no of processes" << endl;
	cin >> prono;

	for (i = 0;i < prono;i++)
	{
		if (i == 0)
		{
			cout << "enter arrival time for " << pid[0] << ":";
			cin >> arrtime[i];
			lowtempat = arrtime[i];
			cout << endl;
			cout << "enter burst time for" << pid[0] << ":";
			cin >> bursttime[i];
			finishtime[0] = arrtime[0] + bursttime[0];
			cout << endl;
		}
		else
		{
			cout << "enter arrival time for " << pid[i] << ":";
			cin >> arrtime[i];
			if (lowtempat>arrtime[i])
			{
				lowtempat = arrtime[i];
			}
			cout << "enter burst time for" << pid[i] << ":";
			cin >> bursttime[i];
			cout << endl;
		}
	}

	int n = sizeof(arrtime) / sizeof(arrtime[0]);
	printarr(prono, arrtime, bursttime, n, pid, finishtime, turnatime, waittime);
	return 0;
}



