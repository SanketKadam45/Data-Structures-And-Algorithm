#include<iostream>

using namespace std;
typedef struct stack
{
    int capacity;
    int top;
    int *arr;
}Stack;


Stack* initialiseStack(int capacity)
{
    Stack* st=(Stack*)malloc(sizeof(Stack));
    st->capacity=capacity;
    st->top=-1;
    st->arr=(int*)malloc(sizeof(int)*capacity);
    return st;
}

int size(Stack *st)
{
    return st->top+1;
}

int isEmpty(Stack *st)
{
    if(st->top==-1)
        return -1;
}

int isFull(Stack *st)
{
    return st->top+1==st->capacity;

}

void push(int data, Stack *st)
{
    if(isFull(st))
    {
        cout<<"STACK OVERFLOW:";
        return;
    }
    ++st->top;
    st->arr[st->top]=data;
}

int peek(Stack *st)
{
    if(isEmpty(st))
    {
        cout<<"STACK EMPTY:";
        return -1;
    }
    return st->arr[st->top];
}

int pop(Stack *st)
{
    if(isEmpty(st))
    {
        cout<<"STACK UNDERFLOW\n";
        return -1;
    }
    int ele=st->arr[st->top];
    st->top=st->top-1;
    return ele;
}

void display(Stack *st)
{
    for(int i=0;i<size(st);i++)
    {
        cout<<st->arr[i]<<" ";
    }
}

int main()
{
    int capacity,n,ele;
    cin>>capacity;
    cin>>n;
    Stack *st=initialiseStack(capacity);

    for(int i=0;i<n;i++)
    {
        cin>>ele;
        push(ele,st);
    }
    cout<<"SIZE OF STACK:"<<size(st);
    display(st);
}
