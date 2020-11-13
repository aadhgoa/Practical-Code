#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* next;
	struct Node* prev;
};

//global scope 
struct Node* head;

//defining the new node.
struct Node* getNewNode(int x){
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = x;
	newNode->prev = NULL;
	newNode->next = NULL;
	return newNode;
}

//function prototype.
void insert_at_head(int x);

void insert_at_end(int x);

void insert_at_middle(int x, int position);

void print();

void reverseprint();

void deletion_at_begining();

void deletion_at_end();

void deletion_at_middle(int position);


int main(){
	
	head = NULL;
  int ch, value, append, position;
  
  do{
  	//Menu List.
    printf("-------Menu-------\n");
    printf("1: Insert at start\n");
    printf("2: Insert at end\n");
    printf("3: Insert after specific position\n");
    printf("4: Deletion at the begining\n");
    printf("5: Deletion at the end\n");
    printf("6: Deleltion at the middle\n");
    printf("7: Exit\n");

    printf("Enter your choice: ");
    scanf("%d", &ch);//taking an input of choice from the user.
    switch(ch){
      case 1:{
        printf("Enter a data: ");
        scanf("%d", &value);
        insert_at_head(value);
        print();
        reverseprint();
        break;
      }

      case 2:{
          printf("Enter a data: ");
          scanf("%d", &value);
        	insert_at_end(value);
          print();
          reverseprint();
          break;
      }

      case 3:{
          printf("Enter the position: ");
          scanf("%d", &position);
          
          printf("Enter a data: ");
          scanf("%d", &value);

          
        	insert_at_middle(value, position);
        	print();
        	reverseprint();
          break;
      }

      case 4:{
        deletion_at_begining();
        print();
        reverseprint();
        break;
      }
      
      case 5:{
      	deletion_at_end();
      	print();
      	reverseprint();
		break;
	  }
	  
	  case 6:{
	  	printf("Enter the position: ");
	  	scanf("%d", &position);
	  	deletion_at_middle(position);
	  	
	  	print();
	  	reverseprint();
		break;
	  }
      case 7:{
      	exit(0);
		break;
	  }
      default:{
        printf("Please, enter again mate");      }
    }
  }while(ch != 7);
	
}


//FUNCTION LIST!!!

//Inserting at the begining.
void insert_at_head(int x){
	struct Node* newNode = getNewNode(x);
	if (head == NULL){
		head = newNode;
		return;
	} 
	
	head->prev = newNode;
	newNode->next = head;
	head = newNode;
}

//Inserting at the end.
void insert_at_end(int x){
	struct Node* temp  = head;
  
	struct Node* newNode = getNewNode(x);
	if (head == NULL){
		head = newNode;
		return;
	}
	
	while(temp->next != NULL) {
	temp = temp->next;
	
	}

  temp->next = newNode;
	newNode->prev = temp;
  newNode->next = NULL;
}

//Inserting after specific position
void insert_at_middle(int x, int position){
  struct Node* temp = head;
  struct Node* prev;

  struct Node* newNode = getNewNode(x);

  int i;
    
  if (newNode == NULL){
    printf("\n Out of memory space, mate");
    return;
  }

  newNode->next = NULL;

	//traversing through the linked list 
    for(i = 0; i < position; ++i){
      temp = temp->next;
      if(temp == NULL){
        printf("You can't insert at this position, mate!!!");
      }
    }
    
    
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    
    temp->next = newNode;

  }

//printing the linked list
void print(){
	struct Node* temp = head;
	
	printf("Forward :");
	
	while(temp != NULL){
		printf(" %d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

//printing in reverse order
void reverseprint(){
	struct Node* temp = head;
	if (temp == NULL)
	return;
	
	while(temp->next != NULL){
		temp = temp -> next;
	}
	
	printf("Reverse :");
	
	while(temp != NULL){
		printf(" %d ", temp->data);
		temp = temp->prev;
	}
	
	printf("\n\n");
}

//Deletion at begining
void deletion_at_begining(){
	struct Node* ptr = head;
	

	
	if(head == NULL){
		printf("\n List is Empty");
		return;
	}
	
	else{
		ptr = head;
		head = head->next;
		head->prev = NULL;
		printf("\n The deleted element is: %d \n", ptr->data);
		free(ptr);
	}
}


//Deletion at end.
void deletion_at_end(){
	struct Node *temp = head;
	struct Node *ptr;
	

		while(temp->next != NULL){
		ptr = temp;
		temp = temp->next;
	} 
	
	
	ptr->next = NULL;
	printf("The deleted element is: %d \n", temp->data);
	free(temp);
}


//Deletion at middle.
void deletion_at_middle(int position){
	struct Node* temp = head;
	struct Node* ptr;
	int i;
	for(i = 0; i < position; i++){
		ptr = temp;
		temp = temp->next;
	}
	
	ptr->next = temp->next;
	temp->next->prev = ptr;
	free(temp);
	
}

