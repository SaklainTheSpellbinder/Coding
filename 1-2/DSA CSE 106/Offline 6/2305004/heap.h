#ifndef HEAP_H
#define HEAP_H

#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>

using namespace std;

class Heap{
    int length;
    int capacity;
    int* numbers;

    void resize(int new_capacity){
        int* temp=new int[new_capacity];
        temp[0]=INT_MIN;
        for(int i=1;i<=length;i++){
            temp[i]=numbers[i];
        }
        delete[] numbers;
        numbers=temp;
        capacity=new_capacity;
    }

    void heapify(int i,int n){
        int l=2*i;
        int r=2*i+1;
        int largest=i;
        if(l<=n && numbers[l]>numbers[largest]){
            largest=l;
        }
        if(r<=n && numbers[r]>numbers[largest]){
            largest=r;
        }
        if(i!=largest){
            swap(numbers[i],numbers[largest]);
            heapify(largest,n);
        }
    }
public:
    Heap(int size){
        length=0;
        capacity=size+1;
        numbers=new int[capacity];
        numbers[0]=INT_MIN;
    }

    Heap(vector<int>&v){
        length=v.size();
        capacity=length+1;
        numbers=new int[capacity];
        numbers[0]=INT_MIN;
        for(int i=0;i<v.size();i++){
            numbers[i+1]=v[i];
        }
        for(int i=length/2;i>0;i--){
            heapify(i,length);
        }
    }

    ~Heap(){
        delete[] numbers;
    }

    void insert(int n){
        if(length+1==capacity){
            resize(2*capacity);
        }
        length++;
        numbers[length]=n;
        int parent=length/2;
        int i=length;
        while(parent>0 && numbers[parent]<numbers[i]){
            swap(numbers[parent],numbers[i]);
            i=parent;
            parent=i/2;
        }
    }

    int getMax(){
        if(length==0){
            throw runtime_error("The heap is already empty");
        }
        return numbers[1];
    }

    int size(){
        return length;
    }

    void deleteKey(){
        if(length==0){
            throw runtime_error("The heap is already empty");
        }
        numbers[1]=numbers[length];
        length--;
        heapify(1,length);
        if(length<(capacity/4)){
            resize(max(capacity/2,2));
        }
    }

    vector<int> heapsortHelper(){
        for(int i=length;i>1;i--){
            swap(numbers[1],numbers[i]);
            heapify(1,i-1);
        }
        vector<int>ans(length);
        for(int i=length;i>0;i--){
            ans[length-i]=numbers[i];
        }
        return ans;
    }
};

void heapsort(vector<int>& numbers){
    Heap h(numbers);
    numbers=h.heapsortHelper();
}
#endif