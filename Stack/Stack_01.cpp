#include<iostream>
using namespace std;

class stack {
    int *arr;
    int top ;

    public : 
        int n = 100;
        stack(){
            arr=new int[n];
            top = -1;
        }
        void push(int x){
            if(top >= n-1){
                cout<<"Stack Overflow"<<endl;
                return;
            }
            else{
                top++;
                arr[top]=x;
            }
        }

        void pop(){
            if(top == -1){
                cout<<"Stack is Empty"<<endl;
                return;
            }
            else{
                top--;
            }
        }

        int Top(){
            if(top == -1){
                cout<<"Stack is Empty"<<endl;
                return -1;
            }
            else{
                return arr[top];
            }
        }

        bool empty(){
            return top==-1;
        }


};

int main(){
    stack st;
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    cout<<st.Top()<<endl;
    st.pop();
    st.pop();
    st.pop();
    cout<<st.Top()<<endl;
    st.pop();
    cout<<st.empty()<<endl;

    return 0;
}