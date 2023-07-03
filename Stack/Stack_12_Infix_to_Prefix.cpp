// Algo
// 1) Reverese the string
//     --> closing brackets become opening
//     --> opening becomes closing
// 2) solve with same as postfix
// if operand
//     print
// if '('
//     push to stack
// if ')'
//     pop fromstack and print until '(' is found
// if operator
//     pop from stack and rint until an operator with less precendece is found
// 3) Reverse the answer string to get the finalresult

#include <bits/stdc++.h>
using namespace std;

int precedence(char c)
{
    if (c == '^')
    {
        return 3;
    }
    else if (c == '*' || c == '/')
    {
        return 2;
    }
    else if (c == '+' || c == '-')
    {
        return 1;
    }
    else
    {
        return -1; // when there is opening bracket , return -1
    }
}

string infix_to_prefix(string infix_expression)
{
    reverse(infix_expression.begin(), infix_expression.end()); // inbuilt func

    stack<char> st;
    string prefix_expression = "";
    for (int i = 0; i < infix_expression.length(); i++)
    {
        if (infix_expression[i] >= 'a' && infix_expression[i] <= 'z' || infix_expression[i] >= 'A' && infix_expression[i] <= 'Z')
        {
            prefix_expression += infix_expression[i];
        }
        // Opening will become closing and closing will become opening : difference frompostfix
        else if (infix_expression[i] == ')')
        {
            st.push(infix_expression[i]);
        }
        else if (infix_expression[i] == '(')
        {
            while (!st.empty() && st.top() != ')')
            {
                prefix_expression += st.top();
                st.pop();
            }
            if (!st.empty())
            {
                st.pop(); // for the opening bracket
            }
        }
        else
        {
            // Checking that the precendence of the current operator is greater than the operator in stack
            while (!st.empty() && precedence(infix_expression[i]) <= precedence(st.top()))
            {
                prefix_expression += st.top();
                st.pop();
            }
            //    pushing the current operator
            st.push(infix_expression[i]);
        }
    }

    while (!st.empty())
    {
        prefix_expression += st.top();
        st.pop();
    }

    reverse(prefix_expression.begin(), prefix_expression.end());
    return prefix_expression;
}

int main()
{
    string infix_expression;
    cin >>infix_expression;

    cout<<infix_to_prefix(infix_expression)<<endl;
    return 0;
}
