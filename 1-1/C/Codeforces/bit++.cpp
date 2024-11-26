#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int sum=0;
    while(n--)
    {
        char str[4];
        cin>>str;
        if(str[2]=='+' || str[0]=='+')
        {
            sum++;
        }
        else if(str[2]=='-' || str[0]=='-')
        {
            sum--;
        }
    }
    cout<<sum<<endl;
    return 0;
}