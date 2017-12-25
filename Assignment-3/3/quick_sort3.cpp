#include<iostream>
#include<vector>

/*
    ****************DIVIDE AND CONQUER****************
    * Take last element as pivot
    * Compare the pivot element with all other elements in the sub array
    * If the element is equal to pivot element then decrement
      pivot index and swap the traversing index and pivot index
    * If the element is smaller increase k-index
    * Else dont increment it.
    => Finally k-index will be the starting index of the elements
       bigger than pivot element and all the elements equal to pivot element 
       will be in the last
    => So shift the last portion with k portion
    => Then the pivot and all of its redundant elements will be in final position 
       of the array 
    => Continue this to get Sorted array
*/
using namespace std;

void swap(int &a, int &b)
{
    if(a == b)
        return;
    int temp = a;
    a = b;
    b = temp;
}

int min(int a, int b)
{
    if(a < b)
        return a;
    return b;
}

void quick_sort3(vector<long long> &list, int low, int high)
{
    if(low > high)
        return;
    int pivot_index = low + rand() % ((high + 1) - low);
    swap(list[high], list[pivot_index]);
    int i = low;
    int k = low;
    int pivot = high;

    while(i < pivot)
    {
        if(list[i] < list[pivot])
        {
            swap(list[i], list[k]);
            i++;
            k++;
        }
        else if(list[i] == list[pivot])
        {
            pivot--;
            swap(list[i], list[pivot]);
        }
        else
        {
            i++;
        }
    }
    int m = min(pivot - k, high - pivot + 1);
    
    for(int lc = 0; lc < m; lc++)
    {
        swap(list[k + lc], list[high - m + 1 + lc]);
    }
    quick_sort3(list, low, k - 1);
    quick_sort3(list, high - pivot + k + 1, high);
}

int main()
{

    int n = 0;
    //cout<<"Give n: ";
    cin>>n;
    
    vector<long long> list(n);

    //cout<<"Give unsorted elements: ";
    for(int i = 0; i < n; i++)
        cin>>list[i];


    quick_sort3(list, 0, n - 1);
    //cout<<"Sorted elements are :";
    for(int i = 0; i < n; i++)
        cout<<list[i]<<" ";
    cout<<"\n";
    return 0;
}
