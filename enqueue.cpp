/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

typedef struct Queue
{
    int rear, front;
    int size,capacity;
    int *arr;
}Queue;

Queue* createQueue(int capacity)
{
    Queue *qu=(Queue*)malloc(sizeof(Queue));
    qu->capacity=capacity;
    qu->size=0;
    qu->front=0;
    qu->rear=capacity-1;
    qu->arr=(int*)malloc(qu->capacity*sizeof(int));
    return qu;
}

int isFull(Queue *queue)
{
    return queue->size==queue->capacity ;
}

int isEmpty(Queue *queue)
{
    return queue->size==0;
}

void enqueue(Queue *queue,int ele)
{
    if(isFull(queue)){
        cout<<"QUEUE IS FULL\n";
    }
    else
    {
        queue->rear=(queue->rear+1)%(queue->capacity);
        queue->arr[queue->rear]=ele;
        queue->size+=1;
    }
}

int front(Queue *queue)
{
    if(isEmpty(queue))
    return 0;

    return queue->arr[queue->front];
}

int rear(Queue *queue)
{
    if(isEmpty(queue))
    return 0;

    return queue->arr[queue->rear];

}

int dequeue(Queue *queue)
{
    if(isEmpty(queue)){
        cout<<"Queue is Empty:";
        return INT_MIN;
    }
    else{
        int data=queue->arr[queue->front];
        queue->front=(queue->front+1)%queue->capacity;
        queue->size=queue->size-1;
        return data;
    }

}

void display(Queue *queue)
{
    for(int i=0;i<queue->size;i++)
    {
        cout<<(queue->arr[queue->front+i])%(queue->capacity);
        cout<<"\n";
    }
}

int main()
{
    int n, capacity;
    cin>>n>>capacity;
    Queue *queue=createQueue(capacity);
    for(int i=0;i<n;i++)
    {
        int ele;
        cin>>ele;
        enqueue(queue,ele);
    }

    display(queue);
    cout<<"FRONT:"<<front(queue)<<"\n";
    cout<<"REAR:"<<rear(queue)<<endl;
dequeue(queue);
display(queue);
dequeue(queue);
cout<<"FRONT:"<<front(queue)<<endl;
cout<<"REAr:"<<rear(queue)<<endl;
    return 0;
}
