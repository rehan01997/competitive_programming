#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n , k;
    cin >> n;
    vector<int>price( n );
    for(int i = 0 ; i < n ; i ++)
    {
        cin >> price[i];
    }
    cin >> k;
    //Dp
    vector<vector<int> >dp( k + 1 , vector<int>(n));
    //row [0]-->0 && col[0]-->0

    for(int i = 1 ; i <= k ; i++)
    {
        if( i == 1)
        {
            int min = price[0];
            for(int j = 1 ; j < n ; j++)
            {   
                if( min > price[j]) min = price[j];
                dp[i][j] = max ( price[j] - min , dp[i][j - 1] );
            }
        }
        else
        {
            for(int j = 1 ; j < n ; j++)
            { 
                int max = 0;
                //take transaction - up_left
                for(int x = 0 ; x < j ; x ++)
                {
                    int profit = price[j] - price[x] + dp[i -1][x];
                    if( max < profit) max = profit;
                }
                //no transaction - left
                if(max < dp[i][j - 1]) max = dp[i][j - 1];
                dp[i][j] = max;
            }
            
        }
    } 
    // for(int i = 0 ; i < dp.size() ; i++)
    // {
    //     for(int j = 0 ; j <dp[0].size() ; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }cout<<endl;
    // }
    cout << dp[k][n-1];
    return 0;
}