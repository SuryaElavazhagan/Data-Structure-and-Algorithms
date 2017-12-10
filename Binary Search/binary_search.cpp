#include<iostream>
#include<vector>

using namespace std;

/*
    ************DIVIDE AND CONQUER***************
    => Get sorted elements as input
    => Compute mid element index and compare it with search key.
    => If the key is greater than mid element then search in right side
    => else search on right side
    => If the key is not found index at which it can be inserted is returned. 
*/

int bin_search(vector<int> array, int low, int high, int key)
{
    if(high < low)
        return low - 1;

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

main()
{
    int n = 0, search_key = 0;

    //cout<<"Give n:";
    cin>>n;

    vector<int> array(n);

    //cout<<"Give sorted elements:";
    for(int i = 0; i < n; i++)
        cin>>array[i];

    //cout<<"Give search key:";
    cin>>search_key;

    //cout<<"Element is found (or) can be inserted at :";
    cout<<bin_search(array, 0 , n - 1, search_key);
    return 0;
}