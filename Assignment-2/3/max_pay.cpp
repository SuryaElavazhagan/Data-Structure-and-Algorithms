#include<iostream>
#include<vector>
#include<algorithm>

/*
    ***************SAFE MOVE****************
    => Sort given arrays
    ***************ALGORITHM****************
    => Multiply elements from each array
        corresponding to their positions
        and add them to final result
    => Return result
*/

using namespace std;

main()
{
    long final_sum = 0;
    int no_of_ads = 0;
    //cout<<"Give no. of ads:";
    cin>>no_of_ads;

    vector<long> profit_per_click(no_of_ads);
    vector<long> avg_click_in_slot(no_of_ads);

    //cout<<"Give profit per click on i-th ad";
    for(int i = 0; i < no_of_ads; i++)
    {
        cin>>profit_per_click[i];
    }

    //cout<<"Give average click per day in i-th slot:";
    for(int i = 0; i < no_of_ads; i++)
    {
        cin>>avg_click_in_slot[i];
    }

    sort(profit_per_click.begin(), profit_per_click.end());
    sort(avg_click_in_slot.begin(), avg_click_in_slot.end());

    //cout<<"Maximum revenue will be:";
    for(int i = 0; i < no_of_ads; i++)
    {
        final_sum += profit_per_click[i] * avg_click_in_slot[i];
    }
    cout<<final_sum<<'\n';
}  