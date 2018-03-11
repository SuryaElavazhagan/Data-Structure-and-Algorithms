#include<iostream>
#include<vector>

using namespace std;

long long min(long long a, long long b)
{
   if(a < b)
      return a;
   return b;
}

int main()
{
    long long n = 0;
    long long temp = 0;
    cin>>n;
    temp = n;
    vector<long long> sequence;
    
    vector<long long> count(n + 1);
    count[0] = 0;
    count[1] = 0;
    
    for(long long i = 2; i <= n; i++)
    {
        if(i < 4)
            count[i] = 1;
        else
        {
            if((i % 3 != 0) && (i % 2 != 0))
            {
               count[i] = count[i - 1] + 1;
            }
            else if((i % 3 != 0) && (i % 2 == 0))
            {
               count[i] = min(count[i / 2] + 1, count[i - 1] + 1);
            }
            else if((i % 3 == 0) && (i % 2 != 0))
            {
               count[i] = min(count[i / 3] + 1, count[i - 1] + 1);
            }
            else
            {
               count[i] = min(count[i / 3] + 1,count[i / 2] + 1);
            }
        }
    }
    
    while(n > 1)
    {
        sequence.push_back(n);
       if(n % 3 != 0 && n % 2 != 0)
        {
           n--;
        }
        else if(n % 3 != 0 && n % 2 == 0)
        {
           if(count[n / 2] < count[n - 1])
            {
               n = n / 2;
            }
           else
            {
               n--;
            }
        }
        else if(n % 2 != 0 && n % 3 == 0)
        {
           if(count[n / 3] < count[n - 1])
            {
               n = n / 3;
            }
           else
            {
               n--;
            }
        }
        else if(n % 3 == 0 && n % 2 == 0)
        {
            if(count[n / 3] < count[n / 2])
            {
               if(count[n / 3] < count[n -1])
                {
                    n = n / 3;
                }
                else
                {
                    n--;
                }
            }
            else
            {
               if(count[n / 2] < count[n - 1])
                {
                   n = n / 2;
                }
                else
                {
                   n--;
                }
            }
        }
    }
    
    sequence.push_back(1);
    
    cout<<count[temp]<<endl;
    
    for(long long i = sequence.size() - 1; i >= 0; --i)
    {
       cout<<sequence[i]<<" ";
    }
    cout<<endl;
    return 0;
}