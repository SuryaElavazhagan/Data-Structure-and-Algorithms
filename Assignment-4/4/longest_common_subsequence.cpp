#include<iostream>
#include<vector>

using namespace std;

long long max(long long a, long long b, long long c)
{
    if(a >= b && a >= c)
        return a;
    else if(b >= c && b >= a)
        return b;
    else
        return c;
}

long long common_subsequence(vector<long long> input_one, vector<long long> input_two, long long n1, long long n2)
{
    vector< vector<long long> > distance(n1 + 1, vector<long long>(n2 + 1));
    long long with_current_character = 0;
    long long without_current_character = 0;
    long long matching = 0;
    
    for(long long i = 0; i <= n1; i++)
    {
        distance[i][0] = 0;
    }

    for(long long i = 0; i <= n2; i++)
    {
        distance[0][i] = 0;
    }

    for(long long i = 1; i <= n1; i++)
    {
        for(long long j = 1; j <= n2; j++)
        {
            with_current_character = distance[i][j - 1];
            without_current_character = distance[i - 1][j];
            matching = distance[i - 1][j - 1];

            if(input_one[i - 1] == input_two[j - 1])
            {
                distance[i][j] = max(with_current_character, without_current_character, matching + 1);
            }
            else
            {
                distance[i][j] = max(with_current_character, without_current_character, matching);
            }
        }
    }

    /*for(int i = 0; i <= n1; i++)
    {
        for(int j = 0; j <= n2; j++)
        {
            cout<<distance[i][j]<<" ";
        }
        cout<<endl;
    }*/
    
    return distance[n1][n2];
}

int main()
{
    long long n1 = 0, n2 = 0;
    
    cin>>n1;
    vector<long long> input_one(n1); 
    
    for(long long i = 0; i < n1; i++)
    {
        cin>>input_one[i];
    }
    
    cin>>n2;
    vector<long long> input_two(n2);

    for(long long i = 0; i < n2; i++)
    {
        cin>>input_two[i];
    }

    cout<<common_subsequence(input_one, input_two, n1, n2)<<endl;
    return 0;
}