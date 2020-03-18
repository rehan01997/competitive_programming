// given 3 string encode string insuch a way thatb the sum of two string after encoding is equal to third string

#include<bits/stdc++.h>
using namespace std;

string a = "send";
string b = "more";
string c = "money";
vector<int>mapping(26,-1);
vector<bool>numused(10,false);

int str_to_num(string str)
{
    int res = 0 ;
    for(int i = 0 ; i < str.length() ; i++)
    {
        int num = mapping[str[i] - 'a'];
        res = res*10 + num;
    }
    return res;
}
int crypto_encoding(string str, int idx)
{
    //base case
    if(idx == str.length() )
    {
        int num1 = str_to_num(a);
        int num2 = str_to_num(b);
        int num3 = str_to_num(c);

        if( (num1  + num2) == num3)
        {
            cout<<num1 <<"+"<< num2 <<"="<<num3<<" ";
            return 1;
        }
        return 0;
    }
    int count = 0;
    char ch = str[idx];
    for(int i = 0 ; i < 10 ; i ++)
    {
        if(!numused[i])
        {
            numused[i] = true;
            mapping[ch  - 'a'] = i;

            count += crypto_encoding(str, idx + 1 );

            mapping[ch - 'a'] = -1;
            numused[i] = false;
        }
    }
}

int main()
{
    vector<int>freq(26,0);
    string str= a + b + c;
    
    for(int i = 0 ; i <str.length() ; i++)
    {
        freq[str[i] - 'a']++;
    }
    string ans =  " ";
    for(int i = 0 ; i < 26 ; i++)
    {
        if(freq[i] != 0 )
        {
            ans += (char)(i + 'a');
        }
    }
    int countt = crypto_encoding(ans,0);
    cout<<endl;
    cout<<"-----"<<countt;
    return 0;
}