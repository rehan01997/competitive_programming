#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreater(vector<int> arr)
{
    stack<int> st;
    vector<int>ans( arr.size() , 0);
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        while( st.size() > 0 && st.top() <= arr[i])
        {
            st.pop();
        }
        if(st.size() == 0)
        {
            ans[i] = -1;
        }
        else
        {
            ans[i] = st.top();
        }
        st.push(arr[i]);
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n,0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> ans = nextGreater(arr);
    for( auto s : ans)
    {
        cout<< s <<endl;
    }
    return 0;
}A