#include<iostream>
#include<vector>
using namespace std;

template< class bubble>
void sort(bubble a[],int n)
{
	bubble b;
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if (a[i]>a[j]){
			b = a[i];
			a[i] = a[j];
			a[j] = b;
            }
		}
	}
}
template< class bubble>
void printarr(bubble a[],int n)
{
	for(int i=0;i<n;i++)
		cout<<"\t"<<a[i]<<"\t";

    cout<<endl<<"*********END*********"<<endl;
}
int main()
{
	int arr[20],c,n;
	char ch[20];
	
    

    while(1){

        cout<<"Enter The Type Of Elements:\n1:Integer\n2:Character\n3:Exit\n";
        cin>>c;
        switch (c)
        {
        case 1:
            cout<<"\nEnter Number Of Elements:- ";
		    cin>>n;
		    cout<<"Enter Elements:\n";
		    for(int a=0;a<n;a++)	
			    cin>>arr[a];		
		    sort(arr,n);
		    cout<<"\nSorted Ordered Integers Are:- ";
		    printarr(arr,n);

            break;

        case 2:
            cout<<"\nEnter Number Of Characters:- ";
            cin>>n;
            cout<<"Enter Elements:\n";
            for(int a=0;a<n;a++)	
                cin>>ch[a];		
            sort(ch,n);
            cout<<"\nSorted Ordered Characters Are:- ";
            printarr(ch,n);
            break;

        case 3:
            exit(0);
        
        default:
            cout<<"Entered number is Invaild";
            break;
        }
    }
	return 0;
}