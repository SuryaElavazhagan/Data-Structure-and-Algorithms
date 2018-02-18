import java.util.Scanner;

class AvlNode
{
    protected int data;
    protected AvlNode left;
    protected AvlNode right;

    AvlNode(int data,AvlNode left,AvlNode right)
    {
        this.data = data;
        this.left = left;
        this.right = right;
    }
}

class Avl
{
    AvlNode root;
    Avl()
    {
        root = null;
    }
    public AvlNode addKey(AvlNode root,int data)
    {
        if(root == null)
        {
            root = new AvlNode(data,null,null);
        }
        else
        {
            if(root.data > data)
            {
                root.left = addKey(root.left,data);
                root = balance(root);
            }
            else if(root.data <= data)
            {
                root.right = addKey(root.right,data);
                root = balance(root);
            }
        }
        return root;
    }

    public AvlNode balance(AvlNode temp)
    {
        int balancingFactor = diff(temp);
        if(balancingFactor > 1)
        {
            if(diff(temp.left) > 0)
            {
                temp = llRotate(temp);
            }
            else
            {
                temp = lrRotate(temp);
            }
        }
        else if(balancingFactor < -1)
        {
            if(diff(temp.right) > 0)
            {
                temp = rlRotate(temp);
            }
            else
            {
                temp = rrRotate(temp);
            }
        }
        return temp;
    }

    public AvlNode deleteNode(AvlNode root,int key)
    {
        if(root == null)
            return root;
        else if(root.data < key)
            root.right = deleteNode(root.right,key);
        else if(root.data > key)
            root.left = deleteNode(root.left,key);
        else 
        {
            if(root.left == null || root.right == null)
            {
                AvlNode temp = root.left==null ? root.right : root.left;
                if(temp == null)
                {
                    root = null;
                }
                else
                {
                    root = temp;
                }
            }
            else
            {
                AvlNode temp = minValue(root.right);
                root.data = temp.data;
                root.right = deleteNode(root.right,temp.data);
            }
        }
        if(root == null)
            return root;
        return balance(root);
    }

    public AvlNode minValue(AvlNode temp)
    {
        if(temp == null)
            return null;
        while(temp.left != null)
            temp = temp.left;
        return temp;
    }

    public int diff(AvlNode temp)
    {
        int balancingFactor = height(temp.left) - height(temp.right);
        return balancingFactor;
        
    }

    public int height(AvlNode temp)
    {
        int height = 0;
        if(temp != null)
        {
            int leftHeight = height(temp.left);
            int rightHeight = height(temp.right);
            int maxHeight = max(leftHeight,rightHeight);
            height = maxHeight + 1;
        }
        return height;
    }

    public int max(int a,int b)
    {
        if(a > b)
            return a;
        else
            return b;
    }

    public AvlNode llRotate(AvlNode parent)
    {
        AvlNode temp;
        temp = parent.left;
        parent.left = temp.right;
        temp.right = parent;
        return temp;
    }

    public AvlNode rrRotate(AvlNode parent)
    {
        AvlNode temp;
        temp = parent.right;
        parent.right = temp.left;
        temp.left = parent;
        return temp;
    }

    public AvlNode rlRotate(AvlNode parent)
    {
        AvlNode temp;
        temp = parent.right;
        parent.right = llRotate(temp);
        return rrRotate(parent);
    }

    public AvlNode lrRotate(AvlNode parent)
    {
        AvlNode temp;
        temp = parent.left;
        parent.left = rrRotate(temp);
        return llRotate(parent);
    }

    public void displayTree(AvlNode temp,int level)
    {
        if(temp != null)
        {
            displayTree(temp.right, level+1);
            System.out.println("");
            if(temp == this.root)
            {
                System.out.print("Root ->");
            }
            for(int i=0; (i < level) && (temp != this.root);i++)
                System.out.print("        ");
            System.out.print(temp.data);
            displayTree(temp.left, level+1);
        }
    }

    public AvlNode search(AvlNode temp,int data)
    {
        try{
        if(temp.data == data || temp == null)
        {
            return temp;
        }
        if(temp.data < data)
            return search(temp.right,data);
        
        return search(temp.left,data);
        }
        catch(Exception e)
        {
            return null;
        }
    }

    public void inOrder(AvlNode temp)
    {
        if(temp == null)
            return;
        inOrder(temp.left);
        System.out.print("->" + temp.data);
        inOrder(temp.right);
    }

    public void preOrder(AvlNode temp)
    {
        if(temp == null)
            return;
        System.out.print("->" + temp.data);
        preOrder(temp.left);
        preOrder(temp.right);
    }

    public void postOrder(AvlNode temp)
    {
        if(temp == null)
            return;
        postOrder(temp.left);
        postOrder(temp.right);
        System.out.print("->" + temp.data);
    }
}

public class AvlTree
{
    public static void main(String args[])
    {
        int choice = 0;
        Scanner scanner = new Scanner(System.in);
        Avl avl = new Avl();
        while(true)
        {
            System.out.println("Enter your choice 1.Insert a data\n 2.Display balanced Tree\n 3.In Order Traversal \n 4. Pre Order Traversal \n 5. Post Order Traversal \n 6.Search \n 7.Delete \n 8.Exit");
            choice = scanner.nextInt();
            switch(choice)
            {
                case 1:
                    System.out.println("Enter the data to be inserted:");
                    avl.root = avl.addKey(avl.root, scanner.nextInt());
                    break;
                case 2:
                    if(avl.root == null)
                        {
                            System.out.println("Tree is empty!");
                            continue;
                        }
                    avl.displayTree(avl.root, 1);
                    System.out.println("");                    
                    break;
                case 3:
                    System.out.println("Inorder traversal:");
                    avl.inOrder(avl.root);
                    System.out.println("");
                    break;
                case 4:
                    System.out.println("PreOrder Traversal:");
                    avl.preOrder(avl.root);
                    System.out.println("");
                    break;
                case 5: 
                    System.out.println("PostOrder Traversal:");
                    avl.postOrder(avl.root);
                    System.out.println("");
                    break;
                case 6:
                        System.out.println("Enter the data to be searched:");
                        int data = scanner.nextInt();
                        AvlNode x = avl.search(avl.root,data);
                        if(x == null)
                            System.out.println("Data not found");
                        else if(x.data == data)
                            System.out.println("Data Found!");
                        break;
                case 7:
                    System.out.println("Enter the element to be deleted:");    
                    data = scanner.nextInt();
                    x = avl.search(avl.root,data);
                    if(x == null)
                        System.out.println("Data not found");
                    else if(x.data == data)
                        avl.root = avl.deleteNode(avl.root,data);
                        System.out.println("Data Deleted!");
                    break;
                case 8:
                        System.out.println("Bye!");
                        System.exit(0);
            }
        }   
    }
}