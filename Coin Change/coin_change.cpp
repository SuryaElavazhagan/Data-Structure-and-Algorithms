#include<iostream>
#include<vector>
#include<limits>

using namespace std;

#define MAX numeric_limits<int>::max()

/*
    **************DYNAMIC PROGRAMMING****************
    * In greedy algorithm, The program fails for some test cases like,
    For e.g., coins -> 1 , 8 , 20
              amount -> 24
              Then the greedy algorithm gives => 20 + 1 + 1 + 1 + 1
    * To overcome this, the change for each and every amount is stored 
    * and used whenever needed.
*/

int get_change(int money, vector<int> coins)
{
    int num_of_coins = 0;
    vector<int> change(money + 1);
    change[0] = 0;

    for(int i = 1; i <= money; i++)
    {
        change[i] = MAX;
        //num_of_coins = 0;
        for(int j = 0; j < coins.size(); j++)
        {
            if(i >= coins[j])
            {
                num_of_coins = change[i - coins[j]] + 1;
            }
            if(num_of_coins < change[i])
            {
                change[i] = num_of_coins;
            }
        }
    }
    return change[money];
}

int main()
{
    int no_of_coins = 0;
    int money = 0;
    int minimum_no_of_coins = 0;

    cout<<"Give number of coins :";
    cin>>no_of_coins;

    vector<int> coins(no_of_coins);
    cout<<"\nGive the coins :"<<endl;

    for(int i = 0; i < no_of_coins; i++)
    {
        cin>>coins[i];
    }

    cout<<"\nGive the amount of money :"<<endl;
    cin>>money;

    minimum_no_of_coins = get_change(money, coins);

    cout<<"\nThe minimum of coins :"<<minimum_no_of_coins<<endl;

    return 0;
}