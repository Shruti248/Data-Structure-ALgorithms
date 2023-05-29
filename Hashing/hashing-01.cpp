#include<bits/stdc++.h>
using namespace std;

int main(){
    // Character Hashing
    char ch = 'n';

    hash<char> ch_hash;

    cout<<ch_hash(ch)<<endl;

    // String Hashing
    string str = "hashing";

    hash<string> string_hash;

    cout<<string_hash(str)<<endl;

    // Integer Hashing
    int num = 17;
    hash<int> int_hash;
    cout<<int_hash(num)<<endl;

    // Vector Hashing
    vector<bool> vec = { true , true , false , false};

    hash<vector<bool>> vector_hash;
    cout<<vector_hash(vec)<<endl;
    return 0;
}
