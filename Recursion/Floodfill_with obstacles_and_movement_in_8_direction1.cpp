
#include<iostream>
#include<vector>

using namespace std;
bool isvalid(int  x,int y, bool path[][], bool visited[][])
{   int row_visited=(sizeof(visited[1])/sizeof(bool));
    int col_visited=(sizeof(visited[0])/sizeof(bool)); 
    if( x>=0 && y>=0 && x < row_visited && y < col_visited && !visited[x][y] && !path[x][y])
    {   
        return true;
    }
    return false;
}

vector<string>maze_path_8(int sr,int sc,int er,int ec,bool path[][],bool visited[][])
{
    if(sr==er && sc==ec)
    {
        vector<string>ans;
        ans.push_back(" ");
        return ans;
    }
    int dir[4][4] = {{1,0},{0,1},{-1,0},{0,-1}};
    int n_dir= sizeof(dir[0])/sizeof(int);
    string dirName[4] = {"R","U","L","D"};

    visited[sr][sc] == true;

    vector<string>finalans;

    for(int d=0 ; d < n_dir ; d++)
    {
        int x=sr+dir[d][0];
        int y=sc+dir[d][1];

        if( isvalid(x,y,path,visited))
        {
            vector<string>ans = maze_path_8(x,y,er,ec,path,visited);
            for(string s: ans)
            {
                finalans.push_back(dirName[d] + s);
            }
        }
    }
    visited[sr][sc] == false;
    return finalans;   
}
int main()
{
     bool path[5][5]= {false};
    //  path[1][2] = true;
    //  path[2][2] = true;
    //  path[3][2] = true;
    //  path[4][3] = true;

    bool visited[5][5] = {false};

    // bool obstacle[4][4]={{false,false,false,false},
    //                      {false,false,true,false},
    //                      {false,false,false,false},
    //                      {false,true,false,false},
    //                      {false,false,true,false}};
    vector<string> ans = maze_path_8(0,0,4,4,visited,path);
    for(string s: ans)
    {
        cout<<s;
    }
    return 0;

}