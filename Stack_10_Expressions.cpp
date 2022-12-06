// Infix : 2+3 ,4*3+2    --> Operand Operator Operand
// _-standard way : BODMAS Rule
// Precedence :    1) () , {} , [] 2) ^  --> Right to left 3) *,/ --> left to right 4) + , - --> left to right
// --> Same precendece : wehave associativity

// Computer doesnt know precemdece , we have prefix

// Prefix(Polish Notation) :Operator Operand Operand
// ((4*2)+3) --> (*42)+3 --> +*423
// (5-(6/3)) --> (5-(/63)) --> -5/63

// PostFix(Reverse Polish Notation) : Operand Operand Operator
// ((4*2)+3) --> (42*)+3 --> 42*3+
// (5-(6/3)) --> (5-(63/)) --> 563/-

// Evaluation of Prefix Expression
// --> - + 7 * 4 5 +2 0  : Strt traversing from the last
// Push 0 . push 2 , pop 2 : op1 , pop0: op 2
// op1 : 2
// op2 : 0
// Operand : +
// op1+op2= 2 : ans :push(ans)
// push(2)
// push(5)
// push(4)
// Operand : * : op1: pop(4) * op2:pop(5) : ans: 20
// push(20)
// push(7)
// operand + : pop(7) + pop(20) : ans : 27
// operand - : pop(27) - pop(2) : ans 25
// String empty
// pop(ans)

#include <bits/stdc++.h>
using namespace std;

int prefix_expression_evaluation(string expression)
{
    stack<int> st;
    int operand1, operand2;
    int ans = 0;

    for (int i = expression.length() - 1; i >= 0; i--)
    {
        if (expression[i] >= '0' && expression[i] <= '9')
        {
            // Pushing as integer value so minus the ASCII value of 0,
            st.push(expression[i] - '0');
        }
        else
        {
            operand1 = st.top();
            st.pop();
            operand2 = st.top();
            st.pop();

            switch (expression[i])
            {
            case '+':
                st.push(operand1 + operand2);
                break;
            case '-':
                st.push(operand1 - operand2);
                break;
            case '*':
                st.push(operand1 * operand2);
                break;
            case '/':
                st.push(operand1 / operand2);
                break;
            case '^':
                st.push(pow(operand1, operand2));
                break;
            }
        }
    }

    return st.top();
}

int postfix_expression_evaluation(string expression)
{

    stack<int> st;
    int operand1, operand2;
    int ans = 0;

    for (int i = 0; i < expression.length(); i++)
    {
        if (expression[i] >= '0' && expression[i] <= '9')
        {
            // Pushing as integer value so minus the ASCII value of 0,
            st.push(expression[i] - '0');
        }
        else
        {
            operand2 = st.top();
            st.pop();
            operand1 = st.top();
            st.pop();

            switch (expression[i])
            {
            case '+':
                st.push(operand1 + operand2);
                break;
            case '-':
                st.push(operand1 - operand2);
                break;
            case '*':
                st.push(operand1 * operand2);
                break;
            case '/':
                st.push(operand1 / operand2);
                break;
            case '^':
                st.push(pow(operand1, operand2));
                break;
            }
        }
    }

    return st.top();
}

int main()
{
    int selection;
    cout<<"Press 1 for Prefix Evaluation "<<endl;
    cout<<"Press 2 for Postfix Evaluation "<<endl;
    cin>>selection;
    string expression;
    cin >> expression;

    switch (selection)
    {
    case   1:
        cout << "Prefix Expressions on evaluation : " << prefix_expression_evaluation(expression);
        break;
    case   2:
            cout << "Postfix Expressions on evaluation : " << postfix_expression_evaluation(expression);
    
    default:
        break;
    }


    


    return 0;
}
