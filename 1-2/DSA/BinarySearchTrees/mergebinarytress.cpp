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

vector<int> merge(vector<int>a,vector<int>b){
    vector<int>sorted;
    int i=0,j=0;
    while(i<a.size() && j<b.size()){
        if(a[i]<b[j]){
            sorted.push_back(a[i++]);
        }
        else{
            sorted.push_back(b[j++]);
        }
    }
    while(i<a.size()){
        sorted.push_back(a[i++]);
    }
    while(j<b.size()){
        sorted.push_back(b[j++]);
    }
    return sorted;
}

int main(){
    Node* root1=new Node(2);
    root1->left=new Node(1);
    root1->right=new Node(4);

    Node* root2=new Node(9);
    root2->left=new Node(3);
    root2->right=new Node(12);
    
    vector<int>sorted1;
    inorder(root1,sorted1);
    vector<int>sorted2;
    inorder(root2,sorted2);
    vector<int>sorted=merge(sorted1,sorted2);
    root1=buildBSTFromSorted(sorted,0,sorted.size()-1);
    preorder(root1);
    cout<<endl;
}   