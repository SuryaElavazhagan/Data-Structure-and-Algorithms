#include<iostream>
#include<vector>

using namespace std;

int knapsack(int total_weight, vector<int> &souvenirs)
{
    vector<int> used_souvenirs;
    int size = souvenirs.size();
    vector< vector<int> > values(total_weight + 1, vector<int>(size + 1));
    int temp_value = 0;
    
    for(int i = 0; i <= size; i++)
    {
        max_values[0][i] = 0;
    }
    for(int i = 0; i <= total_weight; i++)
    {
        max_values[i][0] = 0;
    }

    for(int i = 1; i <= size; i++)
    {
        for(int j = 1; j <= total_weight; j++)
        {
            values[j][i] = values[j][i - 1];

            if(souvenirs[i - 1] <= total_weight)
            {
                temp_value = values[j - souvenirs[i - 1]][i - 1] + souvenirs[i - 1];
            }
            if(temp_value > values[j][i])
            {
                values[j][i] = temp_value;
            }
            temp_value = 0;
        }
    }
    return values[total_weight][size] == total_weight;
}   

int main()
{
    int no_of_souvenirs = 0;
    int sum = 0;

    cin>>no_of_souvenirs;
    vector<int> souvenirs(no_of_souvenirs);

    for(int i = 0; i < no_of_souvenirs; i++)
        sum += souvenirs[i];

    if(sum % 3 != 0)
    {
        cout<<"0"<<endl;
    }
    else
    {

    }
}