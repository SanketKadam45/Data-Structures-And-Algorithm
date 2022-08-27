/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

typedef struct Node{
    int data;
    struct Node* next;

}Node;
Node *head=NULL;

void insert(int data)
{
    Node* newnode=(Node*)malloc(sizeof(Node));
    newnode->data=data;
    newnode->next=NULL;

    Node* temp=head;
    if(temp==NULL)
    {
        head=newnode;
        return;
    }
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;

}
void display()
{
    Node* temp;
    temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

int deleteatend()
{
    int last;
    Node* temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    //last=temp->data;
    return temp->data;
    free(temp);



}
void insertatbeg(int last)
{
    Node *newnode=(Node*)malloc(sizeof(Node));
    newnode->data=last;
    newnode->next=head;
    head=newnode;
}

void deleteat()
{
    Node *temp=head;
    if(temp==NULL)
    {
        cout<<"EMPTY:";
        return;
    }

    if(temp->next==NULL)
    {
        head=NULL;
        free(temp);
        return;
    }
    while(temp->next->next!=NULL)
    {
    temp=temp->next;
    }
    Node* temp1=temp->next;
    temp->next=NULL;
    free(temp1);
}
int main()
{
int t,n,data;
int last;
cin>>t;
while(t--)
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
    cin>>data;
    insert(data);
    }
    //last=deleteatend();
//cout<<last;
//insertatbeg(last);
//deleteat();
display();
head=NULL;
}




    return 0;
}
