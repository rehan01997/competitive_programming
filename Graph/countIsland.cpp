#include<bits/stdc++.h>
using namespace std;
//
int count_islands(vector<vector<int>>& arr )
{
    int count = 0;
    for(int i = 0 ; i < arr.size() ; i++)
    {
        for(int j = 0; j < arr[0].size() ; j++)
        {
            if( arr[i][j] == 0)
            {   //cout<<"b";
                queue<pair<int , int >>q;
                
                q.push( { i , j });
                while (!q.empty())
                {   //cout << "a";
                    pair<int,int> curr = q.front();
                    int x = curr.first;
                    int y = curr.second;
                    arr[x][y] = 1;

                    if( (x - 1)  >= 0 && arr[x - 1][y] == 0)
                    {
                        q.push({ x - 1, y });
                    }
                    if( (y - 1)  >= 0 && arr[x][y - 1] == 0)
                    {
                        q.push({ x , y - 1 });
                    }
                    if( (x + 1)  < arr.size() && arr[x + 1][y] == 0)
                    {
                        q.push({ x + 1, y });
                    }
                    if( (y + 1)  < arr[0].size() && arr[x ][y + 1] == 0)
                    {
                        q.push({ x, y + 1});
                    } 
                    q.pop();                    
                }  
                count ++;              
            }
        }        
    }
    return count;
}
int main()
{
    int n , m;
    cin >> n >> m;
    vector<vector<int>>arr( n , vector<int>(m,0));

    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            cin >> arr[i][j];
        }
    }
    int ans = count_islands( arr );
    cout << ans;
    return 0;
}
