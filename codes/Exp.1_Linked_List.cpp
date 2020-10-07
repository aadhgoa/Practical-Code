#include <stdio.h>
#include <stdlib.h>

struct node{
  int data;
  struct node *next;
};


void create();
void display();
void push();
void append();
void insert_after();
void delete_begin();
void delete_end();
void delete_pos();



struct node *head = NULL;

int main(void) {
  int choice;
  while(1){
    printf("\n Menu");
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
    printf("\n Enter your choice:\t");
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
  struct node* new_node, *temp;

  new_node = (struct node*)malloc(sizeof(struct node));

  if (new_node == NULL){
    printf("\n Out of memory space");
    exit(0);
  }

  printf("\n Enter the data value for the node: ");
  scanf("%d", &new_node->data);

  new_node->next = NULL;

  if(head == NULL){
    head = new_node;
  }

  else{
    temp =head;
    while(temp->next != NULL){
      temp = temp->next;
    }

    temp->next = new_node;
  }
}


void display(){
  struct node* ptr;
  if (head == NULL){
    printf("\n List is empty, mate!!!");
    return;
  }

  else{
    ptr = head;
    printf("The list elements are: ");
    while(ptr != NULL){
      printf("%d", ptr->data);
      ptr = ptr->next;
    }
  }
}

void push(){
  struct node* new_node;
  new_node = (struct node*)malloc(sizeof(struct node));

  if(new_node == NULL){
    printf("\n Out of memory allocation ");
  }

    printf("Enter the value to add at the start of the list: ");
    scanf("%d", &new_node->data);

    new_node->next = NULL;

    if(head == NULL){
      head = new_node;
    }

    else{
      new_node->next = head;
      head = new_node;
    }
  
}



void append(){
  struct node* new_node, *ptr;

  new_node = (struct node*)malloc(sizeof(struct node));

  if(new_node == NULL){
    printf("\n Out of Memory space: ");
    return;
  }
  
  printf("\n Enter the data for the node: ");
  scanf("%d", &new_node->data);

  new_node->next = NULL;

  if(head == NULL){
    head = new_node;
  }
  else{
    ptr=head;
    while(ptr->next != NULL){
      ptr =ptr->next;
    }
    ptr->next = new_node;
  }
}

void insert_after(){
  struct node* ptr, *new_node;

  int i, pos;

  ptr = head;

  new_node = (struct node*)malloc(sizeof(struct node));
  
  if (new_node == NULL){
    printf("\n Out of memory space, mate");
    return;
  }

  printf("Enter the position for the node to be inserted: ");
  scanf("%d",&pos);

  printf("\n Enter the data value of the node: ");
  scanf("%d", &new_node->data);

  new_node->next = NULL;
  if(pos == 0){
    new_node->next = head;
  }

  else{
    for(i = 0; i < pos-1; i++){
      ptr = ptr->next;
      if(ptr == NULL){
        printf ("\n position not found: ");
        return;
      }
    }
    new_node->next = ptr->next;
    ptr->next = new_node;
  }
}

void delete_begin(){
  struct node* ptr;
  ptr = head;
  if(ptr == NULL){
    printf("\n List is Empty");
    return;
  }
  else{
    ptr = head;
    head = head->next;
    printf("\n The deleted element is : %d", ptr->data);
    free(ptr);
  }
}


void delete_end(){
  struct node* temp, *ptr;
  if(head == NULL){
    printf("\n List is empty");
    exit(0);
  }
  else if(head->next == NULL){
    ptr = head;
    head = NULL;
    printf("\n The deleted element is: %d", ptr->data);
    free(ptr);
  }

  else{
    ptr = head;
    while(ptr->next != NULL){
      temp = ptr;
      ptr = ptr->next;
    }
    temp->next = NULL;
    printf("\n The deleted element is : %d", ptr->data);
    free(ptr);
  }
}

void delete_pos(){
  int i, pos;

  struct node* temp, *ptr;

  if (head == NULL){
    printf("\n the List is Empty");
    exit(0);
  }

  else{
    printf("enter the position of the node to be deleted: ");
    scanf("%d", &pos);

    if (pos == 0){
      ptr = head;
      head = head->next;
      printf("\n The deleted element is: %d", ptr->data);
      free(ptr); 
    }

    else{
      ptr = head;
      for(i = 0; i < pos; i++){
        temp =ptr;
        ptr = ptr->next;

        if(ptr == NULL){
          printf("\n Position not Found");
          return;
        }
      }

      temp->next = ptr->next;
      printf("The element is %d", ptr->data);
      free(ptr);
    }
  }
}
