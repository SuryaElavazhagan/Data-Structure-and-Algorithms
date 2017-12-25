import java.util.Scanner;

/*
    ******************DIVIDE AND CONQUER*****************
    * Store the points in the structure like
        -> point
        -> category
      For example: if it is a segment (2, 5)
      store it as (2, 'left') & (5, 'right')
      If it is a point (4)
      store it as (4, 'point')
    * Sort them in non decreasing order:
        Then it will be like
        (2, 'left') (4, 'point') (5, 'right')
        It shows that 4 lies between 2 and 5
    * The important problem to consider lies in sorting
    i.e., (2, 5) (2, 7) (2, 10) => Segments
          (2) (4) (3)           => Points
          then the sorted order should be:
          (2, 'left') (2 , 'left') (2, 'left') (2, 'point')
          (3, 'point') (4, 'point') (5, 'right') (7, 'right')
          (10, 'right')
    => The redundancy should be handled properly.
*/

class Coordinates
{
    public int data;
    public int category;
    public int index;
    /*
        * This index is to store the index of the point.
        * This will be helpful in calculations.
    */
    public Coordinates(int data, int category, int index)
    {
        this.index = index;
        this.category = category;
        this.data = data;
    }
}

public class Lottery
{
    private static final int LEFT = -1; // To indicate it as left side of the segement
    private static final int RIGHT = 1; // To indicate it as right side of the segement
    private static final int POINT = 0;// To indicate it as point

    private static void merge(Coordinates list[], int low, int high, int mid)
    {
        /*
            * Actual logic goes here.
        */
        int left_index, right_index, temp_index;

        int left_size = mid - low + 1;
        int right_size = high - mid;

        Coordinates left_half[] = new Coordinates[left_size];
        Coordinates right_half[] = new Coordinates[right_size];

        // Inserting left half to left temporary array
        for(int i = 0; i < left_size; i++)
            left_half[i] = list[low + i];
        
        // Inserting right half to right temporary array
        for(int i = 0; i < right_size; i++)
            right_half[i] = list[mid + 1 + i];
        
        left_index = 0;
        right_index = 0;
        temp_index = low;

        // Comparing and storing to temporary array
        while(left_index < left_size && right_index < right_size)
        {
            /*
                The redundancy is handle here.
                If the category is same you can push both elements
                from left and right sub array.
                else Check which category is low and push them.
            */
            if(left_half[left_index].data == right_half[right_index].data)
            {
                if(left_half[left_index].category < right_half[right_index].category)
                    list[temp_index++] = left_half[left_index++];
                else if(left_half[left_index].category > right_half[right_index].category)
                    list[temp_index++] = right_half[right_index++];
                else
                    {
                        list[temp_index++] = left_half[left_index++];
                        list[temp_index++] = right_half[right_index++];
                    }
            }
            if(left_half[left_index].data < right_half[right_index].data)
                list[temp_index++] = left_half[left_index++];
            else
                list[temp_index++] = right_half[right_index++];
        }

        // Copying the remaining elements.
        // Only one of the loop will be executed.
        while(left_index < left_size)
            list[temp_index++] = left_half[left_index++];
        
        while(right_index < right_size)
            list[temp_index++] = right_half[right_index++];
    }

    private static void mergeSort(Coordinates list[], int low, int high)
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

    private static void getRange(Coordinates cords[], int segments, int points)
    {
        int size = (2 * segments) + points;
        /*
            This layer indicates the number of segments in 
            which the point lies. 
        */
        int segment_layer = 0;
        int result[] = new int[points];

        for(int i = 0; i < size; i++)
        {
            if(cords[i].category == LEFT)
            {
                segment_layer++;
            }
            if(cords[i].category == RIGHT)
            {
                segment_layer--;
            }
            if(cords[i].category == POINT)
            {
                // Here the index is actually used.
                result[cords[i].index] = segment_layer;
            }
        }

        for(int i = 0; i < points; i++)
        {
            System.out.print(result[i]);
            System.out.print(" ");
        }
    }

    public static void main(String[] args) 
    {
        Scanner scanner = new Scanner(System.in);

        //System.out.println("Give number of segments and points:");
        int segments = scanner.nextInt();
        int points = scanner.nextInt();
        int temp_segments = 2 * segments;
        int temp_left;
        int temp_right;
        int lc1 = 0; // loop counter 1
        int lc2 = 0; // loop counter 2
        Coordinates[] cords = new Coordinates[temp_segments + points];
        
        //System.out.println("Give segments:");
        for(lc1 = 0; lc1 < temp_segments; lc1++)
        {
            temp_left = scanner.nextInt();
            temp_right = scanner.nextInt();
            cords[lc1] = new Coordinates(temp_left, LEFT, -1);
            cords[++lc1] = new Coordinates(temp_right, RIGHT, -1);
        }

        //System.out.println("Give Points:");
        for(lc2 = 0; lc2 < points; lc2++)
        {
            temp_left = scanner.nextInt();
            cords[lc1++] = new Coordinates(temp_left, POINT, lc2);
        }

        mergeSort(cords, 0, temp_segments + points - 1);
        //System.out.println("The result is:");
        getRange(cords, segments, points);
        scanner.close();
        System.out.println("");
    }
}
