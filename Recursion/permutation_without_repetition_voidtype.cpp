#include<bits/stdc++.h>
using namespace std;

int permutation(string ques,string ans)
{
    if(ques.length() == 0)
    {
        cout<<ans;
        return 1;
    }
    int count = 0;
    vector<bool>maping(26,false);
    for(int i=0; i < ques.length() ; i++)
    {   
        char ch = ques[i];
        if(maping[ch - 'a'] == false)
        {
            maping[ch - 'a'] = true;
            char ch = ques[i];
            string roq = ques.substr(0,i) + ques.substr(i+1);
            count += permutation(roq,ans + ch);
        }
    }
    return count;

}
int main()
{   
    string ques;
    cin>>ques; 
    int perm = permutation(ques," ");
    cout<<endl;
    cout<<perm;
    return 0;
}