import java.util.Scanner;

/*
    **************DYNAMIC PROGRAMMING****************
    * In greedy algorithm, The program fails for some test cases like,
    For e.g., coins -> 1 , 8 , 20
              amount -> 24
              Then the greedy algorithm gives => 20 + 1 + 1 + 1 + 1
    * To overcome this, the change for each and every amount is stored 
    * and used whenever needed.
*/

public class CoinChange
{
    private static int getChange(int money, int coins[])
    {
        int change[] = new int[money + 1];
        change[0] = 0;
        int numCoins = 0;
        for(int i = 1; i <= money; i++)
        {   
            change[i] = Integer.MAX_VALUE;
            for(int j = 0; j < coins.length; j++)
            {
                if(i >= coins[j])
                {
                    numCoins = change[i - coins[j]] + 1;
                }
                if(numCoins < change[i])
                {
                    change[i] = numCoins;
                }
            }
        }    
        return change[money];
    } 

    public static void main(String args[])
    {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Give number of coins: ");
        int noOfCoins = scanner.nextInt();

        System.out.println("Give coins");
        int coins[] = new int[noOfCoins];
        for(int i = 0; i < noOfCoins; i++)
        {
            coins[i] = scanner.nextInt();
        }

        System.out.println("Give money :");
        int money = scanner.nextInt();

        System.out.println("The minimum number of coins : " + getChange(money, coins));
        scanner.close();
    }
}