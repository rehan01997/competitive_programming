#include <bits/stdc++.h>
using namespace std;
bool duplicate(string str)
{
    stack<char> st;
    for (int i = 0 ; i < str.length() ; i++)
    {
        char ch = str[i];
        if (ch == ')')
        {
            if ( st.top() == '(')
            {
                return true;
            }
            else
            {
                while (st.top() != '(')
                {
                    st.pop();
                }
                st.pop();
            }
        }
        else
        {
            st.push(ch);
        }
    }
    return false;
}
int main()
{
    string ques;
    getline(cin , ques);
    bool ans = duplicate(ques);
    if (ans == true)
        cout << "true";
    else
        cout << "false";
    return 0;
}