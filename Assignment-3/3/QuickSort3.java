import java.util.Scanner;
import java.util.Random;

/*
    ****************DIVIDE AND CONQUER****************
    * Take last element as pivot
    * Compare the pivot element with all other elements in the sub array
    * If the element is equal to pivot element then decrement
      pivot index and swap the traversing index and pivot index
    * If the element is smaller increase k-index
    * Else dont increment it.
    => Finally k-index will be the starting index of the elements
       bigger than pivot element and all the elements equal to pivot element 
       will be in the last
    => So shift the last portion with k portion
    => Then the pivot and all of its redundant elements will be in final position 
       of the array 
    => Continue this to get Sorted array
*/
public class QuickSort3
{
    private static int min(int a, int b)
    {
        if(a < b)
            return a;
        return b;
    }

    private static void swap(int[] array, int i, int j)
    {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }

    private static void quickSort3(int[] list, int low, int high)
    {
        Random random = new Random();
        if(low > high)
            return;
        
        int pivot_index = random.nextInt(high - low + 1) + low;
        swap(list, pivot_index, high);
        int i = low;
        int k = low;
        int pivot = high;
    
        while(i < pivot)
        {
            if(list[i] < list[pivot])
            {
                swap(list, i, k);
                i++;
                k++;
            }
            else if(list[i] == list[pivot])
            {
                pivot--;
                swap(list, i, pivot);
            }
            else
            {
                i++;
            }
        }
        int m = min(pivot - k, high - pivot + 1);
        
        for(int lc = 0; lc < m; lc++)
        {
            swap(list, k + lc,high - m + 1 + lc );
        }
        quickSort3(list, low, k - 1);
        quickSort3(list, high - pivot + k + 1, high);
    }

    public static void main(String[] args) 
    {
        Scanner scanner = new Scanner(System.in);
        //System.out.println("Give n:");
        int n = scanner.nextInt();
        
        int list[] = new int[n];

        //System.out.println("Give n elements:");
        for(int i = 0; i < n; i++)
            list[i] = scanner.nextInt();
        
        scanner.close();    

        quickSort3(list, 0, n - 1);

        //System.out.println("Sorted elements are: ");
        for(int i = 0; i < n; i++)
            System.out.print(list[i] + " ");
        System.out.println("");
    }
}