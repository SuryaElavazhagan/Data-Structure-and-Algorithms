#include<iostream>

using namespace std;

main()
{
    int n = 0;
    cin>>n;
    
    int previous = 0;
    int current = 1;

    for(int i = 2; i <= n; i++)
    {
        int temp_previous = previous;
        previous = current;
        current = (previous + temp_previous)%10;
    }

    cout<<current;
}