import java.util.Scanner;
//import java.util.Random;

/*
    ***************DIVIDE AND CONQUER*****************
    * Divide the array into two halves.
    * Get the majority element from both the halves.
    * And compare both the majority elements and get the result.

    Note:
        This can also be done using Hash table with O(n) time complexity
        but for now it runs O(nlogn) => Divide and conquer method.
*/

public class MajorityVotes
{
    private static int MAJORITY_ELEMENT_FOUND = 1;
    private static int NO_MAJORITY_ELEMENT = 0;
    private static int NO_VOTE = -1;

    private static long getMajorityElement(long votes[], long leftMajorityElement, long rightMajorityElement, int low, int high)
    {
        int leftCount = 0;
        int rightCount = 0;

        // Counting both left and right majority element.
        for(int i = 0; i <= high; i++)
        {
            if(votes[i] == leftMajorityElement)
                leftCount++;
            if(votes[i] == rightMajorityElement)
                rightCount++;
        }

        /*
            On dividing array into half majority level changes
            i.e., for n = 10, majority votes will be >5
            if it is split to two halves 5 & 5

            for n = 5 => majority votes will be >2
        */
        int majorityLimit = (int)((high + 1 - low) / 2);
        if(leftCount > majorityLimit)
            return leftMajorityElement;
        else if(rightCount > majorityLimit)
            return rightMajorityElement;
        else 
        /*
            If both left and right elements are not majority element
            Then return negative means no vote.
        */
            return NO_VOTE;
    }

    private static long getMajority(long votes[], int low, int high)
    {
        // Base case => Divided array is at last level
        if(low == high)
            return votes[low];
        
        // Computing mid index
        int mid = (int)((low + high) / 2);
        
        // Left half
        long leftMajorityElement = getMajority(votes, low, mid);
        
        // Right half
        long rightMajorityElement = getMajority(votes, mid + 1, high);

        // Returning the majority element if present, else -1.
        return getMajorityElement(votes, leftMajorityElement, rightMajorityElement, low, high);
    }

    private static int divideAndConquer(long votes[], int n)
    {
        if(n <= 2)
            return 0;
        
        if(getMajority(votes, 0, n - 1) == -1)
            return NO_MAJORITY_ELEMENT;
        else
            return MAJORITY_ELEMENT_FOUND;
    }

    /*
    // **********************STRESS TESTING*******************
    private static int naiveAlgorithm(long votes[], int n)
    {
        long current_element = 0;
        int count = 0;
    
        if(n <= 2)
            return NO_MAJORITY_ELEMENT;
        
        for(int i = 0; i < n; i++)
        {
            current_element = votes[i];
            count = 0;
            for(int j = 0; j < n; j++)
            {
                if(votes[j] == current_element)
                    count++;
            }
            if(count > (int)(n / 2))
                return MAJORITY_ELEMENT_FOUND;
        }
        return NO_MAJORITY_ELEMENT;
    }

    private static void stressTesting()
    {
        Random random = new Random();
        while(true)
        {
            int n = random.nextInt(100) + 1;
            
            System.out.println("n : " + n);

            long votes[] = new long[n];

            for(int i = 0; i < n; i++)
            {
                votes[i] = random.nextInt(100000) + 1;
                System.out.print(votes[i]);
            }

            if(divideAndConquer(votes, n) == naiveAlgorithm(votes, n))
            {
                System.out.println("Success.");
            }
            else
            {
                System.out.println("Failed.");
                break;
            }
        }
    }
    */
    public static void main(String[] args) 
    {
        //stressTesting();
    
        Scanner scanner= new Scanner(System.in); 

        //System.out.println("Give n:");   
        int n = scanner.nextInt();
        long votes[] = new long[n];

        //System.out.println("Give n elements:");
        for(int i = 0; i < n; i++)
            votes[i] = scanner.nextLong();
        scanner.close();
        //System.out.println("Majority element found (1 / 0):")
        System.out.println(divideAndConquer(votes, n));
    }
}