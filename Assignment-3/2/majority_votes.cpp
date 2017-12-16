#include<iostream>
#include<vector>
#include<cstdlib>

#define NO_VOTE -1
#define MAJORITY_ELEMENT_FOUND 1
#define NO_MAJORITY_ELEMENT 0

using namespace std;

/*
    ***************DIVIDE AND CONQUER*****************
    * Divide the array into two halves.
    * Get the majority element from both the halves.
    * And compare both the majority elements and get the result.

    Note:
        This can also be done using Hash table with O(n) time complexity
        but for now it runs O(nlogn) => Divide and conquer method.
*/

long long get_majority_element(vector<long long> votes, long long left_majority_element, long long right_majority_element, int low,int high)
{
    int left_count = 0;
    int right_count = 0;

    for(int i = 0; i <= high; i++)
    {
        // Counting both left and right majority element.
        if(left_majority_element == votes[i])
            left_count++;
        
        if(right_majority_element == votes[i])
            right_count++;
    }

    /*
        On dividing array into half majority level changes
        i.e., for n = 10, majority votes will be >5
        if it is split to two halves 5 & 5

        for n = 5 => majority votes will be >2
    */
    int majority_limit = (int)((high - low + 1) / 2);
    if(left_count > majority_limit)
        return left_majority_element;
    else if(right_count > majority_limit)
        return right_majority_element;
    else
        /*
            If both left and right elements are not majority element
            Then return negative means no vote.
        */
        return NO_VOTE;
}

long get_majority(vector<long long> votes, int low, int high)
{
    // Base case => Divided array is at last level
    if(low == high)
        return votes[low];
    
    // Computing mid index
    int mid = (int)((low + high) / 2);
    
    // Left half
    long long left_majority_element = get_majority(votes, low, mid);
    
    // Right half
    long long right_majority_element = get_majority(votes, mid + 1, high);

    // Returning the majority element if present, else -1.
    return get_majority_element(votes, left_majority_element, right_majority_element, low, high); 
}

int main()
{
    int n = 0;

    //cout<<"Give n:";
    cin>>n;

    vector<long long> votes(n);
    
    //cout<<"Give n elements:";
    for(int i = 0; i < n; i++)
        cin>>votes[i];
    
    //cout<<"Majority element found (1 / 0):";
    if(n >= 2)
    {
        if(get_majority(votes, 0, n - 1) == -1)
            cout<<NO_MAJORITY_ELEMENT<<"\n";
        else
            cout<<MAJORITY_ELEMENT_FOUND<<"\n";
    }
    else
    {
        cout<<NO_MAJORITY_ELEMENT<<"\n";
    }
    return 0;
}

/*
    **************STRESS TESTING*********************
*/
/*
int divide_and_conquer(vector<long long> votes, int n)
{
    if(n >= 2)
    {
        if(get_majority(votes, 0, n - 1) == -1)
            return NO_MAJORITY_ELEMENT;
        else
            return MAJORITY_ELEMENT_FOUND;
    }
    else
    {
        return NO_MAJORITY_ELEMENT;
    }
}

int naive_alogirthm(vector<long long> votes, int n)
{
    int current_element = 0;
    int count = 0;

    if(n <= 2)
        return NO_MAJORITY_ELEMENT;
    
    for(int i = 0; i < n; i++)
    {
        current_element = votes[i];
        count = 0;
        for(int j = 0; j < n; j++)
        {
            if(votes[j] == current_element)
                count++;
        }
        if(count > (int)(n / 2))
            return MAJORITY_ELEMENT_FOUND;
    }
    return NO_MAJORITY_ELEMENT;
}

void stress_testing()
{
    while(1)
    {
        int n = rand() % 100 + 1;

        cout<<"n : "<<n<<"\n";
        vector<long long> votes(n);
        for(int i = 0; i < n; i++)
        {
            votes[i] = rand() % 100000 + 1;
            cout<<votes[i]<<" "; 
        }
        cout<<"\n";

        long long res1 = naive_alogirthm(votes, n);
        long long res2 = divide_and_conquer(votes, n);

        if(res1 == res2)
        {
            cout<<"Success"<<"\n";
        }
        else
        {
            cout<<"Failed"<<"\n";
            break;
        }
    }
}

int main()
{
    stress_testing();
    return 0;
}
*/


