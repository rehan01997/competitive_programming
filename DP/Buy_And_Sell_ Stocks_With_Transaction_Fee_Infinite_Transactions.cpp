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
    
    int profit = 0 ;
    int no_transac = 0;

    for( int i = 0 ; i < n - 1; i++)
    {
        for(int j = i + 1 ; j < n ; j++)
        {
            if( price[j] <= price[j - 1])
            {
                if( (j - 1) == i )
                {
                    i++;
                    break;
                } 
                
                profit += price[ j - 1] - price[ i ];
                cout<<"profit"<<profit<<" ";
                no_transac ++;
                i = j;
                //break;
            }
        }
    }
    //int new_profit = profit - no_transac*trac;
    //cout << new_profit;
    cout<<"trac"<<no_transac;
    cout<<"pro"<<profit;
    return 0;
}