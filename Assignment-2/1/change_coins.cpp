#include<iostream>
#include<vector>

/*
    ***************SAFE MOVE****************
    => Sort the coins in decending order
    ***************ALGORITHM****************
    => if amount % coins[i] == amount then
        > skip
    => else 
        > total_coins = amount / coins[i]
        > amount = amount % coins[i]
*/

using namespace std;

int get_minimum_coins(int amount)
{
    // Intialize coins in decending order
    vector<int> coins;
    coins.push_back(10);
    coins.push_back(5);
    coins.push_back(1);
    // total_coins store the result
    int total_coins = 0;
    // i is the index of coins vector
    int i = 0;
    while(amount != 0)
    {
        if(amount % coins[i] == amount)
        {
            i++;
            continue;
        }
        /*else if(amount % coins[i] == 0)
            return amount / coins[i];*/
        else
        {
            total_coins += amount / coins[i];
            amount = amount % coins[i];
            i++;
        }
    }
    return total_coins;
}

main()
{
    int amount = 0;

    // cout<<"Give the amount:";
    cin>>amount;

    //cout<<"Total number of coins needed:";
    cout<<get_minimum_coins(amount);
} 