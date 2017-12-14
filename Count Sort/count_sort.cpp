#include<iostream>
#include<vector>

using namespace std;

/*
    * This sorting is done when the array is filled with a range of numbers
*/

void count_sort(vector<int> &list, int no_of_elements, int max_number)
{
    /*
        * Actual logic goes here
    */
    vector<int> count(max_number + 1);
    fill(count.begin(), count.end(), 0);
    
    // Counts each elements
    for(int i = 0; i < no_of_elements; i++)
        count[list[i]] += 1;
    
    // Stores the position of each elements based on its count
    vector<int> position(max_number + 1);
    fill(position.begin(), position.end(), 0);
    position[0] = 0;
    for(int i = 1; i < max_number + 1; i++)
        position[i] = position[i - 1] + count[i - 1];
    
    vector<int> list_sorted(no_of_elements);
    // Elements are inserted here
    for(int i = 0; i < no_of_elements; i++)
    {
        list_sorted[position[list[i]]] = list[i];
        position[list[i]]++; 
    }
    list = list_sorted;
}

int main()
{
    int no_of_elements = 0;
    int max_number = 0;
    
    //cout<<"Give n and max range:";
    cin>>no_of_elements>>max_number;

    //cout<<"Give array of n numbers:";
    vector<int> list(no_of_elements);
    for(int i = 0; i < no_of_elements; i++)
    {
        cin>>list[i];
    }

    count_sort(list, no_of_elements, max_number);
    
    //cout<<"Sorted list :";
    for(int i = 0; i < no_of_elements; i++)
        cout<<list[i]<<" ";
    cout<<"\n";
    return 0;
}