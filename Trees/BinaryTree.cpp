#include <bits/stdc++.h>
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
int sizeBinaryTree(Node *& node)
{
    if(node == NULL) return 0;
    int c1 = 0 , c2 = 0;
    if( node->left != NULL)
    {
        c1 = sizeBinaryTree(node->left);
    }
    if(node->right != NULL)
    {
        c2 = sizeBinaryTree(node->right);
    }
    return c1 + c2 + 1;
}
int sumBinaryTre(Node *& node)
{
    if( node == NULL) return 0;
    int s1 = 0;
    int s2 = 0;
    if( node->left != NULL)
    {
        s1 = sumBinaryTre(node->left);
    }
    if(node->right != NULL)
    {
        s2 = sumBinaryTre(node->right);
    }
    return s1 + s2 + node->data;
}
int maxBinaryTree(Node *& node)
{
    if(node == NULL) return INT_MIN;
      
    int leftMax = maxBinaryTree(node->left);
    int rightMax = maxBinaryTree(node->right);
      
    return max(max(leftMax,rightMax) , node-> data);
}
int heightBinaryTree(Node *& node) {
    if(node == NULL) return -1;
    int leftHeight = heightBinaryTree(node->left);
    int rightHeight = heightBinaryTree(node->right);
      
    return max(leftHeight , rightHeight) + 1;
}
bool find(Node *node, int data)
{
    if(node == NULL) return false;
    if(node->data == data) return true;
    
    if(node->left != NULL)
    {
        bool recAns = find(node->left , data);
        if(recAns == true) return true;
    }
    if(node->right != NULL)
    {
        bool recAns = find(node->right , data);
        if(recAns == true) return true;
    }
    return false;
}
vector<int>nodeToRootPath(Node * node, int data)
{
    if( node == NULL)
    {
        vector<int>baseAns;
        return baseAns;
    }
    if(node->data == data)
    {
        vector<int>base;
        base.push_back(node->data);
        return base;
    }
    vector<int>ans;
    if(node->left != NULL)
    {
        vector<int>recAns = nodeToRootPath(node->left , data);
        for(int n : recAns)
        {
            ans.push_back(n);
        }
    }
    if(node->right != NULL)
    {
        vector<int>recAns = nodeToRootPath(node->right , data);
        for(int n : recAns)
        {
            ans.push_back(n);
        }
    }
    if( ans.size() > 0)
    {
        ans.push_back(node->data);
    }
    return ans;
}
void PrePostAndInOrder(Node *&root)
{
	stack < pair< Node* , int >> st;
	st.push( { root , 0 } );
	string preOrder = "";
	string postOrder = "";
	string inOrder = "";
	while(!st.empty())
	{
		//pair<Node* , int > curr = st.top();		
		if(st.top().second == 0)
		{
			// st.pop();
			// st.push({ curr.first , curr.second + 1});
            st.top().second++;
			preOrder += to_string(st.top().first->data) + " ";
		}	
		else if(st.top().second == 1)
		{	//left
			// st.pop();
			// st.push({ curr.first , curr.second + 1});
            st.top().second++;
			if( st.top().first->left != NULL)
			{
				st.push({ st.top().first->left , 0 });
			}
		}
		else if( st.top().second == 2)
		{
			// st.pop();
			// st.push({ curr.first , curr.second + 1});
            st.top().second++;
			inOrder += to_string(st.top().first->data) + " ";
		}
		else if(st.top().second == 3)
		{	//right
			// st.pop();
			// st.push({ curr.first , curr.second + 1});
            st.top().second++;
			if( st.top().first->right != NULL)
			{
				st.push({ st.top().first->right , 0 });
			}
		}
		else 
		{   postOrder += to_string(st.top().first->data) + " ";
			st.pop();
		}    
	}
    
	cout << preOrder << endl;
	cout << inOrder << endl;
	cout << postOrder <<endl;
	return;
}
void printKlevelsDown(Node*& root , int k)
{
	if( root == NULL) return;
	else if( k == 0)
	{
		cout << root->data << endl;
		return;
	}
	printKlevelsDown(root->left , k - 1 );
	printKlevelsDown(root -> right , k - 1);
}
void levelOrderBinaryTree(Node *& root)
{
	queue<Node*>q;
	q.push(root);

	while( !q.empty())
	{
		int size = q.size();
		for(int i = 0 ; i < size ; i++)
		{
			Node* cn = q.front() ; q.pop();
			cout << cn->data << " " ;

			if( cn->left != NULL) 
			{
				q.push(cn->left);
			}
			if( cn->right != NULL)
			{
				q.push(cn->right);
			}
		}
		cout<<endl;
	}
}
//*********************************************
// vector<int> nodeToRootPath(Node *& temp , int data)
// {
//     if(temp == NULL) //base case
//     {
//         vector<int>base;
//         return base;
//     }
//     if( temp->data == data) //base case
//     {
//         vector<int> base;
//         base.push_back(temp);
//         return base;
//     }
//     vector<int> ans;
//     if( temp-> left != NULL)
//     {
//         vector<Node*> left = nodeToRootPath( temp->left , data);
//         if( left.size() > 0)
//         {
//             left.push_back( temp );
//         }
//         return 
//     }
//     if(temp ->right != NULL)
//     {
//         vector<Node*> right = nodeToRootPath( temp->right , data);
//         if( right.size() > 0)
//         {
//             right.push_back( temp );
//             return right;
//         }
//     }
//     return ans;
// }

