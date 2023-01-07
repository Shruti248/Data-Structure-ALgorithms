#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class removeConsecutiveCharacters{
    stack<char> st;
    string reverseString="";

    public:
        string removeConsecutiveCharacter(string s){
            st.push(s[0]);
            for(int i = 1 ; i< s.length() ; i++){
                if(s[i] != s[i-1]){
                    st.push(s[i]);
                }
            }
            while(!st.empty()){
                reverseString += st.top();
                st.pop();
            }
            reverse(reverseString.begin() , reverseString.end());

            return reverseString;
        }
        
};

int main(){
    removeConsecutiveCharacters rcc;
    string s;
    cin>>s;

    cout<<rcc.removeConsecutiveCharacter(s);
    
    return 0;
}