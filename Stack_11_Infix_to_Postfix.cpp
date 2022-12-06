// Algo
// if operand
//     print
// if '('
//     push to stack
// if ')'
//     pop fromstack and print until '(' is found
// if operator
//     pop from stack and rint until an operator with less precendece is found

#include <bits/stdc++.h>
using namespace std;

int precedence(char c){
    if(c=='^'){
        return 3;
    }else if(c=='*'  || c=='/'){
        return 2;
    }else if(c=='+'  || c=='-'){
        return 1;
    }else{
        return -1;   //when there is opening bracket , return -1
    }
}


string infix_to_postfix(string infix_expression)
{

    stack<char> st;
    string postfix_expression = "";
    for (int i = 0; i < infix_expression.length(); i++)
    {
        if (infix_expression[i] >= 'a' && infix_expression[i] <= 'z' || infix_expression[i] >= 'A' && infix_expression[i] <= 'Z')
        {
            postfix_expression += infix_expression[i];
        }
        else if (infix_expression[i] == '(')
        {
            st.push(infix_expression[i]);
        }
        else if (infix_expression[i] == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                postfix_expression += st.top();
                st.pop();
            }
            if(!st.empty()){
                st.pop(); // for the opening bracket
            }
        }
        else
        {
            // Checking that the precendence of the current operator is greater than the operator in stack
           while(!st.empty() && precedence(infix_expression[i]) <= precedence(st.top())){
                postfix_expression+=st.top();
                st.pop();
           }
        //    pushing the current operator
        st.push(infix_expression[i]);
        }
    }

    while (!st.empty())
    {
        postfix_expression+=st.top();
        st.pop();
    }
    
    return postfix_expression;
}



int main()
{

    string infix_expression;
    cin >> infix_expression;

    // cout<<"Postfix expression for infix expresssion "<<infix_expression<<" : "<<infix_to_postfix(infix_expression)<<endl;

    cout<<infix_to_postfix(infix_expression)<<endl;
    return 0;
}