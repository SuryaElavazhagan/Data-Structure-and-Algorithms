#include<iostream>
#include<vector>

/*
    ********************SAFE MOVE**********************
    Moving as far as the fuel is good enought to reach another gas station
*/

using namespace std;

    /*
        * This program has Loop nested within another loop
        * So, it seems to have O(n * n) run-time
        * But, the run time of the program is O(n)
            => currentRefills can be atmost n - 1
            => numRefills can be atmost n
            => So there will be atmost n + 1 operations
                => O(n + 1) => O(n)
    */

int minRefills(int n, vector<int> x, int dist_with_full_tank)
{
    int numRefills = 0, currentRefills = 0;
    int lastRefills = 0;
    //cout<<"Stops where you need to get refilling:";
    while(currentRefills < (n - 1))
    {
        lastRefills = currentRefills;
        while((currentRefills < (n - 1)) && (x[currentRefills + 1] - x[lastRefills] <= dist_with_full_tank))
        {
            currentRefills++;
            if(currentRefills == (n - 1))
                break;
        }
        //cout<<a[lastRefills]<<'\n';
        if(currentRefills == lastRefills)
        // This happens when gas station is far away that even full tank of fuel 
        // could not make up
            return -1;
        if(currentRefills < (n - 1))
            numRefills++;
    }
    return numRefills;
}

main()
{
    int n = 0;
    vector<int> x;
    int dist_with_full_tank = 0;

    //cout<<"Give n:"
    cin>>n;
    int temp = 0;
    //cout<<"Give gas station stops in kms:";
    for(int i = 0; i < n; i++)
    {
        cin>>temp;
        x.push_back(temp);
    }
    //cour<<"Give Mileage per full tank:";    
    cin>>dist_with_full_tank;

    //cout<<"Number of refilling required:";
    cout<<minRefills(n, x, dist_with_full_tank)<<'\n';
}