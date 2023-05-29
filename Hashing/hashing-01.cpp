#include<bits/stdc++.h>
using namespace std;

class hash_table{
    list<int> *tbl;
    int ht_size;

    int get_hash(int key){
        return key%ht_size;
    }

    public:
        hash_table(int n){
            ht_size = n;
            tbl = new list<int>[ht_size];
        }

        void insert_key(int key){
            tbl[get_hash(key)].push_back(key);
        }

        void show(){
            for(int i = 0 ; i<ht_size ; i++){
                cout<<"Values at index "<<i<<" : ";
                for(int num : tbl[i]){
                    cout<<num<<" ";
                }
                cout<<endl;
            }
        }
};

int main(){
    // // Character Hashing
    // char ch = 'n';

    // hash<char> ch_hash;

    // cout<<ch_hash(ch)<<endl;

    // // String Hashing
    // string str = "hashing";

    // hash<string> string_hash;

    // cout<<string_hash(str)<<endl;

    // // Integer Hashing
    // int num = 17;
    // hash<int> int_hash;
    // cout<<int_hash(num)<<endl;

    // // Vector Hashing
    // vector<bool> vec = { true , true , false , false};

    // hash<vector<bool>> vector_hash;
    // cout<<vector_hash(vec)<<endl;

        // Creating an array of keys.
    int arr[] = {52, 42, 44, 66, 25, 29, 32};

    // Find the size of the array.
    int sz_arr = sizeof(arr)/sizeof(int);

    // Initializing the hash table.
    hash_table ht(sz_arr);

    // Inserting the elements into the hash table.
    for(int i = 0; i < sz_arr; i++) {
        ht.insert_key(arr[i]);
    }
    cout << "The hash table after insertion of elements: " << endl;
    // Calling function to display the hash table.
    ht.show();

    return 0;
}
