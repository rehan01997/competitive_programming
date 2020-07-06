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
    //***************** IS BST ***** 
    pair<int,pair<bool, int > >bstType(Node *& temp)     //MIN --  isBst  -- MAX
    {
        if( temp == NULL) return { INT_MAX , {true , INT_MIN}};
        if( temp -> left == NULL && temp->right == NULL)  return { temp->data, { true , temp->data}};


        pair<int , pair<bool, int > >l_ans = bstType( temp -> left);
        pair<int , pair<bool, int > >r_ans = bstType( temp -> right);

        pair< int , pair <bool , int > >ans = { 0 , { false , 0}};
        
        bool isbst = false;
        if( l_ans.second.first && r_ans.second.first && temp->data > l_ans.second.second && temp->data < r_ans.first)
        {
            isbst = true;
        }
        ans.second.first = isbst;
        if( ans.second.first == true)
        {
            if( temp -> left == NULL) ans.first = temp->data;
            else ans.first = l_ans.first;

            if( temp -> right == NULL ) ans.second.second = temp->data;
            else ans.second.second = r_ans.second.second;
        }     
        return ans;
    }
    bool isBST( Node *& root)
    {
        pair<int,pair<int,int > > ans = bstType(root);
        return ans.second.first;
    }
    //************************************

    int size_bst(Node *& root)
    {
        if( root == NULL) return 0;

        int l_size = size_bst( root->left );
        int r_size = size_bst( root -> right );

        return l_size + r_size + 1;    
    }
    int sum_bst( Node *& root)
    {
        if( root == NULL) return 0;
        
        int l_Sum = sum_bst( root -> left);
        int r_sum = sum_bst( root -> right);

        return l_Sum + r_sum + root -> data;
    }
    // int maxx = INT_MIN;
    int max_bst( Node *& root)
    {   
        Node * temp = root;
        if( temp == NULL) return INT_MIN;
        while( temp -> right != NULL)
        {
            temp = temp -> right;
        }
        return temp -> data;
    }
    int min_bst( Node *& root)
    {
        Node * temp = root;
        if( temp == NULL) return INT_MAX;
        while( temp -> left != NULL)
        {
            temp = temp -> left;
        }
        return temp -> data;
    }
    bool find_bst(Node *& root , int data)
    {
        Node * temp = root;
        while( temp != NULL)
        {
            if( temp -> data == data) return true;
            else if( data > temp -> data) temp = temp ->right;
            else temp = temp -> left;
        }
        return false;  
    }
    Node * add_bst( Node *& temp , int data)
    {
        if( temp == NULL )
        {
            Node * x = new Node(data);
            return x;
        }
        if( temp -> data == data) return temp;

        if( data > temp -> data ) 
        {
            temp -> right = add_bst( temp -> right , data);
        }
        else
        {
            temp -> left = add_bst( temp -> left , data);
        }
        return temp;  
    }
    //******replce with node with the sum of largest nodes**
    int sum = 0 ;
    void rwsol(Node *& temp)
    {
        if( temp == NULL) return;
        
        rwsol( temp -> right);
        int oval = temp ->data;
        temp -> data = sum;
        sum += oval;
        rwsol( temp ->left);
        return;
    }
    Node * removeBst( Node *& root , int data)
    {
        if( root == NULL) return NULL;

        if( root -> data == data)
        {
            if( root -> left == NULL && root -> right == NULL) return NULL;
            else if( root -> left == NULL)
            {
                Node * rc = root -> right;
                root -> right = NULL;
                return rc ;
            }
            else if( root -> right == NULL)
            {
                Node * lc = root -> left;
                root -> left = NULL;
                return lc;
            }
            else
            {
                int l_max = max_bst( root -> left);
                root -> data = l_max;
                root -> left = removeBst(root->left , l_max);
            }        
        }
        else if( data > root ->data)
        {
            root -> right = removeBst( root -> right , data);
        }
        else
        {
            root -> left = removeBst( root -> left ,data);
        }
        return root;    
    }
    int lca_bst( Node *& root , int n1 ,int n2)
    {
        if( n1 > root -> data &&   n2 >  root -> data)
        {
            int ans = lca_bst( root -> right , n1 , n2 );
            return ans;
        }
        else if( n1 < root -> data && n2 < root ->data)

        {
            int ans = lca_bst( root -> left , n1 , n2);
            return ans;
        }
        else
        {
            int ans = root -> data;
            return ans;
        }   
    }
    vector<int>Print_in_Range( Node *& root , int n1 , int n2)
    {
        vector<int>ans;
        vector<int> l_ans;
        vector<int> r_ans;
        if( n1 < root -> data && root->left != NULL)
        {
            l_ans = Print_in_Range( root -> left , n1 , n2);
            for( int l : l_ans)
            {
                ans.push_back( l );
            }
        }
        if( root ->data >= n1 && root -> data <= n2)
        {
            ans.push_back( root -> data);
        } 
        if( n2 > root -> data && root->right != NULL)
        {
            r_ans = Print_in_Range( root -> right , n1 ,n2);
            for( int r : r_ans)
            {
                ans.push_back( r );
            }
        }  
         
        return ans;
    }
    //***********
    set<int>s;
    void target_Sum(Node *& root , int t_sum)
    {
        if( root == NULL) return;

        target_Sum( root -> left , t_sum);

        //int comp = t_sum - root->data;

        //if( s.find( comp ) != s.end() ) cout << comp<< " " << root->data <<endl ;
        //else
        s.insert( root -> data);
        
        target_Sum( root -> right , t_sum);
    }
    int main()
    {   int n;
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
        // bool ans = isBST(root);
        // if( ans) cout << "true";
        // else cout << "false";


        // int ele ; cin >> ele;
        // cout << size_bst( root ) << endl;
        // cout << sum_bst( root ) << endl;
        // cout << max_bst( root ) << endl;
        // cout << min_bst( root ) << endl;
        // bool ans = find_bst( root , ele);
        // if( ans ) cout <<"true";
        // else cout << "false";


        // int ele ; cin >> ele;
        // root = add_bst( root , ele );
        // display( root );
        
        // rwsol( root );
        // display( root );
        
        // int ele ; cin >> ele;
        // removeBst( root , ele);
        // display(root);

        // int n1 ,  n2;
        // cin >> n1 >> n2;
        // cout << lca_bst( root , n1 ,n2);
        
        // int n1 , n2;
        // cin >> n1 >> n2;
        // vector<int> ans = Print_in_Range( root , n1 , n2 );
        // for( int a : ans)
        // {
        //     cout << a << endl;
        // }

        int t_sum ; cin >> t_sum;
        target_Sum( root , t_sum );
        //cout << s.size();
        auto i = s.begin();
        auto j = s.rbegin();
        while( *i != *j)
        {   
            //cout << *i << " " << *j << endl;
            int sum = *i + *j; 
            if( sum == t_sum)
            {
                cout << *i << " " << *j << endl;
                i++;
                j++;
            }
            else if( sum > t_sum) j++;
            else i++;
        }
        return 0;
    }
