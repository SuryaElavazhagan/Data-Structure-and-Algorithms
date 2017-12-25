#include<iostream>
#include<string>
#include<vector>

using namespace std;

void checkBalance(string input)
{
    long long length = (long long)input.size();
    vector<char> brackets_stack;
    long long stack_top = -1;
    vector<long long> track_index;
    int flag = 0;
    long long lc;
    for(lc = 0; lc < length; lc++)
    {
        //cout<<"loop counter :"<<lc<<"\n";
        switch(input[lc])
        {
            case '{':
            case '[':
            case '(':
                stack_top++;
                track_index.push_back(lc);
                brackets_stack.push_back(input[lc]);
                //cout<<"input :"<<input[lc]<<" track_index: "<<lc<<"\n";
                break;
            case '}':
                if(stack_top == -1)
                {
                    flag = 1;
                    //cout<<"Issue found:{ lc = "<<lc<<"input[lc]"<<input[lc]<<"\n";
                    goto issue;
                }
                else if(brackets_stack[stack_top] != '{')
                {
                    flag = 1;
                    //cout<<"Issue found:{ lc = "<<lc<<"input[lc]"<<input[lc]<<"\n";
                    goto issue;
                }
                else
                {
                    brackets_stack.pop_back();
                    track_index.pop_back();
                    stack_top--;
                    //cout<<"Popping : "<<input[lc]<<"\n";
                }
                break;
            case ']':
                if(stack_top == -1)
                {
                    flag = 1;
                    //cout<<"Issue found:{ lc = "<<lc<<"input[lc]"<<input[lc]<<"\n";
                    goto issue;
                }
                else if((brackets_stack[stack_top] != '[') || (brackets_stack.empty()))
                {
                    flag = 1;
                    //cout<<"Issue found:[ lc = "<<lc<<"input[lc]"<<input[lc]<<"\n";
                    goto issue;
                }
                else
                {
                    brackets_stack.pop_back();
                    track_index.pop_back();
                    stack_top--;
                    //cout<<"Popping : "<<input[lc]<<"\n";
                }
                break;
            case ')':
                if(stack_top == -1)
                {
                    flag = 1;
                    //cout<<"Issue found:{ lc = "<<lc<<"input[lc]"<<input[lc]<<"\n";
                    goto issue;
                }
                else if((brackets_stack[stack_top] != '(') || (brackets_stack.empty()))
                {
                    flag = 1;
                    //cout<<"Issue found:( lc = "<<lc<<"input[lc]"<<input[lc]<<"\n";
                    goto issue;
                }
                else
                {
                    brackets_stack.pop_back();
                    track_index.pop_back();
                    stack_top--;
                    //cout<<"Popping : "<<input[lc]<<"\n";
                }
                break;
        }
    }
    issue:
    if(lc == length && !track_index.empty())
    {
        cout<<track_index[0] + 1<<"\n";
    }
    else if(flag == 0)
    {
        cout<<"Success"<<"\n";
    }
    else if(flag == 1)
    {
        cout<<lc + 1<<"\n";
    }
}

int main()
{
    string input;
    cin>>input;
    checkBalance(input);
    return 0;
}