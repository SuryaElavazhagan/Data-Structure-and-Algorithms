#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int n = 0;
    cout<<"Give n:";
    cin>>n;
    
    int fibbo[n];
    
    //Intialize basic values
    fibbo[0] = 0;
    fibbo[1] = 1;

    /*
        * F[n] = F[n - 1] + F[n - 2]
    */
    for(int i = 2; i <= n; i++)
    {
        fibbo[i] =fibbo[i - 1] + fibbo[i -2];
    }

    for(int i = 0; i <= n; i++)
    {
        cout<<fibbo[i]<<" ";
    }
    cout<<'\n';
    return 0;
}