import java.util.Scanner;

/*
    ***************SAFE MOVE****************
    => Join two elements in the array
     > For ex: 21 2 Join them as
     > 212 and 221 and compare them
*/

public class MaxSalary
{
    /*
        Actual comparison is done here
    */

    private static int get_max(int a, int b)
    {
        String temp_a = String.valueOf(a) + String.valueOf(b);
        String temp_b = String.valueOf(b) + String.valueOf(a);
        if(Integer.parseInt(temp_a) > Integer.parseInt(temp_b))
            return a;
        else
            return b;
    }

    /*
        This function compares all the elements in the array
        and computes the result.
    */

    private static void get_max_salary(int n, int[] numbers)
    {
        String result = "";
        int max = 0;
        int temp_index;
        int temp_n = n;
        while(temp_n != 0)
        {
            max = numbers[0];
            temp_index = 0;
            for(int i = 0; i < n; i++)
            {
                max = get_max(max, numbers[i]);
                if(max == numbers[i])
                    temp_index = i;
            }
            numbers[temp_index] = 0;
            result += String.valueOf(max);
            temp_n--;
        }
        System.out.println(result);
    }

    /*
        Program starts here.
    */
    public static void main(String args[])
    {
        Scanner scanner = new Scanner(System.in);
        
        //System.out.println("Give n:");
        int n = scanner.nextInt();
        int numbers[] = new int[n];
        
        //System.out.println("Give array of n numbers:");
        for(int i = 0; i < n ; i++)
            numbers[i] = scanner.nextInt();
        
        //System.out.println("Maximum salary obtained from the combination of elements is:");
        get_max_salary(n, numbers);
        scanner.close();
    }
}