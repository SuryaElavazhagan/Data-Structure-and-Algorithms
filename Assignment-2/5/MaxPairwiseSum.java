import java.util.*;

/*
    ***************SAFE MOVE****************
    => Always start with 1 and increment till
     k < 2l
      > i.e., For eg., Input : 8
      > Start with => 1     Remaining : 7    > Condition(7 > (2 * 1)) => TRUE   
            > Add 1 to result
      > Increment  => 2     Remaining : 6    > Condition(6 > (2 * 2)) => TRUE
            > Add 2 to result
      > Increment  => 3     Remaining : 5    > Condition(5 > (2 * 3)) => FALSE
            > Add 5 to result
    => Stop
*/
public class MaxPairwiseSum
{
    /*
        This function actually does the SAFE MOVE
    */
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