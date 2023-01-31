#include<bits/stdc++.h>
using namespace std;

class Solution{

    public:
        void stringToUpperCaseAndLowerCase(string str){
            // cout<<'a'-'A'<<endl; //32 : Means a is 32 ahead of Capital A. 

            // 1) To Uppercase
            // Therefore every lower case will be stretched back by 32 charaters for ASCII 
            for(int i = 0 ; i<str.size() ; i++){
                if(str[i] >='a'  && str[i]<='z'){
                    str[i]-=32;
                }
            }

            cout<<str<<endl;

            // 2) To Lowercase
            for(int i = 0 ; i<str.size() ; i++){
                if(str[i] >='A' && str[i]<='Z'){
                    str[i]+=32;
                }
            }
            cout<<str<<endl;

            // 3) Inbuilt Function 
            transform(str.begin() , str.end() , str.begin()+3 /**Uppercase will be converted from this character*/, ::toupper);
            cout<<str<<endl;
            
            
            transform(str.begin() , str.end() , str.begin()+6/**Lowercase will be converted from this character*/, ::tolower);
            cout<<str<<endl;


        }

        void formTheBiggestNumberFromTheNumericString(string str){
            sort(str.begin() , str.end() , greater<int>()); //3rd argument : bcoz we want to sort the characters in decreasing order

            cout<<str<<endl;
        }

        void maximumOccurenceOfCharacters(string str){
            int frequency[26];

            for(int i = 0 ; i<26 ; i++){
                frequency[i] = 0;
            }

            for(int i = 0 ; i<str.size() ; i++){
                // 0 : a 
                // 1:b 
                // 2: c
                // Therefore it will increase the frequency at the particular index for each character
                frequency[str[i]-'a']++;
            }

            // Maximum of frequency
            char ans = 'a';
            int maxF = 0;

            for(int i = 0 ; i<26 ; i++){
                if(frequency[i] > maxF){
                    maxF = frequency[i];
                    ans = i+'a';
                }
            }

            cout<<maxF<<endl;
            cout<<ans<<endl;

            // This will return maximum occurence of the first charcater , that is if 2 maximum are equal , first will be returned....
        }


};

int main(){
    Solution s;
    string str;

    cin>>str;
    // s.stringToUpperCaseAndLowerCase(str);
    // s.formTheBiggestNumberFromTheNumericString(str);
    s.maximumOccurenceOfCharacters(str);


    return 0;
}