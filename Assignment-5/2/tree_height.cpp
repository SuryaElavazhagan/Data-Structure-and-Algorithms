#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct node
{
    long long data;
    vector<struct node*> childs;
} *root = NULL;

int main()
{
    long long n = 0;
    long long root_index = 0;
    long long lc = 0;
    queue<struct node*> traverse;
    int height = 0;
    cin>>n;
    vector<long long> list(n);
    vector<struct node> tree(n);
    for(lc = 0; lc < n; lc++)
    {
        cin>>list[lc];
        tree[lc].data = lc;
        if(list[lc] == -1)
            root_index = lc; 
    }

    root = &tree[root_index];
    for(lc = 0; lc < n; lc++)
    {
        if(list[lc] == -1)
            continue;
        tree[list[lc]].childs.push_back(&tree[lc]);
    }

    traverse.push(root);
    struct node *last_node = root;
    while(!traverse.empty())
    {
        struct node *current_node = traverse.front();
        int current_size = current_node->childs.size();
        if(current_size != 0)
        {    
            for(lc = 0; lc < current_size; lc++)
            {
                traverse.push(current_node->childs[lc]);
            }
        }
        if(last_node == traverse.front())
            {
                height++;
                last_node = traverse.back();
            }
        traverse.pop();
    }

    cout<<height<<"\n";
}
