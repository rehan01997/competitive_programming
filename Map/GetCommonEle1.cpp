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
        mp[ a]++;
    }
    //map< int , int > :: iterator it;
    // for(int i = 0 ; i < n2 ; i++)
    // {
    //     int no;
    //     cin >> no;
    //     // it = mp.find(no);          
    //     // if( it != mp.end() ) cout << *it->first;
    //     cout<<mp.find(no)->first;
    //     cout << endl;
    // }
    cout <<endl;
    for(int b : arr2)
    {
        auto it = mp.find(b);
        if( it != mp.end())
        {
            cout << it -> first << endl;
            mp.erase(it);
        } 
    } 
    return 0;
}