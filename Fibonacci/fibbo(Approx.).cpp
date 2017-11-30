#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;

long double applyFormula(int n)
{
    long double temp = 0;
    long double x = sqrtl(5.0);
    long double t1 = (1 + x)/2;
    t1= powl(t1,n);
    long double t2 =(1 - x)/2;
    t2 = powl(t2,(float) n);
    temp = t1 - t2;
    double t3 = powl(x , -1.0);
    temp = temp * t3;
    return temp;
}

main()
{
    int n;
    cin>>n;
    cout.setf(ios::fixed);
    cout<<setprecision(0)<<applyFormula(n)<<'\n';
}