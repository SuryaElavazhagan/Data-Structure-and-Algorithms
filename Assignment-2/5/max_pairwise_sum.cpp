#include<iostream>
#include<vector>

using namespace std;

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