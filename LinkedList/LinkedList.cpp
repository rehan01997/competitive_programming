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
int  main()
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

    reverseDataIterative() ; display();
    return 0;
}