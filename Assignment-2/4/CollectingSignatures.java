import java.util.*;

/*
    ***************SAFE MOVE****************
    => Sort given segments based on right end
    ***************ALGORITHM****************
    => Check whether right end is to the right of
        next segment left end i.e.,
        > b[i] >= a[i + 1]
    => if not increment the count and add b[i + 1] 
        to the result
*/
class myCoordinates
{
    int pointOne;
    int pointTwo;

    public myCoordinates(int pointOne, int pointTwo)
    {
        this.pointOne = pointOne;
        this.pointTwo = pointTwo;
    }

    public int getPointTwo()
    {
        return this.pointTwo;
    }
}

public class CollectingSignatures
{
    private static void getMinSegment(int n, List<myCoordinates> cord)
    {
        int indexOne = 1;
        int indexTwo = 0;
        int points[] = new int[n];
        points[0] = cord.get(indexTwo).pointTwo;
        int count = 1;

        while(indexOne < n)
        {
            if(points[indexTwo] >= cord.get(indexOne).pointOne)
            {
                indexOne++;
            }
            else{
                indexTwo++;
                count++;
                points[indexTwo] = cord.get(indexOne).pointTwo;
                indexOne++;
            }
        }
        System.out.println(count);
        for(int i = 0; i <= indexTwo; i++)
            System.out.println(points[i]);
    }

    public static void main(String args[])
    {
        Scanner scanner = new Scanner(System.in);
        // System.out.println("Give n:")
        int n = scanner.nextInt();
        List<myCoordinates> cord = new ArrayList<>();
        //System.out.println("Give end points of segments:");
        for(int i = 0; i < n ; i++)
        {
            cord.add(new myCoordinates(scanner.nextInt(), scanner.nextInt()));
        }

        // Sorting based on right end
        Collections.sort(cord, Comparator.comparingInt(myCoordinates::getPointTwo));

        //System.out.println("The result is:");
        getMinSegment(n, cord);
        scanner.close();
    }
}