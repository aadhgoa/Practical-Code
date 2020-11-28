#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data; //node will store an integer
    struct node *right_child; // right child
    struct node *left_child; // left child
};

//function to find the minimum value in a node
struct node* find_minimum(struct node *root)
{
    if(root == NULL)
        return NULL;
    else if(root->left_child != NULL) // node with minimum value will have no left child
        return find_minimum(root->left_child); // left most element will be minimum
    return root;
}

//function to create a node
struct node* new_node(int x)
{
    struct node *newNode = (struct node*) malloc (sizeof(struct node));
    newNode->data = x;
    newNode->left_child = NULL;
    newNode->right_child = NULL;

    return newNode;
}

struct node* insert(struct node *root, int x)
{
    //searching for the place to insert
    if(root==NULL)
        return new_node(x);
    else if(x > root->data) // x is greater. Should be inserted to right
        root->right_child = insert(root->right_child, x);
    else // x is smaller should be inserted to left
        root->left_child = insert(root->left_child,x);
    //return root;
}

// funnction to delete a node
struct node* pop(struct node *root, int x)
{
    //searching for the item to be deleted
    if(root==NULL)
        return NULL;
    if (x>root->data)
        root->right_child = pop(root->right_child, x);
    else if(x<root->data)
        root->left_child = pop(root->left_child, x);
    else
    {
        //No Children
        if(root->left_child==NULL && root->right_child==NULL)
        {
            free(root);
            return NULL;
        }

        //One Child
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

        //Two Children
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
	
    if(root!=NULL) // checking if the root is not null
    {
        
        inorder(root->left_child); // visiting left child
        printf(" %d ", root->data); // printing data at root
        inorder(root->right_child);// visiting right child
    }
}

void preorder(struct node *root)
{
	if(root != NULL)  //checking if the root is not null
	{
		printf(" %d ", root->data);//printing the data at root
		preorder(root->left_child);//visiting left child 
		preorder(root->right_child);//vsiting right child
	}
}

void postorder(struct node *root){
	if(root != NULL)
	{
		postorder(root->left_child);
		postorder(root->right_child);
		printf(" %d ", root->data);
	}
}

int main()
{
	int ch, num;
	struct node *root;
	printf("\nEnter a root node number: ");
	scanf("%d", &num);
    root = new_node(num);

    while(1){
    	
    	printf("*******************MENU*******************");
    	printf("\n1. Insert\n2. Delete\n3. Inoreder\n4. PreOrder\n5. Postorder\n6. Exit\n");
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
			
			case 6:
				exit (0);	
				
    			
    		default:{
    			printf("INVALID SELECTION.");
				break;
			}
    		
    			
    			
		}
    		
    			
	}

    return 0;
}
