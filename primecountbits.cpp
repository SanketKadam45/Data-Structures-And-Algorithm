#include<iostream>

using namespace std;
int countPrimeSetBits(int left, int right) {
    int arr[32];

        for(int j=left;j<=right;j++)
        { int a,i=0;
        while(j>0)
    {
        arr[i]=j%2;
        j=j/2;
        i++;
    }
            a=(j<<i);
            cout<<a<<endl;
        }

    }

    int main()
    {
        int left,right;
        cin>>left>>right;
        cout<<countPrimeSetBits(left,right);
        return 0;
    }
