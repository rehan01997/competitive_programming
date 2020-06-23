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
	st.push( { root , 0 });

	string preOrder = "";
	string postOrder = "";
	string inOrder = "";
	while(!st.empty())
	{
		pair<Node* , int > curr= st.top();
		
		if(curr.second == 0)
		{	
			st.pop();
			st.push({ curr.first , curr.second + 1});
			preOrder += curr.first->data + " ";
		}	
		else if(curr.second == 1)
		{	//left
			st.pop();
			st.push({ curr.first , curr.second + 1});
			if( curr.first->left != NULL)
			{
				st.push({ curr.first->left , 0 });
			}
		}
		else if( curr.second == 2)
		{
			st.pop();
			st.push({ curr.first , curr.second + 1});
			inOrder += curr.first->data + " ";
		}
		else if(curr.second == 3)
		{	
			//right
			st.pop();
			st.push({ curr.first , curr.second + 1});
			if( curr.first->right != NULL)
			{
				st.push({ curr.first->right , 0 });
			}
		}
		else
		{			
			//st.push({ curr.first , curr.second + 1 });
			// st.pop();
			// st.push({ curr.first , curr.second + 1});
			postOrder += curr.first->data + " ";
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
int main()
{
    int n;
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

    cout << "size : " << sizeBinaryTree(root) << endl;
    cout << "sum : " << sumBinaryTre(root) << endl;
    cout << "max : " << maxBinaryTree(root) << endl;
    cout << "height : " << heightBinaryTree(root) << endl; 

    // int val; cin >> val;
    // bool ans = find(root , val);
    // if( ans == 0) cout << "false";
    // else cout << "true"; cout<<endl;

    
    // vector<int> anss = nodeToRootPath( root , val);
    // for(auto an : anss)
    // {
    // 	cout << an << " ";
    // }

   // PrePostAndInOrder(root);

    // int k ; cin >> k; 
    // printKlevelsDown(root , k);
    
    //levelOrderBinaryTree(root);

    return 0 ;
}
//19
//50 25 12 n n 37 30 n n n 75 62 n 70 n n 87 n n
