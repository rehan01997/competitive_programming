#include<bits/stdc++.h>
using namespace std;

int min_jumps(int * jumps , int n)
{
    int dp[ n ] = {0};
    dp[ n - 1 ] = 0;

    for(int i = n - 2  ; i >= 0 ; i--)
    {
        if( jumps[i] == 0) dp[ i ] = INT_MAX;
        else 
        {
            int min = INT_MAX;
            for(int j = 1 ; i + j < n && j <= jumps[i] ; j++)
            {
                if( min > dp[i + j])
                {
                    min = dp[i + j];
                }
            }
            if( min == INT_MAX) dp[i] = INT_MAX; //inf
            else dp[i] = min + 1;
        }
    }
    return dp[0];
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
    int ans = min_jumps( jumps , n);
    if( ans == INT_MAX) cout<<"null";
    else cout<< ans;
    return 0;
}