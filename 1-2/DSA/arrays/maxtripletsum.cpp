#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n<3){
            cout<<"Invalid input\n";
        }
        else{
            vector<int>arr(n);
            for(int i=0;i<n;i++){
                cin>>arr[i];
            }

            vector<int>ans(3);
            int maxsum=INT_MIN;
            for(int i=0;i<n-2;i++){
                int sum=arr[i]+arr[i+1]+arr[i+2];
                if(sum>maxsum){
                    ans[0]=arr[i];
                    ans[1]=arr[i+1];
                    ans[2]=arr[i+2];
                    maxsum=sum;
                }
            }

            for(int i=0;i<3;i++){
                cout<<ans[i]<<" ";
            }
            cout<<endl;
        }
    }
}