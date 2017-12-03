#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector< vector<int> > get_groups(vector<int> values)
{
    int i = 0;
    vector< vector<int> > groups;
    int n = values.size();
    while(i < n)
    {
        int temp_start_index = -1;
        int temp_end_index = 0;

        temp_start_index++;
        groups[temp_start_index][temp_end_index] = values[i];
        // Here 1 is the grouping factor
        int temp = values[i] + 1;
        i++;
        while((i <= n) && (values[i] <= temp))
        {  
           groups[temp_start_index][temp_end_index] = values[i];
           i++; 
           temp_end_index++;
        }
    }
    return groups;
}

main()
{
    int n = 0;
    cin>>n;
    vector<int> values(n);

    int temp = 0;
    for(int i = 0; i < n; i++)
    {
        cin>>temp;
        values.push_back(temp);
    }

    sort(values.begin(), values.end());
    vector< vector < int > > groups = get_groups(values);

    for(int i = 0; i < groups.size(); i++)
    {
        for(int j = 0; j < groups[i].size(); j++)
            cout<<groups[i][j]<<' ';
        cout<<'\n';
    }
}