#include <bits/stdc++.h>
using namespace std;
int solve(char optr, int num1, int num2)
{
    if (optr == '-')
        return (num1 - num2);
    else if (optr == '+')
        return (num1 + num2);
    else if (optr == '*')
        return num1 * num2;
    else
        return num1 / num2;
}
int pred(char optr)
{
    if (optr == '+' || optr == '-')
        return 1;
    else
        return 2;
}
void infixConversion(string exp)
{
    stack<string> prefix;
    stack<string> postfix;
    stack<char> optrs;

    for(int i = 0 ; i < exp.length() ; i++)
    {
        char ch = exp[i];
        if( isdigit(ch))
        {           
            string c(1,ch);
            prefix.push( c );
            postfix.push( c );
        }
        else if( ch == '(') optrs.push(ch);
        else if( ch == ')')
        {
            while( optrs.top() != '(')
            {
                char optr = optrs.top(); optrs.pop();
                //prefix
                string preop2 = prefix.top() ; prefix.pop();
                string preop1 = prefix.top() ; prefix.pop();
                prefix.push( optr + preop1 + preop2 );

                //postfix
                string posop2 = postfix.top(); postfix.pop();
                string posop1 = postfix.top() ; postfix.pop();
                postfix.push( posop1 + posop2 + optr);
            }
            optrs.pop();
        }
        else if( ch == '+' || ch =='-' || ch =='*' || ch =='/')
        {
            while( optrs.size() > 0 && optrs.top() != '(' && pred(ch) <= pred(optrs.top()))
            {
                char optr = optrs.top(); optrs.pop();
                //prefix
                string preop2 = prefix.top() ; prefix.pop();
                string preop1 = prefix.top() ; prefix.pop();
                prefix.push( optr + preop1 + preop2 );

                //postfix
                string posop2 = postfix.top(); postfix.pop();
                string posop1 = postfix.top() ; postfix.pop();
                postfix.push( posop1 + posop2 + optr);
            }
            optrs.push(ch);
        }
    }
    while(optrs.size() > 0)
    {
        char optr = optrs.top(); optrs.pop();
        //prefix
        string preop2 = prefix.top() ; prefix.pop();
        string preop1 = prefix.top() ; prefix.pop();
        prefix.push( optr + preop1 + preop2 );

        //postfix
        string posop2 = postfix.top(); postfix.pop();
        string posop1 = postfix.top() ; postfix.pop();
        postfix.push( posop1 + posop2 + optr);
    }
    cout << postfix.top() << endl << prefix.top();
}
int main()
{
    string ques;
    cin >> ques;
    infixConversion(ques);
    return 0;
}
