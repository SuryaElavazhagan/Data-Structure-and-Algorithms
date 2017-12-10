#include<iostream>
#include<vector>

using namespace std;

/*
    ***************SAFE MOVE****************
    => Always start with 1 and increment till
     k < 2l
      > i.e., For eg., Input : 8
      > Start with => 1     Remaining : 7    > Condition(7 > (2 * 1)) => TRUE   
            > Add 1 to result
      > Increment  => 2     Remaining : 6    > Condition(6 > (2 * 2)) => TRUE
            > Add 2 to result
      > Increment  => 3     Remaining : 5    > Condition(5 > (2 * 3)) => FALSE
            > Add 5 to result
    => Stop
*/

void get_max_pairwise_sum(long n)
{
    vector<long> pairs;
    pairs.push_back(1);
    long temp = 2;
    n = n - 1;

    while(n != 0)
    {
        if(n > (2 * temp))
        {
            pairs.push_back(temp);
            n = n - temp;
            temp++;
        }
        else
        {
            pairs.push_back(n);
            break;
        }
    }
    temp = pairs.size();
    cout<<temp<<'\n';
    for(int i = 0; i < temp; i++)
        cout<<pairs[i]<<' ';
}

main()
{
    long n = 0;

    //cout<<"Give n:";
    cin>>n;

    if(n <= 2)
    {
        cout<<'1'<<'\n'<<n;
    }
    else
    {
        get_max_pairwise_sum(n);    
    }
}