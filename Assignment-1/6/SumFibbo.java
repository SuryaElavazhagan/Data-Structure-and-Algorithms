import java.util.Scanner;

public class SumFibbo
{
    /*
        * Sum of 'n' fibonacci numbers is => F[n + 2] - 1
        * Explaination in README.md
    */
    private static int[] fib = new int[60 + 1];
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
    private static int sumFib(long n)
    {
        if(n <= 1)
            return (int)n;
        load();
        return fib[(int)((n + 2) % 60)] -1;
    }

    public static void main(String args[])
    {
        Scanner scanner = new Scanner(System.in);
        long n = scanner.nextLong();
        System.out.println(sumFib(n));
        scanner.close();
    }
}