import java.util.Scanner;
import java.util.ArrayList;
import java.lang.Long;
import java.lang.Integer;

public class MinHeap
{
    private static int leftChild(int i)
    {
        return (2 * i) + 1;
    }

    private static int rightChild(int i)
    {
        return (2 * i) + 2;
    }

    private static void swap(int a, int b, ArrayList<Long> mHeap)
    {
        Long temp = mHeap.get(a);
        mHeap.set(a, mHeap.get(b));
        mHeap.set(b, temp);
    }

    private static void swiftDown(int i, int SIZE,ArrayList<Long> mHeap, ArrayList<Integer> mSwaps)
    {
        int leftChildIndex = leftChild(i);
        int rightChildIndex = rightChild(i);
        int minIndex = i;

        if(leftChildIndex < SIZE && mHeap.get(minIndex) > mHeap.get(leftChildIndex))
            minIndex = leftChildIndex;
        
        if(rightChildIndex < SIZE && mHeap.get(minIndex) > mHeap.get(rightChildIndex))
            minIndex = rightChildIndex;
        
        if(i != minIndex)
        {
            mSwaps.add(i);
            mSwaps.add(minIndex);
            swap(minIndex, i, mHeap);
            swiftDown(minIndex, SIZE, mHeap, mSwaps);
        }
    }

    public static void main(String[] args) 
    {
        int SIZE = 0;
        ArrayList<Long> mHeap = new ArrayList<Long>();
        ArrayList<Integer> mSwaps = new ArrayList<Integer>();
        Scanner mScanner = new Scanner(System.in);
        SIZE = mScanner.nextInt();

        for(int i = 0; i < SIZE; i++)
        {
            mHeap.add(mScanner.nextLong());
        }

        for(int i = (SIZE/2); i >= 0; i--)
        {
            swiftDown(i, SIZE, mHeap, mSwaps);
        }
        
        System.out.println((mSwaps.size()/2));
        for(int i = 0; i < mSwaps.size(); i++)
        {
            System.out.println(mSwaps.get(i++) + " " + mSwaps.get(i));
        }
        mScanner.close();
    }
}