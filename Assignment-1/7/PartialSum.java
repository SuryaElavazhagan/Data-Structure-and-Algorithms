import java.util.Scanner;

public class PartialSum
{
    private static int fib[] = new int[61];

    /*
        * Sum of n Fibonacci numbers is F[n + 2] - 1
        * Sum of m to n Fibonacci numbers is
            => (F[n + 2] - 1) - (F[m + 2] - 1)
                    ||                ||        
                (nth Fibonacci)  (mth Fibonacci)
            => F[n + 2] - F[m + 2]
    */
    private static void load()
    {
        fib[0] = 0;
        fib[1] = 1;

        for(int i = 2; i <= 60; i++)
        {
            int temp = (fib[i - 1] + fib[i - 2]) % 10;
            if(temp == 0)
                temp = 10;
            fib[i] = temp;   
        }
    }

    private static int getSum(long n, long m)
    {
        load();
        int temp1 = fib[(int)((m + 2) % 60)];
        int temp2 = fib[(int)((n + 2) % 60)];

        if(temp2 < temp1)
            temp2 = temp2 + 10;
        return temp2 - temp1;
    }

    public static void main(String args[])
    {
        Scanner scanner = new Scanner(System.in);
        long n = 0;
        long m = 0;
        m = scanner.nextLong();
        n = scanner.nextLong();
        System.out.println(getSum(n, m - 1));
        scanner.close();
    }
}