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

void push(char data, Stack *st)
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

char pop(Stack *st)
{
    if(isEmpty(st))
    {
        cout<<"STACK UNDERFLOW\n";
        return -1;
    }
    char ele=st->arr[st->top];
    st->top=st->top-1;
    return ele;
}

int prec(char c)
{

    if(c=='^')
        return 3;
    if(c=='/'|| c=='*')
        return 2;
    if(c=='-'||c=='+')
        return 1;
    else
        return -1;

}


void infixTopostfix(string s)
{
Stack* st=(Stack*)malloc(sizeof(Stack));

    int l=s.length();
    string ns;

    for(int i=0;i<l;i++)
    {
        if(s[i]>='a'&&s[i]<='z'||s[i]>='A'&&s[i]<='Z')
           {

            ns=ns+s[i];
           }
           else if(s[i]=='(')
                    {
                        st.push(s[i],*st);
                    }
                    else if(s[i]==')')
                    {
                        while(st.peek()!='#' && st.peek()!='(')
                        {
                            char c=st.pop()
                              ns=ns+c;
                        }
                        if(st.peek()=='(')
                        {
                            st.pop();
                        }
                    }
                    else{
                        while(st.peek()!='#'&&prec(s[i]<=prec(st.peek())))
                        {
                            char ch=st.pop;
                            ns=ns+c;
                        }
                        st.push(s[i]);
                    }

    }
    while(st.peek()!='#')
    {
        char c=st.pop();
        ns=ns+c;
    }
    cout<<ns;
}



int main()
{
    int n;
    char ele;
    string s;

    cin>>n;
    Stack *st=initialiseStack(n);

    for(int i=0;i<n;i++)
    {
        cin>>ele;
        push(ele,st);
    }
    cout<<"SIZE OF STACK:"<<size(st);
    infixTopostfix(st,s);

}
