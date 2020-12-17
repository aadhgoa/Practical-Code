#include <stdio.h>

//declaring global variable.
int top = -1,front = -1, rear = -1, q[20], a[20][20], vis[20], stack[30];

//function prototype
int delete();
void add(int item);
void bfs(int s, int n);
void dfs(int s, int n);
void push(int item);
int pop();


//main function
int main(){

    int n, i, s, ch, j;//declarations
    char c, dummy;

    //!input for the number of vertices
    printf("Enter the number of vertices : ");
    scanf("%d", &n);

    //looping for taking input for the vertices 
    //!(0 for no connection & 1 for a valid connection)
    for(i = 1; i <= n; i++){
        for ( j = 1; j <= n; j++)
        {
            printf("Enter 1 if %d has a node with %d else 0 ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    //printing the final adjacency matrix.
    printf("The Adjacency matrix is\n");
    for(i = 1; i <=n; i++){
        for (j = 1; j <= n; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    do{
        for(i = 1; i <= n; i++)
            vis[i]= 0;
        printf("\nMenu\n1. BFS\n2. DFS\nEnter your choice: ");
        scanf("%d", &ch);//input for chooice
        printf("Enter the souce vertex: ");
        scanf("%d", &s);//input for source vertex

       switch (ch)
       {
       case 1:
           bfs(s,n);
           break;
       case 2:
            dfs(s,n);
            break; 
       default:
        printf("wrong selection");
           break;
       }

       printf("\nDo you want to continue(Y/N): ");
       scanf("%c", &dummy);
       scanf("%c", &c);
    }while ((c == 'y')||(c == 'Y'));
    
    return 0;
}

//!BFS Algo
void bfs(int s, int n){
    int p, i;//delclaration
    add(s);//same as enqueue
    vis[s] = 1;//array of visited nodes
    p = delete();//delete from the queue
    if(p != 0)
        printf(" %d ", p);//printing the value
    for(i = 1; i <= n; i++){
        if(vis[i] == 0)
            bfs(i,n);//recussing to till we reach all the vertices
    }
}

//!DFS Algo
void dfs(int s,int n)
{
    int i,k;//declaration
    push(s);//push the source vertice to the stack
    vis[s]=1;//adding 1 to all the veritices visted.
    k=pop();//poping the value from the stack
    if(k!=0)
        printf(" %d ",k);
    
    while(k!=0){
        for(i=1;i<=n;i++)
            if((a[k][i]!=0)&&(vis[i]==0)){
                push(i);
                vis[i]=1;
        }

        k=pop();
        if(k!=0)
        printf(" %d ",k);
    }
    
for(i=1;i<=n;i++)
    if(vis[i]==0)
        dfs(i,n);
}

//!Queue operations
void add(int item){
    if(rear == 19)
        printf("Queue Full");
    else
    {
        if (rear == -1)
        {
            q[++rear] = item;
            front++;
        }
        else
        {
            q[++rear] = item;
        }
    }
    
}

//!Queue operations
int delete(){
    int k;
    if((front > rear) || (front == -1))
        return(0);

    else
    {
        k = q[front++];
        return(k);
    }
}

//!Stack operations
void push(int item){
    if(top == 19){
        printf("stack overflow");
    }
    else
    {
        stack[++top] = item;
    }
}

//!Stack operations
int pop(){
    int k;
     if(top == -1){
        return (0);
    }else{
        k = stack[top--];
        return(k);
    }
}