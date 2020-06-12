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
void AddLast( Node *& head , int val)
{
    if( head == NULL)
    {
        Node * n = new Node(val);        
        n->next = head;
        head = n;
        return;
    }
    Node *tail = head;
    while(tail -> next != NULL)
    {
        tail = tail->next;
    }
    tail -> next = new Node(val);
    return;
}
void display(Node *head)
{
    while(head != NULL)
    {
        cout<<head->data<<" "; 
        head = head->next;
    }cout<<endl;
}
int  main()
{
    Node *head = NULL;
    AddLast(head , 10);
    AddLast(head , 20);
    AddLast(head , 30);
    display(head);
}