#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int data;
        Node *next;
    Node(int d)
    {
        data = d;
        next = NULL;
    }   
};
class LL
{
public:
//************************************
int size;   ///global
Node *head;  //global
Node *tail;   //global
//**************************************
LL()  
{
    size = 0;
    head = NULL;
    tail = NULL;
}
void addFirst(int val)
{
    if( head == NULL)
    {
        Node *t = new Node(val);
        head = t;
        tail = t;
    }
    else
    {
        Node *t = new Node(val);
        t -> next = head;
        head = t;
    }
    size++;
    return;
}
void addAtIdx( int val , int idx)
{
    if( idx == 0) addFirst(val);
    else if( idx == size - 1)
    {
        Node * temp = new Node(val);
        tail ->next = temp;
        temp->next = NULL;
    }
    else if( idx < size)
    {
        Node * temp = head;
        while(idx - 1 > 0 )
        {
            temp = temp->next;
            idx --;
        }
        Node * n = new Node(val);
        n->next = temp->next;
        temp->next = n;
    }
    else
    {
        cout<<"Invalid Arguments";
    }    
    size++;
    return;    
}
void AddLast(int val)
{
    if( head == NULL)
    {
        Node * n = new Node(val);        
        n->next = head;
        head = n;
        tail = n;
        size++;
        return;
    }
    //Node *tail = head;
    while(tail -> next != NULL)
    {
        tail = tail->next;
    }
    Node * n = new Node(val);
    tail -> next = n;
    tail = n;
    size++;
    return;
}
void removeFirst()
{
    if(head == NULL)
    {
        cout <<"List is empty"<<endl;
        return;
    }
    if( head->next == NULL)
    {
        head = NULL;
        tail = NULL;        
    }
    else
    {
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
    }
    size--;
    return;
}
void removeAtIdx(int idx)
{
    if(head == NULL)
    {
        cout<< "List is empty";
        return;
    }
    else if(idx >= size || idx < 0)
    {
        cout<<"Invalid Arguments";
        return;
    } 
    else if(idx == 0)
    {
        removeFirst();
        return;
    }
    else if( idx == size - 1)
    {
        removeLast();
        return;
    }
    else
    {
        Node * temp = head;
        while( idx - 1 > 0)
        {
            temp = temp->next;
            idx --;
        }
        temp->next = temp->next->next;
        size --;
    }
}
void removeLast()
{
    if(head == NULL)
    {
        cout<<"List is empty";
        return;
    }
    else if( head->next == NULL)
    {
        head = NULL;
        tail = NULL;
    }
    else
    {
        Node *temp = head;
        while( temp -> next != tail)
        {
            temp = temp -> next;
        }
        temp->next = NULL;
        tail = temp;
    }
    size --;
    return;
}
void display()
{
    if( head == NULL)
    {
        cout<<"list is empty";
        return;
    }
    Node *temp = head;
    while(temp != NULL)
    {
        cout<<temp->data<<" "; 
        temp = temp->next;
    }cout<<endl;
    return;
}
int getFirst()
{
    if( size == 0 )
    {
        cout << "List is empty";
        return -1;
    }
    return head -> data;
} 
int getLast()
{
    if( size == 0)
    {
        cout << "List is empty";
        return -1;
    }
    else return tail -> data;
}
int getAt(int idx)
{
    if( head == NULL)
    {
        cout<<"List is empty";
        return -1;
    }
    else if( idx < size)
    {
        Node *temp = head;
        while(idx != 0)
        {
            temp = temp->next;
            idx -- ;
        }
        return temp->data;
    }
    else
    {
        cout<<"Invalid Arguments";
        return -1;
    }  
}
//******************REVERSE******************************
Node * getNodeAt( int idx)
{
    Node *temp = head;
    for(int i = 0 ; i < idx ; i++)
    {
        temp = temp -> next;
    }
    return temp;
}
void reverseDataIterative()
{
    int li = 0;
    int ri = size -1;
    
    while (li < ri)
    {
        Node * left = getNodeAt( li );
        Node * right = getNodeAt( ri );
        int temp = left->data;
        left->data = right->data;
        right->data = temp; 

        li++; ri--;
    }  
}
void reversePointerIterative()
{
    if( size <= 1) return;

    Node *prev = NULL;
    Node *curr = head;

    //tail = head;
    while( curr != NULL) 
    {   
        Node *temp = curr->next;
        curr -> next = prev;
        prev = curr;
        curr = temp;
    }
    Node * t = head;
    head = tail;
    tail = t;
}
int Kth_Node_From_lastL( int k )    //k - 0 , size - 1
{
    Node * slow = head;
    Node * fast = head;
    
    for(int i = 0 ; i < k ; i++)
    {
        fast = fast->next;
    }
    while( fast != tail)
    {
        slow = slow -> next;
        fast = fast -> next;
    }
    return slow->data;
}
int midLL()
{
    if( size == 0)
    {
        cout << "List is empty";
        return -1;
    }
    Node * slow = head;
    Node * fast = head;
    while( fast != tail && fast->next != tail)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow->data;
}
list<int> mergetwo( list<int>&l1 , list<int>&l2)
{
    list<int> ans ;
    auto it1 = l1.begin();
    auto it2 = l2.begin();
    while( it1 != l1.end() && it2 != l2.end() )
    {
        if( *it1 < *it2 ) { ans.push_back( *it1 ); it1++; }
        else if( *it1 > *it2 ){ ans.push_back( *it2 ) ; it2++; }
    }
    while( it1 != l1.end())  { ans.push_back( *it1 ); it1++; }
    while( it2 != l2.end())  { ans.push_back( *it2 ); it2++; }

    return ans;
}
list<int>sort_using_tree( list<int> l , int i , int j)    // o(nlogn)   //used inbuild LL
{
    if( i == j)     //Base
    {
        list<int> base;
        int c = 0;
        auto it = l.begin();
        while( it != l.end())
        {   
            if( c == i )
            {
                base.push_back( *it);
                break;
            }
            c++; it++;
        }
        return base;
    }

    list<int>recAns;
    int mid = ( i + j)/2;
    list<int>left = sort_using_tree( l , i, mid);
    list<int>right = sort_using_tree( l , mid + 1 , j);

    recAns = mergetwo( left , right);
    return recAns;
}
void remove_duplicates()
{
    if(head == NULL ) return;

    Node *curr = head;
    while( curr->next != NULL )
    {
        if(curr->data == curr->next->data){ curr->next = curr->next->next;}
        else curr = curr->next;
    }
    return;
}
void odd_evenLL()    //changes to original LL
{
    if( head == NULL) return;
    LL *odd = new LL();
    LL *even = new LL();

    while( this->size > 0 )
    {
        int val = this->getFirst();
        this->removeFirst();

        if( val % 2 == 0) even->AddLast( val);
        else odd->AddLast( val );
    }
    if( odd->head != NULL && even->head != NULL)
    {
        this->head = odd->head;
        odd->tail->next = even->head;
        this->tail = even->tail;
    } 
    else if( odd->head != NULL)
    {
        this->head = odd->head;
        this->tail = even->tail;  
    } 
    else
    {
        this->head = even->head;
        this->tail = even->tail;
    }  
    this->size = odd->size + even->size;
}
//***************k reverse*********
void reverseDI( int li  , int ri)
{
    while (li < ri)
    {
        Node * left = getNodeAt( li );
        Node * right = getNodeAt( ri );
        int temp = left->data;
        left->data = right->data;
        right->data = temp; 

        li++; ri--;
    } 
    return;
}
void kreverse( int k )     
{
    //int no_t = k/size;
    int i = 0;
    int j;
    while( (i + k - 1) < size - 1)
    {
        j = i + k - 1;
        reverseDI( i , j);
        i += k;
    }
    return;
}
void display_reverse(Node *& node )    //withyout changing original list
{   
    if(node == NULL) return;
    Node *temp = node;
    //int temp_val = temp->data;
    if( temp -> next != NULL)
    {
        display_reverse( temp -> next);
    }
    cout << temp -> data<<" ";
    return;
}
void reverseLLDATARecursive(int li , int ri)
{
    if( li >= ri) return;

    reverseLLDATARecursive( li + 1 , ri - 1);
    Node *t1 = this->getNodeAt( li );
    Node *t2 = this->getNodeAt( ri );
    int temp = t1->data;
    t1->data = t2 ->data;
    t2->data = temp;
    return;
}
Node* reversePOinterRecursive(Node *node)
{
    if( node == NULL) return NULL;
    if( node -> next == NULL)
    {
        this->head = node;
        return node;
    }
    Node *node1 = reversePOinterRecursive( node -> next);
    node1 -> next = node;
    node -> next = NULL;
    tail = node;
    return node;
}
Node* midNode()
{
    if( size == 0) return NULL;
    Node * slow = head;
    Node * fast = head;
    while( fast != tail && fast->next != tail)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}
bool IsPalindrome()
    {
       if(this->size <= 1) return true;
       
       Node *mid = midNode();
       LL * nlist = new LL();
       nlist->head = mid->next;
       nlist->tail = this->tail;
       nlist->size = this->size / 2;
       this->tail = mid;
       mid->next = NULL;
       
       nlist-> reverseDataIterative();
       
       Node *t1 = this->head;
       Node *t2 = nlist->head;
       
       bool isPalin = true;
       while(t1 != NULL && t2 != NULL)
       {
           if(t1->data != t2->data)
           {
               isPalin = false;
               break;
           }
           else
           {
               t1 = t1->next;
               t2 = t2->next;
           }
       }
       
       nlist->reverseDataIterative();
       mid->next = nlist->head;
       this->tail = nlist->tail;
       this->size = this->size + nlist->size;
       
       return isPalin;
    }
    //***************** ADD two linked list******
    int add2ListHelper( Node *n1 , Node *n2 , int pvn1 , int pvn2 , LL*ans)
    {
        if( n1 == NULL && n2 == NULL) return 0;
        
        if(pvn1 == pvn2)
        {
            int carry = add2ListHelper( n1->next , n2->next , pvn1 - 1, pvn2 - 1 , ans);
            int num = carry + n1->data + n2->data;
            ans->addFirst( num % 10);
            return num / 10;
        }
        else if( pvn1 > pvn2)
        {
            int carry = add2ListHelper( n1->next , n2 , pvn1 - 1 , pvn2 , ans);
            int num = n1->data + carry;
            ans->addFirst( num % 10);
            return num / 10;
        }
        else
        {
            int carry = add2ListHelper( n1 , n2->next , pvn1 , pvn2 - 1 , ans);
            int num = n2->data + carry;
            ans->addFirst( num % 10 );
            return num / 10;
        }
    }
    LL *addTwoLists(LL* n1, LL* n2)
    {
      LL* ans = new LL();
      
      int carry = add2ListHelper( n1->head , n2->head , n1->size , n2->size  , ans);
      
      if(carry > 0) ans->addFirst(carry);
      return ans;
    }
};
//*******************_LinkedList_to_Stack_Adapter*******
class Linked_list_To_Stack
{
    public:
    list<int>LinkedList;
    int size()
    {
        return LinkedList.size();
    }
    void push( int val)
    {
        LinkedList.push_back( val );
    }
    int pop()
    {
        if( LinkedList.size() == 0)
        {
            cout << "Stack underflow";
            return -1;
        }
        int pop_val = LinkedList.back();
        LinkedList.pop_back();
        return pop_val;
    }
    int top()
    {
        if(LinkedList.size() == 0)
        {
            cout<<"Stack underflow";
            return -1;
        }
        return LinkedList.back();
    }
};
//********************LinkedList to Queue_adapter******
class Linked_List_To_Queue
{
    public:
    list<int>LinkedList;

