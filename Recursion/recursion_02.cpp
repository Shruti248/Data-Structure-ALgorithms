#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // check if the array is sorted or not

    // 1 2 3 4 5 6 7 8 --> Stricly increasing
    // array[0] < array[1] AND array[1 ... n] SORTED --> Checl this 2

    // array at n = array at n-1 is smaller
    // array at n-1 = array at n-2 is smaller
    // array at n-2 = array at n-3 is smaller

    // array at 2nd position = array at 1st position is smaller

    bool isArraySorted(int arr[], int n)
    {

        // Base Condition
        if (n == 1)
        {
            return true;
        }

        bool restArray = isArraySorted(arr + 1 /**From 1st index rather than 0*/, n - 1);

        // if(arr[0] < arr[1] && restArray){
        //     // If both conditions are satisfied
        //     return true;
        // }

        // return false;

        // Same as above commented portion
        return (arr[0] < arr[1] && restArray);
    }

    // Print numbers till n
    // 1) Decreasing Order
    // n , n-1 .... 0
    // 2) Increasing order

    void printNumbers(int n)
    {
        // Decreasing Order
        // if(n==0){
        //     return;
        // }

        // cout<<n<<endl;
        // printNumbers(n-1);

        // Increasing Order
        if (n == 0)
        {
            return;
        }

        printNumbers(n - 1);
        cout << n << endl;
    }

    // Find First And Last Occurence of the Number in a Array
    // 1) First occurence
    // -- Traverse using recursion from first
    // 2) Last Occurence
    // -- Traverse from start only -- opposite of first

    int firstOccurence(int arr[], int n, int i /**search from position*/, int key)
    {

        if (i == n)
        {
            return -1;
        }

        if (arr[i] == key)
        {
            return i;
        }
        return firstOccurence(arr, n, i + 1, key);
    }

    // First it will traverse all the way to last and then it will check from there
    int lastOccurence(int arr[], int n, int i, int key)
    {

        if (i == n)
        {
            return -1;
        }
        int restArray = lastOccurence(arr, n, i + 1, key);

        if (restArray != -1)
        {
            return restArray;
        }

        if (arr[i] == key)
        {
            return i;
        }
        return -1;
    }

    // Reverse a strig using Recursion
    void reverseAString(string s)
    {
        // Return an empty strig
        // Base
        if (s.length() == 0)
        {
            return;
        }

        // after 1st index , complete string
        string restString = s.substr(1);
        reverseAString(restString);
        cout << s[0];
    }

    // Replace pi with 3.14 in string
    // ith and i+1 element : pi --> Replace   & Print rest characters
    // Rest , call again
    void replacePI(string s)
    {
        // Base case
        if (s.length() == 0)
        {
            return;
        }

        // Recursive Case
        if (s[0] == 'p' && s[1] == 'i')
        {
            cout << "3.14";
            replacePI(s.substr(2));
        }
        else
        {
            cout << s[0];
            replacePI(s.substr(1));
        }
    }

    // Tower of Hanoi
    //  A : Source  , B : Helper Rod , C : Destination

    // n-1 from A to helper
    // A to C : nth
    // n-1 from helper to C

    void towerOfHanoi(int n, char src, char dest, char helper)
    {

        // Base
        if (n == 0)
        {
            return;
        }
        // bcoz n-1 moves from src to helper
        towerOfHanoi(n - 1, src, helper, dest);
        cout << "Move From " << src << " to " << dest << endl;
        // n-1 from helper to C
        towerOfHanoi(n - 1, helper, dest, src);
    }

    // Remove All Adjacent Duplicates from the string
    string removeDuplicates(string s)
    {
        // Base case
        if (s.length() == 0)
        {
            return ""; 
        }
        // Recursive Case
        char ch = s[0];
        string ans = removeDuplicates(s.substr(1));

        if(ch == ans[0]){
            return ans;
        }
        return ch+ans;
    }

    // Move All x to the end of the string
    void moveXtoEndOfString(string s){
        if(s.length() == 0){
            return;
        }

        string XString = "";
        if(s[0] == 'x'){
            XString = XString + s[0];
            moveXtoEndOfString(s.substr(1));
        }else{
            cout<<s[0];
            moveXtoEndOfString(s.substr(1));
        }

        cout<<XString;
    }

    // Generate All Substrings of a STring 
    // Length of strig = n 
    // Number of substrigs = 2^n

    // ABC : "" , A , AB , B , C , AC , BC , ABC 
    // At every step , we are adding a character and also not adding it...

    void allPossibleSubstrings(string s , string ans){

        if(s.length() == 0){
            cout<<ans<<endl;
            return;
        }

        char ch = s[0];

        string restString = s.substr(1);

        allPossibleSubstrings(restString , ans);
        allPossibleSubstrings(restString , ans+ch);
    }

    // Subsequences 
    void substringsWithASCIINumber(string s , string ans){

        if(s.length() ==0){
            cout<<ans<<endl;
            return;
        }
        // 3 recursive calls are made 
        // Once we do not add the character
        // Adding the charcater
        // Adding the ascii value of the character

        char ch = s[0];
        int code  = ch;
        string restString = s.substr(1);

        substringsWithASCIINumber(restString , ans);
        substringsWithASCIINumber(restString , ans+ch);
        substringsWithASCIINumber(restString , ans+to_string(code));

    }


};
int main()
{
    Solution s;
    // int n;
    // cin >> n;
    // int arr[n];
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> arr[i];
    // }
    // cout << s.isArraySorted(arr, n);

    // s.printNumbers(n);

    // int i, key;
    // cin >> i;
    // cin >> key;
    // cout << s.firstOccurence(arr, n, i, key)<<endl;
    // cout << s.lastOccurence(arr, n, i, key)<<endl;

    string str;
    cin >> str;
    // s.reverseAString(str);
    // s.replacePI(str);

    // char src, dest, helper;
    // cin >> src >> dest >> helper;

    // s.towerOfHanoi(n, src, dest, helper);
    // cout<<s.removeDuplicates(str);

    // s.moveXtoEndOfString(str);
    string ans = "";
    // s.allPossibleSubstrings(str , ans);
    s.substringsWithASCIINumber(str , ans);
    return 0;
}