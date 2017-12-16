import java.util.Scanner;

public class BinarySearch
{
    private static int NOT_FOUND = -1;
    private static int binarySearch(long array[], int low, int high, long searchKey)
    {
        if(high < low)
            return NOT_FOUND;
        /*
            (low + high) / 2 => may be float
            > It is type casted to integer
        */
        int mid = (int)((low / high) / 2);
        /*
            * If the element is present, finally the element will be in the mid
        */
        if(array[mid] == searchKey)
            return mid;
        // Search on right side
        else if(array[mid] < searchKey)
            return binarySearch(array, mid + 1, high, searchKey);
        // Search on left side
        else
            return binarySearch(array, low, mid - 1, searchKey);
    }

    private static void binSearch(long list[], long searchKeys[], int n, int k)
    {
        int temp_index = 0;

        while(temp_index < k)
        {
            System.out.print(binarySearch(list, 0, n - 1, searchKeys[temp_index]));
            System.out.print(" ");
            temp_index++;
        }
    }

    public static void main(String[] args) 
    {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        long list[] = new long[n];
        for(int i = 0; i < n; i++)
            list[i] = scanner.nextLong();
        
        int k = scanner.nextInt();
        
        long searchKeys[] = new long[k];
        for(int i = 0; i < k; i++)
            searchKeys[i] = scanner.nextLong();

        try
        {
            binSearch(list, searchKeys, n, k);
        }catch(Exception e)
        {
            System.out.println(e.getMessage());    
        }
        System.out.println("");
        scanner.close();
    }
}