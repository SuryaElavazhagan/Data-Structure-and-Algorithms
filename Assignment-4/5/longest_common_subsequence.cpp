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

long long common_subsequence(vector<long long> input_one, vector<long long> input_two, vector<long long> input_three,long long n1, long long n2, long long n3)
{
    vector< vector< vector<long long> > >   distance(n1 + 1, vector< vector<long long> >(n2 + 1, vector<long long>(n3 + 1, 0)));

    long long with_input_one_character = 0;
    long long with_input_two_character = 0;
    long long with_input_three_character = 0;

    for(int i = 1; i <= n1; i++)
    {
        for(int j = 1; j <= n2; j++)
        {
            for(int k = 1; k <= n3; k++)
            {
                with_input_one_character = distance[i - 1][j][k];
                with_input_two_character = distance[i][j - 1][k];
                with_input_three_character = distance[i][j][k - 1];

                if((input_one[i - 1] == input_two[j - 1]) && (input_one[i - 1] == input_three[k - 1]))
                {
                    distance[i][j][k] = distance[i - 1][j - 1][k - 1] + 1;
                }
                else
                {
                    distance[i][j][k] = max(with_input_one_character, with_input_two_character, with_input_three_character); 
                }
            }
        }
    }
    return distance[n1][n2][n3];
}

int main()
{
    long long n1 = 0, n2 = 0, n3 = 0;
    
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

    cin>>n3;
    vector<long long> input_three(n3);

    for(long long i = 0; i < n3; i++)
    {
        cin>>input_three[i];
    }

    cout<<common_subsequence(input_one, input_two, input_three, n1, n2, n3)<<endl;
    return 0;
}