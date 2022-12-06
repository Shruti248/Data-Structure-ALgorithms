// Array Implementation 
#include<iostream>
using namespace std;

#define n 100

class stack{
    // Private data members
     int* arr;  //Dynamic array
     int top;

    public:
        // COnstructor for allocating the memory of the array
        stack(){
            arr = new int[n]; 
            top = -1;
        }

        void push(int x){
            if(top == n-1){
                cout<<"Stack Overflow"<<endl;
            }else{
                top++;
                arr[top]=x; 
                // cout<<"Pushed element is "<<arr[top]<<endl;
            }
        }

        void pop(){
            if(top == -1){
                cout<<"Stack Underflow"<<endl;
            }else{
                // cout<<"Popped element is "<<arr[top]<<endl;
                top--;
                
            }
        }

        int Top(){
            if(top == -1){
                cout<<"Empty Stack"<<endl;
                return -1;
            }
            return arr[top];
        }

        bool isEmpty(){
            return top==-1;
        }

        void printStack(){
            while(isEmpty() == 0){
                cout<<arr[top];
                pop();
            }
        }
};

int main(){
    stack st;
    st.push(1);
    st.push(2);
    st.push(3);

    st.pop();

    cout<<"isEmpty() : "<<st.isEmpty()<<endl;
    cout<<"st.Top() : "<<st.Top()<<endl;

    st.printStack();
    
    return 0;
}
