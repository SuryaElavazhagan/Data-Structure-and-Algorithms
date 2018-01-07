#include<iostream>
#include<vector>

using namespace std;

/*
    ****************DYNAMIC PROGRAMMING******************
    * This program computes discrete knapsack value with repetitions allowed
    * It stores optimized  discrete knapsack value for each weight 
    * from [1.....W] where W is the total_capacity of the given knapsack.
    * It is same as Coin change problem (Dynamic programming).
    * It takes O(n * W) time.
*/

struct item
{
    long long weight;
    long long value;
};

long long knapsack_repeted(vector<item> items, int total_weight, int total_items)
{
    vector<long long> values_of_weights(total_weight + 1);
    values_of_weights[0] = 0;
    long long current_value = 0;
    for(long long olc = 1; olc <= total_weight; olc++)
    {
        values_of_weights[olc] = 0;
        for(long long ilc = 0; ilc < total_items; ilc++)
        {
            if(items[ilc].weight <= olc)
            {
                current_value = values_of_weights[olc - items[ilc].weight] + items[ilc].value;
            }
            if(current_value > values_of_weights[olc])
            {
                values_of_weights[olc] = current_value;
            }
        }
    }
    return values_of_weights[total_weight];
}

int main()
{
    long long total_weight = 0;
    long long total_items = 0;

    cout<<"Give total weight capacity of knapsack:\n";
    cin>>total_weight;

    cout<<"\nGive total number of items :\n";
    cin>>total_items;

    vector<item> items(total_items);

    cout<<"Give element weight and its value: ";
    for(long long lc = 0; lc < total_items; lc++)
    {
        cin>>items[lc].weight>>items[lc].value;
    }

    cout<<"\nMaximum value stored by knapsack is :"<<knapsack_repeted(items, total_weight, total_items);
    cout<<endl;
    return 0;
}