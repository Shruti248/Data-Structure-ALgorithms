#include <bits/stdc++.h>
#include <set>
using namespace std;

int main()
{
    set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(2);
    s.insert(3);
    // NO duplicate elements in set & therefore only 1 will be printed

    for (auto i : s)
    {
        cout << i << " ";
    }
    cout << "\n";
    for (auto i = s.begin(); i != s.end(); i++)
    {
        cout << *i << " ";
    }
    cout << "\n";

    // Print in reverse
    for (auto i = s.rbegin(); i != s.rend(); i++)
    {
        cout << *i << " ";
    }
    cout << "\n";
    cout << s.size() << endl;

    // Custom Camparator
    // Default set is in ascending order
    set<int> ascendingyDefault;
    set<int, greater<int>> descending;

    descending.insert(1);
    descending.insert(2);
    descending.insert(2);
    descending.insert(3);
    // NO duplicate elements in set & therefore only 1 will be printed

    for (auto i : descending)
    {
        cout << i << " ";
    }
    cout << "\n";
    for (auto i = descending.begin(); i != descending.end(); i++)
    {
        cout << *i << " ";
    }

    // Deletion

    // For single element.
    // name_of_set.erase(iterator);

    // // For single element.
    // name_of_set.erase(element_to_delete);

    // // For the deletion of multiple elements.
    // name_of_set.erase(start_iterator, end_iterator);

    cout << "-------------------------" << endl;
    cout << s.erase(1);
    cout << s.erase(2);
    cout << s.erase(3);
    cout << s.erase(4);
    // If element present & erased : Return 1 --> else 0
    for (auto i : s)
    {
        cout << i << " ";
    }
    cout << "\n";
    for (auto i = s.begin(); i != s.end(); i++)
    {
        cout << *i << " ";
    }
    cout << "\n";

    cout << "-------------------------" << endl;
    // All O(1)
    cout << s.size()<<endl;
    cout << s.empty()<<endl;
    cout << s.max_size()<<endl; // Returns the maximum allowed size/length of the set

    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(5);

    cout << "-------------------------" << endl;
    cout<<"Operatios in the Set"<<endl;
    cout << "-------------------------" << endl;
    // O(logN)
    // Find : Returns the iterator to the element specified if found, else return the iterator to the end of the set
    cout<<*s.find(1)<<endl;
    cout<<*s.find(6)<<endl;
    cout << "-------------------------" << endl;

    // O(logN)
    // count : Returns 1 if the specified element is found, else 0
    cout<<s.count(1)<<endl;
    cout<<s.count(6)<<endl;
    cout << "-------------------------" << endl;

    // O(logN)
    // Returns the iterator to the specified element if it is found, else return the just greater next element.
    cout<<*s.lower_bound(2)<<endl;
    cout<<*s.lower_bound(3)<<endl;
    cout<<*s.lower_bound(0)<<endl;
    cout<<*s.lower_bound(5)<<endl;
    cout << "-------------------------" << endl;
    // O(logN)
    // Returns the iterator to the very next element of the specified element
    cout<<*s.upper_bound(0)<<endl;
    cout<<*s.upper_bound(1)<<endl;
    cout<<*s.upper_bound(2)<<endl;
    // if last or not present then returns last only
    cout<<*s.upper_bound(5)<<endl;
    cout<<*s.upper_bound(6)<<endl;
    cout << "-------------------------" << endl;


    multiset<int>  multiset;
    multiset.insert(1);
    multiset.insert(2);
    multiset.insert(3);
    multiset.insert(3);
    multiset.insert(3);
    multiset.insert(3);
    multiset.insert(5);

    cout << "-------------------------" << endl;
    for(auto i : multiset){
        cout<<i<<" ";
    }
    cout<<endl;
    for(auto i= multiset.begin() ; i != multiset.end() ; i++){
        cout<<*i<<" ";
    }
    cout<<endl;
    cout << "-------------------------" << endl;
    cout<<multiset.size()<<endl;
    cout << "-------------------------" << endl;
    // Deletes all the occurences of 3
    // multiset.erase(3);
    for(auto i= multiset.begin() ; i != multiset.end() ; i++){
        cout<<*i<<" ";
    }
    cout<<endl;
    // Erase only 1 occurence of 3
    multiset.erase(multiset.find(3));
    for(auto i= multiset.begin() ; i != multiset.end() ; i++){
        cout<<*i<<" ";
    }

    return 0;
}
