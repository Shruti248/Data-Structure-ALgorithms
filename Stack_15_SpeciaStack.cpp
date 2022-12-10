//{ Driver Code Starts
#include<iostream>
#include<stack>
#include<vector>
using namespace std;
void push(stack<int>& s,int a);
bool isFull(stack<int>& s,int n);
bool isEmpty(stack<int>& s);
int pop(stack<int>& s);
int getMin(stack<int>& s);
//This is the STL stack (http://quiz.geeksforgeeks.org/stack-container-adaptors-the-c-standard-template-library-stl/).
stack<int> s;

// } Driver Code Ends


void push(stack<int>& s, int a){
	// Your code goes here
	s.push(a);
}

bool isFull(stack<int>& s,int n){
	// Your code goes here
    if(s.size() == n){
        return true;
    }
    return false;
	
}

bool isEmpty(stack<int>& s){
	// Your code goes here
    if(s.empty()){
        return true;
    }
    return false;
}

int pop(stack<int>& s){
	// Your code goes here
    s.pop();
}

int getMin(stack<int>& s){
	// Your code goes here
    vector<int> arr;
    int min;
    while(!s.empty()){
        arr.push_back(s.top());
        s.pop();
    }

    for(int i = 0 ; i<arr.size(); i++){
        
        if(arr[i] < min){
            min = arr[i];
        }
    }
    return min;

}

int main(){
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    cout<<"Min :"<<getMin(s);
    return 0;

}