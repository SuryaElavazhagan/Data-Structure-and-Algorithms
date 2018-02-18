#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next,*prev;
}*head=NULL,*trav,*temp;

void addNode(int value)
{
    struct node *add = (struct node*) malloc(sizeof(struct node));
    add->data = value;

    if(head == NULL)
    {
        head = add;
        add->prev = add->next = NULL;
        trav = add;
    }
    else
    {
        add->prev = trav;
        add->next = NULL;
        trav->next = add;
        trav = add;
    }
}

void forwardTraversal()
{
    for(temp = head; temp != NULL; temp = temp->next)
    {
        printf("->%d", temp->data);
    }
    printf("\n");
}

void reverseTraversal()
{
    for(temp = trav;temp != NULL;temp = temp->prev)
    {
        printf("<-%d",temp->data);
    }
    printf("\n");
}

void search(int sdata)
{
    for(temp = head; temp != NULL; temp = temp->next)
    {
        if(temp->data == sdata)
        {
            printf("\nFound!\n");
            return;
        }
    }
    printf("\nNo matching data!\n");
    return;
}

int getSize()
{
    int count = 0;
    for(temp = head; temp != NULL; temp = temp->next)
    {
        count++;
    } 
    return count;
}

void deleteNodeForward(int position)
{
    if((position >= 1) && (position < getSize))
    {
        temp = head;
        for(int i = 0; i < position; i++)
        {
            temp = temp->next;
        }
        (temp->prev)->next = temp->next;
        forwardTraversal();
    }
    else
    {
        printf("\nEnter valid position and retry!\n");
    }
}

void deleteNodeReverse(int position)
{
    if((position >= 1) && (position < getSize))
    {
        temp = trav;
        for(int i = 0; i < position; i++)
        {
            temp = temp->prev;
        } 
        (temp->prev)->next = temp->next;
        forwardTraversal();
    }
    else
    {
        printf("\nEnter valid position and retry!\n");
    }
}

void insertAtPositionForward(int position,int value)
{
    if((position > 1) && (position < getSize()))
    {
        struct node *add = (struct node*)malloc(sizeof(struct node));
        add->data = value;
        add->next = add->prev = NULL;
        temp = head;
        for(int i = 1; i < position; i++)
        {
            temp = temp->next;
        }   
        add->next = temp->next;
        (temp->next)->prev = add;
        add->prev = temp;
        temp->next = add;
        forwardTraversal();
    }
    else
    {
        printf("\n Enter valid position and retry!\n");
    }
}

void insertAtPositionReverse(int position,int value)
{
    if((position > 1) && (position < getSize()))
    {
        struct node *add = (struct node*)malloc(sizeof(struct node));
        add->data = value;
        add->next = add->prev = NULL;
        temp = trav;
        for(int i = 0; i < position; i++)
        {
            temp = temp->prev;
        }   
        add->next = temp->next;
        (temp->next)->prev = add;
        add->prev = temp;
        temp->next = add;
        forwardTraversal();
    }
    else
    {
        printf("\n Enter valid position and retry!\n");
    }
}

void getChoice()
{
    printf("Enter your choice: \n 1.Insert \n 2.Delete at a position forward \n 3.Delete at a position Reverse \n 4.Search \n 5.Count \n 6.Display forward \n  7.Display Reverse \n 8.Insert at a position Forward \n 9.Insert at a position reverse \n 10.Exit\n");
}


void main()
{
    int choice;
    int temp,pos;
    getChoice();
    scanf("%d",&choice);
    while(TRUE)
    {
        switch(choice)
        {
            case 1:
                printf("\nEnter the element to be inserted:");
                scanf("%d",&temp);
                addNode(temp);
                printf("\nData added\n");
                getChoice();
                scanf("%d",&choice);
                break;
            case 2:
                printf("Enter the position from forward to be deleted:");
                scanf("%d",&pos);
                deleteNodeForward(pos);
                printf("\nDeleted!\n");
                getChoice();
                scanf("%d",&choice);
                break;
            case 3:
                printf("Enter the position from reverse to be deleted:");
                scanf("%d",&pos);
                deleteNodeReverse(pos);
                printf("\nDeleted\n");
                getChoice();
                scanf("%d",&choice);
                break;
            case 4:
                printf("Enter the element to be searched:");
                scanf("%d",&temp);
                search(temp);
                getChoice();
                scanf("%d",&choice);
                break;
            case 5:
                printf("Total number of data added:%d\n", getSize());
                getChoice();
                scanf("%d",&choice);
                break;
            case 6:
                forwardTraversal();
                getChoice();
                scanf("%d",&choice);
                break;
            case 7:
                reverseTraversal();
                getChoice();
                scanf("%d",&choice);
                break;
            case 8:
                printf("Enter the data and the position from forward:");
                scanf("%d%d",&temp,&pos);
                insertAtPositionForward(pos,temp);
                printf("\nData inserted\n");
                getChoice();
                scanf("%d",&choice);
                break;
            case 9:
                printf("Enter the data and the position from reverse:");
                scanf("%d%d",&temp,&pos);
                insertAtPositionReverse(pos,temp);
                printf("\nData inserted\n");
                getChoice();
                scanf("%d",&choice);
                break;
            case 10:
                printf("Do you really want to exit?(1/0):");
                scanf("%d",&temp);
                if(temp != 0)
                    exit(0);
                else
                    {
                        getChoice();
                        scanf("%d",&choice);
                        break;  
                    }
        }
    }    
}