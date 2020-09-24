#include<bits/stdc++.h>
using namespace std;

void solve( vector<int>& arr1 , vector<int>&arr2 , int n , int m)
{
    int i = 0 , j = 0;
    
    for ( int gap = (n+m)/2+(n+m)%2 ; gap > 0 ; gap = gap/2+gap%2 )
    {
        
        for( i = 0 ; i+gap < n ; i++)
        {
            if( arr1[i] > arr1[i+gap] ) swap( arr1[i] , arr1[i+gap] );
        }
        //for both arr1 and arr2  
        if( gap > n) j = gap - n;
        else j = 0;

        for( j ; i < n && j < m ; i++,j++)
        {
            if(arr1[i] > arr2[j]) swap( arr1[i] , arr2[j] );
        }
        for( j ; j+gap < m ; j++ )
        {
            if( arr2[j] > arr2[j+gap] ) swap( arr2[j] , arr2[j+gap] );
        }        
        if( gap <= 1) break;
    }
}
int main()
{
    int n , m ;
    cin >> n >> m;

    vector<int>arr1(n,0);
    vector<int>arr2(m,0);

    for(int i = 0 ; i < n ; i++) cin >> arr1[i];
    for(int i = 0 ; i < m ; i++) cin >> arr2[i];


    solve( arr1, arr2 , n , m);

    for(auto e : arr1) cout << e << " ";
    cout << endl;
    for( auto e : arr2) cout << e << " ";
    return 0;
}