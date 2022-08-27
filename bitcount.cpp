#include <iostream>

using namespace std;

int convert(int num)
{
    int count=0;
    int arr[32];

    int i=0;
    while(num>0)
    {
        arr[i]=num%2;
        num=num/2;
        i++;
    }


    for(int j=0;j<i;j++){
        if(arr[j]==1)
            count++;
    }
    return count;
}



int main()
{
    int num;
    cin>>num;
    do
    {
        cout<<convert(num);
        num--;
    }while(num>0);

    return 0;
}
