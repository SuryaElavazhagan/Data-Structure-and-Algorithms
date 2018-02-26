import java.util.Scanner;

class Node
{
    private int data;
    private Node next;
    private int size = 0;

    public Node(int data, Node next)
    {
        this.data = data;
        this.next = next;
    }

    public void setNext(Node next)
    {
        this.next = next;
    }

    public Node getNext()
    {
        return this.next;
    }

    public int getData()
    {
        return this.data;
    }

    public void incrementSize()
    {
        this.size++;
    }

    public void decrementSize()
    {
        this.size--;
    }

    public int getSize()
    {
        return this.size;
    }
}

public class SinglyLinkedList
{
    private static Node rootNode = null;
    private static Node traverseNode = null;

    public static void addElement(int data)
    {
        if(rootNode == null)
        {
            rootNode = new Node(data, null);
            traverseNode = rootNode;
        }
        else{
            Node newNode = new Node(data, null);
            traverseNode.setNext(newNode);
            traverseNode = newNode;
        }
        rootNode.incrementSize();
    }

    public static boolean searchElement(int data)
    {
        for(Node traverse = rootNode; traverse != null; traverse = traverse.getNext())
        {
            if(traverse.getData() == data)
                return true;
        }
        return false;
    }

    public static boolean deleteNode(int data)
    {
        for(Node traverse = rootNode; traverse != null; traverse = traverse.getNext())
        {
            if(traverse.getNext().getData() == data)
            {
                Node tempNode = traverse.getNext();
                traverse.setNext(tempNode.getNext());
                tempNode = null;
                rootNode.decrementSize();
                return true;
            }            
        }
        return false;
    }

    public static void display()
    {
        for(Node traverse = rootNode; traverse != null; traverse = traverse.getNext())
        {
            System.out.print("->" + traverse.getData());
        }
        System.out.println("");
    }

    public static boolean addAfter(int data, int newData)
    {
        for(Node traverse = rootNode; traverse != null; traverse = traverse.getNext())
        {
            if(traverse.getData() == data)
            {
                traverse.setNext(new Node(newData , traverse.getNext()));
                rootNode.incrementSize();
                return true;
            }
        }
        return false;
    }

    public static int getCount()
    {
        return rootNode.getSize();
    }

    public static void main(String[] args) {
        
        Scanner scanner = new Scanner(System.in);        
        int choice = 0;

        while(true)
        {
            System.out.println("Enter a choice :  \n 1.Insert \n 2.Delete \n 3.Search \n 4.Count \n 5.Display \n 6.Insert after a element \n 7.Exit\n");
            choice = scanner.nextInt();
            switch(choice)
            {
                case 1 :
                    addElement(scanner.nextInt());
                    break;
                case 2 : 
                    if(deleteNode(scanner.nextInt()))
                        System.out.println("Element deleted..........");
                    else
                        System.out.println("Element not found..........");
                    break;
                case 3 : 
                    if(searchElement(scanner.nextInt()))
                        System.out.println("Element found..........");
                    else
                        System.out.println("Element not found..........");
                    break;
                case 4 : 
                    System.out.println("Total elements  :" + getCount());    
                    break;
                case 5 : 
                    display();
                    break;
                case 6 : 
                    addAfter(scanner.nextInt(), scanner.nextInt());
                    break;
                case 7 : 
                    System.exit(0);
            }
        }
        //scanner.close();
    }
}