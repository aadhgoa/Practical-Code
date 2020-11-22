//Queue reversal
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 50
int front=-1,rear=-1;
int queue[MAX];

void enqueue(char a);
void display();

int main()
{
	int j,r;
	int i,ch;
	char s[MAX],b;
	int length;
	while(1)
	{
		printf("\n********Main Menu********\n");
		printf("=========================\n");
		printf("1. Enter String\n");
		printf("2. Exit\n");
		printf("Enter Choice:\t");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			printf("Enter String:\t");
			scanf("%s",&s);
			length=strlen(s);
			for(i=0;i<=length-1;i++)
			{
				b=s[i];
				enqueue(b);
			}
			display();
			break;
			case 2:
			exit(0);
			break;
			default:
			printf("Invalid Choice");
		}
	}
	return 0;
}

void enqueue(char a)
{
	if(rear==MAX-1)
	{
		printf("queue is full");
		exit(0);
	}
	else if(front==-1&&rear==-1)
	{	
		front=rear=0;
		queue[rear]=a;
	}
	else{
		rear=rear+1;
		queue[rear]=a;
	}
}

void display(){
	int i, change;  
    if(rear == -1)  
    {  
        printf("\nEmpty queue\n");  
    }  
    else  
    {   printf("\nprinting values .....\n");  
        for(i=front;i<=rear;i++)  
        {  
            printf("%c",queue[i]);  
        }     
    } 
	
	change = front;
	front = rear;
	rear = change;
	
	if(rear == -1)  
    {  
        printf("\nEmpty queue\n");  
    }  
    else  
    {   printf("\nReverse printing values .....\n");
    
        for(i=front;i>=rear;i--)  
        {  
            printf("%c",queue[i]);  
        } 
		printf("\n\n*****************************\n");    
    }
}
