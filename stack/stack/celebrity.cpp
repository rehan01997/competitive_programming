#include <bits/stdc++.h>
using namespace std;

int celebrity(vector<vector<int>> arr)
{
    stack<int> st;
    for (int i = 0; i < arr.size(); i++)
    {
        st.push(i);
    }
    while (st.size() > 1)
    {
        int p1 = st.top();
        st.pop();
        int p2 = st.top();
        st.pop();
        if (arr[p1][p2] == 1)
        {
            st.push(p2);
        }
        else
        {
            st.push(p1);
        }
    }

    int pc = st.top();
    st.pop();
    bool isCeleb = true;
    for (int i = 0; i < arr.size(); i++)
    {
        if (i != pc && (arr[i][pc] == 0 || arr[pc][i] == 1))
        {
            isCeleb = false;
            break;
        }
    }
    if (isCeleb)
        cout << pc << endl;
    else
    {
        cout << "none" << endl;
    }
    return 0;
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    int ans = celebrity(arr);
    return 0;
}