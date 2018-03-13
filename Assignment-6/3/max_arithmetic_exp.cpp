#include<iostream>
#include<vector>
#include<string>
#include<limits>

using namespace std;

#define MIN numeric_limits<int>::max()
#define MAX numeric_limits<int>::min()

int mini(int a, int b, int c, int d, int e)
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

int maxi(int a, int b, int c, int d, int e)
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


int perform_operation(int a, int b, char op)
{
    switch(op)
    {
        case '+' : return a + b;
        case '-' : return a - b;
        case '*' : return a * b;
    }
}

int main()
{
    string arithmetic_expression;
    cin>>arithmetic_expression;
    int size = arithmetic_expression.size();
    int temp = 0;
    int min_val = MIN;
    int max_val = MAX;

    vector<int> numbers;
    vector<char> operators;
    for(int i = 0; i < size; i++)
    {
        if(i % 2 == 0)
            numbers.push_back(arithmetic_expression[i] - '0');
        else   
            operators.push_back(arithmetic_expression[i]);
    }

    size = numbers.size();

    vector< vector<int> > min(size, vector<int>(size));
    vector< vector<int> > max(size, vector<int>(size));

    for(int i = 0; i < size; i++)
    {
        max[i][i] = min[i][i] = numbers[i];
    }
    temp = 0;
    for(int i = 1; i < size; i++)
    {
        for(int j = 0; j < (size - i); j++)
        {
            temp = j + i;
            min_val = MIN;
            max_val = MAX;
            for(int k = j; k < temp; k++)
            {
                int a = perform_operation(max[j][k], max[k + 1][temp], operators[k]);
                int b = perform_operation(max[j][k], min[k + 1][temp], operators[k]);
                int c = perform_operation(min[j][k], min[k + 1][temp], operators[k]);
                int d = perform_operation(min[j][k], max[k + 1][temp], operators[k]);

                min_val = mini(min_val, a, b, c, d);
                max_val = maxi(max_val, a, b, c, d);

                //cout<<"Pos "<<"["<<j<<"]["<<temp<<"] : "<<"Min : "<<min_val<<" Max_val : "<<max_val<<endl;
            }

            min[j][temp] = min_val;
            max[j][temp] = max_val;
        }
    }

    /*cout<<"Minimum : "<<endl;
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
            cout<<min[i][j]<<" ";
        cout<<endl;
    }
    cout<<"Maximum : "<<endl;
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
            cout<<max[i][j]<<" ";
        cout<<endl;
    }*/

    cout<<max[0][size - 1]<<endl;  
    return 0;
}