#include <iostream>
#include<vector>
using namespace std;

vector<string>find1(int sr,int sc,int er,int ec)
{
    if(sr == er && sc == ec)
    {
        vector<string>ans;
        ans.push_back(" ");
        return ans;
    }

    vector<string> finalans ;
    if(sr+1 <= er)
    {
        vector<string>hori = find1(sr+1,sc,er,ec);
        for(string s:hori)
        {
            finalans.push_back("h"+s);
        }//return finalans;

    }

    if(sc+1 <= ec)
    {
        vector<string>vert = find1(sr,sc+1,er,ec);
        for(string s:vert)
        {
            finalans.push_back("v"+s);
        }
        //return finalans;
    }

    return finalans;

}


int main()
{

    vector<string> ans=find1(0,0,2,2);
    for(string i : ans){
        cout<<i;
    }

    return 0;
}
