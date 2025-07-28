#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Heap{
    vector<int>vec;//CBT   //max heap
public:
    void push(int val){
        //insert
        vec.push_back(val);

        //fix heap
        int x=vec.size()-1; //child1
        int parI=(x-1)/2;

        while(parI>=0 && vec[x]>vec[parI]){  //min heap hole vec[0]<vec[parI] hbe
            swap(vec[x],vec[parI]);
            x=parI;
            parI=(x-1)/2;
        }

    }

    void heapify(int i){
        if(i>=vec.size()){
            return;
        }

        int l=2*i+1;
        int r=2*i+2;
        
        int maxIndex=i;
        if(l<vec.size() && vec[maxIndex]<vec[l]){
            maxIndex=l;
        }
        if(r<vec.size() && vec[maxIndex]<vec[r]){
            maxIndex=r;
        }
        swap(vec[i],vec[maxIndex]);
        if(maxIndex!=i){
            heapify(maxIndex);
        }
    }

    void pop(){
        //step1
        swap(vec[0],vec[vec.size()-1]);

        //step2
        vec.pop_back();

        //step 3
        heapify(0);//O(logn)
    }

    int top(){
        return vec[0];  //O(1)
    }

    bool empty(){
        return vec.size()==0;
    }
};

int main(){
    Heap p;
    p.push(5);
    p.push(67);
    p.push(10);
    p.push(2);
    p.push(15);
    p.push(5);
    p.push(21);
    p.push(2);
    while(!p.empty()){
        cout<<p.top()<<endl;
        p.pop();
    }
}