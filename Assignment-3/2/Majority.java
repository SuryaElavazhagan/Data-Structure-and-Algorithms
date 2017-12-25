import java.util.Scanner;

public class Majority
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

    private static int getMajority(int[] list, int n)
    {
        int mid = (int)(n / 2);
        for(int i = 0; i <= mid; i++)
        {
            if(n <= mid + i)
                continue;
            if(list[i] == list[mid + i])
                return 1;
        }
        return 0;
    }

    public static void main(String[] args) 
    {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] list = new int[n];

        for(int  i = 0; i < n; i++)
            list[i] = scanner.nextInt();
        
        mergeSort(list, 0, n - 1);
        scanner.close();

        System.out.println(getMajority(list, n));
    }
}