#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Selection sort is a sorting algorithm that selects the smallest element from an unsorted list in each iteration and places that element at the beginning of the unsorted list.
    void selectionSort(int arr[], int size)
    {

        for (int i = 0; i < size - 1; i++)
        {
            int min = arr[i];
            for (int j = i + 1; j < size; j++)
            {
                if (arr[j] < arr[i])
                {
                    // Swap
                    int temp = arr[j];
                    arr[j] = arr[i];
                    arr[i] = temp;
                }
            }
        }

        cout << "Sorted Array Using Selection Sort : ";
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl
             << endl;
    }

    // Bubble sort is a sorting algorithm that compares two adjacent elements and swaps them until they are in the intended order.
    void bubbleSort(int arr[], int size)
    {
        for (int iterations = 0; iterations < size; iterations++)
        {
            for (int i = 0; i < size - iterations; i++)
            {
                if (arr[i] > arr[i + 1])
                {
                    // swap
                    int temp = arr[i];
                    arr[i] = arr[i + 1];
                    arr[i + 1] = temp;
                }
            }
        }

        // Print Sorted Array
        cout << "Sorted Array Using Bubble Sort : ";
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl
             << endl;
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
    s.bubbleSort(arr, size);
    return 0;
}