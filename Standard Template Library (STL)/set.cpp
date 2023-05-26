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

    // Custom Camparator
    // Default set is in ascending order
    set<int> ascendingyDefault;
    set<int , greater<int>> descending;

    descending.insert(1);
    descending.insert(2);
    descending.insert(2);
    descending.insert(3);
    // NO duplicate elements in set & therefore only 1 will be printed

    for(auto i : descending){
        cout<<i<<" ";
    }
    cout<<"\n";
    for(auto i = descending.begin() ; i!= descending.end() ; i++){
        cout<<*i<<" ";
    }
    return 0;
}
