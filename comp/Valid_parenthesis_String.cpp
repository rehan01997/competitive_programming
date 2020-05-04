/*
Valid Parenthesis String
Solution
Given a string containing only three types of characters: '(', ')' and '*', write a function to check whether this string is valid. We define the validity of a string by these rules: 
Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string.
An empty string is also valid.

Example 1:
Input: "()"
Output: True

Example 2:
Input: "(*)"
Output: True

Example 3:
Input: "(*))"
Output: True
*/
class Solution {
public:
    bool checkValidString(string s)
    {
        if( s[0] == ')' ) return false;
        int n = s.length();
        
        int count = 0;
        stack  <int> st;
        stack  <int> star;
        for(int i = 0 ; i < n ; i++)
        {
             if ( s[i] == '*') star.push(i);
             else if( s[i] == '(') st.push(i);
             else if( s[i] == ')' && st.empty() && star.empty()) return false;
             else if( s[i] == ')' && !st.empty() ) st.pop();
             else if( s[i] == ')' && st.empty() && !star.empty()) star.pop() ;  
        }
        while( !st.empty() && star.size() > 0)
        {
            if( star.top() > st.top())
            {
                 st.pop();
                 star.pop();
            }   
            else
            {
                return false;
            }
        }
        if( st.empty()) return true;  
        else return false;
    }
};