import java.util.*;

public class MaxPairwiseSum
{
    private static void getMaxPairwiseSum(long n)
    {
        List<Long> pairs = new ArrayList<>();
        long temp = 1;
        pairs.add(temp);
        temp++;
        n -= 1;
        while(n != 0)
        {
            if(n > (temp * 2))
            {
                pairs.add(temp);
                n -= temp;
                temp++;
            }
            else
            {
                pairs.add(n);
                break;
            }
        }
        System.out.println(pairs.size());
        for(int i = 0; i < pairs.size(); i++)
            System.out.println(pairs.get(i));
    }

    public static void main(String args[])
    {
        Scanner scanner = new Scanner(System.in);
        long n = scanner.nextLong();

        if(n <= 2)
            System.out.println("1\n" + n);
        else
            getMaxPairwiseSum(n);
        scanner.close();
    }
}