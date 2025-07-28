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

static int maxSize;

class Info{
public:
    bool isBST;
    int min;
    int max;
    int sz;

    Info(bool isBST,int min,int max,int sz){
        this->isBST=isBST;
        this->min=min;
        this->max=max; 
        this->sz=sz;
    }
};

// Info* largestBST(Node* root){
//     // if(root==NULL){
//     //     return new Info(true,INT32_MAX,INT32_MIN,0);
//     // }

//     if(root==NULL)
//         return NULL;
//     if(root->left==NULL && root->right==NULL){
//         return new Info(true,root->data,root->data,1);
//     }

//     Info* leftinfo=largestBST(root->left);
//     Info* rightinfo=largestBST(root->right);

//     int currMin=min(root->data,min(leftinfo->min,rightinfo->min));
//     int currMax=max(root->data,max(leftinfo->max,rightinfo->max));
//     int currsz=leftinfo->sz+rightinfo->sz+1;
    
//     if(leftinfo->isBST && rightinfo->isBST && root->data>leftinfo->max && root->data<rightinfo->min){
//         maxSize=max(maxSize,currsz);
//         return new Info(true,currMin,currMax,currsz);
//     }
//     return new Info(false,currMin,currMax,currsz);
// }

Info largestBSTUtil(Node* root, int& maxSize) {
    if (root == NULL) {
        return Info(true, INT32_MAX, INT32_MIN, 0);
    }

    // Leaf node
    if (root->left == NULL && root->right == NULL) {
        maxSize = max(maxSize, 1);
        return Info(true, root->data, root->data, 1);
    }

    // Get info from left and right subtrees
    Info leftinfo = largestBSTUtil(root->left, maxSize);
    Info rightinfo = largestBSTUtil(root->right, maxSize);

    // Compute current subtree properties
    int currMin = min(root->data, min(leftinfo.min, rightinfo.min));
    int currMax = max(root->data, max(leftinfo.max, rightinfo.max));
    int currsz = leftinfo.sz + rightinfo.sz + 1;

    if (leftinfo.isBST && rightinfo.isBST && root->data > leftinfo.max && root->data < rightinfo.min) {
        maxSize = max(maxSize, currsz);
        return Info(true, currMin, currMax, currsz);
    }
    return Info(false, currMin, currMax, currsz);
} 

int largestBST(Node* root) {
    int maxSize = 0;
    largestBSTUtil(root, maxSize);
    return maxSize;
}

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
    Node* root=new Node(50);
    root->left=new Node(30);
    root->left->left=new Node(5);
    root->left->right=new Node(20);

    root->right=new Node(60);
    root->right->left=new Node(45);
    root->right->right=new Node(70);
    root->right->right->left=new Node(65);
    root->right->right->right=new Node(80);

    cout<<largestBST(root);
    cout<<endl;
    return 0;
}