import java.util.Scanner;
import java.text.DecimalFormat;

/*
    ***************SAFE MOVE****************
    => Sort value per unit in decending order
    ***************ALGORITHM****************
    => Insert the largest values[i]/weights[i] to the
        knapsack if it is feasible else fill it as much
        as it can hold
    => Insert the next as per the above rule and continue
*/

public class Knapsack
{
    private static int min(int numOne, int numTwo)
    {
        if(numOne <= numTwo)
            return numOne;
        return numTwo;
    }

    private static int getMaxIndex(double valuePerUnit[], int noOfItems)
    {
        int maxIndex = 0;
        for(int i = 0; i < noOfItems; i++)
        {
            if(valuePerUnit[maxIndex] <= valuePerUnit[i])
                maxIndex = i;
        }
        return maxIndex;
    }

    private static double getMaxValue(int noOfItems, int totalWeight, int weights[], int values[])
    {
        double valuePerUnit[] = new double[noOfItems];
        for(int i = 0; i < noOfItems; i++)
        {
            valuePerUnit[i] = ((double)values[i]) / weights[i]; 
        }
        double finalValue = 0;
        for(int i = 0; i < noOfItems; i++)
        {
            if(totalWeight == 0)
                return finalValue;
            int maxIndex = getMaxIndex(valuePerUnit, noOfItems);
            int takenAmount = min(weights[maxIndex] , totalWeight);
            finalValue += takenAmount * valuePerUnit[maxIndex];
            weights[maxIndex] -= takenAmount;
            if(weights[maxIndex] == 0)
                valuePerUnit[maxIndex] = 0;
            else
                valuePerUnit[maxIndex] = values[maxIndex] / weights[maxIndex];
            totalWeight -= takenAmount;
        }
        return finalValue;
    }

    public static void main(String args[])
    {
        Scanner scanner = new Scanner(System.in);
        DecimalFormat decimalFormat = new DecimalFormat("#.####");
        
        //System.out.println("Give total number of items:");
        int noOfItems = scanner.nextInt();

        //System.out.println("Give total capacity of knapsack:");
        int totalWeight = scanner.nextInt();

        int values[] = new int[noOfItems];
        int weights[] = new int[noOfItems];

        //System.out.println("Give values and their weights:");
        for(int i = 0; i < noOfItems; i++)
        {
            values[i] = scanner.nextInt();
            weights[i] = scanner.nextInt();
        }

        //System.out.println("Maximum value can be stored in knapsack is:");
        System.out.println(decimalFormat.format(getMaxValue(noOfItems, totalWeight, weights, values)));
        scanner.close();
    }
}