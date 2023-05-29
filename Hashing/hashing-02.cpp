#include<bits/stdc++.h>
#include<iostream>
#include<map>
using namespace std;

// Hashing in STL
// Maps : Insertion O(log(n))
// Maps : Accessing O(log(n))
// Maps :  Implemented using red black trees

// unordered maps : Insertion O(1)
// unordered maps : accessing  O(1)
// unordered maps : implemented using hash Tables (basically array of buckets)

int main(){
    // Declartion
    // map <key_dataType, value_dataType> mapName;

    map<string , int> mp;

    // Asign Values
    mp["Asia"] = 1;
    mp["Europe"] = 2;
    mp["Australia"] = 3;
    // mp["Australia"] = 4;
    // mp["Australia"] = 5;
    // mp["Australia"] = 6;
    // In multiple values : Last Value is returned
    mp["Antartica"] = 4;

    // Retrieving values using the operator []
    cout<<mp["Asia"]<<endl;
    cout<<mp["Australia"]<<endl;

    // Retrieving values using the at operator.
    // Prints the value associated with the key Asia , i.e. 1
    cout << mp.at("Asia") << endl;

    // Chaning values using the at operator.
    mp.at("Asia") = 9;
    cout<<mp["Asia"];

    // Since there is no key(India) with value 5 in the map, it will create a key India with value 5.
    mp["India"] = 5;
    cout<<mp["India"]<<endl;
    // if used at above , then it will throw the exception

    // O(1)
    cout<<mp.empty()<<endl;

    // O(1)
    cout<<mp.size()<<endl;

    // O(1)
    cout<<mp.max_size()<<endl;

    // Modifiers
    // Insertion O(logn);
    mp.insert({"New Key" , 10});
    cout<<mp["New Key"]<<endl;

    // Erase : O(logn)
    mp.erase("New Key");

    // O(n)
    mp.clear();

    cout<<mp.empty();
    cout<<mp.empty();
    cout<<mp.empty();

    // Iterators
    mp.begin();
    mp.end();
    mp.rbegin();
    mp.rend();
    mp.cbegin();
    mp.cend();
    mp.crbegin();
    mp.crend();
    // Note: All of the above function return iterators, that is, pointers pointing to an element of the cointainer map.

    // Searching & Counting

    // O(logn)
    mp.find("Asia");
    // O(logn)
    mp.count("Asia");
    // O(logn)
    mp.lower_bound("Asia");
    // O(logn)
    mp.upper_bound("Asia");
    // O(logn)
    mp.equal_range("Asia");
    return 0;
}
