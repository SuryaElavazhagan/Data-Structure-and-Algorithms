#include<stdio.h>
#include<stdlib.h>

struct list
{
    int data;
    struct list* next;
}*head = NULL,*temp;

void add(int n)
{
    struct list *node = (struct list *) malloc(sizeof(struct list));
    node->data = n;    

    if(head == NULL)
    {
        head = node;       
        temp = node;
        node->next = NULL;
    }
    else{
        temp->next = node;
        temp = node;
    }
}

int deleteNode(int pos)
{
    struct list *node=head,*prev;
    if(pos < count())
    {
        for(int i=0;i<pos;i++)
        {
            prev = node;
            node = node->next;
        }
        prev->next = node->next;
        return 1;
    }
    else{
        printf("Enter the correct position!");
        return 0;
    }
}

int search(int n)
{
    struct list *node;
    for(node = head ; node!=NULL; node=node->next)
    {
        if(node->data == n)
        {
            return 1;
        }
    }
    return 0;
}

int count()
{
    static int sum = 0;
    struct list *node;
    for(node = head; node != NULL; node = node->next)
    {
        sum++;
    }
    return sum;
}

int addAfter(int n,int pos)
{
    int flag = 0;
    struct list *node = (struct list *)malloc(sizeof(struct list));
    node->data = n;
    node->next = NULL;
    struct list *temp=head;
    if(pos < count())
    {
        for(int i=1;i<pos;i++){
            temp = temp->next;
        }
        node->next = temp->next;
        temp ->next = node;
    }
    if(flag == 0)
    {
        return flag;
    }
    else{
        return flag;
    }
}

void display()
{
    struct list *node;
    for(node = head; node != NULL; node= node->next)
    {
        printf("->%d",node->data);
    }
    printf("\n");
}

void getChoice()
{
    printf("Enter your choice: \n 1.Insert \n 2.Delete at a position \n 3.Search \n 4.Count \n 5.Display \n 6.Insert at a position \n 7.Exit\n");
}
void main()
{
    int choice;
    int temp,addAfter_n;    
    getChoice();
    scanf("%d",&choice);
    while(1)
    {
        switch(choice)
        {
            case 1:
                    printf("Enter the data to be inserted:");
                    scanf("%d",&temp);
                    add(temp);
                    printf("\nData added\n");
                    getChoice();
                    scanf("%d",&choice);
                    printf("\n");
                    break;
            case 2:
                printf("\nEnter the position to be deleted:");
                scanf("%d",&temp);
                if(deleteNode(temp) == 1)
                    printf("\nData deleted!\n");
                getChoice();
                scanf("%d",&choice);
                printf("\n");
                break;
            case 3:
                printf("\nEnter the data to be searched:");
                scanf("%d",&temp);
                temp = search(temp);
                if(temp == 1)
                    printf("\nData found\n");
                else
                    printf("\nNo data found\n");
                getChoice();
                scanf("%d",&choice);
                printf("\n");
                break;
            case 4:
                printf("\nThe total data inserted: %d\n",count());
                getChoice();
                scanf("%d",&choice);
                printf("\n");
                break;
            case 5:
                display();
                getChoice();
                scanf("%d",&choice);
                printf("\n");
                break;
            case 6:
                printf("\nEnter the data to be inserted:");
                scanf("%d",&temp);
                printf("\nEnter the position:");
                scanf("%d",&addAfter_n);
                addAfter(temp,addAfter_n);
                printf("\nData inserted\n");
                display();
                printf("\n");
                getChoice();
                scanf("%d",&choice);
                printf("\n");
                break;
            case 7:
                printf("\nDo you really want to exit?(1/0):");
                scanf("%d",&temp);
                if(temp != 0)
                {
                    exit(1);
                }
                else
                {
                    getChoice();
                    scanf("%d",&choice);
                    break;
                }
        }       
    }
}