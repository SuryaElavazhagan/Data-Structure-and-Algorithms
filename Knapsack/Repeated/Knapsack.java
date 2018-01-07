import java.util.Scanner;

/*
    ****************DYNAMIC PROGRAMMING******************
    * This program computes discrete knapsack value with repetitions allowed
    * It stores optimized  discrete knapsack value for each weight 
    * from [1.....W] where W is the total_capacity of the given knapsack.
    * It is same as Coin change problem (Dynamic programming).
    * It takes O(n * W) time.
*/

class item
{
    public int weight;
    public int value;

    public item(int weight, int value)
    {
        this.weight = weight;
        this.value = value;
    }
}

public class Knapsack
{
    private static int knapsack(item items[], int totalItems, int totalWeight)
    {
        int values_of_weights[] = new int[totalWeight + 1];
        values_of_weights[0] = 0;
        int current_value = 0;
        for(int olc = 1; olc <= totalWeight; olc++)
        {
            values_of_weights[olc] = 0;
            for(int ilc = 0; ilc < totalItems; ilc++)
            {
                if(items[ilc].weight <= olc)
                {
                    current_value = values_of_weights[olc - items[ilc].weight] + items[ilc].value;
                }
                if(current_value > values_of_weights[olc])
                {
                    values_of_weights[olc] = current_value;
                }
            }
        }
        return values_of_weights[totalWeight];
    }

    public static void main(String args[])
    {
        Scanner scanner = new Scanner(System.in);
        
        System.out.println("Give total capacity of knapsack :");
        int totalWeight = scanner.nextInt();

        System.out.println("Give total number of items :");
        int totalItems = scanner.nextInt();

        System.out.println("Give weights and values of items :");
        item items[] = new item[totalItems];

        for(int lc = 0; lc < totalItems; lc++)
        {
            items[lc] = new item(scanner.nextInt(), scanner.nextInt());
        }

        System.out.println("Maximum value the knapsack can hold is : " + knapsack(items, totalItems, totalWeight));
        scanner.close();
    }
}