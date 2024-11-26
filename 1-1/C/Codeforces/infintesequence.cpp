#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    cin>>n;
    long long count=0;
    int temp=0;
    for(int i=1;i>=1;i++)
    {
        for(int j=1;j<=i;j++)
        {
            count++;
            if(count==n)
            {
                cout<<j<<endl;
                temp=1;
                break;
            }
        }
        if(temp==1)
        {
            break;
        }
    }
    return 0;
}