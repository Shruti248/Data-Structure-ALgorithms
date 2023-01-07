#include<bits/stdc++.h>
using namespace std;
// Find the sequence of elements popped out
int main(){
    stack<int> st;
    st.push(10); 
    st.push(20); 
    cout<<st.top()<<" ";
    st.pop(); 
    st.push(10); 
    st.push(20); 
    cout<<st.top()<<" ";
    st.pop(); 
    cout<<st.top()<<" ";
    st.pop(); 
    cout<<st.top()<<" ";
    st.pop(); 
    st.push(20);
    cout<<st.top()<<" ";
    st.pop(); 

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }


    return 0 ;

}

