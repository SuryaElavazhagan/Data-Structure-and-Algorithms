#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

int min(int a, int b, int c)
{
    if((a <= b) && (a <= c))
        return a;
    else if((b <= c) && (b <= a))
        return b;
    else
        return c;
}

int edit_distance(string input_one, string input_two)
{
    int length_one = input_one.size();
    int length_two = input_two.size();

    int insertion = 0;
    int deletion = 0;
    int matching = 0;

    vector< vector<int> > distance(length_one + 1, vector<int>(length_two + 1, 0));
    
    for(int i = 0; i <= length_one; i++)
    {
        distance[i][0] = i;
    }

    for(int i = 0; i <= length_two; i++)
    {
        distance[0][i] = i;
    }

    for(int j = 1; j <= length_two; j++)
    {
        for(int i = 1; i <= length_one; i++)
        {
            insertion = distance[i][j - 1] + 1;
            deletion = distance[i - 1][j] + 1;
            matching = distance[i - 1][j - 1];

            if(input_one[i - 1] == input_two[j - 1])
            {
                distance[i][j] = min(insertion, deletion, matching);
            }
            else{
                distance[i][j] = min(insertion, deletion, matching + 1);
            }
        }
    }

    /*for(int i = 0; i <= length_one; i++)
    {
        for(int j = 0; j <= length_two; j++)
        {
            cout<<distance[i][j]<<" ";
        }
        cout<<endl;
    }*/

    return distance[length_one][length_two];
}

int main()
{
    string input_one;
    string input_two;

    cin>>input_one>>input_two;

    cout<<edit_distance(input_one, input_two)<<endl;
    return 0;
}