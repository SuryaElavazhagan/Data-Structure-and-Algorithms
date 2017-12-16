#include<iostream>
#include<vector>

#define NOT_FOUND -1;

using namespace std;

int bin_search(vector<long long> array, int low, int high, long long key)
{
    // If not found return -1.
    if(high < low)
        return NOT_FOUND;

    /*
        (low + high) / 2 => may be float
        > It is type casted to integer
    */
    int mid = (int)((low + high) / 2);
    
    /*
        * If the element is present, finally the element will be in the mid
    */
    if(array[mid] == key)
        return mid;
    // Search on right side
    else if(array[mid] < key)
    {
        return bin_search(array, mid + 1, high, key);
    }
    // Search on left side
    else
    {
        return bin_search(array, low, mid - 1, key);
    }
}

void binary_search(vector<long long> list, vector<long long> search_keys, int n, int k)
{
    //vector<int> result_indices(k);

    // temp_index is the index for search keys.
    int temp_index = 0;
    
    while(temp_index < k)
        {
            /*
                For each elements in search_keys perform binary search.
            */
            cout<<bin_search(list, 0, n - 1,search_keys[temp_index])<<" ";
            //result_indices[temp_index] = bin_search(list, 0, n - 1,search_keys[temp_index]);
            temp_index++;
        }

    //return result_indices;
}

int main()
{
    int n = 0;
    int k = 0;

    //cout<<"Give n:";
    cin>>n;

    //cout<<"Give n elements:";
    vector<long long> list(n);
    for(int i = 0; i < n; i++)
        cin>>list[i];
    
    //cout<<"Give k elements:";
    cin>>k;

    //cout<<"Give k search elements:";
    vector<long long> search_keys(k);
    for(int i = 0; i < k; i++)
        cin>>search_keys[i];
    
    //cout<<"Output:";
    binary_search(list, search_keys, n, k);
    
    /*
    vector<int> result_indices = binary_search(list, search_keys, n, k);

    for(int i = 0; i < k; i++)
        cout<<result_indices[i]<<" ";
    */

    cout<<"\n"; 
}