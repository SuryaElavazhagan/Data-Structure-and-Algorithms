#include<iostream>
#include<vector>

using namespace std;

/*
    ******************DIVIDE AND CONQUER*****************
    * Store the points in the structure like
        -> point
        -> category
      For example: if it is a segment (2, 5)
      store it as (2, 'left') & (5, 'right')
      If it is a point (4)
      store it as (4, 'point')
    * Sort them in non decreasing order:
        Then it will be like
        (2, 'left') (4, 'point') (5, 'right')
        It shows that 4 lies between 2 and 5
    * The important problem to consider lies in sorting
    i.e., (2, 5) (2, 7) (2, 10) => Segments
          (2) (4) (3)           => Points
          then the sorted order should be:
          (2, 'left') (2 , 'left') (2, 'left') (2, 'point')
          (3, 'point') (4, 'point') (5, 'right') (7, 'right')
          (10, 'right')
    => The redundancy should be handled properly.
*/

#define LEFT -1 // To indicate it as left side of the segement
#define POINT 0 // To indicate it as point
#define RIGHT 1 // To indicate it as right side of the segment

struct coordinates
{
    long long data;
    int category;
    /*
        * This index is to store the index of the point.
        * This will be helpful in calculations.
    */
    long long index; 
    coordinates(long long data, int category, long long index) : data(data), category(category), index(index) {}
};

void merge(vector<struct coordinates> &list, long long low, long long high, long long mid)
{
    /*
        * Actual logic goes here.
    */
    long long left_index, right_index, temp_index;

    long long left_size = mid - low + 1;
    long long right_size = high - mid;

    vector<struct coordinates> left_half;
    vector<struct coordinates> right_half;

    // Inserting left half to left temporary array
    for(long long i = 0; i < left_size; i++)
        left_half.push_back(list[low + i]);

    // Inserting right half to right temporary array
    for(long long i =0; i < right_size; i++)
        right_half.push_back(list[mid + 1 + i]);
    
    left_index = 0;
    right_index = 0;
    temp_index = low;

    // Compare and store them to temp array
    while(left_index < left_size && right_index < right_size)
    {
        /*
            The redundancy is handle here.
            If the category is same you can push both elements
            from left and right sub array.
            else Check which category is low and push them.
        */
        if(left_half[left_index].data == right_half[right_index].data)
        {
            if(left_half[left_index].category < right_half[right_index].category)
            {
                list[temp_index++] = left_half[left_index++];
            }
            else if(left_half[left_index].category > right_half[right_index].category)
            {
                list[temp_index++] = right_half[right_index++];
            }else if(left_half[left_index].category == right_half[right_index].category)
            {
                list[temp_index++] = left_half[left_index++];
                list[temp_index++] = right_half[right_index++];
            }
        }
        else if(left_half[left_index].data < right_half[right_index].data)
            list[temp_index++] = left_half[left_index++];
        else
            list[temp_index++] = right_half[right_index++];
    }

    // Copy the remaining to temp array.
    // Only one of the loop will be executed.
    while(left_index < left_size)
        list[temp_index++] = left_half[left_index++];
    
    while(right_index < right_size)
        list[temp_index++] = right_half[right_index++];
}

void merge_sort(vector<struct coordinates> &list, long long low, long long high)
{
    if(low < high)
    {
        long long mid = (long long)((low + high) / 2);
        
        // Left half
        merge_sort(list, low, mid);
        
        // Right half
        merge_sort(list, mid + 1, high);
        
        // Merging both the halves
        merge(list, low, high, mid);
    }
}
vector<long long> get_range(vector<struct coordinates> cords, long long segments, long long points)
{
    /*
        Since there are two points in segements it takes
        2 * segments + points
    */
    long long n = (2 * segments) + points;
    vector<long long> result(points);
    
    /*
        This layer indicates the number of segments in 
        which the point lies. 
    */
    long long segment_layer = 0;
    for(long long i =0; i < n; i++)
    {
        if(cords[i].category == LEFT)
        {
            segment_layer++;
        }
        if(cords[i].category == RIGHT)
        {
            segment_layer--;
        }
        if(cords[i].category == POINT)
        {
            // Here the index is actually used.
            result[cords[i].index] = segment_layer;
        }
    }
    return result;
}

int main()
{
    long long segments = 0;
    long long points = 0;

    //cout<<"Give number of Segments and number of points:\n";*
    cin>>segments>>points;

    vector<struct coordinates> cords;

    long long temp_left = 0;
    long long temp_right = 0;
    //cout<<"Give "<<segments<<" segment(s):\n";
    for(long long i = 0;i < segments; i++)
    {
        cin>>temp_left>>temp_right;
        // Pushing left point of segement
        cords.push_back(coordinates(temp_left, LEFT, -1));
        // Pushing right point of segement
        cords.push_back(coordinates(temp_right, RIGHT, -1));
    }

    //cout<<"Give "<<points<<" Point(s):";
    for(long long i = 0; i < points; i++)
    {
        cin>>temp_left;
        // Only for points the index is stored.
        cords.push_back(coordinates(temp_left, POINT, i));
    }

    // Sort them.
    merge_sort(cords, (long long)0, ((long long)(2 * segments)) + points - 1);

    vector<long long> result;

    result = get_range(cords, segments, points);

    //cout<<"The result  is :\n";
    for(long long i = 0; i < points; i++)
        cout<<result[i]<<" ";
    
    cout<<"\n";
    return 0;
}