import java.util.Scanner;
import java.util.Arrays;

/*
    ***************SAFE MOVE****************
    => Sort given arrays
    ***************ALGORITHM****************
    => Multiply elements from each array
        corresponding to their positions
        and add them to final result
    => Return result
*/

public class MaxPay
{
    public static void main(String args[])
    {
        Scanner scanner = new Scanner(System.in);
        //System.out.println("Give number of ads:");
        int noOfAds = scanner.nextInt();
        long sum = 0;
        long profitPerClick[] = new long[noOfAds];
        long avgClickInSlot[] = new long[noOfAds];
        
        //System.out.println("Give profit per click:");
        for(int i = 0; i < noOfAds; i++)
            profitPerClick[i] = scanner.nextLong();
        
        //System.out.println("Give average clicks in i-th slot per day:");
        for(int i = 0; i < noOfAds; i++)
            avgClickInSlot[i] = scanner.nextLong();
        
        Arrays.sort(profitPerClick);
        Arrays.sort(avgClickInSlot);

        //System.out.println("Maximum revenue will be:");
        for(int i = 0; i < noOfAds; i++)
            sum += profitPerClick[i] * avgClickInSlot[i];
        
        System.out.println(sum);
    }
}