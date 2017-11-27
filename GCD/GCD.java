import java.util.Scanner;

public class GCD
{
    private static int gcd(int a, int b)
    {
        if(b == 0)
            return a;
        else
        {
            a = a % b;
            //System.out.println("a : " + a + " b : "+ b);
            return gcd(b, a);
        }
    }

    public static void main(String args[])
    {
        Scanner scanner = new Scanner(System.in);
        int a = 0;
        int b = 0;
        System.out.println("Give a:");
        a = scanner.nextInt();
        System.out.println("Give b:");
        b = scanner.nextInt();
        scanner.close();

        System.out.println("GCD(" + a + " , " + b + ") : " + gcd(a, b));
    }
}