import java.util.Scanner;

public class LCM
{
    private static long gcd(long a, long b)
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
        long a = 0;
        long b = 0;
        //System.out.println("Give a:");
        a = scanner.nextLong();
        //System.out.println("Give b:");
        b = scanner.nextLong();
        scanner.close();

        System.out.print(((a * b) / gcd(a , b)));
    }
}