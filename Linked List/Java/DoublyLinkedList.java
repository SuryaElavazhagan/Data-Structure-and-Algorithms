import java.util.Scanner;

class Node2
{
    protected int data;
    protected Node2 next;
    protected Node2 prev;

    Node2(int data,Node2 next,Node2 prev)
    {
        this.data = data;
        this.next = next;
        this.prev = prev;
    }

    int getData()
    {
        return data;
    }

    void setData(int data)
    {
        this.data = data;
    }

    Node2 getNext()
    {
        return next;
    }

    void setNext(Node2 next)
    {
        this.next  = next;
    }

    Node2 getPrev()
    {
        return prev;
    }

    void setPrev(Node2 prev)
    {
        this.prev = prev;
    }
}

class LinkedList2
{
    protected Node2 head;
    protected Node2 trav;
    protected int size;

    LinkedList2()
    {
        head = null;
        size = 0;
    }
    
    public void addNode(int value)
    {
        if(head == null)
        {
            head = new Node2(value,null,null);
            trav = head;
            size++;
        }
        else
        {
            Node2 temp = new Node2(value,null,null);
            trav.setNext(temp);
            temp.setPrev(trav);
            trav = temp;
            size++;
        }
    }

    public void deleteNodeForward(int position)
    {
        Node2 temp = head;
        if(position < size)
        {
        for(int i = 0; i < position; i++)
        {
            temp = temp.next;
        }

        if(temp == head)
        {
            head = head.getNext();;
            System.out.println("Head deleted");
        }
        else
        {
            temp.prev.next = temp.next;
        }
        size--;
    }
    else{System.out.println("Give correct position!");}
    }
    
    public void deleteNodeReverse(int position)
    {
        Node2 temp1 = trav;
        if(position < size)
        {
        for(int i = 0; i < position; i++)
        {
            temp1 = temp1.prev;
        }
    
        if(temp1 == head)
        {
            head = head.getNext();
            System.out.println("Head deleted!");
        }
        else
        {
            temp1.prev.next =  temp1.next;
        }
        size--;
    }
    else{System.out.println("Give correct position!");}
    }

    public void search(int sdata)
    {
        for(Node2 temp = head; temp.next != null; temp = temp.next)
        {
            if(temp.data == sdata)
                {
                    System.out.println("Data found!");
                    return;
                }
        }
        System.out.println("No record found!");
    }

    public int getSize()
    {
        return size;
    }

    public void displayForward()
    {
        for(Node2 temp = head; temp != null; temp = temp.next)
        {
            System.out.print("->" + temp.data);
        }
        System.out.println("");
    }

    public void displayReverse()
    {
        for(Node2 temp = trav; temp != null; temp = temp.prev)
        {
            System.out.print("->" + temp.data);
        }
        System.out.println("");
    }

    public void insertAtPositionForward(int value,int position)
    {
        Node2 temp = head;
        if(position < size)
        {
        for(int i = 1; i < position; i++)
        {
            temp = temp.next;
        }
        Node2 add = new Node2(value,temp.next,temp);
        temp.next.prev = add;
        temp.next = add;
        size++;
    }
    else{System.out.println("Give correct position!");}
    }


    public void insertAtPositionReverse(int value,int position)
    {
        Node2 temp = trav;
        if(position < size)
        {
        for(int i = 0; i < position; i++)
        {
            temp = temp.prev;
        }
        Node2 add = new Node2(value,temp.next,temp);
        temp.next.prev = add;
        temp.next = add;
        size++;
    }
    else{System.out.println("Give correct position!");}
    }
}

public class DoublyLinkedList
{
    static void getChoice()
    {
        System.out.println("Enter your choice: \n 1.Insert \n 2.Delete at a position forward \n 3.Delete at a position Reverse \n 4.Search \n 5.Count \n 6.Display forward \n 7.Display Reverse \n 8.Insert at a position Forward \n 9.Insert at a position reverse \n 10.Exit\n");
    }
    
    public static void main(String args[])
    {
        LinkedList2 linkedList2 = new LinkedList2();
        int choice;
        getChoice();
        Scanner scanner = new Scanner(System.in);
        choice = scanner.nextInt();

        while(true)
        {
        switch(choice)
        {
            case 1:
                System.out.println("Enter a number to insert:");
                linkedList2.addNode(scanner.nextInt());
                getChoice();
                choice  = scanner.nextInt();
                break;
            case 2:
                System.out.println("Enter the position to delete from forward:");
                linkedList2.deleteNodeForward(scanner.nextInt());
                getChoice();
                choice  = scanner.nextInt();
                break;
            case 3:
                System.out.println("Enter the position to delete from reverse:");
                linkedList2.deleteNodeReverse(scanner.nextInt());
                getChoice();
                choice = scanner.nextInt();
                break;
            case 4:
                System.out.println("Enter the element to search:");
                linkedList2.search(scanner.nextInt());
                getChoice();
                choice = scanner.nextInt();
                break;
            case 5:
                System.out.println("Total number of elements inserted:" + linkedList2.getSize());
                getChoice();
                choice = scanner.nextInt();
                break;
            case 6:
                linkedList2.displayForward();
                getChoice();
                choice = scanner.nextInt();
                break;
            case 7:
                linkedList2.displayReverse();
                getChoice();
                choice = scanner.nextInt();
                break;
            case 8:
                int x;
                System.out.println("Enter the data and the position from forward:");
                x = scanner.nextInt();
                linkedList2.insertAtPositionForward(x,scanner.nextInt());
                getChoice();
                choice  = scanner.nextInt();
                break;
            case 9:
                System.out.println("Enter the data and the position from reverse:");
                x = scanner.nextInt();
                linkedList2.insertAtPositionReverse(x,scanner.nextInt());
                getChoice();
                choice  = scanner.nextInt();
                break;
            case 10:
                System.out.println("Do you really want to exit>(1/0):");
                if(scanner.nextInt() != 0)
                {
                    System.exit(0);
                }
                else{
                    getChoice();
                    choice = scanner.nextInt();
                    break;
                }
        } 
    }  
    }
}