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
void vertical_levelI()     //using map
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
//***vertical view II  -- using vector
int min_r = 0;
int max_r = 0;
void find_range(Node *node , int level)      //root , 0 
{
    if( node == NULL) return;

    min_r = min( min_r , level );
    max_r = max( max_r , level);
    if( node ->left != NULL) find_range( node->left , level -1);
    if( node ->right != NULL ) find_range( node->right , level + 1);

    return;
}
void vertical_levelII()
{
    find_range(root , 0);
    queue<pair<Node*,int>>q;          
    vector<vector<Node*>>v( max_r - ( min_r) + 1 );    

    int root_idx = -1*min_r;    
    q.push({root , root_idx});
    //v[root_idx].push_back(root);
    while(!q.empty())
    {
        int size = q.size();
        while( size--)
        {
            pair<Node*,int>curr = q.front();
            q.pop();
            v[curr.second].push_back( curr.first );
            if( curr.first->left != NULL)
            {
                q.push({curr.first->left , curr.second - 1});
            }
            if( curr.first->right != NULL)
            {
                q.push({ curr.first->right , curr.second + 1});
            }
        }
    }
    for(auto vec : v)
    {
        for( auto node : vec)
        {
            cout << node->data << " ";
        }cout << endl;
    }
    return;
}
void bottom_view()
{
    find_range(root , 0);
    queue<pair<Node*,int>>q;          
    vector<Node*>v( max_r - ( min_r) + 1 );    

    int root_idx = -1*min_r;    
    q.push({root , root_idx});
    //v[root_idx].push_back(root);
    while(!q.empty())
    {
        int size = q.size();
        while( size--)
        {
            pair<Node*,int>curr = q.front();
            q.pop();
            v[curr.second] = curr.first;
            if( curr.first->left != NULL)
            {
                q.push({curr.first->left , curr.second - 1});
            }
            if( curr.first->right != NULL)
            {
                q.push({ curr.first->right , curr.second + 1});
            }
        }
    }
    for(auto vec : v)
    {
        cout << vec->data << endl;
    }
    return;
}
void vertical_sum()
{
    find_range(root , 0);
    queue<pair<Node*,int>>q;          
    vector<int>v( max_r - ( min_r) + 1 , 0);    

    int root_idx = -1*min_r;    
    q.push({root , root_idx});
    //v[root_idx].push_back(root);
    while(!q.empty())
    {
        int size = q.size();
        while( size--)
        {
            pair<Node*,int>curr = q.front();
            q.pop();
            v[curr.second] += curr.first->data;
            if( curr.first->left != NULL)
            {
                q.push({curr.first->left , curr.second - 1});
            }
            if( curr.first->right != NULL)
            {
                q.push({ curr.first->right , curr.second + 1});
            }
        }
    }
    for(auto vec : v)
    {
        cout << vec << endl;
    }
    return;

}
void leftview()
{
    queue<Node*>q;
    q.push(root);
    while( !q.empty())
    {
        int size = q.size();
        cout << q.front()->data;
        while(size--)
        {
            Node *currNode = q.front();
            q.pop();

            if (currNode->left != NULL)
            {
                q.push(currNode->left);
            }
            if (currNode->right != NULL)
            {
                q.push(currNode->right);
            }
        }
        cout << endl;
    }
    return;
}
void rightViewI()
{
    queue<Node *> que;
    que.push(root);

    while (que.size() != 0)
    {
        int size = que.size();
        cout << que.back()->data << " ";

        while (size-- > 0)
        {
            Node *currNode = que.front();

            que.pop();

            if (currNode->left != NULL)
            {
                que.push(currNode->left);
            }

            if (currNode->right != NULL)
            {
                que.push(currNode->right);
            }
        }
    }
    cout << "\n";
}
void rightViewII()   //Used to print vertical order
{
    queue<Node *> que;
    que.push(root);
    Node*prev=NULL;

    while (que.size() != 0)
    {
        int size = que.size();

        while (size-- > 0)
        {
            Node *currNode = que.front();
            que.pop();

            prev=currNode;

            if (currNode->left != NULL)
            {
                que.push(currNode->left);
            }

            if (currNode->right != NULL)
            {
                que.push(currNode->right);
            }            
        }
        cout<<prev->data<<" ";
    }
    cout << "\n";
}
void topView()   //Used to print vertical order
{
    queue<Node *> que;
    que.push(root);
    //Node*prev=NULL;

    while (que.size() != 0)
    {
        int size = que.size();
        if(size == 1) cout << que.front()->data << " ";
        else cout << que.front()->data << " " << que.back()->data << " ";
        
       //int count=0;   // count to keep check that root node is not printed twice

        while (size-- > 0)
        {
            //count++;
            Node *currNode = que.front();
            que.pop();

            //prev=currNode;

            if (currNode->left != NULL)
            {
                que.push(currNode->left);
            }

            if (currNode->right != NULL)
            {
                que.push(currNode->right);
            }
            
        }
        // if(count>1)
        //     cout<<prev->data<<" ";
    }
    cout << "\n";
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
        //vertical_levelI();
        //vertical_levelII();
        //vertical_sum();
        bottom_view();
        //leftview();
        //rightViewI();
        //rightViewII();
        //topView();
        //displa
        return 0;
}
