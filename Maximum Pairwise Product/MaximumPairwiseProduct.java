import java.util.Scanner;
import java.util.Random;

/*
    * long is 64 bytes in java
    * int is 4 bytes in java
*/

public class MaximumPairwiseProduct
{
  /*
    private static long maximumPairwise(int a[])
    {
        long mResult = 0;
        for(int i = 0 ; i < a.length; i++)
        {
            for(int j = i+ 1 ; j < a.length; j++)
            {
                if(mResult < ((long)a[i]) * a[j])
                {
                    mResult = ((long)a[i]) * a[j];
                }
            }
        }
        return mResult;
    }
*/
    private static long maximumPairwiseFast(int a[])
    {
        int maxIndexOne = -1;
        int maxIndexTwo = -1;
        for(int i = 0; i < a.length; i++)
        {
            if(maxIndexOne == -1 || a[maxIndexOne] < a[i])
            {
                maxIndexOne = i;
            } 
        }

        for(int i = 0; i < a.length; i++)
        {
            if((maxIndexTwo == -1 || a[maxIndexTwo] < a[i]) && maxIndexOne != i)
            {
                maxIndexTwo = i;
            }
        }
        return ((long)a[maxIndexOne]) * a[maxIndexTwo];
    }
/*
    private static void stressTesting()
    {
        Random random = new Random();
        while(true)
        {
            
                *Random is a class from utility package
                *It generates Random numbers by a method nextInt
                *It can be overloaded with numbers like nextInt(100)
                    => it generates random numbers in range 0(inclusive) to 100(exclusive)
                    i.e., [0-99]
                *if a number is added to that function
                    random.nextInt(100) + 2 => its range will become [2-101]
            
            int n = random.nextInt(10) + 2;
            System.out.println(n);
            int numbers[] = new int[n];
            for(int i = 0; i < n; i++)
            {
                numbers[i] = random.nextInt(100000);
            }
            for(int i = 0; i < n; i++)
                System.out.println(numbers[i] + '\n');
            long mSlow = maximumPairwise(numbers);
            long mFast = maximumPairwiseFast(numbers);
            if(mSlow != mFast)
            {
                System.out.println("Success");
            }
            else{
                System.out.println("Failed " + " Slow : " + mSlow + " Fast : "+ mFast);
                break;
            }
        }
    }
*/
    public static void main(String args[])
    {
        Scanner scanner = new Scanner(System.in);
        int length;
        length = scanner.nextInt();
        int numbers[] = new int[length];
        for(int i = 0; i < length; i++)
        {
            numbers[i] = scanner.nextInt();
        }
        System.out.println(maximumPairwiseFast(numbers));
        //stressTesting();
    }
}