#include<iostream>
#include<vector>

using namespace std;

/*
    * Pisano periods => F(n)%m =>> F[n + p] = F[n]
        => Where p is called 'periods'
    * Pisano periods are always even except for => F[2] = 3
    * Each series starts with 0 , 1
*/
long long pisano(long long n, long long m)
{
    vector<int> fibbo;

    fibbo.push_back(0);
    fibbo.push_back(1);

    long long periods = 0;
    long long i = 2;
    if(m == 2)
    {
        periods = 3;
    }
    else
    {
        while(true)
        {   
            fibbo.push_back((fibbo[i - 1] + fibbo[i - 2]) % m);
            i++;
            periods++;
            fibbo.push_back((fibbo[i - 1] + fibbo[i - 2]) % m);
            periods++;

            if(fibbo[i] == 1 && fibbo[i - 1] == 0)
                break;
            i++;
        }
    }
    return fibbo[n % periods];
    //return periods;
}

main()
{
    long long n = 0;
    long long m = 0;
    cin>>n>>m;

    cout<<pisano(n, m) <<'\n';
    
    return 0;
}

