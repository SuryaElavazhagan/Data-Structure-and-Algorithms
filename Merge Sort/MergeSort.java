import java.util.Scanner;

/*
    *************DIVIDE AND CONQUER**************
    * Divide array into 2
    * Merge the 2 array
    ******************MERGING********************
    * Compare each elements from two half of the array
      from left to right and insert the least to a temp array
    * At last any of the two half will be empty
    * Put all the elements from the non-empty array to temp array
    * Return temp.
*/

public class MergeSort
{
    private static void merge(int list[], int low, int high, int mid)
    {
        /*
            * Actual logic goes here.
        */
        int left_index, right_index, temp_index;

        int left_size = mid - low + 1;
        int right_size = high - mid;

        int left_half[] = new int[left_size];
        int right_half[] = new int[right_size];

        // Inserting left half to left temporary array
        for(int i =0; i < left_size; i++)
            left_half[i] = list[low + i];
        
        // Inserting right half to right temporary array
        for(int i =0; i < right_size; i++)
            right_half[i] = list[mid + 1 + i];
        
        left_index = 0;
        right_index = 0;
        temp_index = low;

        // Comparing and storing to temporary array
        while(left_index < left_size && right_index < right_size)
        {
            if(left_half[left_index] <= right_half[right_index])
                list[temp_index++] = left_half[left_index++];
            else
                list[temp_index++] = right_half[right_index++];
        }

        // Copying the remaining elements.
        while(left_index < left_size)
            list[temp_index++] = left_half[left_index++];
        
        while(right_index < right_size)
            list[temp_index++] = right_half[right_index++];
    }

    private static void mergeSort(int list[], int low, int high)
    {
        if(low < high)
        {
            int mid = (int)((low + high) / 2);

            // Left half
            mergeSort(list, low, mid);
            
            // Right half
            mergeSort(list, mid + 1, high);
            
            // Combining two halves
            merge(list, low, high, mid);
        }
    }

    public static void main(String args[])
    {
        Scanner scanner = new Scanner(System.in);
        
        //System.out.println("Give n:");
        int n = scanner.nextInt();

        int list[] = new int[n];

        //System.out.println("Give n elements:");
        for(int i = 0; i < n; i++)
            list[i] = scanner.nextInt();
        
        scanner.close();
        mergeSort(list, 0, n - 1);

        //System.out.println("Sorted elements:");
        for(int i = 0; i < n; i++)
            System.out.print(list[i] + "\t");
    }
}