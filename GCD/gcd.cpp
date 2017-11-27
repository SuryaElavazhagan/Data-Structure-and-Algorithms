#include<iostream>

using namespace std;

int gcd(int a, int b)
{
    if(b == 0)
        return a;
    else
    {
        a = a % b;
        return gcd(b , a); 
    }
}

int main()
{
    int a = 0;
    int b = 0;

    cout<<"Give a:";
    cin>>a;
    cout<<"Give b:";
    cin>>b;

    cout<<"GCD("<<a<<" , "<<b<<") :"<<gcd(a, b);
    return 0;
}