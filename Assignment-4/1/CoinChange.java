import java.util.Scanner;

public class CoinChange
{
    private static int coins[] = {1, 3, 4};
    private static int coinChange(int money)
    {
        int minimumNumberOfCoins[] = new int[money + 1];
        int noOfCoins = 0;
        minimumNumberOfCoins[0]= 0;
        for(int i = 1; i <= money; i++)
        {
            minimumNumberOfCoins[i] = Integer.MAX_VALUE;
            for(int j = 0; j < 3; j++)
            {
                if(coins[j] <= i)
                {
                    noOfCoins = minimumNumberOfCoins[i - coins[j]] + 1;
                }
                if(noOfCoins < minimumNumberOfCoins[i])
                {
                    minimumNumberOfCoins[i] = noOfCoins;
                }
            }
        }
        return minimumNumberOfCoins[money];
    }

    public static void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);
        int money = scanner.nextInt();

        System.out.println(coinChange(money));
        scanner.close();
    }
}