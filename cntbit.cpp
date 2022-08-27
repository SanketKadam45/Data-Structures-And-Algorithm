#include <iostream>
#include<vector>


using namespace std;

 vector<int> countBits(int n) {
    int count=0;
    vector<int> v;
    int i=0;
    while(n>0)
    {
        v[i]=n%2;
        n=n/2;
        i++;
    }

        for(int j=0;j<i;j++){
        if(v[j]==1)
            count++;

        }
        return v;
}


int main()
{
    int num;
    cin>>num;
    vector<int> vs=countBits(num);
    int size=vs.size();
    cout<<size;



    return 0;
}