// void printKthNodeFarFromNode (Node*& temp , int data , int k)
// {
//     vector<Node*> NodetoRootPath( temp , data);
// }
//********************************************
Node* createLeftCloneTree(Node *& temp)
{
    if(temp == NULL ) return temp;
    createLeftCloneTree( temp -> left );
    createLeftCloneTree( temp -> right );

    Node* copy = new Node( temp->data );
    copy->left = temp->left;
    temp->left = copy;

    return temp;
}
Node * transformToNormalFromLeftCloned( Node *& temp )
{
    if( temp == NULL) return temp;
    Node * copy = temp -> left;
    temp -> left = copy -> left;
    transformToNormalFromLeftCloned( temp -> left);
    transformToNormalFromLeftCloned( temp -> right);
    return temp;
}
void path_From_Root_Leaf_Sum_In_Range( Node *& root , string path , int sum , int l_range , int h_range)
{
    if( root == NULL ) return;
    else if( root->left == NULL && root -> right == NULL )
    {
        sum += root->data;
        if( sum >= l_range && sum <= h_range)
        {
            cout << path + to_string(root -> data) << endl;
        }
        return;
    }    
    path_From_Root_Leaf_Sum_In_Range( root -> left  , path + to_string( root->data) + " " , sum + root->data , l_range , h_range);
    path_From_Root_Leaf_Sum_In_Range( root -> right , path + to_string( root-> data) + " " , sum + root->data, l_range , h_range);
    return;
}
void print_single_child_BinaryTree(Node*& temp)
{
	if(temp == NULL) return;
	else if( temp->left == NULL && temp->right != NULL)
	{
		cout << temp -> right -> data << endl;
	}
	else if( temp -> left != NULL && temp -> right == NULL)
	{
		cout << temp -> left -> data << endl;
	}

	print_single_child_BinaryTree( temp -> left);
	print_single_child_BinaryTree(temp -> right);
	return;
}
Node *Removes_leaves_Binary_tree(Node *& root)
{
	if( root == NULL) return NULL;
	else if( root -> left == NULL && root -> right == NULL)
	{
		return NULL;
	}
	root -> left = Removes_leaves_Binary_tree( root -> left );
	root -> right = Removes_leaves_Binary_tree( root -> right );
	return root;
}
int diameter1(Node *& root)
{
	if( root == NULL) return 0;

	int ld = diameter1( root -> left);
	int rd = diameter1( root -> right);

	int lh = heightBinaryTree(root -> left);
	int rh = heightBinaryTree (root -> right);

	int myDia = max( lh + rh + 2 , max( ld , rd));
	return myDia;
}
//*******diameter 2**

pair<int , int > diameter2(Node *& root)   //height , diameter
{
	if( root == NULL)
	{
		return { -1 , 0 } ;//(pair<int , int >( -1 , 0 ));
	}
	pair<int , int > l_pair = diameter2( root -> left);
	pair<int , int > r_pair = diameter2( root -> right );

	int l_he = l_pair.first;
	int r_he = r_pair.first;
	int l_dia = l_pair.second;
	int r_dia = r_pair.second;

	int final_hei = max( l_he , r_he) + 1;
	int final_dia = max( l_he + r_he + 2 , max( l_dia, r_dia));

	return (pair<int, int> (final_hei , final_dia));
}
int main()
{    int n;
    cin >> n;
    vector<string> tree(n);
    for(int i = 0 ; i < n ; i++)
    {
        cin >> tree[i];
    }
    vector<int>arr(n);
    for(int i = 0 ; i < n ; i++)
    {
        if( tree[i] != "n")
        {
            arr[i] = stoi(tree[i]);
        }
        else
        {
            arr[i] = -1;
        }
    }
    // for(int i = 0 ; i < n ; i++)
    // {
    //     cout<<arr[i] << " ";
    // }
    Node * root = construct(arr);
    //display(root);

    // cout << "size : " << sizeBinaryTree(root) << endl;
    // cout << "sum : " << sumBinaryTre(root) << endl;
    // cout << "max : " << maxBinaryTree(root) << endl;
    // cout << "height : " << heightBinaryTree(root) << endl; 

    // int val; cin >> val;
    // bool ans = find(root , val);
    // if( ans == 0) cout << "false";
    // else cout << "true"; cout<<endl;

    
    // vector<int> anss = nodeToRootPath( root , val);
    // for(auto an : anss)
    // {
    // 	cout << an << " ";
    // }

    //PrePostAndInOrder(root);

    // int k ; cin >> k; 
    // printKlevelsDown(root , k);
    
    //levelOrderBinaryTree(root);

    // root = createLeftCloneTree(root);
    // display(root);

    // root = transformToNormalFromLeftCloned( root );
    // display(root);

    // int li ; cin >> li;
    // int ri ; cin >> ri;
    // path_From_Root_Leaf_Sum_In_Range( root , "" , 0 , li , ri );

    //print_single_child_BinaryTree( root );
    
    // root = Removes_leaves_Binary_tree( root );
    // display( root );

    //cout << diameter1( root );

    pair<int , int > ans = diameter2( root );
    cout << ans.second;
    return 0 ;
}
//19
//50 25 12 n n 37 30 n n n 75 62 n 70 n n 87 n n
