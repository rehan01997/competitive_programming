#include<bits/stdc++.h>
using namespace std;

int ans = 0;
void merge( int i , int j , int mid , vector<int>&arr)
{
    vector<int>temp;
    int it1 = i;
    int it2 = mid+1;


    while( (it1 <= mid) && (it2 <= j) )
    {   
        if( arr[it1] <= arr[it2] ) 
        {
            temp.push_back(arr[it1++]);
        }
        else if( arr[it1] > arr[it2] )
        {
            temp.push_back(arr[it2++]);
            int t = (mid - it1) ;
             ans += t+1;          
        }  
    }
    while( it1 <= mid) temp.push_back(arr[it1++]);
    while( it2 <= j ) temp.push_back(arr[it2++]);

    for(auto x : temp) arr[i++] = x;
}
void mergesort(int i , int j , vector<int>&arr )
{
    if( i < j)
    {
        int mid = (i+j)/2 ;
        mergesort( i , mid , arr );
        mergesort( mid+1 , j , arr );
        merge( i , j , mid , arr);
    }
    return;
}
int main()
{
    int n; cin >> n;
    vector<int>arr(n,0);

    for(int i = 0 ; i < n ; i++) cin >> arr[i];
    mergesort(0 , n-1 , arr);    
    cout << ans;
    return 0;
}
