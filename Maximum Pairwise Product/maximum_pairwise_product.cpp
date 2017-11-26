#include<iostream>
#include<vector>
#include<cstdlib>

using namespace std;

/*
    * int is 4 bytes in g++ -pipe -O2 -std=c++11
    * long is 4 bytes in g++ -pipe -O2 -std=c++11
    => so it makes long long = 4 + 4  = 8 bytes
    => 8 * 8 = 64 bits
    => 2^64 = -9,223,372,036,854,775,807 to 9,223,372,036,854,775,807
*/

/*
void stress_testing()
{
    while(true) {
    int n = rand() % 10 + 2;
    cerr << n << "\n";
    vector<int> a;
    for (int i = 0; i < n; ++i) {
        a.push_back(rand() % 100000);
    }
    for (int i = 0; i < n; ++i) {
        cerr << a[i] << ' ';
    }
    cerr << "\n";
    long long res1 = max_pairwise_product(a);
    long long res2 = max_pairwise_product_fast(a);
    if (res1 != res2) {
        cerr << "Wrong answer: " << res1 << ' ' << res2 << "\n";
        break;
    }
    else {
        cerr << "OK\n";
    }
    }
}

long long max_pairwise_product(const vector<int>& a)
{
    int n = a.size();
    long long product = 0;
    for(int i = 0; i < n ; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(product < ((long long)a[i]) * a[j])
            {
                product = ((long long)a[i]) * a[j];
            }
        }
    }
    return product; 
}
*/

long long max_pairwise_product_fast(const vector<int>& a)
{
    int n = a.size();
    int max_index_1 = -1;
    int max_index_2 = -1;
    for(int i = 0; i < n; i++)
    {
        if(max_index_1 == -1 || (a[i] > a[max_index_1]))
            max_index_1 = i;
    }

    for(int i = 0; i < n; i++)
    {
        if((max_index_2 == -1 || (a[i] > a[max_index_2])) && i != max_index_1)
            max_index_2 = i;
    }

    return ((long long)a[max_index_1]) * a[max_index_2];
}

int main()
{
    int n = 0;
    cin>>n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i)
    {
        cin>>a[i];
    }
     cout<<max_pairwise_product_fast(a);
    return 0;
}
