#include<iostream>

using namespace std;

long long gcd(long long a, long long b)
{
    if(b == 0)
        return a;
    else
    {
        a = a % b;
        return gcd(b , a);
    }
}

main()
{
    long long a = 0;
    long long b = 0;

    cin>>a;
    cin>>b;

    cout<< ((a * b) / gcd(a , b));
}