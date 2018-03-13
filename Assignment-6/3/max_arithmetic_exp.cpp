#include<iostream>
#include<vector>
#include<string>
#include<limits>

using namespace std;

#define MIN numeric_limits<int>::max()
#define MAX numeric_limits<int>::min()

int min(int a, int b, int c, int d, int e)
{
    if(a <= b && a <= c && a <= d && a <= e)
        return a;
    else if(b <= a && b <= c && b <= d && b <= e)
        return b;
    else if(c <= a && c <= b && c <= d && c <= e)
        return c;
    else   
        return d;
}

int max(int a, int b, int c, int d, int e)
{
    if(a >= b && a >= c && a >= d && a >= e)
        return a;
    else if(b >= a && b >= c && b >= d && b >= e)
        return b;
    else if(c >= a && c >= b && c >= d && c >= e)
        return c;
    else   
        return d;
}


int main()
{
    string arithmetic_expression;
    cin>>arithmetic_expression;
    int size = arithmetic_expression.size();
    int temp = 0;

    vector<int> numbers;
    vector<char> operators;
    for(int i = 0; i < size; i++)
    {
        if(i % 2 == 0)
            numbers.push_back(arithmetic_expression[i] - '0');
        else   
            operators.push_back(arithmetic_expression[i]);
    }

    vector< vector<int> > min(size, vector<int>(size));
    vector< vector<int> > max(size, vector<int>(size));

    for(int i = 0; i < size; i++, temp++)
    {
        max[i][i] = min[i][i] = arithmetic_expression[temp++];
    }
    temp = 0;
    for(int i = 1; i < size; i++)
    {
        for(int j = 1; j < (size - i); j++)
        {
            temp = j + i;
            for(int k = j; k < temp; k++)
            {
                int a = perform_operation(max[j][k], max[j][temp], arithmetic_expression[k]);
            }
        }
    }  
    return 0;
}