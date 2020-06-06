#include <bits/stdc++.h>
using namespace std;

int largestAreahistogram(vector<int> arr)
{
    stack<int> ls;
    stack<int> rs;
    vector<int>ans( arr.size() , 0);

    vector<int>leftSmall(arr.size() , 0);
    vector<int>rightSmall(arr.size() , 0);

    for(int i = 0 ; i < arr.size() ; i++)
    {
        while( ls.size() > 0 && arr[ls.top()] > arr[i])
        {
            ls.pop();
        }
        if( ls.size() == 0 ) leftSmall[i] = -1;
        else leftSmall[i] = ls.top();
        ls.push(i);
    }
    for(int i = arr.size() - 1 ; i >= 0 ; i--)
    {
        while( rs.size() > 0 && arr[rs.top()] >= arr[i])
        {
            rs.pop();
        }
        if(rs.size() == 0 ) rightSmall[i] = arr.size();
        else rightSmall[i] = rs.top();
        rs.push(i);
    }
    int maxArea = arr[0] *( rightSmall[0] - leftSmall[0] - 1);
    for(int i = 0 ; i < arr.size() ; i ++)
    {
        int height = arr[i];
        int width = rightSmall[i] - leftSmall[i] - 1;
        int currArea = height * width;
        if( maxArea < currArea) maxArea = currArea;
    }
    return maxArea;
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
    int ans = largestAreahistogram(arr);
    cout << ans <<endl;
    return 0;
}