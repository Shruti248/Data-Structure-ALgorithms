// FIFO/LILO
// Insertion from one end , removal fromanother

// Operations
// 2 pointers: Front and BAck
// Insertion from back and f=removalfrom front pointer

// 1) enqueue(x) : Insertion ofelement (insertion is on back)
// 2) dequeue() : Removal from front
// 3)peek() : value at front..
// 4)empty() : if queue is empty or not

// Array Implementation
// front == -1
// back == -1

//  Enqueue(x) : insert 
    // --> back++
    // --> insert at that position
    // --> front++ (Only when front == -1 else it will remain in same position , front++ happens only when removal takes place)

// dequeue()
    // print the element to be removed
    // --> front++

// peek()

// empty()
    // Return true and false

    // --> when front == back : 1element is present in queue
    // --> when front > back : queue is empty
    // --> front == -1 : queue empty


#include<iostream>
using namespace std;

#define n 20

class queue{
    int* arr;
    int front;
    int back;

    public:
        queue(){
            arr=new int[n];
            front = -1;
            back=-1;
        }

        void push(int x){
            if(back == n-1){
                cout<<"Queue Overflow"<<endl;
                return;
            }
            back++;
            arr[back]=x;

            if(front == -1){
                front++;
            }

        }

        void pop(){
            if(front == -1 || front > back){
                cout<<"Queue Underflow"<<endl;
                return;
            }
            front++;
        }

        int peek(){
            if(front == -1 || front > back){
                cout<<"No elements in Queue"<<endl;
                return -1;
            }

            return arr[front];
        }

        bool empty(){
            if(front == -1 || front > back){
                return true;
            }
            return false;
        }
        
};

int main(){

    queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    cout<<q.peek()<<endl;

    q.pop();
    q.pop();

    cout<<q.peek()<<endl;

    q.pop();
    q.pop();
    q.pop();

    cout<<q.peek()<<endl;
    cout<<q.empty();
    return 0;
}



