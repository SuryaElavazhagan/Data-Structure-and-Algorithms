#include<iostream>
#include<vector>
#include<limits>

using namespace std;

#define MAX numeric_limits<int>::max();

int coins[] = {1, 3, 4};

int get_change(int money)
{
    vector<int> minimum_no_coins(money + 1);
    int num_of_coins = MAX;
    minimum_no_coins[0] = 0;

    for(int i = 1; i <= money; i++)
    {
        minimum_no_coins[i] = MAX;
        for(int j = 0; j < 3; j++)
        {
            if(i >= coins[j])
            {
                num_of_coins = minimum_no_coins[i - coins[j]] + 1;
            }
            if(num_of_coins < minimum_no_coins[i])
            {
                minimum_no_coins[i] = num_of_coins;
            }
        }
        num_of_coins = 0;
    }
    return minimum_no_coins[money];
}

int main()
{
    int money = 0;

    cin>>money;

    cout<<get_change(money)<<endl;
    return 0;
}