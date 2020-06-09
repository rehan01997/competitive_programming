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
void infixEvalConv(string exp)
{
    stack<string>infix;
    stack<string>postfix;
    stack<int>eval;

    for(int i = exp.length() - 1 ; i >= 0   ; i-- )
    {
        char ch = exp[i];
        if( isdigit(ch))
        {
            string c(1,ch);
            eval.push(ch - '0');
            infix.push(c);
            postfix.push(c);
        }
        else
        {
            if( ch == '+' || ch =='-' || ch =='*' || ch =='/')
            {
                // while( eval.size() > 0 && eval.top() !='(' && infd(ch) <= infd(eval.top()))
                // {
                //     char optr = 
                // }
                //eval
                int op1 = eval.top() ; eval.pop();
                int op2 = eval.top() ; eval.pop();
                eval.push(solve( ch , op1 , op2));

                //infix
                string inf1 = infix.top() ; infix.pop();
                string inf2 = infix.top() ; infix.pop();
                infix.push( "(" + inf1 + ch + inf2 + ")");

                //postfix
                string pro1 = postfix.top() ; postfix.pop();
                string pro2 = postfix.top() ; postfix.pop();
                postfix.push( pro1 + pro2 + ch);
            }
        }
    }
    cout<<eval.top()<<endl;
    cout<<infix.top()<<endl;
    cout<<postfix.top();
    return ;
}
int main()
{
    string str;
    cin >> str;
    infixEvalConv(str);
    return 0;
}