#include<bits/stdc++.h>
using namespace std;

int stair_dp_memo( int n , int *dp)
{
    //base caase
    if( n == 0) return 1;
    else if( dp[n] != 0) return dp[n];

    int count = 0;
    for(int i = 1 ; n - i >= 0 && i <= 3 ; i++)
    {
        count += stair_dp_memo( n - i , dp );
    }
    dp[n] = count;
    return count;
}

int main()
{
    int n ; 
    cin>> n ;
    int dp[ n + 1 ] = {0};
    int ans = stair_dp_memo( n , dp);
    cout<< ans;
    return 0;
}