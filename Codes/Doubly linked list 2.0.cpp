#include <stdio.h>
#include <stdlib.h>

struct node 
{
	struct node *nextptr;
    int num;                        //Data of the node
    struct node *prev;           //Address of the prev node
}*head;

void createNodeList(int n); // function to create the list
void insertNodeAtBeginning(int num);
void insertNodeAtEnd(int num);
void insertNodeAtMiddle(int num, int position);
void delete_start();
void delete_end();
void delete_specific(int position);
void displayList();         // function to display the list



int main()
{
    int n,data,position;
		printf("\n\n Linked List : To create and display Doubly Linked List :\n");
		printf("-------------------------------------------------------------\n");
		
    printf(" Input the number of nodes : ");
    scanf("%d", &n);
    createNodeList(n);
    
    printf("\n Data entered in the list : \n");
    displayList();
    
    printf("\nEnter data to be inserted at the beginning of the list: ");
    scanf("%d", &n);
    insertNodeAtBeginning(n);
    
    printf("\nEnter data to be inserted at the end of the list: ");
    scanf("%d", &n);
    insertNodeAtEnd(n);
    
    printf("\nEnter data to be inserted at a specific location in the list: ");
    scanf("%d", &data);
    
    printf("\nEnter the position to enter new node: ");
    scanf("%d",&position);
    insertNodeAtMiddle(data,position);
    

    delete_start();
 
	  //printf("\nDelete from End: ");
    //scanf("%d",&position);
    delete_end();
 
	  printf("\nDelete from Specific Location: ");
    scanf("%d",&position);
    delete_specific(position);
   
 
    printf("\nDATA IN THE LIST\n");
    displayList();    
    
    return 0;
}

void createNodeList(int n)
{
    struct node *newNode, *tmp;
    int num, i;
    
    head = (struct node *)malloc(sizeof(struct node));

    if(head == NULL) //check whether the fnnode is NULL and if so no memory allocation
    {
        printf(" Memory can not be allocated.");
    }
    else
    {
// reads data for the node through keyboard

        printf(" Input data for node 1 : ");
        scanf("%d", &num);
        head->num = num;      
        head->nextptr = NULL; // links the address field to NULL
        tmp = head;
// Creating n nodes and adding to linked list
        for(i=2; i<=n; i++)
        {
            newNode = (struct node *)malloc(sizeof(struct node));
            if(newNode == NULL)
            {
                printf(" Memory can not be allocated.");
                break;
            }
            else
            {
                printf(" Input data for node %d : ", i);
                scanf(" %d", &num);
 
                newNode->num = num;      // links the num field of fnNode with num
                newNode->nextptr = NULL; // links the address field of fnNode with NULL
 
                tmp->nextptr = newNode; // links previous node i.e. tmp to the fnNode
                tmp = tmp->nextptr; 
            }
        }
        printf("\n Doubly link list created \n");
    }
}

void insertNodeAtBeginning(int num)
{

	struct node *newNode, *tmp;
	
	if (head==NULL)
	{
		head = tmp;
		newNode = head;
	}
	else
	{
		tmp->nextptr = head;
		head-> prev = tmp;
		head = tmp;
	}
}

void insertNodeAtEnd(int num)
{
	struct node *newNode, *tmp;
	if(head == NULL)
	{
		head = tmp;
		newNode = head;
	}
	else
	{
		newNode->nextptr = tmp;
		tmp->prev = newNode;
		newNode = tmp;
	}
}

void insertNodeAtMiddle(int num, int position)
{
	struct node *newNode, *tmp;
	
	int i, pos;
	
	if(newNode == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        newNode->num = num; // Link data part
        newNode->nextptr = NULL;

		tmp = head;
	

	
		for(i=1; i<pos - 1; i++)
		{
			tmp = tmp->nextptr;
			if (tmp == NULL)
			{  
	               printf("\n There are less than %d elements", pos);  
	               return;  
	           } 
		}
		newNode->prev = tmp;
		newNode->nextptr = tmp->nextptr;
		tmp->nextptr->prev = newNode;
		printf("\nNODE INSERTED");
	}
}

void delete_start()
{
	struct node *ptr;
	ptr=head;
	if (head == NULL)
	{
 		printf("\nLIST IS EMPTY! \n");
 		return ;		
	}
	else
	{
		head = head->nextptr;
		head->prev = NULL;
		free(ptr);
		printf("\n NODE DELETED!");
	}
}

void delete_end()
{
	struct node *tmp, *ptr;
	tmp = head;
	if(head == NULL)
	  {
	    printf("\n List is empty");
	    exit(0);
	  }
	  else
	  {
	  	while (tmp-> nextptr!= NULL)
	  	{
	  		ptr = tmp;
	  		tmp = tmp->nextptr;
		  }
		  ptr-> nextptr = NULL;
		  free(tmp);
	  }
}

void delete_specific(int position)
{
	int i;
	struct node *ptr, *tmp;

	if(head==NULL)
    {
                printf("\nList is Empty:");
                exit(0);
    }
    else
    	{
    		tmp=head;
    		for(i=1; i<position-1; i++)
    		{
    			ptr = tmp;
    			tmp = tmp->nextptr;
			}
			ptr->nextptr = tmp->nextptr;
			tmp->nextptr->prev = ptr;
			free(tmp);
		}
}

void displayList(){
	struct node* temp = head;
	
	while(temp != NULL){
		printf("%d", temp->num);
		temp = temp->nextptr;
	}
	
}
