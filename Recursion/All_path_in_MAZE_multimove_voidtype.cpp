#include<bits/stdc++.h>
using namespace std;

int maze_path_multimove(int sr,int sc,int er,int ec,string ans)
{
    if(sr == er && sc == ec)
    {
        cout<<ans<<endl;
        return 1;
    }
    int count = 0;
    for(int jump = 1 ; jump + sr <= er ; jump++)
    {
        count += maze_path_multimove(sr+jump , sc ,er,ec, ans + "V"+ to_string(jump));
    }
    for(int jump = 1 ; jump + sc <= ec ; jump++)
    {
        count += maze_path_multimove(sr , sc + jump , er , ec , ans + "H" + to_string(jump));
    }
    for(int jump = 1 ; jump + sc <= ec && jump + sr <=er; jump++)
    {
        count += maze_path_multimove(sr + jump, sc + jump , er , ec , ans + "D" + to_string(jump));
    }
    return count;
}
int main()
{
    cout<<maze_path_multimove(0,0,2,2," ");
    return 0;
}