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
//************************************
int size = 0;   ///global
Node *head = NULL;  //global
Node *tail = NULL;   //global
//**************************************

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
int getValuein(int idx)
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
    }else
    {
        cout<<"Invalid Arguments";
        return -1;
    }  
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
//************************************************
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
    int push( int val )
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
int main()
{   
    AddLast( 10);
    AddLast( 20);
    AddLast( 30);
    AddLast(40);
    AddLast(50);
    display();
    
    //removeFirst(); display();
    
    //cout << getValuein(1);
    // addFirst(80); display();

    // addAtIdx( 80 , 0); display();
    // addAtIdx( 100 , 3); display();
    //addAtIdx( 120 , 1); display();

    //cout<<tail->data;
    
    //removeLast();display();

    // removeAtIdx(0);display();
    // removeAtIdx(1);display();
    //removeAtIdx(2);display();

    //reverseDataIterative() ; display();
    
    //reversePointerIterative(); display();

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

    cout << midLL();
    return 0;
}