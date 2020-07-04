#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> dir ={{-2,1} , {-1,2} , {1,2} , {2,1} , {2,-1}, {1,-2} , {-1,-2} ,{-2,-1}};
// bool isValid(int x, int y, vector<vector<int>> ans)
// {   //cout<<"a"<<isVisited[0].size();
//     //cout<<"b"<<isVisited.size();
//     if( x >= 0 && y >= 0 && x < ans.size() &&  y < ans[0].size() && ans[x][y] == 0)
//     {
//         return true;        
//     }
//     return false;
// }
void knightPath_Fill(int sr,int sc,int count,int Boxes,vector<vector<int>> ans)
{    
    if(count == Boxes )
    {   
        ans[sr][sc] = count;
        for(auto arr : ans)
        {   
            for(int ele : arr) cout<<ele<<" ";
            cout<<endl; 
        }
        cout<<endl;
        ans[sr][sc] = 0;
        return ;
    }
    ans[sr][sc] = count;
    for(int d = 0 ; d < dir.size() ; d++)
    { 
        int x = sr + dir[d][0];
        int y = sc + dir[d][1];
        if( x >= 0 && y >= 0 && x < ans.size() &&  y < ans[0].size() && ans[x][y] == 0)
        {
            knightPath_Fill(x , y , count + 1 , Boxes , ans );
        }
    }    
    ans[sr][sc] = 0;
    return ;
}
int main(){
   int n , r , c;
   cin >> n >> r >> c;
   vector<vector<int>>ans(n , vector<int>( n , 0 ));
   knightPath_Fill( r,c, 1 , n*n , ans );
   cout << endl;
   return 0;   
}
