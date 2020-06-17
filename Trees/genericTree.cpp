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
    cout << temp->data << " -> ";
    for(int i = 0 ; i < temp->children.size() ; i++)
    {
        cout << temp->children[i]->data << ", ";
    }
    cout<<".";
    cout << endl;
    for( auto child : temp->children)
    {
        display(child);
    }
    return;
}
int size(Node *& temp)
{
    int mySize = 1;
    for(int i = 0 ; i < temp->children.size() ; i++)
    {
        int cs = size( temp->children[i]);
        mySize += cs;
    }
    return mySize;
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
void traversalGenericTree(Node* &temp)
{
	if( temp == NULL) return;

	cout << "Node Pre " << temp->data <<endl;
	for(int i = 0 ; i < temp->children.size() ; i++)
	{
		Node *child = temp->children[i];
		cout << "Edge pre " << temp->data << "--" << child -> data << endl;
		traversalGenericTree(child);
		cout <<"Edge Post " << temp -> data << "--" << child -> data <<endl;
	}
	cout << "Node Post " << temp->data << endl;
}

void levelOrdergenericTree( Node *& root)
{
	if(root ==  NULL)
	{
		return;	
	} 
	queue<Node*>Q;
	Q.push(root);

	while( !Q.empty())
	{
		Node * temp = Q.front(); Q.pop();
		cout << temp -> data << " " ;
		for(auto node : temp->children)
		{
			Q.push(node);
		}
		
	}
	return ;
}
void levelOrderLineWise( Node *& root)
{
	if( root == NULL) return;
	queue<Node*> Q;
	Q.push(root);

	while( !Q.empty())
	{	
		int Qsize = Q.size();
		for(int i = 0 ; i < Qsize ; i++ )
		{
			Node * temp = Q.front(); Q.pop();
			cout << temp -> data << " " ;
			for(auto node : temp->children)
			{
				Q.push(node);
			}				
		}cout<<endl;
	}
return;
}
void levelOrderLineWiseZigZag()
{
	if( root == NULL) return;
	int curr_level = 0;
	queue<Node*>Q;
	stack<Node*>st;

	Q.push( root ); 
	while(!Q.empty())
	{	
		int Qsize = Q.size();
		for(int i = 0 ; i < Qsize ; i++)
		{	
			Node * temp = Q.front(); Q.pop();
			if( curr_level % 2 == 0)
			{
				cout << temp -> data << " ";	
			}			
			for( auto node : temp->children)
			{
				Q.push(node);
				if( curr_level % 2 == 0) st.push(node);
			}	
		}
		cout<<endl;
		while(!st.empty())
		{
			Node * t = st.top();
			cout<< t->data << " ";
			st.pop();
		}
		curr_level++;
	}
	return;
}
void removeLeaves(Node*& temp)
{
	vector<Node*> nchild ;
	for(int i = 0 ; i < temp->children.size() ; i ++)
	{
		Node *curr_ch = temp->children[i];
		if( curr_ch->children.size() > 0)
		{
			nchild.push_back(curr_ch);
		}
	}
	temp->children = nchild;
	for(int i= 0 ; i < temp->children.size() ; i++)
	{
		removeLeaves(temp->children[i]);
	}
}
bool find( Node*& temp , int val)
{
	if( temp -> data == val) return true;

	for(int i = 0 ; i < temp->children.size() ; i++)
	{
		bool recAns = find(temp->children[i] , val);
		if( recAns)
			return true;
	}
	return false;
}
void mirrorGenericTree(Node *& temp)
{
	for(auto node : temp->children)
	{
		mirrorGenericTree(node);
	}
	reverse(temp->children.begin() , temp->children.end());
}
vector<int>nodeToRootPath( Node*& temp , int val)
{
	if( temp -> data == val)
	{
		vector<int> base;
		base.push_back(val);
		return base;
	}
	vector<int> ans ;
	for(int i = 0 ; i < temp->children.size() ; i++)
	{
		vector<int> recAns = nodeToRootPath( temp->children[i] , val);
		for( auto nodeData : recAns) ans.push_back(nodeData);
	}
	if( !ans.empty()) ans.push_back(temp->data);
	return ans;
}
int lowestCommonAncestor(int n1 , int n2)
{
	vector<int> num1 = nodeToRootPath(root,n1);
	vector<int> num2 = nodeToRootPath(root,n2);

	int i = num1.size() - 1;
	int j = num2.size() - 1;
	while( i >= 0 && j >= 0 && num1[i] == num2[j] )
	{ 
		i-- ; j--;
	}
	return num1[i + 1];
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
    
    //display(root);
    //cout<<root->data;

    // int maxx = maxInTree(root);
    // cout<<maxx;

    // int height = heightGenericTree(root);
    // cout<<height << endl;

    //traversalGenericTree(root);
    
    // int siz = size(root);
    // cout << siz << endl;

    //levelOrdergenericTree(root);
    //levelOrderLineWise( root );
   ///levelOrderLineWiseZigZag();

    //removeLeaves(root); display(root);

    // int val ; cin >> val;
    // if( find( root , val )) cout<<"true";
    // else cout <<"false";
    //display(root);
    
    // vector<int> anss = nodeToRootPath(root , 60);
    // for(auto s : anss)
    // {
    // 	cout<<s<<" ";
    // }
    // return 0;

    // int n1 , n2;
    // cin >> n1 >> n2;
    // int ans = lowestCommonAncestor(n1 , n2);
    // cout << ans;

    mirrorGenericTree(root); display(root);
}
// 12
// 10 20 -1 30 50 -1 60 -1 -1 40 -1 -1