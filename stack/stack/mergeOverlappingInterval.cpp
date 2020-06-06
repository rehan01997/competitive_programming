#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int> >mergeInt(vector<pair<int,int>> arr)
{
    stack<pair<int,int> >st;
    vector<pair<int,int> >ans;
    st.push(arr[0]);
    for(int i = 1 ; i < arr.size() ; i++)
    {
        if( arr[i].first <= st.top().second  )
        {
            int s = st.top().first;
            int l = max(arr[i].second , st.top().second);
            st.pop();
            st.push(make_pair(s,l));
        }
        else 
        {
            st.push(arr[i]);
        }        
    }
    while( st.size() > 0)
    {
        ans.push_back(st.top());
        st.pop();
    }
    sort(ans.begin() , ans.end());
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<pair<int,int>> arr( n );
    for(int i = 0 ; i < n ; i++)
    {
        int a;
        int b;
        cin>>a;
        cin>>b;
        arr[i] = make_pair(a,b);
    }
    sort(arr.begin() , arr.end());
    vector<pair<int,int> > ans = mergeInt(arr);
    for(int i = 0 ; i < ans.size() ; i++)
    {
        cout<<ans[i].first << " " << ans[i].second;
        cout<<endl;
    }
    return 0;
}