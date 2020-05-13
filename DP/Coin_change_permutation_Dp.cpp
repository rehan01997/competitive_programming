#include<bits/stdc++.h>
using namespace std;
int countWays( vector<int> coins , int amt)
{
    vector<int> dp( amt + 1);
    dp[0] = 1;

    for(int i = 1 ; i < dp.size() ; i++)
    {  
        for(int j = 0 ; j < coins.size(); j++)
        {
            if( i -coins[j] >= 0)
            {
                dp[i] += dp[ i - coins[j]];
            }
        }
       // dp[i] = no_of_ways;
    }
    return dp[amt];
}
int main()
{
    int n , tar;    
    cin>> n ;

    vector<int> coins(n);
    for(int i =0 ; i < n ; i++)
    {
       cin >> coins[i];
    }
    /*for(int i =0 ; i < n ; i++)
    {
       cout<< arr[i] <<" ";
    }*/
    cin >> tar;
    int ans = countWays( coins, tar);
    cout << ans <<endl;
    return 0;
}