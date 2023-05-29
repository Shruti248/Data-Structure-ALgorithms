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
void heapUsingSTL(vector<int> heap)
{
    // By default : Max Heap;
    make_heap(heap.begin(), heap.end());

    heap.push_back(4);
    heap.push_back(20);
    push_heap(heap.begin(), heap.end());

    pop_heap(heap.begin(), heap.end());
    heap.pop_back();

    // deafult : Ascending Order
    sort_heap(heap.begin(), heap.end());

    // is maxHeap = true
    // if not : false
    bool isHeap = is_heap(heap.begin(), heap.end());
    cout << isHeap << endl;

    auto iteratortillHeap = is_heap_until(heap.begin(), heap.end());
    for (auto it = heap.begin(); it != iteratortillHeap; it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    // cout<<"Max Element : "<<heap.front()<<endl;
    for (int i = 0; i < heap.size(); i++)
    {
        cout << heap[i] << " ";
    }
}

// Prioroty queue

void heapUsingPriorityQueue()
{
    // Push O(logn)
    // pop O(logn)
    // top O(1)
    // size O(1)
    priority_queue<int, vector<int>> pq;

    pq.push(2);
    pq.push(3);
    pq.push(1);

    cout << pq.top() << endl;
    pq.pop();
    cout << pq.top() << endl;

    priority_queue<int, vector<int>, greater<int>> pqMinHeap;
    pqMinHeap.push(3);
    pqMinHeap.push(2);
    pqMinHeap.push(1);
    cout << pqMinHeap.top() << endl;
    pqMinHeap.pop();
    cout << pqMinHeap.top() << endl;
}

// Challenges
// Median of Runnig Stream
// Number are coming and we have to tell the median after each input

// Brute Force : Sort after each input O(nlogn) & then median O(n) --> O(n2logn)

// Optimal
// Keep one max Heap & one min Heap
// Partition the array into 2 parts
// If sizes of max heap & minHeap not equal : Top of larger size heap
// Else : Average of top of both heaps

void insert(int x ,  priority_queue<int, vector<int>, greater<int>> &pqmin , priority_queue<int, vector<int>> &pqmax ){
    if(pqmin.size() == pqmax.size()){
        if(pqmax.size() == 0){
            pqmax.push(x);
            return;
        }

        if(x<pqmax.top()){
            pqmax.push(x);
        }else{
            pqmin.push(x);
        }
    }else{
        // 2 cases
        if(pqmax.size() > pqmin.size()){
            if( x>= pqmax.top()){
                pqmin.push(x);
            }else{
                int temp = pqmax.top();
                pqmax.pop();
                pqmin.push(temp);
                pqmax.push(x);
            }
        }else{
            if(x<=pqmin.top()){
                pqmax.push(x);
            }else{
                int temp = pqmin.top();
                pqmin.pop();
                pqmax.push(temp);
                pqmin.push(x);
            }
        }

    }
}

double medianOfRunningStream(priority_queue<int, vector<int>, greater<int>> &pqmin , priority_queue<int, vector<int>> &pqmax)
{
    if(pqmin.size() == pqmax.size()){
        return (pqmin.top()+pqmax.top())/2.0; //.0 for typecasting
    }else if(pqmax.size() > pqmin.size()){
        return pqmax.top();
    }else{
        return pqmin.top();
    }
}

int main()
{
    // vector<int> heap = {};
    // insert(heap, 10);
    // insert(heap, 8);
    // insert(heap, 5);
    // insert(heap, 15);
    // insert(heap, 6);

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

    // cout << endl;
    // heapSort(heap);
    // for (int i = 0; i < heap.size(); i++)
    // {
    //     cout << heap[i] << " ";
    // }

    // heapUsingSTL(heap);
    // heapUsingPriorityQueue();

    priority_queue<int, vector<int>, greater<int>> pqmin; // minHeap
    priority_queue<int, vector<int>> pqmax;               // maxHeap

    insert(10 , pqmin , pqmax);
    cout<<medianOfRunningStream(pqmin , pqmax)<<endl;
    insert(15 , pqmin , pqmax);
    cout<<medianOfRunningStream(pqmin , pqmax)<<endl;
    insert(21 , pqmin , pqmax);
    cout<<medianOfRunningStream(pqmin , pqmax)<<endl;
    insert(30 , pqmin , pqmax);
    cout<<medianOfRunningStream(pqmin , pqmax)<<endl;
    insert(18 , pqmin , pqmax);
    cout<<medianOfRunningStream(pqmin , pqmax)<<endl;
    insert(19 , pqmin , pqmax);
    cout<<medianOfRunningStream(pqmin , pqmax)<<endl;


    return 0;
}
