#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int EqualArrays(int arr1[], int arr2[], int n1, int n2)
    {
        if (n1 != n2)
        {
            return 0;
        }
        else if (!is_sorted(arr1, arr1 + n1) && !is_sorted(arr2, arr2 + n2))
        {
            sort(arr1, arr1 + n1);
            sort(arr2, arr2 + n2);
        }
        for(int i = 0 ; i< n1 ; i++){
                if(arr1[i] == arr2[i]){
                    continue;
                }else{
                    return 0;
                }
            
        }
        return 1;
    }
};

int main()
{
    Solution s;
    int n1; // Size of Array 1
    cout << "Size of Array 1 : ";
    cin >> n1;

    int arr1[n1];
    cout << "Elemets of Array 1 : ";
    for (int i = 0; i < n1; i++)
    {
        cin >> arr1[i];
    }

    int n2; // Size of Array 1
    cout << "Size of Array 2 : ";
    cin >> n2;

    int arr2[n2];
    cout << "Elemets of Array 2 : ";
    for (int i = 0; i < n2; i++)
    {
        cin >> arr2[i];
    }

    int result = s.EqualArrays(arr1, arr2, n1, n2);
    if(result == 1){
        cout<<"Arrays are Equal"<<endl;
    }else{
        cout<<"Arrays are not Equal"<<endl;
    }
    return 0;
}


