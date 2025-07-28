#include<iostream>
#include<stack>

using namespace std;



#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(0);

void sortstack(stack<int>& in,stack<int> &out){
    if(in.empty()){
        return;
    }
    if(out.empty() || out.top()>in.top()){
        out.push(in.top());
        in.pop();
        return;
    }
    else{
        int data=out.top();
        out.pop();
        sortstack(in,out);
        out.push(data);
    }
}

int main(){
    FAST_IO;
    int t;
    cin>>t;
    while(t--){
        stack<int>input;
        stack<int>output;
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            input.push(x);
        }
        while(!input.empty())
            sortstack(input,output);
        while(!output.empty()){
            cout<<output.top()<<" ";
            output.pop();
        }
        cout<<endl;
    }
}