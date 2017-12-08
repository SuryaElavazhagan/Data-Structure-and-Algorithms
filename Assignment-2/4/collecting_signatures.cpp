#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/*
    ***************SAFE MOVE****************
    => Sort given segments based on right end
    ***************ALGORITHM****************
    => Check whether right end is to the right of
        next segment left end i.e.,
        > b[i] >= a[i + 1]
    => if not increment the count and add b[i + 1] 
        to the result
*/

struct my_coordinates
{
    long a;
    long b;
    my_coordinates(long a, long b) : a(a), b(b) {}
};

struct my_sort
{
    inline bool operator() (const my_coordinates& coordinate_1 , const my_coordinates& coordinate_2)
    {
        return coordinate_1.b < coordinate_2.b;
    }
};

void get_min_segment(vector<my_coordinates> cord)
{   
    vector<long> result;
    int count = 0;
    int n = cord.size();
    int index_one = 0;
    int index_two = 1;

    result.push_back(cord[index_one].b);
    count++;
    while(index_two < n)
    {
        if(result[index_one] >= cord[index_two].a)
        {
            index_two++;
        }
        else
        {
            result.push_back(cord[index_two].b);
            count++;
            index_one++;
            index_two++;
        }
    }
    cout<<count<<'\n';
    for(int i = 0; i < result.size(); i++)
        cout<<result[i]<<' ';
}

int main()
{
    int n = 0;
    //cout<<"Give n:";
    cin>>n;
    vector<my_coordinates> cord;
    long temp_start = 0;
    long temp_end = 0;

    //cout<<"Give end points of segemts:";
    for(int i = 0; i < n; i++)
    {
        cin>>temp_start>>temp_end;
        cord.push_back(my_coordinates(temp_start, temp_end));
    }
    
    // Sorting based on right end
    sort(cord.begin(), cord.end(), my_sort());

    //cout<<"The result is:";
    get_min_segment(cord);
    return 0;
}