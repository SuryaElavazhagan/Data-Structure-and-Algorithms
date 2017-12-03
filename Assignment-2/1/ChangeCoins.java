import java.util.Scanner;

public class ChangeCoins
{
    private static int getMinCoins(int amount)
    {
        // Store the coins in decending order
        int coins[] = {10 , 5 , 1};
        // total_coins save the minimum coins required
        int total_coins = 0;
        // i stores the current index of coins array
        int i = 0;
        
        while(amount != 0)
        {
            if(amount % coins[i] == amount)
            {
                i++;
                continue;
            }
            else
            {
                total_coins += amount / coins[i];
                amount = amount % coins[i];
                i++;
            }
        }
        return total_coins;
    }

    public static void main(String args[])
    {
        Scanner scanner = new Scanner(System.in);
        // System.out.println("Enter the amount:");
        int amount = scanner.nextInt();

        // System.out.println("Minimum number of coins required:");
        System.out.println(getMinCoins(amount));
        scanner.close();
    }
}