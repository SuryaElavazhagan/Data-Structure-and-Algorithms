#include<iostream>
#include<vector>

using namespace std;

void merge(vector<int> &list, int low, int high, int mid)
{
    int left_index, right_index, temp_index;

    int left_size = mid - low + 1;
    int right_size = high - mid;

    vector<int> left_half(left_size);
    vector<int> right_half(right_size);

    for(int i =0; i < left_size; i++)
        left_half[i] = list[low + i];
    
    for(int i =0; i < right_size; i++)
        right_half[i] = list[mid + 1 + i];
    
    left_index = 0;
    right_index = 0;
    temp_index = low;
    while(left_index < left_size && right_index < right_size)
    {
        if(left_half[left_index] <= right_half[right_index])
            list[temp_index++] = left_half[left_index++];
        else
            list[temp_index++] = right_half[right_index++];
    }

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
        merge_sort(list, low, mid);
        merge_sort(list, mid + 1, high);
        merge(list, low, high, mid);
    }
}

int main()
{
    int n = 0;
    cin>>n;
    vector<int> list(n);

    for(int i = 0; i < n; i++)
        cin>>list[i];
    
    merge_sort(list, 0, n - 1);

    for(int i = 0; i < n; i++)
        cout<<list[i]<<" ";
    cout<<"\n";
    return 0;
}