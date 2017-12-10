import java.util.Scanner;

/*
    ************DIVIDE AND CONQUER***************
    => Get sorted elements as input
    => Compute mid element index and compare it with search key.
    => If the key is greater than mid element then search in right side
    => else search on right side
    => If the key is not found index at which it can be inserted is returned. 
*/

public class BinarySearch
{
    private static int binarySearch(int array[], int low, int high, int searchKey)
    {
        if(high < low)
            return low;
        /*
            (low + high) / 2 => may be float
            > It is type casted to integer
        */
        int mid = (int)((low / high) / 2);
        /*
            * If the element is present, finally the element will be in the mid
        */
        if(a[mid] == searchKey)
            return mid;
        // Search on right side
        else if(a[mid] < searchKey)
            return binarySearch(array, mid + 1, high, searchKey);
        // Search on left side
        else
            return binarySearch(array, low, mid - 1, searchKey);
    }
    public static void main(String[] args) 
    {
        Scanner scanner = new Scanner(System.in);

        //System.out.println("Give n:");
        int n = scanner.nextInt();
        
        int array[] = new int[n];

        //System.out.println("Give n sorted elements:");
        for(int i = 0; i < n; i++)
            array[i] = scanner.nextInt();

        //System.out.println("Give search key:");
        int searchKey = scanner.nextInt();

        //System.out.println("Element is found at (or) can be inserted at:");
        System.out.println(binarySearch(array, 0, n - 1, searchKey));
        scanner.close();
    }
}