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
int infixEval(string exp)
{
    stack<int> num;
    stack<char> optrs;
    for (int i = 0; i < exp.length(); i++)
    {
        char ch = exp[i];
        if ( isdigit(ch) )
        {
            num.push(ch - '0');
        }            
        else if (ch == '(')
        {
            num.push(ch);
        }
        else if (ch == ')')
        {
            while (optrs.top() != '(')
            {  
                char optr = optrs.top(); optrs.pop();
                int op2 = num.top();  num.pop();               
                int op1 = num.top(); num.pop();                
                num.push(solve(optr, op1, op2));
            }
            optrs.pop(); //to pop ')'
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            while(optrs.size() > 0 && optrs.top() != '(' && pred(ch) <= pred(optrs.top()) )
            { 
                char optr = optrs.top(); optrs.pop();
                int op2 = num.top(); num.pop();               
                int op1 = num.top(); num.pop();                
                num.push(solve(optr, op1, op2));
            }
            optrs.push(ch);
            }
    }
    while (optrs.size() > 0)
    {   
        char optr = optrs.top(); optrs.pop();
        int op2 = num.top(); num.pop();        
        int op1 = num.top();  num.pop();       
        num.push(solve(optr, op1, op2));
    }
    return num.top();
}
int main()
{
    string ques;
    getline(cin , ques);
    int ans = infixEval(ques);
    cout << ans;
    return 0;
}
