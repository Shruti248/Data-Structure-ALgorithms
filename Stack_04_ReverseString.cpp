#include<bits/stdc++.h>
using namespace std;

void reverseString(string s){
    stack<char> st;

    for(int i = 0 ; i<s.length() ; i++){
        st.push(s[i]);
    }
    while(!st.empty()){
        cout<<st.top();
        st.pop();
    }
}

int main(){
    string s;
    cout<<"ENter the String : ";
    cin>>s;

    cout<<"Reversed String is : ";
    reverseString(s);

    return 0;
}