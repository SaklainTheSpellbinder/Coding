//#include "queue.h"
// listqueue.h
#ifndef LISTQUEUE_H
#define LISTQUEUE_H
#include <iostream>
using namespace std;

class ListQueue
{
private:
    /**
     * Node - Structure representing a single element in the linked list
     */
    struct Node
    {
        int data;   // Value stored in this node
        Node *next; // Pointer to the next node in the list

        /**
         * Node constructor
         * @param value The value to store in this node
         * @param next_node Pointer to the next node (default: nullptr)
         */
        Node(int value, Node *next_node = nullptr) : data(value), next(next_node) {}
    };

    Node *front_node; // Pointer to the front node of the queue
    Node *rear_node;  // Pointer to the rear node of the queue
    int current_size; // Number of elements currently in the queue

public:
    /**
     * Constructor - Creates an empty queue
     */
    ListQueue();

    /**
     * Destructor - Cleans up any dynamically allocated memory
     */
    ~ListQueue();

    // Queue interface implementation
    void enqueue(int value);
    int dequeue();
    void clear();
    int front() const;
    int back() const;
    bool empty() const;
    int size() const;
    string toString() const;
};


// Constructor implementation
ListQueue::ListQueue()
{
    // TODO: Initialize front_node and rear_node
    // TODO: Initialize current_size to 0
    front_node=NULL;
    rear_node=NULL;
    current_size=0;
}

// Destructor implementation
ListQueue::~ListQueue()
{
    // TODO: Deallocate all nodes in the linked list
    // TODO: Consider using the clear() method
    clear();
}

// Enqueue implementation (add an item at the rear of the queue)
void ListQueue::enqueue(int item)
{
    // TODO: Create a new node with the given item
    // TODO: Link the new node to the rear
    // TODO: Update the rear_node
    // TODO: Increment the current size
    Node* newNode=new Node(item);
    if(front_node==NULL){
        front_node=rear_node=newNode;
    }
    else{
        rear_node->next=newNode;
        rear_node=rear_node->next;
    }
    current_size++;
}

// Dequeue implementation (remove an item from the front of the queue)
int ListQueue::dequeue()
{
    // TODO: Check if the queue is empty, display error message if it is
    // TODO: Store the data from the front node
    // TODO: Update the front pointer to the next node
    // TODO: Update the rear pointer if the queue becomes empty
    // TODO: Delete the old front node
    // TODO: Decrement current_size
    // TODO: Return the stored data
    if(empty()){
        cerr<<"Queue is already empty\n";
        return -1;
    }
    int temp=front_node->data;
    Node* tempnode=front_node;
    front_node=front_node->next;
    if(front_node==NULL){
        rear_node=NULL;
    }
    delete tempnode;
    current_size--;
    return temp;
}

// Clear implementation (delete all elements)
void ListQueue::clear()
{
    // TODO: Traverse the linked list and delete each node
    // TODO: Reset front and rear pointer
    // TODO: Reset current_size to 0
    while(front_node!=NULL){
        Node* temp=front_node;
        front_node=front_node->next;
        delete temp;
    }
    rear_node=NULL;
    current_size=0;
}

// Size implementation (return the current number of elements)
int ListQueue::size() const
{
    // TODO: Return the current size (current_size)
    return current_size;
}

// Front implementation (get the element at the front of the queue)
int ListQueue::front() const
{
    // TODO: Check if the queue is empty, display error message if it is
    // TODO: Return the data from the front node without removing it
    if(empty()){
        cerr<<"Queue is already empty\n";
        return -1;
    }
    return front_node->data;
}

// Back implementation (get the element at the back of the queue)
int ListQueue::back() const
{
    // TODO: Check if the queue is empty, display error message if it is
    // TODO: Return the data from the back node without removing it
    if(empty()){
        cerr<<"Queue is already empty\n";
        return -1;
    }
    return rear_node->data;
}

// Empty implementation (check if the queue is empty)
bool ListQueue::empty() const
{
    // TODO: Return whether front is nullptr
    return front_node==NULL;
}

// Print implementation (print elements from front to rear)
string ListQueue::toString() const
{
    // TODO: Convert queue to a string representation in the format: <elem1, elem2, ..., elemN|
    // TODO: Traverse the linked list from front
    string ans="<";
    Node* curr=front_node;
    while(curr){
        if(curr!=front_node){
            ans+=", ";
        }
        ans+=to_string(curr->data);
        curr=curr->next;
    }
    ans+="|";
    return ans;
}
#endif