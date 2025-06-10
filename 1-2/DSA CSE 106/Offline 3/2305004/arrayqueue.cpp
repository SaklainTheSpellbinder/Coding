#include "queue.h"
#include <iostream>
using namespace std;
// Constructor implementation
ArrayQueue::ArrayQueue(int initial_capacity)
{
    // TODO: Initialize data members (data, capacity, front_idx, rear_idx)
    // TODO: Allocate memory for the array with the specified initial capacity
    data=new int[initial_capacity];
    capacity=initial_capacity;
    front_idx=-1;
    rear_idx=-1;
}

// Destructor implementation
ArrayQueue::~ArrayQueue()
{
    // TODO: Free the dynamically allocated memory for the array
    delete[] data;
}

// Enqueue implementation (add an item to the rear of the queue)
void ArrayQueue::enqueue(int item)
{
    // TODO: Check if the array is full
    // TODO: If full, resize the array to double its current capacity
    // TODO: Add the new element to the rear of the queue
    if(size()==capacity){
        resize(2*capacity);
    }
    rear_idx=(rear_idx+1)%capacity;
    data[rear_idx]=item;
    if(front_idx==-1){
        front_idx=0;
    }
}

// Dequeue implementation (remove an item from the front of the queue)
int ArrayQueue::dequeue()
{
    // TODO: Check if the queue is empty, display error message if it is
    // TODO: Decrement current_size and return the element at the front of the queue
    // TODO: Update front index
    // TODO: Return the dequeued element
    if(empty()){
        cerr<<"Queue is already empty\n";
        return -1;
    }
    int temp=data[front_idx];
    if(front_idx==rear_idx){
        front_idx=rear_idx=-1;
    }
    else{
        front_idx=(front_idx+1)%capacity;
    }
    if(4*size()<=capacity){
        resize(max(capacity/2,2));;
    }
    return temp;
}

// Clear implementation
void ArrayQueue::clear()
{
    // TODO: Reset the queue to be empty (reset capacity, front_idx, rear_idx, data)
    capacity=2;
    front_idx=-1;
    rear_idx=-1;
    delete[] data;
    data =new int[capacity];
}

// Size implementation
int ArrayQueue::size() const
{
    // TODO: Return the number of elements currently in the queue
    if(rear_idx==-1){
        return 0;
    }
    if((rear_idx+1)%capacity==front_idx){
        return capacity;
    }
    return (rear_idx-front_idx+capacity)%capacity+1;
}

// Front implementation
int ArrayQueue::front() const
{
    // TODO: Check if the queue is empty, display error message if it is
    // TODO: Return the element at the front of the queue without removing it
    if(empty()){
        cerr<<"Queue is already empty\n";
        return -1;
    }
    return data[front_idx];
}

// Back implementation (get the element at the back of the queue)
int ArrayQueue::back() const
{
    // TODO: Check if the queue is empty, display error message if it is
    // TODO: Return the element at the back of the queue without removing it
    if(empty()){
        cerr<<"Queue is already empty\n";
        return -1;
    }
    return data[rear_idx];
}

// Empty implementation
bool ArrayQueue::empty() const
{
    // TODO: Return whether the queue is empty (current_size == 0)
    return size()==0;
}

// Print implementation
string ArrayQueue::toString() const
{
    // TODO: Convert queue to a string representation in the format: <elem1, elem2, ..., elemN|
    string ans="<";
    if(size()>0){
        int j=front_idx;
        for(int i=0;i<size();i++){
            if(j!=front_idx){
                ans+=", ";
            }
            ans+=to_string(data[j]);
            j=(j+1)%capacity;
        }
    }
    ans+="|";
    return ans;
}

// Resize implementation
void ArrayQueue::resize(int new_capacity)
{
    // TODO: Create a new array with the new capacity
    // TODO: Copy elements from the old array to the new array
    // TODO: Delete the old array
    // TODO: Update the data pointer and capacity
    // TODO: Update front and rear indices
    if(new_capacity<2){
        new_capacity=2;
    }
    int* temp=new int[new_capacity];
    int j=front_idx;
    for(int i=0;i<size();i++){
        temp[i]=data[j];
        j=(j+1)%capacity;
    }
    capacity=new_capacity;
    rear_idx=size()-1;
    if(rear_idx==-1){
        front_idx=-1;
    }
    else{
        front_idx=0;
    }
    delete[] data;
    data=temp;
}

int ArrayQueue::getCapacity() const
{
    // TODO: Return the current capacity of the queue
    return capacity;
}