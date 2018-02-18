#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
} *root=NULL;

struct node* addNode(struct node *root, int data)
{
    if(root == NULL)
    {
        root->data = data;
        root->left = NULL;
        root->right = NULL; 
    }
    else
    {
        if(root->data > data)
        {
            root = addNode(root->left, data);
            root = balance(root);
        }
        else
        {
            root = addNode(root->right,data);
            root = balance(root);
        }
    }
    return root;
}

struct node* balance(struct node *temp)
{
    int balancingFactor = diff(temp); 
    if(balancingFactor > 1)
    {
        if(diff(temp->left) > 0)
            temp = llRotate(temp);
        else
            temp = lrRotate(temp);
    }
    else if(balancingFactor < -1)
    {
        if(diff(temp->right) > 0)
           temp = rlRotate(temp);
        else    
           temp = rrRotate(temp);
    }
    return temp;
}

int diff(struct node *temp)
{
    int balancingFactor = height(temp->left) - height(temp->right);
    return balancingFactor;
}

int height(struct node *temp)
{
    int height = 0;
    if(temp != NULL)
    {
        int leftHeight = height(temp->left);
        int rightHeight = height(temp->right);
        int maxHeight = max(leftHeight,rightHeight);
        height = maxHeight + 1;
    }
    return height;
}

int max(int a, int b)
{
    if(a > b)
        return a;
    else    
        return b;
}

struct node* llRotate(struct node *parent)
{
    struct node *temp;
    temp = parent->left;
    parent->left = temp->right;
    temp->right = parent;
    return temp;
}

struct node* rrRotate(struct node *parent)
{
    struct node *temp;
    temp = parent->right;
    parent->right = temp->left;
    temp->left = parent->right;
    return temp; 
}

struct node* rlRotate(struct node *parent)
{
    struct node *temp;
    temp = parent->right;
    parent->right = llRotate(temp);
    return rrRotate(parent);
}

struct node* lrRotate(struct node *parent)
{
    struct node *temp;
    temp = parent->left;
    parent->left = rrRotate(temp);
    return llRotate(parent);
}

void displayTree(struct node *root, int level)
{
    int i;
    if(temp != NULL)
    {
        displayTree(temp->right, level + 1);
        printf("\n");
        if(temp == root)
            printf("Root->");
        for(i = 0; (i < level) && (temp != root);i++)
            printf("       ");
        printf("%d",temp->data);    
        displayTree(temp->left,level + 1);
    }
}

void inOrder(struct node *temp)
{
    if(temp != NULL)
        return;
    inOrder(temp->left);
    printf("%d->",temp->data);
    inOrder(temp->right);
}

void preOrder(struct node *temp)
{
    if(temp != NULL)
        return;
    printf("->%d",temp->data);
    preOrder(temp->left);
    preOrder(temp->right);
}

void postOrder(struct node *temp)
{
    if(temp != NULL)
        return;
    postOrder(temp->left);
    postOrder(temp->right);
    printf("->%d",temp->data);
}

struct node* search(struct node *temp, int data)
{
    if(temp != NULL && temp->data == data)
        return temp;
    if(temp->data < data)
        return search(temp->right, data);
    return search(temp->left , data);
}

int main()
{
    int choice = 0;
    while(1)
    {
        printf("Enter your choice \n 1.Insert a data \n 2.Display balanced tree \n 3.InOrder traversal \n 4.Pre Order traversal \n 5.Post order Traversal \n 6.Search a key \n 7.Exit \n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter the data to be inserted:");
                scanf("%d",&choice);
                root = addNode(root,choice);
                break;
            case 2:
                displayTree(root,1);
                printf("\n");
                break;
            case 3:
                inOrder(root);
                printf("\n");
                break;
            case 4:
                preOrder(root);
                printf("\n");
                break;
            case 5:
                postOrder(root);
                printf("\n");
                break;
            case 6:
                printf("\n Enter the data to be searched:");
                scanf("%d",&choice);
                search(choice);
                break;
            case 7:
                printf("\n Bye");
                exit(0);
        }
    }
}