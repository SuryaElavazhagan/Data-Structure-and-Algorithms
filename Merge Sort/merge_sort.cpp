#include<iostream>
#include<vector>

using namespace std;

/*
    *************DIVIDE AND CONQUER**************
    * Divide array into 2
    * Merge the 2 array
    ******************MERGING********************
    * Compare each elements from two half of the array
      from left to right and insert the least to a temp array
    * At last any of the two half will be empty
    * Put all the elements from the non-empty array to temp array
    * Return temp.
*/

void merge(vector<int> &list, int low, int high, int mid)
{
    /*
        * Actual logic goes here.
    */
    int left_index, right_index, temp_index;

    int left_size = mid - low + 1;
    int right_size = high - mid;

    vector<int> left_half(left_size);
    vector<int> right_half(right_size);

    // Inserting left half to left temporary array
    for(int i =0; i < left_size; i++)
        left_half[i] = list[low + i];

    // Inserting right half to right temporary array
    for(int i =0; i < right_size; i++)
        right_half[i] = list[mid + 1 + i];
    
    left_index = 0;
    right_index = 0;
    temp_index = low;

    // Compare and store them to temp array
    while(left_index < left_size && right_index < right_size)
    {
        if(left_half[left_index] <= right_half[right_index])
            list[temp_index++] = left_half[left_index++];
        else
            list[temp_index++] = right_half[right_index++];
    }

    // Copy the remaining to temp array
    while(left_index < left_size)
        list[temp_index++] = left_half[left_index++];
    
    while(right_index < right_size)
        list[temp_index++] = right_half[right_index++];
}

void merge_sort(vector<int> &list, int low, int high)
{
    if(low < high)
    {
        int mid = (int)((low + high) / 2);
        
        // Left half
        merge_sort(list, low, mid);
        
        // Right half
        merge_sort(list, mid + 1, high);
        
        // Merging both the halves
        merge(list, low, high, mid);
    }
}

int main()
{
    int n = 0;

    //cout<<"Give n:";
    cin>>n;
    vector<int> list(n);

    //cout<<"Give n elements:";
    for(int i = 0; i < n; i++)
        cin>>list[i];
    
    merge_sort(list, 0, n - 1);

    //cout<<"Sorted array:";
    for(int i = 0; i < n; i++)
        cout<<list[i]<<" ";
    cout<<"\n";
    return 0;
}