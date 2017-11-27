import java.util.Scanner;

public class LastDigitFibbo
{
    public static void main(String args[])
    {
        Scanner scanner = new Scanner(System.in);
        int n = 0;
        n = scanner.nextInt();

        int fibbo[] = new int[n + 1];
        fibbo[0] = 0;
        fibbo[1] = 1;

        for(int i = 2; i <= n ; i++)
        {
            fibbo[i] = (fibbo[i - 1] + fibbo[i - 2]) % 10;
        }
        System.out.print(fibbo[n]);
        scanner.close();
    }
}