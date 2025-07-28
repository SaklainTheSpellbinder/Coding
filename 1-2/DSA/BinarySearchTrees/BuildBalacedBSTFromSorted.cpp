#include<iostream>
#include<vector>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data=val;
        left=right=NULL;
    }
};

Node* insert(Node* root,int val){//O(logn)
    if(root==NULL){
        root=new Node(val);
        return root;
    }

    if(val<root->data){
        root->left=insert(root->left,val);
    }
    else{
        root->right=insert(root->right,val);
    }
}

Node* buildBSTFromSorted(vector<int>arr,int start,int end){
    if(start>end)
        return NULL;

    int mid= start + (end- start)/2;
    Node* curr= new Node(arr[mid]);
    curr->left=buildBSTFromSorted(arr,start,mid-1);
    curr->right=buildBSTFromSorted(arr,mid+1,end);
    return curr;
}

void inorder(Node* root,vector<int> &sorted){
    if(root==NULL)
        return;
    inorder(root->left,sorted);
    sorted.push_back(root->data);
    inorder(root->right,sorted);
}

void preorder(Node* root){
    if(root==NULL)
        return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

bool search(Node* root,int key){//O(height)--> average O(logn)
    if(root==NULL)
        return false;
    if(root->data==key)
        return true;
    if(root->data>key)
        search(root->left,key);
    if(root->data<key)
        search(root->right,key);
}

Node* getinordersuccessor(Node* root){
    while(root->left!=NULL){
        root=root->left;
    }
    return root;
}

Node* delNode(Node* root,int val){
    if(root==NULL)
        return NULL;
    if(val<root->data)
        root->left=delNode(root->left,val);
    else if(val>root->data)
        root->right=delNode(root->right,val);
    else{
        //no child
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }
        if( root->left==NULL || root->right==NULL){
            return root->left==NULL ? root->right : root->left;
        }

        Node* IS=getinordersuccessor(root->right); 
        root->data=IS->data;
        root->right=delNode(root->right,IS->data);
        return root;
    }
    return root;
}

int main(){
    Node* root=new Node(6);
    root->left=new Node(5);
    root->left->left=new Node(4);
    root->left->left->left=new Node(3);

    root->right=new Node(7);
    root->right->right=new Node(8);
    root->right->right->right=new Node(9);
    
    vector<int>sorted;
    inorder(root,sorted);
    root=buildBSTFromSorted(sorted,0,6);
    preorder(root);
    cout<<endl;
}