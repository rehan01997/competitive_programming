#include<bits/stdc++.h>
using namespace std;

bool is_safe_to_visit(vector<vector<bool> > isvisited , int x , int y )
{
    int xdir[] = { 0 , -1 , -1 , 1};
    int ydir[] = { -1 , -1 ,0 , 1};

    for(int d = 0 ; d < 4 ; d++)
    {
        for(int  i = 1 ; i < isvisited.size() ; i++)
        {
            int r = x + i*xdir[d];
            int c = y + i*ydir[d];
            if(r>=0 && c>=0 && r<isvisited.size() && c<isvisited.size() && isvisited[r][c])
            {
                return false;
            }
        }
    }
    return true;
}
int queen_with_rules(int tnq , vector<vector<bool> >isvisited , int vidx, string ans)
{
    if(tnq == 0)
    {
        cout<<ans;
        return 1;
    }
    int count = 0 ;
    for(int i = vidx ; i < isvisited.size()*isvisited.size() ; i++)
    {   

        int x = i/isvisited.size();
        int y = i%isvisited.size();  
        if( is_safe_to_visit(isvisited , x , y))
        {
            isvisited[x][y] = true;

            count += queen_with_rules(tnq - 1 , isvisited , i+1 , ans+"(" + to_string(x) +"," + to_string(y) + ")" );
            isvisited[x][y] = false;
        }
    }
    return count ;
}

int main()
{
    vector<vector<bool> > isvisted(4,vector<bool>(4,false));
    int tnq = 4;
    queen_with_rules(tnq , isvisted , 0 ," ");
    return 0 ;
}