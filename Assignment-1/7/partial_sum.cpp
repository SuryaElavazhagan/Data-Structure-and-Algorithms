#include<iostream>
#include<vector>

using namespace std;

/*
    * Sum of n Fibonacci numbers is F[n + 2] - 1
    * Sum of m to n Fibonacci numbers is
        => (F[n + 2] - 1) - (F[m + 2] - 1)
                ||                ||        
            (nth Fibonacci)  (mth Fibonacci)
        => F[n + 2] - F[m + 2]
*/
vector<int> fib;

void load()
{
    fib.push_back(0);
    fib.push_back(1);

    for(int i = 2; i <= 60; i++)
    {
        int temp = (fib[i - 1] + fib[i - 2])%10;
        if(temp == 0)
            temp = 10;
        fib.push_back(temp);
    }
}

int getSum(long long m, long long n)
{
    if(n <= 1)
        return n;
    load();

    int temp1 = fib[(m + 2) % 60];
    int temp2 = fib[(n + 2) % 60];
    
    if(temp2 < temp1)
        temp2 = temp2 + 10;
    return (temp2 - temp1);
}

main()
{
    long long n = 0;
    long long m = 0;
    cin>>m;
    cin>>n;
    cout<<getSum(m - 1, n)<<'\n';
}