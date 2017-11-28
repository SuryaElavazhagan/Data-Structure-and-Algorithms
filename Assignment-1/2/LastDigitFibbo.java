import java.util.Scanner;

public class LastDigitFibbo
{
    public static void main(String args[])
    {
        Scanner scanner = new Scanner(System.in);
        int n = 0;
        n = scanner.nextInt();

        int previous = 0;
        int current = 1;
        
        for(int i = 2; i <= n ; i++)
        {
            int temp_previous = previous;
            previous = current;
            current = (previous + temp_previous)%10;
        }
        System.out.println(current);
        scanner.close();
    }
}