#include<iostream>

using namespace std;

/*
    * Here last digit of nth fibonacci number is calculated  
    * Each time only the last digit of the fibonacci is calculated
*/
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