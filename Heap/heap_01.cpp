#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int> &heap, int i)
{
    int size = heap.size();
    int largest = i;

    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && heap[left] > heap[largest])
        largest = left;
    if (right < size && heap[right] > heap[largest])
        largest = right;

    if (largest != i)
    {
        swap(heap[i], heap[largest]);
        heapify(heap, largest);
    }
}

void insert(vector<int> &heap, int newNum)
{
    int size = heap.size();

    if (size == 0)
    {
        heap.push_back(newNum);
    }
    else
    {
        heap.push_back(newNum);

        for (int i = size / 2 - 1; i >= 0; i--)
        {
            heapify(heap, i);
        }
    }
}

void deleteNode(vector<int> &heap, int num)
{
    int size = heap.size();
    int i;
    for (i = 0; i < size; i++)
    {
        if (num == heap[i])
            break;
    }

    cout << "Element Present at index : " << i << endl;
    swap(heap[i], heap[size - 1]);

    // Removing the element
    heap.pop_back();

    for (int i = size / 2 - 1; i >= 0; i--)
    {
        heapify(heap, i);
    }
}

// Function to heapify the tree
void heapifyonlyGivenSizeHeap(vector<int> &arr, int n, int i)
{
    // Finding left & right child
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // Setting the largest out of root, left child & right child
    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If index is not equal to largest
    if (largest != i)
    {
        // using std::swap()to swap
        swap(arr[i], arr[largest]);

        // heapifying the tree recursively
        heapifyonlyGivenSizeHeap(arr, n, largest);
    }
}

void heapSort(vector<int> &arr)
{
    int n = arr.size();

    // Building max Heap by heapfying the elements
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapifyonlyGivenSizeHeap(arr, n, i);
    }

    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);

        // Heapify root element recursively to get highest element at root
        heapifyonlyGivenSizeHeap(arr, i, 0);
    }
}

// Heap STL
void heapUsingSTL(vector<int> heap){
    // By default : Max Heap;
    make_heap(heap.begin() , heap.end());

    heap.push_back(4);
    heap.push_back(20);
    push_heap(heap.begin() , heap.end());

    pop_heap(heap.begin() , heap.end());
    heap.pop_back();

    // cout<<"Max Element : "<<heap.front()<<endl;
    for(int i = 0 ; i<heap.size() ; i++){
        cout<<heap[i]<<" ";
    }
}

int main()
{
    vector<int> heap = {};
    insert(heap, 10);
    insert(heap, 8);
    insert(heap, 5);
    insert(heap, 15);
    insert(heap, 6);

    // for (int i = 0; i < heap.size(); i++)
    // {
    //     cout << heap[i] << " ";
    // }

    // cout << endl;
    // deleteNode(heap, 10);

    // for (int i = 0; i < heap.size(); i++)
    // {
    //     cout << heap[i] << " ";
    // }

    cout << endl;
    // heapSort(heap);
    // for (int i = 0; i < heap.size(); i++)
    // {
    //     cout << heap[i] << " ";
    // }

    heapUsingSTL(heap);

    return 0;
}
