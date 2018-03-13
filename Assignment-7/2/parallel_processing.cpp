#include<iostream>
#include<numeric>
#include<vector>

using namespace std;

/*  
    *************PARALLEL PROCESSING**************
    -> Structure thread has the index of the thread and,
        - the total time of the processes which it has compeleted already.
    -> This program uses Min-Heap beacause the thread with lower index should always be the root.
    -> It compares the values (i.e., total time which it has completed already) and
        - the index of the thread and swift it down (see swift_down() function)
*/

struct thread
{
    long long index = 0;
    long long current_time = 0;
};

// This will swap two numbers in the array.
void swap(long long &a, long long &b)
{
    long long temp = a;
    a = b;
    b = temp;
}

// This will return the index of parent of node i.
long long parent(long long i)
{
    return (i - 1)/2;
}

// This will return the index of left child of node i.
long long left_child(long long i)
{
    return (2 * i) + 1;
}

// This will return the index of right child of node i.
long long right_child(long long i)
{
    return (2 * i) + 2;
}

/*
// It implements swift up 
void swift_up(long long i, vector<thread> &threads)
{
    while(i < no_of_threads && ((threads[parent(i)].current_time >= threads[i].current_time)))
    {
        if((threads[parent(i)].index > threads[i].index) && 
            (threads[parent(i)].current_time == threads[i].current_time))
            {break;}
        swap(threads[i], threads[parent(i)]);
        i = parent(i);
    }
}*/

/*
 This will move a node down in the tree if it does not satisfy the
 binary min-heap property.

 -> Checks whether the left and right child of the node is lesser than the node i
 -> Checks whether the left and right child's index is lesser than the node i
 -> Swaps it
 -> Perform swift_down() operation on the swapped node.
*/
void swift_down(long long i, vector<thread> &threads)
{
    long long min_index = i;

    long long left_child_index = left_child(i);
    
    if(left_child_index < threads.size())
    {
        if( ((threads[min_index].index > threads[left_child_index].index) && 
            (threads[left_child_index].current_time == threads[min_index].current_time)) ||
            (threads[left_child_index].current_time < threads[min_index].current_time) )
            {
                min_index = left_child_index;
            }
    }
    
    long long right_child_index = right_child(i);
    
    if(right_child_index < threads.size())
    {
        if( ((threads[min_index].index > threads[right_child_index].index) && 
            (threads[right_child_index].current_time == threads[min_index].current_time)) ||
            (threads[right_child_index].current_time < threads[min_index].current_time) )
        {
            min_index = right_child_index;
        }
    }

    if(i != min_index)
    {
        swap(threads[i], threads[min_index]);
        swift_down(min_index, threads);
    }
    //cout<<"Position : "<<min_index<<" Index : "<<threads[min_index].index<<endl;
}

void process_thread(vector<thread> &threads, vector<long long> &process_time)
{
    long long no_of_process = process_time.size();
    //long long no_of_threads = threads.size() - 1;
    long long old_process_time = 0;

    for(long long i = 0; i < no_of_process; i++)
    {
        // Processing each item.
        old_process_time = threads[0].current_time;
        cout<<threads[0].index<<" "<<old_process_time<<endl;
        threads[0].current_time += process_time[i];
        swift_down(0, threads);
    }
}

int main()
{
    long long no_of_threads = 0;
    long long no_of_process = 0;

    cin>>no_of_threads>>no_of_process;

    vector<long long> process_time(no_of_process);
    vector<thread> threads(no_of_threads);
    for(long long i = 0; i < no_of_process; i++)
    {
        cin>>process_time[i];
    }

    for(long long i = 0; i < no_of_threads; i++)
    {
        threads[i].index = i;
        threads[i].current_time = 0;
    }

    process_thread(threads, process_time);
    return 0;
}