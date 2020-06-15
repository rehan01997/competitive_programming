#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
        int data;
        vector<Node*>children;
};
Node *root = NULL;

void construct(vector<int> arr)
{
    stack<Node*> st;
    for(int i = 0 ; i < arr.size() ; i++)
    {
        if( arr[i] == -1) st.pop();
        else 
        {   Node *t = new Node();
            t->data = arr[i];
            if(st.size() > 0)
            {
               st.top()->children.push_back(t);
            }
            else
            {
                root = t;
            }        
            st.push(t);
        }
    }
    return;
}
void display(Node *& temp)
{
    cout << temp->data << " : ";
    for(int i = 0 ; i < temp->children.size() ; i++)
    {
        cout << temp->children[i]->data << ",";
    }
    cout << endl;
    for( auto child : temp->children)
    {
        display(child);
    }
    return;
}
int maxInTree(Node *& temp)
{
    int maxValue = temp->data;

    for(int i = 0 ; i < temp->children.size() ; i++ )
    {
        int childmax = maxInTree( temp->children[i]);
        if( childmax > maxValue) maxValue = childmax;
    }
    return maxValue;
}
int heightGenericTree( Node *& temp)
{
    if( temp->children.size() == 0)
    {
        return 0;
    }
    int minheight = 0;
    for(int i = 0 ; i < temp->children.size() ; i++)
    {
        int ch = heightGenericTree( temp->children[i] );
        if( ch > minheight) minheight = ch;
    }
    return minheight + 1;
}
int main()
{
    int n ; cin >> n;
    vector<int>arr(n); 
    for(int i = 0 ; i < n ; i++)
    {
        cin >> arr[i];
    }
    construct(arr);
    //cout<<root->data;

    // int maxx = maxInTree(root);
    // cout<<maxx;

    // int height = heightGenericTree(root);
    // cout<<height << endl;

    display(root);
    return 0;
}
// 12
// 10 20 -1 30 50 -1 60 -1 -1 40 -1 -1