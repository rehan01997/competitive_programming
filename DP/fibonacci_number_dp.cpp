#include<bits/stdc++.h>
using namespace std;
int fib_dp ( int n , int *dp)
{
    //base case
    if( n == 1 || n == 0 ) return n;
    if( dp[n] != 0) return dp[n];

    int num1 = fib_dp(n - 1 , dp);
    int num2 = fib_dp( n - 2 , dp);
    int myans = num1 + num2;
    dp[n] = myans;
    return myans;
}
int main()
{
    int n ; 
    cin>> n ;
    int dp[ n + 1 ] = {0};
    int ans = fib_dp( n , dp);
    cout<< ans;
    return 0;
}