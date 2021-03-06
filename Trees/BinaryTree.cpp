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
vector<Node*> NTRP(Node *& temp , int data)
{
    if(temp == NULL) //base case
    {
        vector<Node*>base;
        return base;
    }
    if( temp->data == data) //base case
    {
        vector<Node*> base;
        base.push_back(temp );
        return base;
    }
    vector<Node*> ans;
    if( temp-> left != NULL)
    {
        vector<Node*> left = NTRP( temp->left , data);
        for(auto node : left)
        {
            ans.push_back(node);
        }
    }
    if(temp ->right != NULL)
    {
        vector<Node*> right = NTRP( temp -> right , data);
        for(auto node : right)
        {
            ans.push_back(node);
        }
    }
    if( ans.size() > 0) ans.push_back(temp);
    return ans;
}
void printKdown( Node *& temp , Node*& blockage , int k)
{
    if( temp == NULL ) return;    
    if( k == 0)
    {
        cout << temp ->data << endl;
        return;
    }
    if( temp -> left != blockage)
    {
        printKdown( temp -> left , blockage , k - 1 );
    }
    if( temp -> right != blockage)
    {
        printKdown( temp -> right , blockage , k- 1 );
    }
    return;
}
void printKthNodeFarFromNode (Node*& temp , int data , int k)
{
    vector<Node*> ntrp = NTRP( temp , data);
    // for(auto n : ntrp)
    // {
    //     cout << n->data << "  ";
    // }
    for(int i = 0 ; i < ntrp.size() , i <= k ; i ++)
    {
        Node * blockage = NULL;
        if( i > 0 ) blockage = ntrp[ i - 1 ];
        printKdown( ntrp[i] , blockage , k - i );
    }
    return;
}
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
//******************* diameter1 *********
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
//******* diameter 2 *******
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
//********** tilt*****
int tilt = 0;
int tilt_binary_tree(Node *& root)
{
	if( root == NULL ) return 0;

	int l_sum = tilt_binary_tree( root -> left);
	int r_sum = tilt_binary_tree( root -> right);

	int abs_diff = abs( l_sum - r_sum);
	
	tilt += abs_diff;

	return l_sum + r_sum + root -> data;
}
//***************isbalnced
bool isBalancedTree1(Node *& root)
{
	if( root == NULL) return true;

	bool l_tree = isBalancedTree1( root -> left);
	bool r_tree = isBalancedTree1( root -> right);

	int l_height = heightBinaryTree( root -> left);
	int r_height = heightBinaryTree( root -> right);

	if( abs( l_height - r_height) <= 1 && l_tree && r_tree) return true;
	return false;
}

pair<bool , int > isBalancedTree2(Node *&  root)    //isbalanced , height
{
	if(root == NULL ) return { true , -1};

	pair<bool , int > l_tree = isBalancedTree2( root -> left);
	pair<bool , int > r_tree = isBalancedTree2( root -> right);

	int l_height = l_tree.second;
	int r_height = r_tree.second;
	bool isbalanced = false;

	if( abs( l_height - r_height) <= 1 && l_tree.first && r_tree.first) 
	{
		isbalanced = true;
	}
	int final_hei = max( l_height , r_height) + 1;
	return { isbalanced , final_hei};
}
bool isBalancedTree( Node *& root)
{
	pair< bool , int> ans = isBalancedTree2( root);
	return ans.first;
}
//*******************largest bst subtree******
class lbst
{
	public:
		int minn;
		bool isbst;
		int maxx;
		int no_nodes;
};
pair<int ,int > lrgst_bst_subtree = { -1 , -1};    //node->data , no_of_ndes
lbst * largestBstsubtree( Node *& root)
{
	if( root == NULL)
	{
		lbst * base = new lbst();
		base -> minn = INT_MAX;
		base -> isbst = true;
		base -> maxx = INT_MIN;
		base -> no_nodes = 0;
		return base;
	}
	if( root ->left == NULL && root -> right == NULL)
	{
		lbst * base = new lbst();
		base -> minn = root -> data;
		base -> isbst = true;
		base -> maxx = root -> data;
		base -> no_nodes = 1;
	}

	lbst * l_ans = largestBstsubtree( root -> left);
	lbst * r_ans = largestBstsubtree( root -> right);

	lbst * ans = new lbst();
	bool isbalnced = false;
	if( l_ans -> isbst && r_ans -> isbst && root->data > l_ans->maxx
		 && root->data < r_ans->minn)
	{
		isbalnced = true;
	}
	ans -> isbst = isbalnced;
	ans -> no_nodes = l_ans->no_nodes + r_ans-> no_nodes + 1;
	if( ans -> isbst && lrgst_bst_subtree.second < ans->no_nodes)
	{
		lrgst_bst_subtree.first = root->data;
		lrgst_bst_subtree.second = ans->no_nodes; 
	}
	if( ans -> isbst)
	{
		if( root -> left == NULL) ans->minn = root->data;
		else ans->minn = l_ans->minn;

		if( root->right == NULL) ans->maxx = root->data;
		else ans->maxx = r_ans->maxx;
	}
	return ans;
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

    // int data; cin >> data;
    // int k ; cin >> k;
    // printKthNodeFarFromNode( root , data , k );

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

    // pair<int , int > ans = diameter2( root );
    // cout << ans.second;
   	
   	// tilt_binary_tree(root);
   	// cout << tilt;
    
    //NOT OPTIMISED
    // bool ans = isBalancedTree(root);
    // if( ans ) cout << "true";
    // else cout << "false";

    // //OPTIMIZED
    // bool ans = isBalancedTree( root);
    // if( ans ) cout << "true";
    // else cout << "false";
    
    lbst * ans = largestBstsubtree( root );
    cout << lrgst_bst_subtree.first << "@" << lrgst_bst_subtree.second;
    return 0 ;
}
//19
//50 25 12 n n 37 30 n n n 75 62 n 70 n n 87 n n
