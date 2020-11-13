#include <stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node* next;
};

struct node* head;

struct node* getNewNode(int x){
  struct node* newNode = (struct node*)malloc(sizeof(struct node));
  newNode->data = x;
  newNode->next = NULL;
  return newNode;
}

void create();
void display();
void push();
void append();
void insert_after();
void delete_begin();
void delete_end();
void delete_pos();

int x;

int main(void) {
 int choice;
 printf("Hi!!!, My name is Jacob and I will assit you in your way.\n");
  while(1){
  
    printf("\n-----------Menu------------");
    printf("\nSelect your number from 1-9");
    printf("\n 1. Create");
    printf("\n 2. Display");
    printf("\n 3. Insert at the beginning");
    printf("\n 4. Insert at the end");
    printf("\n 5. Insert at specific position");
    printf("\n 6. Deletion at begin");
    printf("\n 7. Deletion at end");
    printf("\n 8. Deletion at specific position");
    printf("\n 9. Exit");

    printf("\n --------------------------------");
    printf("\n Please give me some input:\t");
    scanf("%d", &choice);
    
    
    switch(choice){
      case 1: create();
      break;

      case 2:
      display();
      break;

      case 3:
      push();
      break;

      case 4:
      append();
      break;

      case 5:
      insert_after();
      break;

      case 6:
      delete_begin();
      break;

      case 7:
      delete_end();
      break;

      case 8:
      delete_pos();
      break;
      
      case 9:
      printf("This is Jacob saying adios.\nHope to help you again sometime.\n~Jacob.");
      exit(0);
      break;

      default:
      printf("\n wrong choice, mate !!");
      break;
    }
  }
  return 0;
}

void create(){
  struct node* temp = head;


  printf(" I will need a number to a create a node for you: ");
  scanf("%d", &x);


  struct node* newNode = getNewNode(x);

  if(head == NULL){
    head = newNode;
    newNode->next = head;
  }

  else{
    while(temp->next != head){
      temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;
    head = newNode; 
  }
  printf(" Thanks for the wait, I have created a node for you\n");
}

void display(){
  struct node* temp = head;

  
  printf(" Your wish my command.\n Right away!!!\n The list is");
  do{
    printf(" %d ", temp->data);
    temp = temp->next;
  }while(temp != head);

  printf("\n\n");
}

void push(){
  struct node* temp = head;

  printf(" Hey, how about you giving me a number to add at the start of link: ");
  scanf("%d", &x);
  struct node* newNode = getNewNode(x);

  while(temp->next != head){
      temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;
    head = newNode;

    printf(" Thanks for the wait, I have added a node for you\n");
}

void append(){
  struct node* temp = head;

  printf(" What is the number you want me to add at end?: ");
  scanf("%d", &x);

  struct node* newNode = getNewNode(x);

  while(temp->next != head){
    temp = temp->next;
  }
  temp->next = newNode;
  newNode->next = head;

  printf(" Thanks for the wait, I have added a node for you\n");
}

void insert_after(){
  struct node* temp = head;
  int i, pos;

  printf(" May I know which posiiton I need to insert after: ");
  scanf("%d", &pos);

  printf(" Now  a number to add after the position you commanded: ");
  scanf("%d",&x);
  struct node* newNode = getNewNode(x);

  for(i = 0; i < pos; i++){
    temp = temp->next;
  }

  newNode->next = temp->next;
  temp->next = newNode;

  printf(" Thanks for the wait, I have added a node for you");
}

void delete_begin(){
  struct node* temp = head;

  while(temp->next != head){
    temp = temp->next;
  }

  temp->next = head->next;
  free(head);
  head = temp->next;
  printf(" Thanks for the wait, I have removed a node for you");
}

void delete_end(){
  struct node* ptr, *temp = head;

  while(temp->next != head){
    ptr = temp;
    temp = temp->next;
  }

  ptr->next = temp->next;
  free(temp);
  printf(" Thanks for the wait, I have removed a node for you");
}

void delete_pos(){
  struct node* ptr, *temp = head;
  int i, pos;

  printf(" Hey, sorry to disturb you again,\n  For the last time enter the position to delete from: ");
  scanf("%d", &pos);

  for(i = 0; i < pos; i++){
    ptr = temp;
    temp = temp->next; 
  }

  ptr->next = temp->next;
  free(temp);
  printf(" Thanks for the wait, I have removed a node for you");
}
