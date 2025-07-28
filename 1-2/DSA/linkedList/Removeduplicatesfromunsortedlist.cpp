#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;

    Node(int x)
        : data(x)
        , next(nullptr) {}
};

void printList(Node *head) {
    Node *temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

class Solution {
  public:
    Node *removeDuplicates(Node *head) {
        // your code goes here
        unordered_map<int,int>m;
        Node* curr=head;
        Node* prev=NULL;
        while(curr){
            if(m.count(curr->data)){
                prev->next=curr->next;
                Node* temp=curr;
                curr=curr->next;
                delete temp;
            }
            else{
                m.insert({curr->data,1});
                prev=curr;
                curr=curr->next;
            }
        }
        return head;
    }
};


int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        while (ss >> number) {
            arr.push_back(number);
        }

        if (arr.empty()) {
            cout << "empty" << endl;
            continue;
        }

        Node *head = new Node(arr[0]);
        Node *tail = head;

        for (size_t i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }

        Solution ob;
        Node *result = ob.removeDuplicates(head);
        printList(result);
    }

    return 0;
}