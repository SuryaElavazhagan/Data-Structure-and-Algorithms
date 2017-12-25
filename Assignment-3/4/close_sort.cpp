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

long long merge(vector<long long> &list, int low, int high, int mid, long long left_inversion, long long right_inversion)
{
    /*
        * Actual logic goes here.
    */
    long long inversion = left_inversion + right_inversion;
    int left_index, right_index, temp_index;

    int left_size = mid - low + 1;
    int right_size = high - mid;

    vector<long long> left_half(left_size);
    vector<long long> right_half(right_size);

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
            {
                list[temp_index++] = left_half[left_index++];
            }
        else
        {
            /*
            **************** Important **********************
             * If the right half contains smaller element than the
             * left half then the right element is lesser than
             * all the elements from left_index
             * For eg.,
             *  left half = 2 5 6 8 9
             *  right half = 4 7 10 11
             * Consider '4' from right half
             * It is greater than 2 then left_index is incremented.
             * Now '4' is lesser than 5
             * It is lesser than 5,6,8,9
             * So it takes 4 Inversions.
            */
            inversion += (((long long)left_size) - left_index);
            list[temp_index++] = right_half[right_index++];
        }
    }

    // Copy the remaining to temp array
    while(left_index < left_size)
    {
        list[temp_index++] = left_half[left_index++];
        //inversion++;
    }
    
    while(right_index < right_size)
    {
        list[temp_index++] = right_half[right_index++];
    }
    return inversion;
}

long long merge_sort(vector<long long> &list, int low, int high)
{
    
    long long left_inversion = 0;
    long long right_inversion = 0;
    if(low < high)
    {
        int mid = (int)((low + high) / 2);
        
        // Left half
        left_inversion = merge_sort(list, low, mid);
        
        // Right half
        right_inversion = merge_sort(list, mid + 1, high);
        
        // Merging both the halves
        return merge(list, low, high, mid, left_inversion, right_inversion);
    }
    return 0;
}



int main()
{
    long long n = 0;

    //cout<<"Give n:";
    cin>>n;
    vector<long long> list(n);

    //cout<<"Give n elements:";
    for(int i = 0; i < n; i++)
        cin>>list[i];
    
    if(n <= 2)
        cout<<"0\n";
    else
    cout<<merge_sort(list, 0, n - 1)<<"\n";

    //cout<<"\n";
    return 0;
}