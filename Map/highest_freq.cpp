#include<bits/stdc++.h>
using namespace std;

bool comparator( pair<char , int> p1 , pair<char,int> p2)
{
    return p1.second < p2.second;
}
int main()
{
    string st;
    cin >> st;

    map< char , int > mp;
    for(int i = 0 ; i < st.length() ; i++)
    {
        mp[st[i]]++;
    }
    vector<pair<char,int>> v( mp.begin() , mp.end());
    sort( v.begin() , v.end() , comparator);
    cout<<v[v.size() - 1].first ;
    return 0;
}

