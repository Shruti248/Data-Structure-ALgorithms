#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void selectionSort(int arr[], int size)
    {
        
        for (int i = 0; i < size-1; i++)
        {
            int min = arr[i]; 
            for (int j = i+1; j < size; j++)
            {
                if (arr[j] < arr[i])
                {
                    // Swap
                    int temp = arr[j];
                    arr[j]=arr[i];
                    arr[i] = temp;
                }
            }
           

        }
        
        cout<<"Sorted Array is : ";
        for(int i = 0 ; i<size ; i++){
            cout<<arr[i];
        }
    }
};
int main()
{
    Solution s;
    int size;
    cin >> size;
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    s.selectionSort(arr, size);
    return 0;
}