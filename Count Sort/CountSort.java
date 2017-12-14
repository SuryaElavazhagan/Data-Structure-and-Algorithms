import java.util.Scanner;

/*
    * This sorting is done when the array is filled with a range of numbers
*/

public class CountSort
{
    private static int[] countSort(int list[], int no_of_elements, int max_number)
    {
        /*
            * Actual logic goes here
        */
        int count[] = new int[no_of_elements];
        int position[] = new int[max_number];
        
        // Counts each elements
        for(int i = 0; i < no_of_elements; i++)
            count[list[i]]++;
        
        // Stores position of each elements based on its count
        position[0] = 0;
        for(int i = 1; i < max_number; i++)
            position[i] = position[i - 1] + count[i - 1];

        // All elements are filled here
        int list_sorted[] = new int[no_of_elements];
        for(int i = 0; i < no_of_elements; i++)
        {
            list_sorted[position[list[i]]] = list[i];
            position[list[i]]++;
        }
        return list_sorted;
    }

    public static void main(String args[])
    {
        Scanner scanner = new Scanner(System.in);

        //System.out.println("Give n and max range:");
        int no_of_elements = scanner.nextInt();
        int max_number = scanner.nextInt();
        
        //System.out.println("Give array of n numbers:");
        int list[] = new int[no_of_elements];
        for(int i = 0; i < no_of_elements; i++)
        {
            list[i] = scanner.nextInt();
        }
        scanner.close();

        //System.out.println("Sorted array:");
        list = countSort(list, no_of_elements, max_number + 1);
        for(int i = 0; i < no_of_elements; i++)
            System.out.print(list[i] + "\t");
        System.out.println("");
    }
}