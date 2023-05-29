#include <bits/stdc++.h>
#include <iostream>
#include <map>
using namespace std;

// Hashing in STL
// Maps : Insertion O(log(n))
// Maps : Accessing O(log(n))
// Maps :  Implemented using red black trees

// unordered maps : Insertion O(1)
// unordered maps : accessing  O(1)
// unordered maps : implemented using hash Tables (basically array of buckets)

// Challenges

// Count Frequency of elements
// Key : Array Elements
// Value : Frequency

void countFrequencyofElements(vector<int> arr)
{
    map<int, int> freq;

    for (int i = 0; i < arr.size(); i++)
    {
        freq[arr[i]]++;
    }

    // Iterate over Map & print Frequency
    map<int, int>::iterator it;
    for (it = freq.begin(); it != freq.end(); it++)
    {
        cout << it->first << " " << it->second << endl;
    }
}

// Print Vertical Order of the BInary Tree

// COmpute the horizontal Distance .... Root : H = 0 , left : -1 , rright :  +1 & so on
// Vectical order : -1 0 1 Horizontal Distance

// Start from root node
// Recursively call the left & right with HD-1 & HD+1 as arguments
// Push the value in vector corressonding to the horizontal Distance
// Key : Horizontal Distance , value (Vector) : Elements  at that HD
// Output the MAP

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node* newNode(int data){
    Node* node = new Node;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}
void verticalOrderofTheBInaryTree(Node* root , int hDist , map<int , vector<int>> &m)
{
    if(root == NULL){
        return;
    }

    m[hDist].push_back(root->data);

    verticalOrderofTheBInaryTree(root->left , hDist-1 , m);
    verticalOrderofTheBInaryTree(root->right , hDist+1 , m);
}

// Count Number of Subarrays with Sum Zero
// Brute Force : All Possible subarrays : O(n2)
//Oprimized :
// Compute Prefix Sum : Su from Starting till i

// Map Prefix Sum to a Map
// For Every Key , choose 2 values from all the occurences of the particular prefix Sum (mC2)
// Special Case : For prefSum 0 , we have to also include them

int numberofSubarraysWithSumZero(vector<int> arr){
    map<int , int> count;

    int prefixSum = 0;

    for(int i = 0 ; i<arr.size() ; i++){
            prefixSum += arr[i];

            count[prefixSum]++;
    }

    int ans = 0;

    map<int , int> ::iterator it;

    for(it = count.begin() ; it != count.end() ; it++){
        int c = it->second;

        ans += c*(c-1)/2;

        if(it->first == 0){
            ans += it->second;
        }
    }

    return ans;

}
int main()
{
    // Declartion
    // map <key_dataType, value_dataType> mapName;

    // map<string , int> mp;

    // // Asign Values
    // mp["Asia"] = 1;
    // mp["Europe"] = 2;
    // mp["Australia"] = 3;
    // // mp["Australia"] = 4;
    // // mp["Australia"] = 5;
    // // mp["Australia"] = 6;
    // // In multiple values : Last Value is returned
    // mp["Antartica"] = 4;

    // // Retrieving values using the operator []
    // cout<<mp["Asia"]<<endl;
    // cout<<mp["Australia"]<<endl;

    // // Retrieving values using the at operator.
    // // Prints the value associated with the key Asia , i.e. 1
    // cout << mp.at("Asia") << endl;

    // // Chaning values using the at operator.
    // mp.at("Asia") = 9;
    // cout<<mp["Asia"];

    // // Since there is no key(India) with value 5 in the map, it will create a key India with value 5.
    // mp["India"] = 5;
    // cout<<mp["India"]<<endl;
    // // if used at above , then it will throw the exception

    // // O(1)
    // cout<<mp.empty()<<endl;

    // // O(1)
    // cout<<mp.size()<<endl;

    // // O(1)
    // cout<<mp.max_size()<<endl;

    // // Modifiers
    // // Insertion O(logn);
    // mp.insert({"New Key" , 10});
    // cout<<mp["New Key"]<<endl;

    // // Erase : O(logn)
    // mp.erase("New Key");

    // // O(n)
    // mp.clear();

    // cout<<mp.empty();
    // cout<<mp.empty();
    // cout<<mp.empty();

    // // Iterators
    // mp.begin();
    // mp.end();
    // mp.rbegin();
    // mp.rend();
    // mp.cbegin();
    // mp.cend();
    // mp.crbegin();
    // mp.crend();
    // // Note: All of the above function return iterators, that is, pointers pointing to an element of the cointainer map.

    // // Searching & Counting

    // // O(logn)
    // mp.find("Asia");
    // // O(logn)
    // mp.count("Asia");
    // // O(logn)
    // mp.lower_bound("Asia");
    // // O(logn)
    // mp.upper_bound("Asia");
    // // O(logn)
    // mp.equal_range("Asia");

    // vector<int> arr = {1, 2, 1, 3, 2, 1};
    // countFrequencyofElements(arr);


    // Node *root = newNode(1);
    // root->left = newNode(2);
    // root->right = newNode(3);
    // root->left->left = newNode(4);
    // root->left->right = newNode(6);
    // root->right->left = newNode(5);
    // root->right->right = newNode(7);

    // map<int , vector<int> > m;
    // int hDist = 0;

    // verticalOrderofTheBInaryTree(root , hDist , m);

    // map<int , vector<int>> :: iterator it;

    // for(it = m.begin() ; it != m.end() ; it++){
    //     for(int i = 0 ; i<(it->second).size() ; i++){
    //         cout<<(it->second)[i]<<" ";
    //     }
    //     cout<<endl;
    // }

    vector<int> arr = {1 , -1 , 1 , -1};
    cout<<numberofSubarraysWithSumZero(arr)<<endl;


    return 0;
}
