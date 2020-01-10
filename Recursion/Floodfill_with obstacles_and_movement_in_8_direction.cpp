
#include<bits/stdc++.h>

using namespace std;

vector<string>maze_path_8(int sr,int sc,int er,int ec,bool visited[4][4])
{
    if(sr == er && sc == ec)
    {
        vector<string>finalans;
        finalans.push_back(" ");
        return finalans;
    }
    visited[sr][sc] = true;
    vector<string>finalans;
    
    if(sr-1>=0 && !visited[sr-1][sc])
    {
        vector<string>up = maze_path_8(sr-1,sc,er,ec,visited);
        for(string s: up)
        {
            finalans.push_back("U" + s);
        }
    }
    if(sc+1<=ec && !visited[sr][sc+1])
    {
        vector<string>right = maze_path_8(sr,sc+1,er,ec,visited);
        for(string s: right)
        {
            finalans.push_back("R" + s);
        }
    }
    if(sr+1 <= er && !visited[sr+1][sc])
    {
        vector<string>down = maze_path_8(sr+1,sc,er,ec,visited);
        for(string s: down)
        {
            finalans.push_back("D" + s);
        }
    }
    if(sc-1>=0 && !visited[sr][sc-1])
    {
        vector<string>left = maze_path_8(sr,sc-1,er,ec,visited);
        for(string s: left)
        {
            finalans.push_back("L" + s);
        }
    }
    
    
    visited[sr][sc] == false;
    return finalans;
}

int main()
{
    bool obstacle[4][4]= {false};
    // obstacle[1][2] = true;
    // obstacle[2][2] = true;
    // obstacle[3][2] = true;
    //obstacle[4][3] = true;


    // bool obstacle[4][4]={{false,false,false,false},
    //                      {false,false,true,false},
    //                      {false,false,false,false},
    //                      {false,true,false,false},
    //                      {false,false,true,false}};



    vector<string> ans = maze_path_8(0,0,2,2,obstacle);
    for(string s: ans)
    {
        cout<<s;
    }

}

//DDRRDR, DDRRRD, DDRLLRRDDD, DDRLLRRDDUDR, DRDRDR, DRDRRD, DRLRRDDD, DRLRRDDUDR, RDDRDR, RDDRRD, RDUDRRDR, RDUDRRRD, RRRDDD, RRRDDUDR