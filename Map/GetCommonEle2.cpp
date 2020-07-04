#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n1;
    int n2;
    cin >> n1;
    vector<int>arr1(n1,0);
    for(int i = 0 ; i < n1 ; i++) cin >> arr1[i];
    cin >> n2;
    vector<int>arr2(n2,0);
    for(int i = 0 ; i < n2 ; i++) cin >> arr2[i];
    
    map< int ,int> mp;
    for(int a : arr1)
    {  
        mp[a]++;
    }
      
    for(int b : arr2)
    {
        auto it = mp.find(b);
        if( it != mp.end())
        {
            if( it -> second > 0) cout << it -> first << endl;            
            it -> second --;
        } 
    } 
    return 0;
}