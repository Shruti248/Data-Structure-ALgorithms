#include<bits/stdc++.h>
#include<set>
using namespace std;

int main(){
    set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(2);
    s.insert(3);
    // NO duplicate elements in set & therefore only 1 will be printed

    for(auto i : s){
        cout<<i<<" ";
    }
    cout<<"\n";
    for(auto i = s.begin() ; i!= s.end() ; i++){
        cout<<*i<<" ";
    }
    cout<<"\n";

    // Print in reverse
    for(auto i = s.rbegin() ; i!= s.rend() ; i++){
        cout<<*i<<" ";
    }
    cout<<"\n";
    cout<<s.size()<<endl;

    return 0;
}
