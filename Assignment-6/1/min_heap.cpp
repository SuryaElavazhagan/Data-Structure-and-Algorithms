#include<iostream>
#include<vector>

/*
  ************BINARY MIN HEAP*************
  * It is a refactored method for selection sort.
  * Definition :
    Binary min-heap is a binary tree (each node has zero , one or more children) where the value of
    each node is atmost the values of its children.
  * Implementation of Binary min-heap in Arrays is done here.
*/

using namespace std;

// Global variables

long long SIZE = 0;
vector<long long> min_heap;
vector<long long> swaps;

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
  return (i/2);
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
 This will move a node down in the tree if it does not satisfy the
 binary min-heap property.

 -> Checks whether the left and right child of the node is lesser than the node i
 -> Swaps it
 -> Perform swift_down() operation on the swapped node.
*/
void swift_down(long long i)
{
  long long min_index = i;
  long long left_child_index = left_child(i);
  long long right_child_index = right_child(i);

  if(left_child_index < SIZE && min_heap[left_child_index] < min_heap[min_index])
    min_index = left_child_index;

  if(right_child_index < SIZE && min_heap[right_child_index] < min_heap[min_index])
    min_index = right_child_index;

  if(i != min_index)
  {
    swaps.push_back(i);
    swaps.push_back(min_index);
    swap(min_heap[min_index], min_heap[i]);
    swift_down(min_index);
  }
}

int main()
{
  cin>>SIZE;
  long long temp = 0;

  // Getting array items.
  for(long long i = 0; i < SIZE; i++)
  {
    cin>>temp;
    min_heap.push_back(temp);
  }

  // swift_down() for n/2 to 0 nodes.
  for(long long i = (SIZE / 2); i >= 0; i--)
  {
    swift_down(i);
  }

  cout<<(swaps.size() / 2)<<endl;
  for(long long i = 0; i < swaps.size(); i++)
    cout<<swaps[i]<<" "<<swaps[++i]<<endl;
  //cout<<endl;

  /*
    // Implementation of Heap sort (Ascending order) is done here.

    for(long long i = 0; i < SIZE; i++)
    {
      cout<<min_heap[i]<<" ";
    }
    cout<<endl;
  */
  return 0;
}
