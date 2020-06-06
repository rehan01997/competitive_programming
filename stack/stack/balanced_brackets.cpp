#include <bits/stdc++.h>
using namespace std;

bool balanceBrackets(string str)
{  //() [] {}
    stack<char>st;
    for( int i = 0 ; i < str.length() ; i++)
    { 
        char ch = str[i];
        if( ch == '(' || ch == '{' || ch =='[') st.push(ch);
        else if( ch == ')')
        {
            if( st.size() == 0 || st.top() != '(') return false;
            else st.pop();
        }    
        else if( ch == '}')
        {
            if( st.size() == 0 || st.top() != '{') return false;
            else st.pop();
        } 
        else if( ch == ']')
        {
            if( st.size() == 0 || st.top() != '[') return false;
            else st.pop();
        }         
    }
    if( st.size() > 0) return false;
    else return true; 
}
int main()
{
    string ques;
    getline(cin , ques);
    bool ans = balanceBrackets(ques);
    if (ans == true)
        cout << "true";
    else
        cout << "false";
    return 0;
}