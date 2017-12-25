import java.util.Scanner;

public class CloseSort
{
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
    private static int merge(int list[], int low, int high, int mid, int leftInversion, int rightInversion)
    {
        /*
            * Actual logic goes here.
        */
        int inversion = leftInversion + rightInversion;
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
            {
                /*
                    **************** Important **********************
                    * If the right half contains smaller element than the
                    * left half then the right element is lesser than
                    * all the elements from left_index
                    * For eg.,
                    *  left half = 2 5 6 8 9
                    *  right half = 4 7 10 11
                    * Consider '4' from right half
                    * It is greater than 2 then left_index is incremented.
                    * Now '4' is lesser than 5
                    * It is lesser than 5,6,8,9
                    * So it takes 4 Inversions.
                */
                inversion += left_size - left_index;
                list[temp_index++] = right_half[right_index++];
            }
        }

        // Copying the remaining elements.
        while(left_index < left_size)
            list[temp_index++] = left_half[left_index++];
        
        while(right_index < right_size)
            list[temp_index++] = right_half[right_index++];
        return inversion;
    }

    private static int mergeSort(int list[], int low, int high)
    {
        int leftInversion = 0;
        int rightInversion = 0;
        if(low < high)
        {
            int mid = (int)((low + high) / 2);

            // Left half
            leftInversion = mergeSort(list, low, mid);
            
            // Right half
            rightInversion = mergeSort(list, mid + 1, high);
            
            // Combining two halves
            return merge(list, low, high, mid, leftInversion, rightInversion);
        }
        return 0;
    }
    public static void main(String[] args) 
    {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int list[] = new int[n];
        for(int i = 0; i < n; i++)
        {
            list[i] = scanner.nextInt();
        }
        System.out.println(mergeSort(list, 0, n - 1));
        scanner.close();    
    }
}