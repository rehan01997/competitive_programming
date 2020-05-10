#include<bits/stdc++.h>
using namespace std;
int total_paths( int * jumps , int n)
{
    int dp[ n ] = {0};
    dp[ n - 1 ] = 1;

    for(int i = n - 2 ; i >=0 ; i--)
    {
        if(jumps[i] != 0)
        {
            int count = 0;
            for(int j = i + 1 ; j < n && j <= i + jumps[i] ; j++ )
            {
                count += dp[j];
            }
            dp[ i ] = count;
        }       
    }
    return dp[ 0 ];
}
int main()
{
    int n ; 
    cin>>n;

    int jumps[n];
    for(int i = 0 ; i < n ; i++)
    {
        cin >> jumps[i];
    }
    int ans = total_paths( jumps , n);
    cout<< ans;
    return 0;
}