    #include<bits/stdc++.h>
    using namespace std;
    class Node
    {
        public:
            int data;
            vector<Node*>children;
    };
    Node *root = NULL; //global

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
    void levelOrderLineWiseZigZag(Node *& root)
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
    int distanceBetweenTwoNodes( int d1 , int d2)
    {
        vector<int>listA = nodeToRootPath(root , d1);
        vector<int>listB = nodeToRootPath(root , d2);
        int i = listA.size() - 1 ;
        int j = listB.size() - 1;
        while( i >= 0 && j >= 0 && listA[i] == listB[j] )
        { 
            i-- ; j--;
        }
        return (i + 1) + ( j + 1);
    }
    Node* construct1( vector<int> arr)
    {
        stack<Node*> st;
        Node *troot = NULL;
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
                    troot = t;
                }        
                st.push(t);
            }
        }
        return troot;
    }
    bool AreSimilarTrees(Node *& r1 , Node *& r2)
    {
        bool isSimilar = true;
        if( r1->children.size() != r2->children.size() )
        {
            return false;
        }
        for(int i = 0 ; i < r1->children.size() ; i++)
        {
            bool recAns = AreSimilarTrees(r1->children[i] , r2->children[i]);
            if(recAns == false) return false;
        }
        return isSimilar;
    }
    bool AreTreeMirror(Node *& r1 , Node *& r2)
    {
        if(r1->children.size() != r2->children.size()) 
        {
            return false;
        }
        for(int i = 0 ; i < r1->children.size() ; i++)
        {
            bool recAns = AreTreeMirror( r1->children[i] , r2->children[r2->children.size() - 1 - i]);
            if( recAns == false)
            {
                return false;
            }
        }
        return true;
    }
    bool isTreeSymmetric(Node * temp)
    {
        for(int i = 0 , j = temp->children.size() - 1 ; i <= j ; i++ , j--)
        {
            bool ans = AreTreeMirror( temp->children[i] , temp->children[temp->children.size() - 1 -i]);
            if( !ans) return false;
        }
        return true;
    }

    int ceill_ = INT_MAX;
    int floorr_ = INT_MIN;
    void Ceil_Floor(Node *temp , int val)
    {   
        if(temp->data > val)
        {
            if(temp->data < ceill_)
            { ceill_ = temp->data;
            }
        }
        if( temp->data < val)
        {
            if( temp->data > floorr_)
            { floorr_ = temp->data;}
        }        
        for(int i = 0 ; i < temp->children.size() ; i ++)
        {
            Ceil_Floor(temp->children[i] , val );
        }
        return;
    }
    int kthLargest(Node *& temp , int k)
    {
        int data = INT_MAX;
        for(int  i = 0 ; i < k ; i ++)
        {   
            floorr_ = INT_MIN;
            Ceil_Floor( temp , data);
            data = floorr_;
        }
        return data;
    }
//*****************************************
    int max_ans = INT_MIN;
    int node_val = 0;
    int NodeWithMaximumSubtree(Node *& temp)
    {
    	int sum = temp->data;
    	//int s1 = INT_MIN;

    	for(int i = 0 ; i < temp->children.size() ; i++)
    	{
    		sum += NodeWithMaximumSubtree(temp->children[i]);    		
    		//if( s1 < recAns) s1 = recAns;
    	}
    	if( max_ans < sum)
    	{
    		max_ans = sum;
    		node_val = temp->data;
    	}
    	return sum;
    }
//*****************************************
  
//***************************************
    Node* predecessor = NULL ;
    Node* successor = NULL;
    int state = 0;
    void predecessor_sucessor(Node *& temp , int val)
    {
    	if(state == 0)
    	{
    		if(temp->data == val)
    		{
    			state++;
    		}
    		else
    		{
    			predecessor = temp;
    		}
    	}
    	else if( state == 1)
    	{
    		successor = temp;
    		state++;
    	}
    	else if(state == 2)
    	{
    		return;
    	}
    	for(int i = 0 ; i < temp->children.size() ; i++)
    	{
    		predecessor_sucessor(  temp->children[i] , val);
    	}
    	return;
    }
//**************************************************
    Node *getTail(Node* temp)
    {
    	while(temp->children.size() > 0)
    	{
    		temp = temp->children[0];
    	}
    	return temp;
    }
    void linearizeGenericTree(Node * &temp)
    {
    	for(int i = 0 ; i < temp->children.size() ; i++)
    	{
    		linearizeGenericTree(temp->children[i]);
    	}
    	while(temp->children.size() > 1)
    	{
    		Node* slastTail = getTail(temp->children[temp->children.size() - 2]);
    		Node* lastTail = temp->children[temp->children.size() - 1];
    		temp->children.pop_back();
    		slastTail->children.push_back(lastTail);
    		//temp->children.pop_back();
    	}
    	return;
    }    
//******************************************************
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
    ///levelOrderLineWiseZigZag(root);

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

        // mirrorGenericTree(root); display(root);
        // int d1,d2;
        // cin >> d1 >>d2;
        // cout<<distanceBetweenTwoNodes(d1,d2);


        //***************** INPUT OF TWO GENERIC TREE**************
        // int n1 , n2;
        // cin >> n1;
        // vector<int>arr1(n1); 
    
        // for(int i = 0 ; i < n1 ; i++)
        // {
        //     cin >> arr1[i];	
        // }
        // cin >> n2;
        // vector<int>arr2(n2);
        // for(int i = 0 ; i < n2 ; i++)
        // {
        //     cin >> arr2[i];	
        // }
        // Node *r1 = construct1( arr1 ); 
        // Node *r2 = construct1( arr2 ); 
    //************************************************************

        // bool anss = AreSimilarTrees(r1 , r2);
        // if(anss == true) cout<<"true";
        // else cout << "false";

        // bool anss = AreTreeMirror(r1 , r2);
        // if(anss == true) cout<<"true";
        // else cout << "false";

        // bool anss = isTreeSymmetric(root);
        // if(anss == true) cout<<"true";
        // else cout << "false";
        
        // int val; cin>>val;
       
        // Ceil_Floor(root , val );
        // cout<< "CEIL = " << ceill_ << endl;
        // cout<< "FLOOR = " << floorr_ ;
        
        // //********************
        // int k; cin >> k;
        // int ans = kthLargest( root , k);
        // cout << ans;
       // display();


        // int nul = NodeWithMaximumSubtree(root);
        // cout<<node_val<<"@"<<max_ans;
        
        // int nul = diameterOfGenericTree(root);
        // cout<<dia;

  //       int val ; cin >>val ;
  //       predecessor_sucessor(root , val);
  //       if( predecessor == NULL) cout<<"Predecessor = Not found";
  //       else cout << "Predecessor = "<<predecessor->data<<endl;
		// if(successor == NULL) cout <<"Successor = Not found";
		// else cout<<"Successor = " << successor->data;
        display(root);
        linearizeGenericTree(root);
        display(root);

        return 0;
    }
    // 12
    // 10 20 -1 30 50 -1 60 -1 -1 40 -1 -1
