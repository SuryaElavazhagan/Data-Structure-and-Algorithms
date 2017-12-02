import java.util.Scanner;

public class CarFueling
{
    /*
        * This program has Loop nested within another loop
        * So, it seems to have O(n * n) run-time
        * But, the run time of the program is O(n)
            => currentRefills can be atmost n - 1
            => numRefills can be atmost n
            => So there will be atmost n + 1 operations
                => O(n + 1) => O(n)
    */
    private static int minRefills(int n, int a[], int distWithFullTank)
    {
        int currentRefills = 0;
        int lastRefills = 0;
        int numRefills = 0;
        //System.out.println("Stops where you need to get refilling:");
        while(currentRefills < (n - 1))
        {
            lastRefills = currentRefills;
            while((a[currentRefills + 1] - a[lastRefills]) <= distWithFullTank)
            {
                currentRefills++;
                if(currentRefills == (n - 1))
                    break;
            }
            //System.out.println(a[lastRefills]);
            if(currentRefills == lastRefills)
                return -1;
            if(currentRefills < (n - 1))
                numRefills++;
        }
        return numRefills;
    }

    public static void main(String args[])
    {
        Scanner scanner = new Scanner(System.in);
        
        //System.out.println("Give n:");
        int n = scanner.nextInt();

        int a[] = new int[n];
        //System.out.println("Give gas station stops in kms:");

        for(int i = 0; i < n; i++)
            a[i] = scanner.nextInt();
        
        //System.out.println("Give Mileage per full tank:");    
        int distWithFullTank = scanner.nextInt();

        //System.out.println("Number of refilling required:");
        System.out.println(minRefills(n, a, distWithFullTank));
        scanner.close();
    }
}