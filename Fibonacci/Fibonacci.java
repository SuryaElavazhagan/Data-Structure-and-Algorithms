import java.util.Scanner;

public class Fibonacci
{
    public static void main(String args[])
    {
        Scanner scanner = new Scanner(System.in);
        int n = 0;
        System.out.println("Give n:");
        n = scanner.nextInt();
        int mFibbo[] = new int[n];
        
        // Initialize basic values
        mFibbo[0] = 0;
        mFibbo[1] = 1;

        /*
            * F[n] = F[n - 1] + F[n - 2]
        */
        for(int i = 2; i < n; i++)
        {
            mFibbo[i] = mFibbo[i - 1] + mFibbo[i - 2];
        }
        
        for(int i = 0; i < n; i++)
            System.out.print(mFibbo[i] + " ");
    }
}