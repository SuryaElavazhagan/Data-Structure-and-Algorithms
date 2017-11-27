#include<iostream>

using namespace std;

main()
{
    int n = 0;
    cin>>n;
    int fibbo[n + 1];
    fibbo[0] = 0;
    fibbo[1] = 1;

    for(int i = 2; i <= n; i++)
        fibbo[i] = fibbo[i - 1] + fibbo[i - 2];
    
    cout<<fibbo[n];
    return 0;
}