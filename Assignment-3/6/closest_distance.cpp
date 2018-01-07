#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<cfloat>
#include<cstdlib>
#include<iomanip>

using namespace std;

struct point
{
    long long x;
    long long y;
};

struct x_based_compare
{
    inline bool operator() (const point& struct1, const point& struct2)
    {
        return (struct1.x < struct2.x);
    }
};

struct y_based_compare
{
    inline bool operator() (const point& struct1, const point& struct2)
    {
        return (struct1.y < struct2.y);
    }
};

double min(double a, double b)
{
    if(a < b)
        return a;
    return b;
}

long long min(long long a, long long b)
{
    if(a < b)
        return a;
    else
        return b;
}

double distance_between(point a, point b)
{
    return sqrtf((float)
            ((a.x - b.x) * (a.x - b.x) +
            (a.y - b.y) * (a.y - b.y))
    );
}

double brute_force(vector<point> &points)
{
    long long size = points.size();
    //cout<<" \n Hi my size :"<<size<<"\n";
    double min_distance = DBL_MAX;
    double temp = 0;
    for(long long olc = 0; olc < size; olc++)
    {
        for(long long ilc = olc + 1; ilc < size; ilc++)
        {
            temp = distance_between(points[olc], points[ilc]);
            //cout<<"\noutside min distance :"<<min_distance<<"\n";
            if(min_distance > temp)
            {
                min_distance = temp;
                //cout<<"\ninside min distance :"<<min_distance<<"\n";
            }
        }
    }
    //cout<<"\nOutside\n";
    return min_distance;
}

double closest_split_pair(vector<point> x_sorted, vector<point> y_sorted, double minimum_distance, long long mid)
{
    double best_distance = 0;
    long long size = y_sorted.size();
    long long limit = 0;
    vector<point> split_points;

/*     cout<<"\nMid element : ("<<x_sorted[mid].x<<" , "<<x_sorted[mid].y<<")"<<endl;
    cout<<"\nMinimum Distance = "<<minimum_distance<<endl;
    cout<<"\nY-Sorted elements : "<<endl;
    for(long long lc = 0; lc < size; lc++)
    {
        cout<<"("<<y_sorted[lc].x<<", "<<y_sorted[lc].y<<") ";
    }
    cout<<"\nSplit region :"<<endl; */
    for(long long lc = 0; lc < size; lc++)
    {
        //cout<<"\nabs(x_sorted[mid].x - y_sorted[lc].x) = "<<abs(x_sorted[mid].x - y_sorted[lc].x)<<endl;
        if(abs(x_sorted[mid].x - y_sorted[lc].x) < minimum_distance)
        {
            split_points.push_back(y_sorted[lc]);
            //cout<<"("<<y_sorted[lc].x<<", "<<y_sorted[lc].y<<") ";
        }
    }

    //cout<<endl;
    size = split_points.size();

    for(long long olc = 0; olc < size; olc++)
    {
        limit = min(7, size - olc);
        for(long long ilc = 1; ilc < limit; ilc++)
        {
            best_distance = distance_between(split_points[olc], split_points[olc + ilc]);
            if(best_distance < minimum_distance)
            {
                minimum_distance = best_distance;
            }
        }
    }

    return minimum_distance;
}

double closest_pair(vector<point> &x_sorted, vector<point> &y_sorted)
{
    long long size = x_sorted.size();

    if(y_sorted.size() == 0 || size == 0)
        return DBL_MAX;

    if(size <= 3)
        return brute_force(x_sorted);
    
    long long mid = (long long)((size - 1) / 2);
    point median = x_sorted[mid];
    
    vector<point> left_x_sorted(x_sorted.begin(), x_sorted.begin() + mid + 1);
    vector<point> left_y_sorted;
    vector<point> right_x_sorted(x_sorted.begin() + mid + 1, x_sorted.end());
    vector<point> right_y_sorted;

    size = y_sorted.size();

    for(long long lc = 0; lc < size; lc++)
    {
        if(y_sorted[lc].x <= median.x)
            left_y_sorted.push_back(y_sorted[lc]);
        else
            right_y_sorted.push_back(y_sorted[lc]);
    }

/*     cout<<"\nLeft_X_Sorted :\n";
    for(long long lc = 0; lc < left_x_sorted.size(); lc++)
    {
        cout<<"("<<left_x_sorted[lc].x<<", "<<left_x_sorted[lc].y<<") ";
    }

    cout<<"\nLeft_Y_Sorted :\n";
    for(long long lc = 0; lc < left_y_sorted.size(); lc++)
    {
        cout<<"("<<left_y_sorted[lc].x<<", "<<left_y_sorted[lc].y<<") ";
    }

    cout<<"\nRight_X_Sorted :\n";
    for(long long lc = 0; lc < right_x_sorted.size(); lc++)
    {
        cout<<"("<<right_x_sorted[lc].x<<", "<<right_x_sorted[lc].y<<") ";
    }

    cout<<"\nRight_Y_Sorted :\n";
    for(long long lc = 0; lc < right_y_sorted.size(); lc++)
    {
        cout<<"("<<right_y_sorted[lc].x<<", "<<right_y_sorted[lc].y<<") ";
    }

    cout<<endl; */ 

    double left_minimum_distance = closest_pair(left_x_sorted, left_y_sorted);
    //cout<<"Left_minimum_distance = "<<left_minimum_distance<<endl;
    double right_minimum_distance = closest_pair(right_x_sorted, right_y_sorted);
    //cout<<"Right_minimum_distance = "<<right_minimum_distance<<endl;
    double minimum_distance = min(left_minimum_distance, right_minimum_distance);

    double split_distance = closest_split_pair(x_sorted, y_sorted, minimum_distance, left_x_sorted.size() - 1);
    //cout<<"Split_Distance = "<<split_distance<<endl;

    return min(minimum_distance, split_distance);
}

int main()
{
    //while(1)
    //{
        long long n = 0;
        cin>>n;
        //cout<<"n : "<<n<<endl;
        vector<point> points(n);
        vector<point> x_sorted(n);
        vector<point> y_sorted(n);

        for(long long lc = 0; lc < n; lc++)
        {
            cin>>points[lc].x>>points[lc].y;
            x_sorted[lc].x = y_sorted[lc].x = points[lc].x;
            x_sorted[lc].y = y_sorted[lc].y = points[lc].y;
            //cout<<"("<<x_sorted[lc].x<<", "<<x_sorted[lc].y<<") ";
        } 

        sort(x_sorted.begin(), x_sorted.end(), x_based_compare());
        sort(y_sorted.begin(), y_sorted.end(), y_based_compare());

        /* cout<<"\nX-Sorted :"<<endl;
        for(long long lc = 0; lc < n; lc++)
        {
            cout<<"("<<x_sorted[lc].x<<", "<<x_sorted[lc].y<<") ";
        }
        cout<<endl<<"Y-Sorted :"<<endl;

        for(long long lc = 0; lc < n; lc++)
        {
            cout<<"("<<y_sorted[lc].x<<", "<<y_sorted[lc].y<<") ";
        }
        cout<<endl;  */
        cout<<fixed<<setprecision(4);
        cout<<closest_pair(x_sorted, y_sorted)<<endl;

        /* double naive = brute_force(points);
        
        cout<<"\nNaive :"<<naive;

        double eff = closest_pair(x_sorted, y_sorted);

        if(naive == eff)
            cout<<"Success!"<<endl;
        else
        {
            cout<<"Failed"<<endl;
            cout<<"naive = "<<naive<<" eff :"<<eff<<endl;
            break;
        } 
    } */
    return 0;
}