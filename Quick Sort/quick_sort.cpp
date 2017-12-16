#include<iostream>
#include<vector>

using namespace std;

void swap(int &a, int &b)
{
    /*
        Swaps two elements
    */
    int temp = a;
    a = b;
    b = temp;
}

int partition(vector<int> &list, int low, int high)
{
    /*
        Actual logic goes here.
    */
    int pivot = list[low];
    int index = low;

    for(int i = low + 1; i <= high; i++)
    {
        if(list[i] <= pivot)
        {
            /*
                Occurs when a larger element is on the
                left side of sorted pivot position.    
            */
            index++;
            swap(list[i], list[index]);
        }
    }

    // The pivot element is at the sorted position 
    swap(list[low], list[index]);

    // returns the pivot index
    return index;
}

void quick_sort(vector<int> &list, int low, int high)
{
    if(low > high)
        return;
    
    int pivot_index = partition(list, low, high);
    
    // Divide array by 2 with respect to pivot element

    // Left partition
    quick_sort(list, low, pivot_index - 1);
    
    // Right partition
    quick_sort(list, pivot_index + 1, high);
}

int main()
{
    int n = 0;
    cin>>n;

    vector<int> list(n);

    for(int i = 0; i < n; i++)
        cin>>list[i];

    quick_sort(list, 0, n - 1);

    for(int i = 0; i < n; i++)
        cout<<list[i]<<" ";
    
    cout<<"\n";
}