    int size()
    {
        return LinkedList.size();
    }
    void push( int val )
    {
        LinkedList.push_back( val );
    }
    int pop()
    {
        if( LinkedList.size() == 0)
        {
            cout << "Queue underflow";
            return -1;
        }
        int pop_val = LinkedList.front();
        LinkedList.pop_front();
        return pop_val;
    }
    int top()
    {
        if(LinkedList.size() == 0)
        {
            cout << "Queue underflow";
            return -1;
        }
        return LinkedList.front();
    }
    
};
int main()
{   LL *llist = new LL();
    // int n ; cin >> n;
    //  for(int i = 0 ; i < n ; i++) { int no ; cin >> no ; llist->AddLast( no ); }// llist->display();
    // llist->AddLast( 10);
    // llist->AddLast( 20);
    // llist->AddLast( 30);
    // llist->AddLast(40);
    // llist->AddLast(50);
    // llist->display();
    
    //llist->removeFirst(); llist->display();
    
    //cout << llist->getAt(1);
    // llist->addFirst(80); llist->display();

    // llist->addAtIdx( 80 , 0); llist->display();
    // llist->addAtIdx( 100 , 3); llist->display();
    // llist->addAtIdx( 120 , 1); llist->display();

    // cout<<llist->tail->data;
    
    //llist->removeLast();llist->display();

    // llist->removeAtIdx(0);llist->display();
    // llist->removeAtIdx(1);llist->display();
    //llist->removeAtIdx(2);llist->display();

    //llist->reverseDataIterative() ; llist->display();
    
    //llist->reversePointerIterative(); llist->display();

    //********lINKED lISST TO Stack********
    // Linked_list_To_Stack *LLtoSTACK = new Linked_list_To_Stack();
    // LLtoSTACK->push(10);
    // LLtoSTACK->push(20);
    // LLtoSTACK->push(30);
    // cout << LLtoSTACK->top() << endl; //30
    // cout << LLtoSTACK->size() << endl; //3
    // cout << LLtoSTACK->pop() << endl; //30
    // cout << LLtoSTACK->top() << endl; //20

    //*********LINKED_LIST_To_QUEUE************
    // Linked_List_To_Queue * LLtoQueue = new Linked_List_To_Queue();
    // LLtoQueue->push(10);
    // LLtoQueue->push(20);
    // LLtoQueue->push(30);
    // cout << LLtoQueue->top() << endl; //10
    // cout << LLtoQueue->pop() << endl; //10
    // cout << LLtoQueue->top() << endl; //20

    // int k; cin >> k;
    // cout << Kth_Node_From_lastL(k);

    //cout << midLL();

    //***************Merge Two LL ***************
    // int n1 , n2;
    // cin >> n1;
    // list<int>l1;   //inbuild
    // list<int>l2;    //inbuild
    // for(int i = 0 ; i < n1 ; i++) 
    // {
    //     int no; cin >> no;
    //     l1.push_back( no );
    // } 
    // cin >> n2;
    // for(int i = 0 ; i < n2 ; i++) 
    // {
    //     int no; cin >> no;
    //     l2.push_back( no );
    // }
    // list<int> ans = llist->mergetwo( l1 , l2);
    // list<int>::iterator it;
    // for(it = ans.begin() ; it != ans.end() ; it++) cout << (*it) <<  " ";
    // cout << endl;
    // for(it = l1.begin() ; it != l1.end() ; it++) cout << (*it) <<  " ";
    // cout << endl;
    // for(it = l2.begin() ; it != l2.end() ; it++) cout << (*it) <<  " ";
    // cout << endl;

    //***********Sort Using Recursion tree*************
    // int n;
    // cin >> n;
    // list<int>l1;
    // for(int i = 0 ; i < n ;i++)
    // {
    //     int no; cin >> no;
    //     l1.push_back(no);
    // }
    // list<int>ans = llist->sort_using_tree( l1 , 0 , l1.size() - 1);
    // for(auto it = ans.begin() ; it != ans.end() ; it++) cout << *it << " ";

    //***********remove duplicates*************
    // int n; cin >> n;
    // for(int i = 0 ; i < n ; i++)
    // {   
    //     int val;
    //     cin >> val;
    //     llist->AddLast( val );
    // }
    // llist->remove_duplicates();
    // llist->display();

    //***********odd even LL******
    // int n ; cin >> n;
    // for(int i = 0; i < n ; i++) { int no ; cin >> no ; llist->AddLast( no );}
    // llist->odd_evenLL();
    // llist->display();
    // int no ; cin >> no; 
    // llist->addFirst( no );
    // cin >>no;
    // llist->AddLast( no );
    // llist->display();

    //*******k reverese****
    // int n ; cin >> n;
    // for(int i = 0 ; i < n ; i++) { int no ; cin >> no ; llist->AddLast( no );} llist->display();
    // int k ; cin >> k;
    // llist->kreverse( k ); llist->display();
    
    //***********diaply reverse**
    // llist->display_reverse(llist->head); cout <<endl;
    // int no ; cin >> no; 
    // llist->AddLast( no );
    // cin >>no;
    // llist->addFirst( no );
    // llist->display();

    //**************reverseLLusing Data and POinter recursive******
    // llist->reverseLLDATARecursive( 0 , llist->size - 1);// llist->display();
    // int no ; cin >> no; 
    // llist->AddLast( no );
    // cin >>no;
    // llist->addFirst( no );
    // llist->display();

    // Node * temp = llist->reversePOinterRecursive( llist->head );//  llist->display();
    // int no ; cin >> no; 
    // llist->AddLast( no );
    // cin >>no;
    // llist->addFirst( no );
    // llist->display();        
     
     //***isaplindrome**
    // bool palin = llist->IsPalindrome();
    // if( palin ) cout << "true";
    // else cout << "false";

    // LL *list1 = new LL();
    // LL *list2 = new LL();
    // int n ; cin >> n;
    // for(int i = 0 ; i < n ; i++) { int no; cin >> no; list1->AddLast( no ) ;}
    // cin >> n; 
    // for(int i = 0 ; i < n ; i++) { int no; cin >> no; list2->AddLast( no ) ;}

    // LL *ans  = llist->addTwoLists( list1 , list2);
    // ans->display();

    return 0;
}    