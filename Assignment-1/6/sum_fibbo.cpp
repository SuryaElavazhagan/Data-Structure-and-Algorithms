#include<iostream>
#include<vector>

using namespace std;

vector<int> fib;

void load()
{
    fib.push_back(0);
    fib.push_back(1);

    for(int i = 2; i <=60; i++)
    {
        int temp = (fib[i - 1] + fib[i - 2])%10;
        if(temp != 0)
            fib.push_back(temp);
        else
            fib.push_back(10);
    }
}

int getSum(long long n)
{
    if(n <= 1)
        return n;
    load();
    return fib[(n + 2) % 60] - 1;
}


main()
{
    long long n = 0;
    cin>>n;
    cout<<getSum(n)<<'\n';
}