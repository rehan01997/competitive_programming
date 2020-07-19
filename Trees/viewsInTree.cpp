#include<bits/stdc++.h>
using namespace std;


class Node
{
    public:
        int data;
        Node *left;
        Node *right;

        Node(int data)
        {
            this->data = data;
            left = NULL;
            right = NULL;
        }
};
Node * root = NULL;
Node* construct(vector<int>arr)
{
    Node*root = new Node(arr[0]);
    stack<pair< Node*  , int> >st;    //node  , state
    st.push({ root , 1 });

    int idx = 0;
    while(!st.empty())
    {
        pair<Node *,int> curr = st.top();        
        if(curr.second  == 1)
        {
            idx++;
            st.pop();
            st.push({curr.first , curr.second + 1});  

            if(arr[idx] != -1)
            {
                curr.first->left = new Node(arr[idx]);
                st.push({curr.first->left , 1});
            }          
        }
        else if( curr.second == 2)
        {  
            idx++;
            st.pop();
            st.push({curr.first , curr.second + 1}); 
            if( arr[idx] != -1)
            {
                curr.first->right = new Node(arr[idx]);
                st.push({ curr.first->right , 1 });
            }
        }
        else
        {
            st.pop();
        }        
    }
    return root;
}   
void display(Node *& root)
{
    if( root == NULL) return;
    
    string str = "";
    str += root->left == NULL ? "." : to_string(root->left->data);
    str += " <- " + to_string(root->data) + " -> ";
    str += root->right == NULL ? "." : to_string(root->right->data);
    cout << str << endl;
    display(root->left);
    display(root->right);
    return;
}
    void vertical_level(Node *root)
    {
    	//if( root == NULL) return;
    	
    	queue<pair<Node*,int>>q;     //Node , vertical level number
    	map<int,vector<Node*>>mp; 			 //vertical level number , Node*

    	q.push( {root , 0} );
    	while( !q.empty() )
    	{
    		pair<Node*,int> curr = q.front();
    		Node * node = curr.first;
    		int vert_n = curr.second;
    		mp[vert_n].push_back( node );
    		q.pop(); 
    		
    		if( node -> left != NULL)
    		{
    			q.push( {node -> left , vert_n - 1});
    		}
    		if( node -> right != NULL)
    		{
    			q.push( {node -> right , vert_n + 1});
    		}
    	}
    	for(auto it = mp.begin() ; it != mp.end() ; it++)
    	{
    		for(auto node : it -> second)
    		{
    			cout << node->data << " ";
    		}cout << endl;
    	}
    	return ;
    }
int main()
{
	    int n ; cin >> n;
        vector<int>arr(n); 
        for(int i = 0 ; i < n ; i++)
        {
            cin >> arr[i];	
        }
        root = construct(arr);
        vertical_level( root );
        return 0;
}
