// Stack operations of stack using c++ standard template library 


#include <iostream>
#include <stack>
using namespace std;

int main()
{

    stack<int> stack;
    int stack_size;
    int choice_of_elements_stack;

    cout << "Stack size : ";
    cin >> stack_size;

    while (choice_of_elements_stack != 4)
    {
        cout << "\n\nPress 1 for checking current status of the stack " << endl;
        cout << "Press 2 for pushing elements in stack" << endl;
        cout << "Press 3 for removing elements in stack" << endl;
        cout << "Press 4 to Exit" << endl;
        cin >> choice_of_elements_stack;

        if (choice_of_elements_stack == 1)
        {
            cout << "Current stack is -->  " << endl;
            if (stack.empty() == 1)
            {
                cout << "\nEmpty" << endl;
            }
            else
            {
                cout << "\nStack contains some elements. Elements are : " << endl;
                while (stack.size() != 0)
                {
                    cout << stack.top() << endl;
                    stack.pop();
                }
            }
        }
        else if (choice_of_elements_stack == 2)
        {
            // Push in stack
            int num;

            cout << "Elements to push in stack : ";
            cin >> num;

            if (stack.size() >= stack_size)
            {
                cout << "Cannot push elemets in stack (Stack Overflow)" << endl;
            }
            else
            {
                stack.push(num);
            }
        }
        else if (choice_of_elements_stack == 3)
        {
            // pop in stack
            if (stack.size() == 0)
            {
                cout << "NO elemets in stackto remove (Stack Underflow)" << endl;
            }
            else
            {
                stack.pop();
            }
        }
        else
        {
            cout << "Invalid Choice" << endl;
        }
    }

    return 0;
}
