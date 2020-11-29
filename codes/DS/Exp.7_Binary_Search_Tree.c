#include <stdio.h>
#include <stdlib.h>


struct node
{
    int data; 
    struct node *right_child; 
    struct node *left_child; 
};


struct node* new_node(int x)
{
    struct node *newNode = (struct node*) malloc (sizeof(struct node));
    newNode->data = x;
    newNode->left_child = NULL;
    newNode->right_child = NULL;

    return newNode;
}


struct node* find_minimum(struct node *root);
struct node* insert(struct node *root, int x);
struct node* pop(struct node *root, int x);
void Search(struct node *root, int x);
void inorder(struct node *root);
void preorder(struct node *root);
void postorder(struct node *root);



int main()
{
	int ch, num;
	struct node *root;
	printf("\nEnter a root node number: ");
	scanf("%d", &num);
    root = new_node(num);

    while(1){
    	
    	printf("*******************MENU*******************");
    	printf("\n1. Insert\n2. Delete\n3. Inoreder\n4. PreOrder\n5. Postorder\n6. Height\n7. Search\n8. Exit\n");
    	printf("Enter your choice: ");
    	scanf ("%d", &ch);
    	
    	switch(ch){
    		case 1:{
    			printf("Enter the input number: ");
    			scanf("%d", &num);
    			insert(root, num);
				break;
			}
    		case 2:{
    			printf("Enter the delete number: ");
    			scanf("%d", &num);
    			pop(root, num);
				break;
			}	
			
			case 3: {
				printf("Inorder: ");
				inorder(root);
				printf("\n");
				break;
			}
			
			case 4:{
				printf("Preorder: ");
				preorder(root);
				printf("\n");
				break;
			}
			
			case 5:{
				printf("Postorder: ");
				postorder(root);
				printf("\n");
				break;
			}
			
			case 6:{
				printf("Height: %d\n", height_of_binary_tree(root));
				break;
			}
				
				
			case 7:{
				printf("Enter a number to search: ");
				scanf("%d", &num);
				Search(root, num);
				printf("\n");
				break;
			}
				
			case 8:{
				exit (0);
			}
    			
    		default:{
    			printf("INVALID SELECTION.");
				break;
		}
    			
		}
    		
    			
	}

    return 0;
}


struct node* find_minimum(struct node *root)
{
    if(root == NULL)
        return NULL;
    else if(root->left_child != NULL)
        return find_minimum(root->left_child); 
    return root;
}


void Search(struct node *root, int d) {
   int depth = 0;
   struct node *temp = root;
   
   while(temp != NULL) {
      depth++;
      if(temp->data == d) {
         printf("\nitem found at depth: %d\n", depth);
         return;
      } else if(temp->data > d)
         temp = temp->left_child;
        else
            temp = temp->right_child;
   }
   printf("\n item not found\n");
   return;
}


struct node* insert(struct node *root, int x)
{
    
    if(root==NULL)
        return new_node(x);
    else if(x > root->data) 
        root->right_child = insert(root->right_child, x);
    else 
        root->left_child = insert(root->left_child,x);
    
}


struct node* pop(struct node *root, int x)
{
    if(root==NULL)
        return NULL;
    if (x>root->data)
        root->right_child = pop(root->right_child, x);
    else if(x<root->data)
        root->left_child = pop(root->left_child, x);
    else
    {
        if(root->left_child==NULL && root->right_child==NULL)
        {
            free(root);
            return NULL;
        }

        else if(root->left_child==NULL || root->right_child==NULL)
        {
            struct node *temp;
            if(root->left_child==NULL)
                temp = root->right_child;
            else
                temp = root->left_child;
            free(root);
            return temp;
        }

        else
        {
            struct node *temp = find_minimum(root->right_child);
            root->data = temp->data;
            root->right_child = pop(root->right_child, temp->data);
        }
    }
    return root;
}

void inorder(struct node *root)
{
	
    if(root!=NULL)
    {
        
        inorder(root->left_child);
        printf(" %d ", root->data); 
        inorder(root->right_child);
    }
}

void preorder(struct node *root)
{
	if(root != NULL)
	{
		printf(" %d ", root->data);
		preorder(root->left_child);
		preorder(root->right_child);
	}
}

void postorder(struct node *root)
{
	if(root != NULL)
	{
		postorder(root->left_child);
		postorder(root->right_child);
		printf(" %d ", root->data);
	}
}

int height_of_binary_tree(struct node *root)
{
if(root == NULL)
return 0;
else
{
int left_side;
int right_side;
left_side = height_of_binary_tree(root->left_child);
right_side = height_of_binary_tree(root->right_child);
if(left_side > right_side)
{
return left_side + 1;

}
else
return right_side + 1;
}
}
