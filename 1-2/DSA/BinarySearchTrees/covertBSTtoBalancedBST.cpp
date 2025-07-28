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

Node* buildBST(int arr[],int n){
    Node* root=NULL;
    for(int i=0;i<n;i++){
        root=insert(root,arr[i]);
    }
    return root;
}

void inorder(Node* root){
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
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
    int arr2[9]={8,5,3,1,4,6,10,11,14};
    Node* root=buildBST(arr2,9);
    inorder(root);
    cout<<endl;
    delNode(root,10);
    inorder(root);
    cout<<endl;
}