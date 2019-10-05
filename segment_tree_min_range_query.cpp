#include <bits/stdc++.h>

using namespace std;
void buildtree(int *arr,int *tree,int index,int s,int e)
{
    if(s>e)
    {
        return ;
    }
    //Base case
    if(s==e)
    {
        tree[index]= arr[s];
        return;
    }
    int mid=(s+e)/2;
    buildtree(arr,tree,2*index,s,mid);
    buildtree(arr,tree,2*index+1,mid+1,e);

    tree[index]=min(tree[2*index],tree[2*index+1]);
    return;
}
int query(int *tree,int index,int s,int e,int qs,int qe)
{
    if(qs>e || qe<s)
    {
        return INT_MAX;
    }
    //base case
    if(s>=qs && e<=qe){
        return tree[index];
    }
    int mid=(s+e)/2;
    int leftans=query(tree,2*index,s,mid,qs,qe);
    int rightans=query(tree,2*index+1,mid+1,e,qs,qe);
    return min(leftans,rightans);
}
void updatenode(int *tree,int index,int s,int e,int i,int val)
{
    if(i<s || i>e){
        return;
    }
    //Base case
    if(s==e)
    {
        tree[i] = val;
        return;
    }
    int mid=(s+e)/2;
    updatenode(tree,2*index,s,mid,i,val);
    updatenode(tree,2*index+1,mid+1,e,i,val);

    tree[index]=min(tree[2*index],tree[2*index+1]);
    return ;
}
void updaterange(int *tree,int index,int s, int e,int rs,int re,int inc)
{
    if(re<s || rs>e)
    {
        return;
    }
    //base case
    if(s==e)
    {
        tree[index]+= inc;
        return;
    }
    int mid=(s+e)/2;
    updaterange(tree,2*index,s,mid,rs,re,inc);
    updaterange(tree,2*index+1,mid+1,e,rs,re,inc);

    tree[index]=min(tree[2*index],tree[2*index+1]);
    return;
}
int main()
{
    int arr[]={1,3,2,4,3,-2,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    int *tree=new int[4*n + 1];

    buildtree(arr,tree,1,0,n-1);
    int no_of_queries;
    int qs,qe;
    cin>>no_of_queries;
    while(no_of_queries--)
    {
        cin>>qs>>qe;
        cout<<query(tree,1,0,n-1,qs,qe);
    }
    for(int i=1;i<7;i++)
    {

        cout<<tree[i]<<"---";
    }
    cout<<endl;
    updatenode(tree,1,0,n-1,3,5);
    for(int i=1;i<7;i++)
    {

        cout<<tree[i]<<"---";
    }
    return 0;
}
