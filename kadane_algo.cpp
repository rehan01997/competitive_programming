#include<bits/stdc++.h>
using namespace std;

int main()
{
    
    int n ; cin >> n;
    vector<int>arr( n , 0);
    for( int i = 0 ; i < n ; i++ ) cin >> arr[i];

    int temp = arr[0];
    int max_sum = INT_MIN;

    for(int i = 1 ; i < n ; i++)
    {
        temp = max( arr[i] , arr[i] + temp);
        if( temp > max_sum ) max_sum = temp;
    }
    cout << max_sum;
    return 0;
}