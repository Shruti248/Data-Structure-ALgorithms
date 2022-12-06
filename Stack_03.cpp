// Without stl
#include <iostream>
using namespace std;

#define MAX 10

int size = 0;

struct Stack
{
    /* data */
    int items[MAX];
    int top;
};

void createEmptyStack(Stack *s)
{
    s->top = -1;
}

int isFull(Stack *s)
{
    if (s->top == MAX - 1)
        return 1;
    else
        return 0;
}

int isEmpty(Stack *s)
{
    if(s->top == -1)
        return 1;
    else    
        return 0;
}

void push(Stack *s , int newItem){
    if(isFull(s) == true){
        cout<<"STACK FULL"<<endl;
    }else{
        s->top++;
        s->items[s->top] = newItem;
    }
    size++;
}

void pop(Stack *s){
    if(isEmpty(s) == true){
        cout<<"STACK EMPTY"<<endl;
    }else{
        cout<<"Item Popped : "<<s->items[s->top]<<endl;
        s->top--;
    }
    size--;
}

void print_Stack(Stack *s){
    cout<<"Stack is : "<<endl;
    for (int i = 0; i < size; i++)
    {
        /* code */
        cout<<s->items[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    Stack *s = (Stack *)malloc(sizeof(Stack));

    createEmptyStack(s);

    isEmpty(s);
    isFull(s);

    push(s , 5);
    push(s , 6);
    push(s , 7);
    push(s , 8);
    pop(s);

    print_Stack(s);

    return 0;
}
