import java.util.Scanner;
import java.util.ArrayList;
import java.util.List;
import java.lang.Integer;

public class PisanoPeriod
{
    /*
        * Pisano periods => F(n)%m =>> F[n + p] = F[n]
            => Where p is called 'periods'
        * Pisano periods are always even except for => F[2] = 3
        * Each series starts with 0 , 1
    */

    private static int getPisanoPeriod(long n, int mod)
    {
        List<Integer> fib = new ArrayList<>();
        fib.add(0);
        fib.add(1);
        int i = 2;
        int periods = 0;

        if(mod == 2)
            periods = 3;
        else
        {
            while(true)
            {
                fib.add((fib.get(i - 1) + fib.get(i - 2)) % mod);
                i++;
                periods++;
                fib.add((fib.get(i - 1) + fib.get(i - 2)) % mod);
                periods++;
                if(fib.get(i) == 1 && fib.get(i - 1) == 0)
                    break;
                i++;
            }
        }
        return fib.get((int)(n % periods));
    }

    public static void main(String args[])
    {
        Scanner scanner = new Scanner(System.in);
        long n = 0;
        int mod = 0;

        n = scanner.nextLong();
        mod = scanner.nextInt();

        System.out.println(getPisanoPeriod(n, mod));
        scanner.close();
    }
}