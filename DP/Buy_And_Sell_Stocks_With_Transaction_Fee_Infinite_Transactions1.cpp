#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n , trac;
    cin >> n ;
    vector<int>price( n );

    for(int i = 0 ; i < n ;i++)
    {
        cin >> price[i];
    }
    cin >> trac;
    
    int buyP = 0 - price[ 0 ];
    int sellP = 0;
    for(int i = 1; i <n ; i++)
    {
        int nBuy = max ( sellP - price[i] , buyP);
        int nSell = max ( price[i] + buyP - trac , sellP);

        buyP = nBuy;
        sellP = nSell;
    }
    cout << sellP;
    return 0;
}