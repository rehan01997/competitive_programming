#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int>cost( n );
    for(int i = 0 ; i < n ; i++)
    {
        cin >> cost[i];
    }
    int min = cost[0];
    int max_profit = 0;

    for(int i = 1 ; i < n ; i++)
    {
        if( cost[ i ] < min ) min = cost[ i ];
        int cprofit = cost[ i ] - min;

        if(cprofit > max_profit)
        {
            max_profit = cprofit;
        }
    }
    cout << max_profit;
    return 0;
}