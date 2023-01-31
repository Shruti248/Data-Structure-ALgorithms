// Strings : Bigger version of character Array

//  C : Charater Array & S : Strings
// C : Static in size , S : Dynamic
// C : Larger size array has be made for performing operatiosn like concetantion , append etc so that it can store it , S : Easier to perform such operations
// C : No terminating extra character, S : Terminated with '\0'

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;

    // cin>>str;
    // cout<<str<<endl;

    // Ways to declare a string
    string str1(5, 'n'); // string of size 5 with character as n
    // cout<<str1;

    string str2 = "HelloWorld!";
    // cout<<str2;

    string str3;
    // Input for sentences
    // getline(cin , str3);  //cin will take input for words till spaces , after it , itb will skip
    // cout<<str3<<endl;

    // Operations
    string s1 = "Strig s1";
    string s2 = "Strig s2";

    // Append
    s1.append(s2);
    // cout<<s1<<endl;

    string s3;
    s3 = s1 + " " + s2;
    // cout<<s3;

    // Assign : Already know

    // Access
    // cout<<s1[0];
    // cout<<s1[4];

    // Clear
    string clearString = "cfvgbhjnkml";
    clearString.clear();
    // cout<<clearString<<endl;

    // Campare the 2 Strings
    string first = "abc";
    string second = "abc";

    // If positive : second strings s2 is greater than s1;
    // if 0 : both strings are equal
    // cout<<second.compare(first)<<endl;

    // if(second.compare(first) == 0){
    // cout<<"Strings are equal."<<endl;
    // }

    // Empty
    // second.clear();
    // if(second.empty()){
    // cout<<"EMpty"<<endl;
    // }

    // Erase
    string eraseStr = "erase";
    eraseStr.erase(1, 3); // from index 1 , delete 3 characters
    // cout<<eraseStr<<endl;

    // Find
    // Find a substring
    string findStr = "FindSubstring";
    // cout<<findStr.find("string");  //Returns index of teh firt character to find

    // Insert
    string insertStr = "hi";
    insertStr.insert(2, "InsertedString"); // String inserted at index 2

    // cout<<insertStr<<endl;

    // length
    // insertStr.length();
    // insertStr.size();

    // Substring
    string substring = insertStr.substr(6, 4);
    // cout<<substring<<endl;

    // String to Integer
    string strInt = "786";
    int value = stoi(strInt);
    // cout << value +2 << endl;

    // Integer to string
    int x = 786;
    // int string it appends , rather then  adding
    // cout<<to_string(x)+"2"<<endl;


    // Sorting a String
    string s11 = "xdcfgvbhjnkm";

    sort(s11.begin() , s11.end());
    // cout<<s11<<endl; // Ascending order

    return 0;
}
