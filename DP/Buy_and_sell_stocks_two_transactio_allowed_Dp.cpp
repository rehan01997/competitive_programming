#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n ;
     cin >> n;
     vector<int>price( n );
     for(int i = 0 ; i < n ; i++)
     {
         cin >> price[i];
     }
     vector <int> left(n);
     vector <int> right( n );

     //for left
     int min = price[0];
     for(int i = 1 ; i < n ; i++)
     {
         if( price[i] < min ) min = price[i];
         left[i] = max( price[i] - min , left[ i - 1]);
     }

     int maximum = price[n - 1];
     for(int i = n - 2 ; i >= 0 ; i-- )
     {
         if( price[i] > maximum) maximum = price[i];
         right[i] = max( maximum - price[i] , right[ i + 1] );
     }
    //max from new array left[i] + right[i]
    int newmax = left[0] + right[0];
    for(int i = 1 ; i < n ; i++)
    {
        int new1 = left[i] + right[i];
        if( new1 > newmax) newmax = new1;
    }
    cout << newmax;
    return 0;
}