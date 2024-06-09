#include <bits/stdc++.h>
using namespace std;

// digits from the given number
vector<int> digits(int num)
{
    int rem;
    vector<int> d;
    while (num > 0)
    {
        rem = num % 10;
        num = num / 10;
        d.push_back(rem);
    }

    return d;
}

// Loweest Permutaion of the given number
int lowestPermutation(int num)
{
    string temp = to_string(num);

    sort(temp.begin(), temp.end());

    int i = 0;
    while (temp[i] == '0')
    {
        i++;
    }

    swap(temp[0], temp[i]);

    return stoi(temp);
}

// Find the largest number that can be formed by changing at most K digits
string largestNumberByChangingKDigits(string num, int k)
{
    int i = 0;
    while (k > 0)
    {
        if (num[i] != '9')
        {
            num[i] = '9';
            k--;
        }
        i++;
    }
    return num;
}

int main()
{
    // vector<int> d = digits(123);
    // for(int i = 0 ; i<d.size() ; i++){
    //     cout<<d[i]<< " ";
    // }
    // cout << lowestPermutation(5468001);

    cout<<largestNumberByChangingKDigits("569431" , 3);
    return 0;
}
